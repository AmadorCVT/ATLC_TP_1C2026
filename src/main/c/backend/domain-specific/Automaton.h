#ifndef AUTOMATON_HEADER
#define AUTOMATON_HEADER

#include "../../frontend/syntactic-analysis/AbstractSyntaxTree.h"
#include "../../support/logging/Logger.h"
#include "../../support/type/CompilerState.h"
#include "../../support/type/ModuleDestructor.h"
#include <stdbool.h>
#include <stdlib.h>

ModuleDestructor initializeAutomatonModule();

/* ------------------------------------------------------------------ */
/* Automaton data structures                                           */
/* ------------------------------------------------------------------ */

typedef struct RuntimeStringList {
	char *                   value;
	struct RuntimeStringList * next;
} RuntimeStringList;

typedef struct RuntimeTransition {
	char *               source;
	char *               symbol;        /* NULL when isLambda */
	bool                 isLambda;
	bool                 hadMultipleDestinations; /* set when the source syntax used {.,.} */
	RuntimeStringList *  destinations;
	struct RuntimeTransition * next;
} RuntimeTransition;

typedef struct RuntimeAutomaton {
	char *              name;
	AutomatonType       type;
	RuntimeStringList * alphabet;
	RuntimeStringList * states;
	char *              startState;
	RuntimeStringList * acceptStates;
	RuntimeTransition * transitions;
} RuntimeAutomaton;

/* ------------------------------------------------------------------ */
/* Symbol table (scoped) — shared by semantic analysis and generation  */
/* ------------------------------------------------------------------ */

typedef enum RuntimeSymbolType {
	RUNTIME_SYMBOL_AUTOMATON,
	RUNTIME_SYMBOL_STRING
} RuntimeSymbolType;

typedef struct RuntimeSymbol {
	char *               name;
	RuntimeSymbolType    type;
	union {
		RuntimeAutomaton * automaton;
		char *             string;
	};
	struct RuntimeSymbol * next;
} RuntimeSymbol;

/* RuntimeScope and RuntimeSymbolTable are forward-declared in CompilerState.h
 * (which this header includes) so that CompilerState can hold pointers to them
 * without a circular include. Here we provide the full definitions. */

struct RuntimeScope {
	RuntimeSymbol * symbols;
	RuntimeScope *  parent;
};

struct RuntimeSymbolTable {
	RuntimeScope * globalScope;
	RuntimeScope * currentScope;
};

/* ------------------------------------------------------------------ */
/* Symbol table lifecycle                                              */
/* ------------------------------------------------------------------ */

RuntimeSymbolTable * runtimeSymbolTableCreate();
void                 runtimeSymbolTableDestroy(RuntimeSymbolTable * table);
void                 runtimeSymbolTablePushScope(RuntimeSymbolTable * table);
void                 runtimeSymbolTablePopScope(RuntimeSymbolTable * table);
RuntimeSymbol *      runtimeSymbolTableLookupVisible(RuntimeSymbolTable * table, const char * name);
RuntimeSymbol *      runtimeSymbolTableLookupCurrent(RuntimeSymbolTable * table, const char * name);
bool                 runtimeSymbolTableAddAutomaton(RuntimeSymbolTable * table, const char * name, RuntimeAutomaton * automaton);
bool                 runtimeSymbolTableAddString(RuntimeSymbolTable * table, const char * name, char * value);

/* ------------------------------------------------------------------ */
/* Automaton lifecycle                                                 */
/* ------------------------------------------------------------------ */

RuntimeAutomaton * runtimeAutomatonFromAst(Automaton * ast);
RuntimeAutomaton * cloneRuntimeAutomaton(RuntimeAutomaton * src, const char * newName, AutomatonType newType);
RuntimeAutomaton * cloneRuntimeAutomatonShell(RuntimeAutomaton * src, const char * newName, AutomatonType newType);
void               destroyRuntimeAutomaton(RuntimeAutomaton * automaton);
void               destroyRuntimeStringList(RuntimeStringList * list);
void               destroyRuntimeTransition(RuntimeTransition * transition);

/* ------------------------------------------------------------------ */
/* String-list helpers                                                 */
/* ------------------------------------------------------------------ */

bool         runtimeStringListContains(RuntimeStringList * list, const char * value);
bool         runtimeStringListHasDuplicates(RuntimeStringList * list);
unsigned int runtimeStringListLength(RuntimeStringList * list);
void         appendRuntimeString(RuntimeStringList ** list, const char * value);
void         appendUniqueRuntimeString(RuntimeStringList ** list, const char * value);

/* ------------------------------------------------------------------ */
/* Transition helpers                                                  */
/* ------------------------------------------------------------------ */

bool sameRuntimeTransitionKey(RuntimeTransition * left, RuntimeTransition * right);
bool hasEarlierRuntimeTransitionWithSameKey(RuntimeTransition * first, RuntimeTransition * current);

/* ------------------------------------------------------------------ */
/* Simulation                                                          */
/* ------------------------------------------------------------------ */

bool simulateAutomaton(RuntimeAutomaton * automaton, const char * input);

/* ------------------------------------------------------------------ */
/* Lambda-closure                                                      */
/* ------------------------------------------------------------------ */

RuntimeStringList * lambdaClosure(RuntimeAutomaton * automaton, RuntimeStringList * states);

/* ------------------------------------------------------------------ */
/* Conversions                                                         */
/* ------------------------------------------------------------------ */

RuntimeAutomaton * convertDFAtoNFA(RuntimeAutomaton * dfa, const char * newName);
RuntimeAutomaton * convertNFAtoDFA(RuntimeAutomaton * nfa, const char * newName);
RuntimeAutomaton * convertLNFAtoNFA(RuntimeAutomaton * lnfa, const char * newName);
RuntimeAutomaton * convertLNFAtoDFA(RuntimeAutomaton * lnfa, const char * newName);

/* ------------------------------------------------------------------ */
/* Output                                                              */
/* ------------------------------------------------------------------ */

void printAutomaton(RuntimeAutomaton * automaton);
void showTransitions(RuntimeAutomaton * automaton);
void showTable(RuntimeAutomaton * automaton);
void showClosure(RuntimeAutomaton * automaton, const char * stateName);

/* ------------------------------------------------------------------ */
/* Update                                                              */
/* ------------------------------------------------------------------ */

void applyUpdateStates(RuntimeAutomaton * automaton, StringList * newStates);
void applyUpdateAccept(RuntimeAutomaton * automaton, StringList * newAccept);
void applyUpdateTransitions(RuntimeAutomaton * automaton, Transition * newTransitions);

/* ------------------------------------------------------------------ */
/* String utilities                                                    */
/* ------------------------------------------------------------------ */

char * copyRuntimeString(const char * value);
bool   isQuotedString(const char * value);
char * unquoteString(const char * value);

#endif
