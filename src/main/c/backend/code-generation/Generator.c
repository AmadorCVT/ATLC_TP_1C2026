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
static void _generateAutomaton(Automaton * automaton);
static void _generateStringDeclaration(StringDeclaration * stringDeclaration);
static void _generateConversion(Conversion * conversion);
static void _generateShow(Show * show);
static void _generatePrint(Print * print);
static void _generateTest(Test * test);
static void _generateEquivalent(Equivalent * equivalent);
static void _generateUpdate(Update * update);
static void _generateForLoop(For * for_loop);
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
		case AUTOMATON_STATEMENT:
			_generateAutomaton(statement->automaton);
			break;

		case STRING_DECLARATION_STATEMENT:
			_generateStringDeclaration(statement->stringDeclaration);
			break;

		case CONVERSION_STATEMENT:
			_generateConversion(statement->conversion);
			break;

		case SHOW_STATEMENT: 
			_generateShow(statement->show);
			break;

		case PRINT_STATEMENT:
			_generatePrint(statement->print);
			break;

		case TEST_STATEMENT:
			_generateTest(statement->test);
			break;

		case EQUIVALENT_STATEMENT:
			_generateEquivalent(statement->equivalent);
			break;

		case UPDATE_STATEMENT: {
			_generateUpdate(statement->update);
			break;
		}

		case FOR_STATEMENT:
			_generateForLoop(statement->for_loop);
			break;

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

static void _generateAutomaton(Automaton * automaton) {
	RuntimeAutomaton * runtimeAutomaton = runtimeAutomatonFromAst(automaton);
	if (runtimeSymbolTableAddAutomaton(_table, runtimeAutomaton->name, runtimeAutomaton)) {
		_output("**Automaton** %s (%s) declared.\n\n  --- \n\n", runtimeAutomaton->name, _typeName(runtimeAutomaton->type));
	}
	else {
		destroyRuntimeAutomaton(runtimeAutomaton);
	}
}

static void _generateStringDeclaration(StringDeclaration * stringDeclaration) {
	char * value = unquoteString(stringDeclaration->value);
	if (runtimeSymbolTableAddString(_table, stringDeclaration->id, value)) {
		_output("**string** %s = \"%s\"\n\n  --- \n\n", stringDeclaration->id, value);
	}
	else {
		free(value);
	}
}

static void _generateConversion(Conversion * conversion) {
	RuntimeAutomaton * source = _lookupAutomaton(conversion->input);
	if (source != NULL) {
		RuntimeAutomaton * result = _dispatchConversion(source, conversion->type, conversion->output);
		if (result != NULL && runtimeSymbolTableAddAutomaton(_table, result->name, result)) {
			_output("**convert** %s to %s as %s\n\n",
				conversion->input, _typeName(conversion->type), result->name);
			printAutomaton(output_file, result);
			_output("\n\n  --- \n\n");
		}
		else if (result != NULL) {
			destroyRuntimeAutomaton(result);
		}
	}
}

static void _generateShow(Show * show) {
	RuntimeAutomaton * automaton = _lookupAutomaton(show->id);
	if (automaton != NULL) {
		switch (show->type) {
			case SHOW_TRANSITIONS:
				_output("**show transitions** of %s\n\n", automaton->name);
				_output("```\n");
				showTransitions(output_file, automaton);
				_output("```\n\n  --- \n\n");
				break;
			case SHOW_TABLE:
				_output("**show table** of %s\n\n", automaton->name);
				_output("```\n");
				showTable(output_file, automaton);
				_output("```\n\n  --- \n\n");
				break;
			case SHOW_CLOSURE:
				_output("**show closure** of %s in %s\n\n", show->state, automaton->name);
				_output("```\n");
				showClosure(output_file, automaton, show->state);
				_output("```\n\n  --- \n\n");
				break;
		}
	}
}

static void _generatePrint(Print * print) {
	RuntimeAutomaton * automaton = _lookupAutomaton(print->id);
	if (automaton != NULL) {
		_output("**print** %s (%s)\n\n", automaton->name, _typeName(automaton->type));
		printAutomaton(output_file, automaton);
		_output("\n\n  --- \n\n");
	}
}

static void _generateTest(Test * test) {
	RuntimeAutomaton * automaton = _lookupAutomaton(test->id);
	if (automaton != NULL) {
		char * input = _resolveStringOperand(test->input);
		if (input != NULL) {
			bool accepted = simulateAutomaton(automaton, input);
			_output("**test** %s with \"%s\"\n\n", automaton->name, input);
			_output("**Result:** %s\n\n  --- \n\n", accepted ? "ACCEPTED" : "REJECTED");
			free(input);
		}
	}
}

static void _generateEquivalent(Equivalent * equivalent) {
	RuntimeAutomaton * left = _lookupAutomaton(equivalent->name1);
	RuntimeAutomaton * right = _lookupAutomaton(equivalent->name2);
	_output("**equivalent** %s == %s\n\n", equivalent->name1, equivalent->name2);
	if (left != NULL && right != NULL) {
		bool equiv = automatonsAreEquivalent(left, right);
		_output("**Result:** %s\n\n  --- \n\n", equiv ? "equivalent" : "not equivalent");
	}
}

static void _generateUpdate(Update * update) {
	RuntimeAutomaton * automaton = _lookupAutomaton(update->automatonName);
	if (automaton != NULL) {
		applyUpdateStates(automaton, update->states);
		if (update->acceptStates != NULL) {
			applyUpdateAccept(automaton, update->acceptStates);
		}
		applyUpdateTransitions(automaton, update->transitions);
		_output("**update** %s\n\n", automaton->name);
		printAutomaton(output_file, automaton);
		_output("\n --- \n");
	}
}

static void _generateForLoop(For * loop) {
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
		_output("\n", loop->index);
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
