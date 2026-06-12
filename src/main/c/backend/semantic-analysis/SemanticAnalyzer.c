#include "SemanticAnalyzer.h"
#include "../../frontend/syntactic-analysis/AbstractSyntaxTree.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

typedef enum {
	SEMANTIC_SYMBOL_AUTOMATON,
	SEMANTIC_SYMBOL_STRING
} SemanticSymbolType;
 
typedef struct SemanticStringList SemanticStringList;
typedef struct SemanticTransition SemanticTransition;
typedef struct SemanticAutomaton SemanticAutomaton;
typedef struct SemanticSymbol SemanticSymbol;

struct SemanticStringList {
	char * value;
	SemanticStringList * next;
};

struct SemanticTransition {
	char * source;
	char * symbol;
	bool isLambda;
	bool hadMultipleDestinations;
	SemanticStringList * destinations;
	SemanticTransition * next;
};

struct SemanticAutomaton {
	char * name;
	AutomatonType type;
	SemanticStringList * alphabet;
	SemanticStringList * states;
	char * startState;
	SemanticStringList * acceptStates;
	SemanticTransition * transitions;
	bool isDerived;
};

struct SemanticSymbol {
	char * name;
	SemanticSymbolType type;
	union {
		SemanticAutomaton * automaton;
		char * string;
	};
	SemanticSymbol * next;
};

struct SemanticScope {
	SemanticSymbol * symbols;
	SemanticScope * parent;
};

struct SemanticSymbolTable {
	SemanticScope * globalScope;
	SemanticScope * currentScope;
};

/* MODULE INTERNAL STATE */

static CompilerState * _compilerState = NULL;
static Logger * _logger = NULL;

/* PRIVATE FUNCTIONS */

static void _shutdownSemanticAnalyzerModule();
static void _reportSemanticError(const char * format, ...);
static const char * _automatonTypeAsString(AutomatonType type);
static char * _copyString(const char * value);
static bool _isQuotedString(const char * value);
static char * _unquoteString(const char * value);

static SemanticStringList * _createStringListNode(const char * value);
static SemanticStringList * _cloneAstStringList(StringList * list);
static SemanticStringList * _cloneSemanticStringList(SemanticStringList * list);
static void _destroySemanticStringList(SemanticStringList * list);
static bool _semanticStringListContains(SemanticStringList * list, const char * value);
static bool _semanticStringListHasDuplicates(SemanticStringList * list);
static unsigned int _semanticStringListLength(SemanticStringList * list);
static void _appendSemanticString(SemanticStringList ** list, const char * value);
static void _appendUniqueSemanticString(SemanticStringList ** list, const char * value);

static SemanticTransition * _cloneAstTransition(Transition * transition);
static SemanticTransition * _cloneSemanticTransition(SemanticTransition * transition);
static SemanticStringList * _cloneAstTransitionDestination(TransitionDestination * destination);
static void _destroySemanticTransition(SemanticTransition * transition);
static void _appendSemanticTransition(SemanticTransition ** list, SemanticTransition * transition);
static bool _sameTransitionKey(SemanticTransition * left, SemanticTransition * right);
static bool _hasEarlierTransitionWithSameKey(SemanticTransition * first, SemanticTransition * current);
static void _removeTransitionsWithSameKey(SemanticTransition ** list, SemanticTransition * transition);
static void _addOrReplaceTransition(SemanticAutomaton * automaton, SemanticTransition * transition);

static SemanticAutomaton * _createSemanticAutomatonFromAst(Automaton * automaton);
static SemanticAutomaton * _createDerivedSemanticAutomaton(const char * name, AutomatonType type, SemanticAutomaton * source);
static void _destroySemanticAutomaton(SemanticAutomaton * automaton);

static SemanticSymbolTable * _createSymbolTable();
static void _destroySymbolTable(SemanticSymbolTable * table);
static SemanticScope * _createScope(SemanticScope * parent);
static void _destroyScope(SemanticScope * scope);
static void _pushScope();
static void _popScope();
static SemanticSymbol * _lookupVisibleSymbol(const char * name);
static SemanticSymbol * _lookupCurrentSymbol(const char * name);
static bool _symbolExistsVisible(const char * name);
static bool _addAutomatonSymbol(const char * name, SemanticAutomaton * automaton);
static bool _addStringSymbol(const char * name, char * value);
static void _destroySemanticSymbol(SemanticSymbol * symbol);

