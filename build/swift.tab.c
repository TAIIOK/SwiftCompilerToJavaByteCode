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
#line 1 "../bison/swift.y" /* yacc.c:339  */

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


#line 84 "swift.tab.c" /* yacc.c:339  */

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
   by #include "swift.tab.h".  */
#ifndef YY_YY_SWIFT_TAB_H_INCLUDED
# define YY_YY_SWIFT_TAB_H_INCLUDED
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "../bison/swift.y" /* yacc.c:355  */

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

#line 193 "swift.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
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


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_SWIFT_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 224 "swift.tab.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
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
#define YYLAST   524

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  184

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   129,   129,   130,   133,   136,   141,   142,   145,   146,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   163,   164,   166,   167,   170,   171,   172,   174,
     176,   178,   180,   183,   185,   186,   189,   190,   193,   194,
     195,   196,   198,   199,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   233,   234,   236,   237,   239,   240,   243,   244,
     245,   246,   247,   248,   252,   254,   257,   258,   260,   261,
     270,   273,   274,   277,   278,   281
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "array_constructor", "array_elem_list", "array_elems", "array_elem", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,    60,    62,    61,
      43,    45,    42,    47,    37,    59,    91,    93,   123,   125,
      41,    58,    46,    44,    40
};
# endif

#define YYPACT_NINF -154

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-154)))

