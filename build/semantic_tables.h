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
#include <vector>

using namespace std;

enum SemanticalConst
{
        CONST_Utf8 = 1,
        CONST_Integer = 3,
        CONST_Float = 4,
        CONST_Class = 7,
        CONST_String = 8,
        CONST_Fieldref = 9,
        CONST_Methodref = 10,
        CONST_NameAndType = 12
};

struct SemanticalElement
{
        int id;
        std::string str;
        float const_float;
        int const_int;
        struct SemanticalElement* first;
        struct SemanticalElement* second;
        enum SemanticalConst type;

        SemanticalElement()
        {
                first = NULL;
                second = NULL;
                id = 0;
                const_int = -1;
                const_float = -1;
                str.clear();
        }
};


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

list<NExpr *> Main_varubles;

list<list<NExpr *> > function_varubles;

vector<int> discriptor_of_methods;
vector<int> name_of_methods;

NStmtList *globalroot;
NStmtList *rootwithoutfunc;

int countofvar = 0 ;

void buildBaseTable()
{
        STConst null;
        null.type = CONST_NULL;
        table.push_back(null);

        STConst code;
        code.type = CONST_UTF8;
        code.value.utf8  = "Code";
        table.push_back(code);

        STConst main;
        main.type = CONST_UTF8;
        main.value.utf8  = "Main";
        table.push_back(main);

        STConst classs;
        classs.type = CONST_CLASS;
        classs.value.val_int  = 2;
        table.push_back(classs);

        STConst mainmethod;
        mainmethod.type = CONST_UTF8;
        mainmethod.value.utf8 = "main";
        table.push_back(mainmethod);

        STConst maindecl;
        maindecl.type = CONST_UTF8;
        maindecl.value.utf8 = "([Ljava/lang/String;)V";
        table.push_back(maindecl);

        STConst kostyl;
        kostyl.type = CONST_UTF8;
        kostyl.value.utf8 = "Ljava/lang/String;";
        table.push_back(kostyl);

        STConst superclassname;
        superclassname.type = CONST_UTF8;
        superclassname.value.utf8 = "Ljava/lang/Object;";
        table.push_back(superclassname);

        STConst superclass;
        superclass.type = CONST_CLASS;
        superclass.value.val_int  = 7;
        table.push_back(superclass);

        //Class Print 9


        STConst RTLPrint;
        RTLPrint.type = CONST_CLASS;
        RTLPrint.value.val_int  = 34;
        table.push_back(RTLPrint);



        //Print int block 10 11 12 13
        STConst printIntName;
        printIntName.type = CONST_UTF8;
        printIntName.value.utf8 = "printInt";
        table.push_back(printIntName);

        STConst printIntDesc;
        printIntDesc.type = CONST_UTF8;
        printIntDesc.value.utf8 = "(I)V";
        table.push_back(printIntDesc);

        STConst printIntNT;
        printIntNT.type = CONST_NAMETYPE;
        printIntNT.value.args.arg1 = 10;
        printIntNT.value.args.arg2 = 11;
        table.push_back(printIntNT);

        STConst printIntMethod;
        printIntMethod.type = CONST_METHODREF;
        printIntMethod.value.args.arg1 = 9;
        printIntMethod.value.args.arg2 = 12;
        table.push_back(printIntMethod);


        //Print float block 14 15 16 17
        STConst printFloatName;
        printFloatName.type = CONST_UTF8;
        printFloatName.value.utf8 = "printFloat";
        table.push_back(printFloatName);

        STConst printFloatDesc;
        printFloatDesc.type = CONST_UTF8;
        printFloatDesc.value.utf8 = "(F)V";
        table.push_back(printFloatDesc);

        STConst printFloatNT;
        printFloatNT.type = CONST_NAMETYPE;
        printFloatNT.value.args.arg1 = 14;
        printFloatNT.value.args.arg2 = 15;
        table.push_back(printFloatNT);

        STConst printFloatMethod;
        printFloatMethod.type = CONST_METHODREF;
        printFloatMethod.value.args.arg1 = 9;
        printFloatMethod.value.args.arg2 = 16;
        table.push_back(printFloatMethod);


        //Print char block 18 19 20 21
        STConst printCharName;
        printCharName.type = CONST_UTF8;
        printCharName.value.utf8 = "printChar";
        table.push_back(printCharName);

        STConst printCharDesc;
        printCharDesc.type = CONST_UTF8;
        printCharDesc.value.utf8 = "(C)V";
        table.push_back(printCharDesc);

        STConst printCharNT;
        printCharNT.type = CONST_NAMETYPE;
        printCharNT.value.args.arg1 = 18;
        printCharNT.value.args.arg2 = 19;
        table.push_back(printCharNT);

        STConst printCharMethod;
        printCharMethod.type = CONST_METHODREF;
        printCharMethod.value.args.arg1 = 9;
        printCharMethod.value.args.arg2 = 20;
        table.push_back(printCharMethod);


        //Print bool block 22 23 24 25
        STConst printBoolName;
        printBoolName.type = CONST_UTF8;
        printBoolName.value.utf8 = "printBool";
        table.push_back(printBoolName);

        STConst printBoolDesc;
        printBoolDesc.type = CONST_UTF8;
        printBoolDesc.value.utf8 = "(B)V";
        table.push_back(printBoolDesc);

        STConst printBoolNT;
        printBoolNT.type = CONST_NAMETYPE;
        printBoolNT.value.args.arg1 = 22;
        printBoolNT.value.args.arg2 = 23;
        table.push_back(printBoolNT);

        STConst printBoolMethod;
        printBoolMethod.type = CONST_METHODREF;
        printBoolMethod.value.args.arg1 = 9;
        printBoolMethod.value.args.arg2 = 24;
        table.push_back(printBoolMethod);

        //Print string block 26 27 28 29
        STConst printStringName;
        printStringName.type = CONST_UTF8;
        printStringName.value.utf8 = "printString";
        table.push_back(printStringName);

        STConst printStringDesc;
        printStringDesc.type = CONST_UTF8;
        printStringDesc.value.utf8 = "(Ljava/lang/String;)V";
        table.push_back(printStringDesc);

        STConst printStringNT;
        printStringNT.type = CONST_NAMETYPE;
        printStringNT.value.args.arg1 = 26;
        printStringNT.value.args.arg2 = 27;
        table.push_back(printStringNT);

        STConst printStringMethod;
        printStringMethod.type = CONST_METHODREF;
        printStringMethod.value.args.arg1 = 9;
        printStringMethod.value.args.arg2 = 28;
        table.push_back(printStringMethod);


        //Print object block 30 31 32 33
        STConst printObjectName;
        printObjectName.type = CONST_UTF8;
        printObjectName.value.utf8 = "printObject";
        table.push_back(printObjectName);

        STConst printObjectDesc;
        printObjectDesc.type = CONST_UTF8;
        printObjectDesc.value.utf8 = "(Ljava/lang/Object;)V";
        table.push_back(printObjectDesc);

        STConst printObjectNT;
        printObjectNT.type = CONST_NAMETYPE;
        printObjectNT.value.args.arg1 = 30;
        printObjectNT.value.args.arg2 = 31;
        table.push_back(printObjectNT);

        STConst printObjectMethod;
        printObjectMethod.type = CONST_METHODREF;
        printObjectMethod.value.args.arg1 = 9;
        printObjectMethod.value.args.arg2 = 32;
        table.push_back(printObjectMethod);


        STConst printClass;
        printClass.type = CONST_UTF8;
        printClass.value.utf8 = "Print";
        table.push_back(printClass);


        STConst RTLRead;
    RTLRead.type = CONST_CLASS;
    RTLRead.value.val_int  = 56;
    table.push_back(RTLRead);


    //Print int block 36 37 38 39
    STConst readIntName;
    readIntName.type = CONST_UTF8;
    readIntName.value.utf8 = "Int";
    table.push_back(readIntName);

    STConst readIntDesc;
    readIntDesc.type = CONST_UTF8;
    readIntDesc.value.utf8 = "(Ljava/lang/String;)I";
    table.push_back(readIntDesc);

    STConst readIntNT;
    readIntNT.type = CONST_NAMETYPE;
    readIntNT.value.args.arg1 = 36;
    readIntNT.value.args.arg2 = 37;
    table.push_back(readIntNT);

    STConst readIntMethod;
    readIntMethod.type = CONST_METHODREF;
    readIntMethod.value.args.arg1 = 35;
    readIntMethod.value.args.arg2 = 38;
    table.push_back(readIntMethod);


    //Read float block 40 41 42 43
    STConst readFloatName;
    readFloatName.type = CONST_UTF8;
    readFloatName.value.utf8 = "Float";
    table.push_back(readFloatName);

    STConst readFloatDesc;
    readFloatDesc.type = CONST_UTF8;
    readFloatDesc.value.utf8 = "(Ljava/lang/String;)F";
    table.push_back(readFloatDesc);

    STConst readFloatNT;
    readFloatNT.type = CONST_NAMETYPE;
    readFloatNT.value.args.arg1 = 40;
    readFloatNT.value.args.arg2 = 41;
    table.push_back(readFloatNT);

    STConst readFloaMethod;
    readFloaMethod.type = CONST_METHODREF;
    readFloaMethod.value.args.arg1 = 35;
    readFloaMethod.value.args.arg2 = 42;
    table.push_back(readFloaMethod);


    //Read char block 44 45 46 47
    STConst readCharName;
    readCharName.type = CONST_UTF8;
    readCharName.value.utf8 = "readChar";
    table.push_back(readCharName);

    STConst readCharDesc;
    readCharDesc.type = CONST_UTF8;
    readCharDesc.value.utf8 = "()C";
    table.push_back(readCharDesc);

    STConst readCharNT;
    readCharNT.type = CONST_NAMETYPE;
    readCharNT.value.args.arg1 = 44;
    readCharNT.value.args.arg2 = 45;
    table.push_back(readCharNT);

    STConst readCharMethod;
    readCharMethod.type = CONST_METHODREF;
    readCharMethod.value.args.arg1 = 35;
    readCharMethod.value.args.arg2 = 46;
    table.push_back(readCharMethod);


    //Read bool block 48 49 50 51
    STConst readBoolName;
    readBoolName.type = CONST_UTF8;
    readBoolName.value.utf8 = "readBool";
    table.push_back(readBoolName);

    STConst readBoolDesc;
    readBoolDesc.type = CONST_UTF8;
    readBoolDesc.value.utf8 = "()B";
    table.push_back(readBoolDesc);

    STConst readBoolNT;
    readBoolNT.type = CONST_NAMETYPE;
    readBoolNT.value.args.arg1 = 48;
    readBoolNT.value.args.arg2 = 49;
    table.push_back(readBoolNT);

    STConst readBoolMethod;
    readBoolMethod.type = CONST_METHODREF;
    readBoolMethod.value.args.arg1 = 35;
    readBoolMethod.value.args.arg2 = 50;
    table.push_back(readBoolMethod);

    //Read string block 52 53 54 55
    STConst readStringName;
    readStringName.type = CONST_UTF8;
    readStringName.value.utf8 = "readString";
    table.push_back(readStringName);

    STConst readStringDesc;
    readStringDesc.type = CONST_UTF8;
    readStringDesc.value.utf8 = "()Ljava/lang/String;";
    table.push_back(readStringDesc);

    STConst readStringNT;
    readStringNT.type = CONST_NAMETYPE;
    readStringNT.value.args.arg1 = 52;
    readStringNT.value.args.arg2 = 53;
    table.push_back(readStringNT);

    STConst readStringMethod;
    readStringMethod.type = CONST_METHODREF;
    readStringMethod.value.args.arg1 = 35;
    readStringMethod.value.args.arg2 = 54;
    table.push_back(readStringMethod);

    STConst readClass;
    readClass.type = CONST_UTF8;
    readClass.value.utf8 = "Read";
    table.push_back(readClass);

    STConst RTLStringOperations;
RTLStringOperations.type = CONST_CLASS;
RTLStringOperations.value.val_int  = 62;
table.push_back(RTLStringOperations);

//Print int block 36 37 38 39
STConst concString;
concString.type = CONST_UTF8;
concString.value.utf8 = "ConcString";
table.push_back(concString);

STConst concStringDesc;
concStringDesc.type = CONST_UTF8;
concStringDesc.value.utf8 = "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;";
table.push_back(concStringDesc);

STConst concStringNT;
concStringNT.type = CONST_NAMETYPE;
concStringNT.value.args.arg1 = 58;
concStringNT.value.args.arg2 = 59;
table.push_back(concStringNT);

STConst concStringMethod;
concStringMethod.type = CONST_METHODREF;
concStringMethod.value.args.arg1 = 57;
concStringMethod.value.args.arg2 = 60;
table.push_back(concStringMethod);

STConst stringClass;
stringClass.type = CONST_UTF8;
stringClass.value.utf8 = "StringOperations";
table.push_back(stringClass);



}


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

                                printf("Varuble have wrong type or not declarate\n");
                                exit(EXIT_FAILURE);
                        }
                }
                else{

                        if(strcmp(type,update_varuble(globalroot,op)) != 0)
                        {
                                printf("Varuble have wrong type or not declarate\n");
                                exit(EXIT_FAILURE);
                        }
                }
        }

        return type;
}

