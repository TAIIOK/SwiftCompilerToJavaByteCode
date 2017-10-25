/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IMPORT = 258,
     INT = 259,
     FLOAT = 260,
     DOUBLE = 261,
     BOOL = 262,
     STRING = 263,
     ARRAYINTT = 264,
     ARRAYBOOLT = 265,
     ARRAYSTRINGT = 266,
     ARRAYFLOATT = 267,
     ARRAYDOUBLET = 268,
     STRINGT = 269,
     CHARACTERT = 270,
     INTT = 271,
     FLOATT = 272,
     DOUBLET = 273,
     BOOLT = 274,
     TRUE = 275,
     FALSE = 276,
     LET = 277,
     VAR = 278,
     REPEAT = 279,
     WHILE = 280,
     FOR = 281,
     IN = 282,
     IF = 283,
     ELSE = 284,
     ELSEIF = 285,
     SWITCH = 286,
     CASE = 287,
     DEFAULT = 288,
     BREAK = 289,
     FUNCTION = 290,
     FUNCTIONARROW = 291,
     DO = 292,
     RANGE = 293,
     RETURN = 294,
     NIL = 295,
     SELF = 296,
     ERROR = 297,
     ID = 298,
     EQ = 299,
     NE = 300,
     LE = 301,
     GE = 302,
     NOT = 303,
     ENDL = 304,
     OR = 305,
     AND = 306,
     UMINUS = 307
   };
#endif
/* Tokens.  */
#define IMPORT 258
#define INT 259
#define FLOAT 260
#define DOUBLE 261
#define BOOL 262
#define STRING 263
#define ARRAYINTT 264
#define ARRAYBOOLT 265
#define ARRAYSTRINGT 266
#define ARRAYFLOATT 267
#define ARRAYDOUBLET 268
#define STRINGT 269
#define CHARACTERT 270
#define INTT 271
#define FLOATT 272
#define DOUBLET 273
#define BOOLT 274
#define TRUE 275
#define FALSE 276
#define LET 277
#define VAR 278
#define REPEAT 279
#define WHILE 280
#define FOR 281
#define IN 282
#define IF 283
#define ELSE 284
#define ELSEIF 285
#define SWITCH 286
#define CASE 287
#define DEFAULT 288
#define BREAK 289
#define FUNCTION 290
#define FUNCTIONARROW 291
#define DO 292
#define RANGE 293
#define RETURN 294
#define NIL 295
#define SELF 296
#define ERROR 297
#define ID 298
#define EQ 299
#define NE 300
#define LE 301
#define GE 302
#define NOT 303
#define ENDL 304
#define OR 305
#define AND 306
#define UMINUS 307