static SemanticAutomaton * _requireAutomaton(const char * name, const char * usage);
static char * _requireString(const char * name, const char * usage);
static bool _isSupportedConversion(AutomatonType source, AutomatonType target);

static bool _validateSemanticAutomaton(SemanticAutomaton * automaton);
static bool _validateTransition(SemanticAutomaton * automaton, SemanticTransition * transition);
static void _validateProgram(Program * program);
static void _validateStatementList(Statement * statement);
static void _validateStatement(Statement * statement);
static void _validateAutomatonStatement(Automaton * automaton);
static void _validateStringDeclarationStatement(StringDeclaration * declaration);
static void _validateConversionStatement(Conversion * conversion);
static void _validateShowStatement(Show * show);
static void _validatePrintStatement(Print * print);
static void _validateEquivalentStatement(Equivalent * equivalent);
static void _validateTestStatement(Test * test);
static void _validateForStatement(For * forLoop);
static void _validateUpdateStatement(Update * update);

/* MODULE LIFECYCLE */

static void _shutdownSemanticAnalyzerModule() {
	if (_compilerState != NULL) {
		_destroySymbolTable(_compilerState->symbolTable);
		_compilerState->symbolTable = NULL;
		_compilerState->scopeStack = NULL;
		_compilerState = NULL;
	}
	if (_logger != NULL) {
		logDebugging(_logger, "Destroying module: SemanticAnalyzer...");
		destroyLogger(_logger);
		_logger = NULL;
	}
}

ModuleDestructor initializeSemanticAnalyzerModule() {
	_logger = createLogger("SemanticAnalyzer");
	return _shutdownSemanticAnalyzerModule;
}

/* DIAGNOSTICS */

static void _reportSemanticError(const char * format, ...) {
	char buffer[1024];
	va_list arguments;
	va_start(arguments, format);
	vsnprintf(buffer, sizeof(buffer), format, arguments);
	va_end(arguments);
	logError(_logger, "%s", buffer);
	if (_compilerState != NULL) {
		_compilerState->hasSemanticErrors = true;
	}
}

static const char * _automatonTypeAsString(AutomatonType type) {
	switch (type) {
		case DFA: return "DFA";
		case NFA: return "NFA";
		case LNFA: return "LNFA";
		default: return "UNKNOWN";
	}
}

/* STRING HELPERS */

static char * _copyString(const char * value) {
	if (value == NULL) {
		return NULL;
	}
	char * copy = calloc(strlen(value) + 1, sizeof(char));
	strcpy(copy, value);
	return copy;
}

static bool _isQuotedString(const char * value) {
	if (value == NULL) {
		return false;
	}
	size_t length = strlen(value);
	return 2 <= length && value[0] == '"' && value[length - 1] == '"';
}

static char * _unquoteString(const char * value) {
	if (!_isQuotedString(value)) {
		return _copyString(value);
	}
	size_t length = strlen(value);
	char * copy = calloc(length - 1, sizeof(char));
	strncpy(copy, value + 1, length - 2);
	return copy;
}

/* STRING LIST HELPERS */

static SemanticStringList * _createStringListNode(const char * value) {
	SemanticStringList * node = calloc(1, sizeof(SemanticStringList));
	node->value = _copyString(value);
	return node;
}

static SemanticStringList * _cloneAstStringList(StringList * list) {
	SemanticStringList * clone = NULL;
	for (StringList * current = list; current != NULL; current = current->next) {
		_appendSemanticString(&clone, current->value);
	}
	return clone;
}

static SemanticStringList * _cloneSemanticStringList(SemanticStringList * list) {
	SemanticStringList * clone = NULL;
	for (SemanticStringList * current = list; current != NULL; current = current->next) {
		_appendSemanticString(&clone, current->value);
	}
	return clone;
}

static void _destroySemanticStringList(SemanticStringList * list) {
	while (list != NULL) {
		SemanticStringList * next = list->next;
		free(list->value);
		free(list);
		list = next;
	}
}

static bool _semanticStringListContains(SemanticStringList * list, const char * value) {
	for (SemanticStringList * current = list; current != NULL; current = current->next) {
		if (strcmp(current->value, value) == 0) {
			return true;
		}
	}
	return false;
}

static bool _semanticStringListHasDuplicates(SemanticStringList * list) {
	for (SemanticStringList * current = list; current != NULL; current = current->next) {
		if (_semanticStringListContains(current->next, current->value)) {
			return true;
		}
	}
	return false;
}

