%{
    #include <stdio.h>

%}

%token INT
%token DOUBLE
%token FOR
%token WHILE
%token END
%token IF
%token ELSE
%token ELSEIF
%token DO
%token THEN
%token REPEAT
%token UNTIL
%token RETURN
%token BREAK
%token FUNCTION
%token STRING
%token ID
%token EQ
%token NE
%token LE
%token GE
%token CONCAT
%token TRUE
%token FALSE
%token NIL
%token ENDL
%left  OR
%left  AND
%left  '<' '>' LE GE EQ NE /* < > <= >= == != */
%right CONCAT
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
                    | expr CONCAT expr                                          
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
