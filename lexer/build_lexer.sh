#!/bin/bash
flex swift.yy
g++ -c lex.yy.c
g++ lex.yy.o -o lexer

