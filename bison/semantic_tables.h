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
    CONST_NAMETYPE  = 12
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


/*
 * Function declarations.
 */

void st_stmt_switch_list(struct NCaseList * node);

void st_stmt_switch(struct NSwitch * node);

/**
 * Creates a new constant table with first temporary UTF8 entry.
 * @return A pointer to constant list.
 */
STConst * st_new_const_table();

/**
 * Creates a new one-argument constant.
 * Accepts: CONST_UTF8, CONST_INT, CONST_FLOAT, CONST_CLASS, CONST_STRING.
 * @param [in] type Constant type.
 * @param [in] arg  Constant value.
 * @return Created constant.
 */
STConst * st_new_const(enum st_const_types type, void * arg);

/**
* Creates a new two-argument constant.
* Accepts: CONST_FIELDREF, CONST_METHODREF, CONST_NAMETYPE.
* @param [in] type Constant type.
* @param [in] arg1 Constant first value.
* @param [in] arg2 Constant second value.
* @return Created constant.
*/
STConst * st_new_const2(enum st_const_types type, int arg1, int arg2);



/**
 * Fills tables according to given tree.
 * @param [in] root The root of the tree.
 */


void st_stmt_list(struct NStmtList * node);
void st_stmt(struct NStmt * node);
void st_stmt_while(struct NWhile * node);
void st_stmt_for(struct NFor * node);
void st_stmt_func(struct NFunc * node);
void st_stmt_if(struct NIf * node);
void st_stmt_expr(struct NExpr * node);

/**
 * Returns zero-based index of one-argument constant in table.
 * @param [in] table A constant table to search in
 * @param [in] type  Constant type. Supported types are:
 *                   CONST_INT
 *                   CONST_FLOAT
 *                   CONST_UTF8
 * @param [in] arg1  First value.
 * @param [in] arg2  Second value.
 * @return Zero-based index or -1 when constant not found.
 */
int st_constant_index(enum st_const_types type, const void * value);

/**
 * Returns zero-based index of two-argument constant in table.
 * @param [in] table A constant table to search in
 * @param [in] type  Constant type. Supported types are:
 *                   CONST_FIELDREF
 *                   CONST_METHODREF
 *                   CONST_NAMETYPE
 * @param [in] value Constant value.
 * @return Zero-based index or -1 when constant not found.
 */
int st_constant_index2(STConst * table, enum st_const_types type, int arg1, int arg2);

/**
 * Prints the constants table.
 */
void st_print_const();

void st_print_const_file(FILE *  output,STConst * table);

/**
 * Return a string containing constant type name.
 * Just turns enum value to it's name.
 * @param [in]  type Const type.
 * @param [out] name String.
 * @return param name.
 */
char * st_type_name(enum st_const_types type, char name[10]);

/**
 * Returns the number of elements in given expr list.
 * This function iterates over the list.
 * @param [in] start List head.
 * @return Number of elements.
 */
int    nexprlist_count(NExprList * start);

/**
 * Generates a function handle for the given function;
 * @param [in] f      NFunc tree node.
 * @param [in] buffer Text buffer.
 * @return Text buffer with function handle.
 */
char * st_gen_func_handle(NFunc * f, char * buffer);


//############################################################################//

list<st_const> table; // объявляем пустой список
list<NFunc> functions_list;
void printTable()
{
   for (auto c : table) {
      switch (c.type){
            case CONST_UTF8:      printf("'%s'", c.value.utf8);      break;
            case CONST_INT:       printf("%d", c.value.val_int);   break;
            case CONST_FLOAT:     printf("%f", c.value.val_float); break;
            case CONST_DOUBLE:    printf("%f", c.value.val_double); break;
            case CONST_CLASS:     printf("%d", c.value.val_int); break;
            case CONST_STRING:    printf("%d", c.value.args.arg1); break;

            case CONST_FIELDREF:
            case CONST_METHODREF:
            case CONST_NAMETYPE: printf("%d %d", c.value.args.arg1, c.value.args.arg2); break;

            default:              printf("==WTF?=="); break;
        }
    printf("\n");

    }
}

char * get_function_type(struct NFunc * f)
{
  char * str = (char*)malloc(sizeof(char)*33);;

             switch (f->vartype->type) {
                 case INTTy:       strcat(str,"I;");   break;
                 case FLOATTy:     strcat(str,"F;"); break;
                 case DOUBLETy:    strcat(str,"D;"); break;
                 case BOOLTy:      strcat(str,"B;"); break;
                 case STRINGTy:    strcat(str,"S;"); break;

                 default:              printf("==WTF?==;"); break;
               }
  return str;
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

                   default:              printf("==WTF?==;"); break;
               }
       current = current->next;
   }
    strcat(str,")");
    return str;
}

