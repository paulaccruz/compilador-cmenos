#ifndef ARV_H
#define ARV_H


typedef struct NO {
    struct NO **filhos;
    int qnt_filho;
    char *val; //valor de token
    char *tipo; //tipo semântico do token
} NO;

NO* novo(char *val, char *tipo, int qnt_filho, ... ); // Cria um novo nó qnt variavel de arg
void imp_ARV(NO *no, int h); 
void free_arv(NO *no); 

#endif 