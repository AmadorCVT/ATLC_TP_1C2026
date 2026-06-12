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
/* Runtime data structures                                             */
/* ------------------------------------------------------------------ */

typedef struct RuntimeStringList {
	char *                   value;
	struct RuntimeStringList * next;
} RuntimeStringList;

typedef struct RuntimeTransition {
	char *               source;
	char *               symbol;        /* NULL when isLambda */
	bool                 isLambda;
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

typedef struct RuntimeEntry {
	char *              name;
	RuntimeAutomaton *  automaton;
	struct RuntimeEntry * next;
} RuntimeEntry;

typedef struct RuntimeTable {
	RuntimeEntry * head;
} RuntimeTable;

typedef struct RuntimeStringEntry {
	char *                    name;
	char *                    value;
	struct RuntimeStringEntry * next;
} RuntimeStringEntry;

typedef struct RuntimeStringTable {
	RuntimeStringEntry * head;
} RuntimeStringTable;

/* ------------------------------------------------------------------ */
/* Table lifecycle                                                     */
/* ------------------------------------------------------------------ */

RuntimeTable *       runtimeTableCreate();
void                 runtimeTableDestroy(RuntimeTable * table);
void                 runtimeTableInsert(RuntimeTable * table, RuntimeAutomaton * automaton);
RuntimeAutomaton *   runtimeTableLookup(RuntimeTable * table, const char * name);

RuntimeStringTable * runtimeStringTableCreate();
void                 runtimeStringTableDestroy(RuntimeStringTable * table);
void                 runtimeStringTableSet(RuntimeStringTable * table, const char * name, const char * value);
const char *         runtimeStringTableLookup(RuntimeStringTable * table, const char * name);
void                 runtimeStringTableRemove(RuntimeStringTable * table, const char * name);

/* ------------------------------------------------------------------ */
/* Automaton lifecycle                                                 */
/* ------------------------------------------------------------------ */

RuntimeAutomaton * runtimeAutomatonFromAst(Automaton * ast);
RuntimeAutomaton * cloneRuntimeAutomaton(RuntimeAutomaton * src, const char * newName, AutomatonType newType);
void               destroyRuntimeAutomaton(RuntimeAutomaton * automaton);
void               destroyRuntimeStringList(RuntimeStringList * list);
void               destroyRuntimeTransition(RuntimeTransition * transition);

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
/* String utility                                                      */
/* ------------------------------------------------------------------ */

char * unquoteString(const char * value);

#endif
