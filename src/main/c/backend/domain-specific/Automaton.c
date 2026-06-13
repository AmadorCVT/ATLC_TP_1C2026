#include "Automaton.h"
#include <stdio.h>
#include <string.h>

/* ------------------------------------------------------------------ */
/* Module internal state                                               */
/* ------------------------------------------------------------------ */

static Logger * _logger = NULL;

static void _shutdownAutomatonModule() {
	if (_logger != NULL) {
		logDebugging(_logger, "Destroying module: Automaton...");
		destroyLogger(_logger);
		_logger = NULL;
	}
}

ModuleDestructor initializeAutomatonModule() {
	_logger = createLogger("Automaton");
	return _shutdownAutomatonModule;
}

/* ------------------------------------------------------------------ */
/* Private helpers                                                     */
/* ------------------------------------------------------------------ */

char * copyRuntimeString(const char * value) {
	if (value == NULL) return NULL;
	char * copy = calloc(strlen(value) + 1, sizeof(char));
	strcpy(copy, value);
	return copy;
}

bool isQuotedString(const char * value) {
	if (value == NULL) return false;
	size_t length = strlen(value);
	return 2 <= length && value[0] == '"' && value[length - 1] == '"';
}

bool runtimeStringListContains(RuntimeStringList * list, const char * value) {
	for (RuntimeStringList * n = list; n != NULL; n = n->next) {
		if (strcmp(n->value, value) == 0) return true;
	}
	return false;
}

bool runtimeStringListHasDuplicates(RuntimeStringList * list) {
	for (RuntimeStringList * n = list; n != NULL; n = n->next) {
		if (runtimeStringListContains(n->next, n->value)) return true;
	}
	return false;
}

unsigned int runtimeStringListLength(RuntimeStringList * list) {
	unsigned int length = 0;
	for (RuntimeStringList * n = list; n != NULL; n = n->next) length++;
	return length;
}

void appendRuntimeString(RuntimeStringList ** list, const char * value) {
	RuntimeStringList * node = calloc(1, sizeof(RuntimeStringList));
	node->value = copyRuntimeString(value);
	if (*list == NULL) {
		*list = node;
		return;
	}
	RuntimeStringList * last = *list;
	while (last->next != NULL) last = last->next;
	last->next = node;
}

void appendUniqueRuntimeString(RuntimeStringList ** list, const char * value) {
	if (!runtimeStringListContains(*list, value)) {
		appendRuntimeString(list, value);
	}
}

static RuntimeTransition * _runtimeTransitionFromAst(Transition * t) {
	RuntimeTransition * rt = calloc(1, sizeof(RuntimeTransition));
	rt->source   = copyRuntimeString(t->source);
	rt->isLambda = t->symbol->isLambda;
	rt->hadMultipleDestinations = t->destination->type == MULTIPLE_TRANSITION_DESTINATIONS;
	if (!t->symbol->isLambda) {
		rt->symbol = copyRuntimeString(t->symbol->value);
	}
	if (t->destination->type == SINGLE_TRANSITION_DESTINATION) {
		appendRuntimeString(&rt->destinations, t->destination->state);
	}
	else {
		for (StringList * d = t->destination->states; d != NULL; d = d->next) {
			appendRuntimeString(&rt->destinations, d->value);
		}
	}
	return rt;
}

static void _appendRuntimeTransition(RuntimeAutomaton * automaton, RuntimeTransition * rt) {
	if (automaton->transitions == NULL) {
		automaton->transitions = rt;
		return;
	}
	RuntimeTransition * last = automaton->transitions;
	while (last->next != NULL) last = last->next;
	last->next = rt;
}

bool sameRuntimeTransitionKey(RuntimeTransition * a, RuntimeTransition * b) {
	if (a == NULL || b == NULL) return false;
	if (strcmp(a->source, b->source) != 0) return false;
	if (a->isLambda != b->isLambda) return false;
	if (a->isLambda) return true;
	return strcmp(a->symbol, b->symbol) == 0;
}

bool hasEarlierRuntimeTransitionWithSameKey(RuntimeTransition * first, RuntimeTransition * current) {
	for (RuntimeTransition * t = first; t != NULL && t != current; t = t->next) {
		if (sameRuntimeTransitionKey(t, current)) return true;
	}
	return false;
}

static void _removeTransitionsWithSameKey(RuntimeAutomaton * automaton, RuntimeTransition * key) {
	RuntimeTransition * prev = NULL;
	RuntimeTransition * curr = automaton->transitions;
	while (curr != NULL) {
		RuntimeTransition * next = curr->next;
		if (sameRuntimeTransitionKey(curr, key)) {
			if (prev == NULL) automaton->transitions = next;
			else              prev->next = next;
			curr->next = NULL;
			destroyRuntimeTransition(curr);
		}
		else {
			prev = curr;
		}
		curr = next;
	}
}

