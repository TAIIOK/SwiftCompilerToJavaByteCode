%{
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
%}

%union {
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

%locations

%start root



%token IMPORT

%token <Int> INT
%token <Float>FLOAT
%token <Double>DOUBLE
%token <Bool>BOOL
%token <String> STRING

%token STRINGT
%token CHARACTERT
%token INTT
%token FLOATT
%token DOUBLET
%token BOOLT

%token TRUE
%token FALSE

%token LET
%token VAR

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

%token <Id> ID
%token EQ
%token NE
%token LE
%token GE
%token NOT

%token ENDL


%type <SL> stmt_list
%type <SL> root
%type <SL> stmt_block
%type <Expr> expr
%type <Expr> var
%type <Expr> alone_id
%type <Expr> func_call
%type <While> stmt_while
%type <While> stmt_repeat
%type <Stmt> stmt
%type <If> stmt_if
%type <IfL> elseif_list
%type <For> stmt_for
%type <Func> func_decl_named
%type <Func> func_body
%type <Args> id_chain
%type <Args> var_list
%type <Args> arg_list
%type <Args> args
%type <Args> arg_list_decl
%type <Args> args_decl


/*
%type <Func> func_decl_anon
%type <Table> tableconstructor
%type <Table> tbl_elem_list
%type <Table> tbl_elems
%type <TblElem> tbl_elem
*/

%left  OR
%left  AND
%left  '<' '>' LE GE EQ NE RANGE /* < > <= >= == != */
%left  '+' '-'
%left  '*' '/' '%'
%left  NOT
/*UMINUS*/


%%

end_expr:             ENDL
                    | ';'
;

root:               stmt_list
;

stmt_import:          IMPORT ID ENDL
;

/* == Statements == */

stmt_block:          '{' stmt_list '}' end_expr
                    | stmt_list end_expr
;

stmt_list:            /* empty */
                    | stmt_list stmt end_expr
;

stmt:                 stmt_if
                    | stmt_while
                    | stmt_for
                    | stmt_repeat
                    | stmt_switch
                    | BREAK end_expr
                    | RETURN end_expr
                    | RETURN expr end_expr
                    | expr end_expr
                    | var '=' expr end_expr
                    | func_decl_named
                    | var_list '=' args
;

stmt_if:              IF expr stmt_list elseif_list
                    | IF expr stmt_list elseif_list ELSE stmt_list
;
elseif_list:          /* empty */
                    | elseif_list ELSEIF expr stmt_list
;

stmt_switch_block:    CASE alone_id ':'stmt_block BREAK
                      | DEFAULT ':'stmt_block BREAK
                      | stmt_switch_block ENDL CASE alone_id ':'stmt_block BREAK
;
stmt_switch:          SWITCH alone_id stmt_switch_block
;
stmt_while:           WHILE expr stmt_block
;
stmt_for:             FOR alone_id IN expr stmt_block
;
stmt_repeat:          REPEAT stmt_list WHILE expr end_expr
;
/* == Expressions == */
alone_id:             ID
;
id_chain:             alone_id
                    | id_chain '.' alone_id
;

varlet:               VAR
                    | LET
;

var:                  id_chain
                    | varlet id_chain
                    | var '[' expr ']'
                    | var ':' type
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
                    | BOOL
                    | FLOAT
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
                    | expr RANGE expr
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
args:                 ID ':' expr
                    | args ',' ID ':' expr
;

type:                 INTT
                    | STRINGT
                    | FLOATT
                    | DOUBLET
                    | BOOLT
                    | CHARACTERT
;
/* == Function declaration == */

func_decl_named:      FUNCTION id_chain  func_body
;
func_body:            '(' arg_list_decl ')' FUNCTIONARROW stmt_list
;

arg_list_decl:        /* empty */
                    | args_decl
;
args_decl:            alone_id ':' type
                    | args_decl ',' alone_id ':' type
;
%%