static unsigned int _semanticStringListLength(SemanticStringList * list) {
	unsigned int length = 0;
	for (SemanticStringList * current = list; current != NULL; current = current->next) {
		length++;
	}
	return length;
}

static void _appendSemanticString(SemanticStringList ** list, const char * value) {
	SemanticStringList * node = _createStringListNode(value);
	if (*list == NULL) {
		*list = node;
		return;
	}
	SemanticStringList * last = *list;
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = node;
}

static void _appendUniqueSemanticString(SemanticStringList ** list, const char * value) {
	if (!_semanticStringListContains(*list, value)) {
		_appendSemanticString(list, value);
	}
}

/* TRANSITION HELPERS */

static SemanticTransition * _cloneAstTransition(Transition * transition) {
	if (transition == NULL) {
		return NULL;
	}
	SemanticTransition * clone = calloc(1, sizeof(SemanticTransition));
	clone->source = _copyString(transition->source);
	clone->isLambda = transition->symbol->isLambda;
	clone->hadMultipleDestinations = transition->destination->type == MULTIPLE_TRANSITION_DESTINATIONS;
	if (!clone->isLambda) {
		clone->symbol = _copyString(transition->symbol->value);
	}
	clone->destinations = _cloneAstTransitionDestination(transition->destination);
	return clone;
}

static SemanticTransition * _cloneSemanticTransition(SemanticTransition * transition) {
	if (transition == NULL) {
		return NULL;
	}
	SemanticTransition * clone = calloc(1, sizeof(SemanticTransition));
	clone->source = _copyString(transition->source);
	clone->symbol = _copyString(transition->symbol);
	clone->isLambda = transition->isLambda;
	clone->hadMultipleDestinations = transition->hadMultipleDestinations;
	clone->destinations = _cloneSemanticStringList(transition->destinations);
	return clone;
}

static SemanticStringList * _cloneAstTransitionDestination(TransitionDestination * destination) {
	if (destination == NULL) {
		return NULL;
	}
	switch (destination->type) {
		case SINGLE_TRANSITION_DESTINATION:
			return _createStringListNode(destination->state);
		case MULTIPLE_TRANSITION_DESTINATIONS:
			return _cloneAstStringList(destination->states);
		default:
			return NULL;
	}
}

static void _destroySemanticTransition(SemanticTransition * transition) {
	while (transition != NULL) {
		SemanticTransition * next = transition->next;
		free(transition->source);
		free(transition->symbol);
		_destroySemanticStringList(transition->destinations);
		free(transition);
		transition = next;
	}
}

static void _appendSemanticTransition(SemanticTransition ** list, SemanticTransition * transition) {
	if (transition == NULL) {
		return;
	}
	if (*list == NULL) {
		*list = transition;
		return;
	}
	SemanticTransition * last = *list;
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = transition;
}

static bool _sameTransitionKey(SemanticTransition * left, SemanticTransition * right) {
	if (left == NULL || right == NULL) {
		return false;
	}
	if (strcmp(left->source, right->source) != 0) {
		return false;
	}
	if (left->isLambda != right->isLambda) {
		return false;
	}
	if (left->isLambda) {
		return true;
	}
	return strcmp(left->symbol, right->symbol) == 0;
}

static bool _hasEarlierTransitionWithSameKey(SemanticTransition * first, SemanticTransition * current) {
	for (SemanticTransition * transition = first; transition != NULL && transition != current; transition = transition->next) {
		if (_sameTransitionKey(transition, current)) {
			return true;
		}
	}
	return false;
}

static void _removeTransitionsWithSameKey(SemanticTransition ** list, SemanticTransition * transition) {
	SemanticTransition * current = *list;
	SemanticTransition * previous = NULL;
	while (current != NULL) {
		SemanticTransition * next = current->next;
		if (_sameTransitionKey(current, transition)) {
			if (previous == NULL) {
				*list = next;
			}
			else {
				previous->next = next;
			}
			current->next = NULL;
			_destroySemanticTransition(current);
		}
		else {
			previous = current;
		}
		current = next;
	}
}

static void _addOrReplaceTransition(SemanticAutomaton * automaton, SemanticTransition * transition) {
	_removeTransitionsWithSameKey(&automaton->transitions, transition);
	_appendSemanticTransition(&automaton->transitions, transition);
}