/* ------------------------------------------------------------------ */
/* Destroy                                                             */
/* ------------------------------------------------------------------ */

void destroyRuntimeStringList(RuntimeStringList * list) {
	while (list != NULL) {
		RuntimeStringList * next = list->next;
		free(list->value);
		free(list);
		list = next;
	}
}

void destroyRuntimeTransition(RuntimeTransition * transition) {
	while (transition != NULL) {
		RuntimeTransition * next = transition->next;
		free(transition->source);
		free(transition->symbol);
		destroyRuntimeStringList(transition->destinations);
		free(transition);
		transition = next;
	}
}

void destroyRuntimeAutomaton(RuntimeAutomaton * automaton) {
	if (automaton == NULL) return;
	free(automaton->name);
	destroyRuntimeStringList(automaton->alphabet);
	destroyRuntimeStringList(automaton->states);
	free(automaton->startState);
	destroyRuntimeStringList(automaton->acceptStates);
	destroyRuntimeTransition(automaton->transitions);
	free(automaton);
}

/* ------------------------------------------------------------------ */
/* Symbol table (scoped)                                               */
/* ------------------------------------------------------------------ */

static void _destroyRuntimeSymbol(RuntimeSymbol * symbol) {
	if (symbol == NULL) return;
	free(symbol->name);
	switch (symbol->type) {
		case RUNTIME_SYMBOL_AUTOMATON:
			destroyRuntimeAutomaton(symbol->automaton);
			break;
		case RUNTIME_SYMBOL_STRING:
			free(symbol->string);
			break;
		default:
			break;
	}
	free(symbol);
}

static void _destroyRuntimeScope(RuntimeScope * scope) {
	if (scope == NULL) return;
	RuntimeSymbol * symbol = scope->symbols;
	while (symbol != NULL) {
		RuntimeSymbol * next = symbol->next;
		_destroyRuntimeSymbol(symbol);
		symbol = next;
	}
	free(scope);
}

RuntimeSymbolTable * runtimeSymbolTableCreate() {
	RuntimeSymbolTable * table = calloc(1, sizeof(RuntimeSymbolTable));
	table->globalScope = calloc(1, sizeof(RuntimeScope));
	table->currentScope = table->globalScope;
	return table;
}

void runtimeSymbolTableDestroy(RuntimeSymbolTable * table) {
	if (table == NULL) return;
	RuntimeScope * scope = table->currentScope;
	while (scope != NULL) {
		RuntimeScope * parent = scope->parent;
		_destroyRuntimeScope(scope);
		scope = parent;
	}
	free(table);
}

void runtimeSymbolTablePushScope(RuntimeSymbolTable * table) {
	RuntimeScope * scope = calloc(1, sizeof(RuntimeScope));
	scope->parent = table->currentScope;
	table->currentScope = scope;
}

void runtimeSymbolTablePopScope(RuntimeSymbolTable * table) {
	RuntimeScope * scope = table->currentScope;
	if (scope == NULL || scope->parent == NULL) return;
	table->currentScope = scope->parent;
	_destroyRuntimeScope(scope);
}

RuntimeSymbol * runtimeSymbolTableLookupVisible(RuntimeSymbolTable * table, const char * name) {
	for (RuntimeScope * scope = table->currentScope; scope != NULL; scope = scope->parent) {
		for (RuntimeSymbol * symbol = scope->symbols; symbol != NULL; symbol = symbol->next) {
			if (strcmp(symbol->name, name) == 0) return symbol;
		}
	}
	return NULL;
}

RuntimeSymbol * runtimeSymbolTableLookupCurrent(RuntimeSymbolTable * table, const char * name) {
	RuntimeScope * scope = table->currentScope;
	if (scope == NULL) return NULL;
	for (RuntimeSymbol * symbol = scope->symbols; symbol != NULL; symbol = symbol->next) {
		if (strcmp(symbol->name, name) == 0) return symbol;
	}
	return NULL;
}

bool runtimeSymbolTableAddAutomaton(RuntimeSymbolTable * table, const char * name, RuntimeAutomaton * automaton) {
	if (runtimeSymbolTableLookupCurrent(table, name) != NULL) return false;
	RuntimeSymbol * symbol = calloc(1, sizeof(RuntimeSymbol));
	symbol->name = copyRuntimeString(name);
	symbol->type = RUNTIME_SYMBOL_AUTOMATON;
	symbol->automaton = automaton;
	symbol->next = table->currentScope->symbols;
	table->currentScope->symbols = symbol;
	return true;
}

