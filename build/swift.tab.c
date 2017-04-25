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
     FOUNDATIONI = 300,
     OR = 301,
     AND = 302
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
#define FOUNDATIONI 300
#define OR 301
#define AND 302




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
#line 230 "swift.tab.c"
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
#line 255 "swift.tab.c"

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
#define YYLAST   553

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNRULES -- Number of states.  */
#define YYNSTATES  189

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
       2,     2,     2,     2,     2,     2,     2,    54,     2,     2,
      63,    64,    52,    50,    65,    51,    60,    53,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,    55,
      48,    58,    49,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    13,    15,    18,
      23,    24,    28,    30,    32,    34,    36,    38,    40,    43,
      46,    50,    53,    58,    60,    62,    69,    78,    79,    84,
      93,    94,    97,   100,   103,   107,   110,   114,   120,   125,
     127,   129,   133,   135,   137,   139,   142,   148,   154,   158,
     160,   162,   164,   166,   168,   170,   172,   174,   176,   179,
     182,   186,   190,   194,   198,   202,   206,   210,   214,   218,
     222,   226,   230,   234,   238,   242,   244,   246,   248,   250,
     255,   256,   258,   260,   264,   270,   272,   274,   276,   278,
     280,   282,   286,   293,   294,   295,   298,   302,   308,   312,
     313,   315,   317,   321
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      69,     0,    -1,    44,    -1,    55,    68,    -1,    -1,    44,
      -1,    73,    -1,    45,    -1,     3,    88,    -1,    56,    73,
      57,    68,    -1,    -1,    73,    74,    68,    -1,    72,    -1,
      75,    -1,    82,    -1,    83,    -1,    84,    -1,    77,    -1,
      29,    67,    -1,    34,    67,    -1,    34,    89,    67,    -1,
      89,    67,    -1,    88,    58,    89,    67,    -1,    94,    -1,
      67,    -1,    23,    89,    68,    72,    76,    68,    -1,    23,
      89,    68,    72,    76,    24,    72,    68,    -1,    -1,    76,
      25,    89,    72,    -1,    26,    89,    68,    56,    68,    78,
      68,    57,    -1,    -1,    78,    79,    -1,    80,    73,    -1,
      81,    73,    -1,    27,    89,    59,    -1,    28,    59,    -1,
      20,    89,    72,    -1,    21,    85,    22,    89,    72,    -1,
      19,    72,    20,    89,    -1,    38,    -1,    85,    -1,    86,
      60,    85,    -1,    18,    -1,    17,    -1,    86,    -1,    87,
      86,    -1,    61,    93,    62,    63,    64,    -1,    88,    59,
      61,    93,    62,    -1,    88,    59,    93,    -1,    88,    -1,
       4,    -1,     6,    -1,     8,    -1,    15,    -1,    16,    -1,
       7,    -1,     5,    -1,    35,    -1,    43,    89,    -1,    89,
      43,    -1,    89,    47,    89,    -1,    89,    46,    89,    -1,
      89,    50,    89,    -1,    89,    51,    89,    -1,    89,    52,
      89,    -1,    89,    53,    89,    -1,    89,    54,    89,    -1,
      89,    49,    89,    -1,    89,    48,    89,    -1,    89,    42,
      89,    -1,    89,    41,    89,    -1,    89,    39,    89,    -1,
      89,    40,    89,    -1,    89,    33,    89,    -1,    63,    89,
      64,    -1,    90,    -1,    99,    -1,    71,    -1,    70,    -1,
      88,    63,    91,    64,    -1,    -1,    92,    -1,    89,    -1,
      85,    59,    89,    -1,    92,    65,    85,    59,    89,    -1,
      11,    -1,     9,    -1,    12,    -1,    13,    -1,    14,    -1,
      10,    -1,    30,    86,    95,    -1,    63,    96,    64,    31,
      93,    72,    -1,    -1,    -1,    98,    97,    -1,    85,    59,
      93,    -1,    98,    65,    85,    59,    93,    -1,    61,   100,
      62,    -1,    -1,   101,    -1,   102,    -1,   101,    65,   102,
      -1,    89,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   125,   125,   126,   129,   130,   133,   136,   140,   145,
     148,   149,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   167,   168,   170,   171,   174,
     176,   177,   179,   180,   182,   184,   186,   188,   190,   193,
     195,   196,   199,   200,   203,   204,   205,   206,   207,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   244,
     246,   247,   249,   250,   251,   254,   255,   256,   257,   258,
     259,   263,   265,   268,   269,   269,   271,   272,   281,   284,
     285,   288,   289,   292
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
  "EQ", "NE", "LE", "GE", "NOT", "ENDL", "FOUNDATIONI", "OR", "AND", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "';'", "'{'", "'}'", "'='",
  "':'", "'.'", "'['", "']'", "'('", "')'", "','", "$accept", "end_expr",
  "opt_endl", "root", "stmt_Foundation", "stmt_import", "stmt_block",
  "stmt_list", "stmt", "stmt_if", "elseif_list", "stmt_switch",
  "switch_cases", "switch_case", "case_label", "default_label",
  "stmt_while", "stmt_for", "stmt_repeat", "alone_id", "id_chain",
  "varlet", "var", "expr", "func_call", "arg_list", "args", "type",
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
     295,   296,   297,   298,   299,   300,   301,   302,    60,    62,
      43,    45,    42,    47,    37,    59,   123,   125,    61,    58,
      46,    91,    93,    40,    41,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    67,    68,    68,    69,    70,    71,    72,
      73,    73,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    75,    75,    76,    76,    77,
      78,    78,    79,    79,    80,    81,    82,    83,    84,    85,
      86,    86,    87,    87,    88,    88,    88,    88,    88,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    90,
      91,    91,    92,    92,    92,    93,    93,    93,    93,    93,
      93,    94,    95,    96,    97,    96,    98,    98,    99,   100,
     100,   101,   101,   102
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     2,     4,
       0,     3,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     2,     4,     1,     1,     6,     8,     0,     4,     8,
       0,     2,     2,     2,     3,     2,     3,     5,     4,     1,
       1,     3,     1,     1,     1,     2,     5,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     4,
       0,     1,     1,     3,     5,     1,     1,     1,     1,     1,
       1,     3,     6,     0,     0,     2,     3,     5,     3,     0,
       1,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      10,     0,     6,     1,     0,    50,    56,    51,    55,    52,
      53,    54,    43,    42,     0,     0,     0,     0,     0,     0,
       0,     0,    57,    39,     0,     2,     7,     4,    10,    99,
       0,    24,    78,    77,    12,     4,    13,    17,    14,    15,
      16,    40,    44,     0,    49,     0,    75,    23,    76,     0,
       8,     0,    49,     0,     0,     4,     4,    18,     0,    19,
       0,    58,     5,     3,     0,    86,    90,    85,    87,    88,
      89,   103,     0,     0,   100,   101,     0,    11,     0,    45,
       0,     0,    80,     0,     0,     0,     0,     0,    59,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
      36,     0,     0,     0,    93,    91,    20,     4,     0,    98,
       0,    74,    41,     0,     0,    48,    40,    82,     0,    81,
      73,    71,    72,    70,    69,    61,    60,    68,    67,    62,
      63,    64,    65,    66,    38,     0,    27,     4,     0,     0,
      94,     9,     0,   102,    22,     0,     0,    79,     0,    37,
       4,    30,     0,     0,     0,    95,    46,    47,    83,     0,
       0,     0,    25,     4,    96,     0,     0,     0,     4,     0,
       0,     0,     0,    31,    10,    10,     0,     0,    84,    26,
      28,     0,    35,    29,    32,    33,    92,    97,    34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    31,    63,     1,    32,    33,    34,     2,    35,    36,
     150,    37,   163,   173,   174,   175,    38,    39,    40,    41,
      42,    43,    52,    45,    46,   118,   119,    72,    47,   105,
     139,   155,   140,    48,    73,    74,    75
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -60
static const yytype_int16 yypact[] =
{
     -60,    17,   230,   -60,    -7,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,   -32,   108,   -12,   108,   108,    -6,
     -12,   315,   -60,   -60,   108,   -60,   -60,    -5,   -60,   291,
     108,   -60,   -60,   -60,   -60,    -5,   -60,   -60,   -60,   -60,
     -60,   -60,   -23,   -12,     0,   410,   -60,   -60,   -60,   121,
     -16,    21,   -40,   388,    22,   433,   433,   -60,   -56,   -60,
     410,   -60,   -60,   -60,   169,   -60,   -60,   -60,   -60,   -60,
     -60,   455,   -17,   -10,   -14,   -60,   340,   -60,   -12,   -23,
     108,    56,   108,   108,   108,   108,   108,   108,   -60,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   -60,   108,
     -60,   108,   -32,     4,   -12,   -60,   -60,    -5,     1,   -60,
     108,   -60,   -60,   410,   121,   -60,    13,   455,    15,    -4,
     165,   165,   165,   165,   165,   477,   499,   165,   165,   -18,
     -18,     7,     7,     7,   455,   388,   -60,    -5,    32,    31,
      35,   -60,    33,   -60,   -60,    34,   108,   -60,   -12,   -60,
     -11,   -60,   121,    25,   -12,   -60,   -60,   -60,   455,    43,
     -32,   108,   -60,     2,   -60,   121,    44,   108,    -5,   388,
     108,    45,    48,   -60,   -60,   -60,   -32,   121,   455,   -60,
     -60,   366,   -60,   -60,   230,   230,   -60,   -60,   -60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -60,    -3,    -8,   -60,   -60,   -60,   -13,   -25,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,    16,
     -15,   -60,    -2,    -9,   -60,   -60,   -60,   -59,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,   -60,   -57
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      44,    51,    50,    64,    78,    58,    53,   104,    55,    56,
      12,    13,    60,   160,   161,    61,    57,     3,    59,    81,
      71,    76,   115,    82,    28,    88,    23,    77,    79,   170,
     171,    23,    54,    62,    95,    96,    97,    78,    25,    62,
     100,    99,    98,    81,   101,   108,    62,   102,   103,    27,
      88,   110,   109,   143,    49,   145,   165,   106,    80,    81,
     137,   148,    44,    82,   142,    65,    66,    67,    68,    69,
      70,   113,   146,   117,   120,   121,   122,   123,   124,   147,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   136,
     134,   152,   135,   164,   112,   153,   157,   156,   116,   141,
     154,    71,   167,   177,   182,   183,   176,     0,     0,     0,
     144,     4,     5,     6,     7,     8,     9,   114,   187,     0,
     138,     0,   149,    10,    11,    12,    13,     0,     0,   151,
      65,    66,    67,    68,    69,    70,     0,   158,     0,     0,
       0,     0,   162,    22,     0,     0,    23,   168,     0,   184,
     185,    24,   169,    26,     0,   172,   180,     0,   178,     0,
     179,   181,     0,   186,   159,     0,     0,     0,     0,    29,
     166,    30,     4,     5,     6,     7,     8,     9,     0,     0,
       0,     0,    44,    44,    10,    11,    12,    13,    14,    15,
      16,     0,    17,     0,     0,    18,     0,     0,    19,    20,
       0,     0,     0,    21,    22,     0,     0,    23,    88,     0,
       0,     0,    24,    25,    26,    93,    94,    95,    96,    97,
       0,     0,     0,     0,    27,    28,   107,     0,     0,     0,
      29,     0,    30,     4,     5,     6,     7,     8,     9,     0,
       0,     0,     0,     0,     0,    10,    11,    12,    13,    14,
      15,    16,     0,    17,     0,     0,    18,     0,     0,    19,
      20,     0,     0,     0,    21,    22,     0,     0,    23,     0,
       0,     0,     0,    24,    25,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,    28,     0,     0,     0,
       0,    29,     0,    30,     4,     5,     6,     7,     8,     9,
      65,    66,    67,    68,    69,    70,    10,    11,    12,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     4,     5,
       6,     7,     8,     9,     0,     0,    22,     0,     0,    23,
      10,    11,    12,    13,    24,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,     0,    29,    23,    30,     0,     0,     0,    24,    25,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,     0,     0,    83,     0,     0,    29,     0,    30,    84,
      85,    86,    87,    88,     0,     0,    89,    90,    91,    92,
      93,    94,    95,    96,    97,     0,     0,     0,     0,    83,
       0,     0,     0,     0,   111,    84,    85,    86,    87,    88,
       0,     0,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    83,     0,     0,     0,   188,     0,    84,    85,    86,
      87,    88,     0,     0,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    83,    28,     0,     0,     0,     0,    84,
      85,    86,    87,    88,    25,     0,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    27,    83,     0,     0,     0,
       0,     0,    84,    85,    86,    87,    88,    62,     0,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    83,     0,
       0,     0,     0,     0,    84,    85,    86,    87,    88,     0,
       0,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      83,     0,     0,     0,     0,     0,    84,    85,    86,    87,
      88,     0,     0,     0,    90,    91,    92,    93,    94,    95,
      96,    97,    83,     0,     0,     0,     0,     0,    84,    85,
      86,    87,    88,     0,     0,     0,     0,    91,    92,    93,
      94,    95,    96,    97
};

