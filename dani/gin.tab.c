/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "gin.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "tree.h"

int yylex(void);
void yyerror(char *s);

FILE* yyin;
int yylineno;

#line 81 "gin.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "gin.tab.h".  */
#ifndef YY_YY_GIN_TAB_H_INCLUDED
# define YY_YY_GIN_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ASSIGN_SYMBOL = 258,
    AND = 259,
    OR = 260,
    TRUE = 261,
    FALSE = 262,
    NOT = 263,
    REAL = 264,
    INT = 265,
    VOID = 266,
    CHAR = 267,
    STRING = 268,
    BGIN = 269,
    END = 270,
    CLASS = 271,
    INTEGER = 272,
    FLOAT = 273,
    STR = 274,
    CHR = 275,
    ID = 276,
    WHILE = 277,
    IF = 278,
    PRINT = 279,
    FOR = 280,
    RETURN = 281,
    CONST = 282,
    IFX = 283,
    ELSE = 284,
    GEQ = 285,
    LEQ = 286,
    EQ = 287,
    NEQ = 288,
    GE = 289,
    LE = 290,
    MINUS = 291,
    PLUS = 292,
    TIMES = 293,
    DIVIDE = 294,
    MOD = 295,
    NEG = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "gin.y" /* yacc.c:355  */

    int iValue;
    double fValue;
    char* sValue;
    char cValue;
    char* sIndex;
    nodeType *nPtr;

#line 172 "gin.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GIN_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 189 "gin.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   421

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,     2,
      46,    47,     2,     2,    48,     2,    49,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    45,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    42,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    50,    50,    53,    54,    57,    58,    59,    60,    61,
      62,    63,    64,    67,    68,    71,    72,    73,    76,    77,
      80,    83,    86,    89,    90,    93,    94,    95,    98,    99,
     102,   103,   106,   107,   110,   111,   112,   113,   114,   117,
     118,   119,   124,   125,   126,   127,   128,   129,   130,   131,
     134,   135,   136,   137,   138,   139,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   153,   154,   155,   158,   162,
     166,   170,   176,   181,   186,   191,   196,   201,   208,   209,
     212,   213,   216,   217
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASSIGN_SYMBOL", "AND", "OR", "TRUE",
  "FALSE", "NOT", "REAL", "INT", "VOID", "CHAR", "STRING", "BGIN", "END",
  "CLASS", "INTEGER", "FLOAT", "STR", "CHR", "ID", "WHILE", "IF", "PRINT",
  "FOR", "RETURN", "CONST", "IFX", "ELSE", "GEQ", "LEQ", "EQ", "NEQ", "GE",
  "LE", "MINUS", "PLUS", "TIMES", "DIVIDE", "MOD", "'&'", "'|'", "'^'",
  "NEG", "';'", "'('", "')'", "','", "'.'", "'['", "']'", "$accept",
  "program", "statements", "statement", "statement_block", "instruction",
  "if_block", "for_block", "while_block", "class_block", "function_block",
  "function_call", "param_list_elem", "param_list", "expression_list",
  "declaration", "assignment", "expression", "aritmetic_expressions",
  "boolean_expressions", "binary_expressions", "type", "atom", "brackets",
  "class_declarations_element", "class_declarations", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,    38,   124,    94,   296,    59,    40,    41,    44,    46,
      91,    93
};
# endif