bool runtimeSymbolTableAddString(RuntimeSymbolTable * table, const char * name, char * value) {
	if (runtimeSymbolTableLookupCurrent(table, name) != NULL) return false;
	RuntimeSymbol * symbol = calloc(1, sizeof(RuntimeSymbol));
	symbol->name = copyRuntimeString(name);
	symbol->type = RUNTIME_SYMBOL_STRING;
	symbol->string = value;
	symbol->next = table->currentScope->symbols;
	table->currentScope->symbols = symbol;
	return true;
}

/* ------------------------------------------------------------------ */
/* Automaton lifecycle                                                 */
/* ------------------------------------------------------------------ */

RuntimeAutomaton * runtimeAutomatonFromAst(Automaton * ast) {
	RuntimeAutomaton * ra = calloc(1, sizeof(RuntimeAutomaton));
	ra->name = copyRuntimeString(ast->id);
	ra->type = ast->type;
	for (StringList * s = ast->definition->alphabet;     s != NULL; s = s->next) appendRuntimeString(&ra->alphabet,     s->value);
	for (StringList * s = ast->definition->states;       s != NULL; s = s->next) appendRuntimeString(&ra->states,       s->value);
	ra->startState = copyRuntimeString(ast->definition->startState);
	for (StringList * s = ast->definition->acceptStates; s != NULL; s = s->next) appendRuntimeString(&ra->acceptStates, s->value);
	for (Transition * t = ast->definition->transitions;  t != NULL; t = t->next) _appendRuntimeTransition(ra, _runtimeTransitionFromAst(t));
	return ra;
}

RuntimeAutomaton * cloneRuntimeAutomaton(RuntimeAutomaton * src, const char * newName, AutomatonType newType) {
	RuntimeAutomaton * clone = calloc(1, sizeof(RuntimeAutomaton));
	clone->name = copyRuntimeString(newName);
	clone->type = newType;
	for (RuntimeStringList * s = src->alphabet;     s != NULL; s = s->next) appendRuntimeString(&clone->alphabet,     s->value);
	for (RuntimeStringList * s = src->states;       s != NULL; s = s->next) appendRuntimeString(&clone->states,       s->value);
	clone->startState = copyRuntimeString(src->startState);
	for (RuntimeStringList * s = src->acceptStates; s != NULL; s = s->next) appendRuntimeString(&clone->acceptStates, s->value);
	for (RuntimeTransition * t = src->transitions; t != NULL; t = t->next) {
		RuntimeTransition * rt = calloc(1, sizeof(RuntimeTransition));
		rt->source   = copyRuntimeString(t->source);
		rt->symbol   = copyRuntimeString(t->symbol);
		rt->isLambda = t->isLambda;
		rt->hadMultipleDestinations = t->hadMultipleDestinations;
		for (RuntimeStringList * d = t->destinations; d != NULL; d = d->next) appendRuntimeString(&rt->destinations, d->value);
		_appendRuntimeTransition(clone, rt);
	}
	return clone;
}

/* A metadata-only copy: alphabet, states, start and accept states, but no
 * transitions. Used when a conversion only needs to register its output symbol
 * (with the right type) so later statements type-check; the real transitions
 * are produced later by the conversion routines. */
RuntimeAutomaton * cloneRuntimeAutomatonShell(RuntimeAutomaton * src, const char * newName, AutomatonType newType) {
	RuntimeAutomaton * shell = calloc(1, sizeof(RuntimeAutomaton));
	shell->name = copyRuntimeString(newName);
	shell->type = newType;
	for (RuntimeStringList * s = src->alphabet;     s != NULL; s = s->next) appendRuntimeString(&shell->alphabet,     s->value);
	for (RuntimeStringList * s = src->states;       s != NULL; s = s->next) appendRuntimeString(&shell->states,       s->value);
	shell->startState = copyRuntimeString(src->startState);
	for (RuntimeStringList * s = src->acceptStates; s != NULL; s = s->next) appendRuntimeString(&shell->acceptStates, s->value);
	return shell;
}

/* ------------------------------------------------------------------ */
/* Lambda-closure (fixpoint)                                           */
/* ------------------------------------------------------------------ */

RuntimeStringList * lambdaClosure(RuntimeAutomaton * automaton, RuntimeStringList * states) {
	RuntimeStringList * closure = NULL;
	for (RuntimeStringList * s = states; s != NULL; s = s->next) {
		appendUniqueRuntimeString(&closure, s->value);
	}
	bool changed = true;
	while (changed) {
		changed = false;
		for (RuntimeStringList * state = closure; state != NULL; state = state->next) {
			for (RuntimeTransition * t = automaton->transitions; t != NULL; t = t->next) {
				if (!t->isLambda) continue;
				if (strcmp(t->source, state->value) != 0) continue;
				for (RuntimeStringList * d = t->destinations; d != NULL; d = d->next) {
					if (!runtimeStringListContains(closure, d->value)) {
						appendRuntimeString(&closure, d->value);
						changed = true;
					}
				}
			}
		}
	}
	return closure;
}

