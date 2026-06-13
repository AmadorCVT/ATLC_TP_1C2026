#ifndef COMPILER_STATE_HEADER
#define COMPILER_STATE_HEADER

#include <stdbool.h>

typedef struct RuntimeScope RuntimeScope;
typedef struct RuntimeSymbolTable RuntimeSymbolTable;

/**
 * The global state of the compiler. Should transport every data structure
 * needed across the different phases of a compilation.
 */
typedef struct {
	/**
	 * The root node of the AST.
	 */
	void * abstractSyntaxtTree;

	/**
	 * Symbol table built from the AST during semantic analysis and kept alive
	 * so later phases (e.g. code generation) can consume the validated
	 * automata. The concrete structures live in the domain-specific Automaton
	 * module.
	 */
	RuntimeSymbolTable * symbolTable;
	RuntimeScope * scopeStack;
	bool hasSemanticErrors;

	// TODO: Add more configuration.
	// TODO: Add whatever you need.
	// TODO: ...
} CompilerState;

#endif
