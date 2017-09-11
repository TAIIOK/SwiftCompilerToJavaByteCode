/**
 * @file semantic_tables.h
 * Provides functions to create various tables (e. g. constants,
 * local variables) for .class files.
 */

#ifndef _H_SEMANTIC_TABLES_
#define _H_SEMANTIC_TABLES_

#include "tree_nodes.h"

#include <iostream>
#include <list>     // подключаем заголовок списка
#include <iterator> // заголовок итераторов
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;


enum st_const_types {
        CONST_UTF8      = 1,
        CONST_DOUBLE    = 2,
        CONST_INT       = 3,
        CONST_FLOAT     = 4,
        CONST_CLASS     = 7,
        CONST_STRING    = 8,
        CONST_FIELDREF  = 9,
        CONST_METHODREF = 10,
        CONST_NAMETYPE  = 12,
        CONST_FUNCTION   = 13,
        CONST_NULL = -1
};


typedef struct st_const STConst;
struct st_const {
        enum st_const_types type;
        union {
                char * utf8;
                struct {
                        int arg1;
                        int arg2;
                } args;

                int val_int;
                float val_float;
                double val_double;
        } value;

        STConst * next;
};

void st_stmt_list(struct NStmtList * node);
void st_stmt(struct NStmt * node);
void st_stmt_while(struct NWhile * node);
void st_stmt_for(struct NFor * node);
void st_stmt_func(struct NStmt * node);
void st_stmt_if(struct NIf * node);
void st_stmt_expr(struct NExpr * node);
void st_stmt_switch_list(struct NCaseList * node);
void st_stmt_switch(struct NSwitch * node);
int st_constant_index(enum st_const_types type, const void * value);
int st_constant_index2(STConst * table, enum st_const_types type, int arg1, int arg2);
void st_print_const();
void st_print_const_file(FILE *  output);
void printLocalVars();
void printLocalVars_file(FILE *  output);
char * st_type_name(enum st_const_types type, char name[10]);
int    nexprlist_count(NExprList * start);
char * st_gen_func_handle(NFunc * f, char * buffer);
char * get_function_args(struct NFunc * f);
char * update_varuble(NStmtList *root,NExpr *var);
void mult_declaration(NStmtList *root,NExpr *var);
void collect_functions(struct NStmtList * node);
void printTable();
char * return_Expr_Init_Type(NExpr *var);
char * return_varuble_type(NExpr *var);
//############################################################################//

list<st_const> table;
list<NFunc> functions_list;
list<NExpr> function_call;
list<NFunc> main_functions_list;
list<st_const> Main_table;
list<NExpr> Main_varubles;
NStmtList *globalroot;
NStmtList *rootwithoutfunc;




list<NExpr *> create_stack_operation(NExpr *var){
        list<NExpr *> var_stack;

        if(var->left->type==EXPR_MINUS ||var->left->type==EXPR_PLUS || var->left->type==EXPR_MUL || var->left->type==EXPR_DIV || var->left->type==EXPR_MOD) {
                list<NExpr *> temp = create_stack_operation(var->left);
                var_stack.insert(var_stack.end(), temp.begin(), temp.end());
                temp.clear();
        }
        else{
                var_stack.push_back(var->left);
        }

        if(var->right->type==EXPR_MINUS ||var->right->type==EXPR_PLUS || var->right->type==EXPR_MUL || var->right->type==EXPR_DIV || var->right->type==EXPR_MOD) {
                list<NExpr *> temp = create_stack_operation(var->right);
                var_stack.insert(var_stack.end(), temp.begin(), temp.end());
                temp.clear();
        }
        else{
                var_stack.push_back(var->right);
        }

        return var_stack;
}

char * check_stack_operation(list <NExpr *> operations){
        char * type =  (char*)malloc(sizeof(char)*33);
        if(operations.front()->type != EXPR_ID_LIST && operations.front()->type != EXPR_ID)
        {
                strcpy(type,return_Expr_Init_Type(operations.front()));
        }
        else{
                strcpy(type,update_varuble(globalroot,operations.front()));
        }


        for (auto op : operations)
        {

                if(op->type != EXPR_ID_LIST && op->type != EXPR_ID)
                {

                        if(strcmp(type,return_Expr_Init_Type(op)) != 0)
                        {

                                printf("1Varuble have wrong type or not declarate\n");
                                exit(EXIT_FAILURE);
                        }
                }
                else{

                        if(strcmp(type,update_varuble(globalroot,op)) != 0)
                        {
                                printf("2Varuble have wrong type or not declarate\n");
                                exit(EXIT_FAILURE);
                        }
                }
        }

        return type;
}