/* ------------------------------------------------------------------ */
/* Simulation                                                          */
/* ------------------------------------------------------------------ */

static bool _simulateDFA(RuntimeAutomaton * automaton, const char * input) {
	const char * state = automaton->startState;
	for (int i = 0; input[i] != '\0'; i++) {
		char sym[2] = { input[i], '\0' };
		const char * next = NULL;
		for (RuntimeTransition * t = automaton->transitions; t != NULL; t = t->next) {
			if (!t->isLambda
				&& strcmp(t->source, state) == 0
				&& strcmp(t->symbol, sym)   == 0
				&& t->destinations != NULL) {
				next = t->destinations->value;
				break;
			}
		}
		if (next == NULL) return false;
		state = next;
	}
	return runtimeStringListContains(automaton->acceptStates, state);
}

static bool _simulateNFA(RuntimeAutomaton * automaton, const char * input) {
	RuntimeStringList * current = NULL;
	appendRuntimeString(&current, automaton->startState);
	for (int i = 0; input[i] != '\0'; i++) {
		char sym[2] = { input[i], '\0' };
		RuntimeStringList * next = NULL;
		for (RuntimeStringList * state = current; state != NULL; state = state->next) {
			for (RuntimeTransition * t = automaton->transitions; t != NULL; t = t->next) {
				if (!t->isLambda
					&& strcmp(t->source, state->value) == 0
					&& strcmp(t->symbol, sym)           == 0) {
					for (RuntimeStringList * d = t->destinations; d != NULL; d = d->next) {
						appendUniqueRuntimeString(&next, d->value);
					}
				}
			}
		}
		destroyRuntimeStringList(current);
		current = next;
		if (current == NULL) return false;
	}
	bool accepted = false;
	for (RuntimeStringList * s = current; s != NULL; s = s->next) {
		if (runtimeStringListContains(automaton->acceptStates, s->value)) {
			accepted = true;
			break;
		}
	}
	destroyRuntimeStringList(current);
	return accepted;
}

static bool _simulateLNFA(RuntimeAutomaton * automaton, const char * input) {
	RuntimeStringList * initial = NULL;
	appendRuntimeString(&initial, automaton->startState);
	RuntimeStringList * current = lambdaClosure(automaton, initial);
	destroyRuntimeStringList(initial);
	for (int i = 0; input[i] != '\0'; i++) {
		char sym[2] = { input[i], '\0' };
		RuntimeStringList * moved = NULL;
		for (RuntimeStringList * state = current; state != NULL; state = state->next) {
			for (RuntimeTransition * t = automaton->transitions; t != NULL; t = t->next) {
				if (!t->isLambda
					&& strcmp(t->source, state->value) == 0
					&& strcmp(t->symbol, sym)           == 0) {
					for (RuntimeStringList * d = t->destinations; d != NULL; d = d->next) {
						appendUniqueRuntimeString(&moved, d->value);
					}
				}
			}
		}
		destroyRuntimeStringList(current);
		if (moved == NULL) return false;
		current = lambdaClosure(automaton, moved);
		destroyRuntimeStringList(moved);
	}
	bool accepted = false;
	for (RuntimeStringList * s = current; s != NULL; s = s->next) {
		if (runtimeStringListContains(automaton->acceptStates, s->value)) {
			accepted = true;
			break;
		}
	}
	destroyRuntimeStringList(current);
	return accepted;
}

bool simulateAutomaton(RuntimeAutomaton * automaton, const char * input) {
	switch (automaton->type) {
		case DFA:  return _simulateDFA(automaton, input);
		case NFA:  return _simulateNFA(automaton, input);
		case LNFA: return _simulateLNFA(automaton, input);
		default:   return false;
	}
}

/* ------------------------------------------------------------------ */
/* Conversions                                                         */
/* ------------------------------------------------------------------ */

RuntimeAutomaton * convertDFAtoNFA(RuntimeAutomaton * dfa, const char * newName) {
	return cloneRuntimeAutomaton(dfa, newName, NFA);
}

/* We need a way to name subset-states so they're consistent,
   regardless of the order we found them*/

static RuntimeStringList * _cloneStringList(RuntimeStringList * list) {
	RuntimeStringList * clone = NULL;
	for (RuntimeStringList * s = list; s != NULL; s = s->next) {
		appendRuntimeString(&clone, s->value);
	}
	return clone;
}

static void _sortStringList(RuntimeStringList ** list) {
	if (*list == NULL || (*list)->next == NULL) return;
	/* Simple bubble sort */
	bool swapped = true;
	while (swapped) {
		swapped = false;
		RuntimeStringList ** ptr = list;
		while ((*ptr)->next != NULL) {
			if (strcmp((*ptr)->value, (*ptr)->next->value) > 0) {
				/* swap the two nodes */
				RuntimeStringList * a = *ptr;
				RuntimeStringList * b = a->next;
				a->next = b->next;
				b->next = a;
				*ptr = b;
				swapped = true;
			}
			ptr = &(*ptr)->next;
		}
	}
}

