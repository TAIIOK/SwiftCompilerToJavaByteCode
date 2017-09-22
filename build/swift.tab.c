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
     STRINGT = 264,
     CHARACTERT = 265,
     INTT = 266,
     FLOATT = 267,
     DOUBLET = 268,
     BOOLT = 269,
     TRUE = 270,
     FALSE = 271,
     LET = 272,
     VAR = 273,
     REPEAT = 274,
     WHILE = 275,
     FOR = 276,
     IN = 277,
     IF = 278,
     ELSE = 279,
     ELSEIF = 280,
     SWITCH = 281,
     CASE = 282,
     DEFAULT = 283,
     BREAK = 284,
     FUNCTION = 285,
     FUNCTIONARROW = 286,
     DO = 287,
     RANGE = 288,
     RETURN = 289,
     NIL = 290,
     SELF = 291,
     ERROR = 292,
     ID = 293,
     EQ = 294,
     NE = 295,
     LE = 296,
     GE = 297,
     NOT = 298,
     ENDL = 299,
     OR = 300,
     AND = 301,
     UMINUS = 302
   };
#endif
/* Tokens.  */
#define IMPORT 258
#define INT 259
#define FLOAT 260
#define DOUBLE 261
#define BOOL 262
#define STRING 263
#define STRINGT 264
#define CHARACTERT 265
#define INTT 266
#define FLOATT 267
#define DOUBLET 268
#define BOOLT 269
#define TRUE 270
#define FALSE 271
#define LET 272
#define VAR 273
#define REPEAT 274
#define WHILE 275
#define FOR 276
#define IN 277
#define IF 278
#define ELSE 279
#define ELSEIF 280
#define SWITCH 281
#define CASE 282
#define DEFAULT 283
#define BREAK 284
#define FUNCTION 285
#define FUNCTIONARROW 286
#define DO 287
#define RANGE 288
#define RETURN 289
#define NIL 290
#define SELF 291
#define ERROR 292
#define ID 293
#define EQ 294
#define NE 295
#define LE 296
#define GE 297
#define NOT 298
#define ENDL 299
#define OR 300
#define AND 301
#define UMINUS 302




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
#line 236 "swift.tab.c"
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
#line 261 "swift.tab.c"

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
#define YYLAST   584

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNRULES -- Number of states.  */
#define YYNSTATES  192

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    53,     2,     2,
      63,    64,    51,    49,    65,    50,    60,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,    55,
      47,    58,    48,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,     2,    57,     2,     2,     2,     2,
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
      45,    46,    54
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
     288,   290,   294,   301,   306,   307,   308,   311,   315,   321,
     325,   326,   328,   330,   334
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      69,     0,    -1,    44,    -1,    55,    68,    -1,    -1,    44,
      -1,    72,    -1,     3,    87,    -1,    56,    72,    57,    -1,
      -1,    72,    73,    68,    -1,    71,    -1,    74,    -1,    81,
      -1,    82,    -1,    83,    -1,    76,    -1,    29,    67,    -1,
      34,    67,    -1,    34,    88,    67,    -1,    67,    -1,    88,
      67,    -1,    87,    58,    88,    67,    -1,    93,    -1,    70,
      -1,    23,    88,    68,    71,    68,    75,    68,    -1,    23,
      88,    68,    71,    68,    75,    68,    24,    71,    68,    -1,
      -1,    75,    25,    88,    71,    -1,    26,    88,    68,    56,
      68,    77,    68,    57,    -1,    -1,    77,    78,    -1,    79,
      72,    -1,    80,    72,    -1,    27,    88,    59,    -1,    28,
      59,    -1,    20,    88,    71,    -1,    21,    84,    22,    88,
      71,    -1,    19,    71,    20,    88,    -1,    38,    -1,    84,
      -1,    85,    60,    84,    -1,    18,    -1,    17,    -1,    85,
      -1,    87,    61,    88,    62,    -1,    86,    85,    -1,    86,
      85,    59,    61,    92,    62,    -1,    86,    85,    59,    92,
      -1,    87,    -1,     4,    -1,     6,    -1,     8,    -1,    15,
      -1,    16,    -1,     7,    -1,     5,    -1,    35,    -1,    43,
      88,    -1,    50,    88,    -1,    88,    43,    -1,    88,    46,
      88,    -1,    88,    45,    88,    -1,    88,    49,    88,    -1,
      88,    50,    88,    -1,    88,    51,    88,    -1,    88,    52,
      88,    -1,    88,    53,    88,    -1,    88,    48,    88,    -1,
      88,    47,    88,    -1,    88,    42,    88,    -1,    88,    41,
      88,    -1,    88,    39,    88,    -1,    88,    40,    88,    -1,
      88,    33,    88,    -1,    63,    88,    64,    -1,    61,    92,
      62,    63,    64,    -1,    89,    -1,    98,    -1,    87,    63,
      90,    64,    -1,    -1,    91,    -1,    88,    -1,    84,    59,
      88,    -1,    91,    65,    84,    59,    88,    -1,    11,    -1,
       9,    -1,    12,    -1,    13,    -1,    14,    -1,    10,    -1,
      30,    85,    94,    -1,    63,    95,    64,    31,    92,    71,
      -1,    63,    95,    64,    71,    -1,    -1,    -1,    97,    96,
      -1,    84,    59,    92,    -1,    97,    65,    84,    59,    92,
      -1,    61,    99,    62,    -1,    -1,   100,    -1,   101,    -1,
     100,    65,   101,    -1,    88,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   135,   135,   136,   139,   140,   143,   146,   151,   154,
     155,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   174,   175,   177,   178,   181,
     183,   184,   186,   187,   189,   191,   193,   195,   197,   200,
     202,   203,   206,   207,   210,   211,   212,   213,   214,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   252,
     254,   255,   257,   258,   259,   262,   263,   264,   265,   266,
     267,   271,   273,   274,   277,   278,   278,   280,   281,   290,
     293,   294,   297,   298,   301
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IMPORT", "INT", "FLOAT", "DOUBLE",
  "BOOL", "STRING", "STRINGT", "CHARACTERT", "INTT", "FLOATT", "DOUBLET",
  "BOOLT", "TRUE", "FALSE", "LET", "VAR", "REPEAT", "WHILE", "FOR", "IN",
  "IF", "ELSE", "ELSEIF", "SWITCH", "CASE", "DEFAULT", "BREAK", "FUNCTION",
  "FUNCTIONARROW", "DO", "RANGE", "RETURN", "NIL", "SELF", "ERROR", "ID",
  "EQ", "NE", "LE", "GE", "NOT", "ENDL", "OR", "AND", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "UMINUS", "';'", "'{'", "'}'", "'='", "':'",
  "'.'", "'['", "']'", "'('", "')'", "','", "$accept", "end_expr",
  "opt_endl", "root", "stmt_import", "stmt_block", "stmt_list", "stmt",
  "stmt_if", "elseif_list", "stmt_switch", "switch_cases", "switch_case",
  "case_label", "default_label", "stmt_while", "stmt_for", "stmt_repeat",
  "alone_id", "id_chain", "varlet", "var", "expr", "func_call", "arg_list",
  "args", "varubleType", "func_decl_named", "func_body", "arg_list_decl",
  "@1", "args_decl", "array_constructor", "array_elem_list", "array_elems",
  "array_elem", 0
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
     295,   296,   297,   298,   299,   300,   301,    60,    62,    43,
      45,    42,    47,    37,   302,    59,   123,   125,    61,    58,
      46,    91,    93,    40,    41,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    67,    68,    68,    69,    70,    71,    72,
      72,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    74,    74,    75,    75,    76,
      77,    77,    78,    78,    79,    80,    81,    82,    83,    84,
      85,    85,    86,    86,    87,    87,    87,    87,    87,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    89,
      90,    90,    91,    91,    91,    92,    92,    92,    92,    92,
      92,    93,    94,    94,    95,    96,    95,    97,    97,    98,
      99,    99,   100,   100,   101
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
       1,     3,     6,     4,     0,     0,     2,     3,     5,     3,
       0,     1,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       9,     0,     6,     1,     0,    50,    56,    51,    55,    52,
      53,    54,    43,    42,     0,     0,     0,     0,     0,     0,
       0,     0,    57,    39,     0,     2,     0,     4,     9,   100,
       0,    20,    24,    11,     4,    12,    16,    13,    14,    15,
      40,    44,     0,    49,     0,    77,    23,    78,     7,     0,
      49,     0,     0,     4,     4,    17,     0,    18,     0,    58,
      59,     5,     3,     0,    86,    90,    85,    87,    88,    89,
     104,     0,     0,   101,   102,     0,    10,     0,    46,     0,
       0,    80,     0,     0,     0,     0,     0,    60,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,     0,    36,
       0,     0,     0,    94,    91,    19,     8,     0,    99,     0,
      75,    41,     0,     0,     0,    40,    82,     0,    81,    74,
      72,    73,    71,    70,    62,    61,    69,    68,    63,    64,
      65,    66,    67,    38,     0,     4,     4,     0,     0,    95,
       0,   103,     0,    48,    22,    45,     0,    79,     0,    37,
      27,    30,     0,     0,     0,    96,    76,     0,    83,     0,
       4,     4,    97,     0,    93,     0,    47,     0,     0,    25,
       0,     0,     0,    31,     9,     9,     0,     0,    84,     0,
       0,     0,    35,    29,    32,    33,    92,    98,    28,     4,
      34,    26
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    31,    62,     1,    32,    33,     2,    34,    35,   160,
      36,   161,   173,   174,   175,    37,    38,    39,    40,    41,
      42,    50,    44,    45,   117,   118,    71,    46,   104,   138,
     155,   139,    47,    72,    73,    74
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -88
static const yytype_int16 yypact[] =
{
     -88,     8,   230,   -88,     9,   -88,   -88,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,   -36,   330,     1,   330,   330,   -27,
       1,   306,   -88,   -88,   330,   -88,   330,     2,   -88,   290,
     330,   -88,   -88,   -88,     2,   -88,   -88,   -88,   -88,   -88,
     -88,    -7,     1,    36,   447,   -88,   -88,   -88,     6,    46,
     -32,   426,    64,   468,   468,   -88,   -39,   -88,   447,   -88,
     -88,   -88,   -88,   169,   -88,   -88,   -88,   -88,   -88,   -88,
     489,    34,    38,    28,   -88,   355,   -88,     1,    -8,   330,
     330,   330,   330,   330,   330,   330,   330,   -88,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   -88,   330,   -88,
     330,   -36,    45,     1,   -88,   -88,   -88,    39,   -88,   330,
     -88,   -88,    31,   447,   381,    53,   489,    49,    50,     7,
       7,     7,     7,     7,   510,   531,     7,     7,    11,    11,
      71,    71,    71,   489,   426,     2,     2,    57,    54,    55,
      58,   -88,    97,   -88,   -88,   -88,   330,   -88,     1,   -88,
     -88,   -88,    97,   -19,     1,   -88,   -88,    61,   489,    60,
      -9,     5,   -88,    97,   -88,    65,   -88,   330,   330,   101,
     330,    67,    70,   -88,   -88,   -88,   -36,    97,   489,   426,
     -36,   405,   -88,   -88,   230,   230,   -88,   -88,   -88,     2,
     -88,   -88
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -88,   -10,   -31,   -88,   -88,   -13,   -23,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,    14,    -6,
     -88,    -2,   -11,   -88,   -88,   -88,   -87,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,    19
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      43,    49,    48,    76,    51,    63,    53,    54,     3,    55,
      58,    57,   163,    59,    56,    60,   168,    25,    70,    75,
      28,    77,   101,   102,   103,   143,    12,    13,    27,    80,
      52,    81,   170,   171,    97,    61,    78,    28,    99,    23,
      64,    65,    66,    67,    68,    69,    61,    23,   105,    61,
      87,   112,    77,    77,    87,   157,    92,    93,    94,    95,
      96,    43,    94,    95,    96,   162,    98,    80,   113,   114,
     116,   119,   120,   121,   122,   123,   176,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   100,   133,   135,   134,
     187,   111,   142,   109,    79,   115,   107,    80,    70,    81,
     108,   136,   140,   144,   150,   151,    64,    65,    66,    67,
      68,    69,   146,   147,    87,   148,   152,   137,   153,   167,
     154,   149,   156,   166,   177,   180,   182,   183,   141,   169,
     172,     0,     0,     0,     0,   158,     0,     0,     0,     0,
     164,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   184,   185,     0,     0,     0,   178,   179,   191,   181,
       0,     0,   159,   186,     0,     0,   188,   189,   165,     0,
       0,     0,     4,     5,     6,     7,     8,     9,     0,     0,
       0,     0,    43,    43,    10,    11,    12,    13,    14,    15,
      16,     0,    17,     0,     0,    18,     0,     0,    19,    20,
       0,     0,     0,    21,    22,     0,     0,    23,     0,     0,
       0,     0,    24,    25,     0,     0,     0,     0,     0,    26,
       0,     0,     0,     0,    27,    28,   106,     0,     0,     0,
      29,     0,    30,     4,     5,     6,     7,     8,     9,     0,
       0,     0,     0,     0,     0,    10,    11,    12,    13,    14,
      15,    16,     0,    17,     0,     0,    18,     0,     0,    19,
      20,     0,     0,     0,    21,    22,     0,     0,    23,     0,
       0,     0,     0,    24,    25,     0,     0,     0,     0,     0,
      26,     0,     0,     0,     0,    27,    28,     0,     0,     0,
       0,    29,     0,    30,     5,     6,     7,     8,     9,    64,
      65,    66,    67,    68,    69,    10,    11,    12,    13,     0,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
       0,    10,    11,    12,    13,    22,     0,     0,    23,     0,
       0,     0,     0,    24,     5,     6,     7,     8,     9,     0,
      26,    22,     0,     0,    23,    10,    11,    12,    13,    24,
      25,    29,     0,    30,     0,     0,    26,     0,     0,     0,
       0,    27,     0,     0,     0,    22,     0,    29,    23,    30,
       0,     0,     0,    24,     0,     0,     0,     0,     0,     0,
      26,     0,     0,     0,     0,     0,     0,     0,    82,     0,
       0,    29,     0,    30,    83,    84,    85,    86,    87,     0,
      88,    89,    90,    91,    92,    93,    94,    95,    96,     0,
       0,     0,     0,     0,    82,     0,     0,     0,     0,   110,
      83,    84,    85,    86,    87,     0,    88,    89,    90,    91,
      92,    93,    94,    95,    96,     0,     0,     0,    82,     0,
       0,     0,     0,   145,    83,    84,    85,    86,    87,     0,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    82,
       0,     0,     0,     0,   190,    83,    84,    85,    86,    87,
       0,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      82,     0,    28,     0,     0,     0,    83,    84,    85,    86,
      87,    25,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    82,    27,     0,     0,     0,     0,    83,    84,    85,
      86,    87,    61,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    82,     0,     0,     0,     0,     0,    83,    84,
      85,    86,    87,     0,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    82,     0,     0,     0,     0,     0,    83,
      84,    85,    86,    87,     0,     0,    89,    90,    91,    92,
      93,    94,    95,    96,    82,     0,     0,     0,     0,     0,
      83,    84,    85,    86,    87,     0,     0,     0,    90,    91,
      92,    93,    94,    95,    96
};

