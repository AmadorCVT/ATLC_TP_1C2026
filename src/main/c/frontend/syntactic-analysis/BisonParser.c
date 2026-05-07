/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 1

/* Pull parsers.  */
#define YYPULL 0




/* First part of user prologue.  */
#line 1 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"


#include "../../support/type/TokenLabel.h"
#include "AbstractSyntaxTree.h"
#include "BisonActions.h"

void yyerror(const YYLTYPE * location, const char * message) {}


#line 81 "src/main/c/frontend/syntactic-analysis/BisonParser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "BisonParser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ACCEPT = 3,                     /* ACCEPT  */
  YYSYMBOL_ALPHABET = 4,                   /* ALPHABET  */
  YYSYMBOL_ARROW = 5,                      /* ARROW  */
  YYSYMBOL_ASSIGN = 6,                     /* ASSIGN  */
  YYSYMBOL_AUTOMATON = 7,                  /* AUTOMATON  */
  YYSYMBOL_CLOSE_COMMENT = 8,              /* CLOSE_COMMENT  */
  YYSYMBOL_CLOSE_CURLY_BRACKET = 9,        /* CLOSE_CURLY_BRACKET  */
  YYSYMBOL_COLON = 10,                     /* COLON  */
  YYSYMBOL_COMMA = 11,                     /* COMMA  */
  YYSYMBOL_CONVERT = 12,                   /* CONVERT  */
  YYSYMBOL_ID = 13,                        /* ID  */
  YYSYMBOL_IGNORED = 14,                   /* IGNORED  */
  YYSYMBOL_LAMBDA = 15,                    /* LAMBDA  */
  YYSYMBOL_NUMERIC_SYMBOL = 16,            /* NUMERIC_SYMBOL  */
  YYSYMBOL_OPEN_COMMENT = 17,              /* OPEN_COMMENT  */
  YYSYMBOL_OPEN_CURLY_BRACKET = 18,        /* OPEN_CURLY_BRACKET  */
  YYSYMBOL_QUOTATION_MARK = 19,            /* QUOTATION_MARK  */
  YYSYMBOL_PRINT = 20,                     /* PRINT  */
  YYSYMBOL_SEMICOLON = 21,                 /* SEMICOLON  */
  YYSYMBOL_SHOW = 22,                      /* SHOW  */
  YYSYMBOL_START = 23,                     /* START  */
  YYSYMBOL_STATES = 24,                    /* STATES  */
  YYSYMBOL_TRANSITIONS = 25,               /* TRANSITIONS  */
  YYSYMBOL_TYPE_DFA = 26,                  /* TYPE_DFA  */
  YYSYMBOL_TYPE_LNFA = 27,                 /* TYPE_LNFA  */
  YYSYMBOL_TYPE_NFA = 28,                  /* TYPE_NFA  */
  YYSYMBOL_TYPE_STRING = 29,               /* TYPE_STRING  */
  YYSYMBOL_UNKNOWN = 30,                   /* UNKNOWN  */
  YYSYMBOL_TEST = 31,                      /* TEST  */
  YYSYMBOL_FOR = 32,                       /* FOR  */
  YYSYMBOL_TO = 33,                        /* TO  */
  YYSYMBOL_AS = 34,                        /* AS  */
  YYSYMBOL_TABLE = 35,                     /* TABLE  */
  YYSYMBOL_OF = 36,                        /* OF  */
  YYSYMBOL_CLOSURE = 37,                   /* CLOSURE  */
  YYSYMBOL_IN = 38,                        /* IN  */
  YYSYMBOL_WITH = 39,                      /* WITH  */
  YYSYMBOL_EQUIVALENT = 40,                /* EQUIVALENT  */
  YYSYMBOL_OP_LEQ = 41,                    /* OP_LEQ  */
  YYSYMBOL_OP_GEQ = 42,                    /* OP_GEQ  */
  YYSYMBOL_OP_NEQ = 43,                    /* OP_NEQ  */
  YYSYMBOL_OP_LT = 44,                     /* OP_LT  */
  YYSYMBOL_OP_GT = 45,                     /* OP_GT  */
  YYSYMBOL_OPEN_PARENTHESIS = 46,          /* OPEN_PARENTHESIS  */
  YYSYMBOL_CLOSE_PARENTHESIS = 47,         /* CLOSE_PARENTHESIS  */
  YYSYMBOL_STRING = 48,                    /* STRING  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_program = 50,                   /* program  */
  YYSYMBOL_statement_list = 51,            /* statement_list  */
  YYSYMBOL_statement = 52,                 /* statement  */
  YYSYMBOL_for_loop = 53,                  /* for_loop  */
  YYSYMBOL_automaton = 54,                 /* automaton  */
  YYSYMBOL_type = 55,                      /* type  */
  YYSYMBOL_definition = 56,                /* definition  */
  YYSYMBOL_alphabet_set = 57,              /* alphabet_set  */
  YYSYMBOL_alphabet_symbol_list = 58,      /* alphabet_symbol_list  */
  YYSYMBOL_alphabet_symbol = 59,           /* alphabet_symbol  */
  YYSYMBOL_state_set = 60,                 /* state_set  */
  YYSYMBOL_array_list = 61,                /* array_list  */
  YYSYMBOL_state_list = 62,                /* state_list  */
  YYSYMBOL_state = 63,                     /* state  */
  YYSYMBOL_transition_list = 64,           /* transition_list  */
  YYSYMBOL_transition = 65,                /* transition  */
  YYSYMBOL_transition_symbol = 66,         /* transition_symbol  */
  YYSYMBOL_transition_destination = 67,    /* transition_destination  */
  YYSYMBOL_test = 68,                      /* test  */
  YYSYMBOL_string_declaration = 69,        /* string_declaration  */
  YYSYMBOL_conversion = 70,                /* conversion  */
  YYSYMBOL_show = 71,                      /* show  */
  YYSYMBOL_print = 72,                     /* print  */
  YYSYMBOL_equivalent = 73,                /* equivalent  */
  YYSYMBOL_update = 74,                    /* update  */
  YYSYMBOL_update_body = 75                /* update_body  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   124

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  136

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   303


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   135,   135,   138,   139,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   153,   157,   161,   162,   163,   166,
     173,   176,   177,   180,   181,   184,   187,   188,   191,   192,
     195,   198,   199,   202,   205,   206,   209,   210,   213,   214,
     217,   220,   223,   224,   225,   228,   231,   234,   237,   238,
     239,   240
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", "ACCEPT", "ALPHABET", "ARROW",
  "ASSIGN", "AUTOMATON", "CLOSE_COMMENT", "CLOSE_CURLY_BRACKET", "COLON",
  "COMMA", "CONVERT", "ID", "IGNORED", "LAMBDA", "NUMERIC_SYMBOL",
  "OPEN_COMMENT", "OPEN_CURLY_BRACKET", "QUOTATION_MARK", "PRINT",
  "SEMICOLON", "SHOW", "START", "STATES", "TRANSITIONS", "TYPE_DFA",
  "TYPE_LNFA", "TYPE_NFA", "TYPE_STRING", "UNKNOWN", "TEST", "FOR", "TO",
  "AS", "TABLE", "OF", "CLOSURE", "IN", "WITH", "EQUIVALENT", "OP_LEQ",
  "OP_GEQ", "OP_NEQ", "OP_LT", "OP_GT", "OPEN_PARENTHESIS",
  "CLOSE_PARENTHESIS", "STRING", "$accept", "program", "statement_list",
  "statement", "for_loop", "automaton", "type", "definition",
  "alphabet_set", "alphabet_symbol_list", "alphabet_symbol", "state_set",
  "array_list", "state_list", "state", "transition_list", "transition",
  "transition_symbol", "transition_destination", "test",
  "string_declaration", "conversion", "show", "print", "equivalent",
  "update", "update_body", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#define YYPACT_NINF (-85)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       1,    -8,     3,     4,    23,    10,    31,    39,    53,    55,
      62,     1,   -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,
     -85,   -85,    57,    36,   -85,    51,    34,    37,    25,    68,
      38,    40,    63,   -85,   -85,    29,    29,    15,   -85,    66,
      67,    69,    27,   -10,    65,    60,   -85,   -85,   -85,    70,
      52,    78,    64,    81,    71,    72,    73,    43,    75,    76,
      77,    79,   -85,    87,    86,    82,   -85,    82,   -85,   -85,
     -85,    74,   -85,   -85,   -85,   -85,    49,    95,    93,    83,
      90,   -85,   -85,     2,    92,    88,    94,    91,    89,   -85,
     -85,    50,   -85,   -85,   103,   -85,    96,     1,   -85,    30,
      97,   -85,   -85,    90,    35,   -85,    -3,   -85,   -85,    54,
     -85,   105,   -85,   -85,   -85,   104,   -85,   -85,    30,    82,
      -6,   -85,    99,   -85,   -85,   -85,   107,    90,   112,   110,
      82,    98,   100,   -85,    18,   -85
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     3,    13,     5,     6,     7,     8,     9,    10,
      11,    12,     0,     0,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     4,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,    16,    18,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    46,     0,     0,     0,    47,     0,    31,    42,
      43,     0,    40,    39,    38,    26,     0,     0,     0,     0,
       0,    50,    49,     0,     0,     0,     0,     0,     0,    41,
      30,     0,    28,    51,     0,    32,     0,     0,    27,     0,
       0,    15,    25,     0,     0,    44,     0,    23,    24,     0,
      21,     0,    29,    35,    34,     0,    14,    20,     0,     0,
       0,    22,     0,    37,    36,    33,     0,     0,     0,     0,
       0,     0,     0,    31,     0,    19
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -85,   -85,    22,   -11,   -85,   -85,    84,   -85,   -85,   -85,
     -84,   -66,   -85,   -85,   -78,    -9,   -85,   -85,   -85,   -85,
     -85,   -85,   -85,   -85,   -85,   -85,   -85
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    10,    11,    12,    13,    14,    49,    78,   100,   109,
     110,    81,    76,    91,    94,    83,    95,   115,   125,    15,
      16,    17,    18,    19,    20,    21,    37
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      34,    82,    92,    59,     1,    22,   116,    90,     1,     2,
       3,    93,    80,     2,     3,    90,    23,     4,    51,     5,
     114,     4,    24,     5,    52,   112,     6,   135,     7,     8,
       6,    90,     7,     8,   121,    26,    25,     9,    60,    53,
      54,     9,   124,   107,    29,    27,   108,    28,   107,   128,
     113,   108,    30,   122,   123,    46,    47,    48,    85,   102,
      86,   103,    33,   117,   131,   118,    31,    35,    32,    36,
      39,    41,    38,    40,    42,    58,    45,    43,    44,    55,
      56,    62,    57,    61,    65,    66,    64,    67,    63,    68,
      71,    77,    75,    69,    70,    34,    72,    73,    74,    79,
      80,    87,    88,    90,    89,    96,    97,    98,   104,    99,
     101,   119,    84,   127,   120,   129,   130,   105,   133,   106,
      50,   111,   126,   132,   134
};

static const yytype_uint8 yycheck[] =
{
      11,    67,    80,    13,     7,    13,     9,    13,     7,    12,
      13,     9,    18,    12,    13,    13,    13,    20,     3,    22,
     104,    20,    18,    22,     9,   103,    29,     9,    31,    32,
      29,    13,    31,    32,   118,    25,    13,    40,    48,    24,
      25,    40,   120,    13,    13,    35,    16,    37,    13,   127,
      15,    16,    13,   119,   120,    26,    27,    28,     9,     9,
      11,    11,     0,     9,   130,    11,    13,    10,    13,    33,
      36,    46,    21,    36,     6,    48,    13,    39,    38,    13,
      13,    21,    13,    18,     6,    21,    34,     6,    18,    18,
      47,     4,    13,    21,    21,   106,    21,    21,    21,    13,
      18,     6,     9,    13,    21,    13,    18,    13,     5,    18,
      21,     6,    38,     6,    10,     3,     6,    21,    18,    97,
      36,    24,    23,    25,   133
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,    12,    13,    20,    22,    29,    31,    32,    40,
      50,    51,    52,    53,    54,    68,    69,    70,    71,    72,
      73,    74,    13,    13,    18,    13,    25,    35,    37,    13,
      13,    13,    13,     0,    52,    10,    33,    75,    21,    36,
      36,    46,     6,    39,    38,    13,    26,    27,    28,    55,
      55,     3,     9,    24,    25,    13,    13,    13,    48,    13,
      48,    18,    21,    18,    34,     6,    21,     6,    18,    21,
      21,    47,    21,    21,    21,    13,    61,     4,    56,    13,
      18,    60,    60,    64,    38,     9,    11,     6,     9,    21,
      13,    62,    63,     9,    63,    65,    13,    18,    13,    18,
      57,    21,     9,    11,     5,    21,    51,    13,    16,    58,
      59,    24,    63,    15,    59,    66,     9,     9,    11,     6,
      10,    59,    60,    60,    63,    67,    23,     6,    63,     3,
       6,    60,    25,    18,    64,     9
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    53,    54,    55,    55,    55,    56,
      57,    58,    58,    59,    59,    60,    61,    61,    62,    62,
      63,    64,    64,    65,    66,    66,    67,    67,    68,    68,
      69,    70,    71,    71,    71,    72,    73,    74,    75,    75,
      75,    75
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     9,     8,     1,     1,     1,    16,
       3,     1,     3,     1,     1,     3,     1,     3,     1,     3,
       1,     0,     2,     5,     1,     1,     1,     1,     5,     5,
       5,     7,     5,     5,     8,     3,     4,     5,     0,     4,
       4,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif
/* Parser data structure.  */
struct yypstate
  {
    /* Number of syntax errors so far.  */
    int yynerrs;

    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;
    /* Whether this instance has not started parsing yet.
     * If 2, it corresponds to a finished parsing.  */
    int yynew;
  };