static char * _buildSubsetName(RuntimeStringList * states) {
	RuntimeStringList * sorted = _cloneStringList(states);
	_sortStringList(&sorted);

	/* figure out how much space we need */
	size_t length = 2; /* for the braces */
	int count = 0;
	for (RuntimeStringList * s = sorted; s != NULL; s = s->next) {
		length += strlen(s->value);
		count++;
	}
	if (count > 1) length += (count - 1); /* commas */

	char * name = calloc(length + 1, sizeof(char));
	strcat(name, "{");
	for (RuntimeStringList * s = sorted; s != NULL; s = s->next) {
		strcat(name, s->value);
		if (s->next != NULL) strcat(name, ",");
	}
	strcat(name, "}");

	destroyRuntimeStringList(sorted);
	return name;
}

/* Given a set of NFA states and a symbol, find all the states
 * we can reach by following transitions with that symbol */
static RuntimeStringList * _moveNFA(RuntimeAutomaton * nfa, RuntimeStringList * states, const char * symbol) {
	RuntimeStringList * result = NULL;
	for (RuntimeStringList * state = states; state != NULL; state = state->next) {
		for (RuntimeTransition * t = nfa->transitions; t != NULL; t = t->next) {
			if (!t->isLambda
				&& strcmp(t->source, state->value) == 0
				&& strcmp(t->symbol, symbol) == 0) {
				for (RuntimeStringList * d = t->destinations; d != NULL; d = d->next) {
					appendUniqueRuntimeString(&result, d->value);
				}
			}
		}
	}
	return result;
}

/* Check if two string lists have the same elements, regardless of order */
static bool _sameStringSet(RuntimeStringList * a, RuntimeStringList * b) {
	for (RuntimeStringList * s = a; s != NULL; s = s->next) {
		if (!runtimeStringListContains(b, s->value)) return false;
	}
	for (RuntimeStringList * s = b; s != NULL; s = s->next) {
		if (!runtimeStringListContains(a, s->value)) return false;
	}
	return true;
}

/* We keep a worklist of subset-states during the NFA→DFA construction.
 * Each entry is a set of NFA states plus the name we gave it. */

typedef struct SubsetEntry {
	RuntimeStringList * states;
	char * name;
	bool processed;
	struct SubsetEntry * next;
} SubsetEntry;

static SubsetEntry * _createSubsetEntry(RuntimeStringList * states) {
	SubsetEntry * entry = calloc(1, sizeof(SubsetEntry));
	entry->states = _cloneStringList(states);
	entry->name = _buildSubsetName(states);
	return entry;
}

static void _destroySubsetList(SubsetEntry * list) {
	while (list != NULL) {
		SubsetEntry * next = list->next;
		destroyRuntimeStringList(list->states);
		free(list->name);
		free(list);
		list = next;
	}
}

static SubsetEntry * _findSubset(SubsetEntry * list, RuntimeStringList * states) {
	for (SubsetEntry * e = list; e != NULL; e = e->next) {
		if (_sameStringSet(e->states, states)) return e;
	}
	return NULL;
}

