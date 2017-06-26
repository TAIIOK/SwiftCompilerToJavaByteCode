#include <stdlib.h>
#include "tree_nodes.h"
#include <stdio.h>
#include <string.h>
#include <cmath>
/*
 * Function definition
 */
void update_tree(struct NStmt* current, NStmt* prev, NStmtList* root, NStmtList* list, bool first_in_list, bool last_in_list);
void update_tree_if(struct NIf* current, struct NStmtList* root);
void set_parent_func(struct NStmt* child, struct NFunc* parent);
void set_null_field_expr(struct NExpr* expr);

struct NExpr * get_clone_for_clojure(struct NExpr * expr)
{
    struct NExpr * clone = (struct NExpr*)malloc(sizeof(struct NExpr));
    set_null_field_expr(clone);
    clone->type = expr->type;
    clone->idlist = expr->idlist;
    clone->origin = expr;
    clone->left = expr->left;
    clone->right = expr->right;
    return clone;
}

bool compare_var_names(struct NExpr* first, struct NExpr * second)
{
    if( first->type == second->type)
    {
        if (first->type == EXPR_ID || first->type == EXPR_STR)
        {
            return strlen(first->name) == strlen(second->name) && strcmp(first->name,second->name) == 0;
        }
        else if (first->type == EXPR_ID_LIST)
        {
            struct NExpr * fcur, * scur;
            bool eq = true;
            fcur = first->idlist->first;
            scur = second->idlist->first;
            while(fcur!=NULL&&scur!=NULL&&eq)
            {
                eq = compare_var_names(fcur,scur);
                fcur = fcur->next;
                scur = scur->next;
            }
            if(eq && (fcur == NULL && scur != NULL) && (fcur != NULL && scur == NULL))
                eq = false;
            return eq;
        }
        else if (first->type == EXPR_MET || first->type == EXPR_MAS)
        {
            bool eq = false;
            eq = compare_var_names(first->left,second->left);
            if (eq)
            {
                eq = compare_var_names(first->right,second->right);
            }
            return eq;
        }
        else if (first->type == EXPR_INT)
        {
            return first->Int - second->Int == 0;
        }
        else if (first->type == EXPR_DOUBLE)
        {
            return abs(first->Double - second->Double) < 0.0000001;
        }
        else if (first->type == EXPR_FLOAT)
        {
            return abs(first->Float - second->Float) < 0.0000001;
        }
        else if (first->type == EXPR_UMIN)
        {
            return compare_var_names(first->right,second->right);
        }
        else
            return false;

    }
    else
        return false;
}

struct NExprList * get_vars(struct NStmt* stmt)
{
    struct NExprList* list = (NExprList *)malloc(sizeof(NExprList));
    struct NExprList* list1;
    if (stmt->type == STMT_WHILE || stmt->type == STMT_REPEAT ||
        stmt->type == STMT_FOR || stmt->type == STMT_IF || stmt->type == STMT_BLOCK)
    {
        struct NStmt * cur = NULL;
        if(stmt->type == STMT_WHILE || stmt->type == STMT_REPEAT)
        {
            cur = stmt->while_loop->body->first;
        }
        else if (stmt->type == STMT_FOR)
        {
            cur = stmt->for_loop->body->first;
        }
        else if (stmt->type == STMT_BLOCK)
        {
            cur = stmt->list->first;
        }
        else
        {
            cur = stmt->if_tree->elsebody->first;
            while (cur != NULL)
            {
                list1 = get_vars(cur);
                if (list->first == NULL && list1->first != NULL)
                {
                    list->first = list1->first;
                    list->last = list1->last;
                }
                else if (list1->first != NULL)
                {
                    list->last->next = list1->first;
                    list->last = list1->last;
                }
                cur = cur->next;
                free(list1);
            }

            struct NIf * ift = stmt->if_tree->elseiflist->first;
            while (ift != NULL)
            {
                cur = ift->body->first;
                while (cur != NULL)
                {
                    list1 = get_vars(cur);
                    if (list->first == NULL && list1->first != NULL)
                    {
                        list->first = list1->first;
                        list->last = list1->last;
                    }
                    else if (list1->first != NULL)
                    {
                        list->last->next = list1->first;
                        list->last = list1->last;
                    }
                    cur = cur->next;
                    free(list1);
                }
                ift = ift->next;
            }
            cur = stmt->if_tree->body->first;
        }
        while (cur != NULL)
        {
            list1 = get_vars(cur);
            if (list->first == NULL && list1->first != NULL)
            {
                list->first = list1->first;
                list->last = list1->last;
            }
            else if (list1->first != NULL)
            {
                list->last->next = list1->first;
                list->last = list1->last;
            }
            cur = cur->next;
            free(list1);
        }
    }
    else if (stmt->type == STMT_EXPR && (stmt->expr->type == EXPR_ID_LIST && stmt->expr->type == EXPR_ID))
    {
        if(list->first == NULL)
        {
            list->first = get_clone_for_clojure(stmt->expr);
            list->last = list->first;
        }
        else
        {
            list->last->next = get_clone_for_clojure(stmt->expr);
            list->last = list->last->next;
        }
    }
    else if(stmt->type == STMT_LASSIGN)
    {

        if(list->first == NULL)
        {
            list->first = get_clone_for_clojure(stmt->var);
            list->last = list->first;
        }
        else
        {
            list->last->next = get_clone_for_clojure(stmt->var);
            list->last = list->last->next;
        }
    }
    return list;
}

