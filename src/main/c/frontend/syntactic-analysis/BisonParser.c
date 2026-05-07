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
  YYSYMBOL_WITH = 32,                      /* WITH  */
  YYSYMBOL_TO = 33,                        /* TO  */
  YYSYMBOL_AS = 34,                        /* AS  */
  YYSYMBOL_TABLE = 35,                     /* TABLE  */
  YYSYMBOL_OF = 36,                        /* OF  */
  YYSYMBOL_CLOSURE = 37,                   /* CLOSURE  */
  YYSYMBOL_IN = 38,                        /* IN  */
  YYSYMBOL_EQUIVALENT = 39,                /* EQUIVALENT  */
  YYSYMBOL_OP_LEQ = 40,                    /* OP_LEQ  */
  YYSYMBOL_OP_GEQ = 41,                    /* OP_GEQ  */
  YYSYMBOL_OP_NEQ = 42,                    /* OP_NEQ  */
  YYSYMBOL_OP_LT = 43,                     /* OP_LT  */
  YYSYMBOL_OP_GT = 44,                     /* OP_GT  */
  YYSYMBOL_OPEN_PARENTHESIS = 45,          /* OPEN_PARENTHESIS  */
  YYSYMBOL_CLOSE_PARENTHESIS = 46,         /* CLOSE_PARENTHESIS  */
  YYSYMBOL_STRING = 47,                    /* STRING  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_program = 49,                   /* program  */
  YYSYMBOL_statement_list = 50,            /* statement_list  */
  YYSYMBOL_statement = 51,                 /* statement  */
  YYSYMBOL_automaton = 52,                 /* automaton  */
  YYSYMBOL_type = 53,                      /* type  */
  YYSYMBOL_definition = 54,                /* definition  */
  YYSYMBOL_alphabet_set = 55,              /* alphabet_set  */
  YYSYMBOL_alphabet_symbol_list = 56,      /* alphabet_symbol_list  */
  YYSYMBOL_alphabet_symbol = 57,           /* alphabet_symbol  */
  YYSYMBOL_state_set = 58,                 /* state_set  */
  YYSYMBOL_state_list = 59,                /* state_list  */
  YYSYMBOL_state = 60,                     /* state  */
  YYSYMBOL_transition_list = 61,           /* transition_list  */
  YYSYMBOL_transition = 62,                /* transition  */
  YYSYMBOL_transition_symbol = 63,         /* transition_symbol  */
  YYSYMBOL_transition_destination = 64,    /* transition_destination  */
  YYSYMBOL_test = 65,                      /* test  */
  YYSYMBOL_string_declaration = 66,        /* string_declaration  */
  YYSYMBOL_conversion = 67,                /* conversion  */
  YYSYMBOL_show = 68,                      /* show  */
  YYSYMBOL_print = 69,                     /* print  */
  YYSYMBOL_equivalent = 70,                /* equivalent  */
  YYSYMBOL_update = 71,                    /* update  */
  YYSYMBOL_update_body = 72                /* update_body  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   111

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  123

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


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
      45,    46,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   128,   128,   131,   132,   135,   136,   137,   138,   139,
     140,   141,   142,   145,   149,   150,   151,   154,   161,   164,
     165,   168,   169,   172,   175,   176,   179,   182,   183,   186,
     189,   190,   193,   194,   197,   198,   201,   204,   207,   208,
     209,   212,   215,   218,   221,   222,   223,   224
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
  "TYPE_LNFA", "TYPE_NFA", "TYPE_STRING", "UNKNOWN", "TEST", "WITH", "TO",
  "AS", "TABLE", "OF", "CLOSURE", "IN", "EQUIVALENT", "OP_LEQ", "OP_GEQ",
  "OP_NEQ", "OP_LT", "OP_GT", "OPEN_PARENTHESIS", "CLOSE_PARENTHESIS",
  "STRING", "$accept", "program", "statement_list", "statement",
  "automaton", "type", "definition", "alphabet_set",
  "alphabet_symbol_list", "alphabet_symbol", "state_set", "state_list",
  "state", "transition_list", "transition", "transition_symbol",
  "transition_destination", "test", "string_declaration", "conversion",
  "show", "print", "equivalent", "update", "update_body", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#define YYPACT_NINF (-89)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -1,     2,    20,     8,    21,   -21,    24,    30,    39,    50,
      -1,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
      41,    23,   -89,    32,    18,    22,    12,    53,    28,    48,
     -89,   -89,    13,    13,     0,   -89,    49,    51,    52,    19,
     -11,    42,   -89,   -89,   -89,    54,    33,    62,    55,    63,
      56,    57,    58,    25,    59,    60,    61,   -89,    66,    64,
      65,   -89,    65,   -89,   -89,   -89,    35,   -89,   -89,   -89,
      69,    75,    67,    72,   -89,   -89,     9,    73,    71,    70,
     -89,   -89,    37,   -89,   -89,    82,   -89,    74,    -6,    68,
     -89,   -89,    72,    16,   -89,   -89,   -89,    38,   -89,    84,
     -89,   -89,   -89,    83,   -89,    -6,    65,    -5,   -89,    76,
     -89,   -89,   -89,    88,    72,    93,    91,    65,    77,    80,
     -89,    14,   -89
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     3,     5,     6,     7,     8,     9,    10,    11,    12,
       0,     0,    44,     0,     0,     0,     0,     0,     0,     0,
       1,     4,     0,     0,     0,    41,     0,     0,     0,     0,
       0,     0,    14,    16,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,    43,     0,    27,    38,    39,     0,    36,    35,    34,
       0,     0,     0,     0,    46,    45,     0,     0,     0,     0,
      37,    26,     0,    24,    47,     0,    28,     0,     0,     0,
      13,    23,     0,     0,    40,    21,    22,     0,    19,     0,
      25,    31,    30,     0,    18,     0,     0,     0,    20,     0,
      33,    32,    29,     0,     0,     0,     0,     0,     0,     0,
      27,     0,    17
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -89,   -89,   -89,    90,   -89,    78,   -89,   -89,   -89,   -88,
     -62,   -89,   -72,   -19,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     9,    10,    11,    12,    45,    71,    89,    97,    98,
      74,    82,    85,    76,    86,   103,   112,    13,    14,    15,
      16,    17,    18,    19,    34
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      75,    83,    55,    47,    24,   102,     1,    95,    81,    48,
      96,     2,     3,    73,    25,    20,    26,   108,    84,     4,
     100,     5,    81,   122,    49,    50,    22,    81,     6,    95,
       7,   101,    96,    21,    23,   111,    56,    27,     8,    42,
      43,    44,   115,    28,   109,   110,    91,   104,    92,   105,
      30,    32,    29,    35,    36,   118,    33,    38,    37,    39,
      40,    41,    51,    57,    52,    53,    54,    59,    60,    62,
      70,    66,    58,    77,    63,    78,    61,    72,    64,    65,
      67,    68,    69,    73,    79,    81,    87,    93,    80,    88,
     106,    90,    99,   107,   114,    94,   116,   117,   120,   113,
      31,   121,   119,     0,     0,     0,     0,     0,     0,     0,
       0,    46
};

static const yytype_int8 yycheck[] =
{
      62,    73,    13,     3,    25,    93,     7,    13,    13,     9,
      16,    12,    13,    18,    35,    13,    37,   105,     9,    20,
      92,    22,    13,     9,    24,    25,    18,    13,    29,    13,
      31,    15,    16,    13,    13,   107,    47,    13,    39,    26,
      27,    28,   114,    13,   106,   107,     9,     9,    11,    11,
       0,    10,    13,    21,    36,   117,    33,    45,    36,     6,
      32,    13,    13,    21,    13,    13,    47,    34,     6,     6,
       4,    46,    18,    38,    18,     6,    21,    13,    21,    21,
      21,    21,    21,    18,     9,    13,    13,     5,    21,    18,
       6,    21,    24,    10,     6,    21,     3,     6,    18,    23,
      10,   120,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,    12,    13,    20,    22,    29,    31,    39,    49,
      50,    51,    52,    65,    66,    67,    68,    69,    70,    71,
      13,    13,    18,    13,    25,    35,    37,    13,    13,    13,
       0,    51,    10,    33,    72,    21,    36,    36,    45,     6,
      32,    13,    26,    27,    28,    53,    53,     3,     9,    24,
      25,    13,    13,    13,    47,    13,    47,    21,    18,    34,
       6,    21,     6,    18,    21,    21,    46,    21,    21,    21,
       4,    54,    13,    18,    58,    58,    61,    38,     6,     9,
      21,    13,    59,    60,     9,    60,    62,    13,    18,    55,
      21,     9,    11,     5,    21,    13,    16,    56,    57,    24,
      60,    15,    57,    63,     9,    11,     6,    10,    57,    58,
      58,    60,    64,    23,     6,    60,     3,     6,    58,    25,
      18,    61,     9
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    51,    51,    51,
      51,    51,    51,    52,    53,    53,    53,    54,    55,    56,
      56,    57,    57,    58,    59,    59,    60,    61,    61,    62,
      63,    63,    64,    64,    65,    65,    66,    67,    68,    68,
      68,    69,    70,    71,    72,    72,    72,    72
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     8,     1,     1,     1,    16,     3,     1,
       3,     1,     1,     3,     1,     3,     1,     0,     2,     5,
       1,     1,     1,     1,     5,     5,     5,     7,     5,     5,
       8,     3,     4,     5,     0,     4,     4,     5
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
#line 39 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { free(((*yyvaluep).string)); }
#line 1281 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_NUMERIC_SYMBOL: /* NUMERIC_SYMBOL  */
#line 39 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { free(((*yyvaluep).string)); }
#line 1287 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_STRING: /* STRING  */
#line 39 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { free(((*yyvaluep).string)); }
#line 1293 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_statement_list: /* statement_list  */
#line 47 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyStatement(((*yyvaluep).statement)); }
#line 1299 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 47 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyStatement(((*yyvaluep).statement)); }
#line 1305 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_automaton: /* automaton  */
#line 40 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyAutomaton(((*yyvaluep).automaton)); }
#line 1311 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_definition: /* definition  */
#line 46 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyDefinition(((*yyvaluep).definition)); }
#line 1317 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_alphabet_set: /* alphabet_set  */
#line 48 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyStringList(((*yyvaluep).stringList)); }
#line 1323 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_alphabet_symbol_list: /* alphabet_symbol_list  */
#line 48 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyStringList(((*yyvaluep).stringList)); }
#line 1329 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_alphabet_symbol: /* alphabet_symbol  */
#line 39 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { free(((*yyvaluep).string)); }
#line 1335 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_state_set: /* state_set  */
#line 48 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyStringList(((*yyvaluep).stringList)); }
#line 1341 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_state_list: /* state_list  */
#line 48 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyStringList(((*yyvaluep).stringList)); }
#line 1347 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_state: /* state  */
#line 39 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { free(((*yyvaluep).string)); }
#line 1353 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_transition_list: /* transition_list  */
#line 49 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyTransition(((*yyvaluep).transition)); }
#line 1359 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_transition: /* transition  */
#line 49 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyTransition(((*yyvaluep).transition)); }
#line 1365 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_transition_symbol: /* transition_symbol  */
#line 51 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyTransitionSymbol(((*yyvaluep).transitionSymbol)); }
#line 1371 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_transition_destination: /* transition_destination  */
#line 50 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyTransitionDestination(((*yyvaluep).transitionDestination)); }
#line 1377 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_test: /* test  */
#line 41 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyTest(((*yyvaluep).test)); }
#line 1383 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_string_declaration: /* string_declaration  */
#line 42 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyStringDeclaration(((*yyvaluep).stringDeclaration)); }
#line 1389 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_conversion: /* conversion  */
#line 43 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyConversion(((*yyvaluep).conversion)); }
#line 1395 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_show: /* show  */
#line 44 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyShow(((*yyvaluep).show)); }
#line 1401 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_print: /* print  */
#line 45 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyPrint(((*yyvaluep).print)); }
#line 1407 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_equivalent: /* equivalent  */
#line 52 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyEquivalent(((*yyvaluep).equivalent)); }
#line 1413 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_update: /* update  */
#line 53 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyUpdate(((*yyvaluep).update)); }
#line 1419 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
        break;

    case YYSYMBOL_update_body: /* update_body  */
