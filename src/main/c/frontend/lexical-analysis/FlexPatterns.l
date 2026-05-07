%top{

#include "../../support/type/CompilationStatus.h"
#include "../../support/type/FlexContext.h"
#include "../../support/type/TokenLabel.h"
#include "../syntactic-analysis/AbstractSyntaxTree.h"
#include "../syntactic-analysis/BisonParser.h"

}

%{
extern CompilationStatus EOFLexemeAction();
extern CompilationStatus EnterMultilineCommentLexemeAction(FlexContext context);
extern CompilationStatus IgnoredLexemeAction();
extern CompilationStatus LeaveMultilineCommentLexemeAction();
extern CompilationStatus TokenLexemeAction(TokenLabel label);
extern CompilationStatus TokenWithStringLexemeAction(TokenLabel label);
extern CompilationStatus UnknownLexemeAction();

%}

%x MULTILINE_COMMENT

identifier			[[:alpha:]_][[:alnum:]_]*
numeric_symbol		[[:digit:]]+
whitespace			[[:space:]]+
line_comment		"//"[^\r\n]*

%%

"/*"								{ return EnterMultilineCommentLexemeAction(MULTILINE_COMMENT); }
<MULTILINE_COMMENT>"*/"				{ return LeaveMultilineCommentLexemeAction(); }
<MULTILINE_COMMENT>[^*]+			{ return IgnoredLexemeAction(); }
<MULTILINE_COMMENT>.				{ return IgnoredLexemeAction(); }

"automaton"							{ return TokenLexemeAction(AUTOMATON); }
"alphabet"							{ return TokenLexemeAction(ALPHABET); }
"states"							{ return TokenLexemeAction(STATES); }
"start"								{ return TokenLexemeAction(START); }
"accept"							{ return TokenLexemeAction(ACCEPT); }
"transitions"						{ return TokenLexemeAction(TRANSITIONS); }
"lambda"							{ return TokenLexemeAction(LAMBDA); }
"convert"							{ return TokenLexemeAction(CONVERT); }
"print"								{ return TokenLexemeAction(PRINT); }
"show"								{ return TokenLexemeAction(SHOW); }
"test"								{ return TokenLexemeAction(TEST); }
"with"								{ return TokenLexemeAction(WITH); }
"to"								{ return TokenLexemeAction(TO); }
"as"								{ return TokenLexemeAction(AS); }
"table"								{ return TokenLexemeAction(TABLE); }
"of"								{ return TokenLexemeAction(OF); }
"closure"							{ return TokenLexemeAction(CLOSURE); }
"in"								{ return TokenLexemeAction(IN); }
"equivalent"						{ return TokenLexemeAction(EQUIVALENT); }
"for"						        { return TokenLexemeAction(FOR); }
"IN"						        { return TokenLexemeAction(IN); }

"DFA"								{ return TokenLexemeAction(TYPE_DFA); }
"NFA"								{ return TokenLexemeAction(TYPE_NFA); }
"LNFA"								{ return TokenLexemeAction(TYPE_LNFA); }

"->"								{ return TokenLexemeAction(ARROW); }
"<="								{ return TokenLexemeAction(OP_LEQ); }
">="								{ return TokenLexemeAction(OP_GEQ); }
"!="								{ return TokenLexemeAction(OP_NEQ); }
":"									{ return TokenLexemeAction(COLON); }
";"									{ return TokenLexemeAction(SEMICOLON); }
","									{ return TokenLexemeAction(COMMA); }
"="									{ return TokenLexemeAction(ASSIGN); }
"<"									{ return TokenLexemeAction(OP_LT); }
">"									{ return TokenLexemeAction(OP_GT); }
"{"									{ return TokenLexemeAction(OPEN_CURLY_BRACKET); }
"}"									{ return TokenLexemeAction(CLOSE_CURLY_BRACKET); }
"("									{ return TokenLexemeAction(OPEN_PARENTHESIS); }
")"									{ return TokenLexemeAction(CLOSE_PARENTHESIS); }

\"[^\"]*\"							{ return TokenWithStringLexemeAction(STRING); }
{identifier}						{ return TokenWithStringLexemeAction(ID); }
{numeric_symbol}					{ return TokenWithStringLexemeAction(NUMERIC_SYMBOL); }

{line_comment}						{ return IgnoredLexemeAction(); }
{whitespace}						{ return IgnoredLexemeAction(); }
.									{ return UnknownLexemeAction(); }

<<EOF>>								{ return EOFLexemeAction(); }

%%

#include "FlexActions.h"
#include "FlexExport.h"
