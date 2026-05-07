/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_MAIN_C_FRONTEND_SYNTACTIC_ANALYSIS_BISONPARSER_H_INCLUDED
# define YY_YY_SRC_MAIN_C_FRONTEND_SYNTACTIC_ANALYSIS_BISONPARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ACCEPT = 258,                  /* ACCEPT  */
    ALPHABET = 259,                /* ALPHABET  */
    ARROW = 260,                   /* ARROW  */
    ASSIGN = 261,                  /* ASSIGN  */
    AUTOMATON = 262,               /* AUTOMATON  */
    CLOSE_COMMENT = 263,           /* CLOSE_COMMENT  */
    CLOSE_CURLY_BRACKET = 264,     /* CLOSE_CURLY_BRACKET  */
    COLON = 265,                   /* COLON  */
    COMMA = 266,                   /* COMMA  */
    CONVERT = 267,                 /* CONVERT  */
    ID = 268,                      /* ID  */
    IGNORED = 269,                 /* IGNORED  */
    LAMBDA = 270,                  /* LAMBDA  */
    NUMERIC_SYMBOL = 271,          /* NUMERIC_SYMBOL  */
    OPEN_COMMENT = 272,            /* OPEN_COMMENT  */
    OPEN_CURLY_BRACKET = 273,      /* OPEN_CURLY_BRACKET  */
    QUOTATION_MARK = 274,          /* QUOTATION_MARK  */
    PRINT = 275,                   /* PRINT  */
    SEMICOLON = 276,               /* SEMICOLON  */
    SHOW = 277,                    /* SHOW  */
    START = 278,                   /* START  */
    STATES = 279,                  /* STATES  */
    TRANSITIONS = 280,             /* TRANSITIONS  */
    TYPE_DFA = 281,                /* TYPE_DFA  */
    TYPE_LNFA = 282,               /* TYPE_LNFA  */
    TYPE_NFA = 283,                /* TYPE_NFA  */
<<<<<<< HEAD
    UNKNOWN = 284,                 /* UNKNOWN  */
    TEST = 285,                    /* TEST  */
    FOR = 286,                     /* FOR  */
    TO = 287,                      /* TO  */
    AS = 288,                      /* AS  */
    TABLE = 289,                   /* TABLE  */
    OF = 290,                      /* OF  */
    CLOSURE = 291,                 /* CLOSURE  */
    IN = 292,                      /* IN  */
    WITH = 293,                    /* WITH  */
=======
    TYPE_STRING = 284,             /* TYPE_STRING  */
    UNKNOWN = 285,                 /* UNKNOWN  */
    TEST = 286,                    /* TEST  */
    WITH = 287,                    /* WITH  */
    TO = 288,                      /* TO  */
    AS = 289,                      /* AS  */
    TABLE = 290,                   /* TABLE  */
    OF = 291,                      /* OF  */
    CLOSURE = 292,                 /* CLOSURE  */
    IN = 293,                      /* IN  */
>>>>>>> be209b8824e0f7050916f057e2966a76425abd8e
    EQUIVALENT = 294,              /* EQUIVALENT  */
    OP_LEQ = 295,                  /* OP_LEQ  */
    OP_GEQ = 296,                  /* OP_GEQ  */
    OP_NEQ = 297,                  /* OP_NEQ  */
    OP_LT = 298,                   /* OP_LT  */
    OP_GT = 299,                   /* OP_GT  */
    OPEN_PARENTHESIS = 300,        /* OPEN_PARENTHESIS  */
    CLOSE_PARENTHESIS = 301,       /* CLOSE_PARENTHESIS  */
    STRING = 302                   /* STRING  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
#line 13 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
union SemanticValue
{
#line 17 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"

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

#line 134 "src/main/c/frontend/syntactic-analysis/BisonParser.h"

};
#line 13 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
typedef union SemanticValue YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif




#ifndef YYPUSH_MORE_DEFINED
# define YYPUSH_MORE_DEFINED
enum { YYPUSH_MORE = 4 };
#endif

typedef struct yypstate yypstate;


int yypush_parse (yypstate *ps,
                  int pushed_char, YYSTYPE const *pushed_val, YYLTYPE *pushed_loc);

yypstate *yypstate_new (void);
void yypstate_delete (yypstate *ps);


#endif /* !YY_YY_SRC_MAIN_C_FRONTEND_SYNTACTIC_ANALYSIS_BISONPARSER_H_INCLUDED  */