/* Copy the first part of user declarations.  */
#line 1 "../bison/swift.y"

    #include <stdio.h>
    #include "swift.tab.h"
    #include "tree_nodes_funcs.h"
    #define YYDEBUG 1
    extern int yylex(void);

    void yyerror(const char *s)
    {

        fprintf(stderr,"Lines %d: %s %s\n", yylloc.first_line, s);
        exit(1);
    }

    struct NStmtList* root;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "../bison/swift.y"
{
    int Int;
    char* Id;
    char* String;
    double Double;
    float Float;
    bool Bool;
    struct NWhile * While;
    struct NExpr * Expr;
    struct NFor * For;
    struct NStmtList * SL;
    struct NStmt * Stmt;
    struct NFunc * Func;
    struct NExprList * Args;
    struct NIf * If;
    struct NIfList * IfL;
    struct NTable* Table;
    struct NTblElem* TblElem;
    struct NSwitch * Switch;
    struct NImport * Import;
    struct NConstant * Constant;
    struct NCase * Case;
    struct NLabelCase * LabelCase;
    struct NCaseList * CaseL;
    struct NVarType * VarType;

}
/* Line 193 of yacc.c.  */
#line 246 "swift.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 271 "swift.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   620

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNRULES -- Number of states.  */
#define YYNSTATES  197

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    58,     2,     2,
      68,    69,    56,    54,    70,    55,    65,    57,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    64,    60,
      52,    63,    53,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    66,     2,    67,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,     2,    62,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    59
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    13,    16,    20,
      21,    25,    27,    29,    31,    33,    35,    37,    40,    43,
      47,    49,    52,    57,    59,    61,    69,    80,    81,    86,
      95,    96,    99,   102,   105,   109,   112,   116,   122,   127,
     129,   131,   135,   137,   139,   141,   146,   149,   156,   161,
     163,   165,   167,   169,   171,   173,   175,   177,   179,   182,
     185,   188,   192,   196,   200,   204,   208,   212,   216,   220,
     224,   228,   232,   236,   240,   244,   248,   254,   256,   258,
     263,   264,   266,   268,   272,   278,   280,   282,   284,   286,
     288,   290,   292,   294,   296,   298,   300,   304,   311,   316,
     317,   318,   321,   325,   331,   335,   336,   338,   340,   344
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      74,     0,    -1,    49,    -1,    60,    73,    -1,    -1,    49,
      -1,    77,    -1,     3,    92,    -1,    61,    77,    62,    -1,
      -1,    77,    78,    73,    -1,    76,    -1,    79,    -1,    86,
      -1,    87,    -1,    88,    -1,    81,    -1,    34,    72,    -1,
      39,    72,    -1,    39,    93,    72,    -1,    72,    -1,    93,
      72,    -1,    92,    63,    93,    72,    -1,    98,    -1,    75,
      -1,    28,    93,    73,    76,    73,    80,    73,    -1,    28,
      93,    73,    76,    73,    80,    73,    29,    76,    73,    -1,
      -1,    80,    30,    93,    76,    -1,    31,    93,    73,    61,
      73,    82,    73,    62,    -1,    -1,    82,    83,    -1,    84,
      77,    -1,    85,    77,    -1,    32,    93,    64,    -1,    33,
      64,    -1,    25,    93,    76,    -1,    26,    89,    27,    93,
      76,    -1,    24,    76,    25,    93,    -1,    43,    -1,    89,
      -1,    90,    65,    89,    -1,    23,    -1,    22,    -1,    90,
      -1,    92,    66,    93,    67,    -1,    91,    90,    -1,    91,
      90,    64,    66,    97,    67,    -1,    91,    90,    64,    97,
      -1,    92,    -1,     4,    -1,     6,    -1,     8,    -1,    20,
      -1,    21,    -1,     7,    -1,     5,    -1,    40,    -1,    48,
      93,    -1,    55,    93,    -1,    93,    48,    -1,    93,    51,
      93,    -1,    93,    50,    93,    -1,    93,    54,    93,    -1,
      93,    55,    93,    -1,    93,    56,    93,    -1,    93,    57,
      93,    -1,    93,    58,    93,    -1,    93,    53,    93,    -1,
      93,    52,    93,    -1,    93,    47,    93,    -1,    93,    46,
      93,    -1,    93,    44,    93,    -1,    93,    45,    93,    -1,
      93,    38,    93,    -1,    68,    93,    69,    -1,    66,    97,
      67,    68,    69,    -1,    94,    -1,   103,    -1,    92,    68,
      95,    69,    -1,    -1,    96,    -1,    93,    -1,    89,    64,
      93,    -1,    96,    70,    89,    64,    93,    -1,    16,    -1,
      14,    -1,    17,    -1,    18,    -1,    19,    -1,    15,    -1,
       9,    -1,    11,    -1,    12,    -1,    13,    -1,    10,    -1,
      35,    90,    99,    -1,    68,   100,    69,    36,    97,    76,
      -1,    68,   100,    69,    76,    -1,    -1,    -1,   102,   101,
      -1,    89,    64,    97,    -1,   102,    70,    89,    64,    97,
      -1,    66,   104,    67,    -1,    -1,   105,    -1,   106,    -1,
     105,    70,   106,    -1,    93,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   143,   143,   144,   147,   148,   151,   154,   159,   162,
     163,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   182,   183,   185,   186,   189,
     191,   192,   194,   195,   197,   199,   201,   203,   205,   208,
     210,   211,   214,   215,   218,   219,   220,   221,   222,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   260,
     262,   263,   265,   266,   267,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   284,   286,   287,   290,
     291,   291,   293,   294,   303,   306,   307,   310,   311,   314
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IMPORT", "INT", "FLOAT", "DOUBLE",
  "BOOL", "STRING", "ARRAYINTT", "ARRAYBOOLT", "ARRAYSTRINGT",
  "ARRAYFLOATT", "ARRAYDOUBLET", "STRINGT", "CHARACTERT", "INTT", "FLOATT",
  "DOUBLET", "BOOLT", "TRUE", "FALSE", "LET", "VAR", "REPEAT", "WHILE",
  "FOR", "IN", "IF", "ELSE", "ELSEIF", "SWITCH", "CASE", "DEFAULT",
  "BREAK", "FUNCTION", "FUNCTIONARROW", "DO", "RANGE", "RETURN", "NIL",
  "SELF", "ERROR", "ID", "EQ", "NE", "LE", "GE", "NOT", "ENDL", "OR",
  "AND", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "UMINUS", "';'",
  "'{'", "'}'", "'='", "':'", "'.'", "'['", "']'", "'('", "')'", "','",
  "$accept", "end_expr", "opt_endl", "root", "stmt_import", "stmt_block",
  "stmt_list", "stmt", "stmt_if", "elseif_list", "stmt_switch",
  "switch_cases", "switch_case", "case_label", "default_label",
  "stmt_while", "stmt_for", "stmt_repeat", "alone_id", "id_chain",
  "varlet", "var", "expr", "func_call", "arg_list", "args", "varubleType",
  "func_decl_named", "func_body", "arg_list_decl", "@1", "args_decl",
  "array_constructor", "array_elem_list", "array_elems", "array_elem", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    60,    62,    43,    45,    42,    47,    37,   307,
      59,   123,   125,    61,    58,    46,    91,    93,    40,    41,
      44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    72,    73,    73,    74,    75,    76,    77,
      77,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    79,    79,    80,    80,    81,
      82,    82,    83,    83,    84,    85,    86,    87,    88,    89,
      90,    90,    91,    91,    92,    92,    92,    92,    92,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    94,
      95,    95,    96,    96,    96,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    98,    99,    99,   100,
     101,   100,   102,   102,   103,   104,   104,   105,   105,   106
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     2,     3,     0,
       3,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       1,     2,     4,     1,     1,     7,    10,     0,     4,     8,
       0,     2,     2,     2,     3,     2,     3,     5,     4,     1,
       1,     3,     1,     1,     1,     4,     2,     6,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     5,     1,     1,     4,
       0,     1,     1,     3,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     6,     4,     0,
       0,     2,     3,     5,     3,     0,     1,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       9,     0,     6,     1,     0,    50,    56,    51,    55,    52,
      53,    54,    43,    42,     0,     0,     0,     0,     0,     0,
       0,     0,    57,    39,     0,     2,     0,     4,     9,   105,
       0,    20,    24,    11,     4,    12,    16,    13,    14,    15,
      40,    44,     0,    49,     0,    77,    23,    78,     7,     0,
      49,     0,     0,     4,     4,    17,     0,    18,     0,    58,
      59,     5,     3,     0,    91,    95,    92,    93,    94,    86,
      90,    85,    87,    88,    89,   109,     0,     0,   106,   107,
       0,    10,     0,    46,     0,     0,    80,     0,     0,     0,
       0,     0,    60,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,    36,     0,     0,     0,    99,    96,
      19,     8,     0,   104,     0,    75,    41,     0,     0,     0,
      40,    82,     0,    81,    74,    72,    73,    71,    70,    62,
      61,    69,    68,    63,    64,    65,    66,    67,    38,     0,
       4,     4,     0,     0,   100,     0,   108,     0,    48,    22,
      45,     0,    79,     0,    37,    27,    30,     0,     0,     0,
     101,    76,     0,    83,     0,     4,     4,   102,     0,    98,
       0,    47,     0,     0,    25,     0,     0,     0,    31,     9,
       9,     0,     0,    84,     0,     0,     0,    35,    29,    32,
      33,    97,   103,    28,     4,    34,    26
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    31,    62,     1,    32,    33,     2,    34,    35,   165,
      36,   166,   178,   179,   180,    37,    38,    39,    40,    41,
      42,    50,    44,    45,   122,   123,    76,    46,   109,   143,
     160,   144,    47,    77,    78,    79
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -102
static const yytype_int16 yypact[] =
{
    -102,    27,   237,  -102,     2,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,   -26,   356,    -4,   356,   356,   -32,
      -4,   326,  -102,  -102,   356,  -102,   356,     6,  -102,   302,
     356,  -102,  -102,  -102,     6,  -102,  -102,  -102,  -102,  -102,
    -102,   -21,    -4,    -9,   478,  -102,  -102,  -102,   -19,    37,
      -8,   362,    38,   499,   499,  -102,   -39,  -102,   478,  -102,
    -102,  -102,  -102,   171,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,   520,     1,     3,    21,  -102,
     398,  -102,    -4,    -1,   356,   356,   356,   356,   356,   356,
     356,   356,  -102,   356,   356,   356,   356,   356,   356,   356,
     356,   356,  -102,   356,  -102,   356,   -26,     5,    -4,  -102,
    -102,  -102,     4,  -102,   356,  -102,  -102,   416,   478,   433,
       7,   520,     0,    25,    -5,    -5,    -5,    -5,    -5,   541,
     562,    -5,    -5,   -16,   -16,    49,    49,    49,   520,   362,
       6,     6,    34,    30,    31,    33,  -102,   102,  -102,  -102,
    -102,   356,  -102,    -4,  -102,  -102,  -102,   102,   -28,    -4,
    -102,  -102,    39,   520,    40,   -18,   -12,  -102,   102,  -102,
      41,  -102,   356,   356,    78,   356,    59,    62,  -102,  -102,
    -102,   -26,   102,   520,   362,   -26,   457,  -102,  -102,   237,
     237,  -102,  -102,  -102,     6,  -102,  -102
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -102,   -10,   -31,  -102,  -102,   -13,   -23,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,    14,    -6,
    -102,    -2,   -11,  -102,  -102,  -102,  -101,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,    11
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      43,    49,    48,    81,    51,    63,    53,    54,   168,    55,
      58,    57,   173,    59,    56,    60,   148,    25,    75,    80,
     175,   176,   106,   107,    12,    13,    82,     3,    27,   108,
      52,    61,    92,    28,   102,    28,    83,    61,   104,    23,
      99,   100,   101,    92,    82,    23,   162,    85,   110,    97,
      98,    99,   100,   101,    84,    61,   167,    85,    85,    86,
      86,    43,   103,   117,    82,   105,   141,   181,   112,   152,
     113,   151,   145,   118,   119,   121,   124,   125,   126,   127,
     128,   192,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   114,   138,   140,   139,   153,   116,    92,   157,   158,
     120,   159,   161,    75,   172,   182,   171,   185,   149,   155,
     156,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,   142,   187,   188,   146,   154,     0,     0,     0,
       0,     0,     0,     0,   174,   177,     0,     0,     0,     0,
     163,     0,     0,     0,     0,   169,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   189,   190,     0,     0,
       0,   183,   184,   196,   186,     0,     0,   164,   191,     0,
       0,   193,   194,   170,     4,     5,     6,     7,     8,     9,
       0,     0,     0,     0,     0,     0,     0,    43,    43,     0,
       0,    10,    11,    12,    13,    14,    15,    16,     0,    17,
       0,     0,    18,     0,     0,    19,    20,     0,     0,     0,
      21,    22,     0,     0,    23,     0,     0,     0,     0,    24,
      25,     0,     0,     0,     0,     0,    26,     0,     0,     0,
       0,    27,    28,   111,     0,     0,     0,    29,     0,    30,
       4,     5,     6,     7,     8,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,    14,    15,    16,     0,    17,     0,     0,    18,     0,
       0,    19,    20,     0,     0,     0,    21,    22,     0,     0,
      23,     0,     0,     0,     0,    24,    25,     0,     0,     0,
       0,     0,    26,     0,     0,     0,     0,    27,    28,     0,
       0,     0,     0,    29,     0,    30,     5,     6,     7,     8,
       9,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    10,    11,    12,    13,     0,     0,     0,     0,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
       0,     0,    22,     0,     0,    23,    10,    11,    12,    13,
      24,     0,     0,     0,     0,     0,     0,    26,     0,     0,
       5,     6,     7,     8,     9,     0,    22,     0,    29,    23,
      30,     0,     0,     0,    24,    25,    10,    11,    12,    13,
       0,    26,     0,     0,     0,     0,    27,     0,     0,     0,
       0,     0,    29,     0,    30,     0,    22,     0,     0,    23,
      87,     0,     0,     0,    24,     0,    88,    89,    90,    91,
      92,    26,    93,    94,    95,    96,    97,    98,    99,   100,
     101,     0,    29,    28,    30,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    87,     0,     0,     0,
       0,     0,    88,    89,    90,    91,    92,     0,    93,    94,
      95,    96,    97,    98,    99,   100,   101,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   115,     0,     0,
       0,    87,     0,     0,     0,     0,     0,    88,    89,    90,
      91,    92,   147,    93,    94,    95,    96,    97,    98,    99,
     100,   101,     0,     0,     0,    87,     0,     0,     0,     0,
     150,    88,    89,    90,    91,    92,     0,    93,    94,    95,
      96,    97,    98,    99,   100,   101,    87,     0,     0,     0,
       0,   195,    88,    89,    90,    91,    92,    25,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    87,    27,     0,
       0,     0,     0,    88,    89,    90,    91,    92,    61,    93,
      94,    95,    96,    97,    98,    99,   100,   101,    87,     0,
       0,     0,     0,     0,    88,    89,    90,    91,    92,     0,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    87,
       0,     0,     0,     0,     0,    88,    89,    90,    91,    92,
       0,     0,    94,    95,    96,    97,    98,    99,   100,   101,
      87,     0,     0,     0,     0,     0,    88,    89,    90,    91,
      92,     0,     0,     0,    95,    96,    97,    98,    99,   100,
     101
};