struct NExprList * get_local_var_table(struct NFunc * func)
{

    struct NExprList* list = (NExprList *)malloc(sizeof(NExprList));
    list->first = NULL;
    list->first = NULL;
    struct NExprList* list1;
    struct NStmt* cur = func->body->first;
    while (cur != NULL)
    {
        list1 = get_vars(cur);
        if(list->first == NULL)
        {
            list->first = list1->first;
            list->last = list1->last;
        }
        else
        {
            list->last->next = list1->first;
            list->last = list1->last;
        }
        free(list1);
        cur = cur->next;
    }
    return list;
}

struct NExprList * compare_tables(struct NExprList * parent, struct NExprList * child)
{
    struct NExpr * pexpr;
    struct NExpr * cexpr = child->first;
    bool isFind;
    struct NExprList* list = (NExprList *)malloc(sizeof(NExprList));
    list->first = NULL;
    list->first = NULL;
    while (cexpr != NULL)
    {
        isFind = false;
        pexpr = parent->first;
        while (pexpr != NULL && !isFind)
        {
            if(compare_var_names(pexpr,cexpr))
            {
                isFind = true;
                if(list->first ==NULL)
                {
                    list->first = get_clone_for_clojure(cexpr);
                    list->first->origin = cexpr->origin;
                    list->last = list->first;
                }
                else
                {
                    list->last->next = get_clone_for_clojure(cexpr);
                    list->last->next->origin = cexpr->origin;
                    list->last = list->last->next;
                }
            }
        }
    }
    return list;

}
void find_clojure_variables(struct NFunc* func)
{
    struct NFunc * pfunc = func->pfunc;
    struct NExprList * clojure_vars;
    struct NExpr * cur, *prev;
    while (pfunc != NULL)
    {
        clojure_vars = compare_tables(pfunc->locals_list,func->locals_list);
        cur = clojure_vars->first;
        while (cur != NULL)
        {
            prev = cur;
            cur->origin->clojure = true;
            cur = cur->next;
            free(prev);
        }
        free(clojure_vars);
    }
}

void update_tree_parent_func(struct NStmtList* root)
{
    struct NStmt* current = root->first;
    while(current!=NULL)
    {
        set_parent_func(current,NULL);
        current = current->next;
    }
}

void update_tree_stmtlist(struct NStmtList* list, struct NStmtList* root)
{
    struct NStmt* current = list->first, * prev = NULL, * next = NULL;
    bool start = true, end = false;
    struct NStmtList* body = list;
    while(current!=NULL)
    {
        next = current->next;
        if (current->next == NULL)
        {
            body = list;
            end = true;
        }
        update_tree(current,prev,root,body,start,end);
        prev = current;
        start = false;
        body = NULL;
        current = next;
    }
}

