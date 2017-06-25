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
using namespace std;



/*
 * Table structure declarations.
 */

/**
 * Constant types.
 */
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
    CONST_NULL = -1
};


/**
 * A record of constants table.
 * Singly-Linked list element.
 */
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
void st_print_const_file(FILE *  output,STConst * table);
char * st_type_name(enum st_const_types type, char name[10]);
int    nexprlist_count(NExprList * start);
char * st_gen_func_handle(NFunc * f, char * buffer);
char * get_function_args(struct NFunc * f);

//############################################################################//

list<st_const> table;
list<NFunc> functions_list;
list<NExpr> function_call;
NStmtList *globalroot;

int nexprlist_count(NExprList * start) {
    int count = 0;
    NExpr * cur = start->first;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    return count;
}

void update_varuble(NStmtList *root,NExpr *var)
{
  if(var->type != EXPR_ID_LIST && var->type != EXPR_ID)
  {
    return;
  }

  bool exist = false;
  struct NStmt * current = root->first;
  printf("%d VAR Type of statement\n",var->type );
  while (current != NULL) {
    printf("%d Type of statement\n",current->type );

      if(current->type == STMT_BLOCK)
      {
        struct NStmtList* result = (NStmtList*)malloc(sizeof(NStmtList));
        result->first = current;
        update_varuble(result,var);
      }

      if(var->type == EXPR_ID  && current->type == STMT_ASSIGN)
      {
        if(strcmp(current->var->idlist->first->name , var->name) == 0 )
        {
          exist = true;
        }
      }
      if(current->type == STMT_ASSIGN && var->type == EXPR_ID_LIST){
        if(strcmp(var->idlist->first->name,current->var->idlist->first->name)==0)
        {
          exist = true;
            printf("Founded need Varuble\n");

            STConst name;
            name.next = NULL;
            name.type = CONST_UTF8;
            name.value.utf8  = current->var->idlist->first->name;
            table.push_back(name);
        printf("name %s\n",current->var->idlist->first->name);
        printf("Varuble found var->type %d\n",current->var->type);
        printf("Varuble found var->idlist->first->type %d\n",current->var->idlist->first->type);
        if(current->var->vartype != NULL){
        printf("Varuble found current->var->vartype->type %d\n",current->var->vartype->type);

          char * str = (char*)malloc(sizeof(char)*33);;


          switch (current->var->vartype->type) {
              case INTTy:       strcat(str,"I;");    break;
              case FLOATTy:     strcat(str,"F;");    break;
              case DOUBLETy:    strcat(str,"D;");    break;
              case BOOLTy:      strcat(str,"B;");    break;
              case STRINGTy:    strcat(str,"S;");    break;
              case VOIDTy:      strcat(str,"V");     break;
              case NULLTYPE:    exist = false;;      break;
              default:          printf("==WTF?==;"); break;
            }
            STConst type_var;
            type_var.next = NULL;
            type_var.type = CONST_UTF8;
            type_var.value.utf8  = str;
            table.push_back(type_var);

        }
        else {
          exist = false;
        }

         if(current->var->varconstant != NULL){
        printf("Varuble found var->varconstant %d\n",current->var->varconstant->constant);
        }
        printf("Varuble found expr->type %d\n",current->expr->type);
        break;
      }
      }
      current = current->next;
  }
  if(!exist){
    printf("Varuble doest exist\n");
    exit (EXIT_FAILURE);
  }
}

void printTable()
{
  char name[10] = "";
  int index = 0;
   for (auto c : table) {
     if(c.type != CONST_NULL){
     printf("%5d:  %9s  ", index, st_type_name(c.type, name));
   }
      switch (c.type){
            case CONST_UTF8:      printf("'%s'\n", c.value.utf8);      break;
            case CONST_INT:       printf("%d\n", c.value.val_int);   break;
            case CONST_FLOAT:     printf("%f\n", c.value.val_float); break;
            case CONST_DOUBLE:    printf("%f\n", c.value.val_double); break;
            case CONST_CLASS:     printf("%d\n", c.value.val_int); break;
            case CONST_STRING:    printf("%d\n", c.value.args.arg1); break;
            case CONST_NULL:      break;
            case CONST_FIELDREF:  break;
            case CONST_METHODREF: break;
            case CONST_NAMETYPE:  printf("%d %d\n", c.value.args.arg1, c.value.args.arg2); break;

            default:              printf("==WTF?==\n"); break;
        }
        index++;
    }
}