static const yytype_int16 yycheck[] =
{
       2,    14,     4,    34,    15,    28,    17,    18,    36,    19,
      21,    21,    30,    24,    20,    26,   117,    49,    29,    30,
      32,    33,    53,    54,    22,    23,    65,     0,    60,    68,
      16,    49,    48,    61,    44,    61,    42,    49,    51,    43,
      56,    57,    58,    48,    65,    43,   147,    66,    58,    54,
      55,    56,    57,    58,    63,    49,   157,    66,    66,    68,
      68,    63,    25,    64,    65,    27,    61,   168,    67,    69,
      67,    64,    68,    84,    85,    86,    87,    88,    89,    90,
      91,   182,    93,    94,    95,    96,    97,    98,    99,   100,
     101,    70,   103,   106,   105,    70,    82,    48,    64,    69,
      86,    70,    69,   114,    64,    64,    67,    29,   118,   140,
     141,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,   108,    64,    62,   114,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   165,   166,    -1,    -1,    -1,    -1,
     151,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   179,   180,    -1,    -1,
      -1,   172,   173,   194,   175,    -1,    -1,   153,   181,    -1,
      -1,   184,   185,   159,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    -1,    28,
      -1,    -1,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,
      39,    40,    -1,    -1,    43,    -1,    -1,    -1,    -1,    48,
      49,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,    -1,    66,    -1,    68,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    28,    -1,    -1,    31,    -1,
      -1,    34,    35,    -1,    -1,    -1,    39,    40,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    60,    61,    -1,
      -1,    -1,    -1,    66,    -1,    68,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    43,    20,    21,    22,    23,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,
       4,     5,     6,     7,     8,    -1,    40,    -1,    66,    43,
      68,    -1,    -1,    -1,    48,    49,    20,    21,    22,    23,
      -1,    55,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    66,    -1,    68,    -1,    40,    -1,    -1,    43,
      38,    -1,    -1,    -1,    48,    -1,    44,    45,    46,    47,
      48,    55,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    66,    61,    68,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    38,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    66,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      67,    44,    45,    46,    47,    48,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    38,    -1,    -1,    -1,
      -1,    64,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    38,    60,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    38,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    38,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      -1,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      38,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    52,    53,    54,    55,    56,    57,
      58
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    74,    77,     0,     3,     4,     5,     6,     7,     8,
      20,    21,    22,    23,    24,    25,    26,    28,    31,    34,
      35,    39,    40,    43,    48,    49,    55,    60,    61,    66,
      68,    72,    75,    76,    78,    79,    81,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    98,   103,    92,    76,
      92,    93,    89,    93,    93,    72,    90,    72,    93,    93,
      93,    49,    73,    77,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    93,    97,   104,   105,   106,
      93,    73,    65,    90,    63,    66,    68,    38,    44,    45,
      46,    47,    48,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    72,    25,    76,    27,    73,    73,    68,    99,
      72,    62,    67,    67,    70,    69,    89,    64,    93,    93,
      89,    93,    95,    96,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      76,    61,    89,   100,   102,    68,   106,    66,    97,    72,
      67,    64,    69,    70,    76,    73,    73,    64,    69,    70,
     101,    69,    97,    93,    89,    80,    82,    97,    36,    76,
      89,    67,    64,    30,    73,    32,    33,    73,    83,    84,
      85,    97,    64,    93,    93,    29,    93,    64,    62,    77,
      77,    76,    97,    76,    76,    64,    73
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 143 "../bison/swift.y"
    {;;}
    break;

  case 3:
#line 144 "../bison/swift.y"
    {;;}
    break;

  case 4:
#line 147 "../bison/swift.y"
    {;;}
    break;

  case 5:
#line 148 "../bison/swift.y"
    {;;}
    break;

  case 6:
#line 151 "../bison/swift.y"
    {printf("root\n");root=(yyvsp[(1) - (1)].SL); (yyval.SL)=(yyvsp[(1) - (1)].SL);;}
    break;

  case 7:
#line 154 "../bison/swift.y"
    {printf("import found\n");(yyval.Import) = create_import((yyvsp[(2) - (2)].Expr));;}
    break;

  case 8:
#line 159 "../bison/swift.y"
    {printf("block found\n");(yyval.SL) = (yyvsp[(2) - (3)].SL);;}
    break;

  case 9:
#line 162 "../bison/swift.y"
    { printf("stmt list null found\n");(yyval.SL) = create_stmt_list(NULL);;}
    break;

  case 10:
#line 163 "../bison/swift.y"
    {printf("stmt list not null\n");(yyval.SL) = add_stmt_to_list((yyvsp[(1) - (3)].SL), (yyvsp[(2) - (3)].Stmt));;}
    break;

  case 11:
#line 166 "../bison/swift.y"
    {printf("stmt_block\n");(yyval.Stmt) = create_stmt_block((yyvsp[(1) - (1)].SL));;}
    break;

  case 12:
#line 167 "../bison/swift.y"
    {printf("stmt_if\n");(yyval.Stmt) = create_stmt_if((yyvsp[(1) - (1)].If));;}
    break;

  case 13:
#line 168 "../bison/swift.y"
    {printf("stmt_while\n");(yyval.Stmt) = create_stmt_while((yyvsp[(1) - (1)].While), 0);;}
    break;

  case 14:
#line 169 "../bison/swift.y"
    {printf("stmt_for\n");(yyval.Stmt) = create_stmt_for((yyvsp[(1) - (1)].For));;}
    break;

  case 15:
#line 170 "../bison/swift.y"
    {printf("stmt_repeat\n");(yyval.Stmt) = create_stmt_while((yyvsp[(1) - (1)].While), 1);;}
    break;

  case 16:
#line 171 "../bison/swift.y"
    {printf("stmt_switch\n");(yyval.Stmt) = create_stmt_switch((yyvsp[(1) - (1)].Switch));;}
    break;

  case 17:
#line 172 "../bison/swift.y"
    {printf("stmt_break\n");(yyval.Stmt) = create_stmt_spec(0);;}
    break;

  case 18:
#line 173 "../bison/swift.y"
    {printf("stmt_return\n");(yyval.Stmt) = create_stmt_spec(1);;}
    break;

  case 19:
#line 174 "../bison/swift.y"
    {printf("stmt_return end\n");(yyval.Stmt) = create_stmt_return((yyvsp[(2) - (3)].Expr));;}
    break;

  case 20:
#line 175 "../bison/swift.y"
    {printf("end_expr\n");(yyval.Stmt) = create_stmt_spec(2);;}
    break;

  case 21:
#line 176 "../bison/swift.y"
    {printf("stmt_expr\n");(yyval.Stmt) = create_stmt_expr((yyvsp[(1) - (2)].Expr));;}
    break;

  case 22:
#line 177 "../bison/swift.y"
    {printf("line with eq\n"); (yyval.Stmt) = create_stmt_assign((yyvsp[(1) - (4)].Expr), (yyvsp[(3) - (4)].Expr), 0);;}
    break;

  case 23:
#line 178 "../bison/swift.y"
    {printf("stmt_func decl\n");(yyval.Stmt) = create_stmt_func((yyvsp[(1) - (1)].Func));;}
    break;

  case 24:
#line 179 "../bison/swift.y"
    {printf("stmt_import\n");(yyval.Stmt) = create_stmt_import((yyvsp[(1) - (1)].Import));;}
    break;

  case 25:
#line 182 "../bison/swift.y"
    {printf("stmt_if_1\n");(yyval.If) = create_if((yyvsp[(2) - (7)].Expr), (yyvsp[(4) - (7)].SL), (yyvsp[(6) - (7)].IfL), create_stmt_list(NULL));;}
    break;

  case 26:
#line 183 "../bison/swift.y"
    {printf("stmt_if_2\n");(yyval.If) = create_if((yyvsp[(2) - (10)].Expr), (yyvsp[(4) - (10)].SL), (yyvsp[(6) - (10)].IfL), (yyvsp[(9) - (10)].SL));;}
    break;

  case 27:
#line 185 "../bison/swift.y"
    {printf("empty else if\n");(yyval.IfL) = create_if_list(NULL); ;}
    break;

  case 28:
#line 186 "../bison/swift.y"
    {printf("else_if\n");(yyval.IfL) = add_if_to_list((yyvsp[(1) - (4)].IfL), create_if((yyvsp[(3) - (4)].Expr), (yyvsp[(4) - (4)].SL), create_if_list(NULL), create_stmt_list(NULL)));;}
    break;

  case 29:
#line 189 "../bison/swift.y"
    {printf("stmt_switch\n");(yyval.Switch) = create_switch((yyvsp[(2) - (8)].Expr),(yyvsp[(6) - (8)].CaseL));;}
    break;

  case 30:
#line 191 "../bison/swift.y"
    {printf("empty case\n");(yyval.CaseL) = create_case_list(NULL);;}
    break;

  case 31:
#line 192 "../bison/swift.y"
    {printf("switch cases\n");(yyval.CaseL) = add_case_to_list((yyvsp[(1) - (2)].CaseL),(yyvsp[(2) - (2)].Case));;}
    break;

  case 32:
#line 194 "../bison/swift.y"
    {printf("switch case\n");(yyval.Case) = create_case((yyvsp[(1) - (2)].LabelCase),(yyvsp[(2) - (2)].SL));;}
    break;

  case 33:
#line 195 "../bison/swift.y"
    {printf("switch case 2\n");(yyval.Case) = create_case((yyvsp[(1) - (2)].LabelCase),(yyvsp[(2) - (2)].SL));;}
    break;

  case 34:
#line 197 "../bison/swift.y"
    {printf("case label\n");(yyval.LabelCase) = create_label_case((yyvsp[(2) - (3)].Expr),DIFFERENT);;}
    break;

  case 35:
#line 199 "../bison/swift.y"
    {printf("default label \n");(yyval.LabelCase) = create_label_case(NULL,DEFAULTT);;}
    break;

  case 36:
#line 201 "../bison/swift.y"
    {printf("stmt_while\n");(yyval.While) = create_while((yyvsp[(2) - (3)].Expr), (yyvsp[(3) - (3)].SL),false);;}
    break;

  case 37:
#line 203 "../bison/swift.y"
    {printf("stmt_for\n");(yyval.For) = create_for((yyvsp[(2) - (5)].Expr), (yyvsp[(4) - (5)].Expr), (yyvsp[(5) - (5)].SL), create_expr_int(1));;}
    break;

  case 38:
#line 205 "../bison/swift.y"
    {printf("stmt_repeat\n");(yyval.While) = create_while((yyvsp[(4) - (4)].Expr), (yyvsp[(2) - (4)].SL),true); ;}
    break;

  case 39:
#line 208 "../bison/swift.y"
    {printf("alone_id\n");(yyval.Expr) = create_expr_id(yylval.Id);;}
    break;

  case 40:
#line 210 "../bison/swift.y"
    {printf("id-chain\n");(yyval.Args) = create_expr_list((yyvsp[(1) - (1)].Expr),NULL);;}
    break;

  case 41:
#line 211 "../bison/swift.y"
    {printf("id chain class\n");(yyval.Args) = add_expr_to_list((yyvsp[(1) - (3)].Args), (yyvsp[(3) - (3)].Expr), NULL); ;}
    break;

  case 42:
#line 214 "../bison/swift.y"
    {printf("var \n"); (yyval.Constant) = create_var_constant_type(VART);;}
    break;

  case 43:
#line 215 "../bison/swift.y"
    {printf("let\n"); (yyval.Constant) = create_var_constant_type(LETT);;}
    break;

  case 44:
#line 218 "../bison/swift.y"
    {printf("varuble 1\n"); (yyval.Expr) = create_expr_exprlist((yyvsp[(1) - (1)].Args),NULL,NULL); ;}
    break;

  case 45:
#line 219 "../bison/swift.y"
    { (yyval.Expr) = create_op_expr(EXPR_MAS, (yyvsp[(1) - (4)].Expr), (yyvsp[(3) - (4)].Expr)); ;}
    break;

  case 46:
#line 220 "../bison/swift.y"
    {printf("varuble 2\n");(yyval.Expr) = create_expr_exprlist((yyvsp[(2) - (2)].Args),NULL,(yyvsp[(1) - (2)].Constant)); ;}
    break;

  case 47:
#line 221 "../bison/swift.y"
    {printf("varuble 4\n");(yyval.Expr) = create_expr_exprlist((yyvsp[(2) - (6)].Args),(yyvsp[(5) - (6)].VarType),(yyvsp[(1) - (6)].Constant),true); ;}
    break;

  case 48:
#line 222 "../bison/swift.y"
    {printf("varuble 5\n");(yyval.Expr) = create_expr_exprlist((yyvsp[(2) - (4)].Args),(yyvsp[(4) - (4)].VarType),(yyvsp[(1) - (4)].Constant),false);;}
    break;

  case 49:
#line 227 "../bison/swift.y"
    {printf("expr var\n");(yyval.Expr) = (yyvsp[(1) - (1)].Expr);;}
    break;

  case 50:
#line 228 "../bison/swift.y"
    {printf("expr INT\n"); (yyval.Expr) = create_expr_int(yylval.Int);;}
    break;

  case 51:
#line 229 "../bison/swift.y"
    {printf("expr DOUBLE\n"); (yyval.Expr) = create_expr_double(yylval.Double);;}
    break;

  case 52:
#line 230 "../bison/swift.y"
    {printf("expr STRING\n"); (yyval.Expr) = create_expr_string(yylval.String);;}
    break;

  case 53:
#line 231 "../bison/swift.y"
    {printf("expr TRUE\n"); (yyval.Expr) = create_expr_boolean(1);;}
    break;

  case 54:
#line 232 "../bison/swift.y"
    {printf("expr FALSE\n"); (yyval.Expr) = create_expr_boolean(0); ;}
    break;

  case 55:
#line 233 "../bison/swift.y"
    {printf("expr BOOL\n");;}
    break;

  case 56:
#line 234 "../bison/swift.y"
    {printf("expr FLOAT\n");(yyval.Expr) = create_expr_float(yylval.Double);;}
    break;

  case 57:
#line 235 "../bison/swift.y"
    {printf("expr NIL\n");(yyval.Expr) = create_expr_nil(); ;}
    break;

  case 58:
#line 236 "../bison/swift.y"
    {printf("not expr "); (yyval.Expr) = create_op_expr(EXPR_NOT, (yyvsp[(2) - (2)].Expr), NULL);;}
    break;

  case 59:
#line 237 "../bison/swift.y"
    { (yyval.Expr) = create_op_expr(EXPR_UMIN, (yyvsp[(2) - (2)].Expr), NULL); ;}
    break;

  case 60:
#line 238 "../bison/swift.y"
    {printf("expr not type\n");;}
    break;

  case 61:
#line 239 "../bison/swift.y"
    {printf("expr and expr\n");(yyval.Expr) = create_op_expr(EXPR_AND, (yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].Expr));;}
    break;

  case 62:
#line 240 "../bison/swift.y"
    {printf("expr or expr\n"); (yyval.Expr) = create_op_expr(EXPR_OR, (yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].Expr));;}
    break;

  case 63:
#line 241 "../bison/swift.y"
    {printf("expr + expr\n"); (yyval.Expr) = create_op_expr(EXPR_PLUS, (yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].Expr));;}
    break;

  case 64:
#line 242 "../bison/swift.y"
    {printf("expr - expr\n"); (yyval.Expr) = create_op_expr(EXPR_MINUS, (yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].Expr));;}
    break;

  case 65:
#line 243 "../bison/swift.y"
    {printf("expr * expr\n"); (yyval.Expr) = create_op_expr(EXPR_MUL, (yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].Expr));;}
    break;

  case 66:
#line 244 "../bison/swift.y"
    {printf("expr / expr\n"); (yyval.Expr) = create_op_expr(EXPR_DIV, (yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].Expr));;}
    break;

  case 67:
#line 245 "../bison/swift.y"
    {printf("expr % expr\n"); (yyval.Expr) = create_op_expr(EXPR_MOD, (yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].Expr));;}
    break;

  case 68:
#line 246 "../bison/swift.y"
    {printf("expr > expr\n"); (yyval.Expr) = create_op_expr(EXPR_GT, (yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].Expr));;}
    break;

  case 69:
#line 247 "../bison/swift.y"
    {printf("expr < expr\n"); (yyval.Expr) = create_op_expr(EXPR_LT, (yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].Expr));;}
    break;

  case 70:
#line 248 "../bison/swift.y"
    {printf("expr GE expr\n"); (yyval.Expr) = create_op_expr(EXPR_GE, (yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].Expr));;}
    break;

  case 71:
#line 249 "../bison/swift.y"
    {printf("expr LE expr\n"); (yyval.Expr) = create_op_expr(EXPR_LE, (yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].Expr));;}
    break;

  case 72:
#line 250 "../bison/swift.y"
    {printf("expr EQ expr\n"); (yyval.Expr) = create_op_expr(EXPR_EQ, (yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].Expr));;}
    break;

  case 73:
#line 251 "../bison/swift.y"
    {printf("expr NE expr\n"); (yyval.Expr) = create_op_expr(EXPR_NQ, (yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].Expr));;}
    break;

  case 74:
#line 252 "../bison/swift.y"
    {printf("expr RANGE expr\n"); (yyval.Expr) = create_op_expr(EXPR_RANGE, (yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].Expr));;}
    break;

  case 75:
#line 253 "../bison/swift.y"
    {printf("(expr)\n"); (yyval.Expr) = (yyvsp[(2) - (3)].Expr);;}
    break;

  case 76:
#line 254 "../bison/swift.y"
    {printf("varuble 3\n");(yyval.Expr) = create_expr_table(NULL, (yyvsp[(2) - (5)].VarType));;}
    break;

  case 77:
#line 255 "../bison/swift.y"
    {printf("expr func_call\n"); (yyval.Expr) = (yyvsp[(1) - (1)].Expr);;}
    break;

  case 78:
#line 256 "../bison/swift.y"
    {printf("expr array_constructor\n"); (yyval.Expr) = create_expr_table((yyvsp[(1) - (1)].Table), NULL);;}
    break;

  case 79:
#line 260 "../bison/swift.y"
    {printf("function call\n"); (yyval.Expr) = create_op_expr(EXPR_MET, (yyvsp[(1) - (4)].Expr), create_expr_exprlist((yyvsp[(3) - (4)].Args),NULL,NULL));;}
    break;

  case 80:
#line 262 "../bison/swift.y"
    {printf("arg_list empty\n");(yyval.Args) = create_expr_list(NULL,NULL);;}
    break;

  case 81:
#line 263 "../bison/swift.y"
    {printf("arg_list args \n");(yyval.Args) = (yyvsp[(1) - (1)].Args);;}
    break;

  case 82:
#line 265 "../bison/swift.y"
    { (yyval.Args) = create_expr_list((yyvsp[(1) - (1)].Expr),NULL); ;}
    break;

  case 83:
#line 266 "../bison/swift.y"
    {printf("args id : expr\n");(yyval.Args) = create_expr_list((yyvsp[(3) - (3)].Expr),NULL);;}
    break;

  case 84:
#line 267 "../bison/swift.y"
    {printf("args , id : expr\n");(yyval.Args) = add_expr_to_list((yyvsp[(1) - (5)].Args), (yyvsp[(5) - (5)].Expr),NULL);;}
    break;

  case 85:
#line 270 "../bison/swift.y"
    {printf("int type\n");(yyval.VarType) = create_var_type(INTTy);;}
    break;

  case 86:
#line 271 "../bison/swift.y"
    {printf("string type\n");(yyval.VarType) = create_var_type(STRINGTy);;}
    break;

  case 87:
#line 272 "../bison/swift.y"
    {printf("float type\n");(yyval.VarType) = create_var_type(FLOATTy);;}
    break;

  case 88:
#line 273 "../bison/swift.y"
    {printf("double type\n");(yyval.VarType) = create_var_type(DOUBLETy);;}
    break;

  case 89:
#line 274 "../bison/swift.y"
    {printf("bool type\n");(yyval.VarType) = create_var_type(BOOLTy);;}
    break;

  case 90:
#line 275 "../bison/swift.y"
    {printf("character type\n");(yyval.VarType) = create_var_type(CHARACTERTy);;}
    break;

  case 91:
#line 276 "../bison/swift.y"
    {printf("character type\n");(yyval.VarType) = create_var_type(ARRAYINTTy);;}
    break;

  case 92:
#line 277 "../bison/swift.y"
    {printf("character type\n");(yyval.VarType) = create_var_type(ARRAYSTRINGTy);;}
    break;

  case 93:
#line 278 "../bison/swift.y"
    {printf("character type\n");(yyval.VarType) = create_var_type(ARRAYFLOATTy);;}
    break;

  case 94:
#line 279 "../bison/swift.y"
    {printf("character type\n");(yyval.VarType) = create_var_type(ARRAYDOUBLETy);;}
    break;

  case 95:
#line 280 "../bison/swift.y"
    {printf("character type\n");(yyval.VarType) = create_var_type(ARRAYDOUBLETy);;}
    break;

  case 96:
#line 284 "../bison/swift.y"
    {printf("func decl name\n");(yyval.Func) = set_func_name((yyvsp[(2) - (3)].Args), (yyvsp[(3) - (3)].Func));;}
    break;

  case 97:
#line 286 "../bison/swift.y"
    {printf("function body\n");(yyval.Func) = create_func((yyvsp[(2) - (6)].Args), (yyvsp[(6) - (6)].SL),(yyvsp[(5) - (6)].VarType));;}
    break;

  case 98:
#line 287 "../bison/swift.y"
    {printf("function body\n");(yyval.Func) = create_func((yyvsp[(2) - (4)].Args), (yyvsp[(4) - (4)].SL),create_var_type(VOIDTy));;}
    break;

  case 99:
#line 290 "../bison/swift.y"
    {printf("arg list decl empty\n");(yyval.Args) = create_expr_list(NULL,NULL);;}
    break;

  case 100:
#line 291 "../bison/swift.y"
    {;;}
    break;

  case 101:
#line 291 "../bison/swift.y"
    {printf("arg list decl \n");(yyval.Args) = (yyvsp[(1) - (2)].Args);;}
    break;

  case 102:
#line 293 "../bison/swift.y"
    {printf("args decl 1 \n");(yyval.Args) = create_expr_list((yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].VarType));;}
    break;

  case 103:
#line 294 "../bison/swift.y"
    { printf("args decl 2 \n"); (yyval.Args) = add_expr_to_list((yyvsp[(1) - (5)].Args), (yyvsp[(3) - (5)].Expr),(yyvsp[(5) - (5)].VarType));;}
    break;

  case 104:
#line 303 "../bison/swift.y"
    {printf("array constructor");(yyval.Table) = (yyvsp[(2) - (3)].Table);;}
    break;

  case 105:
#line 306 "../bison/swift.y"
    {printf("array elem list empty \n");(yyval.Table) = create_table(NULL);;}
    break;

  case 106:
#line 307 "../bison/swift.y"
    {printf("array elems list \n"); (yyval.Table) = (yyvsp[(1) - (1)].Table);;}
    break;

  case 107:
#line 310 "../bison/swift.y"
    {printf("array elem 1 \n"); (yyval.Table) = create_table((yyvsp[(1) - (1)].TblElem));;}
    break;

  case 108:
#line 311 "../bison/swift.y"
    {printf("array elem more \n"); (yyval.Table) = add_elem_to_table((yyvsp[(1) - (3)].Table), (yyvsp[(3) - (3)].TblElem));;}
    break;

  case 109:
#line 314 "../bison/swift.y"
    {printf("array elem array elem \n");(yyval.TblElem) = create_tbl_elem(NULL, (yyvsp[(1) - (1)].Expr)); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2301 "swift.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 317 "../bison/swift.y"