/* AUTOMATA HELPERS */

static SemanticAutomaton * _createSemanticAutomatonFromAst(Automaton * automaton) {
	SemanticAutomaton * semanticAutomaton = calloc(1, sizeof(SemanticAutomaton));
	semanticAutomaton->name = _copyString(automaton->id);
	semanticAutomaton->type = automaton->type;
	semanticAutomaton->alphabet = _cloneAstStringList(automaton->definition->alphabet);
	semanticAutomaton->states = _cloneAstStringList(automaton->definition->states);
	semanticAutomaton->startState = _copyString(automaton->definition->startState);
	semanticAutomaton->acceptStates = _cloneAstStringList(automaton->definition->acceptStates);
	semanticAutomaton->isDerived = false;
	for (Transition * transition = automaton->definition->transitions; transition != NULL; transition = transition->next) {
		_appendSemanticTransition(&semanticAutomaton->transitions, _cloneAstTransition(transition));
	}
	return semanticAutomaton;
}

static SemanticAutomaton * _createDerivedSemanticAutomaton(const char * name, AutomatonType type, SemanticAutomaton * source) {
	SemanticAutomaton * automaton = calloc(1, sizeof(SemanticAutomaton));
	automaton->name = _copyString(name);
	automaton->type = type;
	automaton->alphabet = _cloneSemanticStringList(source->alphabet);
	automaton->states = _cloneSemanticStringList(source->states);
	automaton->startState = _copyString(source->startState);
	automaton->acceptStates = _cloneSemanticStringList(source->acceptStates);
	automaton->isDerived = true;
	return automaton;
}

static void _destroySemanticAutomaton(SemanticAutomaton * automaton) {
	if (automaton != NULL) {
		free(automaton->name);
		_destroySemanticStringList(automaton->alphabet);
		_destroySemanticStringList(automaton->states);
		free(automaton->startState);
		_destroySemanticStringList(automaton->acceptStates);
		_destroySemanticTransition(automaton->transitions);
		free(automaton);
	}
}

/* SYMBOL TABLE HELPERS */

static SemanticSymbolTable * _createSymbolTable() {
	SemanticSymbolTable * table = calloc(1, sizeof(SemanticSymbolTable));
	table->globalScope = _createScope(NULL);
	table->currentScope = table->globalScope;
	return table;
}

static void _destroySymbolTable(SemanticSymbolTable * table) {
	if (table != NULL) {
		SemanticScope * current = table->currentScope;
		while (current != NULL) {
			SemanticScope * parent = current->parent;
			_destroyScope(current);
			current = parent;
		}
		free(table);
	}
}

static SemanticScope * _createScope(SemanticScope * parent) {
	SemanticScope * scope = calloc(1, sizeof(SemanticScope));
	scope->parent = parent;
	return scope;
}

static void _destroyScope(SemanticScope * scope) {
	if (scope != NULL) {
		SemanticSymbol * symbol = scope->symbols;
		while (symbol != NULL) {
			SemanticSymbol * next = symbol->next;
			_destroySemanticSymbol(symbol);
			symbol = next;
		}
		free(scope);
	}
}

static void _pushScope() {
	SemanticScope * scope = _createScope(_compilerState->symbolTable->currentScope);
	_compilerState->symbolTable->currentScope = scope;
	_compilerState->scopeStack = scope;
}

static void _popScope() {
	SemanticScope * scope = _compilerState->symbolTable->currentScope;
	if (scope == NULL || scope->parent == NULL) {
		return;
	}
	_compilerState->symbolTable->currentScope = scope->parent;
	_compilerState->scopeStack = scope->parent;
	_destroyScope(scope);
}

static SemanticSymbol * _lookupVisibleSymbol(const char * name) {
	for (SemanticScope * scope = _compilerState->symbolTable->currentScope; scope != NULL; scope = scope->parent) {
		for (SemanticSymbol * symbol = scope->symbols; symbol != NULL; symbol = symbol->next) {
			if (strcmp(symbol->name, name) == 0) {
				return symbol;
			}
		}
	}
	return NULL;
}

static SemanticSymbol * _lookupCurrentSymbol(const char * name) {
	SemanticScope * scope = _compilerState->symbolTable->currentScope;
	if (scope == NULL) {
		return NULL;
	}
	for (SemanticSymbol * symbol = scope->symbols; symbol != NULL; symbol = symbol->next) {
		if (strcmp(symbol->name, name) == 0) {
			return symbol;
		}
	}
	return NULL;
}

