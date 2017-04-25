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
%token FOUNDATIONI


%type <Expr> expr
%type <Expr> var
%type <Expr> alone_id
%type <Expr> func_call
%type <SL> stmt_list
%type <SL> root
%type <SL> stmt_block
%type <While> stmt_while
%type <While> stmt_repeat
%type <Stmt> stmt
%type <If> stmt_if
%type <IfL> elseif_list
%type <For> stmt_for
%type <Func> func_decl_named
%type <Func> func_body
%type <Args> id_chain
%type <Args> arg_list
%type <Args> args
%type <Args> arg_list_decl
%type <Args> args_decl
%type <Table> array_constructor
%type <Table> array_elem_list
%type <Table> array_elems
%type <TblElem> array_elem
%type <Import> stmt_import
%type <Switch> stmt_switch

%left  OR
%left  AND
%left  '<' '>' LE GE EQ NE RANGE  /* < > <= >= == != */
%left  '+' '-'
%left  '*' '/' '%'
%left NOT


%%

end_expr:             ENDL  {;}
                      | ';' opt_endl {;}
;

opt_endl:             /* empty */ {;}
                      | ENDL {;}
;

root:               stmt_list {printf("root\n");}
;

stmt_Foundation:      FOUNDATIONI {printf("foundation\n");}

;

stmt_import:          IMPORT var {printf("import found\n");}
;

/* == Statements == */

stmt_block:          '{' stmt_list '}'  opt_endl  {printf("block found\n");}
;

stmt_list:            /* empty */ { printf("stmt list null found\n");}
                    | stmt_list stmt opt_endl  {printf("stmt list not null\n");}
;

stmt:                 stmt_block {printf("stmt_block\n");}
                    | stmt_if {printf("stmt_if\n");}
                    | stmt_while {printf("stmt_while\n");}
                    | stmt_for {printf("stmt_for\n");}
                    | stmt_repeat {printf("stmt_repeat\n");}
                    | stmt_switch {printf("stmt_switch\n");}
                    | BREAK end_expr {printf("stmt_break\n");}
                    | RETURN end_expr {printf("stmt_return\n");}
                    | RETURN expr end_expr {printf("stmt_return end\n");}
                    | expr end_expr {printf("stmt_expr\n");}
                    | var '=' expr end_expr {printf("line with eq\n");}
                    | func_decl_named {printf("stmt_func decl\n");}
                    | end_expr {printf("end_expr\n");}
;

stmt_if:              IF expr opt_endl stmt_block elseif_list opt_endl {printf("stmt_if_1\n");}
                    | IF expr opt_endl stmt_block elseif_list ELSE stmt_block opt_endl {printf("stmt_if_2\n");}
;
elseif_list:          /* empty */ {printf("empty else if\n");}
                    | elseif_list ELSEIF expr stmt_block {printf("else_if\n");}
;

stmt_switch:          SWITCH expr opt_endl '{' opt_endl switch_cases opt_endl '}' {printf("stmt_switch\n");}
;
switch_cases:         /* nothing */ {printf("empty case\n");}
                      | switch_cases switch_case {printf("switch cases\n");}
;
switch_case:          case_label stmt_list {printf("switch case\n");}
                      | default_label stmt_list {printf("switch case 2\n");}
;
case_label:           CASE expr ':' {printf("case label\n");}
;
default_label:        DEFAULT ':' {printf("default label \n");}

stmt_while:           WHILE expr stmt_block {printf("stmt_while\n");}
;
stmt_for:             FOR alone_id IN expr stmt_block {printf("stmt_for\n");}
;
stmt_repeat:          REPEAT stmt_block WHILE expr   {printf("stmt_repeat\n");}
;
/* == Expressions == */
alone_id:             ID {printf("alone_id\n");}
;
id_chain:             alone_id {printf("id-chain\n");}
                    | id_chain '.' alone_id {printf("id chain class\n");}
;

