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
     AND = 301
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
}
/* Line 193 of yacc.c.  */
#line 228 "swift.tab.c"
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
#line 253 "swift.tab.c"

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
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNRULES -- Number of states.  */
#define YYNSTATES  196

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    53,     2,     2,
      62,    63,    51,    49,    64,    50,    59,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    58,    54,
      47,    57,    48,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    60,     2,    61,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,    56,     2,     2,     2,     2,
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
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    13,    16,    21,
      22,    26,    28,    30,    32,    34,    36,    38,    41,    44,
      48,    51,    56,    58,    60,    64,    71,    80,    81,    86,
      95,    96,    99,   102,   105,   109,   112,   116,   122,   127,
     129,   131,   135,   137,   139,   141,   144,   150,   156,   160,
     162,   166,   168,   170,   172,   174,   176,   178,   180,   182,
     184,   187,   190,   194,   198,   202,   206,   210,   214,   218,
     222,   226,   230,   234,   238,   242,   246,   250,   252,   254,
     256,   261,   268,   269,   271,   273,   277,   283,   285,   287,
     289,   291,   293,   295,   299,   306,   307,   309,   313,   319,
     323,   324,   326,   328,   332
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      68,     0,    -1,    44,    -1,    54,    67,    -1,    -1,    44,
      -1,    71,    -1,     3,    86,    -1,    55,    71,    56,    67,
      -1,    -1,    71,    72,    67,    -1,    70,    -1,    73,    -1,
      80,    -1,    81,    -1,    82,    -1,    75,    -1,    29,    66,
      -1,    34,    66,    -1,    34,    88,    66,    -1,    88,    66,
      -1,    86,    57,    88,    66,    -1,    93,    -1,    66,    -1,
      87,    57,    91,    -1,    23,    88,    67,    70,    74,    67,
      -1,    23,    88,    67,    70,    74,    24,    70,    67,    -1,
      -1,    74,    25,    88,    70,    -1,    26,    88,    67,    55,
      67,    76,    67,    56,    -1,    -1,    76,    77,    -1,    78,
      71,    -1,    79,    71,    -1,    27,    88,    58,    -1,    28,
      58,    -1,    20,    88,    70,    -1,    21,    83,    22,    88,
      70,    -1,    19,    70,    20,    88,    -1,    38,    -1,    83,
      -1,    84,    59,    83,    -1,    18,    -1,    17,    -1,    84,
      -1,    85,    84,    -1,    60,    92,    61,    62,    63,    -1,
      86,    58,    60,    92,    61,    -1,    86,    58,    92,    -1,
      86,    -1,    87,    64,    86,    -1,    86,    -1,     4,    -1,
       6,    -1,     8,    -1,    15,    -1,    16,    -1,     7,    -1,
       5,    -1,    35,    -1,    43,    88,    -1,    88,    43,    -1,
      88,    46,    88,    -1,    88,    45,    88,    -1,    88,    49,
      88,    -1,    88,    50,    88,    -1,    88,    51,    88,    -1,
      88,    52,    88,    -1,    88,    53,    88,    -1,    88,    48,
      88,    -1,    88,    47,    88,    -1,    88,    42,    88,    -1,
      88,    41,    88,    -1,    88,    39,    88,    -1,    88,    40,
      88,    -1,    88,    33,    88,    -1,    62,    88,    63,    -1,
      89,    -1,    97,    -1,    69,    -1,    86,    62,    90,    63,
      -1,    86,    58,    83,    62,    90,    63,    -1,    -1,    91,
      -1,    84,    -1,    38,    58,    88,    -1,    91,    64,    38,
      58,    88,    -1,    11,    -1,     9,    -1,    12,    -1,    13,
      -1,    14,    -1,    10,    -1,    30,    84,    94,    -1,    62,
      95,    63,    31,    92,    70,    -1,    -1,    96,    -1,    84,
      58,    92,    -1,    96,    64,    83,    58,    92,    -1,    60,
      98,    61,    -1,    -1,    99,    -1,   100,    -1,    99,    64,
     100,    -1,    88,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   126,   126,   127,   130,   131,   134,   137,   142,   145,
     146,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   165,   166,   168,   169,   172,
     174,   175,   177,   178,   180,   182,   184,   186,   188,   191,
     193,   194,   197,   198,   201,   202,   203,   204,   205,   207,
     208,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     243,   244,   246,   247,   249,   250,   251,   254,   255,   256,
     257,   258,   259,   263,   265,   268,   269,   271,   272,   281,
     284,   285,   288,   289,   292
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
  "'-'", "'*'", "'/'", "'%'", "';'", "'{'", "'}'", "'='", "':'", "'.'",
  "'['", "']'", "'('", "')'", "','", "$accept", "end_expr", "opt_endl",
  "root", "stmt_import", "stmt_block", "stmt_list", "stmt", "stmt_if",
  "elseif_list", "stmt_switch", "switch_cases", "switch_case",
  "case_label", "default_label", "stmt_while", "stmt_for", "stmt_repeat",
  "alone_id", "id_chain", "varlet", "var", "var_list", "expr", "func_call",
  "arg_list", "args", "type", "func_decl_named", "func_body",
  "arg_list_decl", "args_decl", "array_constructor", "array_elem_list",
  "array_elems", "array_elem", 0
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
      45,    42,    47,    37,    59,   123,   125,    61,    58,    46,
      91,    93,    40,    41,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    66,    67,    67,    68,    69,    70,    71,
      71,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    73,    73,    74,    74,    75,
      76,    76,    77,    77,    78,    79,    80,    81,    82,    83,
      84,    84,    85,    85,    86,    86,    86,    86,    86,    87,
      87,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      89,    89,    90,    90,    91,    91,    91,    92,    92,    92,
      92,    92,    92,    93,    94,    95,    95,    96,    96,    97,
      98,    98,    99,    99,   100
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     2,     4,     0,
       3,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       2,     4,     1,     1,     3,     6,     8,     0,     4,     8,
       0,     2,     2,     2,     3,     2,     3,     5,     4,     1,
       1,     3,     1,     1,     1,     2,     5,     5,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       4,     6,     0,     1,     1,     3,     5,     1,     1,     1,
       1,     1,     1,     3,     6,     0,     1,     3,     5,     3,
       0,     1,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       9,     0,     6,     1,     0,    52,    58,    53,    57,    54,
      55,    56,    43,    42,     0,     0,     0,     0,     0,     0,
       0,     0,    59,    39,     0,     2,     4,     9,   100,     0,
      23,    79,    11,     4,    12,    16,    13,    14,    15,    40,
      44,     0,    51,     0,     0,    77,    22,    78,     0,     7,
       0,    51,     0,     0,     4,     4,    17,     0,    18,     0,
      60,     5,     3,     0,    88,    92,    87,    89,    90,    91,
     104,     0,     0,   101,   102,     0,    10,     0,    45,     0,
       0,    82,     0,     0,     0,     0,     0,     0,     0,    61,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    20,
       0,     0,    36,     0,     0,     0,    95,    93,    19,     4,
       0,    99,     0,    76,    41,     0,     0,     0,    48,    39,
      84,     0,    83,    24,    50,    75,    73,    74,    72,    71,
      63,    62,    70,    69,    64,    65,    66,    67,    68,    38,
       0,    27,     4,     0,     0,    96,     8,     0,   103,    21,
       0,    82,     0,    80,     0,    37,     4,    30,     0,     0,
       0,    46,    47,     0,    85,     0,     0,     0,    25,     4,
      97,     0,     0,    81,     0,     4,     0,     0,     0,     0,
      31,     9,     9,     0,     0,    86,    26,    28,     0,    35,
      29,    32,    33,    94,    98,    34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    30,    62,     1,    31,    32,     2,    33,    34,   156,
      35,   169,   180,   181,   182,    36,    37,    38,    39,    40,
      41,    51,    43,    44,    45,   121,   122,    71,    46,   107,
     144,   145,    47,    72,    73,    74
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -67
static const yytype_int16 yypact[] =
{
     -67,    22,   236,   -67,     6,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -14,   397,     5,   397,   397,   -36,
       5,   337,   -67,   -67,   397,   -67,     2,   -67,   296,   397,
     -67,   -67,   -67,     2,   -67,   -67,   -67,   -67,   -67,   -67,
     -28,     5,    -6,   -45,   446,   -67,   -67,   -67,   103,    -1,
      29,   -20,   425,    37,   468,   468,   -67,   -29,   -67,   446,
     -67,   -67,   -67,   176,   -67,   -67,   -67,   -67,   -67,   -67,
     489,     3,     8,    10,   -67,   378,   -67,     5,   -28,   397,
     112,    24,    24,     6,   397,   397,   397,   397,   397,   -67,
     397,   397,   397,   397,   397,   397,   397,   397,   397,   -67,
     127,   397,   -67,   397,   -14,    12,     5,   -67,   -67,     2,
      13,   -67,   397,   -67,   -67,   446,   103,    32,   -67,    38,
     -28,    -3,    34,    34,    -1,    57,    57,    57,    57,    57,
     510,   531,    57,    57,   -16,   -16,    20,    20,    20,   489,
     425,   -67,     2,    -5,     7,    35,   -67,    40,   -67,   -67,
      58,    24,   397,   -67,    63,   -67,   -19,   -67,   103,    89,
       5,   -67,   -67,    65,   489,    71,   -14,   397,   -67,     1,
     -67,   103,    72,   -67,   397,     2,   425,   397,    73,    76,
     -67,   -67,   -67,   -14,   103,   489,   -67,   -67,   403,   -67,
     -67,   236,   236,   -67,   -67,   -67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -67,    -4,    -7,   -67,   -67,   -13,   -24,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -12,    -9,
     -67,    -2,   -67,    -8,   -67,   -18,    52,   -66,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,    31
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -50
static const yytype_int16 yytable[] =
{
      42,    50,    49,    63,    53,   166,   167,    52,    25,    54,
      55,    57,    82,    59,   118,    56,    60,    58,    26,    83,
      70,    75,     3,    12,    13,    61,    76,    89,   177,   178,
      77,    77,    78,   106,   118,    96,    97,    98,    80,   102,
      99,    27,    81,    23,    23,    61,    61,   104,   105,   101,
     150,    79,    80,   158,    77,   108,    81,   100,   -49,   103,
     153,    42,   119,    89,   110,   114,    48,   142,   117,   111,
     159,   115,   120,   120,   112,   147,   125,   126,   127,   128,
     129,   124,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   141,   170,   139,   151,   140,   152,   143,   154,   160,
      89,   165,   146,   161,    70,   183,    94,    95,    96,    97,
      98,   149,    64,    65,    66,    67,    68,    69,   194,   162,
     171,    64,    65,    66,    67,    68,    69,   155,   173,   174,
     184,   189,   190,   163,   123,   157,    64,    65,    66,    67,
      68,    69,   120,   148,   164,     0,     0,     0,   172,   168,
      23,     0,     0,   175,     0,     0,     0,   191,   192,   176,
       0,     0,   179,   187,     0,     0,   185,     0,   186,   188,
     193,     0,   116,     0,     0,     0,     0,     0,     0,     4,
       5,     6,     7,     8,     9,     0,     0,   116,     0,    42,
      42,    10,    11,    12,    13,    14,    15,    16,     0,    17,
       0,     0,    18,     0,     0,    19,    20,     0,     0,     0,
      21,    22,     0,     0,    23,     0,     0,     0,     0,    24,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,    27,   109,     0,     0,     0,    28,     0,    29,     4,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
       0,    10,    11,    12,    13,    14,    15,    16,     0,    17,
       0,     0,    18,     0,     0,    19,    20,     0,     0,     0,
      21,    22,     0,     0,    23,     0,     0,     0,     0,    24,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,    27,     0,     0,     0,     0,    28,     0,    29,     4,
       5,     6,     7,     8,     9,    64,    65,    66,    67,    68,
      69,    10,    11,    12,    13,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,     0,     0,    23,     0,     0,     0,     0,    24,
       4,     5,     6,     7,     8,     9,     0,     0,     0,     0,
       0,     0,    10,    11,    12,    13,    28,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,     0,     0,    23,     0,     0,     0,     0,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,     0,     0,     0,     0,    28,     0,    29,
       4,     5,     6,     7,     8,     9,     0,     0,     0,     0,
       0,    84,    10,    11,    12,    13,     0,    85,    86,    87,
      88,    89,     0,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    22,     0,     0,    23,    84,     0,     0,     0,
      24,   113,    85,    86,    87,    88,    89,     0,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    28,    84,    29,
       0,   195,     0,     0,    85,    86,    87,    88,    89,     0,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    84,
      27,     0,     0,     0,     0,    85,    86,    87,    88,    89,
      25,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      26,    84,     0,     0,     0,     0,     0,    85,    86,    87,
      88,    89,    61,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    84,     0,     0,     0,     0,     0,    85,    86,
      87,    88,    89,     0,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    84,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,     0,     0,    91,    92,    93,    94,
      95,    96,    97,    98,    84,     0,     0,     0,     0,     0,
      85,    86,    87,    88,    89,     0,     0,     0,    92,    93,
      94,    95,    96,    97,    98
};

static const yytype_int16 yycheck[] =
{
       2,    14,     4,    27,    16,    24,    25,    15,    44,    17,
      18,    20,    57,    21,    80,    19,    24,    21,    54,    64,
      28,    29,     0,    17,    18,    44,    33,    43,    27,    28,
      59,    59,    41,    62,   100,    51,    52,    53,    58,    52,
      44,    55,    62,    38,    38,    44,    44,    54,    55,    20,
     116,    57,    58,    58,    59,    59,    62,    58,    64,    22,
      63,    63,    38,    43,    61,    77,    60,    55,    80,    61,
      63,    79,    81,    82,    64,    62,    84,    85,    86,    87,
      88,    83,    90,    91,    92,    93,    94,    95,    96,    97,
      98,   104,   158,   101,    62,   103,    58,   106,    64,    64,
      43,    38,   109,    63,   112,   171,    49,    50,    51,    52,
      53,   115,     9,    10,    11,    12,    13,    14,   184,    61,
      31,     9,    10,    11,    12,    13,    14,   140,    63,    58,
      58,    58,    56,   151,    82,   142,     9,    10,    11,    12,
      13,    14,   151,   112,   152,    -1,    -1,    -1,   160,   156,
      38,    -1,    -1,   166,    -1,    -1,    -1,   181,   182,   167,
      -1,    -1,   169,   176,    -1,    -1,   174,    -1,   175,   177,
     183,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    -1,    60,    -1,   191,
     192,    15,    16,    17,    18,    19,    20,    21,    -1,    23,
      -1,    -1,    26,    -1,    -1,    29,    30,    -1,    -1,    -1,
      34,    35,    -1,    -1,    38,    -1,    -1,    -1,    -1,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    56,    -1,    -1,    -1,    60,    -1,    62,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    -1,    23,
      -1,    -1,    26,    -1,    -1,    29,    30,    -1,    -1,    -1,
      34,    35,    -1,    -1,    38,    -1,    -1,    -1,    -1,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    -1,    -1,    -1,    -1,    60,    -1,    62,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    38,    -1,    -1,    -1,    -1,    43,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    60,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    -1,    62,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    33,    15,    16,    17,    18,    -1,    39,    40,    41,
      42,    43,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    35,    -1,    -1,    38,    33,    -1,    -1,    -1,
      43,    63,    39,    40,    41,    42,    43,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    60,    33,    62,
      -1,    58,    -1,    -1,    39,    40,    41,    42,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    33,
      55,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    33,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
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
       0,    68,    71,     0,     3,     4,     5,     6,     7,     8,
      15,    16,    17,    18,    19,    20,    21,    23,    26,    29,
      30,    34,    35,    38,    43,    44,    54,    55,    60,    62,
      66,    69,    70,    72,    73,    75,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    93,    97,    60,    86,
      70,    86,    88,    83,    88,    88,    66,    84,    66,    88,
      88,    44,    67,    71,     9,    10,    11,    12,    13,    14,
      88,    92,    98,    99,   100,    88,    67,    59,    84,    57,
      58,    62,    57,    64,    33,    39,    40,    41,    42,    43,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    66,
      58,    20,    70,    22,    67,    67,    62,    94,    66,    56,
      61,    61,    64,    63,    83,    88,    60,    83,    92,    38,
      84,    90,    91,    91,    86,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    70,    55,    84,    95,    96,    67,    62,   100,    66,
      92,    62,    58,    63,    64,    70,    74,    67,    58,    63,
      64,    63,    61,    90,    88,    38,    24,    25,    67,    76,
      92,    31,    83,    63,    58,    70,    88,    27,    28,    67,
      77,    78,    79,    92,    58,    88,    67,    70,    88,    58,
      56,    71,    71,    70,    92,    58
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
#line 126 "../bison/swift.y"
    {;;}
    break;

  case 3:
#line 127 "../bison/swift.y"
    {;;}
    break;

  case 4:
#line 130 "../bison/swift.y"
    {;;}
    break;

  case 5:
#line 131 "../bison/swift.y"
    {;;}
    break;

  case 6:
#line 134 "../bison/swift.y"
    {;;}
    break;

  case 7:
#line 137 "../bison/swift.y"
    {printf("import found\n");;}
    break;

  case 8:
#line 142 "../bison/swift.y"
    {printf("block found\n");;}
    break;

  case 9:
#line 145 "../bison/swift.y"
    { printf("stmt list null found\n");;}
    break;

  case 10:
#line 146 "../bison/swift.y"
    {printf("stmt list not null\n");;}
    break;

  case 11:
#line 149 "../bison/swift.y"
    {;;}
    break;

  case 12:
#line 150 "../bison/swift.y"
    {;;}
    break;

  case 13:
#line 151 "../bison/swift.y"
    {;;}
    break;

  case 14:
#line 152 "../bison/swift.y"
    {;;}
    break;

  case 15:
#line 153 "../bison/swift.y"
    {;;}
    break;

  case 16:
#line 154 "../bison/swift.y"
    {;;}
    break;

  case 17:
#line 155 "../bison/swift.y"
    {;;}
    break;

  case 18:
#line 156 "../bison/swift.y"
    {;;}
    break;

  case 19:
#line 157 "../bison/swift.y"
    {;;}
    break;

  case 20:
#line 158 "../bison/swift.y"
    {;;}
    break;

  case 21:
#line 159 "../bison/swift.y"
    {printf("line with eq\n");;}
    break;

  case 22:
#line 160 "../bison/swift.y"
    {;;}
    break;

  case 23:
#line 161 "../bison/swift.y"
    {;;}
    break;

  case 24:
#line 162 "../bison/swift.y"
    {;;}
    break;

  case 25:
#line 165 "../bison/swift.y"
    {;;}
    break;

  case 26:
#line 166 "../bison/swift.y"
    {;;}
    break;

  case 27:
#line 168 "../bison/swift.y"
    {;;}
    break;

  case 28:
#line 169 "../bison/swift.y"
    {;;}
    break;

  case 29:
#line 172 "../bison/swift.y"
    {;;}
    break;

  case 30:
#line 174 "../bison/swift.y"
    {;;}
    break;

  case 31:
#line 175 "../bison/swift.y"
    {;;}
    break;

  case 32:
#line 177 "../bison/swift.y"
    {;;}
    break;

  case 33:
#line 178 "../bison/swift.y"
    {;;}
    break;

  case 34:
#line 180 "../bison/swift.y"
    {;;}
    break;

  case 35:
#line 182 "../bison/swift.y"
    {;;}
    break;

  case 36:
#line 184 "../bison/swift.y"
    {;;}
    break;

  case 37:
#line 186 "../bison/swift.y"
    {;;}
    break;

  case 38:
#line 188 "../bison/swift.y"
    {;;}
    break;

  case 39:
#line 191 "../bison/swift.y"
    {;;}
    break;

  case 40:
#line 193 "../bison/swift.y"
    {;;}
    break;

  case 41:
#line 194 "../bison/swift.y"
    {;;}
    break;

  case 42:
#line 197 "../bison/swift.y"
    {;;}
    break;

  case 43:
#line 198 "../bison/swift.y"
    {;;}
    break;

  case 44:
#line 201 "../bison/swift.y"
    {;;}
    break;

  case 45:
#line 202 "../bison/swift.y"
    {;;}
    break;

  case 46:
#line 203 "../bison/swift.y"
    {;;}
    break;

  case 47:
#line 204 "../bison/swift.y"
    {;;}
    break;

  case 48:
#line 205 "../bison/swift.y"
    {;;}
    break;

  case 49:
#line 207 "../bison/swift.y"
    {;;}
    break;

  case 50:
#line 208 "../bison/swift.y"
    {;;}
    break;

  case 51:
#line 211 "../bison/swift.y"
    {;;}
    break;

  case 52:
#line 212 "../bison/swift.y"
    {;;}
    break;

  case 53:
#line 213 "../bison/swift.y"
    {;;}
    break;

  case 54:
#line 214 "../bison/swift.y"
    {;;}
    break;

  case 55:
#line 215 "../bison/swift.y"
    {;;}
    break;

  case 56:
#line 216 "../bison/swift.y"
    {;;}
    break;

  case 57:
#line 217 "../bison/swift.y"
    {;;}
    break;

  case 58:
#line 218 "../bison/swift.y"
    {;;}
    break;

  case 59:
#line 219 "../bison/swift.y"
    {;;}
    break;

  case 60:
#line 220 "../bison/swift.y"
    {printf("not ");;}
    break;

  case 62:
#line 222 "../bison/swift.y"
    {;;}
    break;

  case 63:
#line 223 "../bison/swift.y"
    {;;}
    break;

  case 64:
#line 224 "../bison/swift.y"
    {;;}
    break;

  case 65:
#line 225 "../bison/swift.y"
    {;;}
    break;

  case 66:
#line 226 "../bison/swift.y"
    {;;}
    break;

  case 67:
#line 227 "../bison/swift.y"
    {;;}
    break;

  case 68:
#line 228 "../bison/swift.y"
    {;;}
    break;

  case 69:
#line 229 "../bison/swift.y"
    {;;}
    break;

  case 70:
#line 230 "../bison/swift.y"
    {;;}
    break;

  case 71:
#line 231 "../bison/swift.y"
    {;;}
    break;

  case 72:
#line 232 "../bison/swift.y"
    {;;}
    break;

  case 73:
#line 233 "../bison/swift.y"
    {;;}
    break;

  case 74:
#line 234 "../bison/swift.y"
    {;;}
    break;

  case 75:
#line 235 "../bison/swift.y"
    {;;}
    break;

  case 76:
#line 236 "../bison/swift.y"
    {;;}
    break;

  case 77:
#line 237 "../bison/swift.y"
    {;;}
    break;

  case 78:
#line 238 "../bison/swift.y"
    {;;}
    break;

  case 79:
#line 239 "../bison/swift.y"
    {;;}
    break;

  case 80:
#line 243 "../bison/swift.y"
    {;;}
    break;

  case 81:
#line 244 "../bison/swift.y"
    {;;}
    break;

  case 82:
#line 246 "../bison/swift.y"
    {;;}
    break;

  case 83:
#line 247 "../bison/swift.y"
    {;;}
    break;

  case 85:
#line 250 "../bison/swift.y"
    {;;}
    break;

  case 86:
#line 251 "../bison/swift.y"
    {;;}
    break;

  case 87:
#line 254 "../bison/swift.y"
    {;;}
    break;

  case 88:
#line 255 "../bison/swift.y"
    {;;}
    break;

  case 89:
#line 256 "../bison/swift.y"
    {;;}
    break;

  case 90:
#line 257 "../bison/swift.y"
    {;;}
    break;

  case 91:
#line 258 "../bison/swift.y"
    {;;}
    break;

  case 92:
#line 259 "../bison/swift.y"
    {;;}
    break;

  case 93:
#line 263 "../bison/swift.y"
    {;;}
    break;

  case 94:
#line 265 "../bison/swift.y"
    {;;}
    break;

  case 95:
#line 268 "../bison/swift.y"
    {;;}
    break;

  case 96:
#line 269 "../bison/swift.y"
    {;;}
    break;

  case 97:
#line 271 "../bison/swift.y"
    {;;}
    break;

  case 98:
#line 272 "../bison/swift.y"
    {;;}
    break;

  case 99:
#line 281 "../bison/swift.y"
    {;;}
    break;

  case 100:
#line 284 "../bison/swift.y"
    {;;}
    break;

  case 101:
#line 285 "../bison/swift.y"
    {;;}
    break;

  case 102:
#line 288 "../bison/swift.y"
    {;;}
    break;

  case 103:
#line 289 "../bison/swift.y"
    {;;}
    break;

  case 104:
#line 292 "../bison/swift.y"
    {;;}
    break;


/* Line 1267 of yacc.c.  */
#line 2237 "swift.tab.c"
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


#line 295 "../bison/swift.y"


