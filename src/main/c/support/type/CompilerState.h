#ifndef COMPILER_STATE_HEADER
#define COMPILER_STATE_HEADER

#include <stdbool.h>

typedef struct SemanticScope SemanticScope;
typedef struct SemanticSymbolTable SemanticSymbolTable;

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
	 * Semantic-analysis state built from the AST. The concrete structures are
	 * owned by the semantic analyzer module.
	 */
	SemanticSymbolTable * symbolTable;
	SemanticScope * scopeStack;
	bool hasSemanticErrors;

	// TODO: Add more configuration.
	// TODO: Add whatever you need.
	// TODO: ...
} CompilerState;

#endif
