%{
    #include <stdio.h>
    #include "swift.tab.h"
    #include "tree_nodes_funcs.h"

    extern int yylex(void);

    void yyerror(const char *s)
    {
        fprintf(stderr,"Line %d: %s\n", yylloc.first_line, s);
        exit(1);
    }

    struct NStmtList* root;
%}

%locations

%start root


%token STRING

%token IMPORT

%token INT
%token CHARACTER
%token STRINGT
%token FLOAT
%token DOUBLE
%token BOOL

%token TRUE
%token FALSE

%token REPEAT
%token WHILE

%token FOR
%token IN

%token IF
%token ELSE
%token ELSEIF

%token SWITCH
%token CASE
%token DEFAULT
%token BREAK

%token FUNCTION
%token FUNCTIONARROW

%token DO
%token RANGE

%token RETURN
%token NIL

%token SELF
%token ERROR

%token ID
%token EQ
%token NE
%token LE
%token GE
%token NOT

%token ENDL
%token END

%left  OR
%left  AND
%left  '<' '>' LE GE EQ NE /* < > <= >= == != */
%left  '+' '-'
%left  '*' '/' '%'

%%
end_expr:             ENDL
                    | ';' opt_endl
;
opt_endl:             /* empty */
                    | ENDL
;
;

root:               stmt_list
;
/* == Statements == */
stmt_list:            /* empty */
                    | stmt_list stmt opt_endl
;
stmt:                 stmt_block
                    | stmt_if
                    | stmt_while
                    | stmt_for
                    | stmt_repeat
                    | BREAK end_expr
                    | RETURN end_expr
                    | RETURN expr end_expr
                    | expr end_expr
                    | var '=' expr end_expr
                    | func_decl_named
                    | end_expr
                    | var_list '=' args
;
stmt_block:           DO stmt_list END opt_endl
;
stmt_if:              IF expr stmt_list elseif_list
                    | IF expr stmt_list elseif_list ELSE stmt_list
;
elseif_list:          /* empty */
                    | elseif_list ELSEIF expr stmt_list
;
stmt_while:           WHILE expr stmt_block
;
stmt_for:             FOR alone_id  ',' expr stmt_block
;
stmt_repeat:          REPEAT stmt_list WHILE expr end_expr
;
/* == Expressions == */
alone_id:             ID
;
id_chain:             alone_id
                    | id_chain '.' alone_id
;
var:                  id_chain
                    | var '[' expr ']'
;
var_list:             var
                    | var_list ',' var
;
expr:                 var
                    | INT
                    | DOUBLE
                    | STRING
                    | TRUE
                    | FALSE
                    | NIL
                    | NOT expr
                    | expr AND expr
                    | expr OR  expr
                    | expr '+' expr
                    | expr '-' expr
                    | expr '*' expr
                    | expr '/' expr
                    | expr '%' expr
                    | expr '>' expr
                    | expr '<' expr
                    | expr GE  expr
                    | expr LE  expr
                    | expr EQ  expr
                    | expr NE  expr
                    | '(' expr ')'
                    | func_call

;
/* == Function call == */
func_call:            var '(' arg_list ')'
                    | var ':' alone_id '(' arg_list ')'
;
arg_list:             /* empty */
                    | args
;
args:                 expr
                    | args ',' expr
;
/* == Function declaration == */

func_decl_named:      FUNCTION id_chain func_body
                    | FUNCTION id_chain ':' alone_id func_body
;
func_body:            '(' arg_list_decl ')' stmt_list END
;
arg_list_decl:        /* empty */
                    | args_decl
;
args_decl:            alone_id
                    | args_decl ',' alone_id
;
%%
