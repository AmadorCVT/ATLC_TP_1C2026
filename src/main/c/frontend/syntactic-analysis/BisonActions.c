#include "BisonActions.h"

/* MODULE INTERNAL STATE */

static CompilerState * _compilerState = NULL;
static Logger * _logger = NULL;

/** Shutdown module's internal state. */
void _shutdownBisonActionsModule() {
	if (_logger != NULL) {
		logDebugging(_logger, "Destroying module: BisonActions...");
		destroyLogger(_logger);
		_logger = NULL;
	}
	_compilerState = NULL;
}

ModuleDestructor initializeBisonActionsModule(CompilerState * compilerState) {
	_compilerState = compilerState;
	_logger = createLogger("BisonActions");
	return _shutdownBisonActionsModule;
}

/* PRIVATE FUNCTIONS */

static void _logSyntacticAnalyzerAction(const char * functionName);

/**
 * Logs a syntactic-analyzer action in DEBUGGING level.
 */
static void _logSyntacticAnalyzerAction(const char * functionName) {
	logDebugging(_logger, "%s", functionName);
}

/* PUBLIC FUNCTIONS */

For * ForSemanticAction(char * index, StringList * values, Statement * statements) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	For * for_loop = calloc(1, sizeof(For));
	for_loop->index = index;
	for_loop->values = values;
	for_loop->statements= statements;
	return for_loop;
}

Automaton * AutomatonSemanticAction(char * id, AutomatonType type, Definition * definition) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Automaton * automaton = calloc(1, sizeof(Automaton));
	automaton->id = id;
	automaton->type = type;
	automaton->definition = definition;
	return automaton;
}

Test * TestSemanticAction(char * id, char * input) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Test * test = calloc(1, sizeof(Test));
	test->id = id;
	test->input = input;
	test->inputType = TEST_INPUT_LITERAL;
	return test;
}

Test * TestVariableSemanticAction(char * id, char * input) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Test * test = calloc(1, sizeof(Test));
	test->id = id;
	test->input = input;
	test->inputType = TEST_INPUT_VARIABLE;
	return test;
}

StringDeclaration * StringDeclarationSemanticAction(char * id, char * value) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	StringDeclaration * declaration = calloc(1, sizeof(StringDeclaration));
	declaration->id = id;
	declaration->value = value;
	return declaration;
}

Conversion * ConversionSemanticAction(char * input, AutomatonType type, char * output) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Conversion * conversion = calloc(1, sizeof(Conversion));
	conversion->input = input;
	conversion->type = type;
	conversion->output = output;
	return conversion;
}

AutomatonType AutomatonTypeSemanticAction(AutomatonType type) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	return type;
}

Definition * DefinitionSemanticAction(
	StringList * alphabet,
	StringList * states,
	char * startState,
	StringList * acceptStates,
	Transition * transitions) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Definition * definition = calloc(1, sizeof(Definition));
	definition->alphabet = alphabet;
	definition->states = states;
	definition->startState = startState;
	definition->acceptStates = acceptStates;
	definition->transitions = transitions;
	return definition;
}

Program * StatementListProgramSemanticAction(Statement * statements) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Program * program = calloc(1, sizeof(Program));
	program->statements = statements;
	_compilerState->abstractSyntaxtTree = program;
	return program;
}

Statement * AppendStatementListSemanticAction(Statement * list, Statement * statement) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	if (list == NULL) {
		return statement;
	}
	Statement * last = list;
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = statement;
	return list;
}

Statement * ForStatementSemanticAction(For * for_loop) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Statement * statement = calloc(1, sizeof(Statement));
	statement->for_loop = for_loop;
	statement->type = FOR_STATEMENT;
	return statement;
}

Statement * AutomatonStatementSemanticAction(Automaton * automaton) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Statement * statement = calloc(1, sizeof(Statement));
	statement->automaton = automaton;
	statement->type = AUTOMATON_STATEMENT;
	return statement;
}

Statement * TestStatementSemanticAction(Test * test) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Statement * statement = calloc(1, sizeof(Statement));
	statement->test = test;
	statement->type = TEST_STATEMENT;
	return statement;
}

Statement * StringDeclarationStatementSemanticAction(StringDeclaration * declaration) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Statement * statement = calloc(1, sizeof(Statement));
	statement->stringDeclaration = declaration;
	statement->type = STRING_DECLARATION_STATEMENT;
	return statement;
}