void check_equal(char *left,char *right){
        printf("%s left\n",left);
        printf("%s right\n",right);

        if(strcmp("A ",right) == 0)
        {

          return;
        }

        if(strcmp("D ",left) == 0 || strcmp("F ",left) == 0)
        {
                if(strcmp("F ",right) == 0 || strcmp("D ",right) == 0 || strcmp("I ",right) == 0)
                {
                        return;
                }
        }

        if(strcmp(left,right) != 0)
        {
                printf("Wrong equal TYPE\n");
                exit (EXIT_FAILURE);
        }
        return;
}
void mult_declaration(NStmtList *root,NExpr *var){
        int count = 0;

        struct NStmt * current = root->first;
        printf("%d VAR Type of statement\n",var->type );
        while (current != NULL) {
                if(current->type == STMT_BLOCK)
                {
                        struct NStmtList* result = (NStmtList*)malloc(sizeof(NStmtList));
                        result->first = current;
                        update_varuble(result,var);
                }

                if(current->type == STMT_ASSIGN && var->type == EXPR_ID_LIST) {
                        if(strcmp(var->idlist->first->name,current->var->idlist->first->name)==0)
                        {
                                if(current->var->vartype != NULL && current->var->varconstant != NULL) {
                                        if(var->vartype != NULL)
                                        {
                                                if(var->vartype->type != NULL)
                                                {
                                                        if(var->vartype->type ==current->var->vartype->type)
                                                        {
                                                                count++;
                                                        }
                                                        else{

                                                        }
                                                }
                                        }
                                }
                        }
                }
                current = current->next;
        }

        if(count > 1)
        {
                printf("Varuble have double declaration\n");
                exit(EXIT_FAILURE);
        }
}
char * return_varuble_type(NExpr *var){
        char * str = (char*)malloc(sizeof(char)*33);
        switch (var->vartype->type) {
        case INTTy:       strcat(str,"I ");    break;
        case FLOATTy:     strcat(str,"F ");    break;
        case DOUBLETy:    strcat(str,"D ");    break;
        case BOOLTy:      strcat(str,"B ");    break;
        case STRINGTy:    strcat(str,"S ");    break;
        case VOIDTy:      strcat(str,"V ");     break;
        case ARRAYTy:      strcat(str,"A ");     break;
        default:          printf("==WTF?== "); break;
        }
        return str;
}
char * return_Expr_Init_Type(NExpr *var){
        if(var->type != EXPR_ID_LIST && var->type != EXPR_ID)
        {
                switch (var->type ) {
                case EXPR_BOOL:
                        return "B ";
                        break;
                case EXPR_INT:
                        return "I ";
                        break;
                case EXPR_FLOAT:
                        return "F ";
                        break;
                case EXPR_DOUBLE:
                        return "D ";
                        break;
                case EXPR_STR:
                        return "S ";
                default:
                        break;

                }

        }
        return "";
}
char * update_varuble(NStmtList *root,NExpr *var){

        if(var->type == EXPR_TABLE)
        {
          char * str = (char*)malloc(sizeof(char)*33);
          strcat(str,return_varuble_type(var));

          return str;
        }

        if(var->type != EXPR_ID_LIST && var->type != EXPR_ID)
        {
                return return_Expr_Init_Type(var);
        }

        bool exist = false;
        struct NStmt * current = root->first;
        printf("%d VAR Type of statement\n",var->type );
        while (current != NULL) {
                printf("%d Type of statement\n",current->type );

                if(current->type == STMT_FUNC)
                {
                        struct NStmt * currentf = current->func->body->first;
                        while(currentf != NULL)
                        {
                                if(currentf->type == STMT_ASSIGN && var->type == EXPR_ID_LIST)
                                {
                                        if(strcmp(var->idlist->first->name,currentf->var->idlist->first->name)==0)
                                        {
                                                exist = true;
                                                printf("Founded need Varuble\n");

                                                STConst name;
                                                name.next = NULL;
                                                name.type = CONST_UTF8;
                                                name.value.utf8  = currentf->var->idlist->first->name;
                                                table.push_back(name);
                                                printf("name %s\n",currentf->var->idlist->first->name);
                                                mult_declaration(globalroot,var);
                                                printf("Varuble found var->type %d\n",currentf->var->type);
                                                printf("Varuble found var->idlist->first->type %d\n",currentf->var->idlist->first->type);
                                                if(currentf->var->vartype != NULL) {
                                                        if(var->vartype != NULL)
                                                        {
                                                                if(var->vartype->type != NULL)
                                                                {
                                                                        if(var->vartype->type !=currentf->var->vartype->type)
                                                                        {
                                                                                printf("Varuble have double declaration\n");
                                                                                exit(EXIT_FAILURE);
                                                                        }
                                                                }
                                                        }
                                                        printf("Varuble found current->var->vartype->type %d\n",currentf->var->vartype->type);
                                                        exist = true;
                                                        char * str = (char*)malloc(sizeof(char)*33);;
                                                        strcat(str,return_varuble_type(currentf->var));

                                                        STConst type_var;
                                                        type_var.next = NULL;
                                                        type_var.type = CONST_UTF8;
                                                        type_var.value.utf8  = str;
                                                        table.push_back(type_var);

                                                        STConst name_type;
                                                        name_type.next = NULL;
                                                        name_type.type = CONST_NAMETYPE;
                                                        name_type.value.args.arg1 = table.size() - 2;
                                                        name_type.value.args.arg2 = table.size() - 1;
                                                        table.push_back(name_type);

                                                        STConst method_ref;
                                                        method_ref.next = NULL;
                                                        method_ref.type = CONST_METHODREF;
                                                        method_ref.value.args.arg1 = 3;
                                                        method_ref.value.args.arg2 = table.size() - 1;
                                                        table.push_back(method_ref);



                                                        return str;
                                                        break;
                                                }

                                        }

                                }
                                currentf = currentf->next;
                        }
                }

                if(current->type == STMT_BLOCK)
                {
                        struct NStmtList* result = (NStmtList*)malloc(sizeof(NStmtList));
                        result->first = current;
                        if  ( strstr(update_varuble(result,var), "") == 0 )
                        {
                                return update_varuble(result,var);
                        }
                }

                if(var->type == EXPR_ID  && current->type == STMT_ASSIGN)
                {
                        if(strcmp(current->var->idlist->first->name, var->name) == 0  && strlen(current->var->idlist->first->name) == strlen(var->name))
                        {
                              printf("YA EBAL SSSSSSSSS\n" );
                                exist = true;
                        }
                }
                if(current->type == STMT_ASSIGN && var->type == EXPR_ID_LIST) {
                        if(strcmp(var->idlist->first->name,current->var->idlist->first->name)==0)
                        {
                                exist = true;
                                printf("Founded need Varuble\n");

                                printf("name %s\n",current->var->idlist->first->name);
                                mult_declaration(globalroot,var);
                                printf("Varuble found var->type %d\n",current->var->type);
                                printf("Varuble found var->idlist->first->type %d\n",current->var->idlist->first->type);
                                if(current->var->vartype != NULL) {
                                        if(var->vartype != NULL)
                                        {
                                                if(var->vartype->type != NULL)
                                                {
                                                        if(var->vartype->type != current->var->vartype->type)
                                                        {
                                                                printf("Varuble have double declaration\n");
                                                                exit(EXIT_FAILURE);
                                                        }
                                                }
                                        }
                                        printf("Varuble found current->var->vartype->type %d\n",current->var->vartype->type);
                                        exist = true;

                                        char * str = (char*)malloc(sizeof(char)*33);
                                        strcat(str,return_varuble_type(current->var));

                                        if (st_constant_index(CONST_UTF8, (void *)(current->var->idlist->first->name)) == -1) {
                                                STConst name;
                                                name.next = NULL;
                                                name.type = CONST_UTF8;
                                                name.value.utf8  = current->var->idlist->first->name;
                                                table.push_back(name);

                                                STConst type_var;
                                                type_var.next = NULL;
                                                type_var.type = CONST_UTF8;
                                                type_var.value.utf8  = str;
                                                table.push_back(type_var);

                                                STConst name_type;
                                                name_type.next = NULL;
                                                name_type.type = CONST_NAMETYPE;
                                                name_type.value.args.arg1 = table.size() - 2;
                                                name_type.value.args.arg2 = table.size() - 1;
                                                table.push_back(name_type);

                                                STConst method_ref;
                                                method_ref.next = NULL;
                                                method_ref.type = CONST_FIELDREF;
                                                method_ref.value.args.arg1 = 3;
                                                method_ref.value.args.arg2 = table.size() - 1;
                                                table.push_back(method_ref);
                                        }

                                        if(strcmp(str,"") == 0)
                                        {
                                                printf("Varuble doest exist\n");
                                                exit(EXIT_FAILURE);

                                        }

                                        return str;
                                        break;
                                }
                                else {
                                        exist = false;
                                }

                                if(current->var->varconstant != NULL) {
                                        printf("Varuble found var->varconstant %d\n",current->var->varconstant->constant);
                                }
                                if(current->expr->type != NULL && exist)
                                {
                                    if(current->expr->isArray == true)
                                    {
                                      return "return_Expr_Init_Type(current->expr)";
                                    }
                                        return return_Expr_Init_Type(current->expr);
                                }
                                printf("Varuble found expr->type %d\n",current->expr->type);
                                break;


                        }
                }



                current = current->next;
        }
        if(!exist) {
                printf("Varuble doest exist\n");
                exit (EXIT_FAILURE);
        }

        return "";
}
bool check_return_function(NStmtList *root,char * type){
        bool result = false;
        bool inbodyresult = false;
        char * str = (char*)malloc(sizeof(char)*33);
        char * strbody = (char*)malloc(sizeof(char)*33);
        struct NStmt * current = root->first;

        while (current != NULL && !result) {

                switch (current->type) {
                case STMT_WHILE: result = check_return_function(current->while_loop->body,type);                  break;
                case STMT_FOR:   result =check_return_function(current->for_loop->body,type);                      break;
                case STMT_EXPR:                           break;
                case STMT_BLOCK: result = check_return_function(current->list,type);                         break;
                case STMT_REPEAT: result = check_return_function(current->while_loop->body,type);                  break;
                case STMT_RETURN:
                        if (current->expr != NULL )
                        {

                                if(current->expr->type != EXPR_ID_LIST && current->expr->type != EXPR_ID)
                                {

                                        strcat(str,return_Expr_Init_Type(current->expr));
                                }
                                else{
                                        strcpy(str,update_varuble(globalroot,current->expr));
                                }


                                if(strcmp("D ",type) == 0 || strcmp("F ",type) == 0)
                                {
                                        if(strcmp("F ",str) == 0 || strcmp("D ",str) == 0 || strcmp("I ",str) == 0)
                                        {
                                                result = true;;
                                        }
                                        else{
                                                result = false;
                                        }
                                }

                                else if(strcmp(str,type) == 0)
                                {
                                        result = true;
                                }
                                else{
                                        printf("Return doesnot exist or wrong return value");
                                        exit(EXIT_FAILURE);
                                        result = false;
                                }



                        }
                        else if(strcmp(type, "V ") == 0)
                        {
                                result = true;
                        }
                        break;
                case STMT_IF:

                        result = check_return_function(current->if_tree->body,type);

                        struct NIf* currentif = current->if_tree->elseiflist->first;

                        while (currentif != NULL && !result)
                        {
                                result = check_return_function(currentif->body,type);
                                currentif = currentif->next;
                        }

                        if(!result)
                                result = check_return_function(current->if_tree->elsebody,type);

                        break;

                }
                current = current->next;
        }


        struct NStmt * currentbody = root->first;

        while (currentbody != NULL && !inbodyresult )
        {
                if(currentbody->type == STMT_RETURN) {

                        if (currentbody->expr != NULL )
                        {

                                if(currentbody->expr->type != EXPR_ID_LIST && currentbody->expr->type != EXPR_ID)
                                {
                                        strcat(strbody,return_Expr_Init_Type(currentbody->expr));

                                }
                                else{
                                        strcat(strbody,update_varuble(globalroot,currentbody->expr));
                                }

                                if(strcmp("D ",type) == 0 || strcmp("F ",type) == 0)
                                {
                                        if(strcmp("F ",strbody) == 0 || strcmp("D ",strbody) == 0 || strcmp("I ",strbody) == 0)
                                        {
                                                inbodyresult = true;;
                                        }
                                        else{
                                                inbodyresult = false;
                                        }
                                }

                                else if(strcmp(strbody,type) == 0)
                                {
                                        inbodyresult = true;
                                }
                                else{
                                        inbodyresult = false;
                                }

                        }
                }
                currentbody = currentbody->next;
        }

        if(strcmp(type, "V ") == 0)
        {
                return true;
        }
        else if (result && inbodyresult) {
                return true;
        }
        else if (inbodyresult) {
                return true;
        }
        else {
                return false;
        }



        return result;
}
char * get_function_type(struct NFunc * f){
        if(strcmp("readLine",f->name->last->name) == 0)
        {
                return "S ";
        }
        char * str = (char*)malloc(sizeof(char)*33);;

        switch (f->vartype->type) {
        case INTTy:       strcat(str,"I ");    break;
        case FLOATTy:     strcat(str,"F ");    break;
        case DOUBLETy:    strcat(str,"D ");    break;
        case BOOLTy:      strcat(str,"B ");    break;
        case STRINGTy:    strcat(str,"S ");    break;
        case VOIDTy:      strcat(str,"V ");     break;
        default:          printf("==WTF?== "); break;
        }
        return str;
}
void check_function_args(struct NExpr * cur){

        if (strcmp(cur->left->idlist->first->name, "print") == 0 )
        {
                if(cur->right->idlist->first != NULL) {
                        if(cur->right->idlist->first->type==EXPR_MINUS ||cur->right->idlist->first->type==EXPR_PLUS || cur->right->idlist->first->type==EXPR_MUL || cur->right->idlist->first->type==EXPR_DIV || cur->right->idlist->first->type==EXPR_MOD)
                        {
                                check_equal(update_varuble(globalroot,cur->right->idlist->first->right), update_varuble(globalroot,cur->right->idlist->first->left));
                        }
                        update_varuble(globalroot,cur->right->idlist->first);
                }
                return;
        }

        if(strcmp(cur->left->idlist->first->name, "readLine") == 0 )
        {
                if(cur->right->idlist->first != NULL)
                {
                        printf("Function have extra argument\n");
                        exit (EXIT_FAILURE);
                }
                return;
        }
        char * str = (char*)malloc(sizeof(char)*33);
        char * newstr = (char*)malloc(sizeof(char)*33);
        bool exist = false;
        for (auto c : functions_list) {
                if (strcmp(c.name->last->name, cur->left->idlist->first->name) == 0)
                {
                        exist = true;
                        strcat(str,"");
                        strcpy(str,get_function_args(&c));
                        struct NExpr * cura = cur->right->idlist->first;
                        strcat(newstr,"(");
                        while (cura != NULL) {
                                if(cura->idlist->first != NULL && cura->idlist->first->vartype != NULL) {
                                        strcat(newstr,return_varuble_type(cura->idlist->first));
                                }
                                strcat(newstr,return_Expr_Init_Type(cura->idlist->first));

                                cura = cura->next;
                        }
                        strcat(newstr,")");

                        if (strcmp(str, newstr) != 0)
                        {
                                printf("Fuction has wrong arguments\n");
                                exit (EXIT_FAILURE);
                        }
                        else{

                        }
                        break;
                }
        }

        for (auto c : main_functions_list) {
                if (strcmp(c.name->last->name, cur->left->idlist->first->name) == 0)
                {
                        exist = true;
                        strcat(str,"");
                        strcpy(str,get_function_args(&c));
                        struct NExpr * cura = cur->right->idlist->first;
                        strcat(newstr,"(");
                        while (cura != NULL) {
                                if(cura->idlist->first != NULL && cura->idlist->first->vartype != NULL) {
                                        strcat(newstr,return_varuble_type(cura->idlist->first));

                                }
                                strcat(newstr,return_Expr_Init_Type(cura));

                                cura = cura->next;
                        }
                        strcat(newstr,")");

                        if (strcmp(str, newstr) != 0)
                        {
                                printf("Fuction has wrong arguments\n");
                                exit (EXIT_FAILURE);
                        }
                        else{

                        }
                        break;
                }
        }
        if(!exist) {
                printf("fuction doesnot exist\n");
                exit (EXIT_FAILURE);
        }
}
char * get_function_args(struct NFunc * f){
        char * str = (char*)malloc(sizeof(char)*33);
        strcat(str,"(");
        if(f->args != NULL) {
                struct NExpr * current = f->args->first;


                while(current != NULL)
                {
                        strcat(str,return_varuble_type(current));

                        current = current->next;
                }
        }
        strcat(str,")");
        if(strcmp(str,"()") == 0)
        {
                return "()";
        }
        return str;
}
void print_function_param(char * function,struct NStmt * current){
        char * str = (char*)malloc(sizeof(char)*33);;
        int func_num = -1;
        if(current->type == STMT_FUNC)
        {
                STConst name;
                name.next = NULL;
                name.type = CONST_UTF8;
                name.value.utf8  = function;
                table.push_back(name);
                func_num = table.size();
                if(strcmp(current->func->name->last->name,function) == 0)
                {
                        if(current->func->args->first == NULL)
                        {
                                strcat(str,"()");

                        }
                        else{
                                strcat(str,get_function_args(current->func));
                        }
                        if(current->func->vartype == NULL)
                        {
                                strcat(str,"V ");
                        }else{
                                strcat(str,get_function_type(current->func));
                        }
                        if((st_constant_index( CONST_UTF8, (void*)(str)) == -1)){
                        STConst code;
                        code.next = NULL;
                        code.type = CONST_UTF8;
                        code.value.utf8  = str;
                        table.push_back(code);
                        }

                        STConst name_type;
                        name_type.next = NULL;
                        name_type.type = CONST_NAMETYPE;
                        name_type.value.args.arg1  = func_num;
                        name_type.value.args.arg2  = (st_constant_index( CONST_UTF8, (void*)(str)));
                        table.push_back(name_type);
                        STConst method_ref;
                        method_ref.next = NULL;
                        method_ref.type = CONST_METHODREF;
                        method_ref.value.args.arg1  = 3;
                        method_ref.value.args.arg2  = table.size()-1;
                        table.push_back(method_ref);

                }
        }
}
void print_function_param(char * function, NStmtList *root){
        char * str = (char*)malloc(sizeof(char)*33);;
        struct NStmt * current = root->first;
        while (current != NULL) {

                if(current->type == STMT_FUNC)
                {
                        if(strcmp(current->func->name->last->name,function) == 0)
                        {
                                STConst name;
                                name.next = NULL;
                                name.type = CONST_UTF8;
                                name.value.utf8  = function;
                                table.push_back(name);
                                if(current->func->args->first == NULL)
                                {
                                        strcat(str,"()");

                                }
                                else{
                                        strcat(str,get_function_args(current->func));
                                }
                                if(current->func->vartype == NULL)
                                {
                                        strcat(str,"V ");
                                }else{
                                        strcat(str,get_function_type(current->func));
                                }
                                break;
                        }
                }
                current = current->next;
        }

        STConst code;
        code.next = NULL;
        code.type = CONST_UTF8;
        code.value.utf8  = str;
        table.push_back(code);

}
void collect_functions(struct NStmtList * node){
        struct NStmt * current = node->first;
        while (current != NULL) {
                if(current->type == STMT_FUNC)
                {
                        for (auto c : main_functions_list)
                        {
                                if (strcmp(c.name->last->name,current->func->name->last->name) == 0)
                                {
                                        printf("redefine function\n");
                                        exit(EXIT_FAILURE);
                                }
                        }
                        main_functions_list.push_back(*current->func);
                }
                current = current->next;
        }
}
void create_header(NStmtList *root){
        STConst null;
        null.next = NULL;
        null.type = CONST_NULL;
        table.push_back(null);

        STConst code;
        code.next = NULL;
        code.type = CONST_UTF8;
        code.value.utf8  = "Code";
        table.push_back(code);

        STConst main;
        main.next = NULL;
        main.type = CONST_UTF8;
        main.value.utf8  = "Main";
        table.push_back(main);

        STConst classs;
        classs.next = NULL;
        classs.type = CONST_CLASS;
        classs.value.val_int  = 2;
        table.push_back(classs);


        STConst paramO;
        paramO.next = NULL;
        paramO.type = CONST_UTF8;
        paramO.value.utf8  = "java/lang/Object";
        table.push_back(paramO);

        STConst classss;
        classss.next = NULL;
        classss.type = CONST_CLASS;
        classss.value.val_int  = 4;
        table.push_back(classss);

        STConst minit;
        minit.next = NULL;
        minit.type = CONST_UTF8;
        minit.value.utf8  = "Main";
        table.push_back(minit);

        STConst param;
        param.next = NULL;
        param.type = CONST_UTF8;
        param.value.utf8  = "()V";
        table.push_back(param);

        STConst name_type;
        name_type.next = NULL;
        name_type.type = CONST_NAMETYPE;
        name_type.value.args.arg1 = table.size() - 2;
        name_type.value.args.arg2 = table.size() - 1;
        table.push_back(name_type);

        STConst method_ref;
        method_ref.next = NULL;
        method_ref.type = CONST_METHODREF;
        method_ref.value.args.arg1 = 3;
        method_ref.value.args.arg2 = table.size() - 1;
        table.push_back(method_ref);


}
void create_table(NStmtList *root){

        table.clear();
        create_header(root);

        globalroot = root;


        collect_functions(globalroot);

        struct NStmt * current = root->first;
        while (current != NULL) {
                st_stmt(current);
                current = current->next;
        }

        printTable();
        printLocalVars();
}
void create_main_table(NStmtList *root){
        struct NStmt * current = root->first;
        while (current != NULL) {

                if (current->type == STMT_ASSIGN && current->type == STMT_LASSIGN) {

                        st_stmt_expr(current->var);
                        st_stmt_expr(current->expr);
                }
                current = current->next;
        }
}
//############################################################################//
void st_stmt_list(struct NStmtList * node) {
        struct NStmt * current = node->first;
        while (current != NULL) {
                st_stmt(current);
                current = current->next;
        }
}
void st_stmt(struct NStmt * node) {
        switch (node->type) {
        case STMT_WHILE:  st_stmt_while(node->while_loop);                  break;
        case STMT_FOR:    st_stmt_for(node->for_loop);                      break;
        case STMT_EXPR:

                if(node->expr->type==EXPR_MINUS ||node->expr->type==EXPR_PLUS || node->expr->type==EXPR_MUL || node->expr->type==EXPR_DIV || node->expr->type==EXPR_MOD) {

                        check_equal(update_varuble(globalroot,node->expr->left),update_varuble(globalroot,node->expr->right));
                        st_stmt_expr(node->expr->left);
                        st_stmt_expr(node->expr->right);
                }
                else{
                        st_stmt_expr(node->expr);
                }

                break;
        case STMT_BLOCK:  st_stmt_list(node->list);                         break;
        case STMT_REPEAT: st_stmt_while(node->while_loop);                  break;
        case STMT_LFUNC:  st_stmt_func(node);                               break;
        case STMT_RETURN: if (node->expr != NULL) st_stmt_expr(node->expr); break;
        case STMT_IF:     st_stmt_if(node->if_tree);                        break;
        case STMT_SWITCH:  st_stmt_switch(node->switch_tree);               break;

        case STMT_FUNC: {

                for (auto c : functions_list)
                {
                        if (strcmp(c.name->last->name,node->func->name->last->name) == 0)
                        {
                                printf("redefine function\n");
                                exit(EXIT_FAILURE);
                        }
                }

                if(!check_return_function(node->func->body,get_function_type(node->func)))
                {
                        printf("Return doesnot exist or wrong return value\n");
                        exit(EXIT_FAILURE);
                }
                bool flag = false;


                for(auto cf : main_functions_list)
                {
                        if (strcmp(cf.name->last->name,node->func->name->last->name) == 0)
                        {
                                flag = true;
                                break;
                        }
                }
                if(!flag)
                        functions_list.push_back(*node->func);

                // Fill table.
                st_stmt_func(node);

        }
                        break;

        case STMT_ASSIGN:

                if (node->expr->type == EXPR_ID_LIST)
                {
                        check_equal(update_varuble(globalroot,node->var),update_varuble(globalroot,node->expr));
                }

                else if (node->expr->type==EXPR_MINUS ||node->expr->type==EXPR_PLUS || node->expr->type==EXPR_MUL || node->expr->type==EXPR_DIV || node->expr->type==EXPR_MOD)
                {
                        check_stack_operation(create_stack_operation(node->expr));
                        check_equal(update_varuble(globalroot,node->var),check_stack_operation(create_stack_operation(node->expr)));
                }

                else if(node->expr->type == EXPR_MET )
                {
                        for (auto c : functions_list) {
                                if (strcmp(c.name->last->name, node->expr->left->idlist->first->name) == 0)
                                {
                                        check_equal(update_varuble(globalroot,node->var),get_function_type(&c));
                                        break;
                                }
                        }
                        if(strcmp(node->expr->left->idlist->first->name,"readLine" )==0)
                        {
                                check_equal(update_varuble(globalroot,node->var),"S ");

                        }
                }

                else{
                        check_equal(update_varuble(globalroot,node->var),update_varuble(globalroot,node->expr));
                }
                st_stmt_expr(node->var);
                st_stmt_expr(node->expr);

                break;
        case STMT_LASSIGN:
                update_varuble(globalroot,node->var);
                st_stmt_expr(node->var);

                break;
        default:
                break;
        }
}
void st_stmt_switch_list(struct NCaseList * node) {
        struct NCase * current = node->first;
        while (current != NULL) {

                struct NStmt* current1 = current->body->first;
                while (current1 != NULL)
                {
                        st_stmt(current1);
                        current1 = current1->next;
                }
                current = current->next;
        }
}
void st_stmt_switch(struct NSwitch * node){
        st_stmt_expr(node->Name);

        st_stmt_switch_list(node->caselist);
}
void st_stmt_while(struct NWhile * node) {
        update_varuble(globalroot,node->condition->left);
        update_varuble(globalroot,node->condition->left);
        st_stmt_expr(node->condition);
        st_stmt_list(node->body);
}
void st_stmt_for(struct NFor * node) {
        //  update_varuble(globalroot,node->name);
        st_stmt_expr(node->name);
        st_stmt_expr(node->start);
        st_stmt_expr(node->step);
        st_stmt_list(node->body);
}
void st_stmt_func(struct NStmt * node) {

        print_function_param(node->func->name->last->name,node);

        st_stmt_list(node->func->body);
}
void st_stmt_if(struct NIf * node) {
        update_varuble(globalroot,node->condition->left);
        update_varuble(globalroot,node->condition->right);
        st_stmt_expr(node->condition);
        st_stmt_list(node->body);

        struct NIf* current = node->elseiflist->first;
        while (current != NULL)
        {
                st_stmt_if(current);
                current = current->next;
        }

        st_stmt_list(node->elsebody);
}
void st_stmt_expr(struct NExpr * node) {
      printf("%d st_stmt_expr node->type\n",node->type);
        switch (node->type) {
        case EXPR_INT: {
                if (st_constant_index(CONST_INT, (void *)&(node->Int)) == -1) {
                        STConst cint;
                        cint.next = NULL;
                        cint.type = CONST_INT;
                        cint.value.val_int = node->Int;
                        table.push_back(cint);
                }
        }
                       break;

        case EXPR_FLOAT: {
                if (st_constant_index( CONST_FLOAT, (void *)&(node->Float)) == -1) {
                        STConst cfloat;
                        cfloat.next = NULL;

                        cfloat.type = CONST_FLOAT;
                        cfloat.value.val_float = node->Float;

                        table.push_back(cfloat);

                }
        }

        case EXPR_DOUBLE: {
                if (st_constant_index( CONST_DOUBLE, (void *)&(node->Double)) == -1) {
                        STConst cfloat;
                        cfloat.next = NULL;

                        cfloat.type = CONST_DOUBLE;
                        cfloat.value.val_double = node->Double;

                        table.push_back(cfloat);


                }
        }
                          break;

        case EXPR_STR: {
                // Make UTF-8
                if (st_constant_index( CONST_UTF8, (void*)(node->name)) == -1) {
                        STConst utf8;
                        utf8.next = NULL;

                        utf8.type = CONST_UTF8;
                        utf8.value.utf8 = node->name; // `strcpy` it in case of problems

                        table.push_back(utf8);


                        STConst cstr;
                        cstr.next = NULL;

                        cstr.type = CONST_STRING;
                        cstr.value.args.arg1 = st_constant_index(CONST_UTF8, utf8.value.utf8);

                        table.push_back(cstr);


                }
        }
                       break;

        case EXPR_MET: {
                function_call.push_back(*node);
              //  check_function_args(node);

                printf("%s",node->left->idlist->first->name );
                printf("%d\n\n\n",node->left->idlist->first->type);
                check_equal("",update_varuble(globalroot,node->left->idlist->first));


                struct NExpr * cur = node->right->idlist->first;
                while (cur != NULL) {
                        st_stmt_expr(cur);
                        cur = cur->next;
                }
        }
                       break;

        case EXPR_ID_LIST: {
                if(node->vartype != NULL) {
                        if(node->idlist->first->name != NULL)
                        {
                                if (st_constant_index( CONST_UTF8, (void*)(node->idlist->first->name)) == -1) {
                                        char * str = (char*)malloc(sizeof(char)*33);
                                        STConst var;
                                        var.next = NULL;
                                        var.type = CONST_UTF8;
                                        var.value.utf8  = node->idlist->first->name;
                                        table.push_back(var);

                                        strcat(str,return_varuble_type(node));

                                        STConst type_var;
                                        type_var.next = NULL;
                                        type_var.type = CONST_UTF8;
                                        type_var.value.utf8  = str;
                                        table.push_back(type_var);

                                        STConst name_type;
                                        name_type.next = NULL;
                                        name_type.type = CONST_NAMETYPE;
                                        name_type.value.args.arg1 = table.size() - 2;
                                        name_type.value.args.arg2 = table.size() - 1;
                                        table.push_back(name_type);

                                        STConst field_ref;
                                        field_ref.next = NULL;
                                        field_ref.type = CONST_FIELDREF;
                                        field_ref.value.args.arg1 = 3;
                                        field_ref.value.args.arg2 = table.size() - 1;
                                        table.push_back(field_ref);
                                }
                        }
                }
        }

                           break;
        default:
                break;
        }


        if (node->left != NULL) {
                st_stmt_expr(node->left);
        }

        if (node->right != NULL) {
                st_stmt_expr(node->right);
        }
}
int nexprlist_count(NExprList * start) {
        int count = 0;
        NExpr * cur = start->first;
        while (cur != NULL) {
                count++;
                cur = cur->next;
        }
        return count;
}
int st_constant_index(enum st_const_types type, const void * value) {

        int index = 0;
        for (auto c : table) {
                if (c.type == type) {
                        switch (type) {
                        case CONST_INT:
                                if (c.value.val_int == *((int *)value)) {
                                        return index;
                                }
                                break;

                        case CONST_DOUBLE:
                                if (c.value.val_double == *((double *)value)) {
                                        return index;
                                }
                                break;


                        case CONST_FLOAT:
                                if (c.value.val_float == *((double *)value)) {
                                        return index;
                                }
                                break;

                        case CONST_UTF8:
                                if (strcmp(c.value.utf8, (char *)value) == 0) {
                                        return index;
                                }
                                break;

                        default:
                                return -1;
                                break;
                        }
                }
                index++;
        }
        return -1;
}
int st_constant_index2(STConst * table, enum st_const_types type, int arg1, int arg2) {
        STConst * cur = table;
        int index = 0;
        while (cur != NULL) {
                if (cur->type == type
                    && cur->value.args.arg1 == arg1
                    && cur->value.args.arg2 == arg2) {

                        return index;
                }
                cur = cur->next;
                index++;
        }
        return -1;
}
void st_print_const_file(FILE * output) {

        char name[10] = "";
        fprintf(output,";Constant table size = %d;\n", table.size()-1);
        int index = 0;
        for (auto c : table) {
                if(c.type != CONST_NULL) {
                        fprintf(output,"%5d;%9s;  ", index, st_type_name(c.type, name));
                }
                switch (c.type) {
                case CONST_UTF8:      fprintf(output,"'%s'\n", c.value.utf8);      break;
                case CONST_INT:       fprintf(output,"%d\n", c.value.val_int);   break;
                case CONST_FLOAT:     fprintf(output,"%f\n", c.value.val_float); break;
                case CONST_DOUBLE:    fprintf(output,"%f\n", c.value.val_double); break;
                case CONST_CLASS:     fprintf(output,"%d\n", c.value.val_int); break;
                case CONST_STRING:    fprintf(output,"%d\n", c.value.args.arg1); break;
                case CONST_NULL:      break;
                case CONST_FIELDREF:  fprintf(output,"%d %d\n", c.value.args.arg1, c.value.args.arg2); break;
                case CONST_METHODREF: fprintf(output,"%d %d\n", c.value.args.arg1, c.value.args.arg2); break;
                case CONST_NAMETYPE:  fprintf(output,"%d %d\n", c.value.args.arg1, c.value.args.arg2); break;

                default:              fprintf(output,"%s","==WTF?==\n"); break;
                }
                index++;
        }

}
char * st_type_name(enum st_const_types type, char name[10]) {
        switch (type) {
        case CONST_UTF8:      strcpy(name, "UTF8");      break;
        case CONST_INT:       strcpy(name, "INT");       break;
        case CONST_DOUBLE:    strcpy(name, "DOUBLE");     break;
        case CONST_FLOAT:     strcpy(name, "FLOAT");     break;
        case CONST_CLASS:     strcpy(name, "CLASS");     break;
        case CONST_STRING:    strcpy(name, "STRING");    break;
        case CONST_FIELDREF:  strcpy(name, "FIELDREF");  break;
        case CONST_METHODREF: strcpy(name, "METHODREF"); break;
        case CONST_NAMETYPE:  strcpy(name, "NAMETYPE");  break;
        default:              strcpy(name, "==WTF?==");  break;
        }
        return name;
}
void printLocalVars(){
        NStmtList * tempGlobal = globalroot;

        list<st_const> tempTable;
        tempTable = table;
        int index = 1;


        printf("Method list size = %d\n",functions_list.size() + main_functions_list.size());
        for (auto t : main_functions_list) {
                table.clear();
                globalroot = t.body;
                st_stmt_list(t.body);
                printf("%s:\n",t.name->last->name);
                printf("List local varubles:\n");
                for (auto c : table) {
                        switch (c.type) {
                        case CONST_UTF8:      if(strstr(c.value.utf8," ")== 0 && strlen(c.value.utf8) > 0) {printf("%5d: ", index); printf("'%s'\n", c.value.utf8); index++;}      break;
                        }
                }
                printf("\n");
                index = 1;
        }

        for (auto t : functions_list) {
                table.clear();
                globalroot = t.body;
                st_stmt_list(t.body);
                printf("%s:\n",t.name->last->name);
                printf("List local varubles:\n");
                for (auto c : table) {
                        switch (c.type) {
                        case CONST_UTF8:      if(strstr(c.value.utf8," ")== 0 && strlen(c.value.utf8) > 0) {printf("%5d: ", index); printf("'%s'\n", c.value.utf8); index++;}      break;
                        }
                }
                printf("\n");
                index = 1;
        }
        globalroot = tempGlobal;
        table = tempTable;
}
void printLocalVars_file(FILE *output){
        list<st_const> tempTable;
        tempTable = table;
        int index = 1;
        fprintf(output,"Method list size = %d\n",functions_list.size());
        for (auto t : functions_list) {
                table.clear();

                st_stmt_list(t.body);
                fprintf(output,"%s:;\n",t.name->last->name);
                fprintf(output,";List local varubles:;\n");
                for (auto c : table) {
                        switch (c.type) {
                        case CONST_UTF8:      if(strstr(c.value.utf8," ")== 0) {fprintf(output,"%5d:; ", index); fprintf(output,"'%s'\n", c.value.utf8); index++;}      break;
                        }
                }
                printf("\n");
                index = 1;
        }
        table = tempTable;
}
void printTable(){
        char name[10] = "";
        int index = 0;
        printf("Constant table size = %d\n", table.size()-1);
        for (auto c : table) {
                if(c.type != CONST_NULL) {
                        printf("%5d:  %9s  ", index, st_type_name(c.type, name));
                }
                switch (c.type) {
                case CONST_UTF8:      printf("'%s'\n", c.value.utf8);      break;
                case CONST_INT:       printf("%d\n", c.value.val_int);   break;
                case CONST_FLOAT:     printf("%f\n", c.value.val_float); break;
                case CONST_DOUBLE:    printf("%f\n", c.value.val_double); break;
                case CONST_CLASS:     printf("%d\n", c.value.val_int); break;
                case CONST_STRING:    printf("%d\n", c.value.args.arg1); break;
                case CONST_NULL:      break;
                case CONST_FIELDREF:  printf("%d %d\n", c.value.args.arg1, c.value.args.arg2); break;
                case CONST_METHODREF: printf("%d %d\n", c.value.args.arg1, c.value.args.arg2); break;
                case CONST_NAMETYPE:  printf("%d %d\n", c.value.args.arg1, c.value.args.arg2); break;

                default:              printf("==WTF?==\n"); break;
                }
                index++;
        }
}

#endif