static bool _symbolExistsVisible(const char * name) {
	return _lookupVisibleSymbol(name) != NULL;
}

static bool _addAutomatonSymbol(const char * name, SemanticAutomaton * automaton) {
	if (_lookupCurrentSymbol(name) != NULL) {
		return false;
	}
	SemanticSymbol * symbol = calloc(1, sizeof(SemanticSymbol));
	symbol->name = _copyString(name);
	symbol->type = SEMANTIC_SYMBOL_AUTOMATON;
	symbol->automaton = automaton;
	symbol->next = _compilerState->symbolTable->currentScope->symbols;
	_compilerState->symbolTable->currentScope->symbols = symbol;
	return true;
}

static bool _addStringSymbol(const char * name, char * value) {
	if (_lookupCurrentSymbol(name) != NULL) {
		return false;
	}
	SemanticSymbol * symbol = calloc(1, sizeof(SemanticSymbol));
	symbol->name = _copyString(name);
	symbol->type = SEMANTIC_SYMBOL_STRING;
	symbol->string = value;
	symbol->next = _compilerState->symbolTable->currentScope->symbols;
	_compilerState->symbolTable->currentScope->symbols = symbol;
	return true;
}

static void _destroySemanticSymbol(SemanticSymbol * symbol) {
	if (symbol != NULL) {
		free(symbol->name);
		switch (symbol->type) {
			case SEMANTIC_SYMBOL_AUTOMATON:
				_destroySemanticAutomaton(symbol->automaton);
				break;
			case SEMANTIC_SYMBOL_STRING:
				free(symbol->string);
				break;
			default:
				break;
		}
		free(symbol);
	}
}

/* SYMBOL REQUIREMENTS */

static SemanticAutomaton * _requireAutomaton(const char * name, const char * usage) {
	SemanticSymbol * symbol = _lookupVisibleSymbol(name);
	if (symbol == NULL) {
		_reportSemanticError("Cannot %s undeclared automaton '%s'.", usage, name);
		return NULL;
	}
	if (symbol->type != SEMANTIC_SYMBOL_AUTOMATON) {
		_reportSemanticError("Symbol '%s' is not an automaton for %s.", name, usage);
		return NULL;
	}
	return symbol->automaton;
}

static char * _requireString(const char * name, const char * usage) {
	SemanticSymbol * symbol = _lookupVisibleSymbol(name);
	if (symbol == NULL) {
		_reportSemanticError("Cannot %s undeclared string '%s'.", usage, name);
		return NULL;
	}
	if (symbol->type != SEMANTIC_SYMBOL_STRING) {
		_reportSemanticError("Symbol '%s' is not a string for %s.", name, usage);
		return NULL;
	}
	return symbol->string;
}

static bool _isSupportedConversion(AutomatonType source, AutomatonType target) {
	return (source == DFA && target == NFA)
		|| (source == NFA && target == DFA)
		|| (source == LNFA && target == NFA)
		|| (source == LNFA && target == DFA);
}

/* DOMAIN VALIDATION */

static bool _validateSemanticAutomaton(SemanticAutomaton * automaton) {
	bool isValid = true;
	if (_semanticStringListHasDuplicates(automaton->states)) {
		_reportSemanticError("Automaton '%s' declares duplicated states.", automaton->name);
		isValid = false;
	}
	if (_semanticStringListHasDuplicates(automaton->alphabet)) {
		_reportSemanticError("Automaton '%s' declares duplicated symbols in its alphabet.", automaton->name);
		isValid = false;
	}
	if (_semanticStringListContains(automaton->alphabet, "lambda")) {
		_reportSemanticError("Automaton '%s' cannot declare lambda as a regular alphabet symbol.", automaton->name);
		isValid = false;
	}
	if (!_semanticStringListContains(automaton->states, automaton->startState)) {
		_reportSemanticError("Automaton '%s' start state '%s' is not declared in states.", automaton->name, automaton->startState);
		isValid = false;
	}
	for (SemanticStringList * accept = automaton->acceptStates; accept != NULL; accept = accept->next) {
		if (!_semanticStringListContains(automaton->states, accept->value)) {
			_reportSemanticError("Automaton '%s' accept state '%s' is not declared in states.", automaton->name, accept->value);
			isValid = false;
		}
	}
	for (SemanticTransition * transition = automaton->transitions; transition != NULL; transition = transition->next) {
		if (!_validateTransition(automaton, transition)) {
			isValid = false;
		}
		if (automaton->type == DFA && _hasEarlierTransitionWithSameKey(automaton->transitions, transition)) {
			_reportSemanticError("DFA '%s' declares more than one transition for state '%s' and symbol '%s'.",
				automaton->name,
				transition->source,
				transition->isLambda ? "lambda" : transition->symbol);
			isValid = false;
		}
	}
	return isValid;
}