void check_equal(char *left,char *right){

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
                printf("Wrong equal TYPE %s %s \n",right,left);
                exit (EXIT_FAILURE);
        }
        return;
}
void mult_declaration(NStmtList *root,NExpr *var){
        int count = 0;
        struct NStmt * current = root->first;
        while (current != NULL) {
                if(current->type == STMT_BLOCK)
                {
                        struct NStmtList* result = (NStmtList*)malloc(sizeof(NStmtList));
                        result->first = current;
                        update_varuble(result,var);
                }

                if(current->type == STMT_ASSIGN && var->type == EXPR_ID_LIST) {

                        if(current->var->type != EXPR_MAS) {

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
        case INTTy:       strcpy(str,"I ");    break;
        case FLOATTy:     strcpy(str,"F ");    break;
        case DOUBLETy:    strcpy(str,"D ");    break;
        case BOOLTy:      strcpy(str,"B ");    break;
        case STRINGTy:    strcpy(str,"S ");    break;
        case VOIDTy:      strcpy(str,"V ");     break;
        case ARRAYTy:     strcpy(str,"A ");     break;
        default:           break;
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

  for(auto c : Main_varubles)
  {
    if(c->name != NULL  && var->name != NULL)
    if(strcmp(c->name,var->name)==0)
    {
      printf("%s %s", c->name , var->name);
      exit(EXIT_FAILURE);
      if(c->type != EXPR_ID_LIST && c->type != EXPR_ID && c->type != EXPR_MAS)
      {
              return return_Expr_Init_Type(c);
      }
      else{

        char * str = (char*)malloc(sizeof(char)*33);
        strcat(str,return_varuble_type(c));
        return str;
      }
    }
  }

  if(var->varconstant != NULL) {
          if(var->vartype != NULL)
          {

          char * str = (char*)malloc(sizeof(char)*33);;

          strcpy(str,return_varuble_type(var));

          /* тут вставить сбор в контейнер expr */
          if(!(std::find(Main_varubles.begin(), Main_varubles.end(), var) != Main_varubles.end()))
          {
            countofvar = countofvar  + 1;
            var->id = countofvar;
            Main_varubles.push_back(var);
          }
          return str;

  }
}



        if(var->type == EXPR_TABLE)
        {
                char * str = (char*)malloc(sizeof(char)*33);
                strcat(str,return_varuble_type(var));

                return str;
        }

        if(var->type != EXPR_ID_LIST && var->type != EXPR_ID && var->type != EXPR_MAS)
        {
                return return_Expr_Init_Type(var);
        }

        bool exist = false;
        struct NStmt * current = root->first;

        while (current != NULL) {

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

                                                STConst name;
                                                name.next = NULL;
                                                name.type = CONST_UTF8;
                                                name.value.utf8  = currentf->var->idlist->first->name;
                                                table.push_back(name);
                                                mult_declaration(globalroot,var);
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

                                                        exist = true;
                                                        char * str = (char*)malloc(sizeof(char)*33);;

                                                        strcpy(str,return_varuble_type(currentf->var));

                                                        /* тут вставить сбор в контейнер expr */
                                                        if(!(std::find(Main_varubles.begin(), Main_varubles.end(), currentf->var) != Main_varubles.end()))
                                                        {
                                                          countofvar  = countofvar  + 1;
                                                          var->id = countofvar;
                                                          currentf->var->id = countofvar;
                                                          Main_varubles.push_back(var);
                                                        }


                                                        return str;
                                                        break;
                                                }

                                        }

                                }
                                currentf = currentf->next;
                        }
                }


                if((var->type == EXPR_MAS || var->type == EXPR_ID ) && current->type == STMT_ASSIGN)
                {
                        if(var->type == EXPR_ID) {

                        }
                        if (current->var->type != EXPR_MAS) {
                                if(var->type == EXPR_MAS && current->var->type != EXPR_MAS)
                                {
                                        if(var->left->idlist != NULL) {
                                                if(strcmp(current->var->idlist->first->name, var->left->idlist->first->name) == 0  && strlen(current->var->idlist->first->name) == strlen(var->left->idlist->first->name))
                                                {
                                                        exist = true;
                                                        printf("Array founded with type %s\n",return_varuble_type(current->var));
                                                        return return_varuble_type(current->var);
                                                }
                                        }
                                }
                                else if(strcmp(current->var->idlist->first->name, var->name) == 0  && strlen(current->var->idlist->first->name) == strlen(var->name))
                                {
                                        printf("YA EBAL SSSSSSSSS\n" );
                                        exist = true;
                                }
                        }
                }
                if(current->type == STMT_ASSIGN ) {
                }

                if(current->type == STMT_ASSIGN && var->type == EXPR_ID_LIST) {

                        if(current->var->type == EXPR_MAS)
                        {

                        }

                        else if(strcmp(var->idlist->first->name,current->var->idlist->first->name)==0)
                        {
                                exist = true;

                                mult_declaration(globalroot,var);

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

                                        exist = true;

                                        char * str = (char*)malloc(sizeof(char)*33);

                                        if(strcmp(return_varuble_type(current->var),"V ") == 0)
                                        {
                                                switch (update_varuble(globalroot,current->expr)[0]) {
                                                case 'I':    var->vartype->type = INTTy;     break;
                                                case 'F':    var->vartype->type = FLOATTy;   break;
                                                case 'D':    var->vartype->type = DOUBLETy;  break;
                                                case 'B':    var->vartype->type = BOOLTy;    break;
                                                case 'S':    var->vartype->type = STRINGTy;  break;
                                                case 'A':    var->vartype->type = ARRAYTy;   break;
                                                default:                break;
                                                }
                                        }

                                        strcpy(str,return_varuble_type(current->var));

                                        if(!(std::find(Main_varubles.begin(), Main_varubles.end(), current->var) != Main_varubles.end()))
                                        {
                                          countofvar  = countofvar  + 1;
                                          var->id = countofvar ;
                                          current->var->id = countofvar ;
                                          Main_varubles.push_back(var);

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
                                }
                                if(current->expr->type != NULL && exist)
                                {
                                        return return_Expr_Init_Type(current->expr);
                                }
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


                                if(strcmp("D",type) == 0 || strcmp("F",type) == 0)
                                {
                                        if(strcmp("F",str) == 0 || strcmp("D",str) == 0 || strcmp("I",str) == 0)
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
                                      if(str[0] == type[0])
                                      {
                                        result = true;
                                        return true;
                                      } else {
                                        printf("Return doesnot exist or wrong return value %s %s ", str , type);
                                        exit(EXIT_FAILURE);
                                        result = false;
                                      }
                                }



                        }
                        else if(strcmp(type, "V") == 0)
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

                                if(strcmp("D",type) == 0 || strcmp("F",type) == 0)
                                {
                                        if(strcmp("F",strbody) == 0 || strcmp("D",strbody) == 0 || strcmp("I",strbody) == 0)
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

        if(strcmp(type, "V") == 0)
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

void check_function_call(NStmtList *root,NExpr *var){

}
char * get_function_type(struct NFunc * f){
  if(strcmp("toFloat",f->name->last->name) == 0)
  {
    return "F";
  }
        if(strcmp("toInt",f->name->last->name) == 0)
        {
          return "I";
        }
        if(strcmp("readLine",f->name->last->name) == 0)
        {
                return "S";
        }
        if(strcmp("count",f->name->last->name) == 0)
        {
                return "I";
        }
        char * str = (char*)malloc(sizeof(char)*33);;

        switch (f->vartype->type) {
        case INTTy:       strcpy(str,"I");    break;
        case FLOATTy:     strcpy(str,"F");    break;
        case DOUBLETy:    strcpy(str,"D");    break;
        case BOOLTy:      strcpy(str,"B");    break;
        case STRINGTy:    strcpy(str,"S");    break;
        case VOIDTy:      strcpy(str,"V");     break;
        default:           break;
        }
        return str;
}
void check_function_args(struct NExpr * cur){

        if (strcmp(cur->left->idlist->first->name, "print") == 0 || strcmp(cur->left->idlist->first->name, "toInt") == 0  ||  strcmp(cur->left->idlist->first->name, "toFloat") == 0)
        {
                if(cur->right->idlist->first != NULL) {
                        if(cur->right->idlist->first->type==EXPR_MINUS ||cur->right->idlist->first->type==EXPR_PLUS || cur->right->idlist->first->type==EXPR_MUL || cur->right->idlist->first->type==EXPR_DIV || cur->right->idlist->first->type==EXPR_MOD)
                        {

                            check_stack_operation(create_stack_operation(cur->right->idlist->first));

                        }
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

        if(cur->left->idlist->first->next != NULL) {
                if(strcmp(cur->left->idlist->first->next->name, "count") == 0 )
                {
                        if(cur->right->idlist->first != NULL)
                        {
                                printf("Function have extra argument\n");
                                exit (EXIT_FAILURE);
                        }
                        return;
                }
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
                                if(cura->type == EXPR_ID_LIST) {
                                        strcat(newstr,update_varuble(globalroot,cura));
                                }
                                else{
                                        strcat(newstr,return_Expr_Init_Type(cura));
                                }

                                cura = cura->next;
                        }
                        strcat(newstr,")");



                        if (strcmp(str, newstr) != 0)
                        {
                                printf("Function has wrong arguments\n");
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
                                if(cura->type == EXPR_ID_LIST) {
                                        strcat(newstr,update_varuble(globalroot,cura));
                                }
                                else{
                                        strcat(newstr,return_Expr_Init_Type(cura));
                                }

                                cura = cura->next;
                        }
                        strcat(newstr,")");


                        if (strcmp(str, newstr) != 0)
                        {
                                printf("Function has wrong arguments\n");
                                exit (EXIT_FAILURE);
                        }
                        else{

                        }
                        break;
                }
        }
        if(!exist) {
                printf("Function  doesnot exist \n");
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
                                strcat(str,"V");
                        }else{
                                strcat(str,get_function_type(current->func));
                        }
                        if((st_constant_index( CONST_UTF8, (void*)(str)) == -1)) {
                                STConst code;
                                code.next = NULL;
                                code.type = CONST_UTF8;
                                code.value.utf8  = str;
                                table.push_back(code);
                        }
                        name_of_methods.insert(name_of_methods.end(),func_num - 1);
                        discriptor_of_methods.insert(discriptor_of_methods.end(),func_num);

                        STConst name_type;
                        name_type.next = NULL;
                        name_type.type = CONST_NAMETYPE;
                        name_type.value.args.arg1  = func_num - 1;
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
                                        printf("Redefine function\n");
                                        exit(EXIT_FAILURE);
                                }
                        }
                        main_functions_list.push_back(*current->func);
                }
                current = current->next;
        }
}

