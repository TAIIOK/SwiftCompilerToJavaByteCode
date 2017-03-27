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
     CHARACTER = 260,
     STRING = 261,
     FLOAT = 262,
     DOUBLE = 263,
     BOOL = 264,
     TRUE = 265,
     FALSE = 266,
     REPEAT = 267,
     WHILE = 268,
     FOR = 269,
     IN = 270,
     IF = 271,
     ELSE = 272,
     ELSEIF = 273,
     SWITCH = 274,
     CASE = 275,
     DEFAULT = 276,
     BREAK = 277,
     FUNCTION = 278,
     FUNCTIONARROW = 279,
     DO = 280,
     RANGE = 281,
     RETURN = 282,
     NIL = 283,
     SELF = 284,
     ERROR = 285,
     ID = 286,
     EQ = 287,
     NE = 288,
     LE = 289,
     GE = 290,
     CONCAT = 291,
     NOT = 292,
     ENDL = 293,
     END = 294,
     OR = 295,
     AND = 296
   };
#endif
/* Tokens.  */
#define IMPORT 258
#define INT 259
#define CHARACTER 260
#define STRING 261
#define FLOAT 262
#define DOUBLE 263
#define BOOL 264
#define TRUE 265
#define FALSE 266
#define REPEAT 267
#define WHILE 268
#define FOR 269
#define IN 270
#define IF 271
#define ELSE 272
#define ELSEIF 273
#define SWITCH 274
#define CASE 275
#define DEFAULT 276
#define BREAK 277
#define FUNCTION 278
#define FUNCTIONARROW 279
#define DO 280
#define RANGE 281
#define RETURN 282
#define NIL 283
#define SELF 284
#define ERROR 285
#define ID 286
#define EQ 287
#define NE 288
#define LE 289
#define GE 290
#define CONCAT 291
#define NOT 292
#define ENDL 293
#define END 294
#define OR 295
#define AND 296




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
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
