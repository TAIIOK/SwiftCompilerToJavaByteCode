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
     INT = 258,
     DOUBLE = 259,
     FOR = 260,
     WHILE = 261,
     END = 262,
     IF = 263,
     ELSE = 264,
     ELSEIF = 265,
     DO = 266,
     THEN = 267,
     REPEAT = 268,
     UNTIL = 269,
     RETURN = 270,
     BREAK = 271,
     FUNCTION = 272,
     LOCAL = 273,
     STRING = 274,
     ID = 275,
     EQ = 276,
     NE = 277,
     LE = 278,
     GE = 279,
     CONCAT = 280,
     TRUE = 281,
     FALSE = 282,
     NIL = 283,
     ENDL = 284,
     OR = 285,
     AND = 286,
     UMINUS = 287,
     NOT = 288
   };
#endif
/* Tokens.  */
#define INT 258
#define DOUBLE 259
#define FOR 260
#define WHILE 261
#define END 262
#define IF 263
#define ELSE 264
#define ELSEIF 265
#define DO 266
#define THEN 267
#define REPEAT 268
#define UNTIL 269
#define RETURN 270
#define BREAK 271
#define FUNCTION 272
#define LOCAL 273
#define STRING 274
#define ID 275
#define EQ 276
#define NE 277
#define LE 278
#define GE 279
#define CONCAT 280
#define TRUE 281
#define FALSE 282
#define NIL 283
#define ENDL 284
#define OR 285
#define AND 286
#define UMINUS 287
#define NOT 288




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

