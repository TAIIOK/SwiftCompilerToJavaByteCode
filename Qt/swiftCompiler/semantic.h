#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "tree_nodes.h"
#include <stdlib.h>
#include <stdio.h>

class semantic
{
public:
    void create_tree(struct NStmtList * root);
    void st_stmt(struct NStmt * node);
    void st_stmt_switch_list(struct NCaseList * node);
    void st_stmt_switch(struct NSwitch * node);
    void st_stmt_while(struct NWhile * node);
    void st_stmt_for(struct NFor * node);
    void st_stmt_func(struct NFunc * node);
    void st_stmt_if(struct NIf * node);
    void st_stmt_expr(struct NExpr * node);
    void st_stmt_list(struct NStmtList * node);

    semantic();
};

#endif // SEMANTIC_H