RuntimeAutomaton * convertNFAtoDFA(RuntimeAutomaton * nfa, const char * newName) {
	RuntimeAutomaton * dfa = calloc(1, sizeof(RuntimeAutomaton));
	dfa->name = copyRuntimeString(newName);
	dfa->type = DFA;

	/* same alphabet */
	for (RuntimeStringList * s = nfa->alphabet; s != NULL; s = s->next) {
		appendRuntimeString(&dfa->alphabet, s->value);
	}

	/* the initial DFA state is just {startState} */
	RuntimeStringList * initialSet = NULL;
	appendRuntimeString(&initialSet, nfa->startState);

	SubsetEntry * allSubsets = _createSubsetEntry(initialSet);
	destroyRuntimeStringList(initialSet);
	dfa->startState = copyRuntimeString(allSubsets->name);
	appendRuntimeString(&dfa->states, allSubsets->name);

	/* keep processing until every subset has been visited.
	 * instead of a separate worklist we just scan for unprocessed entries. */
	bool foundUnprocessed = true;
	while (foundUnprocessed) {
		foundUnprocessed = false;

		SubsetEntry * current = NULL;
		for (SubsetEntry * e = allSubsets; e != NULL; e = e->next) {
			if (!e->processed) {
				current = e;
				current->processed = true;
				foundUnprocessed = true;
				break;
			}
		}
		if (current == NULL) break;

		/* try every symbol in the alphabet */
		for (RuntimeStringList * sym = dfa->alphabet; sym != NULL; sym = sym->next) {
			RuntimeStringList * moved = _moveNFA(nfa, current->states, sym->value);
			if (moved == NULL) {
				/* no transitions for this symbol, reject */
				continue;
			}

			SubsetEntry * existing = _findSubset(allSubsets, moved);
			if (existing == NULL) {
				/* brand new subset */
				SubsetEntry * newEntry = _createSubsetEntry(moved);
				appendRuntimeString(&dfa->states, newEntry->name);
				newEntry->next = allSubsets;
				allSubsets = newEntry;

				RuntimeTransition * rt = calloc(1, sizeof(RuntimeTransition));
				rt->source = copyRuntimeString(current->name);
				rt->symbol = copyRuntimeString(sym->value);
				appendRuntimeString(&rt->destinations, newEntry->name);
				_appendRuntimeTransition(dfa, rt);
			} else {
				RuntimeTransition * rt = calloc(1, sizeof(RuntimeTransition));
				rt->source = copyRuntimeString(current->name);
				rt->symbol = copyRuntimeString(sym->value);
				appendRuntimeString(&rt->destinations, existing->name);
				_appendRuntimeTransition(dfa, rt);
			}
			destroyRuntimeStringList(moved);
		}
	}

	/* a DFA state is accepting if any of its NFA states is accepting */
	for (SubsetEntry * e = allSubsets; e != NULL; e = e->next) {
		for (RuntimeStringList * s = e->states; s != NULL; s = s->next) {
			if (runtimeStringListContains(nfa->acceptStates, s->value)) {
				appendUniqueRuntimeString(&dfa->acceptStates, e->name);
				break;
			}
		}
	}

	_destroySubsetList(allSubsets);

	return dfa;
}

RuntimeAutomaton * convertLNFAtoNFA(RuntimeAutomaton * lnfa, const char * newName) {
	RuntimeAutomaton * nfa = calloc(1, sizeof(RuntimeAutomaton));
	nfa->name = copyRuntimeString(newName);
	nfa->type = NFA;

	/* same alphabet (no lambda column in an NFA) */
	for (RuntimeStringList * s = lnfa->alphabet; s != NULL; s = s->next) {
		appendRuntimeString(&nfa->alphabet, s->value);
	}

	/* same states */
	for (RuntimeStringList * s = lnfa->states; s != NULL; s = s->next) {
		appendRuntimeString(&nfa->states, s->value);
	}

	/* same start state */
	nfa->startState = copyRuntimeString(lnfa->startState);

	/* accept state if it contains any of the original accept states */
	for (RuntimeStringList * state = lnfa->states; state != NULL; state = state->next) {
		RuntimeStringList * seed = NULL;
		appendRuntimeString(&seed, state->value);
		RuntimeStringList * closure = lambdaClosure(lnfa, seed);
		destroyRuntimeStringList(seed);

		bool isAccept = false;
		for (RuntimeStringList * c = closure; c != NULL; c = c->next) {
			if (runtimeStringListContains(lnfa->acceptStates, c->value)) {
				isAccept = true;
				break;
			}
		}
		destroyRuntimeStringList(closure);

		if (isAccept) {
			appendUniqueRuntimeString(&nfa->acceptStates, state->value);
		}
	}

	for (RuntimeStringList * state = lnfa->states; state != NULL; state = state->next) {
		RuntimeStringList * seed = NULL;
		appendRuntimeString(&seed, state->value);
		RuntimeStringList * closureOfState = lambdaClosure(lnfa, seed);
		destroyRuntimeStringList(seed);

		for (RuntimeStringList * sym = lnfa->alphabet; sym != NULL; sym = sym->next) {
			RuntimeStringList * moved = _moveNFA(lnfa, closureOfState, sym->value);
			if (moved == NULL) {
				continue;
			}

			RuntimeStringList * closureOfMoved = lambdaClosure(lnfa, moved);
			destroyRuntimeStringList(moved);

			if (closureOfMoved != NULL) {
				RuntimeTransition * rt = calloc(1, sizeof(RuntimeTransition));
				rt->source = copyRuntimeString(state->value);
				rt->symbol = copyRuntimeString(sym->value);
				for (RuntimeStringList * d = closureOfMoved; d != NULL; d = d->next) {
					appendUniqueRuntimeString(&rt->destinations, d->value);
				}
				_appendRuntimeTransition(nfa, rt);
			}
			destroyRuntimeStringList(closureOfMoved);
		}
		destroyRuntimeStringList(closureOfState);
	}

	return nfa;
}

RuntimeAutomaton * convertLNFAtoDFA(RuntimeAutomaton * lnfa, const char * newName) {
	RuntimeAutomaton * intermediate = convertLNFAtoNFA(lnfa, "__intermediate__");
	RuntimeAutomaton * dfa = convertNFAtoDFA(intermediate, newName);
	destroyRuntimeAutomaton(intermediate);
	return dfa;
}

