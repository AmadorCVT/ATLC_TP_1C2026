#include "Generator.h"
#include "../domain-specific/Automaton.h"

/* MODULE INTERNAL STATE */

static Logger * _logger = NULL;
static FILE * output_file = NULL;

/* The generator is a tree-walking interpreter: it re-executes the validated AST
 * using the shared domain API, keeping its own symbol table. Conversions and
 * for-loops need real execution (the semantic table only holds metadata shells
 * and discards loop scopes), so the generator owns this table rather than
 * consuming compilerState->symbolTable. */
static RuntimeSymbolTable * _table = NULL;

/** Shutdown module's internal state. */
void _shutdownGeneratorModule() {
	if (_logger != NULL) {
		logDebugging(_logger, "Destroying module: Generator...");
		destroyLogger(_logger);
		_logger = NULL;
	}
}

ModuleDestructor initializeGeneratorModule() {
	_logger = createLogger("Generator");
	return _shutdownGeneratorModule;
}

/** PRIVATE FUNCTIONS */

static void _generateProgram(Program * program);
static void _generateStatement(Statement * statement);
static void _generatePrologue(void);
static void _output(const char * const format, ...);

static const char * _typeName(AutomatonType type);
static RuntimeAutomaton * _lookupAutomaton(const char * name);
static const char * _lookupString(const char * name);
static char * _resolveStringOperand(const char * token);
static RuntimeAutomaton * _dispatchConversion(RuntimeAutomaton * source, AutomatonType target, const char * newName);

/* HELPERS */

static const char * _typeName(AutomatonType type) {
	switch (type) {
		case DFA: return "DFA";
		case NFA: return "NFA";
		case LNFA: return "LNFA";
		default: return "UNKNOWN";
	}
}

static RuntimeAutomaton * _lookupAutomaton(const char * name) {
	RuntimeSymbol * symbol = runtimeSymbolTableLookupVisible(_table, name);
	if (symbol == NULL || symbol->type != RUNTIME_SYMBOL_AUTOMATON) {
		return NULL;
	}
	return symbol->automaton;
}

static const char * _lookupString(const char * name) {
	RuntimeSymbol * symbol = runtimeSymbolTableLookupVisible(_table, name);
	if (symbol == NULL || symbol->type != RUNTIME_SYMBOL_STRING) {
		return NULL;
	}
	return symbol->string;
}

/* Resolves a string operand (used by `test` and `for`): a quoted literal is
 * unquoted; a bare identifier is looked up as a string variable. Returns a
 * heap-allocated string the caller must free, or NULL if undeclared. */
static char * _resolveStringOperand(const char * token) {
	if (isQuotedString(token)) {
		return unquoteString(token);
	}
	const char * value = _lookupString(token);
	if (value == NULL) {
		return NULL;
	}
	return copyRuntimeString(value);
}

static RuntimeAutomaton * _dispatchConversion(RuntimeAutomaton * source, AutomatonType target, const char * newName) {
	if (source->type == DFA  && target == NFA) return convertDFAtoNFA(source, newName);
	if (source->type == NFA  && target == DFA) return convertNFAtoDFA(source, newName);
	if (source->type == LNFA && target == NFA) return convertLNFAtoNFA(source, newName);
	if (source->type == LNFA && target == DFA) return convertLNFAtoDFA(source, newName);
	return NULL;
}

/* STATEMENT DISPATCH */