static bool _validateTransition(SemanticAutomaton * automaton, SemanticTransition * transition) {
	bool isValid = true;
	if (!_semanticStringListContains(automaton->states, transition->source)) {
		_reportSemanticError("Automaton '%s' transition source '%s' is not declared in states.", automaton->name, transition->source);
		isValid = false;
	}
	if (transition->isLambda) {
		if (automaton->type != LNFA) {
			_reportSemanticError("%s '%s' cannot use lambda transitions.", _automatonTypeAsString(automaton->type), automaton->name);
			isValid = false;
		}
	}
	else if (!_semanticStringListContains(automaton->alphabet, transition->symbol)) {
		_reportSemanticError("Automaton '%s' transition symbol '%s' is not declared in alphabet.", automaton->name, transition->symbol);
		isValid = false;
	}
	if (automaton->type == DFA && (transition->hadMultipleDestinations || _semanticStringListLength(transition->destinations) != 1)) {
		_reportSemanticError("DFA '%s' transition from '%s' with symbol '%s' must use a single destination.",
			automaton->name,
			transition->source,
			transition->isLambda ? "lambda" : transition->symbol);
		isValid = false;
	}
	for (SemanticStringList * destination = transition->destinations; destination != NULL; destination = destination->next) {
		if (!_semanticStringListContains(automaton->states, destination->value)) {
			_reportSemanticError("Automaton '%s' transition destination '%s' is not declared in states.", automaton->name, destination->value);
			isValid = false;
		}
	}
	return isValid;
}

/* AST WALK */

static void _validateProgram(Program * program) {
	if (program == NULL) {
		_reportSemanticError("Cannot semantically analyze an empty AST.");
		return;
	}
	_validateStatementList(program->statements);
}

static void _validateStatementList(Statement * statement) {
	for (Statement * current = statement; current != NULL; current = current->next) {
		_validateStatement(current);
	}
}

static void _validateStatement(Statement * statement) {
	switch (statement->type) {
		case AUTOMATON_STATEMENT:
			_validateAutomatonStatement(statement->automaton);
			break;
		case STRING_DECLARATION_STATEMENT:
			_validateStringDeclarationStatement(statement->stringDeclaration);
			break;
		case CONVERSION_STATEMENT:
			_validateConversionStatement(statement->conversion);
			break;
		case SHOW_STATEMENT:
			_validateShowStatement(statement->show);
			break;
		case PRINT_STATEMENT:
			_validatePrintStatement(statement->print);
			break;
		case EQUIVALENT_STATEMENT:
			_validateEquivalentStatement(statement->equivalent);
			break;
		case TEST_STATEMENT:
			_validateTestStatement(statement->test);
			break;
		case FOR_STATEMENT:
			_validateForStatement(statement->for_loop);
			break;
		case UPDATE_STATEMENT:
			_validateUpdateStatement(statement->update);
			break;
		default:
			_reportSemanticError("Cannot validate unknown statement type: %d.", statement->type);
			break;
	}
}

static void _validateAutomatonStatement(Automaton * automaton) {
	if (_symbolExistsVisible(automaton->id)) {
		_reportSemanticError("Symbol '%s' is already declared.", automaton->id);
		return;
	}
	SemanticAutomaton * semanticAutomaton = _createSemanticAutomatonFromAst(automaton);
	if (_validateSemanticAutomaton(semanticAutomaton)) {
		_addAutomatonSymbol(semanticAutomaton->name, semanticAutomaton);
	}
	else {
		_destroySemanticAutomaton(semanticAutomaton);
	}
}

static void _validateStringDeclarationStatement(StringDeclaration * declaration) {
	if (_symbolExistsVisible(declaration->id)) {
		_reportSemanticError("Symbol '%s' is already declared.", declaration->id);
		return;
	}
	char * value = _unquoteString(declaration->value);
	if (!_addStringSymbol(declaration->id, value)) {
		free(value);
		_reportSemanticError("String '%s' is already declared in the current scope.", declaration->id);
	}
}