#line 53 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
            { destroyUpdate(((*yyvaluep).update)); }
#line 1425 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
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
#line 128 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                        { (yyval.program) = StatementListProgramSemanticAction((yyvsp[0].statement)); }
#line 1794 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 3: /* statement_list: statement  */
#line 131 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                        { (yyval.statement) = (yyvsp[0].statement); }
#line 1800 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 4: /* statement_list: statement_list statement  */
#line 132 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                        { (yyval.statement) = AppendStatementListSemanticAction((yyvsp[-1].statement), (yyvsp[0].statement)); }
#line 1806 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 5: /* statement: automaton  */
#line 135 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                        { (yyval.statement) = AutomatonStatementSemanticAction((yyvsp[0].automaton)); }
#line 1812 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 6: /* statement: test  */
#line 136 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                        { (yyval.statement) = TestStatementSemanticAction((yyvsp[0].test)); }
#line 1818 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 7: /* statement: string_declaration  */
#line 137 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                        { (yyval.statement) = StringDeclarationStatementSemanticAction((yyvsp[0].stringDeclaration)); }
#line 1824 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 8: /* statement: conversion  */
#line 138 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                { (yyval.statement) = ConversionStatementSemanticAction((yyvsp[0].conversion)); }
#line 1830 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 9: /* statement: show  */
#line 139 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                        { (yyval.statement) = ShowStatementSemanticAction((yyvsp[0].show)); }
#line 1836 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 10: /* statement: print  */
#line 140 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                        { (yyval.statement) = PrintStatementSemanticAction((yyvsp[0].print)); }
#line 1842 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 11: /* statement: equivalent  */
#line 141 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                { (yyval.statement) = EquivalentStatementSemanticAction((yyvsp[0].equivalent)); }
#line 1848 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 12: /* statement: update  */
#line 142 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                        { (yyval.statement) = UpdateStatementSemanticAction((yyvsp[0].update)); }
#line 1854 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 13: /* automaton: AUTOMATON ID COLON type OPEN_CURLY_BRACKET definition CLOSE_CURLY_BRACKET SEMICOLON  */
#line 146 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                                { (yyval.automaton) = AutomatonSemanticAction((yyvsp[-6].string), (yyvsp[-4].type), (yyvsp[-2].definition)); }
#line 1860 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 14: /* type: TYPE_DFA  */
#line 149 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                { (yyval.type) = AutomatonTypeSemanticAction(DFA); }
#line 1866 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 15: /* type: TYPE_NFA  */
#line 150 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                        { (yyval.type) = AutomatonTypeSemanticAction(NFA); }
#line 1872 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 16: /* type: TYPE_LNFA  */
#line 151 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                        { (yyval.type) = AutomatonTypeSemanticAction(LNFA); }
#line 1878 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 17: /* definition: ALPHABET ASSIGN alphabet_set STATES ASSIGN state_set START ASSIGN state ACCEPT ASSIGN state_set TRANSITIONS OPEN_CURLY_BRACKET transition_list CLOSE_CURLY_BRACKET  */
#line 158 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                { (yyval.definition) = DefinitionSemanticAction((yyvsp[-13].stringList), (yyvsp[-10].stringList), (yyvsp[-7].string), (yyvsp[-4].stringList), (yyvsp[-1].transition)); }
#line 1884 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 18: /* alphabet_set: OPEN_CURLY_BRACKET alphabet_symbol_list CLOSE_CURLY_BRACKET  */
#line 161 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                        { (yyval.stringList) = (yyvsp[-1].stringList); }
#line 1890 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 19: /* alphabet_symbol_list: alphabet_symbol  */
#line 164 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                        { (yyval.stringList) = SingleStringListSemanticAction((yyvsp[0].string)); }
#line 1896 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 20: /* alphabet_symbol_list: alphabet_symbol_list COMMA alphabet_symbol  */
#line 165 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                { (yyval.stringList) = AppendStringListSemanticAction((yyvsp[-2].stringList), (yyvsp[0].string)); }
#line 1902 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 21: /* alphabet_symbol: ID  */
#line 168 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                { (yyval.string) = (yyvsp[0].string); }
#line 1908 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 22: /* alphabet_symbol: NUMERIC_SYMBOL  */
#line 169 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                { (yyval.string) = (yyvsp[0].string); }
#line 1914 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 23: /* state_set: OPEN_CURLY_BRACKET state_list CLOSE_CURLY_BRACKET  */
#line 172 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                { (yyval.stringList) = (yyvsp[-1].stringList); }
#line 1920 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 24: /* state_list: state  */
#line 175 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                { (yyval.stringList) = SingleStringListSemanticAction((yyvsp[0].string)); }
#line 1926 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 25: /* state_list: state_list COMMA state  */
#line 176 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                        { (yyval.stringList) = AppendStringListSemanticAction((yyvsp[-2].stringList), (yyvsp[0].string)); }
#line 1932 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 26: /* state: ID  */
#line 179 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                        { (yyval.string) = (yyvsp[0].string); }
#line 1938 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 27: /* transition_list: %empty  */
#line 182 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                { (yyval.transition) = NULL; }
#line 1944 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 28: /* transition_list: transition_list transition  */
#line 183 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                { (yyval.transition) = AppendTransitionListSemanticAction((yyvsp[-1].transition), (yyvsp[0].transition)); }
#line 1950 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 29: /* transition: state ARROW transition_symbol COLON transition_destination  */
#line 186 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                        { (yyval.transition) = TransitionSemanticAction((yyvsp[-4].string), (yyvsp[-2].transitionSymbol), (yyvsp[0].transitionDestination)); }
#line 1956 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 30: /* transition_symbol: alphabet_symbol  */
#line 189 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                { (yyval.transitionSymbol) = SymbolTransitionSymbolSemanticAction((yyvsp[0].string)); }
#line 1962 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 31: /* transition_symbol: LAMBDA  */
#line 190 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                        { (yyval.transitionSymbol) = LambdaTransitionSymbolSemanticAction(); }
#line 1968 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 32: /* transition_destination: state  */
#line 193 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                { (yyval.transitionDestination) = SingleTransitionDestinationSemanticAction((yyvsp[0].string)); }
#line 1974 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 33: /* transition_destination: state_set  */
#line 194 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                        { (yyval.transitionDestination) = MultipleTransitionDestinationSemanticAction((yyvsp[0].stringList)); }
#line 1980 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 34: /* test: TEST ID WITH STRING SEMICOLON  */
#line 197 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                { (yyval.test) = TestSemanticAction((yyvsp[-3].string), (yyvsp[-1].string)); }
#line 1986 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 35: /* test: TEST ID WITH ID SEMICOLON  */
#line 198 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                        { (yyval.test) = TestVariableSemanticAction((yyvsp[-3].string), (yyvsp[-1].string)); }
#line 1992 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 36: /* string_declaration: TYPE_STRING ID ASSIGN STRING SEMICOLON  */
#line 201 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                        { (yyval.stringDeclaration) = StringDeclarationSemanticAction((yyvsp[-3].string), (yyvsp[-1].string)); }
#line 1998 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 37: /* conversion: CONVERT ID TO type AS ID SEMICOLON  */
#line 204 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                        { (yyval.conversion) = ConversionSemanticAction((yyvsp[-5].string), (yyvsp[-3].type), (yyvsp[-1].string)); }
#line 2004 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 38: /* show: SHOW TRANSITIONS OF ID SEMICOLON  */
#line 207 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                { (yyval.show) = ShowTransitionsSemanticAction((yyvsp[-1].string)); }
#line 2010 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 39: /* show: SHOW TABLE OF ID SEMICOLON  */
#line 208 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                        { (yyval.show) = ShowTableSemanticAction((yyvsp[-1].string)); }
#line 2016 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 40: /* show: SHOW CLOSURE OPEN_PARENTHESIS ID CLOSE_PARENTHESIS IN ID SEMICOLON  */
#line 209 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                { (yyval.show) = ShowClosureSemanticAction((yyvsp[-4].string), (yyvsp[-1].string)); }
#line 2022 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 41: /* print: PRINT ID SEMICOLON  */
#line 212 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                { (yyval.print) = PrintSemanticAction((yyvsp[-1].string)); }
#line 2028 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 42: /* equivalent: EQUIVALENT ID ID SEMICOLON  */
#line 215 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                        { (yyval.equivalent) = EquivalentSemanticAction((yyvsp[-2].string), (yyvsp[-1].string)); }
#line 2034 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 43: /* update: ID OPEN_CURLY_BRACKET update_body CLOSE_CURLY_BRACKET SEMICOLON  */
#line 218 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                { (yyval.update) = UpdateSemanticAction((yyvsp[-4].string), (yyvsp[-2].update)); }
#line 2040 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 44: /* update_body: %empty  */
#line 221 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                { (yyval.update) = EmptyUpdateBodySemanticAction(); }
#line 2046 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 45: /* update_body: update_body STATES ASSIGN state_set  */
#line 222 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                        { (yyval.update) = StatesUpdateBodySemanticAction((yyvsp[-3].update), (yyvsp[0].stringList)); }
#line 2052 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 46: /* update_body: update_body ACCEPT ASSIGN state_set  */
#line 223 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                        { (yyval.update) = AcceptUpdateBodySemanticAction((yyvsp[-3].update), (yyvsp[0].stringList)); }
#line 2058 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;

  case 47: /* update_body: update_body TRANSITIONS OPEN_CURLY_BRACKET transition_list CLOSE_CURLY_BRACKET  */
#line 225 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"
                                                                                                                                                                { (yyval.update) = TransitionsUpdateBodySemanticAction((yyvsp[-4].update), (yyvsp[-1].transition)); }
#line 2064 "src/main/c/frontend/syntactic-analysis/BisonParser.c"
    break;


#line 2068 "src/main/c/frontend/syntactic-analysis/BisonParser.c"

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
#line 227 "src/main/c/frontend/syntactic-analysis/BisonGrammar.y"