static const yytype_int16 yycheck[] =
{
       2,    14,     4,    28,    60,    20,    15,    63,    17,    18,
      17,    18,    21,    24,    25,    24,    19,     0,    21,    59,
      29,    30,    81,    63,    56,    43,    38,    35,    43,    27,
      28,    38,    16,    44,    52,    53,    54,    60,    44,    44,
      53,    20,    45,    59,    22,    62,    44,    55,    56,    55,
      43,    65,    62,   110,    61,   114,    31,    60,    58,    59,
      56,    65,    64,    63,    63,     9,    10,    11,    12,    13,
      14,    80,    59,    82,    83,    84,    85,    86,    87,    64,
      89,    90,    91,    92,    93,    94,    95,    96,    97,   102,
      99,    59,   101,   152,    78,    64,    62,    64,    82,   107,
      65,   110,    59,    59,    59,    57,   165,    -1,    -1,    -1,
     113,     3,     4,     5,     6,     7,     8,    61,   177,    -1,
     104,    -1,   135,    15,    16,    17,    18,    -1,    -1,   137,
       9,    10,    11,    12,    13,    14,    -1,   146,    -1,    -1,
      -1,    -1,   150,    35,    -1,    -1,    38,   160,    -1,   174,
     175,    43,   161,    45,    -1,   163,   169,    -1,   167,    -1,
     168,   170,    -1,   176,   148,    -1,    -1,    -1,    -1,    61,
     154,    63,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,   184,   185,    15,    16,    17,    18,    19,    20,
      21,    -1,    23,    -1,    -1,    26,    -1,    -1,    29,    30,
      -1,    -1,    -1,    34,    35,    -1,    -1,    38,    43,    -1,
      -1,    -1,    43,    44,    45,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    55,    56,    57,    -1,    -1,    -1,
      61,    -1,    63,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    -1,    23,    -1,    -1,    26,    -1,    -1,    29,
      30,    -1,    -1,    -1,    34,    35,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    43,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    -1,    -1,    -1,
      -1,    61,    -1,    63,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    -1,    35,    -1,    -1,    38,
      15,    16,    17,    18,    43,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    -1,    61,    38,    63,    -1,    -1,    -1,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    33,    -1,    -1,    61,    -1,    63,    39,
      40,    41,    42,    43,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    64,    39,    40,    41,    42,    43,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    33,    -1,    -1,    -1,    59,    -1,    39,    40,    41,
      42,    43,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    33,    56,    -1,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    33,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    33,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      33,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    54,    33,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    69,    73,     0,     3,     4,     5,     6,     7,     8,
      15,    16,    17,    18,    19,    20,    21,    23,    26,    29,
      30,    34,    35,    38,    43,    44,    45,    55,    56,    61,
      63,    67,    70,    71,    72,    74,    75,    77,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    94,    99,    61,
      88,    72,    88,    89,    85,    89,    89,    67,    86,    67,
      89,    89,    44,    68,    73,     9,    10,    11,    12,    13,
      14,    89,    93,   100,   101,   102,    89,    68,    60,    86,
      58,    59,    63,    33,    39,    40,    41,    42,    43,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    67,    20,
      72,    22,    68,    68,    63,    95,    67,    57,    62,    62,
      65,    64,    85,    89,    61,    93,    85,    89,    91,    92,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    72,    56,    85,    96,
      98,    68,    63,   102,    67,    93,    59,    64,    65,    72,
      76,    68,    59,    64,    65,    97,    64,    62,    89,    85,
      24,    25,    68,    78,    93,    31,    85,    59,    72,    89,
      27,    28,    68,    79,    80,    81,    93,    59,    89,    68,
      72,    89,    59,    57,    73,    73,    72,    93,    59
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
#line 125 "../bison/swift.y"
    {;;}
    break;

  case 3:
#line 126 "../bison/swift.y"
    {;;}
    break;

  case 4:
#line 129 "../bison/swift.y"
    {;;}
    break;

  case 5:
#line 130 "../bison/swift.y"
    {;;}
    break;

  case 6:
#line 133 "../bison/swift.y"
    {printf("root\n");;}
    break;

  case 7:
#line 136 "../bison/swift.y"
    {printf("foundation\n");;}
    break;

  case 8:
#line 140 "../bison/swift.y"
    {printf("import found\n");;}
    break;

  case 9:
#line 145 "../bison/swift.y"
    {printf("block found\n");;}
    break;

  case 10:
#line 148 "../bison/swift.y"
    { printf("stmt list null found\n");;}
    break;

  case 11:
#line 149 "../bison/swift.y"
    {printf("stmt list not null\n");;}
    break;

  case 12:
#line 152 "../bison/swift.y"
    {printf("stmt_block\n");;}
    break;

  case 13:
#line 153 "../bison/swift.y"
    {printf("stmt_if\n");;}
    break;

  case 14:
#line 154 "../bison/swift.y"
    {printf("stmt_while\n");;}
    break;

  case 15:
#line 155 "../bison/swift.y"
    {printf("stmt_for\n");;}
    break;

  case 16:
#line 156 "../bison/swift.y"
    {printf("stmt_repeat\n");;}
    break;

  case 17:
#line 157 "../bison/swift.y"
    {printf("stmt_switch\n");;}
    break;

  case 18:
#line 158 "../bison/swift.y"
    {printf("stmt_break\n");;}
    break;

  case 19:
#line 159 "../bison/swift.y"
    {printf("stmt_return\n");;}
    break;

  case 20:
#line 160 "../bison/swift.y"
    {printf("stmt_return end\n");;}
    break;

  case 21:
#line 161 "../bison/swift.y"
    {printf("stmt_expr\n");;}
    break;

  case 22:
#line 162 "../bison/swift.y"
    {printf("line with eq\n");;}
    break;

  case 23:
#line 163 "../bison/swift.y"
    {printf("stmt_func decl\n");;}
    break;

  case 24:
#line 164 "../bison/swift.y"
    {printf("end_expr\n");;}
    break;

  case 25:
#line 167 "../bison/swift.y"
    {printf("stmt_if_1\n");;}
    break;

  case 26:
#line 168 "../bison/swift.y"
    {printf("stmt_if_2\n");;}
    break;

  case 27:
#line 170 "../bison/swift.y"
    {printf("empty else if\n");;}
    break;

  case 28:
#line 171 "../bison/swift.y"
    {printf("else_if\n");;}
    break;

  case 29:
#line 174 "../bison/swift.y"
    {printf("stmt_switch\n");;}
    break;

  case 30:
#line 176 "../bison/swift.y"
    {printf("empty case\n");;}
    break;

  case 31:
#line 177 "../bison/swift.y"
    {printf("switch cases\n");;}
    break;

  case 32:
#line 179 "../bison/swift.y"
    {printf("switch case\n");;}
    break;

  case 33:
#line 180 "../bison/swift.y"
    {printf("switch case 2\n");;}
    break;

  case 34:
#line 182 "../bison/swift.y"
    {printf("case label\n");;}
    break;

  case 35:
#line 184 "../bison/swift.y"
    {printf("default label \n");;}
    break;

  case 36:
#line 186 "../bison/swift.y"
    {printf("stmt_while\n");;}
    break;

  case 37:
#line 188 "../bison/swift.y"
    {printf("stmt_for\n");;}
    break;

  case 38:
#line 190 "../bison/swift.y"
    {printf("stmt_repeat\n");;}
    break;

  case 39:
#line 193 "../bison/swift.y"
    {printf("alone_id\n");;}
    break;

  case 40:
#line 195 "../bison/swift.y"
    {printf("id-chain\n");;}
    break;

  case 41:
#line 196 "../bison/swift.y"
    {printf("id chain class\n");;}
    break;

  case 42:
#line 199 "../bison/swift.y"
    {printf("var \n");;}
    break;

  case 43:
#line 200 "../bison/swift.y"
    {printf("let\n");;}
    break;

  case 44:
#line 203 "../bison/swift.y"
    {printf("varuble 1\n");;}
    break;

  case 45:
#line 204 "../bison/swift.y"
    {printf("varuble 2\n");;}
    break;

  case 46:
#line 205 "../bison/swift.y"
    {printf("varuble 3\n");;}
    break;

  case 47:
#line 206 "../bison/swift.y"
    {printf("varuble 4\n");;}
    break;

  case 48:
#line 207 "../bison/swift.y"
    {printf("varuble 5\n");;}
    break;

  case 49:
#line 211 "../bison/swift.y"
    {printf("expr var\n");;}
    break;

  case 50:
#line 212 "../bison/swift.y"
    {printf("expr INT\n");;}
    break;

  case 51:
#line 213 "../bison/swift.y"
    {printf("expr DOUBLE\n");;}
    break;

  case 52:
#line 214 "../bison/swift.y"
    {printf("expr STRING\n");;}
    break;

  case 53:
#line 215 "../bison/swift.y"
    {printf("expr TRUE\n");;}
    break;

  case 54:
#line 216 "../bison/swift.y"
    {printf("expr FALSE\n");;}
    break;

  case 55:
#line 217 "../bison/swift.y"
    {printf("expr BOOL\n");;}
    break;

  case 56:
#line 218 "../bison/swift.y"
    {printf("expr FLOAT\n");;}
    break;

  case 57:
#line 219 "../bison/swift.y"
    {printf("expr NIL\n");;}
    break;

  case 58:
#line 220 "../bison/swift.y"
    {printf("not expr ");;}
    break;

  case 59:
#line 221 "../bison/swift.y"
    {printf("expr not type\n");;}
    break;

  case 60:
#line 222 "../bison/swift.y"
    {printf("expr and expr\n");;}
    break;

  case 61:
#line 223 "../bison/swift.y"
    {printf("expr or expr\n");;}
    break;

  case 62:
#line 224 "../bison/swift.y"
    {printf("expr + expr\n");;}
    break;

  case 63:
#line 225 "../bison/swift.y"
    {printf("expr - expr\n");;}
    break;

  case 64:
#line 226 "../bison/swift.y"
    {printf("expr * expr\n");;}
    break;

  case 65:
#line 227 "../bison/swift.y"
    {printf("expr / expr\n");;}
    break;

  case 66:
#line 228 "../bison/swift.y"
    {printf("expr % expr\n");;}
    break;

  case 67:
#line 229 "../bison/swift.y"
    {printf("expr > expr\n");;}
    break;

  case 68:
#line 230 "../bison/swift.y"
    {printf("expr < expr\n");;}
    break;

  case 69:
#line 231 "../bison/swift.y"
    {printf("expr GE expr\n");;}
    break;

  case 70:
#line 232 "../bison/swift.y"
    {printf("expr LE expr\n");;}
    break;

  case 71:
#line 233 "../bison/swift.y"
    {printf("expr EQ expr\n");;}
    break;

  case 72:
#line 234 "../bison/swift.y"
    {printf("expr NE expr\n");;}
    break;

  case 73:
#line 235 "../bison/swift.y"
    {printf("expr RANGE expr\n");;}
    break;

  case 74:
#line 236 "../bison/swift.y"
    {printf("(expr)\n");;}
    break;

  case 75:
#line 237 "../bison/swift.y"
    {printf("expr func_call\n");;}
    break;

  case 76:
#line 238 "../bison/swift.y"
    {printf("expr array_constructor\n");;}
    break;

  case 77:
#line 239 "../bison/swift.y"
    {printf("expr stmt_import\n");;}
    break;

  case 78:
#line 240 "../bison/swift.y"
    {printf("expr stmt_Foundation\n");;}
    break;

  case 79:
#line 244 "../bison/swift.y"
    {printf("function call\n");;}
    break;

  case 80:
#line 246 "../bison/swift.y"
    {printf("arg_list empty\n");;}
    break;

  case 81:
#line 247 "../bison/swift.y"
    {printf("arg_list args \n");;}
    break;

  case 82:
#line 249 "../bison/swift.y"
    {printf("args expr\n");;}
    break;

  case 83:
#line 250 "../bison/swift.y"
    {printf("args id : expr\n");;}
    break;

  case 84:
#line 251 "../bison/swift.y"
    {printf("args , id : expr\n");;}
    break;

  case 85:
#line 254 "../bison/swift.y"
    {printf("int type\n");;}
    break;

  case 86:
#line 255 "../bison/swift.y"
    {printf("string type\n");;}
    break;

  case 87:
#line 256 "../bison/swift.y"
    {printf("float type\n");;}
    break;

  case 88:
#line 257 "../bison/swift.y"
    {printf("double type\n");;}
    break;

  case 89:
#line 258 "../bison/swift.y"
    {printf("bool type\n");;}
    break;

  case 90:
#line 259 "../bison/swift.y"
    {printf("character type\n");;}
    break;

  case 91:
#line 263 "../bison/swift.y"
    {printf("func decl name\n");;}
    break;

  case 92:
#line 265 "../bison/swift.y"
    {printf("function body\n");;}
    break;

  case 93:
#line 268 "../bison/swift.y"
    {printf("arg list decl empty\n");;}
    break;

  case 94:
#line 269 "../bison/swift.y"
    {;;}
    break;

  case 95:
#line 269 "../bison/swift.y"
    {printf("arg list decl \n");;}
    break;

  case 96:
#line 271 "../bison/swift.y"
    {printf("args decl 1 \n");;}
    break;

  case 97:
#line 272 "../bison/swift.y"
    { printf("args decl 2 \n");;}
    break;

  case 98:
#line 281 "../bison/swift.y"
    {printf("array constructor");;}
    break;

  case 99:
#line 284 "../bison/swift.y"
    {printf("array elem list empty \n");;}
    break;

  case 100:
#line 285 "../bison/swift.y"
    {printf("array elems list \n");;}
    break;

  case 101:
#line 288 "../bison/swift.y"
    {printf("array elem 1 \n");;}
    break;

  case 102:
#line 289 "../bison/swift.y"
    {printf("array elem more \n");;}
    break;

  case 103:
#line 292 "../bison/swift.y"
    {printf("array elem array elem \n");;}
    break;


/* Line 1267 of yacc.c.  */
#line 2234 "swift.tab.c"
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