/* Context of a parse error.  */
typedef struct
{
  yypstate* yyps;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypstate_expected_tokens (yypstate *yyps,
                          yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyps->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}


/* Similar to the previous function.  */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  return yypstate_expected_tokens (yyctx->yyps, yyarg, yyargn);
}


#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif



static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yystrlen (yysymbol_name (yyarg[yyi]));
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_ID: /* ID  */
#line 42 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { free(((*yyvaluep).string)); }
#line 1293 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_NUMERIC_SYMBOL: /* NUMERIC_SYMBOL  */
#line 42 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { free(((*yyvaluep).string)); }
#line 1299 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_STRING: /* STRING  */
#line 42 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { free(((*yyvaluep).string)); }
#line 1305 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_statement_list: /* statement_list  */
#line 51 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyStatement(((*yyvaluep).statement)); }
#line 1311 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 51 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyStatement(((*yyvaluep).statement)); }
#line 1317 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_for_loop: /* for_loop  */
#line 44 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyFor(((*yyvaluep).for_loop)); }
#line 1323 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_automaton: /* automaton  */
#line 43 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyAutomaton(((*yyvaluep).automaton)); }
#line 1329 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_definition: /* definition  */
#line 50 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyDefinition(((*yyvaluep).definition)); }
#line 1335 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_alphabet_set: /* alphabet_set  */
#line 52 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyStringList(((*yyvaluep).stringList)); }
#line 1341 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_alphabet_symbol_list: /* alphabet_symbol_list  */
#line 52 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyStringList(((*yyvaluep).stringList)); }
#line 1347 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_alphabet_symbol: /* alphabet_symbol  */
#line 42 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { free(((*yyvaluep).string)); }
#line 1353 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_state_set: /* state_set  */
#line 52 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyStringList(((*yyvaluep).stringList)); }
#line 1359 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_array_list: /* array_list  */
#line 52 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyStringList(((*yyvaluep).stringList)); }
#line 1365 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_state_list: /* state_list  */
#line 52 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyStringList(((*yyvaluep).stringList)); }
#line 1371 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_state: /* state  */
#line 42 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { free(((*yyvaluep).string)); }
#line 1377 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_transition_list: /* transition_list  */
#line 53 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyTransition(((*yyvaluep).transition)); }
#line 1383 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_transition: /* transition  */
#line 53 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyTransition(((*yyvaluep).transition)); }
#line 1389 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_transition_symbol: /* transition_symbol  */
#line 55 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyTransitionSymbol(((*yyvaluep).transitionSymbol)); }
#line 1395 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_transition_destination: /* transition_destination  */
#line 54 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyTransitionDestination(((*yyvaluep).transitionDestination)); }
#line 1401 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_test: /* test  */
#line 45 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyTest(((*yyvaluep).test)); }
#line 1407 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_string_declaration: /* string_declaration  */
#line 46 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyStringDeclaration(((*yyvaluep).stringDeclaration)); }
#line 1413 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_conversion: /* conversion  */
#line 47 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyConversion(((*yyvaluep).conversion)); }
#line 1419 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_show: /* show  */
#line 48 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyShow(((*yyvaluep).show)); }
#line 1425 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_print: /* print  */
#line 49 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyPrint(((*yyvaluep).print)); }
#line 1431 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_equivalent: /* equivalent  */
#line 56 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyEquivalent(((*yyvaluep).equivalent)); }
#line 1437 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_update: /* update  */
#line 57 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyUpdate(((*yyvaluep).update)); }
#line 1443 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_update_body: /* update_body  */
#line 57 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyUpdate(((*yyvaluep).update)); }
#line 1449 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}