static void _generateStatement(Statement * statement) {
	switch (statement->type) {
		case AUTOMATON_STATEMENT: {
			RuntimeAutomaton * automaton = runtimeAutomatonFromAst(statement->automaton);
			if (runtimeSymbolTableAddAutomaton(_table, automaton->name, automaton)) {
				_output("## automaton %s (%s)\n\n", automaton->name, _typeName(automaton->type));
				_output("```\n");
				printAutomaton(output_file, automaton);
				_output("```\n\n");
			}
			else {
				destroyRuntimeAutomaton(automaton);
			}
			break;
		}

		case STRING_DECLARATION_STATEMENT: {
			char * value = unquoteString(statement->stringDeclaration->value);
			if (runtimeSymbolTableAddString(_table, statement->stringDeclaration->id, value)) {
				_output("## string %s = \"%s\"\n\n", statement->stringDeclaration->id, value);
			}
			else {
				free(value);
			}
			break;
		}

		case CONVERSION_STATEMENT: {
			RuntimeAutomaton * source = _lookupAutomaton(statement->conversion->input);
			if (source != NULL) {
				RuntimeAutomaton * result = _dispatchConversion(source, statement->conversion->type, statement->conversion->output);
				if (result != NULL && runtimeSymbolTableAddAutomaton(_table, result->name, result)) {
					_output("## convert %s to %s as %s\n\n",
						statement->conversion->input, _typeName(statement->conversion->type), result->name);
					_output("```\n");
					printAutomaton(output_file, result);
					_output("```\n\n");
				}
				else if (result != NULL) {
					destroyRuntimeAutomaton(result);
				}
			}
			break;
		}

		case SHOW_STATEMENT: {
			RuntimeAutomaton * automaton = _lookupAutomaton(statement->show->id);
			if (automaton != NULL) {
				switch (statement->show->type) {
					case SHOW_TRANSITIONS:
						_output("## show transitions of %s\n\n", automaton->name);
						_output("```\n");
						showTransitions(output_file, automaton);
						_output("```\n\n");
						break;
					case SHOW_TABLE:
						_output("## show table of %s\n\n", automaton->name);
						_output("```\n");
						showTable(output_file, automaton);
						_output("```\n\n");
						break;
					case SHOW_CLOSURE:
						_output("## show closure of %s in %s\n\n", statement->show->state, automaton->name);
						_output("```\n");
						showClosure(output_file, automaton, statement->show->state);
						_output("```\n\n");
						break;
				}
			}
			break;
		}

		case PRINT_STATEMENT: {
			RuntimeAutomaton * automaton = _lookupAutomaton(statement->print->id);
			if (automaton != NULL) {
				_output("## print %s (%s)\n\n", automaton->name, _typeName(automaton->type));
				_output("```\n");
				printAutomaton(output_file, automaton);
				_output("```\n\n");
			}
			break;
		}

		case TEST_STATEMENT: {
			RuntimeAutomaton * automaton = _lookupAutomaton(statement->test->id);
			if (automaton != NULL) {
				char * input = _resolveStringOperand(statement->test->input);
				if (input != NULL) {
					bool accepted = simulateAutomaton(automaton, input);
					_output("## test %s with \"%s\"\n\n", automaton->name, input);
					_output("**Result:** %s\n\n", accepted ? "ACCEPTED" : "REJECTED");
					free(input);
				}
			}
			break;
		}

		case EQUIVALENT_STATEMENT: {
			RuntimeAutomaton * left = _lookupAutomaton(statement->equivalent->name1);
			RuntimeAutomaton * right = _lookupAutomaton(statement->equivalent->name2);
			_output("## equivalent %s == %s\n\n", statement->equivalent->name1, statement->equivalent->name2);
			if (left != NULL && right != NULL) {
				automatonsAreEquivalent(left, right);
			}
			_output("**Result:** TODO (equivalence not implemented)\n\n");
			break;
		}

		case UPDATE_STATEMENT: {
			RuntimeAutomaton * automaton = _lookupAutomaton(statement->update->automatonName);
			if (automaton != NULL) {
				applyUpdateStates(automaton, statement->update->states);
				if (statement->update->acceptStates != NULL) {
					applyUpdateAccept(automaton, statement->update->acceptStates);
				}
				applyUpdateTransitions(automaton, statement->update->transitions);
				_output("## update %s\n\n", automaton->name);
				_output("```\n");
				printAutomaton(output_file, automaton);
				_output("```\n\n");
			}
			break;
		}

		case FOR_STATEMENT: {
			For * loop = statement->for_loop;
			_output("## for %s\n\n", loop->index);
			for (StringList * value = loop->values; value != NULL; value = value->next) {
				char * resolved = _resolveStringOperand(value->value);
				if (resolved == NULL) {
					continue;
				}
				runtimeSymbolTablePushScope(_table);
				runtimeSymbolTableAddString(_table, loop->index, resolved);
				_output("### %s = \"%s\"\n\n", loop->index, resolved);
				for (Statement * body = loop->statements; body != NULL; body = body->next) {
					_generateStatement(body);
				}
				runtimeSymbolTablePopScope(_table);
			}
			break;
		}

		default:
			logError(_logger, "The specified statement type is unknown: %d", statement->type);
			break;
	}
}

/**
 * Creates the prologue of the generated output, a MarkDown document that
 * renders the operations being made.
 */
static void _generatePrologue(void) {
	_output("%s\n\n", "# Automaton program");
}

/**
 * Walks every statement in the program, in order.
 */
static void _generateProgram(Program * program) {
	if (program == NULL) {
		return;
	}
	for (Statement * statement = program->statements; statement != NULL; statement = statement->next) {
		_generateStatement(statement);
	}
}

/**
 * Outputs a formatted string to the output file. The "fflush" instruction
 * allows to see the output even close to a failure, because it drops the
 * buffering.
 */
static void _output(const char * const format, ...) {
	va_list arguments;
	va_start(arguments, format);
	vfprintf(output_file, format, arguments);
	fflush(output_file);
	va_end(arguments);
}

/** PUBLIC FUNCTIONS */

void executeGenerator(CompilerState * compilerState) {
	logDebugging(_logger, "Generating final output...");

	output_file = fopen("output.md", "w");
	_table = runtimeSymbolTableCreate();

	_generatePrologue();
	_generateProgram(compilerState->abstractSyntaxtTree);

	runtimeSymbolTableDestroy(_table);
	_table = NULL;
	fclose(output_file);

	logDebugging(_logger, "Generation is done.");
}
