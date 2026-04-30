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

Automaton * AutomatonSemanticAction(char * id, AutomatonType type, Definition * definition) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Automaton * automaton = calloc(1, sizeof(Automaton));
	automaton->id = id;
	automaton->type = type;
	automaton->definition = definition;
	return automaton;
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

Statement * AutomatonStatementSemanticAction(Automaton * automaton) {
	_logSyntacticAnalyzerAction(__FUNCTION__);
	Statement * statement = calloc(1, sizeof(Statement));
	statement->automaton = automaton;
	statement->type = AUTOMATON_STATEMENT;
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
