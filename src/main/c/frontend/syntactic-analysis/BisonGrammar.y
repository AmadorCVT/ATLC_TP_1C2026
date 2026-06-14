%{

#include "../../support/type/TokenLabel.h"
#include "AbstractSyntaxTree.h"
#include "BisonActions.h"

void yyerror(const YYLTYPE * location, const char * message) {}

%}

%define api.pure full
%define api.push-pull push
%define api.value.union.name SemanticValue
%define parse.error detailed
%locations

%union {
	char * string;
	AutomatonType type;
	TokenLabel token;

	Automaton * automaton;
	For * for_loop;
	Test * test;
	StringDeclaration * stringDeclaration;
	Conversion * conversion;
	Show * show;
	Print * print;
	Definition * definition;
	Program * program;
	Statement * statement;
	StringList * stringList;
	Transition * transition;
	TransitionDestination * transitionDestination;
	TransitionSymbol * transitionSymbol;
	Equivalent * equivalent;
	Update *     update;
}

%left TEST

%destructor { free($$); } <string>
%destructor { destroyAutomaton($$); } <automaton>
%destructor { destroyFor($$); } <for_loop>
%destructor { destroyTest($$); } <test>
%destructor { destroyStringDeclaration($$); } <stringDeclaration>
%destructor { destroyConversion($$); } <conversion>
%destructor { destroyShow($$); } <show>
%destructor { destroyPrint($$); } <print>
%destructor { destroyDefinition($$); } <definition>
%destructor { destroyStatement($$); } <statement>
%destructor { destroyStringList($$); } <stringList>
%destructor { destroyTransition($$); } <transition>
%destructor { destroyTransitionDestination($$); } <transitionDestination>
%destructor { destroyTransitionSymbol($$); } <transitionSymbol>
%destructor { destroyEquivalent($$); } <equivalent>
%destructor { destroyUpdate($$); }     <update>

%token <token> ACCEPT
%token <token> ALPHABET
%token <token> ARROW
%token <token> ASSIGN
%token <token> AUTOMATON
%token <token> CLOSE_COMMENT
%token <token> CLOSE_CURLY_BRACKET
%token <token> COLON
%token <token> COMMA
%token <token> CONVERT
%token <string> ID
%token <token> IGNORED
%token <token> LAMBDA
%token <string> NUMERIC_SYMBOL
%token <token> OPEN_COMMENT
%token <token> OPEN_CURLY_BRACKET
%token <token> QUOTATION_MARK
%token <token> PRINT
%token <token> SEMICOLON
%token <token> SHOW
%token <token> START
%token <token> STATES
%token <token> TRANSITIONS
%token <token> TYPE_DFA
%token <token> TYPE_LNFA
%token <token> TYPE_NFA
%token <token> TYPE_STRING
%token <token> UNKNOWN
%token <token> TEST
%token <token> FOR
%token <token> TO
%token <token> AS
%token <token> TABLE
%token <token> OF
%token <token> CLOSURE
%token <token> IN
%token <token> WITH
%token <token> EQUIVALENT
%token <token> OP_LEQ
%token <token> OP_GEQ
%token <token> OP_NEQ
%token <token> OP_LT
%token <token> OP_GT
%token <token> OPEN_PARENTHESIS
%token <token> CLOSE_PARENTHESIS
%token <string> STRING

%type <automaton> automaton
%type <test> test
%type <stringDeclaration> string_declaration
%type <for_loop> for_loop
%type <conversion> conversion
%type <show> show
%type <print> print
%type <type> type
%type <definition> definition
%type <program> program
%type <statement> statement
%type <statement> statement_list
%type <string> alphabet_symbol
%type <string> state
%type <stringList> alphabet_set
%type <stringList> alphabet_symbol_list
%type <stringList> state_set
%type <stringList> state_list
%type <stringList> array_list
%type <transition> transition
%type <transition> transition_list
%type <transitionDestination> transition_destination
%type <transitionSymbol> transition_symbol
%type <equivalent> equivalent
%type <update>     update
%type <update>     update_body

%%

program: statement_list															{ $$ = StatementListProgramSemanticAction($1); }
	;

statement_list: statement														{ $$ = $1; }
	| statement_list statement													{ $$ = AppendStatementListSemanticAction($1, $2); }
	;

statement: automaton															{ $$ = AutomatonStatementSemanticAction($1); }
	| test																		{ $$ = TestStatementSemanticAction($1); }
	| string_declaration														{ $$ = StringDeclarationStatementSemanticAction($1); }
	| conversion																{ $$ = ConversionStatementSemanticAction($1); }
	| show																		{ $$ = ShowStatementSemanticAction($1); }
	| print																		{ $$ = PrintStatementSemanticAction($1); }
	| equivalent																{ $$ = EquivalentStatementSemanticAction($1); }
	| update																	{ $$ = UpdateStatementSemanticAction($1); }
	| for_loop																	{ $$ = ForStatementSemanticAction($1); }
	;

