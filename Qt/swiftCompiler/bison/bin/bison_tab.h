
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     DOUBLE = 259,
     STRING = 260,
     CHAR = 261,
     ID = 262,
     INTT = 263,
     CHART = 264,
     UNITT = 265,
     BOOLEANT = 266,
     BYTET = 267,
     LONGT = 268,
     SHORTT = 269,
     UBYTET = 270,
     USHORT = 271,
     UINTT = 272,
     ULONGT = 273,
     DOUBLET = 274,
     TRUE = 275,
     FALSE = 276,
     RETURN = 277,
     WHILE = 278,
     BREAK = 279,
     WHEN = 280,
     ELSE = 281,
     ELSEIF = 282,
     VAL = 283,
     VAR = 284,
     FUN = 285,
     FOR = 286,
     IS = 287,
     IN = 288,
     IF = 289,
     DO = 290,
     ENUM = 291,
     STRICT_EQUALITY = 292,
     NOT_STRICT_EQUALITY = 293,
     NOT_IN = 294,
     NOT_IS = 295,
     INCREMENT = 296,
     DECREMENT = 297,
     AND = 298,
     OR = 299,
     MULTIPLY_ASSIGNMENT = 300,
     DIVIDE_ASSIGNMENT = 301,
     PERCENT_ASSIGNMENT = 302,
     ADDITION_ASSIGNMENT = 303,
     SUBTRACTION_ASSIGNMENT = 304,
     ARROW = 305,
     FATARROW = 306,
     TWO_COLONS = 307,
     TWO_DECIMAL_POINT = 308,
     EQ = 309,
     NE = 310,
     LE = 311,
     GE = 312,
     NOT = 313,
     ENDL = 314,
     RANGE = 315
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 21 "bison.y"

        int Int;
        char* Id;
        char* String;
        double Double;

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
        struct NConstant * Constant;
        struct NVarType * VarType;



/* Line 1676 of yacc.c  */
#line 135 "bison.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