void update_tree(struct NStmt* current, NStmt* prev, NStmtList* root, NStmtList* list, bool first_in_list, bool last_in_list)
{
    bool start = true, end = false;
    struct NStmtList* body = NULL;
    switch(current->type)
    {
        case STMT_WHILE:
            body = current->while_loop->body;
            update_tree_stmtlist(body,root);
            break;
        case STMT_FOR:
            body = current->for_loop->body;
            update_tree_stmtlist(body,root);
            break;
        case STMT_FUNC:
            body = current->func->body;
            update_tree_stmtlist(body,root);
            if(current != root->first)
            {
                if (prev != NULL)
                {
                    prev->next = current->next;
                }
                if (last_in_list)
                {
                    list->last = prev;
                }
                if (first_in_list)
                {
                    list->first = current->next;
                }
                current->next = root->first;
                root->first = current;
            }
            break;
        case STMT_BLOCK:
            body = current->list;
            update_tree_stmtlist(body,root);
            break;
        case STMT_LFUNC:
            body = current->func->body;
            update_tree_stmtlist(body,root);
            if(current != root->first)
            {
                if (prev != NULL)
                {
                    prev->next = current->next;
                }
                if (last_in_list)
                {
                    list->last = prev;
                }
                if (first_in_list)
                {
                    list->first = current->next;
                }
                current->next = root->first;
                root->first = current;
            }
            break;
        case STMT_REPEAT:
            body = current->while_loop->body;
            update_tree_stmtlist(body,root);
            break;
        case STMT_ASSIGN:
            if (current->expr->type == EXPR_FUNC_DEC_ANON)
            {
                body = current->expr->func->body;
                update_tree_stmtlist(body,root);
                if (current != root->first)
                {
                    if (prev != NULL)
                    {
                        prev->next = current->next;
                    }
                    if (last_in_list)
                    {
                        list->last = prev;
                    }
                    if (first_in_list)
                    {
                        list->first = current->next;
                    }
                    current->next = root->first;
                    root->first = current;
                }
            }
            if(current->var->type == EXPR_MAS)
                current->type = STMT_ASSIGN_MAS;
            break;
        case STMT_LASSIGN:
            if (current->expr->type == EXPR_FUNC_DEC_ANON)
            {
                body = current->expr->func->body;
                update_tree_stmtlist(body,root);
                if (current != root->first)
                {
                    if (prev != NULL)
                    {
                        prev->next = current->next;
                    }
                    if (last_in_list)
                    {
                        list->last = prev;
                    }
                    if (first_in_list)
                    {
                        list->first = current->next;
                    }
                    current->next = root->first;
                    root->first = current;
                }
            }
            if(current->var->type == EXPR_MAS)
                current->type = STMT_LASSIGN_MAS;
            break;
        case STMT_IF:
            update_tree_if(current->if_tree, root);
            break;
    }
}

void update_tree_if(struct NIf* current, struct NStmtList* root)
{
            struct NStmtList* body = current->body;
            update_tree_stmtlist(body,root);
            body = current->elsebody;
            update_tree_stmtlist(body,root);
            struct NIf* elseif = current->elseiflist->first;
            while(elseif != NULL)
            {
                update_tree_if(elseif, root);
                elseif = elseif->next;
            }
}

void set_parent_func(struct NStmt* child, struct NFunc* parent)
{
    if(child->type == STMT_LFUNC || child->type == STMT_FUNC
        || ((child->type == STMT_ASSIGN ||
            child->type == STMT_LASSIGN ||
            child->type == STMT_EXPR) &&
        child->expr->type == EXPR_FUNC_DEC_ANON))
    {
        struct NStmt * cur;
        struct NFunc * func;
        if (child->type == STMT_LFUNC || child->type == STMT_FUNC)
        {
            child->func->pfunc = parent;
            cur = child->func->body->first;
            func = child->func;
        }
        else
        {
            child->expr->func->pfunc = parent;
            cur = child->expr->func->body->first;
            func = child->expr->func;
        }
        find_clojure_variables(func);
        while (cur != NULL)
        {
            set_parent_func(cur,func);
            cur = cur->next;
        }
    }
    else if (child->type == STMT_WHILE || child->type == STMT_REPEAT ||
            child->type == STMT_FOR || child->type == STMT_IF || child->type == STMT_BLOCK)
    {
        struct NStmt * cur = NULL;
        if(child->type == STMT_WHILE || child->type == STMT_REPEAT)
        {
            cur = child->while_loop->body->first;
        }
        else if (child->type == STMT_FOR)
        {
            cur = child->for_loop->body->first;
        }
        else if (child->type == STMT_BLOCK)
        {
            cur = child->list->first;
        }
        else
        {
            cur = child->if_tree->elsebody->first;
            while (cur != NULL)
            {
                set_parent_func(cur,parent);
                cur = cur->next;
            }

            struct NIf * ift = child->if_tree->elseiflist->first;
            while (ift != NULL)
            {
                cur = ift->body->first;
                while (cur != NULL)
                {
                    set_parent_func(cur,parent);
                    cur = cur->next;
                }
                ift = ift->next;
            }
            cur = child->if_tree->body->first;
        }
        while (cur != NULL)
        {
            set_parent_func(cur,parent);
            cur = cur->next;
        }
    }

}