for_loop: FOR ID IN OPEN_CURLY_BRACKET array_list CLOSE_CURLY_BRACKET OPEN_CURLY_BRACKET statement_list CLOSE_CURLY_BRACKET      
																				{ $$ = ForSemanticAction($2, $5, $8); }
	;

automaton: AUTOMATON ID COLON type OPEN_CURLY_BRACKET definition CLOSE_CURLY_BRACKET SEMICOLON
																				{ $$ = AutomatonSemanticAction($2, $4, $6); }
	;

type: TYPE_DFA																	{ $$ = AutomatonTypeSemanticAction(DFA); }
	| TYPE_NFA																	{ $$ = AutomatonTypeSemanticAction(NFA); }
	| TYPE_LNFA																	{ $$ = AutomatonTypeSemanticAction(LNFA); }
	;

definition: ALPHABET ASSIGN alphabet_set
		STATES ASSIGN state_set
		START ASSIGN state
		ACCEPT ASSIGN state_set
		TRANSITIONS OPEN_CURLY_BRACKET transition_list CLOSE_CURLY_BRACKET		{ $$ = DefinitionSemanticAction($3, $6, $9, $12, $15); }
	;

alphabet_set: OPEN_CURLY_BRACKET alphabet_symbol_list CLOSE_CURLY_BRACKET		{ $$ = $2; }
	;

alphabet_symbol_list: alphabet_symbol											{ $$ = SingleStringListSemanticAction($1); }
	| alphabet_symbol_list COMMA alphabet_symbol								{ $$ = AppendStringListSemanticAction($1, $3); }
	;

alphabet_symbol: ID																{ $$ = $1; }
	| NUMERIC_SYMBOL															{ $$ = $1; }
	;

state_set: OPEN_CURLY_BRACKET state_list CLOSE_CURLY_BRACKET					{ $$ = $2; }
	;

array_list: STRING																{ $$ = SingleStringListSemanticAction($1); }
	| ID																		{ $$ = SingleVariableListSemanticAction($1); }
	| array_list COMMA STRING													{ $$ = AppendStringListSemanticAction($1, $3); }
	| array_list COMMA ID														{ $$ = AppendVariableListSemanticAction($1, $3); }
	;

state_list: state																{ $$ = SingleStringListSemanticAction($1); }
	| state_list COMMA state													{ $$ = AppendStringListSemanticAction($1, $3); }
	;

state: ID																		{ $$ = $1; }
	;

transition_list: %empty															{ $$ = NULL; }
	| transition_list transition												{ $$ = AppendTransitionListSemanticAction($1, $2); }
	;

transition: state ARROW transition_symbol COLON transition_destination			{ $$ = TransitionSemanticAction($1, $3, $5); }
	;

transition_symbol: alphabet_symbol												{ $$ = SymbolTransitionSymbolSemanticAction($1); }
	| LAMBDA																	{ $$ = LambdaTransitionSymbolSemanticAction(); }
	;

transition_destination: state													{ $$ = SingleTransitionDestinationSemanticAction($1); }
	| state_set																	{ $$ = MultipleTransitionDestinationSemanticAction($1); }
	;

test: TEST ID WITH STRING SEMICOLON												{ $$ = TestSemanticAction($2, $4); }
	| TEST ID WITH ID SEMICOLON													{ $$ = TestVariableSemanticAction($2, $4); }
	;

string_declaration: TYPE_STRING ID ASSIGN STRING SEMICOLON						{ $$ = StringDeclarationSemanticAction($2, $4); }
	;

conversion: CONVERT ID TO type AS ID SEMICOLON										{ $$ = ConversionSemanticAction($2, $4, $6); }
	;

show: SHOW TRANSITIONS OF ID SEMICOLON												{ $$ = ShowTransitionsSemanticAction($4); }
	| SHOW TABLE OF ID SEMICOLON													{ $$ = ShowTableSemanticAction($4); }
	| SHOW CLOSURE OPEN_PARENTHESIS ID CLOSE_PARENTHESIS IN ID SEMICOLON			{ $$ = ShowClosureSemanticAction($4, $7); }
	;

print: PRINT ID SEMICOLON															{ $$ = PrintSemanticAction($2); }
	;

equivalent: EQUIVALENT ID ID SEMICOLON											{ $$ = EquivalentSemanticAction($2, $3); }
	;

update: ID OPEN_CURLY_BRACKET update_body CLOSE_CURLY_BRACKET SEMICOLON		{ $$ = UpdateSemanticAction($1, $3); }
	;

update_body: %empty																{ $$ = EmptyUpdateBodySemanticAction(); }
	| update_body STATES ASSIGN state_set										{ $$ = StatesUpdateBodySemanticAction($1, $4); }
	| update_body ACCEPT ASSIGN state_set										{ $$ = AcceptUpdateBodySemanticAction($1, $4); }
	| update_body TRANSITIONS OPEN_CURLY_BRACKET transition_list CLOSE_CURLY_BRACKET
																				{ $$ = TransitionsUpdateBodySemanticAction($1, $4); }
	;
%%