#define YYTABLE_NINF -43

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -154,     3,   285,  -154,   -17,  -154,  -154,  -154,  -154,  -154,
    -154,  -154,  -154,  -154,   -28,   351,   -17,   351,   -17,   -40,
     -17,   327,  -154,  -154,   351,   351,   351,  -154,   -40,  -154,
    -154,  -154,  -154,  -154,  -154,   -25,   -17,   -30,   -27,   415,
    -154,  -154,  -154,   -40,  -154,    35,   181,   -22,   371,    40,
     371,    26,  -154,  -154,  -154,   -21,  -154,   415,  -154,   438,
       8,     4,  -154,    97,  -154,   -17,   -25,   351,    47,    30,
      30,    -9,   351,   351,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   351,  -154,  -154,   223,   351,
    -154,  -154,   351,  -154,   -17,     9,    62,   -17,  -154,  -154,
    -154,   351,  -154,  -154,   415,  -154,  -154,  -154,  -154,  -154,
    -154,   351,    32,  -154,    36,    41,    48,    48,    37,    81,
      81,    81,    81,    81,   454,   470,    81,    81,   -41,   -41,
    -154,  -154,  -154,   -40,   415,   371,    39,    51,   -28,   -17,
      53,    42,    52,  -154,  -154,   393,    30,   351,  -154,    61,
      38,  -154,  -154,  -154,  -154,   351,   -28,    88,    57,    95,
      89,   -17,  -154,    65,   438,    60,   285,   371,    99,  -154,
     -28,  -154,  -154,    68,  -154,   351,  -154,  -154,   111,   285,
      95,   438,  -154,  -154
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     4,     1,     0,    45,    51,    46,    50,    47,
      48,    49,    37,    36,     8,     0,     0,     0,     0,     0,
       0,     0,    52,    33,     0,    91,     0,    71,     0,    10,
      14,    11,    12,    13,    34,    38,     0,    44,     0,     0,
      69,    20,    70,     0,     8,     0,     0,    44,     8,     0,
       8,     0,     2,     3,    15,     0,    16,     0,    53,    95,
       0,    92,    93,     0,     9,     0,    39,     0,     0,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,     5,     0,     0,
       7,    30,     0,    24,     0,     0,    29,    86,    84,    17,
      90,     0,    68,    35,     0,    79,    83,    78,    80,    81,
      82,     0,     0,    41,     0,     0,    75,    21,    43,    67,
      65,    66,    64,    63,    55,    54,    62,    61,    56,    57,
      58,    59,    60,     0,     0,     8,    22,     0,     8,     0,
       0,     0,    87,    94,    19,     0,    74,     0,    72,     0,
       0,     6,    32,    31,     8,     0,     8,     0,     0,     0,
       0,     0,    40,     0,    76,     0,    23,     8,     0,    27,
       8,    88,     8,     0,    73,     0,    25,    26,     0,    85,
       0,    77,    28,    89
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -154,   -11,  -154,  -154,   -43,     1,  -154,  -154,  -154,  -154,
    -154,  -154,  -154,  -154,    22,   -18,  -154,    -2,  -154,    -1,
    -154,   -20,    71,  -153,  -154,  -154,  -154,  -154,  -154,  -154,
    -154,    55
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    54,     1,    27,    45,    46,    28,    29,   136,    96,
      30,    31,    32,    33,    34,    35,    36,    47,    38,    39,
      40,   115,   116,   113,    41,    98,   141,   142,    42,    60,
      61,    62
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
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
       0,    26,     0,     0,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    72,     0,     0,    25,     0,     0,
      73,    74,    75,    76,     0,    26,    77,    78,    79,    80,
       0,    81,    82,    83,    84,    85,    72,     0,     0,    44,
       0,     0,    73,    74,    75,    76,     0,     0,    77,    78,
      79,    80,     0,    81,    82,    83,    84,    85,    72,     0,
     162,     0,     0,     0,    73,    74,    75,    76,     0,    52,
      77,    78,    79,    80,     0,    81,    82,    83,    84,    85,
      53,    72,     0,     0,     0,     0,     0,    73,    74,    75,
      76,     0,     0,    77,    78,    79,    80,    72,    81,    82,
      83,    84,    85,    73,    74,    75,    76,     0,     0,     0,
      78,    79,    80,    72,    81,    82,    83,    84,    85,    73,
      74,    75,    76,     0,     0,     0,     0,    79,    80,     0,
      81,    82,    83,    84,    85
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
      -1,    64,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    -1,    56,    -1,    -1,
      39,    40,    41,    42,    -1,    64,    45,    46,    47,    48,
      -1,    50,    51,    52,    53,    54,    33,    -1,    -1,    58,
      -1,    -1,    39,    40,    41,    42,    -1,    -1,    45,    46,
      47,    48,    -1,    50,    51,    52,    53,    54,    33,    -1,
      57,    -1,    -1,    -1,    39,    40,    41,    42,    -1,    44,
      45,    46,    47,    48,    -1,    50,    51,    52,    53,    54,
      55,    33,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    -1,    -1,    45,    46,    47,    48,    33,    50,    51,
      52,    53,    54,    39,    40,    41,    42,    -1,    -1,    -1,
      46,    47,    48,    33,    50,    51,    52,    53,    54,    39,
      40,    41,    42,    -1,    -1,    -1,    -1,    47,    48,    -1,
      50,    51,    52,    53,    54
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
      93,    94,    94,    95,    95,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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
       3,     0,     1,     1,     3,     1
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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
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

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
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
     '$$ = $1'.

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
#line 129 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1598 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 130 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1604 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 133 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1610 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 136 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1616 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 141 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1622 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 142 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1628 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 145 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1634 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 146 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1640 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 149 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1646 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 150 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1652 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 151 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1658 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 152 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1664 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 153 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1670 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 154 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1676 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 155 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1682 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 156 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1688 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 157 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1694 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 158 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1700 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 159 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1706 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 160 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1712 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 163 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1718 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 164 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1724 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 166 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1730 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 167 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1736 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 170 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1742 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 171 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1748 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 172 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1754 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 174 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1760 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 176 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1766 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 178 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1772 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 180 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1778 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 183 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1784 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 185 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1790 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 186 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1796 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 189 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1802 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 190 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1808 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 193 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1814 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 194 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1820 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 195 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1826 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 196 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1832 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 198 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1838 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 199 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1844 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 202 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1850 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 203 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1856 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 204 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1862 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 205 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1868 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 206 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1874 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 207 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1880 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 208 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1886 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 209 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1892 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 210 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1898 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 211 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1904 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 212 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1910 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 213 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1916 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 214 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1922 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 215 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1928 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 216 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1934 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 217 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1940 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 218 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1946 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 219 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1952 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 220 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1958 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 221 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1964 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 222 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1970 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 223 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1976 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 224 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1982 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 225 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1988 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 226 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 1994 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 227 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 2000 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 228 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 2006 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 229 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 2012 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 233 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 2018 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 234 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 2024 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 236 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 2030 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 237 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 2036 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 239 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 2042 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 240 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 2048 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 243 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 2054 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 244 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 2060 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 245 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 2066 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 246 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 2072 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 247 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 2078 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 248 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 2084 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 252 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 2090 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 254 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 2096 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 257 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 2102 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 258 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 2108 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 260 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 2114 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 261 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 2120 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 270 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 2126 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 273 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 2132 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 274 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 2138 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 277 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 2144 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 278 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 2150 "swift.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 281 "../bison/swift.y" /* yacc.c:1646  */
    {;}
#line 2156 "swift.tab.c" /* yacc.c:1646  */
    break;


#line 2160 "swift.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 284 "../bison/swift.y" /* yacc.c:1906  */

