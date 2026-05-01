#ifndef BISON_ACTIONS_HEADER
#define BISON_ACTIONS_HEADER

#include "../../support/logging/Logger.h"
#include "../../support/type/CompilerState.h"
#include "../../support/type/ModuleDestructor.h"
#include "../../support/type/TokenLabel.h"
#include "AbstractSyntaxTree.h"
#include "BisonParser.h"
#include <stdlib.h>

ModuleDestructor initializeBisonActionsModule(CompilerState * compilerState);

Automaton * AutomatonSemanticAction(char * id, AutomatonType type, Definition * definition);
Test * TestSemanticAction(char * id, char * string);
Conversion * ConversionSemanticAction(char * input, AutomatonType type, char * output);
AutomatonType AutomatonTypeSemanticAction(AutomatonType type);
Definition * DefinitionSemanticAction(
	StringList * alphabet,
	StringList * states,
	char * startState,
	StringList * acceptStates,
	Transition * transitions);
Program * StatementListProgramSemanticAction(Statement * statements);
Statement * AppendStatementListSemanticAction(Statement * list, Statement * statement);
Statement * AutomatonStatementSemanticAction(Automaton * automaton);
Statement * TestStatementSemanticAction(Test * test);
Statement * ConversionStatementSemanticAction(Conversion * conversion);
StringList * AppendStringListSemanticAction(StringList * list, char * value);
StringList * SingleStringListSemanticAction(char * value);
Transition * AppendTransitionListSemanticAction(Transition * list, Transition * transition);
Transition * TransitionSemanticAction(char * source, TransitionSymbol * symbol, TransitionDestination * destination);
TransitionDestination * MultipleTransitionDestinationSemanticAction(StringList * states);
TransitionDestination * SingleTransitionDestinationSemanticAction(char * state);
TransitionSymbol * LambdaTransitionSymbolSemanticAction();
TransitionSymbol * SymbolTransitionSymbolSemanticAction(char * value);

#endif
