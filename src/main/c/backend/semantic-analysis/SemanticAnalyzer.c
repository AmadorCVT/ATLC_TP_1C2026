#include "SemanticAnalyzer.h"
#include "../../frontend/syntactic-analysis/AbstractSyntaxTree.h"
#include "../domain-specific/Automaton.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/* The automaton representation, the scoped symbol table and all the data-structure
 * helpers live in the domain-specific Automaton module and are shared with the
 * code generator. This module only adds the validation logic on top of them. */

/* MODULE INTERNAL STATE */

static CompilerState * _compilerState = NULL;
static Logger * _logger = NULL;

/* PRIVATE FUNCTIONS */

static void _shutdownSemanticAnalyzerModule();
static void _reportSemanticError(const char * format, ...);
static const char * _automatonTypeAsString(AutomatonType type);

static RuntimeSymbol * _lookupVisible(const char * name);
static bool _symbolExistsVisible(const char * name);
static bool _addAutomaton(const char * name, RuntimeAutomaton * automaton);
static bool _addString(const char * name, char * value);
static void _pushScope();
static void _popScope();

static RuntimeAutomaton * _requireAutomaton(const char * name, const char * usage);
static char * _requireString(const char * name, const char * usage);
static bool _isSupportedConversion(AutomatonType source, AutomatonType target);

static bool _validateAutomaton(RuntimeAutomaton * automaton);
static bool _validateTransition(RuntimeAutomaton * automaton, RuntimeTransition * transition);
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
		runtimeSymbolTableDestroy(_compilerState->symbolTable);
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

/* SYMBOL TABLE WRAPPERS */

static RuntimeSymbol * _lookupVisible(const char * name) {
	return runtimeSymbolTableLookupVisible(_compilerState->symbolTable, name);
}

static bool _symbolExistsVisible(const char * name) {
	return _lookupVisible(name) != NULL;
}

static bool _addAutomaton(const char * name, RuntimeAutomaton * automaton) {
	return runtimeSymbolTableAddAutomaton(_compilerState->symbolTable, name, automaton);
}

static bool _addString(const char * name, char * value) {
	return runtimeSymbolTableAddString(_compilerState->symbolTable, name, value);
}

static void _pushScope() {
	runtimeSymbolTablePushScope(_compilerState->symbolTable);
	_compilerState->scopeStack = _compilerState->symbolTable->currentScope;
}

static void _popScope() {
	runtimeSymbolTablePopScope(_compilerState->symbolTable);
	_compilerState->scopeStack = _compilerState->symbolTable->currentScope;
}

/* SYMBOL REQUIREMENTS */

static RuntimeAutomaton * _requireAutomaton(const char * name, const char * usage) {
	RuntimeSymbol * symbol = _lookupVisible(name);
	if (symbol == NULL) {
		_reportSemanticError("Cannot %s undeclared automaton '%s'.", usage, name);
		return NULL;
	}
	if (symbol->type != RUNTIME_SYMBOL_AUTOMATON) {
		_reportSemanticError("Symbol '%s' is not an automaton for %s.", name, usage);
		return NULL;
	}
	return symbol->automaton;
}

