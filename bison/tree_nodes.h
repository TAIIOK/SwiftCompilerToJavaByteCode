#ifndef _H_TREE_NODES_
#define _H_TREE_NODES_

typedef struct st_const STConst;
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
    EXPR_EQ,
    EXPR_NQ,
    EXPR_PLUS,
    EXPR_MINUS,
    EXPR_DIV,
    EXPR_MUL,
    EXPR_POW,
    EXPR_LE,
    EXPR_GE,
    EXPR_LT,
    EXPR_GT, //10
    EXPR_MOD,
    EXPR_ID,
    EXPR_INT,
    EXPR_DOUBLE,
    EXPR_FLOAT,
    EXPR_RANGE,
    EXPR_STR,
    EXPR_MET,
    EXPR_AND,
    EXPR_NOT, //20
    EXPR_OR,
    EXPR_MAS,
    EXPR_BOOL,
    EXPR_NIL,
    EXPR_UMIN,
    EXPR_FUNC_DEC_ANON,
    EXPR_TABLE,
    EXPR_ID_LIST,
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