char * get_function_type(struct NFunc * f)
{
  char * str = (char*)malloc(sizeof(char)*33);;

             switch (f->vartype->type) {
                 case INTTy:       strcat(str,"I;");    break;
                 case FLOATTy:     strcat(str,"F;");    break;
                 case DOUBLETy:    strcat(str,"D;");    break;
                 case BOOLTy:      strcat(str,"B;");    break;
                 case STRINGTy:    strcat(str,"S;");    break;
                 case VOIDTy:      strcat(str,"V");     break;
                 default:          printf("==WTF?==;"); break;
               }
  return str;
}

void check_function_args(struct NExpr * cur)
{

  if (strcmp(cur->left->idlist->first->name , "print") == 0 )
  {
    update_varuble(globalroot,cur->right->idlist->first);
    return;
  }

  if(strcmp(cur->left->idlist->first->name , "readLine") == 0 )
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
  if (strcmp(c.name->last->name , cur->left->idlist->first->name) == 0)
  {
      exist = true;

      strcat(str,get_function_args(&c));
      struct NExpr * cura = cur->right->idlist->first;
      strcat(newstr,"(");
      while (cura != NULL) {
        switch(cura->type)
        {
          case EXPR_INT:
          strcat(newstr,"I;");   break;
          break;
          case EXPR_DOUBLE:
          strcat(newstr,"D;");   break;
          break;
          case EXPR_FLOAT:
          strcat(newstr,"F;");   break;
          break;
          case EXPR_STR:
          strcat(newstr,"S;");   break;
          break;
          case EXPR_BOOL:
          strcat(newstr,"B;");   break;
          break;
          default:
            break;
        }

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

if(!exist)
{
  printf("fuction doesnot exist\n");
  exit (EXIT_FAILURE);
}
}

char * get_function_args(struct NFunc * f)
{
    char * str = (char*)malloc(sizeof(char)*33);;

   struct NExpr * current = f->args->first;
   strcat(str,"(");

   while(current != NULL)
   {
               switch (current->vartype->type) {
                   case INTTy:       strcat(str,"I;");   break;
                   case FLOATTy:     strcat(str,"F;"); break;
                   case DOUBLETy:    strcat(str,"D;"); break;
                   case BOOLTy:      strcat(str,"B;"); break;
                   case STRINGTy:    strcat(str,"S;"); break;
                   case VOIDTy:      strcat(str,"S;"); break;
                   default:          printf("==WTF?==;"); break;
               }
       current = current->next;
   }
    strcat(str,")");
    return str;
}


void print_function_param(char * function,struct NStmt * current){
    char * str = (char*)malloc(sizeof(char)*33);;

        if(current->type == STMT_FUNC)
        {
          STConst name;
          name.next = NULL;
          name.type = CONST_UTF8;
          name.value.utf8  = function;
          table.push_back(name);

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
              strcat(str,"V;");
             }else{
                strcat(str,get_function_type(current->func));
             }
             STConst code;
             code.next = NULL;
             code.type = CONST_UTF8;
             code.value.utf8  = str;
             table.push_back(code);
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
              strcat(str,"V;");
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


}
void create_table(NStmtList *root){

    table.clear();
    create_header(root);

    globalroot = root;



    struct NStmt * current = root->first;
    while (current != NULL) {
        st_stmt(current);
        current = current->next;
    }
    printTable();
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
        case STMT_EXPR:   st_stmt_expr(node->expr);                         break;
        case STMT_BLOCK:  st_stmt_list(node->list);                         break;
        case STMT_REPEAT: st_stmt_while(node->while_loop);                  break;
        case STMT_LFUNC:  st_stmt_func(node);                               break;
        case STMT_RETURN: if (node->expr != NULL) st_stmt_expr(node->expr); break;
        case STMT_IF:     st_stmt_if(node->if_tree);                        break;
        case STMT_SWITCH:  st_stmt_switch(node->switch_tree);               break;

        case STMT_FUNC: {
          functions_list.push_back(*node->func);

            // Fill table.
            st_stmt_func(node);

        }
        break;

        case STMT_ASSIGN:
        update_varuble(globalroot,node->var);
        update_varuble(globalroot,node->expr);
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
  update_varuble(globalroot,node->name);
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
                STConst  cfloat;
                cfloat.next = NULL;

                cfloat.type = CONST_FLOAT;
                cfloat.value.val_float = node->Float;

                table.push_back(cfloat);

            }
        }

        case EXPR_DOUBLE: {
            if (st_constant_index( CONST_DOUBLE, (void *)&(node->Double)) == -1) {
                STConst  cfloat;
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
            STConst  utf8;
            utf8.next = NULL;

            utf8.type = CONST_UTF8;
            utf8.value.utf8 = node->name; // `strcpy` it in case of problems

            table.push_back(utf8);


            STConst  cstr ;
            cstr.next = NULL;

            cstr.type = CONST_STRING;
            cstr.value.args.arg1 = st_constant_index(CONST_UTF8, utf8.value.utf8);

            table.push_back(cstr);


          }
        }
        break;

        case EXPR_MET: {
            function_call.push_back(*node);
            check_function_args(node);
            struct NExpr * cur = node->right->idlist->first;
            while (cur != NULL) {
                st_stmt_expr(cur);
                cur = cur->next;
            }
        }
        break;

        case EXPR_ID_LIST: {
          if(node->vartype != NULL){
            if(node->idlist->first->name != NULL)
            {
              if (st_constant_index( CONST_UTF8, (void*)(node->idlist->first->name)) == -1) {
                char * str = (char*)malloc(sizeof(char)*33);
                STConst var;
                var.next = NULL;
                var.type = CONST_UTF8;
                var.value.utf8  = node->idlist->first->name;
                table.push_back(var);

                switch (node->vartype->type) {
                    case INTTy:       strcat(str,"I;");   break;
                    case FLOATTy:     strcat(str,"F;"); break;
                    case DOUBLETy:    strcat(str,"D;"); break;
                    case BOOLTy:      strcat(str,"B;"); break;
                    case STRINGTy:    strcat(str,"S;"); break;
                    case VOIDTy:      strcat(str,"V"); break;
                    default:          printf("==WTF?==;"); break;
                  }
                  STConst type_var;
                  type_var.next = NULL;
                  type_var.type = CONST_UTF8;
                  type_var.value.utf8  = str;
                  table.push_back(type_var);
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

int st_constant_index(enum st_const_types type, const void * value) {

    int index = 0;
    for (auto c : table){
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

void st_print_const_file(FILE * output, STConst * table) {

    char name[10] = "";
    STConst * cur = table;
    int index = 0;
    while (cur != 0) {

      fprintf(output, "%5d;%9s; ", index, st_type_name(cur->type, name));

      //  printf("%5d:  %9s  ", index, st_type_name(cur->type, name));
        switch (cur->type) {
            case CONST_UTF8:      fprintf(output, "'%s'", cur->value.utf8);      break;
            case CONST_INT:       fprintf(output, "%d", cur->value.val_int);   break;
            case CONST_FLOAT:     fprintf(output, "%f", cur->value.val_float); break;
            case CONST_DOUBLE:    fprintf(output, "%f", cur->value.val_double); break;
            case CONST_CLASS:
            case CONST_STRING:    fprintf(output, "%d", cur->value.args.arg1); break;

            case CONST_FIELDREF:
            case CONST_METHODREF:
            case CONST_NAMETYPE: fprintf(output, "%d %d", cur->value.args.arg1, cur->value.args.arg2); break;

            default:              fprintf(output,"%s", "==WTF?=="); break;
        }
        fprintf(output,"%s","\n");

        cur = cur->next;
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



#endif