varlet:               VAR {printf("var \n");}
                    | LET {printf("let\n");}
;

var:                  id_chain {printf("varuble 1\n");}
                    | varlet id_chain {printf("varuble 2\n");}
                    | '[' type ']' '(' ')' {printf("varuble 3\n");}
                    | var ':' '[' type ']' {printf("varuble 4\n");}
                    | var ':' type {printf("varuble 5\n");}
;


expr:                 var {printf("expr var\n");}
                    | INT {printf("expr INT\n");}
                    | DOUBLE {printf("expr DOUBLE\n");}
                    | STRING {printf("expr STRING\n");}
                    | TRUE {printf("expr TRUE\n");}
                    | FALSE {printf("expr FALSE\n");}
                    | BOOL {printf("expr BOOL\n");}
                    | FLOAT {printf("expr FLOAT\n");}
                    | NIL {printf("expr NIL\n");}
                    | NOT expr {printf("not expr ");}
                    | expr NOT {printf("expr not type\n");}
                    | expr AND expr {printf("expr and expr\n");}
                    | expr OR  expr {printf("expr or expr\n");}
                    | expr '+' expr {printf("expr + expr\n");}
                    | expr '-' expr {printf("expr - expr\n");}
                    | expr '*' expr {printf("expr * expr\n");}
                    | expr '/' expr {printf("expr / expr\n");}
                    | expr '%' expr {printf("expr % expr\n");}
                    | expr '>' expr {printf("expr > expr\n");}
                    | expr '<' expr {printf("expr < expr\n");}
                    | expr GE  expr {printf("expr GE expr\n");}
                    | expr LE  expr {printf("expr LE expr\n");}
                    | expr EQ  expr {printf("expr EQ expr\n");}
                    | expr NE  expr {printf("expr NE expr\n");}
                    | expr RANGE expr {printf("expr RANGE expr\n");}
                    | '(' expr ')' {printf("(expr)\n");}
                    | func_call {printf("expr func_call\n");}
                    | array_constructor {printf("expr array_constructor\n");}
                    | stmt_import {printf("expr stmt_import\n");}
                    | stmt_Foundation {printf("expr stmt_Foundation\n");}

;
/* == Function call == */
func_call:            var '(' arg_list ')' {printf("function call\n");}
;
arg_list:             /* empty */ {printf("arg_list empty\n");}
                    | args {printf("arg_list args \n");}
;
args:                 expr  {printf("args expr\n");}
                    | alone_id ':' expr {printf("args id : expr\n");}
                    | args ',' alone_id ':' expr {printf("args , id : expr\n");}
;

type:                 INTT {printf("int type\n");}
                    | STRINGT {printf("string type\n");}
                    | FLOATT {printf("float type\n");}
                    | DOUBLET {printf("double type\n");}
                    | BOOLT {printf("bool type\n");}
                    | CHARACTERT {printf("character type\n");}
;
/* == Function declaration == */

func_decl_named:      FUNCTION id_chain  func_body {printf("func decl name\n");}
;
func_body:            '(' arg_list_decl ')' FUNCTIONARROW type stmt_block {printf("function body\n");}
;

arg_list_decl:        /* empty */ {printf("arg list decl empty\n");}
                    | args_decl {;} {printf("arg list decl \n");}
;
args_decl:            alone_id ':' type {printf("args decl 1 \n");}
                    | args_decl ',' alone_id ':' type { printf("args decl 2 \n");}
;

/* == Array declaration == */

/* var massive:[Int] = []
var someInts = [Int]() */


array_constructor:  '[' array_elem_list ']' {printf("array constructor");}
;

array_elem_list:        /* empty */ {printf("array elem list empty \n");}
                    | array_elems {printf("array elems list \n");}
;

array_elems:            array_elem {printf("array elem 1 \n");}
                    | array_elems ',' array_elem {printf("array elem more \n");}
;

array_elem:          expr {printf("array elem array elem \n");}
;

%%