void print_function_param(char * function,NStmtList *root){
    char * str = (char*)malloc(sizeof(char)*33);;
    struct NStmt * current = root->first;
    while (current != NULL) {
        if(current->type == STMT_FUNC)
        {
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

/*
STConst param;
param.next = NULL;
param.type = CONST_UTF8;
param.value.utf8  = "()V";
table.push_back(param);

STConst minit;
minit.next = NULL;
minit.type = CONST_UTF8;
minit.value.utf8  = "<init>";
table.push_back(minit);
*/

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
        case STMT_LFUNC:  st_stmt_func(node->func);                         break;
        case STMT_RETURN: if (node->expr != NULL) st_stmt_expr(node->expr); break;
        case STMT_IF:     st_stmt_if(node->if_tree);                        break;
        case STMT_SWITCH:  st_stmt_switch(node->switch_tree);               break;

        case STMT_FUNC: {
          functions_list.push_back(*node->func);

            // Fill table.
            st_stmt_func(node->func);

        }
        break;

        case STMT_ASSIGN:
        case STMT_LASSIGN:
            st_stmt_expr(node->var);
            st_stmt_expr(node->expr);
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
    st_stmt_expr(node->condition);
    st_stmt_list(node->body);
}

void st_stmt_for(struct NFor * node) {
    st_stmt_expr(node->name);
    st_stmt_expr(node->start);
    st_stmt_expr(node->step);
    st_stmt_list(node->body);
}

void st_stmt_func(struct NFunc * node) {
  /*
    int arg1;
    char buf[512];
    STConst * c = NULL;
    SList * f = (SList *)malloc(sizeof(SList));

    // Add function to list
    f->next = NULL;
    f->data = (void *)(node);
    if (func_list == NULL) {
        func_list = f;
        func_last = f;
    } else {
        func_last->next = f;
        func_last = f;
    }

    // Set function classname
    node->classname = (char *)malloc(10);
    sprintf(node->classname, "func%d", funcnum);
    funcnum++;

    // Create methodref

    // Method name UTF8
    if (st_constant_index(st_func_handles, CONST_UTF8, "value") == -1) {
        c = st_new_const(CONST_UTF8, NULL);
        c->value.utf8 = (char *)malloc(6);
        strcpy(c->value.utf8, "value");
        st_func_hlast->next = c;
        st_func_hlast = c;
        fconstnum++;
    }

    // Function handle UTF8
    st_gen_func_handle(node, buf);
    int fh = st_constant_index(st_func_handles, CONST_UTF8, buf);
    if (fh == -1) {
        c = st_new_const(CONST_UTF8, NULL);
        c->value.utf8 = (char *)malloc(512);
        strcpy(c->value.utf8, buf);
        st_func_hlast->next = c;
        st_func_hlast = c;
        fh = ++fconstnum;
    }

    // Class name UTF8
    c = st_new_const(CONST_UTF8, (void *)node->classname);
    st_func_hlast->next = c;
    st_func_hlast = c;
    fconstnum++;

    // Class
    c = st_new_const(CONST_CLASS, (void *)&fconstnum);
    st_func_hlast->next = c;
    st_func_hlast = c;
    fconstnum++;

    // Name and type
    arg1 = st_constant_index(st_func_handles, CONST_UTF8, "value");
    int nt = st_constant_index2(st_func_handles, CONST_NAMETYPE, arg1, fh);
    if (nt == -1) {
        c = st_new_const2(CONST_NAMETYPE, arg1, fh);
        st_func_hlast->next = c;
        st_func_hlast = c;
        nt = ++fconstnum;
    }

    // Methodref
    arg1 = fconstnum - 1;
    c = st_new_const2(CONST_METHODREF, arg1, nt);
    st_func_hlast->next = c;
    st_func_hlast = c;
    fconstnum++;

    // Set methodref attribute
    node->methodref = fconstnum;
*/
    st_stmt_list(node->body);
}

void st_stmt_if(struct NIf * node) {
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
            struct NExpr * cur = node->right->idlist->first;
            while (cur != NULL) {
                st_stmt_expr(cur);
                cur = cur->next;
            }
        }
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

void st_print_const(STConst * table)
{
  char name[10] = "";
  STConst * cur = table;
  int index = 0;
  while (cur != 0) {
      printf("%5d:  %9s  ", index, st_type_name(cur->type, name));
      switch (cur->type) {
          case CONST_UTF8:      printf("'%s'", cur->value.utf8);      break;
          case CONST_INT:       printf("%d", cur->value.val_int);   break;
          case CONST_FLOAT:     printf("%f", cur->value.val_float); break;
          case CONST_DOUBLE:    printf("%f", cur->value.val_double); break;
          case CONST_CLASS:
          case CONST_STRING:    printf("%d", cur->value.args.arg1); break;

          case CONST_FIELDREF:
          case CONST_METHODREF:
          case CONST_NAMETYPE: printf("%d %d", cur->value.args.arg1, cur->value.args.arg2); break;

          default:              printf("==WTF?=="); break;
      }
      printf("\n");

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
