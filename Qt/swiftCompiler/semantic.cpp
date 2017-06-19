#include "semantic.h"

semantic::semantic()
{

}


void semantic::create_tree(NStmtList *root){

    table.clear();

    struct NStmt * current = root->first;
    while (current != 0) {
        st_stmt(current);
        current = current->next;
    }

}

void semantic::st_stmt_list(struct NStmtList * node) {
    struct NStmt * current = node->first;
    while (current != 0) {
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
            st_stmt_func(node->func);

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
    st_stmt_expr(node->start);
    st_stmt_expr(node->step);
    st_stmt_list(node->body);
}

void semantic::st_stmt_func(struct NFunc * node) {
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
            /*if (st_constant_index(*st_current_const_table, CONST_INT, (void *)&(node->Int)) == -1) {
                STConst * cint = (STConst *)malloc(sizeof(STConst));
                cint->next = NULL;

                cint->type = CONST_INT;
                cint->value.val_int = node->Int;

                (*st_current_const_last)->next = cint;
                *st_current_const_last = cint;
            }
            */
        }
        break;

        case EXPR_FLOAT: {
        /*
            if (st_constant_index(*st_current_const_table, CONST_FLOAT, (void *)&(node->Float)) == -1) {
                STConst * cfloat = (STConst *)malloc(sizeof(STConst));
                cfloat->next = NULL;

                cfloat->type = CONST_FLOAT;
                cfloat->value.val_float = node->Float;

                (*st_current_const_last)->next = cfloat;
                *st_current_const_last = cfloat;
            }
            */
        }

        case EXPR_DOUBLE: {
        /*
            if (st_constant_index(*st_current_const_table, CONST_DOUBLE, (void *)&(node->Double)) == -1) {
                STConst * cfloat = (STConst *)malloc(sizeof(STConst));
                cfloat->next = NULL;

                cfloat->type = CONST_DOUBLE;
                cfloat->value.val_double = node->Double;

                (*st_current_const_last)->next = cfloat;
                *st_current_const_last = cfloat;

            }
            */
        }
        break;

        case EXPR_STR: {
        /*
            // Make UTF-8
            STConst * utf8 = (STConst *)malloc(sizeof(STConst));
            utf8->next = NULL;

            utf8->type = CONST_UTF8;
            utf8->value.utf8 = node->name; // `strcpy` it in case of problems

            (*st_current_const_last)->next = utf8;
            *st_current_const_last = utf8;

            // Make constant
            STConst * cstr = (STConst *)malloc(sizeof(STConst));
            cstr->next = NULL;

            cstr->type = CONST_STRING;
            cstr->value.args.arg1 = st_constant_index(*st_current_const_table, CONST_UTF8, utf8->value.utf8);

            (*st_current_const_last)->next = cstr;
            *st_current_const_last = cstr;
            */
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
