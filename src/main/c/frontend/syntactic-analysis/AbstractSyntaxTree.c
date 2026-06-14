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

void destroyTest(Test * test) {
	logDebugging(_logger, "Executing destructor: %s", __FUNCTION__);
	if (test != NULL) {
		free(test->id);
		free(test->input);
		free(test);
	}
}

void destroyStringDeclaration(StringDeclaration * declaration) {
	logDebugging(_logger, "Executing destructor: %s", __FUNCTION__);
	if (declaration != NULL) {
		free(declaration->id);
		free(declaration->value);
		free(declaration);
	}
}

void destroyConversion(Conversion * conversion) {
	logDebugging(_logger, "Executing destructor: %s", __FUNCTION__);
	if (conversion != NULL) {
		free(conversion->input);
		free(conversion->output);
		free(conversion);
	}
}

void destroyShow(Show * show) {
	logDebugging(_logger, "Executing destructor: %s", __FUNCTION__);
	if (show != NULL) {
		free(show->id);
		free(show->state);
		free(show);
	}
}

void destroyPrint(Print * print) {
	logDebugging(_logger, "Executing destructor: %s", __FUNCTION__);
	if (print != NULL) {
		free(print->id);
		free(print);
	}
}

void destroyEquivalent(Equivalent * node) {
	logDebugging(_logger, "Executing destructor: %s", __FUNCTION__);
	if (node != NULL) {
		free(node->name1);
		free(node->name2);
		free(node);
	}
}

void destroyUpdate(Update * node) {
	logDebugging(_logger, "Executing destructor: %s", __FUNCTION__);
	if (node != NULL) {
		free(node->automatonName);
		destroyStringList(node->states);
		destroyStringList(node->acceptStates);
		destroyTransition(node->transitions);
		free(node);
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

void destroyFor(For * for_loop) {
	logDebugging(_logger, "Executing destructor: %s", __FUNCTION__);
	if (for_loop != NULL) {
		free(for_loop->index);
		destroyStringList(for_loop->values);
		destroyStatement(for_loop->statements);
		free(for_loop);
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
			case TEST_STATEMENT:
				destroyTest(statement->test);
				break;
			case CONVERSION_STATEMENT:
				destroyConversion(statement->conversion);
				break;
			case SHOW_STATEMENT:
				destroyShow(statement->show);
				break;
			case PRINT_STATEMENT:
				destroyPrint(statement->print);
				break;
			case EQUIVALENT_STATEMENT:
				destroyEquivalent(statement->equivalent);
				break;
			case UPDATE_STATEMENT:
				destroyUpdate(statement->update);
				break;
			case FOR_STATEMENT:
				destroyFor(statement->for_loop);
				break;
			case STRING_DECLARATION_STATEMENT:
				destroyStringDeclaration(statement->stringDeclaration);
				break;
			default:
				logError(_logger, "Unknown statement type: %d", statement->type);
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
			default:
				logError(_logger, "Unknown transition destination type: %d", destination->type);
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