#define YYPACT_NINF -78

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-78)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -78,    14,   329,   -78,   -78,   -78,    80,   -78,   -78,   -78,
     -78,   329,   -18,   -78,   -78,   -78,   -78,     6,   -29,   -26,
     -10,    -9,    29,    80,   -78,    80,   -78,     2,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   378,   -78,   -78,   -78,
      27,   -78,   -41,   -78,   -78,   288,    63,    80,   -78,   246,
      61,    66,    25,    80,    80,    80,   360,    64,   -78,   126,
     -78,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    28,    68,   -78,
     -78,     3,   378,   -78,   -37,   378,    87,    40,    80,    75,
     144,   166,   184,    49,    74,    93,   -78,   248,   248,   248,
     248,   248,   248,   248,   248,   237,   237,    38,    38,    38,
     -78,   -78,   -78,    80,   125,    52,   -78,    82,   -78,    60,
     -78,   247,   -78,    80,    80,   -78,   378,    55,   329,   329,
     -78,    80,    26,    80,   378,    29,   329,   -78,   -15,    86,
     -78,   -78,   -78,   378,   378,   -78,   -78,    79,   206,   378,
      89,   -78,   329,    13,   -78,   329,    90,   -78,   -78,   -78,
     -78,     4,    65,    92,   329,    87,   -78
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,    76,    77,     0,    69,    68,    70,
      71,     0,     0,    72,    73,    74,    75,    43,     0,     0,
       0,     0,     0,     0,     5,     0,     3,     0,     7,     8,
       9,    11,    10,    48,    16,    15,    17,    45,    46,    47,
       0,    42,    43,    64,    13,     0,     0,     0,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,     0,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    34,     0,    12,
      14,     0,    39,    27,     0,    32,    44,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    49,    62,    63,    58,
      59,    60,    61,    57,    56,    52,    51,    53,    54,    55,
      65,    66,    67,     0,     0,    36,    44,     0,    81,     0,
      82,     0,    26,     0,     0,    79,    40,     0,     0,     0,
      25,     0,    34,     0,    35,     0,     0,    30,     0,     0,
      80,    22,    83,    33,    41,    78,    21,    18,     0,    37,
       0,    24,     0,     0,    28,     0,     0,    29,    23,    31,
      19,     0,     0,     0,     0,     0,    20
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -78,   -78,   -78,   -11,   -78,    59,   -78,   -78,   -78,   -78,
     -77,   -78,   -32,   -78,   -78,   -75,   -34,    -4,   -78,   -78,
     -78,   -21,   -78,   -59,     7,   -78
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    26,    45,    27,    28,    29,    30,    31,
      32,    33,   137,   138,    84,    34,    35,    36,    37,    38,
      39,    40,    41,    52,   120,   121
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      44,    57,    43,    46,   118,    49,   119,    47,    78,    47,
     122,   123,     7,     8,     3,     9,    10,    53,   115,    58,
      54,    59,     7,     8,   117,     9,    10,    48,    88,   113,
      22,   113,   152,   153,    80,    94,    55,    56,     7,     8,
     135,     9,    10,    82,   118,    85,   119,    60,    77,    90,
      91,    92,    49,   163,    51,    50,    51,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   115,   114,    89,    51,    81,    51,    74,
      75,    76,    86,    87,   126,    95,     4,     5,     6,   116,
     124,   125,   127,   139,   131,   132,   133,    13,    14,    15,
      16,    42,    89,    48,    20,   140,   145,   154,   155,   134,
     157,   161,   164,   165,   150,    93,    23,   146,   147,   143,
     144,   159,   162,     0,     0,   151,    25,   148,   142,   149,
      61,    62,   139,     0,     7,     8,     0,     9,    10,     0,
       0,   158,     0,     0,   160,     0,     0,     0,    61,    62,
       0,     0,   135,   166,     0,     0,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      61,    62,   136,    96,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    61,    62,
       0,   128,     0,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      61,    62,     0,   129,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,     0,     0,
       0,   130,     0,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
       0,   156,     4,     5,     6,     0,     7,     8,     0,     9,
      10,     0,   141,    13,    14,    15,    16,    42,   117,     0,
      20,     0,     0,     0,    22,    71,    72,    73,    74,    75,
      76,     0,    23,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    25,    83,     4,     5,     6,     7,     8,     0,
       9,    10,    11,    79,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,    22,     0,     0,     0,     0,
       0,     0,     0,     0,    23,     0,     0,     0,     0,     0,
       0,     0,     0,    24,    25,     4,     5,     6,     7,     8,
       0,     9,    10,    11,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,    22,     0,     0,     0,
       0,     0,     0,     0,     0,    23,     4,     5,     6,     7,
       8,     0,     9,    10,    24,    25,     0,    13,    14,    15,
      16,    17,    61,    62,    20,     0,     0,    22,     0,     0,
       0,     0,     0,     0,     0,     0,    23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76
};