static const yytype_int16 yycheck[] =
{
       2,    14,     4,    34,    15,    28,    17,    18,     0,    19,
      21,    21,    31,    24,    20,    26,    25,    44,    29,    30,
      56,    60,    53,    54,    63,   112,    17,    18,    55,    61,
      16,    63,    27,    28,    44,    44,    42,    56,    51,    38,
       9,    10,    11,    12,    13,    14,    44,    38,    58,    44,
      43,    59,    60,    60,    43,   142,    49,    50,    51,    52,
      53,    63,    51,    52,    53,   152,    20,    61,    79,    80,
      81,    82,    83,    84,    85,    86,   163,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    22,    98,   101,   100,
     177,    77,    61,    65,    58,    81,    62,    61,   109,    63,
      62,    56,    63,   113,   135,   136,     9,    10,    11,    12,
      13,    14,    59,    64,    43,    65,    59,   103,    64,    59,
      65,   134,    64,    62,    59,    24,    59,    57,   109,   160,
     161,    -1,    -1,    -1,    -1,   146,    -1,    -1,    -1,    -1,
     153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   174,   175,    -1,    -1,    -1,   167,   168,   189,   170,
      -1,    -1,   148,   176,    -1,    -1,   179,   180,   154,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,   184,   185,    15,    16,    17,    18,    19,    20,
      21,    -1,    23,    -1,    -1,    26,    -1,    -1,    29,    30,
      -1,    -1,    -1,    34,    35,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    -1,    -1,    55,    56,    57,    -1,    -1,    -1,
      61,    -1,    63,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    -1,    23,    -1,    -1,    26,    -1,    -1,    29,
      30,    -1,    -1,    -1,    34,    35,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    -1,    -1,    -1,    55,    56,    -1,    -1,    -1,
      -1,    61,    -1,    63,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    18,    35,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    43,     4,     5,     6,     7,     8,    -1,
      50,    35,    -1,    -1,    38,    15,    16,    17,    18,    43,
      44,    61,    -1,    63,    -1,    -1,    50,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    35,    -1,    61,    38,    63,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,
      -1,    61,    -1,    63,    39,    40,    41,    42,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    64,
      39,    40,    41,    42,    43,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    62,    39,    40,    41,    42,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    33,
      -1,    -1,    -1,    -1,    59,    39,    40,    41,    42,    43,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      33,    -1,    56,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    33,    55,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    33,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    33,    -1,    -1,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    33,    -1,    -1,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    69,    72,     0,     3,     4,     5,     6,     7,     8,
      15,    16,    17,    18,    19,    20,    21,    23,    26,    29,
      30,    34,    35,    38,    43,    44,    50,    55,    56,    61,
      63,    67,    70,    71,    73,    74,    76,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    93,    98,    87,    71,
      87,    88,    84,    88,    88,    67,    85,    67,    88,    88,
      88,    44,    68,    72,     9,    10,    11,    12,    13,    14,
      88,    92,    99,   100,   101,    88,    68,    60,    85,    58,
      61,    63,    33,    39,    40,    41,    42,    43,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    67,    20,    71,
      22,    68,    68,    63,    94,    67,    57,    62,    62,    65,
      64,    84,    59,    88,    88,    84,    88,    90,    91,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    71,    56,    84,    95,    97,
      63,   101,    61,    92,    67,    62,    59,    64,    65,    71,
      68,    68,    59,    64,    65,    96,    64,    92,    88,    84,
      75,    77,    92,    31,    71,    84,    62,    59,    25,    68,
      27,    28,    68,    78,    79,    80,    92,    59,    88,    88,
      24,    88,    59,    57,    72,    72,    71,    92,    71,    71,
      59,    68
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
#line 135 "../bison/swift.y"
    {;;}
    break;

  case 3:
#line 136 "../bison/swift.y"
    {;;}
    break;

  case 4:
#line 139 "../bison/swift.y"
    {;;}
    break;

  case 5:
#line 140 "../bison/swift.y"
    {;;}
    break;

  case 6:
#line 143 "../bison/swift.y"
    {printf("root\n");root=(yyvsp[(1) - (1)].SL); (yyval.SL)=(yyvsp[(1) - (1)].SL);;}
    break;

  case 7:
#line 146 "../bison/swift.y"
    {printf("import found\n");(yyval.Import) = create_import((yyvsp[(2) - (2)].Expr));;}
    break;

  case 8:
#line 151 "../bison/swift.y"
    {printf("block found\n");(yyval.SL) = (yyvsp[(2) - (3)].SL);;}
    break;

  case 9:
#line 154 "../bison/swift.y"
    { printf("stmt list null found\n");(yyval.SL) = create_stmt_list(NULL);;}
    break;

  case 10:
#line 155 "../bison/swift.y"
    {printf("stmt list not null\n");(yyval.SL) = add_stmt_to_list((yyvsp[(1) - (3)].SL), (yyvsp[(2) - (3)].Stmt));;}
    break;

  case 11:
#line 158 "../bison/swift.y"
    {printf("stmt_block\n");(yyval.Stmt) = create_stmt_block((yyvsp[(1) - (1)].SL));;}
    break;

  case 12:
#line 159 "../bison/swift.y"
    {printf("stmt_if\n");(yyval.Stmt) = create_stmt_if((yyvsp[(1) - (1)].If));;}
    break;

  case 13:
#line 160 "../bison/swift.y"
    {printf("stmt_while\n");(yyval.Stmt) = create_stmt_while((yyvsp[(1) - (1)].While), 0);;}
    break;

  case 14:
#line 161 "../bison/swift.y"
    {printf("stmt_for\n");(yyval.Stmt) = create_stmt_for((yyvsp[(1) - (1)].For));;}
    break;

  case 15:
#line 162 "../bison/swift.y"
    {printf("stmt_repeat\n");(yyval.Stmt) = create_stmt_while((yyvsp[(1) - (1)].While), 1);;}
    break;

  case 16:
#line 163 "../bison/swift.y"
    {printf("stmt_switch\n");(yyval.Stmt) = create_stmt_switch((yyvsp[(1) - (1)].Switch));;}
    break;

  case 17:
#line 164 "../bison/swift.y"
    {printf("stmt_break\n");(yyval.Stmt) = create_stmt_spec(0);;}
    break;

  case 18:
#line 165 "../bison/swift.y"
    {printf("stmt_return\n");(yyval.Stmt) = create_stmt_spec(1);;}
    break;

  case 19:
#line 166 "../bison/swift.y"
    {printf("stmt_return end\n");(yyval.Stmt) = create_stmt_return((yyvsp[(2) - (3)].Expr));;}
    break;

  case 20:
#line 167 "../bison/swift.y"
    {printf("end_expr\n");(yyval.Stmt) = create_stmt_spec(2);;}
    break;

  case 21:
#line 168 "../bison/swift.y"
    {printf("stmt_expr\n");(yyval.Stmt) = create_stmt_expr((yyvsp[(1) - (2)].Expr));;}
    break;

  case 22:
#line 169 "../bison/swift.y"
    {printf("line with eq\n"); (yyval.Stmt) = create_stmt_assign((yyvsp[(1) - (4)].Expr), (yyvsp[(3) - (4)].Expr), 0);;}
    break;

  case 23:
#line 170 "../bison/swift.y"
    {printf("stmt_func decl\n");(yyval.Stmt) = create_stmt_func((yyvsp[(1) - (1)].Func));;}
    break;

  case 24:
#line 171 "../bison/swift.y"
    {printf("stmt_import\n");(yyval.Stmt) = create_stmt_import((yyvsp[(1) - (1)].Import));;}
    break;

  case 25:
#line 174 "../bison/swift.y"
    {printf("stmt_if_1\n");(yyval.If) = create_if((yyvsp[(2) - (7)].Expr), (yyvsp[(4) - (7)].SL), (yyvsp[(6) - (7)].IfL), create_stmt_list(NULL));;}
    break;

  case 26:
#line 175 "../bison/swift.y"
    {printf("stmt_if_2\n");(yyval.If) = create_if((yyvsp[(2) - (10)].Expr), (yyvsp[(4) - (10)].SL), (yyvsp[(6) - (10)].IfL), (yyvsp[(9) - (10)].SL));;}
    break;

  case 27:
#line 177 "../bison/swift.y"
    {printf("empty else if\n");(yyval.IfL) = create_if_list(NULL); ;}
    break;

  case 28:
#line 178 "../bison/swift.y"
    {printf("else_if\n");(yyval.IfL) = add_if_to_list((yyvsp[(1) - (4)].IfL), create_if((yyvsp[(3) - (4)].Expr), (yyvsp[(4) - (4)].SL), create_if_list(NULL), create_stmt_list(NULL)));;}
    break;

  case 29:
#line 181 "../bison/swift.y"
    {printf("stmt_switch\n");(yyval.Switch) = create_switch((yyvsp[(2) - (8)].Expr),(yyvsp[(6) - (8)].CaseL));;}
    break;

  case 30:
#line 183 "../bison/swift.y"
    {printf("empty case\n");(yyval.CaseL) = create_case_list(NULL);;}
    break;

  case 31:
#line 184 "../bison/swift.y"
    {printf("switch cases\n");(yyval.CaseL) = add_case_to_list((yyvsp[(1) - (2)].CaseL),(yyvsp[(2) - (2)].Case));;}
    break;

  case 32:
#line 186 "../bison/swift.y"
    {printf("switch case\n");(yyval.Case) = create_case((yyvsp[(1) - (2)].LabelCase),(yyvsp[(2) - (2)].SL));;}
    break;

  case 33:
#line 187 "../bison/swift.y"
    {printf("switch case 2\n");(yyval.Case) = create_case((yyvsp[(1) - (2)].LabelCase),(yyvsp[(2) - (2)].SL));;}
    break;

  case 34:
#line 189 "../bison/swift.y"
    {printf("case label\n");(yyval.LabelCase) = create_label_case((yyvsp[(2) - (3)].Expr),DIFFERENT);;}
    break;

  case 35:
#line 191 "../bison/swift.y"
    {printf("default label \n");(yyval.LabelCase) = create_label_case(NULL,DEFAULTT);;}
    break;

  case 36:
#line 193 "../bison/swift.y"
    {printf("stmt_while\n");(yyval.While) = create_while((yyvsp[(2) - (3)].Expr), (yyvsp[(3) - (3)].SL),false);;}
    break;

  case 37:
#line 195 "../bison/swift.y"
    {printf("stmt_for\n");(yyval.For) = create_for((yyvsp[(2) - (5)].Expr), (yyvsp[(4) - (5)].Expr), (yyvsp[(5) - (5)].SL), create_expr_int(1));;}
    break;

  case 38:
#line 197 "../bison/swift.y"
    {printf("stmt_repeat\n");(yyval.While) = create_while((yyvsp[(4) - (4)].Expr), (yyvsp[(2) - (4)].SL),true); ;}
    break;

  case 39:
#line 200 "../bison/swift.y"
    {printf("alone_id\n");(yyval.Expr) = create_expr_id(yylval.Id);;}
    break;

  case 40:
#line 202 "../bison/swift.y"
    {printf("id-chain\n");(yyval.Args) = create_expr_list((yyvsp[(1) - (1)].Expr),NULL);;}
    break;

  case 41:
#line 203 "../bison/swift.y"
    {printf("id chain class\n");(yyval.Args) = add_expr_to_list((yyvsp[(1) - (3)].Args), (yyvsp[(3) - (3)].Expr), NULL); ;}
    break;

  case 42:
#line 206 "../bison/swift.y"
    {printf("var \n"); (yyval.Constant) = create_var_constant_type(VART);;}
    break;

  case 43:
#line 207 "../bison/swift.y"
    {printf("let\n"); (yyval.Constant) = create_var_constant_type(LETT);;}
    break;

  case 44:
#line 210 "../bison/swift.y"
    {printf("varuble 1\n"); (yyval.Expr) = create_expr_exprlist((yyvsp[(1) - (1)].Args),NULL,NULL); ;}
    break;

  case 45:
#line 211 "../bison/swift.y"
    { (yyval.Expr) = create_op_expr(EXPR_MAS, (yyvsp[(1) - (4)].Expr), (yyvsp[(3) - (4)].Expr)); ;}
    break;

  case 46:
#line 212 "../bison/swift.y"
    {printf("varuble 2\n");(yyval.Expr) = create_expr_exprlist((yyvsp[(2) - (2)].Args),NULL,(yyvsp[(1) - (2)].Constant)); ;}
    break;

  case 47:
#line 213 "../bison/swift.y"
    {printf("varuble 4\n");(yyval.Expr) = create_expr_exprlist((yyvsp[(2) - (6)].Args),(yyvsp[(5) - (6)].VarType),(yyvsp[(1) - (6)].Constant),true); ;}
    break;

  case 48:
#line 214 "../bison/swift.y"
    {printf("varuble 5\n");(yyval.Expr) = create_expr_exprlist((yyvsp[(2) - (4)].Args),(yyvsp[(4) - (4)].VarType),(yyvsp[(1) - (4)].Constant),false);;}
    break;

  case 49:
#line 219 "../bison/swift.y"
    {printf("expr var\n");(yyval.Expr) = (yyvsp[(1) - (1)].Expr);;}
    break;

  case 50:
#line 220 "../bison/swift.y"
    {printf("expr INT\n"); (yyval.Expr) = create_expr_int(yylval.Int);;}
    break;

  case 51:
#line 221 "../bison/swift.y"
    {printf("expr DOUBLE\n"); (yyval.Expr) = create_expr_double(yylval.Double);;}
    break;

  case 52:
#line 222 "../bison/swift.y"
    {printf("expr STRING\n"); (yyval.Expr) = create_expr_string(yylval.String);;}
    break;

  case 53:
#line 223 "../bison/swift.y"
    {printf("expr TRUE\n"); (yyval.Expr) = create_expr_boolean(1);;}
    break;

  case 54:
#line 224 "../bison/swift.y"
    {printf("expr FALSE\n"); (yyval.Expr) = create_expr_boolean(0); ;}
    break;

  case 55:
#line 225 "../bison/swift.y"
    {printf("expr BOOL\n");;}
    break;

  case 56:
#line 226 "../bison/swift.y"
    {printf("expr FLOAT\n");(yyval.Expr) = create_expr_float(yylval.Double);;}
    break;

  case 57:
#line 227 "../bison/swift.y"
    {printf("expr NIL\n");(yyval.Expr) = create_expr_nil(); ;}
    break;

  case 58:
#line 228 "../bison/swift.y"
    {printf("not expr "); (yyval.Expr) = create_op_expr(EXPR_NOT, (yyvsp[(2) - (2)].Expr), NULL);;}
    break;

  case 59:
#line 229 "../bison/swift.y"
    { (yyval.Expr) = create_op_expr(EXPR_UMIN, (yyvsp[(2) - (2)].Expr), NULL); ;}
    break;

  case 60:
#line 230 "../bison/swift.y"
    {printf("expr not type\n");;}
    break;

  case 61:
#line 231 "../bison/swift.y"
    {printf("expr and expr\n");(yyval.Expr) = create_op_expr(EXPR_AND, (yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].Expr));;}
    break;

  case 62:
#line 232 "../bison/swift.y"
    {printf("expr or expr\n"); (yyval.Expr) = create_op_expr(EXPR_OR, (yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].Expr));;}
    break;

  case 63:
#line 233 "../bison/swift.y"
    {printf("expr + expr\n"); (yyval.Expr) = create_op_expr(EXPR_PLUS, (yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].Expr));;}
    break;

  case 64:
#line 234 "../bison/swift.y"
    {printf("expr - expr\n"); (yyval.Expr) = create_op_expr(EXPR_MINUS, (yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].Expr));;}
    break;

  case 65:
#line 235 "../bison/swift.y"
    {printf("expr * expr\n"); (yyval.Expr) = create_op_expr(EXPR_MUL, (yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].Expr));;}
    break;

  case 66:
#line 236 "../bison/swift.y"
    {printf("expr / expr\n"); (yyval.Expr) = create_op_expr(EXPR_DIV, (yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].Expr));;}
    break;

  case 67:
#line 237 "../bison/swift.y"
    {printf("expr % expr\n"); (yyval.Expr) = create_op_expr(EXPR_MOD, (yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].Expr));;}
    break;

  case 68:
#line 238 "../bison/swift.y"
    {printf("expr > expr\n"); (yyval.Expr) = create_op_expr(EXPR_GT, (yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].Expr));;}
    break;

  case 69:
#line 239 "../bison/swift.y"
    {printf("expr < expr\n"); (yyval.Expr) = create_op_expr(EXPR_LT, (yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].Expr));;}
    break;

  case 70:
#line 240 "../bison/swift.y"
    {printf("expr GE expr\n"); (yyval.Expr) = create_op_expr(EXPR_GE, (yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].Expr));;}
    break;

  case 71:
#line 241 "../bison/swift.y"
    {printf("expr LE expr\n"); (yyval.Expr) = create_op_expr(EXPR_LE, (yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].Expr));;}
    break;

  case 72:
#line 242 "../bison/swift.y"
    {printf("expr EQ expr\n"); (yyval.Expr) = create_op_expr(EXPR_EQ, (yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].Expr));;}
    break;

  case 73:
#line 243 "../bison/swift.y"
    {printf("expr NE expr\n"); (yyval.Expr) = create_op_expr(EXPR_NQ, (yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].Expr));;}
    break;

  case 74:
#line 244 "../bison/swift.y"
    {printf("expr RANGE expr\n"); (yyval.Expr) = create_op_expr(EXPR_RANGE, (yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].Expr));;}
    break;

  case 75:
#line 245 "../bison/swift.y"
    {printf("(expr)\n"); (yyval.Expr) = (yyvsp[(2) - (3)].Expr);;}
    break;

  case 76:
#line 246 "../bison/swift.y"
    {printf("varuble 3\n");(yyval.Expr) = create_expr_table(NULL, (yyvsp[(2) - (5)].VarType));;}
    break;

  case 77:
#line 247 "../bison/swift.y"
    {printf("expr func_call\n"); (yyval.Expr) = (yyvsp[(1) - (1)].Expr);;}
    break;

  case 78:
#line 248 "../bison/swift.y"
    {printf("expr array_constructor\n"); (yyval.Expr) = create_expr_table((yyvsp[(1) - (1)].Table), NULL);;}
    break;

  case 79:
#line 252 "../bison/swift.y"
    {printf("function call\n"); (yyval.Expr) = create_op_expr(EXPR_MET, (yyvsp[(1) - (4)].Expr), create_expr_exprlist((yyvsp[(3) - (4)].Args),NULL,NULL));;}
    break;

  case 80:
#line 254 "../bison/swift.y"
    {printf("arg_list empty\n");(yyval.Args) = create_expr_list(NULL,NULL);;}
    break;

  case 81:
#line 255 "../bison/swift.y"
    {printf("arg_list args \n");(yyval.Args) = (yyvsp[(1) - (1)].Args);;}
    break;

  case 82:
#line 257 "../bison/swift.y"
    { (yyval.Args) = create_expr_list((yyvsp[(1) - (1)].Expr),NULL); ;}
    break;

  case 83:
#line 258 "../bison/swift.y"
    {printf("args id : expr\n");(yyval.Args) = create_expr_list((yyvsp[(3) - (3)].Expr),NULL);;}
    break;

  case 84:
#line 259 "../bison/swift.y"
    {printf("args , id : expr\n");(yyval.Args) = add_expr_to_list((yyvsp[(1) - (5)].Args), (yyvsp[(5) - (5)].Expr),NULL);;}
    break;

  case 85:
#line 262 "../bison/swift.y"
    {printf("int type\n");(yyval.VarType) = create_var_type(INTTy);;}
    break;

  case 86:
#line 263 "../bison/swift.y"
    {printf("string type\n");(yyval.VarType) = create_var_type(STRINGTy);;}
    break;

  case 87:
#line 264 "../bison/swift.y"
    {printf("float type\n");(yyval.VarType) = create_var_type(FLOATTy);;}
    break;

  case 88:
#line 265 "../bison/swift.y"
    {printf("double type\n");(yyval.VarType) = create_var_type(DOUBLETy);;}
    break;

  case 89:
#line 266 "../bison/swift.y"
    {printf("bool type\n");(yyval.VarType) = create_var_type(BOOLTy);;}
    break;

  case 90:
#line 267 "../bison/swift.y"
    {printf("character type\n");(yyval.VarType) = create_var_type(CHARACTERTy);;}
    break;

  case 91:
#line 271 "../bison/swift.y"
    {printf("func decl name\n");(yyval.Func) = set_func_name((yyvsp[(2) - (3)].Args), (yyvsp[(3) - (3)].Func));;}
    break;

  case 92:
#line 273 "../bison/swift.y"
    {printf("function body\n");(yyval.Func) = create_func((yyvsp[(2) - (6)].Args), (yyvsp[(6) - (6)].SL),(yyvsp[(5) - (6)].VarType));;}
    break;

  case 93:
#line 274 "../bison/swift.y"
    {printf("function body\n");(yyval.Func) = create_func((yyvsp[(2) - (4)].Args), (yyvsp[(4) - (4)].SL),create_var_type(VOIDTy));;}
    break;

  case 94:
#line 277 "../bison/swift.y"
    {printf("arg list decl empty\n");(yyval.Args) = create_expr_list(NULL,NULL);;}
    break;

  case 95:
#line 278 "../bison/swift.y"
    {;;}
    break;

  case 96:
#line 278 "../bison/swift.y"
    {printf("arg list decl \n");(yyval.Args) = (yyvsp[(1) - (2)].Args);;}
    break;

  case 97:
#line 280 "../bison/swift.y"
    {printf("args decl 1 \n");(yyval.Args) = create_expr_list((yyvsp[(1) - (3)].Expr), (yyvsp[(3) - (3)].VarType));;}
    break;

  case 98:
#line 281 "../bison/swift.y"
    { printf("args decl 2 \n"); (yyval.Args) = add_expr_to_list((yyvsp[(1) - (5)].Args), (yyvsp[(3) - (5)].Expr),(yyvsp[(5) - (5)].VarType));;}
    break;

  case 99:
#line 290 "../bison/swift.y"
    {printf("array constructor");(yyval.Table) = (yyvsp[(2) - (3)].Table);;}
    break;

  case 100:
#line 293 "../bison/swift.y"
    {printf("array elem list empty \n");(yyval.Table) = create_table(NULL);;}
    break;

  case 101:
#line 294 "../bison/swift.y"
    {printf("array elems list \n"); (yyval.Table) = (yyvsp[(1) - (1)].Table);;}
    break;

  case 102:
#line 297 "../bison/swift.y"
    {printf("array elem 1 \n"); (yyval.Table) = create_table((yyvsp[(1) - (1)].TblElem));;}
    break;

  case 103:
#line 298 "../bison/swift.y"
    {printf("array elem more \n"); (yyval.Table) = add_elem_to_table((yyvsp[(1) - (3)].Table), (yyvsp[(3) - (3)].TblElem));;}
    break;

  case 104:
#line 301 "../bison/swift.y"
    {printf("array elem array elem \n");(yyval.TblElem) = create_tbl_elem(NULL, (yyvsp[(1) - (1)].Expr)); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2255 "swift.tab.c"
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


#line 304 "../bison/swift.y"


