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
    struct NConstant * Constant;
    struct NCase * Case;
    struct NLabelCase * LabelCase;
    struct NCaseList * CaseL;
    struct NVarType * VarType;

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
%type <VarType> type
%type <Constant> varlet
%type <Case> switch_case
%type <CaseL> switch_cases
%type <LabelCase> case_label
%type <LabelCase> default_label

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

root:               stmt_list {printf("root\n");root=$1; $$=$1;}
;

stmt_import:          IMPORT var {printf("import found\n");$$ = create_import($2);}
;

/* == Statements == */

stmt_block:          '{' stmt_list '}'  opt_endl  {printf("block found\n");$$ = $2;}
;

stmt_list:            /* empty */ { printf("stmt list null found\n");$$ = create_stmt_list(NULL);}
                    | stmt_list stmt opt_endl  {printf("stmt list not null\n");$$ = add_stmt_to_list($1, $2);}
;

stmt:                 stmt_block {printf("stmt_block\n");$$ = create_stmt_block($1);}
                    | stmt_if {printf("stmt_if\n");$$ = create_stmt_if($1);}
                    | stmt_while {printf("stmt_while\n");$$ = create_stmt_while($1, 0);}
                    | stmt_for {printf("stmt_for\n");$$ = create_stmt_for($1);}
                    | stmt_repeat {printf("stmt_repeat\n");$$ = create_stmt_while($1, 1);}
                    | stmt_switch {printf("stmt_switch\n");$$ = create_stmt_switch($1);}
                    | BREAK end_expr {printf("stmt_break\n");$$ = create_stmt_spec(0);}
                    | RETURN end_expr {printf("stmt_return\n");$$ = create_stmt_spec(1);}
                    | RETURN expr end_expr {printf("stmt_return end\n");$$ = create_stmt_return($2);}
                    | expr end_expr {printf("stmt_expr\n");$$ = create_stmt_expr($1);}
                    | var '=' expr end_expr {printf("line with eq\n"); $$ = create_stmt_assign($1, $3, 0);}
                    | func_decl_named {printf("stmt_func decl\n");$$ = create_stmt_func($1);}
                    | end_expr {printf("end_expr\n");$$ = create_stmt_spec(2);}
                    | stmt_import {printf("stmt_import\n");$$ = create_stmt_import($1);}
;

stmt_if:              IF expr opt_endl stmt_block elseif_list opt_endl {printf("stmt_if_1\n");$$ = create_if($2, $4, $5, create_stmt_list(NULL));}
                    | IF expr opt_endl stmt_block elseif_list ELSE stmt_block opt_endl {printf("stmt_if_2\n");$$ = create_if($2, $4, $5, $7);}
;
elseif_list:          /* empty */ {printf("empty else if\n");$$ = create_if_list(NULL); }
                    | elseif_list ELSEIF expr stmt_block {printf("else_if\n");$$ = add_if_to_list($1, create_if($3, $4, create_if_list(NULL), create_stmt_list(NULL)));}
;

stmt_switch:          SWITCH expr opt_endl '{' opt_endl switch_cases opt_endl '}' {printf("stmt_switch\n");$$ = create_switch($2,$6);}
;
switch_cases:         /* nothing */ {printf("empty case\n");$$ = create_case_list(NULL);}
                      | switch_cases switch_case {printf("switch cases\n");$$ = add_case_to_list($1,$2);}
;
switch_case:          case_label stmt_list {printf("switch case\n");$$ = create_case($1,$2);}
                      | default_label stmt_list {printf("switch case 2\n");$$ = create_case($1,$2);}
;
case_label:           CASE expr ':' {printf("case label\n");$$ = create_label_case($2,DIFFERENT);}
;
default_label:        DEFAULT ':' {printf("default label \n");$$ = create_label_case(NULL,DEFAULTT);}

stmt_while:           WHILE expr stmt_block {printf("stmt_while\n");$$ = create_while($2, $3);}
;
stmt_for:             FOR alone_id IN expr stmt_block {printf("stmt_for\n");$$ = create_for($2, $4, $5, create_expr_int(1));}
;
stmt_repeat:          REPEAT stmt_block WHILE expr   {printf("stmt_repeat\n");$$ = create_while($4, $2); }
;
/* == Expressions == */
alone_id:             ID {printf("alone_id\n");$$ = create_expr_id(yylval.Id);}
;
id_chain:             alone_id {printf("id-chain\n");$$ = create_expr_list($1);}
                    | id_chain '.' alone_id {printf("id chain class\n");$$ = add_expr_to_list($1, $3); }
;

varlet:               VAR {printf("var \n"); $$ = create_var_constant_type(VART);}
                    | LET {printf("let\n"); $$ = create_var_constant_type(LETT);}
;

var:                  id_chain {printf("varuble 1\n"); $$ = create_expr_exprlist($1); }
                    | varlet id_chain {printf("varuble 2\n");$$ = create_expr_exprlist($2); }
                    | '[' type ']' '(' ')' {printf("varuble 3\n");}
                    | var ':' '[' type ']' {printf("varuble 4\n");}
                    | varlet id_chain ':' type {printf("varuble 5\n");$$ = create_expr_exprlist($2);}



;


