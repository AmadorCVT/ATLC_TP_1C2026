#ifndef ABSTRACT_SYNTAX_TREE_HEADER
#define ABSTRACT_SYNTAX_TREE_HEADER

#include "../../support/logging/Logger.h"
#include "../../support/type/ModuleDestructor.h"
#include <stdbool.h>
#include <stdlib.h>

ModuleDestructor initializeAbstractSyntaxTreeModule();

typedef enum AutomatonType AutomatonType;
typedef enum ShowType ShowType;
typedef enum StatementType StatementType;
typedef enum TestInputType TestInputType;
typedef enum TransitionDestinationType TransitionDestinationType;

typedef struct Automaton Automaton;
typedef struct Test Test;
typedef struct StringDeclaration StringDeclaration;
typedef struct For For;
typedef struct Array Array;
typedef struct Conversion Conversion;
typedef struct Show Show;
typedef struct Print Print;
typedef struct Definition Definition;
typedef struct Program Program;
typedef struct Statement Statement;
typedef struct StringList StringList;
typedef struct Transition Transition;
typedef struct TransitionDestination TransitionDestination;
typedef struct TransitionSymbol TransitionSymbol;
typedef struct Equivalent Equivalent;
typedef struct Update     Update;

enum AutomatonType {
	DFA,
	NFA,
	LNFA
};

enum StatementType {
	AUTOMATON_STATEMENT,
	TEST_STATEMENT,
	CONVERSION_STATEMENT,
	SHOW_STATEMENT,
	PRINT_STATEMENT,
	EQUIVALENT_STATEMENT,
	UPDATE_STATEMENT,
	STRING_DECLARATION_STATEMENT
};

enum TestInputType {
	TEST_INPUT_LITERAL,
	TEST_INPUT_VARIABLE,
	FOR_STATEMENT
};

enum TransitionDestinationType {
	SINGLE_TRANSITION_DESTINATION,
	MULTIPLE_TRANSITION_DESTINATIONS
};

enum ShowType {
	SHOW_TRANSITIONS,
	SHOW_TABLE,
	SHOW_CLOSURE
};

struct For {
	char * index;
	StringList * values;
	Statement * statements;
};

struct StringList {
	char * value;
	StringList * next;
};

struct TransitionSymbol {
	char * value;
	bool isLambda;
};

struct TransitionDestination {
	union {
		char * state;
		StringList * states;
	};
	TransitionDestinationType type;
};

struct Transition {
	char * source;
	TransitionSymbol * symbol;
	TransitionDestination * destination;
	Transition * next;
};

struct Definition {
	StringList * alphabet;
	StringList * states;
	char * startState;
	StringList * acceptStates;
	Transition * transitions;
};

struct Automaton {
	char * id;
	AutomatonType type;
	Definition * definition;
};

struct Test{
	char * id;
	char * input;
	TestInputType inputType;
};

struct StringDeclaration {
	char * id;
	char * value;
};

struct Conversion {
	char * input;
	AutomatonType type;
	char * output;
};

struct Show {
	char * id;
	ShowType type;
	char * state;	/* only used for SHOW_CLOSURE */
};

struct Print {
	char * id;
};

struct Equivalent {
	char * name1;
	char * name2;
};

struct Update {
	char *       automatonName;
	StringList * states;       /* NULL if not specified */
	StringList * acceptStates; /* NULL if not specified */
	Transition * transitions;  /* NULL if not specified */
};

struct Statement {
	union {
		Automaton *  automaton;
		Test *       test;
		Conversion * conversion;
		Show *       show;
		Print *      print;
		Equivalent * equivalent;
		Update *     update;
		StringDeclaration * stringDeclaration;
		For *     	 for_loop;
	};
	StatementType type;
	Statement *   next;
};

struct Program {
	Statement * statements;
};

void destroyAutomaton(Automaton * automaton);
void destroyTest(Test * test);
void destroyStringDeclaration(StringDeclaration * declaration);
void destroyFor(For * for_loop);
void destroyConversion(Conversion * conversion);
void destroyShow(Show * show);
void destroyPrint(Print * print);
void destroyEquivalent(Equivalent * node);
void destroyUpdate(Update * node);
void destroyDefinition(Definition * definition);
void destroyProgram(Program * program);
void destroyStatement(Statement * statement);
void destroyStringList(StringList * stringList);
void destroyTransition(Transition * transition);
void destroyTransitionDestination(TransitionDestination * destination);
void destroyTransitionSymbol(TransitionSymbol * symbol);

#endif
