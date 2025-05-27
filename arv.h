#ifndef ARV_H
#define ARV_H

typedef enum {
    PrgK, 
    FnK,
    ParamK,
    PlusK,
    CallK,
    ConstK,
    IdK
} NodeKind;

typedef struct NO {
    NodeKind nodekind;
    struct NO **filhos; 
    int qnt_filho;
    char *val; 
    char *tipo; 
} NO;

NO* novo(NodeKind nodekind, char *val, char *tipo, int qnt_filho, ... ); 
void imp_ARV(NO *no, int h); 
void free_arv(NO *no); 

#endif