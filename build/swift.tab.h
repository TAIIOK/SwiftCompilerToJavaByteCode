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
#line 181 "swift.tab.h"
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
