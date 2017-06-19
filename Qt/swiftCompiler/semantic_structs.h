#ifndef SEMANTIC_STRUCTS_H
#define SEMANTIC_STRUCTS_H
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
#endif // SEMANTIC_STRUCTS_H
