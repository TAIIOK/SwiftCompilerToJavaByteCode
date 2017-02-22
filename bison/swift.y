%{
    #include <stdio.h>
%}

%token INT
%token DOUBLE
%token FOR
%token WHILE
%token IF
%token ELSE
%token ELSEIF
%token REPEAT
%token RETURN
%token BREAK
%token FUNC
%token LOCAL
%token CONC
%token STRING
%token ID
%token EQ
%token NQ
%token LT
%token GT
%token AND
%token NOT
%token OR
%token END


%%

NUM:    INT
        | DOUBLE
        | NUM '+' NUM
        | NUM '-' NUM
        | NUM '*' NUM
        | NUM '\\' NUM
        | NUM '%' NUM
;

EXPR:    EXPR AND EXPR
         | EXPR OR EXPR
         | NOT EXPR
         | EXPR EQ EXPR
         | EXPR NQ EXPR
         | EXPR '>' EXPR
         | EXPR '<' EXPR
         | EXPR GT EXPR
         | EXPR LT EXPR
         | ID '('ARGS')'
         | ID ARGS
         | ID
         | NUM
         | STRING CONC ID
         | ID CONC STRING
         | '('EXPR')'
         | STRING CONC STRING
         | ID CONC ID
;

ARGS:
         | ARGSN
;

ARGSN:   EXPR
         | ARGSN ',' EXPR
;

OP:      WHILE EXPR STMS END
         | IF EXPR  STMS END
         | IF EXPR  STMS ELSE STMS END
         | IF EXPR  STMS ELSEIF EXPR STMS END
         | FOR ID '=' ID ',' ID  STMS END
         | FOR ID '=' ID ',' NUM  STMS END
         | FOR ID '=' NUM ',' ID  STMS END
         | FOR ID '=' NUM ',' NUM  STMS END
;

STMS:
         | EXPR
         | STMS EXPR
         | STMS OP
         | OP
;