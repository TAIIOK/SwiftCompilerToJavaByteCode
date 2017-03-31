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
#define YYLAST   553

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNRULES -- Number of states.  */
#define YYNSTATES  184

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
       2,     2,     2,     2,     2,     2,     2,    54,     2,     2,
      64,    60,    52,    50,    63,    51,    62,    53,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    61,    55,
      47,    49,    48,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,    59,     2,     2,     2,     2,
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
       0,     0,     3,     5,     7,     9,    13,    18,    21,    22,
      26,    28,    30,    32,    34,    36,    39,    42,    46,    49,
      54,    56,    60,    65,    72,    73,    78,    84,    89,    96,
     100,   104,   110,   116,   118,   120,   124,   126,   128,   130,
     133,   139,   143,   145,   149,   151,   153,   155,   157,   159,
     161,   163,   165,   167,   170,   174,   178,   182,   186,   190,
     194,   198,   202,   206,   210,   214,   218,   222,   226,   230,
     232,   234,   236,   241,   248,   249,   251,   255,   261,   263,
     265,   267,   269,   271,   273,   277,   283,   284,   286,   290,
     296,   300,   301,   303,   305,   309,   310
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      67,     0,    -1,    44,    -1,    55,    -1,    70,    -1,     3,
      79,    66,    -1,    58,    70,    59,    66,    -1,    70,    66,
      -1,    -1,    70,    71,    66,    -1,    72,    -1,    76,    -1,
      77,    -1,    78,    -1,    75,    -1,    29,    66,    -1,    34,
      66,    -1,    34,    84,    66,    -1,    84,    66,    -1,    82,
      49,    84,    66,    -1,    89,    -1,    83,    49,    87,    -1,
      23,    84,    69,    73,    -1,    23,    84,    69,    73,    24,
      70,    -1,    -1,    73,    25,    84,    69,    -1,    27,    79,
      61,    69,    29,    -1,    28,    61,    69,    29,    -1,    74,
      27,    79,    61,    69,    29,    -1,    26,    79,    74,    -1,
      20,    84,    69,    -1,    21,    79,    22,    84,    69,    -1,
      19,    69,    20,    84,    66,    -1,    38,    -1,    79,    -1,
      80,    62,    79,    -1,    18,    -1,    17,    -1,    80,    -1,
      81,    80,    -1,    82,    61,    56,    84,    57,    -1,    82,
      61,    88,    -1,    82,    -1,    83,    63,    82,    -1,    82,
      -1,     4,    -1,     6,    -1,     8,    -1,    15,    -1,    16,
      -1,     7,    -1,     5,    -1,    35,    -1,    43,    84,    -1,
      84,    46,    84,    -1,    84,    45,    84,    -1,    84,    50,
      84,    -1,    84,    51,    84,    -1,    84,    52,    84,    -1,
      84,    53,    84,    -1,    84,    54,    84,    -1,    84,    48,
      84,    -1,    84,    47,    84,    -1,    84,    42,    84,    -1,
      84,    41,    84,    -1,    84,    39,    84,    -1,    84,    40,
      84,    -1,    84,    33,    84,    -1,    64,    84,    60,    -1,
      85,    -1,    93,    -1,    68,    -1,    82,    64,    86,    60,
      -1,    82,    61,    79,    64,    86,    60,    -1,    -1,    87,
      -1,    38,    61,    84,    -1,    87,    63,    38,    61,    84,
      -1,    11,    -1,     9,    -1,    12,    -1,    13,    -1,    14,
      -1,    10,    -1,    30,    80,    90,    -1,    64,    91,    60,
      31,    70,    -1,    -1,    92,    -1,    79,    61,    88,    -1,
      92,    63,    79,    61,    88,    -1,    56,    94,    57,    -1,
      -1,    95,    -1,    96,    -1,    95,    63,    96,    -1,    -1,
      84,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   132,   132,   133,   136,   139,   144,   145,   148,   149,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   166,   167,   169,   170,   173,   174,   175,   177,
     179,   181,   183,   186,   188,   189,   192,   193,   196,   197,
     198,   199,   201,   202,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   235,   236,   238,   239,   241,   242,   245,   246,
     247,   248,   249,   250,   254,   256,   259,   260,   262,   263,
     272,   275,   276,   279,   280,   283,   284
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
  "EQ", "NE", "LE", "GE", "NOT", "ENDL", "OR", "AND", "'<'", "'>'", "'='",
  "'+'", "'-'", "'*'", "'/'", "'%'", "';'", "'['", "']'", "'{'", "'}'",
  "')'", "':'", "'.'", "','", "'('", "$accept", "end_expr", "root",
  "stmt_import", "stmt_block", "stmt_list", "stmt", "stmt_if",
  "elseif_list", "stmt_switch_block", "stmt_switch", "stmt_while",
  "stmt_for", "stmt_repeat", "alone_id", "id_chain", "varlet", "var",
  "var_list", "expr", "func_call", "arg_list", "args", "type",
  "func_decl_named", "func_body", "arg_list_decl", "args_decl",
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
     295,   296,   297,   298,   299,   300,   301,    60,    62,    61,
      43,    45,    42,    47,    37,    59,    91,    93,   123,   125,
      41,    58,    46,    44,    40
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    66,    67,    68,    69,    69,    70,    70,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    72,    72,    73,    73,    74,    74,    74,    75,
      76,    77,    78,    79,    80,    80,    81,    81,    82,    82,
      82,    82,    83,    83,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    85,    85,    86,    86,    87,    87,    88,    88,
      88,    88,    88,    88,    89,    90,    91,    91,    92,    92,
      93,    94,    94,    95,    95,    96,    96
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     4,     2,     0,     3,
       1,     1,     1,     1,     1,     2,     2,     3,     2,     4,
       1,     3,     4,     6,     0,     4,     5,     4,     6,     3,
       3,     5,     5,     1,     1,     3,     1,     1,     1,     2,
       5,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     4,     6,     0,     1,     3,     5,     1,     1,
       1,     1,     1,     1,     3,     5,     0,     1,     3,     5,
       3,     0,     1,     1,     3,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     4,     1,     0,    45,    51,    46,    50,    47,
      48,    49,    37,    36,     8,     0,     0,     0,     0,     0,
       0,     0,    52,    33,     0,    91,     0,    71,     0,    10,
      14,    11,    12,    13,    34,    38,     0,    44,     0,     0,
      69,    20,    70,     0,     8,     0,     0,    44,     8,     0,
       8,     0,     2,     3,    15,     0,    16,     0,    53,    96,
       0,    92,    93,     0,     9,     0,    39,     0,     0,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,     5,     0,     0,
       7,    30,     0,    24,     0,     0,    29,    86,    84,    17,
      90,    95,    68,    35,     0,    79,    83,    78,    80,    81,
      82,     0,     0,    41,     0,     0,    75,    21,    43,    67,
      65,    66,    64,    63,    55,    54,    62,    61,    56,    57,
      58,    59,    60,     0,     0,     8,    22,     0,     8,     0,
       0,     0,    87,    94,    19,     0,    74,     0,    72,     0,
       0,     6,    32,    31,     8,     0,     8,     0,     0,     0,
       0,     0,    40,     0,    76,     0,    23,     8,     0,    27,
       8,    88,     8,     0,    73,     0,    25,    26,     0,    85,
       0,    77,    28,    89
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    54,     1,    27,    45,    46,    28,    29,   136,    96,
      30,    31,    32,    33,    34,    35,    36,    47,    38,    39,
      40,   115,   116,   113,    41,    98,   141,   142,    42,    60,
      61,    62
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -154
static const yytype_int16 yypact[] =
{
    -154,     3,   285,  -154,   -17,  -154,  -154,  -154,  -154,  -154,
    -154,  -154,  -154,  -154,   -28,   393,   -17,   393,   -17,   -40,
     -17,   327,  -154,  -154,   393,   351,   393,  -154,   -40,  -154,
    -154,  -154,  -154,  -154,  -154,   -25,   -17,   -30,   -27,   444,
    -154,  -154,  -154,   -40,  -154,    35,   181,   -22,   400,    40,
     400,    26,  -154,  -154,  -154,   -21,  -154,   444,  -154,   467,
       8,     4,  -154,    97,  -154,   -17,   -25,   393,    47,    30,
      30,    -9,   393,   393,   393,   393,   393,   393,   393,   393,
     393,   393,   393,   393,   393,   393,  -154,  -154,   223,   393,
    -154,  -154,   393,  -154,   -17,     9,    62,   -17,  -154,  -154,
    -154,   393,  -154,  -154,   444,  -154,  -154,  -154,  -154,  -154,
    -154,   393,    32,  -154,    36,    41,    48,    48,    37,    81,
      81,    81,    81,    81,   483,   499,    81,    81,   -41,   -41,
    -154,  -154,  -154,   -40,   444,   400,    39,    51,   -28,   -17,
      53,    42,    52,  -154,  -154,   422,    30,   393,  -154,    61,
      38,  -154,  -154,  -154,  -154,   393,   -28,    88,    57,    95,
      89,   -17,  -154,    65,   467,    60,   285,   400,    99,  -154,
     -28,  -154,  -154,    68,  -154,   393,  -154,  -154,   111,   285,
      95,   467,  -154,  -154
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -154,   -11,  -154,  -154,   -43,     1,  -154,  -154,  -154,  -154,
    -154,  -154,  -154,  -154,    22,   -18,  -154,    -2,  -154,    -1,
    -154,   -20,    71,  -153,  -154,  -154,  -154,  -154,  -154,  -154,
    -154,    55
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -96
static const yytype_int16 yytable[] =
{
      37,     2,    55,     3,    52,    91,   171,    93,    12,    13,
      56,    83,    84,    85,    48,    53,    50,    64,    66,    67,
      57,    23,    70,    58,    59,    63,    43,   183,    86,    23,
      44,    68,    87,   -42,    69,    90,    71,    65,    49,    68,
      51,    65,    69,    97,    37,    88,    99,   105,   106,   107,
     108,   109,   110,    94,    95,    89,   105,   106,   107,   108,
     109,   110,    92,   154,   155,   100,   104,   101,   114,   118,
     138,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    23,    37,   103,   134,   139,
     112,   135,   153,   144,   111,   157,   146,   147,   150,   165,
      59,   148,   160,   111,   105,   106,   107,   108,   109,   110,
     145,   149,   156,   168,   159,   161,   137,   169,   170,   140,
     172,   175,   151,   152,   176,   174,   163,   178,   177,   180,
      72,    81,    82,    83,    84,    85,    73,    74,    75,    76,
     182,   117,    77,    78,    79,    80,   164,    81,    82,    83,
      84,    85,     0,     0,   167,   166,   143,   102,     0,     0,
       0,   158,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,     0,   179,   181,     0,     0,    37,     0,     0,
       0,     0,     0,   173,     4,     5,     6,     7,     8,     9,
       0,     0,     0,     0,     0,     0,    10,    11,    12,    13,
      14,    15,    16,     0,    17,     0,     0,    18,     0,     0,
      19,    20,     0,     0,     0,    21,    22,     0,     0,    23,
       0,     0,     0,     0,    24,    52,     4,     5,     6,     7,
       8,     9,     0,     0,     0,     0,    53,    25,    10,    11,
      12,    13,    14,    15,    16,    26,    17,     0,     0,    18,
       0,     0,    19,    20,     0,     0,     0,    21,    22,     0,
       0,    23,     0,     0,     0,     0,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    25,
       0,     0,   133,     0,     0,     0,     0,    26,     4,     5,
       6,     7,     8,     9,     0,     0,     0,     0,     0,     0,
      10,    11,    12,    13,    14,    15,    16,     0,    17,     0,
       0,    18,     0,     0,    19,    20,     0,     0,     0,    21,
      22,     0,     0,    23,     0,     0,     0,     0,    24,     0,
       4,     5,     6,     7,     8,     9,     0,     0,     0,     0,
       0,    25,    10,    11,    12,    13,     0,     0,     0,    26,
       0,     0,     0,     0,     4,     5,     6,     7,     8,     9,
       0,     0,    22,     0,     0,    23,    10,    11,    12,    13,
      24,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    25,     0,     0,    22,     0,     0,    23,
       0,    26,     0,     0,    24,     0,     4,     5,     6,     7,
       8,     9,     0,     0,     0,     0,     0,    25,    10,    11,
      12,    13,     0,     0,   -95,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    22,     0,
       0,    23,     0,    72,     0,     0,    24,     0,     0,    73,
      74,    75,    76,     0,     0,    77,    78,    79,    80,    25,
      81,    82,    83,    84,    85,    72,     0,    26,    44,     0,
       0,    73,    74,    75,    76,     0,     0,    77,    78,    79,
      80,     0,    81,    82,    83,    84,    85,    72,     0,   162,
       0,     0,     0,    73,    74,    75,    76,     0,    52,    77,
      78,    79,    80,     0,    81,    82,    83,    84,    85,    53,
      72,     0,     0,     0,     0,     0,    73,    74,    75,    76,
       0,     0,    77,    78,    79,    80,    72,    81,    82,    83,
      84,    85,    73,    74,    75,    76,     0,     0,     0,    78,
      79,    80,    72,    81,    82,    83,    84,    85,    73,    74,
      75,    76,     0,     0,     0,     0,    79,    80,     0,    81,
      82,    83,    84,    85
};

static const yytype_int16 yycheck[] =
{
       2,     0,    20,     0,    44,    48,   159,    50,    17,    18,
      21,    52,    53,    54,    15,    55,    17,    28,    36,    49,
      21,    38,    49,    24,    25,    26,     4,   180,    39,    38,
      58,    61,    43,    63,    64,    46,    63,    62,    16,    61,
      18,    62,    64,    64,    46,    44,    57,     9,    10,    11,
      12,    13,    14,    27,    28,    20,     9,    10,    11,    12,
      13,    14,    22,    24,    25,    57,    67,    63,    38,    71,
      61,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    38,    88,    65,    89,    27,
      68,    92,   135,   104,    56,   138,    64,    61,    61,    38,
     101,    60,    60,    56,     9,    10,    11,    12,    13,    14,
     111,    63,    61,   156,    61,    63,    94,    29,    61,    97,
      31,    61,   133,   134,   167,    60,   146,   170,    29,    61,
      33,    50,    51,    52,    53,    54,    39,    40,    41,    42,
      29,    70,    45,    46,    47,    48,   147,    50,    51,    52,
      53,    54,    -1,    -1,   155,   154,   101,    60,    -1,    -1,
      -1,   139,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   172,   175,    -1,    -1,   179,    -1,    -1,
      -1,    -1,    -1,   161,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    -1,    23,    -1,    -1,    26,    -1,    -1,
      29,    30,    -1,    -1,    -1,    34,    35,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    43,    44,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    55,    56,    15,    16,
      17,    18,    19,    20,    21,    64,    23,    -1,    -1,    26,
      -1,    -1,    29,    30,    -1,    -1,    -1,    34,    35,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    59,    -1,    -1,    -1,    -1,    64,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    -1,    23,    -1,
      -1,    26,    -1,    -1,    29,    30,    -1,    -1,    -1,    34,
      35,    -1,    -1,    38,    -1,    -1,    -1,    -1,    43,    -1,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    56,    15,    16,    17,    18,    -1,    -1,    -1,    64,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    -1,    35,    -1,    -1,    38,    15,    16,    17,    18,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    -1,    -1,    35,    -1,    -1,    38,
      -1,    64,    -1,    -1,    43,    -1,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    56,    15,    16,
      17,    18,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      -1,    38,    -1,    33,    -1,    -1,    43,    -1,    -1,    39,
      40,    41,    42,    -1,    -1,    45,    46,    47,    48,    56,
      50,    51,    52,    53,    54,    33,    -1,    64,    58,    -1,
      -1,    39,    40,    41,    42,    -1,    -1,    45,    46,    47,
      48,    -1,    50,    51,    52,    53,    54,    33,    -1,    57,
      -1,    -1,    -1,    39,    40,    41,    42,    -1,    44,    45,
      46,    47,    48,    -1,    50,    51,    52,    53,    54,    55,
      33,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,
      -1,    -1,    45,    46,    47,    48,    33,    50,    51,    52,
      53,    54,    39,    40,    41,    42,    -1,    -1,    -1,    46,
      47,    48,    33,    50,    51,    52,    53,    54,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    47,    48,    -1,    50,
      51,    52,    53,    54
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    67,    70,     0,     3,     4,     5,     6,     7,     8,
      15,    16,    17,    18,    19,    20,    21,    23,    26,    29,
      30,    34,    35,    38,    43,    56,    64,    68,    71,    72,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    89,    93,    79,    58,    69,    70,    82,    84,    79,
      84,    79,    44,    55,    66,    80,    66,    84,    84,    84,
      94,    95,    96,    84,    66,    62,    80,    49,    61,    64,
      49,    63,    33,    39,    40,    41,    42,    45,    46,    47,
      48,    50,    51,    52,    53,    54,    66,    66,    70,    20,
      66,    69,    22,    69,    27,    28,    74,    64,    90,    66,
      57,    63,    60,    79,    84,     9,    10,    11,    12,    13,
      14,    56,    79,    88,    38,    86,    87,    87,    82,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    59,    84,    84,    73,    79,    61,    27,
      79,    91,    92,    96,    66,    84,    64,    61,    60,    63,
      61,    66,    66,    69,    24,    25,    61,    69,    79,    61,
      60,    63,    57,    86,    84,    38,    70,    84,    69,    29,
      61,    88,    31,    79,    60,    61,    69,    29,    69,    70,
      61,    84,    29,    88
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
#line 132 "../bison/swift.y"
    {;;}
    break;

  case 3:
#line 133 "../bison/swift.y"
    {;;}
    break;

  case 4:
#line 136 "../bison/swift.y"
    {;;}
    break;

  case 5:
#line 139 "../bison/swift.y"
    {;;}
    break;

  case 6:
#line 144 "../bison/swift.y"
    {;;}
    break;

  case 7:
#line 145 "../bison/swift.y"
    {;;}
    break;

  case 8:
#line 148 "../bison/swift.y"
    {;;}
    break;

  case 9:
#line 149 "../bison/swift.y"
    {;;}
    break;

  case 10:
#line 152 "../bison/swift.y"
    {;;}
    break;

  case 11:
#line 153 "../bison/swift.y"
    {;;}
    break;

  case 12:
#line 154 "../bison/swift.y"
    {;;}
    break;

  case 13:
#line 155 "../bison/swift.y"
    {;;}
    break;

  case 14:
#line 156 "../bison/swift.y"
    {;;}
    break;

  case 15:
#line 157 "../bison/swift.y"
    {;;}
    break;

  case 16:
#line 158 "../bison/swift.y"
    {;;}
    break;

  case 17:
#line 159 "../bison/swift.y"
    {;;}
    break;

  case 18:
#line 160 "../bison/swift.y"
    {;;}
    break;

  case 19:
#line 161 "../bison/swift.y"
    {;;}
    break;

  case 20:
#line 162 "../bison/swift.y"
    {;;}
    break;

  case 21:
#line 163 "../bison/swift.y"
    {;;}
    break;

  case 22:
#line 166 "../bison/swift.y"
    {;;}
    break;

  case 23:
#line 167 "../bison/swift.y"
    {;;}
    break;

  case 24:
#line 169 "../bison/swift.y"
    {;;}
    break;

  case 25:
#line 170 "../bison/swift.y"
    {;;}
    break;

  case 26:
#line 173 "../bison/swift.y"
    {;;}
    break;

  case 27:
#line 174 "../bison/swift.y"
    {;;}
    break;

  case 28:
#line 175 "../bison/swift.y"
    {;;}
    break;

  case 29:
#line 177 "../bison/swift.y"
    {;;}
    break;

  case 30:
#line 179 "../bison/swift.y"
    {;;}
    break;

  case 31:
#line 181 "../bison/swift.y"
    {;;}
    break;

  case 32:
#line 183 "../bison/swift.y"
    {;;}
    break;

  case 33:
#line 186 "../bison/swift.y"
    {;;}
    break;

  case 34:
#line 188 "../bison/swift.y"
    {;;}
    break;

  case 35:
#line 189 "../bison/swift.y"
    {;;}
    break;

  case 36:
#line 192 "../bison/swift.y"
    {;;}
    break;

  case 37:
#line 193 "../bison/swift.y"
    {;;}
    break;

  case 38:
#line 196 "../bison/swift.y"
    {;;}
    break;

  case 39:
#line 197 "../bison/swift.y"
    {;;}
    break;

  case 40:
#line 198 "../bison/swift.y"
    {;;}
    break;

  case 41:
#line 199 "../bison/swift.y"
    {;;}
    break;

  case 42:
#line 201 "../bison/swift.y"
    {;;}
    break;

  case 43:
#line 202 "../bison/swift.y"
    {;;}
    break;

  case 44:
#line 204 "../bison/swift.y"
    {;;}
    break;

  case 45:
#line 205 "../bison/swift.y"
    {;;}
    break;

  case 46:
#line 206 "../bison/swift.y"
    {;;}
    break;

  case 47:
#line 207 "../bison/swift.y"
    {;;}
    break;

  case 48:
#line 208 "../bison/swift.y"
    {;;}
    break;

  case 49:
#line 209 "../bison/swift.y"
    {;;}
    break;

  case 50:
#line 210 "../bison/swift.y"
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
    {;;}
    break;

  case 61:
#line 221 "../bison/swift.y"
    {;;}
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
#line 235 "../bison/swift.y"
    {;;}
    break;

  case 73:
#line 236 "../bison/swift.y"
    {;;}
    break;

  case 74:
#line 238 "../bison/swift.y"
    {;;}
    break;

  case 75:
#line 239 "../bison/swift.y"
    {;;}
    break;

  case 76:
#line 241 "../bison/swift.y"
    {;;}
    break;

  case 77:
#line 242 "../bison/swift.y"
    {;;}
    break;

  case 78:
#line 245 "../bison/swift.y"
    {;;}
    break;

  case 79:
#line 246 "../bison/swift.y"
    {;;}
    break;

  case 80:
#line 247 "../bison/swift.y"
    {;;}
    break;

  case 81:
#line 248 "../bison/swift.y"
    {;;}
    break;

  case 82:
#line 249 "../bison/swift.y"
    {;;}
    break;

  case 83:
#line 250 "../bison/swift.y"
    {;;}
    break;

  case 84:
#line 254 "../bison/swift.y"
    {;;}
    break;

  case 85:
#line 256 "../bison/swift.y"
    {;;}
    break;

  case 86:
#line 259 "../bison/swift.y"
    {;;}
    break;

  case 87:
#line 260 "../bison/swift.y"
    {;;}
    break;

  case 88:
#line 262 "../bison/swift.y"
    {;;}
    break;

  case 89:
#line 263 "../bison/swift.y"
    {;;}
    break;

  case 90:
#line 272 "../bison/swift.y"
    {;;}
    break;

  case 91:
#line 275 "../bison/swift.y"
    {;;}
    break;

  case 92:
#line 276 "../bison/swift.y"
    {;;}
    break;

  case 93:
#line 279 "../bison/swift.y"
    {;;}
    break;

  case 94:
#line 280 "../bison/swift.y"
    {;;}
    break;

  case 95:
#line 283 "../bison/swift.y"
    {;;}
    break;

  case 96:
#line 284 "../bison/swift.y"
    {;;}
    break;


/* Line 1267 of yacc.c.  */
#line 2191 "swift.tab.c"
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


#line 287 "../bison/swift.y"


