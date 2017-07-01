/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */
#line 171 "swift.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

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

extern YYLTYPE yylloc;