#define yynerrs yyps->yynerrs
#define yystate yyps->yystate
#define yyerrstatus yyps->yyerrstatus
#define yyssa yyps->yyssa
#define yyss yyps->yyss
#define yyssp yyps->yyssp
#define yyvsa yyps->yyvsa
#define yyvs yyps->yyvs
#define yyvsp yyps->yyvsp
#define yylsa yyps->yylsa
#define yyls yyps->yyls
#define yylsp yyps->yylsp
#define yystacksize yyps->yystacksize

/* Initialize the parser data structure.  */
static void
yypstate_clear (yypstate *yyps)
{
  yynerrs = 0;
  yystate = 0;
  yyerrstatus = 0;

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

  /* Initialize the state stack, in case yypcontext_expected_tokens is
     called before the first call to yyparse. */
  *yyssp = 0;
  yyps->yynew = 1;
}

/* Initialize the parser data structure.  */
yypstate *
yypstate_new (void)
{
  yypstate *yyps;
  yyps = YY_CAST (yypstate *, YYMALLOC (sizeof *yyps));
  if (!yyps)
    return YY_NULLPTR;
  yystacksize = YYINITDEPTH;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yypstate_clear (yyps);
  return yyps;
}

void
yypstate_delete (yypstate *yyps)
{
  if (yyps)
    {
#ifndef yyoverflow
      /* If the stack was reallocated but the parse did not complete, then the
         stack still needs to be freed.  */
      if (yyss != yyssa)
        YYSTACK_FREE (yyss);
#endif
      YYFREE (yyps);
    }
}



