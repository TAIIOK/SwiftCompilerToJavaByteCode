#include <locale.h>
#include <iostream>
#include "tree_nodes.h"
#include "tree_nodes_funcs.h"
#include "tree_print.h"
#include "semantic_tables.h"

#include <QString>
#include "semantic.h"

//#include <conio.h>


using namespace std;
extern "C" FILE *yyin;
extern "C" int yyparse();
extern "C" int yylex();

int main(int argc,char* argv[])
{
    setlocale(LC_ALL, "Russian");
    yyin = fopen(argv[1], "r");

    yyparse();
    update_tree_parent_func(root);
    //update_tree_stmtlist(root,root);
    print_tree(root);
    system("pause");


    FILE* output;
    output = fopen("constant_table.csv","w");
    semantic table;
    table.create_table(root);

    printf("Constant table:\n");
    fprintf(output, "'%s'", ";Constant table:;\n");
    st_fill_tables(root);
    st_print_const(st_const_table);
    st_print_const_file(output,st_const_table);
    struct NStmt * current = root->first;
    while (current != NULL)
    {
        if (current->type == STMT_FUNC)
        {
            printf("Function constant table:\n");
            st_print_const(current->func->const_table);
            fprintf(output, "'%s'", ";Function constant table:;\n");
            st_print_const_file(output,current->func->const_table);
        }
        current = current->next;
    }

    printf("Function list:\n");
    fprintf(output, "'%s'", ";Function list:;\n");
    SList * cur = func_list;
    while (cur != NULL)
    {
        printf("function %s\n", ((NFunc *)(cur->data))->name->last->name );
        fprintf(output, ";'%s';",((NFunc *)(cur->data))->name->last->name);
        cur = cur->next;
    }

    printf("Function methodrefs:\n");
    fprintf(output, "%s",";Function methodrefs:;\n");
    st_print_const(st_func_handles);
    st_print_const_file(output,st_func_handles);

    fclose(output);

}