void set_null_field_expr(struct NExpr* expr)
{
    expr->Int = 0;
    expr->Double = 0;
    expr->name = NULL;
    expr->left = NULL;
    expr->right = NULL;
    expr->next = NULL;
    expr->vartype = NULL;
    expr->varconstant = NULL;
    expr->idlist = NULL;
    expr->table = NULL;
    expr->func = NULL;
    expr->clojure = false;
    expr->origin = NULL;
}

struct NExpr* create_op_expr(NExprType type,NExpr* left,NExpr* right)
{
    NExpr* result = (NExpr*)malloc(sizeof(NExpr));
    set_null_field_expr(result);
    result->left = left;
    result->right = right;
    result->type = type;
    return result;

}

struct NExpr* create_expr_id(char* id)
{
    NExpr* result = (NExpr*)malloc(sizeof(NExpr));
    set_null_field_expr(result);
    result->name = id;
    result->type = EXPR_ID;
    return result;
}

struct NExpr* create_expr_string(char* string)
{
    NExpr* result = (NExpr*)malloc(sizeof(NExpr));
    set_null_field_expr(result);
    result->name = string;
    result->type = EXPR_STR;
    return result;
}

struct NExpr* create_expr_int(int value)
{
    NExpr* result = (NExpr*)malloc(sizeof(NExpr));
    set_null_field_expr(result);
    result->Int = value;
    result->type = EXPR_INT;
    return result;
}

struct NExpr* create_expr_double(double value)
{
    NExpr* result = (NExpr*)malloc(sizeof(NExpr));
    set_null_field_expr(result);
    result->Double = value;
    result->type = EXPR_DOUBLE;
    return result;
}

struct NExpr* create_expr_float(float value)
{
    NExpr* result = (NExpr*)malloc(sizeof(NExpr));
    set_null_field_expr(result);
    result->Float = value;
    result->type = EXPR_FLOAT;
    return result;
}

struct NImport* create_import(struct NExpr* func)
{
  struct NImport* result = (NImport*)malloc(sizeof(NImport));
  result->name = func;
  return result;
}

struct NStmt* create_stmt_import(struct NImport* func)
{
  struct NStmt* result = (NStmt*)malloc(sizeof(NStmt));
  result->import = func;
  result->type = STMT_IMPORT;
  return result;
}

struct NExpr* create_expr_boolean(int value)
{
    NExpr* result = (NExpr*)malloc(sizeof(NExpr));
    set_null_field_expr(result);
    result->Int = value;
    result->type = EXPR_BOOL;
    return result;
}

struct NExpr* create_expr_exprlist(struct NExprList* value,struct NVarType* varubltype ,struct NConstant* varlet)
{

    NExpr* result = (NExpr*)malloc(sizeof(NExpr));
    set_null_field_expr(result);
    result->idlist = value;
    result->varconstant = varlet;
    result->vartype = varubltype;

    result->type = EXPR_ID_LIST;

    return result;
}

struct NExpr* create_expr_table(struct NTable* value, struct NVarType* varubltype)
{
    NExpr* result = (NExpr*)malloc(sizeof(NExpr));
    set_null_field_expr(result);
    result->table = value;
    result->vartype = varubltype;
    result->type = EXPR_TABLE;
    return result;
}

struct NExpr* create_expr_func(struct NFunc* value)
{
    NExpr* result = (NExpr*)malloc(sizeof(NExpr));
    set_null_field_expr(result);
    result->func = value;
    result->type = EXPR_FUNC_DEC_ANON;
    return result;
}

struct NExpr* create_expr_nil()
{
    NExpr* result = (NExpr*)malloc(sizeof(NExpr));
    set_null_field_expr(result);
    result->type = EXPR_NIL;
    return result;
}

struct NStmt* create_stmt_func(struct NFunc* func)
{
    struct NStmt* result = (NStmt*)malloc(sizeof(NStmt));
    result->func = func;
    result->type = STMT_FUNC;
    return result;
}