void create_table(NStmtList *root){

        table.clear();
        buildBaseTable();

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
                                printf("Redefine function\n");
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

                        if(strcmp(node->expr->left->idlist->first->name,"toInt" )==0)
                        {
                          if(strcmp(update_varuble(globalroot,node->var),"V ") ==0){
                            node->var->vartype->type = INTTy;
                          }
                                check_equal(update_varuble(globalroot,node->var),"I ");

                        }

                        if(strcmp(node->expr->left->idlist->first->name,"toFloat" )==0)
                        {
                          if(strcmp(update_varuble(globalroot,node->var),"V ") ==0){
                            node->var->vartype->type = FLOATTy;
                          }
                                check_equal(update_varuble(globalroot,node->var),"F ");

                        }

                        if(strcmp(node->expr->left->idlist->first->name,"readLine" )==0)
                        {
                            printf("%s",update_varuble(globalroot,node->var));
                          if(strcmp(update_varuble(globalroot,node->var),"V ") ==0){

                            node->var->vartype->type = STRINGTy;

                          }
                                check_equal(update_varuble(globalroot,node->var),"S ");

                        }
                        if(node->expr->left->idlist->first->next != NULL)
                        if(strcmp(node->expr->left->idlist->first->next->name,"count" )==0)
                        {
                          if(strcmp(update_varuble(globalroot,node->var),"V ") ==0){
                            node->var->vartype->type = INTTy;
                          }
                                check_equal(update_varuble(globalroot,node->var),"I ");
                        }
                }

                else{

                        check_equal(update_varuble(globalroot,node->var),update_varuble(globalroot,node->expr));
                        if(node->expr->type == EXPR_TABLE && node->expr->array_id == 0)
                        {
                          node->expr->vartype = node->var->vartype;
                          node->expr->array_id = node->var->id;

                          struct NTblElem * currentElem = node->expr->table->first;
                          while(currentElem != NULL)
                          {
                            st_stmt_expr(currentElem->value);
                            update_varuble(globalroot,currentElem->value);
                            currentElem = currentElem->next;
                          }
                        }

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
        st_stmt_expr(node->start);
        st_stmt_expr(node->step);
        st_stmt_list(node->body);
}
void st_stmt_func(struct NStmt * node) {

        print_function_param(node->func->name->last->name,node);

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
                        node->id = st_constant_index(CONST_INT, (void *)&(node->Int));
                }
                else{
                  node->id = st_constant_index(CONST_INT, (void *)&(node->Int));
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
                        node->id = st_constant_index(CONST_FLOAT, (void *)&(node->Float));

                }
                else{
                  node->id = st_constant_index(CONST_FLOAT, (void *)&(node->Float));
                }
        }

        case EXPR_DOUBLE: {
                if (st_constant_index( CONST_DOUBLE, (void *)&(node->Double)) == -1) {
                        STConst cfloat;
                        cfloat.next = NULL;

                        cfloat.type = CONST_DOUBLE;
                        cfloat.value.val_double = node->Double;
                        node->id = st_constant_index(CONST_DOUBLE, (void *)&(node->Double));
                        table.push_back(cfloat);
                }
                else{
                  node->id = st_constant_index(CONST_DOUBLE, (void *)&(node->Double));
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

                        node->id = st_constant_index( CONST_UTF8, (void*)(node->name)) + 1;
                }
                else{
                  node->id = st_constant_index(CONST_UTF8, (void *)(node->name)) + 1;
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
                if(node->vartype != NULL) {
                        if(node->idlist->first->name != NULL)
                        {
                          if(!(std::find(Main_varubles.begin(), Main_varubles.end(), node) != Main_varubles.end()))
                          {
                          countofvar  = countofvar  + 1;
                          node->id = countofvar ;
                          Main_varubles.push_back(node);

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
list<NExpr*> tempMain = Main_varubles;


        int index = 1;



        printf("Method list size = %d\n",functions_list.size() + main_functions_list.size());
        for (auto t : main_functions_list) {
              //  table.clear();
              countofvar = -1;
               Main_varubles.clear();
                globalroot = t.body;
                st_stmt_list(t.body);
                printf("%s:\n",t.name->last->name);
                printf("List local varubles:\n");
                for (auto c : table) {
                        switch (c.type) {
                        case CONST_UTF8:      if(strstr(c.value.utf8," ")== 0 && strlen(c.value.utf8) > 0) {printf("%5d: ", index); printf("'%s'\n", c.value.utf8); index++;}      break;
                        }
                }
                function_varubles.push_back(Main_varubles);
                printf("\n");
                index = 1;
        }

        for (auto t : functions_list) {
              //  table.clear();
                Main_varubles.clear();
                              countofvar = 0;
                globalroot = t.body;
                st_stmt_list(t.body);
                printf("%s:\n",t.name->last->name);
                printf("List local varubles:\n");
                for (auto c : table) {
                        switch (c.type) {
                        case CONST_UTF8:      if(strstr(c.value.utf8," ")== 0 && strlen(c.value.utf8) > 0) {printf("%5d: ", index); printf("'%s'\n", c.value.utf8); index++;}      break;
                        }
                }
                function_varubles.push_back(Main_varubles);
                printf("\n");
                index = 1;
        }
      Main_varubles = tempMain;

        globalroot = tempGlobal;
        //table = tempTable;
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

                default:              break;
                }
                index++;
        }
}

#endif