/*---------------.
| yypush_parse.  |
`---------------*/

int
yypush_parse (yypstate *yyps,
              int yypushed_char, YYSTYPE const *yypushed_val, YYLTYPE *yypushed_loc)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  switch (yyps->yynew)
    {
    case 0:
      yyn = yypact[yystate];
      goto yyread_pushed_token;

    case 2:
      yypstate_clear (yyps);
      break;

    default:
      break;
    }

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = *yypushed_loc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      if (!yyps->yynew)
        {
          YYDPRINTF ((stderr, "Return for a new token:\n"));
          yyresult = YYPUSH_MORE;
          goto yypushreturn;
        }
      yyps->yynew = 0;
yyread_pushed_token:
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yypushed_char;
      if (yypushed_val)
        yylval = *yypushed_val;
      if (yypushed_loc)
        yylloc = *yypushed_loc;
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: statement_list  */
#line 135 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                        { (yyval.program) = StatementListProgramSemanticAction((yyvsp[0].statement)); }
#line 1818 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 3: /* statement_list: statement  */
#line 138 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                        { (yyval.statement) = (yyvsp[0].statement); }
#line 1824 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 4: /* statement_list: statement_list statement  */
#line 139 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                        { (yyval.statement) = AppendStatementListSemanticAction((yyvsp[-1].statement), (yyvsp[0].statement)); }
#line 1830 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 5: /* statement: automaton  */
#line 142 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                        { (yyval.statement) = AutomatonStatementSemanticAction((yyvsp[0].automaton)); }
#line 1836 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 6: /* statement: test  */
#line 143 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                        { (yyval.statement) = TestStatementSemanticAction((yyvsp[0].test)); }
#line 1842 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 7: /* statement: string_declaration  */
#line 144 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                        { (yyval.statement) = StringDeclarationStatementSemanticAction((yyvsp[0].stringDeclaration)); }
#line 1848 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 8: /* statement: conversion  */
#line 145 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                { (yyval.statement) = ConversionStatementSemanticAction((yyvsp[0].conversion)); }
#line 1854 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 9: /* statement: show  */
#line 146 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                        { (yyval.statement) = ShowStatementSemanticAction((yyvsp[0].show)); }
#line 1860 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 10: /* statement: print  */
#line 147 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                        { (yyval.statement) = PrintStatementSemanticAction((yyvsp[0].print)); }
#line 1866 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 11: /* statement: equivalent  */
#line 148 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                { (yyval.statement) = EquivalentStatementSemanticAction((yyvsp[0].equivalent)); }
#line 1872 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 12: /* statement: update  */
#line 149 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                        { (yyval.statement) = UpdateStatementSemanticAction((yyvsp[0].update)); }
#line 1878 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 13: /* statement: for_loop  */
#line 150 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                        { (yyval.statement) = ForStatementSemanticAction((yyvsp[0].for_loop)); }
#line 1884 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 14: /* for_loop: FOR ID IN OPEN_CURLY_BRACKET array_list CLOSE_CURLY_BRACKET OPEN_CURLY_BRACKET statement_list CLOSE_CURLY_BRACKET  */
#line 154 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                                { (yyval.for_loop) = ForSemanticAction((yyvsp[-7].string), (yyvsp[-4].stringList), (yyvsp[-1].statement)); }
#line 1890 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 15: /* automaton: AUTOMATON ID COLON type OPEN_CURLY_BRACKET definition CLOSE_CURLY_BRACKET SEMICOLON  */
#line 158 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                                { (yyval.automaton) = AutomatonSemanticAction((yyvsp[-6].string), (yyvsp[-4].type), (yyvsp[-2].definition)); }
#line 1896 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 16: /* type: TYPE_DFA  */
#line 161 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                { (yyval.type) = AutomatonTypeSemanticAction(DFA); }
#line 1902 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 17: /* type: TYPE_NFA  */
#line 162 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                        { (yyval.type) = AutomatonTypeSemanticAction(NFA); }
#line 1908 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 18: /* type: TYPE_LNFA  */
#line 163 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                        { (yyval.type) = AutomatonTypeSemanticAction(LNFA); }
#line 1914 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 19: /* definition: ALPHABET ASSIGN alphabet_set STATES ASSIGN state_set START ASSIGN state ACCEPT ASSIGN state_set TRANSITIONS OPEN_CURLY_BRACKET transition_list CLOSE_CURLY_BRACKET  */
#line 170 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                { (yyval.definition) = DefinitionSemanticAction((yyvsp[-13].stringList), (yyvsp[-10].stringList), (yyvsp[-7].string), (yyvsp[-4].stringList), (yyvsp[-1].transition)); }
#line 1920 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 20: /* alphabet_set: OPEN_CURLY_BRACKET alphabet_symbol_list CLOSE_CURLY_BRACKET  */
#line 173 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                        { (yyval.stringList) = (yyvsp[-1].stringList); }
#line 1926 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 21: /* alphabet_symbol_list: alphabet_symbol  */
#line 176 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                        { (yyval.stringList) = SingleStringListSemanticAction((yyvsp[0].string)); }
#line 1932 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 22: /* alphabet_symbol_list: alphabet_symbol_list COMMA alphabet_symbol  */
#line 177 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                { (yyval.stringList) = AppendStringListSemanticAction((yyvsp[-2].stringList), (yyvsp[0].string)); }
#line 1938 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 23: /* alphabet_symbol: ID  */
#line 180 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                { (yyval.string) = (yyvsp[0].string); }
#line 1944 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 24: /* alphabet_symbol: NUMERIC_SYMBOL  */
#line 181 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                { (yyval.string) = (yyvsp[0].string); }
#line 1950 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 25: /* state_set: OPEN_CURLY_BRACKET state_list CLOSE_CURLY_BRACKET  */
#line 184 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                { (yyval.stringList) = (yyvsp[-1].stringList); }
#line 1956 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 26: /* array_list: ID  */
#line 187 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                { (yyval.stringList) = SingleStringListSemanticAction((yyvsp[0].string)); }
#line 1962 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 27: /* array_list: array_list COMMA ID  */
#line 188 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                        { (yyval.stringList) = AppendStringListSemanticAction((yyvsp[-2].stringList), (yyvsp[0].string)); }
#line 1968 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 28: /* state_list: state  */
#line 191 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                { (yyval.stringList) = SingleStringListSemanticAction((yyvsp[0].string)); }
#line 1974 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 29: /* state_list: state_list COMMA state  */
#line 192 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                        { (yyval.stringList) = AppendStringListSemanticAction((yyvsp[-2].stringList), (yyvsp[0].string)); }
#line 1980 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 30: /* state: ID  */
#line 195 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                        { (yyval.string) = (yyvsp[0].string); }
#line 1986 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 31: /* transition_list: %empty  */
#line 198 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                        { (yyval.transition) = NULL; }
#line 1992 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 32: /* transition_list: transition_list transition  */
#line 199 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                { (yyval.transition) = AppendTransitionListSemanticAction((yyvsp[-1].transition), (yyvsp[0].transition)); }
#line 1998 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 33: /* transition: state ARROW transition_symbol COLON transition_destination  */
#line 202 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                        { (yyval.transition) = TransitionSemanticAction((yyvsp[-4].string), (yyvsp[-2].transitionSymbol), (yyvsp[0].transitionDestination)); }
#line 2004 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 34: /* transition_symbol: alphabet_symbol  */
#line 205 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                { (yyval.transitionSymbol) = SymbolTransitionSymbolSemanticAction((yyvsp[0].string)); }
#line 2010 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 35: /* transition_symbol: LAMBDA  */
#line 206 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                        { (yyval.transitionSymbol) = LambdaTransitionSymbolSemanticAction(); }
#line 2016 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 36: /* transition_destination: state  */
#line 209 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                { (yyval.transitionDestination) = SingleTransitionDestinationSemanticAction((yyvsp[0].string)); }
#line 2022 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 37: /* transition_destination: state_set  */
#line 210 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                        { (yyval.transitionDestination) = MultipleTransitionDestinationSemanticAction((yyvsp[0].stringList)); }
#line 2028 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 38: /* test: TEST ID WITH STRING SEMICOLON  */
#line 213 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                { (yyval.test) = TestSemanticAction((yyvsp[-3].string), (yyvsp[-1].string)); }
#line 2034 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 39: /* test: TEST ID WITH ID SEMICOLON  */
#line 214 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                        { (yyval.test) = TestVariableSemanticAction((yyvsp[-3].string), (yyvsp[-1].string)); }
#line 2040 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 40: /* string_declaration: TYPE_STRING ID ASSIGN STRING SEMICOLON  */
#line 217 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                        { (yyval.stringDeclaration) = StringDeclarationSemanticAction((yyvsp[-3].string), (yyvsp[-1].string)); }
#line 2046 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 41: /* conversion: CONVERT ID TO type AS ID SEMICOLON  */
#line 220 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                        { (yyval.conversion) = ConversionSemanticAction((yyvsp[-5].string), (yyvsp[-3].type), (yyvsp[-1].string)); }
#line 2052 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 42: /* show: SHOW TRANSITIONS OF ID SEMICOLON  */
#line 223 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                { (yyval.show) = ShowTransitionsSemanticAction((yyvsp[-1].string)); }
#line 2058 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 43: /* show: SHOW TABLE OF ID SEMICOLON  */
#line 224 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                        { (yyval.show) = ShowTableSemanticAction((yyvsp[-1].string)); }
#line 2064 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 44: /* show: SHOW CLOSURE OPEN_PARENTHESIS ID CLOSE_PARENTHESIS IN ID SEMICOLON  */
#line 225 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                { (yyval.show) = ShowClosureSemanticAction((yyvsp[-4].string), (yyvsp[-1].string)); }
#line 2070 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 45: /* print: PRINT ID SEMICOLON  */
#line 228 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                { (yyval.print) = PrintSemanticAction((yyvsp[-1].string)); }
#line 2076 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 46: /* equivalent: EQUIVALENT ID ID SEMICOLON  */
#line 231 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                        { (yyval.equivalent) = EquivalentSemanticAction((yyvsp[-2].string), (yyvsp[-1].string)); }
#line 2082 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 47: /* update: ID OPEN_CURLY_BRACKET update_body CLOSE_CURLY_BRACKET SEMICOLON  */
#line 234 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                { (yyval.update) = UpdateSemanticAction((yyvsp[-4].string), (yyvsp[-2].update)); }
#line 2088 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 48: /* update_body: %empty  */
#line 237 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                { (yyval.update) = EmptyUpdateBodySemanticAction(); }
#line 2094 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 49: /* update_body: update_body STATES ASSIGN state_set  */
#line 238 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                        { (yyval.update) = StatesUpdateBodySemanticAction((yyvsp[-3].update), (yyvsp[0].stringList)); }
#line 2100 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 50: /* update_body: update_body ACCEPT ASSIGN state_set  */
#line 239 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                        { (yyval.update) = AcceptUpdateBodySemanticAction((yyvsp[-3].update), (yyvsp[0].stringList)); }
#line 2106 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 51: /* update_body: update_body TRANSITIONS OPEN_CURLY_BRACKET transition_list CLOSE_CURLY_BRACKET  */
#line 241 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                                { (yyval.update) = TransitionsUpdateBodySemanticAction((yyvsp[-4].update), (yyvsp[-1].transition)); }
#line 2112 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;


#line 2116 "src/main/c/frontend/syntactic-analysis/BisonParser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyps, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
  yyps->yynew = 2;
  goto yypushreturn;


/*-------------------------.
| yypushreturn -- return.  |
`-------------------------*/
yypushreturn:
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}
#undef yynerrs
#undef yystate
#undef yyerrstatus
#undef yyssa
#undef yyss
#undef yyssp
#undef yyvsa
#undef yyvs
#undef yyvsp
#undef yylsa
#undef yyls
#undef yylsp
#undef yystacksize
#line 243 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"