struct NStmt* create_stmt_expr(struct NExpr* expr)
{
    struct NStmt* result = (NStmt*)malloc(sizeof(NStmt));
    result->expr = expr;
    result->type = STMT_EXPR;
    return result;
}

struct NStmt* create_stmt_while(struct NWhile* While, int rep)
{
    struct NStmt* result = (NStmt*)malloc(sizeof(NStmt));
    result->while_loop = While;
    if (rep)
        result->type = STMT_REPEAT;
    else
        result->type = STMT_WHILE;
    return result;
}



struct NStmt* create_stmt_assign(struct NExpr* var, struct NExpr* expr, int local)
{
    struct NStmt* result = (NStmt*)malloc(sizeof(NStmt));
    result->var = var;
    result->expr = expr;
    if (local)
        result->type = STMT_LASSIGN;
    else
    if(var->type == EXPR_ID_LIST){
      /*
      EXPR_INT,
      EXPR_DOUBLE,
      EXPR_FLOAT,
      EXPR_STR
      */
      struct NVarType* varType = (NVarType*)malloc(sizeof(NVarType));

      switch (expr->type)
      {
        case EXPR_INT:
        varType->type = INTTy;
        break;
        case EXPR_DOUBLE:
        varType->type = DOUBLETy;
        break;
        case EXPR_FLOAT:
        varType->type = FLOATTy;
        break;
        case EXPR_STR:
        varType->type = STRINGTy;
        break;
        default:
          break;
      }
      if(var->vartype == NULL && var->varconstant != NULL)
      {
        result->var->vartype = varType;
      }
    }
        result->type = STMT_ASSIGN;
    return result;
}

struct NStmt* create_stmt_for(struct NFor* For)
{
    struct NStmt* result = (NStmt*)malloc(sizeof(NStmt));
    result->for_loop = For;
    result->type = STMT_FOR;
    return result;
}

struct NStmt* create_stmt_if(struct NIf* if_tree)
{
    struct NStmt* result = (NStmt*)malloc(sizeof(NStmt));
    result->if_tree = if_tree;
    result->type = STMT_IF;
    return result;
}

struct NStmt* create_stmt_block(struct NStmtList* stmtlist)
{
    struct NStmt* result = (NStmt*)malloc(sizeof(NStmt));
    result->list = stmtlist;
    result->type = STMT_BLOCK;
    return result;
}

struct NStmt* create_stmt_spec(int ret)
{
    struct NStmt* result = (NStmt*)malloc(sizeof(NStmt));
    if (ret == 1)
        result->type = STMT_RETURN;
    else if (ret == 0)
        result->type = STMT_BREAK;
    else
        result->type = STMT_ENDL;
    return result;
}

struct  NExprList* create_expr_list(struct NExpr* first , struct NVarType* type)
{
    struct NExprList* result = (NExprList*)malloc(sizeof(NExprList));
    result->first = first;
    if(type != NULL){
    result->first->vartype = type;
    result->first->type = EXPR_ID;
    }
    result->last = result->first;
    return result;
}

struct NExprList* add_expr_to_list(struct NExprList* list, struct NExpr* element,struct NVarType* type )
{
    if (type != NULL)
    {
      element->vartype = type;
      element->type = EXPR_ID;
    }
    list->last->next = element;
    list->last = element;
    return list;
}

struct NStmtList* create_stmt_list(struct NStmt* first)
{
    struct NStmtList* result = (NStmtList*)malloc(sizeof(NStmtList));
    result->first = first;
    result->last = first;
    return result;
}

struct NStmtList* add_stmt_to_list(struct NStmtList* list, struct NStmt* element)
{
    if(list->first == NULL)
    {
        list->first = element;
    }
    else
    {
        list->last->next = element;
    }
    list->last = element;
    return list;
}

struct NFor* create_for(struct NExpr* operand, struct NExpr* start, struct NStmtList* body, struct NExpr* step)
{
    struct NFor* result = (NFor*)malloc(sizeof(NFor));
    result->name = operand;
    result->start = start;
    result->step = step;
    result->body = body;
    return result;
}

struct NWhile* create_while(struct NExpr* condition, struct NStmtList* body)
{
    struct NWhile* result = (NWhile*)malloc(sizeof(NWhile));
    result->condition = condition;
    result->body = body;
    return result;
}
struct NStmt* create_stmt_switch(struct NSwitch* switch_tree)
{
    struct NStmt* result = (NStmt*)malloc(sizeof(NStmt));
    result->switch_tree = switch_tree;
    result->type = STMT_SWITCH;
    return result;
}

