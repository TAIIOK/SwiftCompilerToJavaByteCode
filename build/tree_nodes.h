#ifndef _H_TREE_NODES_
#define _H_TREE_NODES_

typedef struct st_const STConst;


#include <iostream>
#include <list>     // подключаем заголовок списка
#include <iterator> // заголовок итераторов
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;



enum NVarEnumType{
  NULLTYPE = 0,
  STRINGTy = 1,
  INTTy = 2,
  DOUBLETy = 3,
  FLOATTy = 4,
  BOOLTy = 5,
  CHARACTERTy = 6,
  VOIDTy = 7
};

enum NConstantEnum{
  VART = 1,
  LETT = 2
};

enum NSwitchCaseType {
  DIFFERENT,
  DEFAULTT
};

enum NStmtType {
    STMT_WHILE,
    STMT_FOR,
    STMT_EXPR,
    STMT_FUNC,
    STMT_BLOCK,
    STMT_REPEAT,
    STMT_LFUNC,
    STMT_BREAK,
    STMT_RETURN,
    STMT_ASSIGN,//9
    STMT_ASSIGN_MAS,
    STMT_LASSIGN_MAS,
    STMT_LASSIGN,
    STMT_IF,
    STMT_ENDL, //14
    STMT_SWITCH,
    STMT_IMPORT
};

enum NExprType {
    EXPR_EQ,    //0
    EXPR_NQ,    //1
    EXPR_PLUS,  //2
    EXPR_MINUS, //3
    EXPR_DIV,   //4
    EXPR_MUL,   //5
    EXPR_POW,   //6
    EXPR_LE,    //7
    EXPR_GE,    //8
    EXPR_LT,    //9
    EXPR_GT,    //10
    EXPR_MOD,   //11
    EXPR_ID,    //12
    EXPR_INT,   //13
    EXPR_DOUBLE,//14
    EXPR_FLOAT, //15
    EXPR_RANGE, //16
    EXPR_STR,   //17
    EXPR_MET,   //18
    EXPR_AND,   //19
    EXPR_NOT,   //20
    EXPR_OR,    //21
    EXPR_MAS,   //22
    EXPR_BOOL,  //23
    EXPR_NIL,   //24
    EXPR_UMIN,  //25
    EXPR_FUNC_DEC_ANON, //26
    EXPR_TABLE, //27
    EXPR_ID_LIST, //28
};
struct NImport
{
    struct NExpr* name;
};

struct NConstant
{
  enum NConstantEnum constant;
};
struct NWhile
{
    struct NExpr * condition;
    struct NStmtList * body;
};

struct NFor
{
    struct NExpr* name;
    struct NExpr* start;
    struct NExpr* step;
    struct NStmtList * body;
};

struct NRange
{
    int start;
    int end;
};

struct NExpr
{
    bool isArray;
    char * name;
    struct NExpr * left;
    struct NExpr * right;
    int Int;
    double Double;
    float Float;
    enum NExprType type;
    struct NConstant* varconstant;
    struct NVarType* vartype;
    struct NExpr * next;
    struct NExprList* idlist;
    struct NTable* table;
    struct NFunc* func;

    // Attributes
    int constant_index;
    bool clojure;
    NExpr * origin;
};

struct NVarType
{
    enum NVarEnumType type;
};

struct NStmt
{
    enum NStmtType type;
    struct NExpr * var;
    struct NExpr * expr;
    struct NFunc * func;
    struct NStmtList * list;
    struct NStmt * next;
    struct NFor * for_loop;
    struct NWhile * while_loop;
    struct NIf * if_tree;
    struct NSwitch * switch_tree;
    struct NImport * import;
};

struct NStmtList
{
    struct NStmt * first;
    struct NStmt * last;
};

struct NFunc
{
    struct NExprList* name;
    struct NExprList* args;
    struct NStmtList* body;

    // Attributes
    struct NVarType* vartype;

    STConst * const_table;
    STConst * const_last;
    char * classname;
    int methodref;
    struct NFunc* pfunc;
    struct NExprList* locals_list;
};

struct NExprList
{
    struct NExpr * first;
    struct NExpr * last;
};
struct NSwitch
{
  struct NExpr* Name;
  struct NCaseList* caselist;

};

struct NCase
{
  struct NExpr* name;
  struct NStmtList* body;
  struct NCase* next;
  enum NSwitchCaseType type;
};

struct NLabelCase
{
  struct NExpr * name;
  enum NSwitchCaseType type;
};

struct NCaseList
{
    struct NCase* first;
    struct NCase* last;
};
struct NIf
{
    struct NExpr* condition;
    struct NStmtList* body;
    struct NStmtList* elsebody;
    struct NIfList* elseiflist;
    struct NIf* next;
};

struct NIfList
{
    struct NIf* first;
    struct NIf* last;
};

struct NTable
{
    struct NTblElem * first;
    struct NTblElem * last;
};

struct NTblElem
{
    struct NExpr* key;
    struct NExpr* value;
    struct NTblElem * next;
};

#endif