expr:                 var {printf("expr var\n");$$ = $1;}
                    | INT {printf("expr INT\n"); $$ = create_expr_int(yylval.Int);}
                    | DOUBLE {printf("expr DOUBLE\n"); $$ = create_expr_double(yylval.Double);}
                    | STRING {printf("expr STRING\n"); $$ = create_expr_string(yylval.String);}
                    | TRUE {printf("expr TRUE\n"); $$ = create_expr_boolean(1);}
                    | FALSE {printf("expr FALSE\n"); $$ = create_expr_boolean(0); }
                    | BOOL {printf("expr BOOL\n");}
                    | FLOAT {printf("expr FLOAT\n");}
                    | NIL {printf("expr NIL\n");$$ = create_expr_nil(); }
                    | NOT expr {printf("not expr "); $$ = create_op_expr(EXPR_NOT, $2, NULL);}
                    | expr NOT {printf("expr not type\n");}
                    | expr AND expr {printf("expr and expr\n");$$ = create_op_expr(EXPR_AND, $1, $3);}
                    | expr OR  expr {printf("expr or expr\n"); $$ = create_op_expr(EXPR_OR, $1, $3);}
                    | expr '+' expr {printf("expr + expr\n"); $$ = create_op_expr(EXPR_PLUS, $1, $3);}
                    | expr '-' expr {printf("expr - expr\n"); $$ = create_op_expr(EXPR_MINUS, $1, $3);}
                    | expr '*' expr {printf("expr * expr\n"); $$ = create_op_expr(EXPR_MUL, $1, $3);}
                    | expr '/' expr {printf("expr / expr\n"); $$ = create_op_expr(EXPR_DIV, $1, $3);}
                    | expr '%' expr {printf("expr % expr\n"); $$ = create_op_expr(EXPR_MOD, $1, $3);}
                    | expr '>' expr {printf("expr > expr\n"); $$ = create_op_expr(EXPR_GT, $1, $3);}
                    | expr '<' expr {printf("expr < expr\n"); $$ = create_op_expr(EXPR_LT, $1, $3);}
                    | expr GE  expr {printf("expr GE expr\n"); $$ = create_op_expr(EXPR_GE, $1, $3);}
                    | expr LE  expr {printf("expr LE expr\n"); $$ = create_op_expr(EXPR_LE, $1, $3);}
                    | expr EQ  expr {printf("expr EQ expr\n"); $$ = create_op_expr(EXPR_EQ, $1, $3);}
                    | expr NE  expr {printf("expr NE expr\n"); $$ = create_op_expr(EXPR_NQ, $1, $3);}
                    | expr RANGE expr {printf("expr RANGE expr\n"); $$ = create_op_expr(EXPR_RANGE, $1, $3);}
                    | '(' expr ')' {printf("(expr)\n"); $$ = $2;}
                    | func_call {printf("expr func_call\n"); $$ = $1;}
                    | array_constructor {printf("expr array_constructor\n"); $$ = create_expr_table($1);}

;
/* == Function call == */
func_call:            var '(' arg_list ')' {printf("function call\n"); $$ = create_op_expr(EXPR_MET, $1, create_expr_exprlist($3));}
;
arg_list:             /* empty */ {printf("arg_list empty\n");$$ = create_expr_list(NULL);}
                    | args {printf("arg_list args \n");$$ = $1;}
;
args:                 expr  {printf("args expr\n"); $$ = create_expr_list($1);}
                    | id_chain ':' expr {printf("args id : expr\n");$$ = add_expr_to_list($1, $3);}
                    | args ',' alone_id ':' expr {printf("args , id : expr\n");$$ = add_expr_to_list($1, $3);}
;

type:                 INTT {printf("int type\n");$$ = create_var_type(INTTy);}
                    | STRINGT {printf("string type\n");$$ = create_var_type(STRINGTy);}
                    | FLOATT {printf("float type\n");$$ = create_var_type(FLOATTy);}
                    | DOUBLET {printf("double type\n");$$ = create_var_type(DOUBLETy);}
                    | BOOLT {printf("bool type\n");$$ = create_var_type(BOOLTy);}
                    | CHARACTERT {printf("character type\n");$$ = create_var_type(CHARACTERTy);}
;
/* == Function declaration == */

func_decl_named:      FUNCTION id_chain  func_body {printf("func decl name\n");$$ = set_func_name($2, $3);}
;
func_body:            '(' arg_list_decl ')' FUNCTIONARROW type stmt_block {printf("function body\n");$$ = create_func($2, $6,$5);}
                    |  '(' arg_list_decl ')'  stmt_block {printf("function body\n");$$ = create_func($2, $4,create_var_type(VOIDTy));}
;

arg_list_decl:        /* empty */ {printf("arg list decl empty\n");$$ = create_expr_list(NULL);}
                    | args_decl {;} {printf("arg list decl \n");$$ = $1;}
;
args_decl:            alone_id ':' type {printf("args decl 1 \n");$$ = create_expr_list($1);}
                    | args_decl ',' alone_id ':' type { printf("args decl 2 \n"); $$ = add_expr_to_list($1, $3);}
;

/* == Array declaration == */

/* var massive:[Int] = []
var someInts = [Int]() */


array_constructor:  '[' array_elem_list ']' {printf("array constructor");$$ = $2;}
;

array_elem_list:        /* empty */ {printf("array elem list empty \n");$$ = create_table(NULL);}
                    | array_elems {printf("array elems list \n"); $$ = $1;}
;

array_elems:            array_elem {printf("array elem 1 \n"); $$ = create_table($1);}
                    | array_elems ',' array_elem {printf("array elem more \n"); $$ = add_elem_to_table($1, $3);}
;

array_elem:          expr {printf("array elem array elem \n");$$ = create_tbl_elem(NULL, $1); }
;

%%