struct NSwitch* create_switch(struct NExpr* condition, struct NCaseList* caselist)
{
    struct NSwitch* result = (NSwitch*)malloc(sizeof(NSwitch));
    result->Name = condition;
    result->caselist = caselist;
    return result;
}

struct NCaseList* create_case_list(struct NCase* element)
{
    struct NCaseList* result = (NCaseList*)malloc(sizeof(NCaseList));
    result->first = element;
    result->last = element;
    return result;
}
struct NCaseList* add_case_to_list(struct NCaseList* list, struct NCase* element)
{
    if(list->first == NULL)
    {
        list->first = element;
    }
    else
    {
        list->last->next = element;
    }
    list->last = element;
    return list;
}

struct NRange* create_range(int start, int end)
{
  struct NRange* result = (NRange*)malloc(sizeof(NRange));
    result->start = start;
    result->end = end;
  return result;
}

struct NCase* create_case(struct NLabelCase* label, struct NStmtList* body)
{
  struct NCase* result = (NCase*)malloc(sizeof(NCase));
  if(label->name != NULL)
  {
    result->type = DIFFERENT;
    result->name = label->name;

  }
  else{
  result->name = NULL;
  result->type = DEFAULTT;

  }
  result->body = body;
  result->next = NULL;
  return result;
}

struct NLabelCase* create_label_case(struct NExpr* condition,NSwitchCaseType type)
{
  struct NLabelCase* result = (NLabelCase*)malloc(sizeof(NLabelCase));

  result->name = condition;
  result->type = type;

  return result;
}


struct NIf* create_if(struct NExpr* condition, struct NStmtList* body, struct NIfList* elseif_list, struct NStmtList* elsebody)
{
    struct NIf* result = (NIf*)malloc(sizeof(NIf));
    result->condition = condition;
    result->elsebody = elsebody;
    result->body = body;
    result->elseiflist = elseif_list;
    result->next = NULL;
    return result;
}

struct NIfList* create_if_list(struct NIf* element)
{
    struct NIfList* result = (NIfList*)malloc(sizeof(NIfList));
    result->first = element;
    result->last = element;
    return result;
}
struct NIfList* add_if_to_list(struct NIfList* list, struct NIf* element)
{
    if(list->first == NULL)
    {
        list->first = element;
    }
    else
    {
        list->last->next = element;
    }
    list->last = element;
    return list;
}

struct NTblElem* create_tbl_elem(struct NExpr* key, struct NExpr* value)
{
    struct NTblElem* result = (NTblElem*)malloc(sizeof(NTblElem));
    result->key = key;
    result->value = value;
    result->next = NULL;
    return result;
}

struct NTable* create_table(struct NTblElem* first)
{
    struct NTable* result = (NTable*)malloc(sizeof(NTable));
    result->first = first;
    result->last = first;
    return result;
}

struct NTable* add_elem_to_table(struct NTable* list, struct NTblElem* element)
{
    if(list->first == NULL)
    {
        list->first = element;
    }
    else
    {
        list->last->next = element;
    }
    list->last = element;
    return list;
}

struct NFunc* create_func(struct NExprList* args, struct NStmtList* body, struct NVarType* type)
{
    struct NFunc* result = (NFunc*)malloc(sizeof(NFunc));
    result->name = NULL;
    result->vartype = type;
    result->args = args;
    result->body = body;
    result->locals_list = get_local_var_table(result);
    return result;
}

struct NFunc* set_func_name(struct NExprList* name, struct NFunc* result)
{
    result->name = name;
    return result;
}

struct NConstant* create_var_constant_type(NConstantEnum varEnumType)
{
  struct NConstant *result = (NConstant*)malloc(sizeof(NConstant));
  result->constant = varEnumType;
  return result;
}

struct NVarType* create_var_type(NVarEnumType varEnumType)
{
  struct NVarType* result = (NVarType*)malloc(sizeof(NVarType));
  result->type = varEnumType;
  return result;
}

struct NStmt* create_stmt_return(struct NExpr* expr)
{
    struct NStmt* result = (NStmt*)malloc(sizeof(NStmt));
    result->type = STMT_RETURN;
    result->expr = expr;
    return result;
}
