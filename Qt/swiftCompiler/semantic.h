#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "tree_nodes.h"
#include <stdlib.h>
#include <stdio.h>

#include <QList>
#include "semantic_structs.h"
#include <QDebug>


class semantic
{
public:
    QList <st_const> table;

    QList <QList<st_const>> functions_list;

    char * get_function_args(struct NFunc * f);
    void print_function_param(char * function,NStmtList *root);
    void create_header(NStmtList *root);

    void create_table(struct NStmtList * root);
    void st_stmt(struct NStmt * node);
    void st_stmt_switch_list(struct NCaseList * node);
    void st_stmt_switch(struct NSwitch * node);
    void st_stmt_while(struct NWhile * node);
    void st_stmt_for(struct NFor * node);
    QList<st_const> st_stmt_func(struct NFunc * node);
    void st_stmt_if(struct NIf * node);
    void st_stmt_expr(struct NExpr * node);
    void st_stmt_list(struct NStmtList * node);
    void get_function_body(struct NStmtList * node);
    int st_constant_index(enum st_const_types type, const void * value);
    void printTable();
    semantic();
};

#endif // SEMANTIC_H