static void _validateConversionStatement(Conversion * conversion) {
	SemanticAutomaton * source = _requireAutomaton(conversion->input, "convert");
	if (source == NULL) {
		return;
	}
	if (_symbolExistsVisible(conversion->output)) {
		_reportSemanticError("Conversion output symbol '%s' is already declared.", conversion->output);
		return;
	}
	if (!_isSupportedConversion(source->type, conversion->type)) {
		_reportSemanticError("Conversion from %s to %s is not supported.",
			_automatonTypeAsString(source->type),
			_automatonTypeAsString(conversion->type));
		return;
	}
	SemanticAutomaton * derived = _createDerivedSemanticAutomaton(conversion->output, conversion->type, source);
	_addAutomatonSymbol(derived->name, derived);
}

static void _validateShowStatement(Show * show) {
	SemanticAutomaton * automaton = _requireAutomaton(show->id, "show");
	if (automaton == NULL) {
		return;
	}
	if (show->type == SHOW_CLOSURE && !_semanticStringListContains(automaton->states, show->state)) {
		_reportSemanticError("Cannot show closure of undeclared state '%s' in automaton '%s'.", show->state, show->id);
	}
}

static void _validatePrintStatement(Print * print) {
	_requireAutomaton(print->id, "print");
}

static void _validateEquivalentStatement(Equivalent * equivalent) {
	_requireAutomaton(equivalent->name1, "compare equivalence");
	_requireAutomaton(equivalent->name2, "compare equivalence");
}

static void _validateTestStatement(Test * test) {
	_requireAutomaton(test->id, "test");
	if (test->inputType == TEST_INPUT_VARIABLE) {
		_requireString(test->input, "test");
	}
}

static void _validateForStatement(For * forLoop) {
	bool indexAlreadyExists = _symbolExistsVisible(forLoop->index);
	if (indexAlreadyExists) {
		_reportSemanticError("For index '%s' shadows an existing symbol.", forLoop->index);
	}
	for (StringList * value = forLoop->values; value != NULL; value = value->next) {
		if (!_isQuotedString(value->value)) {
			_requireString(value->value, "iterate");
		}
	}
	_pushScope();
	char * iterationValue = _copyString("");
	_addStringSymbol(forLoop->index, iterationValue);
	_validateStatementList(forLoop->statements);
	_popScope();
}

static void _validateUpdateStatement(Update * update) {
	SemanticAutomaton * automaton = _requireAutomaton(update->automatonName, "update");
	if (automaton == NULL) {
		return;
	}
	for (StringList * state = update->states; state != NULL; state = state->next) {
		_appendUniqueSemanticString(&automaton->states, state->value);
	}
	if (update->acceptStates != NULL) {
		bool acceptIsValid = true;
		for (StringList * accept = update->acceptStates; accept != NULL; accept = accept->next) {
			if (!_semanticStringListContains(automaton->states, accept->value)) {
				_reportSemanticError("Automaton '%s' update uses undeclared accept state '%s'.", automaton->name, accept->value);
				acceptIsValid = false;
			}
		}
		if (acceptIsValid) {
			_destroySemanticStringList(automaton->acceptStates);
			automaton->acceptStates = _cloneAstStringList(update->acceptStates);
		}
	}
	for (Transition * transition = update->transitions; transition != NULL; transition = transition->next) {
		_addOrReplaceTransition(automaton, _cloneAstTransition(transition));
	}
	_validateSemanticAutomaton(automaton);
}

/* PUBLIC FUNCTIONS */

CompilationStatus executeSemanticAnalysis(CompilerState * compilerState) {
	logDebugging(_logger, "Running semantic analysis...");
	_compilerState = compilerState;
	_destroySymbolTable(_compilerState->symbolTable);
	_compilerState->symbolTable = _createSymbolTable();
	_compilerState->scopeStack = _compilerState->symbolTable->currentScope;
	_compilerState->hasSemanticErrors = false;
	_validateProgram((Program *) _compilerState->abstractSyntaxtTree);
	if (_compilerState->hasSemanticErrors) {
		logDebugging(_logger, "Semantic analysis rejected the program.");
		return FAILED;
	}
	logDebugging(_logger, "Semantic analysis accepted the program.");
	return SUCCEEDED;
}