static const yytype_int16 yycheck[] =
{
      11,    22,     6,    21,    81,    46,    81,     3,    49,     3,
      47,    48,     9,    10,     0,    12,    13,    46,    77,    23,
      46,    25,     9,    10,    21,    12,    13,    21,     3,     3,
      27,     3,    47,    48,    45,    56,    46,    46,     9,    10,
      27,    12,    13,    47,   121,    49,   121,    45,    21,    53,
      54,    55,    46,    49,    50,    49,    50,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,   132,    46,    50,    50,    14,    50,    41,
      42,    43,    21,    17,    88,    21,     6,     7,     8,    21,
       3,    51,    17,   114,    45,    21,     3,    17,    18,    19,
      20,    21,    50,    21,    24,    45,    51,    21,    29,   113,
      21,    21,    47,    21,   135,    56,    36,   128,   129,   123,
     124,   153,   156,    -1,    -1,   136,    46,   131,   121,   133,
       4,     5,   153,    -1,     9,    10,    -1,    12,    13,    -1,
      -1,   152,    -1,    -1,   155,    -1,    -1,    -1,     4,     5,
      -1,    -1,    27,   164,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       4,     5,    47,    47,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     4,     5,
      -1,    47,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       4,     5,    -1,    47,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    45,     6,     7,     8,    -1,     9,    10,    -1,    12,
      13,    -1,    15,    17,    18,    19,    20,    21,    21,    -1,
      24,    -1,    -1,    -1,    27,    38,    39,    40,    41,    42,
      43,    -1,    36,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    46,    47,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,     6,     7,     8,     9,
      10,    -1,    12,    13,    45,    46,    -1,    17,    18,    19,
      20,    21,     4,     5,    24,    -1,    -1,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    53,    54,     0,     6,     7,     8,     9,    10,    12,
      13,    14,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    27,    36,    45,    46,    55,    57,    58,    59,
      60,    61,    62,    63,    67,    68,    69,    70,    71,    72,
      73,    74,    21,    69,    55,    56,    21,     3,    21,    46,
      49,    50,    75,    46,    46,    46,    46,    73,    69,    69,
      45,     4,     5,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    21,    49,    15,
      55,    14,    69,    47,    66,    69,    21,    17,     3,    50,
      69,    69,    69,    57,    73,    21,    47,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,     3,    46,    75,    21,    21,    62,    67,
      76,    77,    47,    48,     3,    51,    69,    17,    47,    47,
      47,    45,    21,     3,    69,    27,    47,    64,    65,    73,
      45,    15,    76,    69,    69,    51,    55,    55,    69,    69,
      73,    55,    47,    48,    21,    29,    45,    21,    55,    64,
      55,    21,    68,    49,    47,    21,    55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    55,    55,    55,    55,
      55,    55,    55,    56,    56,    57,    57,    57,    58,    58,
      59,    60,    61,    62,    62,    63,    63,    63,    64,    64,
      65,    65,    66,    66,    67,    67,    67,    67,    67,    68,
      68,    68,    69,    69,    69,    69,    69,    69,    69,    69,
      70,    70,    70,    70,    70,    70,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    72,    72,    72,    73,    73,
      73,    73,    74,    74,    74,    74,    74,    74,    75,    75,
      76,    76,    77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     2,     1,     1,     1,
       1,     1,     3,     1,     2,     1,     1,     1,     5,     7,
       9,     5,     5,     6,     5,     4,     4,     3,     2,     3,
       1,     3,     1,     3,     2,     4,     3,     5,     2,     3,
       4,     5,     1,     1,     3,     1,     1,     1,     1,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     3,
       2,     1,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 50 "gin.y" /* yacc.c:1646  */
    { exit(0); }
#line 1433 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 53 "gin.y" /* yacc.c:1646  */
    { execute_tree((yyvsp[0].nPtr)); remove_tree((yyvsp[0].nPtr)); }
#line 1439 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 57 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node(';', 2, NULL, NULL); }
#line 1445 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 58 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1451 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 62 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1457 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 64 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1463 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 67 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1469 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 68 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node(';', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr)); }
#line 1475 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 76 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node(IF, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1481 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 77 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node(IF, 3, (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1487 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 80 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node(FOR, 4, (yyvsp[-6].nPtr), (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1493 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 83 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node(WHILE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1499 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 86 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node('@', 2, add_identifier_node((yyvsp[-3].sIndex)), (yyvsp[-1].nPtr)); }
#line 1505 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 89 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node('_', 4, (yyvsp[-5].nPtr), add_identifier_node((yyvsp[-4].sIndex)), (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1511 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 90 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node('_', 4, (yyvsp[-4].nPtr), add_identifier_node((yyvsp[-3].sIndex)), NULL, (yyvsp[0].nPtr));}
#line 1517 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 93 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node(PRINT, 1, (yyvsp[-1].nPtr)); }
#line 1523 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 94 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node('%', 2, add_identifier_node((yyvsp[-3].sIndex)), (yyvsp[-1].nPtr)); }
#line 1529 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 95 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node('%', 2, add_identifier_node((yyvsp[-2].sIndex)), NULL); }
#line 1535 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 98 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node('~', 2, (yyvsp[-1].nPtr), add_identifier_node((yyvsp[0].sIndex))); }
#line 1541 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 99 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node('~', 2, (yyvsp[-1].nPtr), add_identifier_node((yyvsp[0].sIndex))); }
#line 1547 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 103 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node(';', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1553 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 107 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node(';', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1559 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 110 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node('~', 2, (yyvsp[-1].nPtr), add_identifier_node((yyvsp[0].sIndex))); }
#line 1565 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 111 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node('~', 3, (yyvsp[-3].nPtr), add_identifier_node((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 1571 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 112 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node(';', 2, NULL, NULL); }
#line 1577 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 113 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node(';', 2, NULL, NULL); }
#line 1583 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 114 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node('#', 2, add_identifier_node((yyvsp[-1].sIndex)), add_identifier_node((yyvsp[0].sIndex))); }
#line 1589 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 117 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node(ASSIGN_SYMBOL, 2, add_identifier_node((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 1595 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 118 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node(';', 2, NULL, NULL); }
#line 1601 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 119 "gin.y" /* yacc.c:1646  */
    { char s[200] = {'\0'}; 
                                                   sprintf(s, "%s.%s", (yyvsp[-4].sIndex), (yyvsp[-2].sIndex)); 
                                                   (yyval.nPtr) = add_opr_node(ASSIGN_SYMBOL, 2, add_identifier_node(strdup(s)), (yyvsp[0].nPtr)); }
#line 1609 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 125 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_identifier_node((yyvsp[0].sIndex)); }
#line 1615 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 126 "gin.y" /* yacc.c:1646  */
    { char s[200] = {'\0'}; sprintf(s, "%s.%s", (yyvsp[-2].sIndex), (yyvsp[0].sIndex)); (yyval.nPtr) = add_identifier_node(strdup(s)); }
#line 1621 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 131 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1627 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 134 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node(NEG, 1, (yyvsp[0].nPtr)); }
#line 1633 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 135 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node(PLUS, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1639 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 136 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node(MINUS, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1645 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 137 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node(TIMES, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1651 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 138 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node(DIVIDE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1657 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 139 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node(MOD, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1663 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 142 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node(LE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1669 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 143 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node(GE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1675 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 144 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node(GEQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1681 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 145 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node(LEQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1687 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 146 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node(EQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1693 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 147 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node(NEQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1699 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 148 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node(AND, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1705 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 149 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node(OR, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1711 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 150 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node(NOT, 1, (yyvsp[0].nPtr)); }
#line 1717 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 153 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node('&', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1723 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 154 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node('|', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1729 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 155 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node('^', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1735 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 158 "gin.y" /* yacc.c:1646  */
    { Data* value;
             value = malloc(sizeof(Data));
             value->type = int_type;
             (yyval.nPtr) = add_constant_node(value); }
#line 1744 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 162 "gin.y" /* yacc.c:1646  */
    { Data* value;
             value = malloc(sizeof(Data));
             value->type = float_type;
             (yyval.nPtr) = add_constant_node(value);  }
#line 1753 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 166 "gin.y" /* yacc.c:1646  */
    { Data* value;
             value = malloc(sizeof(Data));
             value->type = char_type;
             (yyval.nPtr) = add_constant_node(value);  }
#line 1762 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 170 "gin.y" /* yacc.c:1646  */
    { Data* value;
             value = malloc(sizeof(Data));
             value->type = string_type;
             (yyval.nPtr) = add_constant_node(value);  }
#line 1771 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 176 "gin.y" /* yacc.c:1646  */
    { Data* value; 
                 value = malloc(sizeof(Data));
                 value->type = int_type; 
                 value->int_value = (yyvsp[0].iValue); 
                 (yyval.nPtr) = add_constant_node(value); }
#line 1781 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 181 "gin.y" /* yacc.c:1646  */
    { Data* value; 
                 value = malloc(sizeof(Data));
                 value->type = float_type; 
                 value->float_value = (yyvsp[0].fValue); 
                 (yyval.nPtr) = add_constant_node(value); }
#line 1791 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 186 "gin.y" /* yacc.c:1646  */
    { Data* value;
                 value = malloc(sizeof(Data));
                 value->type = string_type;
                 value->str_value = (yyvsp[0].sValue);
                 (yyval.nPtr) = add_constant_node(value); }
#line 1801 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 191 "gin.y" /* yacc.c:1646  */
    { Data* value;
                 value = malloc(sizeof(Data));
                 value->type = char_type;
                 value->chr_value = (yyvsp[0].cValue);
                 (yyval.nPtr) = add_constant_node(value); }
#line 1811 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 196 "gin.y" /* yacc.c:1646  */
    { Data* value;
                 value = malloc(sizeof(Data));
                 value->type = int_type; 
                 value->int_value = 1; 
                 (yyval.nPtr) = add_constant_node(value); }
#line 1821 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 201 "gin.y" /* yacc.c:1646  */
    { Data* value;
                 value = malloc(sizeof(Data));
                 value->type = int_type; 
                 value->int_value = 0; 
                 (yyval.nPtr) = add_constant_node(value); }
#line 1831 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 212 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1837 "gin.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 217 "gin.y" /* yacc.c:1646  */
    { (yyval.nPtr) = add_opr_node(';', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr)); }
#line 1843 "gin.tab.c" /* yacc.c:1646  */
    break;


#line 1847 "gin.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 219 "gin.y" /* yacc.c:1906  */


void yyerror(char *s) {
  fprintf(stdout, "%s\n", s);
}

int main(int argc, char** argv) {
  if(argc>0)
    yyin = fopen(argv[1], "r");

  yyparse();
  return 0;
}
