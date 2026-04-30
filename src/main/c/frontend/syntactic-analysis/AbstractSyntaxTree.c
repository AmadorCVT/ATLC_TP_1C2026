#include "AbstractSyntaxTree.h"

/* MODULE INTERNAL STATE */

static Logger * _logger = NULL;

/** Shutdown module's internal state. */
void _shutdownAbstractSyntaxTreeModule() {
	if (_logger != NULL) {
		logDebugging(_logger, "Destroying module: AbstractSyntaxTree...");
		destroyLogger(_logger);
		_logger = NULL;
	}
}

ModuleDestructor initializeAbstractSyntaxTreeModule() {
	_logger = createLogger("AbstractSyntaxTree");
	return _shutdownAbstractSyntaxTreeModule;
}

/* PUBLIC FUNCTIONS */

void destroyAutomaton(Automaton * automaton) {
	logDebugging(_logger, "Executing destructor: %s", __FUNCTION__);
	if (automaton != NULL) {
		free(automaton->id);
		destroyDefinition(automaton->definition);
		free(automaton);
	}
}

void destroyDefinition(Definition * definition) {
	logDebugging(_logger, "Executing destructor: %s", __FUNCTION__);
	if (definition != NULL) {
		destroyStringList(definition->alphabet);
		destroyStringList(definition->states);
		free(definition->startState);
		destroyStringList(definition->acceptStates);
		destroyTransition(definition->transitions);
		free(definition);
	}
}

void destroyProgram(Program * program) {
	logDebugging(_logger, "Executing destructor: %s", __FUNCTION__);
	if (program != NULL) {
		destroyStatement(program->statements);
		free(program);
	}
}

void destroyStatement(Statement * statement) {
	logDebugging(_logger, "Executing destructor: %s", __FUNCTION__);
	while (statement != NULL) {
		Statement * next = statement->next;
		switch (statement->type) {
			case AUTOMATON_STATEMENT:
				destroyAutomaton(statement->automaton);
				break;
		}
		free(statement);
		statement = next;
	}
}

void destroyStringList(StringList * stringList) {
	logDebugging(_logger, "Executing destructor: %s", __FUNCTION__);
	while (stringList != NULL) {
		StringList * next = stringList->next;
		free(stringList->value);
		free(stringList);
		stringList = next;
	}
}

void destroyTransition(Transition * transition) {
	logDebugging(_logger, "Executing destructor: %s", __FUNCTION__);
	while (transition != NULL) {
		Transition * next = transition->next;
		free(transition->source);
		destroyTransitionSymbol(transition->symbol);
		destroyTransitionDestination(transition->destination);
		free(transition);
		transition = next;
	}
}

void destroyTransitionDestination(TransitionDestination * destination) {
	logDebugging(_logger, "Executing destructor: %s", __FUNCTION__);
	if (destination != NULL) {
		switch (destination->type) {
			case SINGLE_TRANSITION_DESTINATION:
				free(destination->state);
				break;
			case MULTIPLE_TRANSITION_DESTINATIONS:
				destroyStringList(destination->states);
				break;
		}
		free(destination);
	}
}

void destroyTransitionSymbol(TransitionSymbol * symbol) {
	logDebugging(_logger, "Executing destructor: %s", __FUNCTION__);
	if (symbol != NULL) {
		free(symbol->value);
		free(symbol);
	}
}