static char * _requireString(const char * name, const char * usage) {
	RuntimeSymbol * symbol = _lookupVisible(name);
	if (symbol == NULL) {
		_reportSemanticError("Cannot %s undeclared string '%s'.", usage, name);
		return NULL;
	}
	if (symbol->type != RUNTIME_SYMBOL_STRING) {
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

static bool _validateAutomaton(RuntimeAutomaton * automaton) {
	bool isValid = true;
	if (runtimeStringListHasDuplicates(automaton->states)) {
		_reportSemanticError("Automaton '%s' declares duplicated states.", automaton->name);
		isValid = false;
	}
	if (runtimeStringListHasDuplicates(automaton->alphabet)) {
		_reportSemanticError("Automaton '%s' declares duplicated symbols in its alphabet.", automaton->name);
		isValid = false;
	}
	if (runtimeStringListContains(automaton->alphabet, "lambda")) {
		_reportSemanticError("Automaton '%s' cannot declare lambda as a regular alphabet symbol.", automaton->name);
		isValid = false;
	}
	if (!runtimeStringListContains(automaton->states, automaton->startState)) {
		_reportSemanticError("Automaton '%s' start state '%s' is not declared in states.", automaton->name, automaton->startState);
		isValid = false;
	}
	for (RuntimeStringList * accept = automaton->acceptStates; accept != NULL; accept = accept->next) {
		if (!runtimeStringListContains(automaton->states, accept->value)) {
			_reportSemanticError("Automaton '%s' accept state '%s' is not declared in states.", automaton->name, accept->value);
			isValid = false;
		}
	}
	for (RuntimeTransition * transition = automaton->transitions; transition != NULL; transition = transition->next) {
		if (!_validateTransition(automaton, transition)) {
			isValid = false;
		}
		if (automaton->type == DFA && hasEarlierRuntimeTransitionWithSameKey(automaton->transitions, transition)) {
			_reportSemanticError("DFA '%s' declares more than one transition for state '%s' and symbol '%s'.",
				automaton->name,
				transition->source,
				transition->isLambda ? "lambda" : transition->symbol);
			isValid = false;
		}
	}
	return isValid;
}

static bool _validateTransition(RuntimeAutomaton * automaton, RuntimeTransition * transition) {
	bool isValid = true;
	if (!runtimeStringListContains(automaton->states, transition->source)) {
		_reportSemanticError("Automaton '%s' transition source '%s' is not declared in states.", automaton->name, transition->source);
		isValid = false;
	}
	if (transition->isLambda) {
		if (automaton->type != LNFA) {
			_reportSemanticError("%s '%s' cannot use lambda transitions.", _automatonTypeAsString(automaton->type), automaton->name);
			isValid = false;
		}
	}
	else if (!runtimeStringListContains(automaton->alphabet, transition->symbol)) {
		_reportSemanticError("Automaton '%s' transition symbol '%s' is not declared in alphabet.", automaton->name, transition->symbol);
		isValid = false;
	}
	if (automaton->type == DFA && (transition->hadMultipleDestinations || runtimeStringListLength(transition->destinations) != 1)) {
		_reportSemanticError("DFA '%s' transition from '%s' with symbol '%s' must use a single destination.",
			automaton->name,
			transition->source,
			transition->isLambda ? "lambda" : transition->symbol);
		isValid = false;
	}
	for (RuntimeStringList * destination = transition->destinations; destination != NULL; destination = destination->next) {
		if (!runtimeStringListContains(automaton->states, destination->value)) {
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
	RuntimeAutomaton * runtimeAutomaton = runtimeAutomatonFromAst(automaton);
	if (_validateAutomaton(runtimeAutomaton)) {
		_addAutomaton(runtimeAutomaton->name, runtimeAutomaton);
	}
	else {
		destroyRuntimeAutomaton(runtimeAutomaton);
	}
}

static void _validateStringDeclarationStatement(StringDeclaration * declaration) {
	if (_symbolExistsVisible(declaration->id)) {
		_reportSemanticError("Symbol '%s' is already declared.", declaration->id);
		return;
	}
	char * value = unquoteString(declaration->value);
	if (!_addString(declaration->id, value)) {
		free(value);
		_reportSemanticError("String '%s' is already declared in the current scope.", declaration->id);
	}
}

static void _validateConversionStatement(Conversion * conversion) {
	RuntimeAutomaton * source = _requireAutomaton(conversion->input, "convert");
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
	RuntimeAutomaton * derived = cloneRuntimeAutomatonShell(source, conversion->output, conversion->type);
	_addAutomaton(derived->name, derived);
}

static void _validateShowStatement(Show * show) {
	RuntimeAutomaton * automaton = _requireAutomaton(show->id, "show");
	if (automaton == NULL) {
		return;
	}
	if (show->type == SHOW_CLOSURE && !runtimeStringListContains(automaton->states, show->state)) {
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
		if (!isQuotedString(value->value)) {
			_requireString(value->value, "iterate");
		}
	}
	_pushScope();
	char * iterationValue = copyRuntimeString("");
	_addString(forLoop->index, iterationValue);
	_validateStatementList(forLoop->statements);
	_popScope();
}

static void _validateUpdateStatement(Update * update) {
	RuntimeAutomaton * automaton = _requireAutomaton(update->automatonName, "update");
	if (automaton == NULL) {
		return;
	}
	applyUpdateStates(automaton, update->states);
	if (update->acceptStates != NULL) {
		bool acceptIsValid = true;
		for (StringList * accept = update->acceptStates; accept != NULL; accept = accept->next) {
			if (!runtimeStringListContains(automaton->states, accept->value)) {
				_reportSemanticError("Automaton '%s' update uses undeclared accept state '%s'.", automaton->name, accept->value);
				acceptIsValid = false;
			}
		}
		if (acceptIsValid) {
			applyUpdateAccept(automaton, update->acceptStates);
		}
	}
	applyUpdateTransitions(automaton, update->transitions);
	_validateAutomaton(automaton);
}

/* PUBLIC FUNCTIONS */

CompilationStatus executeSemanticAnalysis(CompilerState * compilerState) {
	logDebugging(_logger, "Running semantic analysis...");
	_compilerState = compilerState;
	runtimeSymbolTableDestroy(_compilerState->symbolTable);
	_compilerState->symbolTable = runtimeSymbolTableCreate();
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
