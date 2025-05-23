#ifndef TABELA_H
#define TABELA_H

typedef struct tabela {
    char *tipo_dado;    
    char *tipo;       
    char *nome;  
    char *escopo;
    int linha;          
} tabela;

void inicia(tabela **T, int *tm);
void add(tabela **T, int *tm, char *nome, char *tipo_dado, char *tipo, int linha, char *escopo); 
void imprime(tabela *T, int tm); 
int busca(tabela *T, int tm, char *nome, char *escopo);

#endif