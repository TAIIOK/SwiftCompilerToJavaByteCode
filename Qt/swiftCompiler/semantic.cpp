#include "semantic.h"

semantic::semantic()
{

}

void semantic::printTable()
{
    for(int i = 0; i < table.size(); i++)
    {
        switch (table[i].type) {
            case CONST_UTF8:      printf("'%s'", table[i].value.utf8);      break;
            case CONST_INT:       printf("%d", table[i].value.val_int);   break;
            case CONST_FLOAT:     printf("%f", table[i].value.val_float); break;
            case CONST_DOUBLE:    printf("%f", table[i].value.val_double); break;
            case CONST_CLASS:     printf("%d", table[i].value.val_int); break;
            case CONST_STRING:    printf("%d", table[i].value.args.arg1); break;

            case CONST_FIELDREF:
            case CONST_METHODREF:
            case CONST_NAMETYPE: printf("%d %d", table[i].value.args.arg1, table[i].value.args.arg2); break;

            default:              printf("==WTF?=="); break;
        }
    printf("\n");

    }
}

char * semantic::get_function_args(struct NFunc * f)
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

void semantic::print_function_param(char * function,NStmtList *root){
    char * str = (char*)malloc(sizeof(char)*33);;
    struct NStmt * current = root->first;
    while (current != NULL) {
        if(current->type == STMT_FUNC)
        {

         if(strcmp(current->func->name->last->name,function))
         {
             if(current->func->args->first == NULL)
             {
                 qDebug() << current->func->args->first;
                 printf("1111111111111111111111111111111111111111111111111111111111");
                 strcat(str,"()");

             }
             else{
                 strcat(str,get_function_args(current->func));
             }
             if(current->func->vartype == NULL)
             {

             }else{

             }

         }
        }
        current = current->next;
    }

    printf("%s",str);

}

void semantic::create_header(NStmtList *root){
STConst code;
code.next = NULL;
code.type = CONST_UTF8;
code.value.utf8  = "Code";
table.append(code);
STConst main;
main.next = NULL;
main.type = CONST_UTF8;
main.value.utf8  = "Main";
table.append(main);

STConst classs;
classs.next = NULL;
classs.type = CONST_CLASS;
classs.value.val_int  = 2;
table.append(classs);
print_function_param("main",root);
}
void semantic::create_table(NStmtList *root){

    table.clear();
    create_header(root);
    struct NStmt * current = root->first;
    while (current != NULL) {

        st_stmt(current);
        current = current->next;
    }

    printTable();

}

void semantic::st_stmt_list(struct NStmtList * node) {
    struct NStmt * current = node->first;
    while (current != NULL) {

        st_stmt(current);
        current = current->next;
    }
}

void semantic::st_stmt(struct NStmt * node) {
    switch (node->type) {
        case STMT_WHILE:  st_stmt_while(node->while_loop);                  break;
        case STMT_FOR:    st_stmt_for(node->for_loop);                      break;
        case STMT_EXPR:   st_stmt_expr(node->expr);                         break;
        case STMT_BLOCK:  st_stmt_list(node->list);                         break;
        case STMT_REPEAT: st_stmt_while(node->while_loop);                  break;
        case STMT_LFUNC:  st_stmt_func(node->func);                         break;
        case STMT_RETURN: if (node->expr != 0) st_stmt_expr(node->expr); break;
        case STMT_IF:     st_stmt_if(node->if_tree);                        break;
        case STMT_SWITCH:  st_stmt_switch(node->switch_tree);               break;

        case STMT_FUNC: {
            // Switch to local constant table and initialize it.
    //        st_current_const_table  = &(node->func->const_table);
     //       st_current_const_last   = &(node->func->const_last);
      //      *st_current_const_table = st_new_const_table();
        //    *st_current_const_last  = *st_current_const_table;

            // Fill table.
           functions_list.append(st_stmt_func(node->func));

            // Switch to global.
          //  st_current_const_table = &st_const_table;
           // st_current_const_last  = &st_const_last;
        }
        break;

        case STMT_ASSIGN:
        case STMT_LASSIGN:
            st_stmt_expr(node->var);
            st_stmt_expr(node->expr);
            break;
    }
}

void semantic::st_stmt_switch_list(struct NCaseList * node) {
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
void semantic::st_stmt_switch(struct NSwitch * node){
  st_stmt_expr(node->Name);

 // printf("%d\n",(int)node->Name->type);


  st_stmt_switch_list(node->caselist);
}
void semantic::st_stmt_while(struct NWhile * node) {
    st_stmt_expr(node->condition);
    st_stmt_list(node->body);
}

void semantic::st_stmt_for(struct NFor * node) {
    st_stmt_expr(node->name);
    st_stmt_expr(node->start->right);
    st_stmt_expr(node->start->left);
    st_stmt_list(node->body);
}

QList<st_const> semantic::st_stmt_func(struct NFunc * node) {

      QList<st_const> temp;

     STConst func;
     func.type == CONST_UTF8;
     func.next == NULL;
     func.value.utf8 = node->name->last->name;

     st_stmt_list(node->body);

     return temp;

}

void semantic::get_function_body(struct NStmtList * node)
{
    QList<st_const> temp_body;

    struct NStmt * current = node->first;
    while (current != NULL) {
        st_stmt(current);
        current = current->next;
    }

}

void semantic::st_stmt_if(struct NIf * node) {
    st_stmt_list(node->body);

    struct NIf* current = node->elseiflist->first;
    while (current != NULL)
    {
        st_stmt_if(current);
        current = current->next;
    }

    st_stmt_list(node->elsebody);
}

void semantic::st_stmt_expr(struct NExpr * node) {
    switch (node->type) {
        case EXPR_INT: {

            if (st_constant_index(CONST_INT, (void *)&(node->Int)) == -1) {
                STConst cint;
                cint.next = NULL;

                cint.type = CONST_INT;
                cint.value.val_int = node->Int;
               table.append(cint);
            }


        break;

        case EXPR_FLOAT: {
                if (st_constant_index(CONST_FLOAT, (void *)&(node->Float)) == -1) {
                    STConst cint;
                    cint.next = NULL;

                    cint.type = CONST_FLOAT;
                    cint.value.val_float = node->Float;
                   table.append(cint);
                }
        }

        case EXPR_DOUBLE: {
                if (st_constant_index(CONST_DOUBLE, (void *)&(node->Double)) == -1) {
                    STConst cint;
                    cint.next = NULL;

                    cint.type = CONST_DOUBLE;
                    cint.value.val_double = node->Double;
                   table.append(cint);
                }

        }
        break;

        case EXPR_STR: {

                if (st_constant_index(CONST_UTF8, (void *)&(node->name)) == -1) {
                    STConst cint;
                    cint.next = NULL;

                    cint.type = CONST_UTF8;
                    cint.value.utf8 = node->name;
                   table.append(cint);
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
}

int semantic::st_constant_index(enum st_const_types type, const void *value)
{
    QList<st_const>::iterator cur;
    int index = 0;
    for (cur = table.begin(); cur != table.end(); ++cur){
        if (cur->type == type) {
            switch (type) {
                case CONST_INT:
                    if (cur->value.val_int == *((int *)value)) {
                        return index;
                    }
                break;

                case CONST_DOUBLE:
                    if (cur->value.val_double == *((double *)value)) {
                        return index;
                    }
                break;


                case CONST_FLOAT:
                    if (cur->value.val_float == *((double *)value)) {
                        return index;
                    }
                break;

                case CONST_UTF8:
                    if (strcmp(cur->value.utf8, (const char *)value) == 0) {
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