Statement * ConversionStatementSemanticAction(Conversion * conversion) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Statement * statement = calloc(1, sizeof(Statement));
	statement->conversion = conversion;
	statement->type = CONVERSION_STATEMENT;
	return statement;
}

Statement * ShowStatementSemanticAction(Show * show) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Statement * statement = calloc(1, sizeof(Statement));
	statement->show = show;
	statement->type = SHOW_STATEMENT;
	return statement;
}

Statement * PrintStatementSemanticAction(Print * print) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Statement * statement = calloc(1, sizeof(Statement));
	statement->print = print;
	statement->type = PRINT_STATEMENT;
	return statement;
}

StringList * AppendStringListSemanticAction(StringList * list, char * value) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	StringList * next = SingleStringListSemanticAction(value);
	if (list == NULL) {
		return next;
	}
	StringList * last = list;
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = next;
	return list;
}

StringList * SingleStringListSemanticAction(char * value) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	StringList * stringList = calloc(1, sizeof(StringList));
	stringList->value = value;
	return stringList;
}

Transition * AppendTransitionListSemanticAction(Transition * list, Transition * transition) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	if (list == NULL) {
		return transition;
	}
	Transition * last = list;
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = transition;
	return list;
}

Transition * TransitionSemanticAction(char * source, TransitionSymbol * symbol, TransitionDestination * destination) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Transition * transition = calloc(1, sizeof(Transition));
	transition->source = source;
	transition->symbol = symbol;
	transition->destination = destination;
	return transition;
}

TransitionDestination * MultipleTransitionDestinationSemanticAction(StringList * states) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	TransitionDestination * destination = calloc(1, sizeof(TransitionDestination));
	destination->states = states;
	destination->type = MULTIPLE_TRANSITION_DESTINATIONS;
	return destination;
}

TransitionDestination * SingleTransitionDestinationSemanticAction(char * state) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	TransitionDestination * destination = calloc(1, sizeof(TransitionDestination));
	destination->state = state;
	destination->type = SINGLE_TRANSITION_DESTINATION;
	return destination;
}

TransitionSymbol * LambdaTransitionSymbolSemanticAction() {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	TransitionSymbol * symbol = calloc(1, sizeof(TransitionSymbol));
	symbol->isLambda = true;
	return symbol;
}

TransitionSymbol * SymbolTransitionSymbolSemanticAction(char * value) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	TransitionSymbol * symbol = calloc(1, sizeof(TransitionSymbol));
	symbol->value = value;
	symbol->isLambda = false;
	return symbol;
}

Show * ShowTransitionsSemanticAction(char * id) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Show * show = calloc(1, sizeof(Show));
	show->id = id;
	show->type = SHOW_TRANSITIONS;
	show->state = NULL;
	return show;
}

Show * ShowTableSemanticAction(char * id) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Show * show = calloc(1, sizeof(Show));
	show->id = id;
	show->type = SHOW_TABLE;
	show->state = NULL;
	return show;
}

Show * ShowClosureSemanticAction(char * state, char * id) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Show * show = calloc(1, sizeof(Show));
	show->id = id;
	show->type = SHOW_CLOSURE;
	show->state = state;
	return show;
}

Print * PrintSemanticAction(char * id) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Print * print = calloc(1, sizeof(Print));
	print->id = id;
	return print;
}

Equivalent * EquivalentSemanticAction(char * name1, char * name2) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Equivalent * node = calloc(1, sizeof(Equivalent));
	node->name1 = name1;
	node->name2 = name2;
	return node;
}

Statement * EquivalentStatementSemanticAction(Equivalent * equivalent) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Statement * statement = calloc(1, sizeof(Statement));
	statement->equivalent = equivalent;
	statement->type = EQUIVALENT_STATEMENT;
	return statement;
}

Update * EmptyUpdateBodySemanticAction() {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	return calloc(1, sizeof(Update));
}

Update * StatesUpdateBodySemanticAction(Update * body, StringList * states) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	body->states = states;
	return body;
}

Update * AcceptUpdateBodySemanticAction(Update * body, StringList * acceptStates) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	body->acceptStates = acceptStates;
	return body;
}

Update * TransitionsUpdateBodySemanticAction(Update * body, Transition * transitions) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	body->transitions = transitions;
	return body;
}

Update * UpdateSemanticAction(char * name, Update * body) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	body->automatonName = name;
	return body;
}

Statement * UpdateStatementSemanticAction(Update * update) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Statement * statement = calloc(1, sizeof(Statement));
	statement->update = update;
	statement->type = UPDATE_STATEMENT;
	return statement;
}