/* ------------------------------------------------------------------ */
/* Output                                                              */
/* ------------------------------------------------------------------ */

void printAutomaton(FILE * out, RuntimeAutomaton * automaton) {
	const char * typeName = automaton->type == DFA ? "DFA" : automaton->type == NFA ? "NFA" : "LNFA";
	fprintf(out, "automaton %s : %s {\n", automaton->name, typeName);

	fprintf(out, "    alphabet = {");
	for (RuntimeStringList * s = automaton->alphabet; s != NULL; s = s->next) {
		fprintf(out, "%s%s", s->value, s->next ? ", " : "");
	}
	fprintf(out, "}\n");

	fprintf(out, "    states = {");
	for (RuntimeStringList * s = automaton->states; s != NULL; s = s->next) {
		fprintf(out, "%s%s", s->value, s->next ? ", " : "");
	}
	fprintf(out, "}\n");

	fprintf(out, "    start = %s\n", automaton->startState);

	fprintf(out, "    accept = {");
	for (RuntimeStringList * s = automaton->acceptStates; s != NULL; s = s->next) {
		fprintf(out, "%s%s", s->value, s->next ? ", " : "");
	}
	fprintf(out, "}\n");

	fprintf(out, "    transitions {\n");
	for (RuntimeTransition * t = automaton->transitions; t != NULL; t = t->next) {
		const char * sym = t->isLambda ? "lambda" : t->symbol;
		if (t->destinations != NULL && t->destinations->next != NULL) {
			fprintf(out, "        %s -> %s : {", t->source, sym);
			for (RuntimeStringList * d = t->destinations; d != NULL; d = d->next) {
				fprintf(out, "%s%s", d->value, d->next ? ", " : "");
			}
			fprintf(out, "}\n");
		}
		else if (t->destinations != NULL) {
			fprintf(out, "        %s -> %s : %s\n", t->source, sym, t->destinations->value);
		}
	}
	fprintf(out, "    }\n};\n");
}

void showTransitions(FILE * out, RuntimeAutomaton * automaton) {
	fprintf(out, "Transitions of %s:\n", automaton->name);
	for (RuntimeTransition * t = automaton->transitions; t != NULL; t = t->next) {
		const char * sym = t->isLambda ? "lambda" : t->symbol;
		fprintf(out, "  %s -> %s : ", t->source, sym);
		for (RuntimeStringList * d = t->destinations; d != NULL; d = d->next) {
			fprintf(out, "%s%s", d->value, d->next ? ", " : "");
		}
		fprintf(out, "\n");
	}
}

/* Prints a transition table*/
void showTable(FILE * out, RuntimeAutomaton * automaton) {
	const char * typeName = automaton->type == DFA ? "DFA" : automaton->type == NFA ? "NFA" : "LNFA";
	fprintf(out, "Transition table of %s (%s):\n", automaton->name, typeName);

	/* get column headers */
	bool hasLambda = false;
	for (RuntimeTransition * t = automaton->transitions; t != NULL; t = t->next) {
		if (t->isLambda) { hasLambda = true; break; }
	}

	/* figure out column widths so things line up nicely */
	int stateColWidth = 5; /* minimum */
	for (RuntimeStringList * s = automaton->states; s != NULL; s = s->next) {
		int len = (int) strlen(s->value) + 2;
		if (len > stateColWidth) stateColWidth = len;
	}

	/* print header row */
	fprintf(out, "  %-*s", stateColWidth, "State");
	for (RuntimeStringList * sym = automaton->alphabet; sym != NULL; sym = sym->next) {
		fprintf(out, " | %-8s", sym->value);
	}
	if (hasLambda) {
		fprintf(out, " | %-8s", "lambda");
	}
	fprintf(out, "\n");

	/* separator line */
	fprintf(out, "  ");
	for (int i = 0; i < stateColWidth; i++) fprintf(out, "-");
	for (RuntimeStringList * sym = automaton->alphabet; sym != NULL; sym = sym->next) {
		fprintf(out, "-+---------");
	}
	if (hasLambda) {
		fprintf(out, "-+---------");
	}
	fprintf(out, "\n");

	/* one row per state */
	for (RuntimeStringList * state = automaton->states; state != NULL; state = state->next) {
		/* mark the start state with -> and accept states with * */
		bool isStart = strcmp(state->value, automaton->startState) == 0;
		bool isAccept = runtimeStringListContains(automaton->acceptStates, state->value);

		char label[256];
		snprintf(label, sizeof(label), "%s%s%s",
			isStart ? "->" : "",
			isAccept ? "*" : "",
			state->value);
		fprintf(out, "  %-*s", stateColWidth, label);

		/* for each alphabet symbol, find where this state goes */
		for (RuntimeStringList * sym = automaton->alphabet; sym != NULL; sym = sym->next) {
			RuntimeStringList * dests = NULL;
			for (RuntimeTransition * t = automaton->transitions; t != NULL; t = t->next) {
				if (!t->isLambda
					&& strcmp(t->source, state->value) == 0
					&& strcmp(t->symbol, sym->value) == 0) {
					for (RuntimeStringList * d = t->destinations; d != NULL; d = d->next) {
						appendUniqueRuntimeString(&dests, d->value);
					}
				}
			}
			if (dests == NULL) {
				fprintf(out, " | %-8s", "-");
			} else if (dests->next == NULL) {
				fprintf(out, " | %-8s", dests->value);
			} else {
				/* multiple destinations, show as {q0,q1} */
				char buf[256] = "{";
				for (RuntimeStringList * d = dests; d != NULL; d = d->next) {
					strcat(buf, d->value);
					if (d->next != NULL) strcat(buf, ",");
				}
				strcat(buf, "}");
				fprintf(out, " | %-8s", buf);
			}
			destroyRuntimeStringList(dests);
		}

		/* lambda column for LNFAs */
		if (hasLambda) {
			RuntimeStringList * dests = NULL;
			for (RuntimeTransition * t = automaton->transitions; t != NULL; t = t->next) {
				if (t->isLambda && strcmp(t->source, state->value) == 0) {
					for (RuntimeStringList * d = t->destinations; d != NULL; d = d->next) {
						appendUniqueRuntimeString(&dests, d->value);
					}
				}
			}
			if (dests == NULL) {
				fprintf(out, " | %-8s", "-");
			} else if (dests->next == NULL) {
				fprintf(out, " | %-8s", dests->value);
			} else {
				char buf[256] = "{";
				for (RuntimeStringList * d = dests; d != NULL; d = d->next) {
					strcat(buf, d->value);
					if (d->next != NULL) strcat(buf, ",");
				}
				strcat(buf, "}");
				fprintf(out, " | %-8s", buf);
			}
			destroyRuntimeStringList(dests);
		}
		fprintf(out, "\n");
	}
}

void showClosure(FILE * out, RuntimeAutomaton * automaton, const char * stateName) {
	RuntimeStringList * initial = NULL;
	appendRuntimeString(&initial, stateName);
	RuntimeStringList * closure = lambdaClosure(automaton, initial);
	destroyRuntimeStringList(initial);

	fprintf(out, "closure(%s) in %s = {", stateName, automaton->name);
	for (RuntimeStringList * s = closure; s != NULL; s = s->next) {
		fprintf(out, "%s%s", s->value, s->next ? ", " : "");
	}
	fprintf(out, "}\n");

	destroyRuntimeStringList(closure);
}

/* ------------------------------------------------------------------ */
/* Update                                                              */
/* ------------------------------------------------------------------ */

void applyUpdateStates(RuntimeAutomaton * automaton, StringList * newStates) {
	for (StringList * s = newStates; s != NULL; s = s->next) {
		appendUniqueRuntimeString(&automaton->states, s->value);
	}
}

void applyUpdateAccept(RuntimeAutomaton * automaton, StringList * newAccept) {
	destroyRuntimeStringList(automaton->acceptStates);
	automaton->acceptStates = NULL;
	for (StringList * s = newAccept; s != NULL; s = s->next) {
		appendRuntimeString(&automaton->acceptStates, s->value);
	}
}

void applyUpdateTransitions(RuntimeAutomaton * automaton, Transition * newTransitions) {
	for (Transition * t = newTransitions; t != NULL; t = t->next) {
		RuntimeTransition * rt = _runtimeTransitionFromAst(t);
		_removeTransitionsWithSameKey(automaton, rt);
		_appendRuntimeTransition(automaton, rt);
	}
}

/* ------------------------------------------------------------------ */
/* Equivalence                                                         */
/* ------------------------------------------------------------------ */

bool automatonsAreEquivalent(RuntimeAutomaton * left, RuntimeAutomaton * right) {
	/* TODO: implementar equivalencia (p. ej. convertir ambos a DFA y verificar
	   que la diferencia simétrica sea vacía). */
	(void) left;
	(void) right;
	return false;
}

/* ------------------------------------------------------------------ */
/* String utility                                                      */
/* ------------------------------------------------------------------ */

char * unquoteString(const char * value) {
	if (value == NULL) return NULL;
	size_t len = strlen(value);
	if (len >= 2 && value[0] == '"' && value[len - 1] == '"') {
		char * result = calloc(len - 1, sizeof(char));
		strncpy(result, value + 1, len - 2);
		return result;
	}
	return copyRuntimeString(value);
}
