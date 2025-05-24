#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

void inicia(tabela **T, int *tm) {
    *tm = 0;
    *T = malloc(sizeof(tabela) * 10);
    if (*T == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }
}

void add(tabela **T, int *tm, char *nome, char *tipo_dado, char *tipo, int linha, char *escopo) {
    if (*tm % 10 == 0 && *tm > 0) { 
        size_t new_size = (*tm + 10) * sizeof(tabela);
        tabela *new_T = realloc(*T, new_size);
        if (new_T == NULL) {
            fprintf(stderr, "Failed to reallocate memory\n");
            exit(1);
        }
        *T = new_T;
    }
    
    (*T)[*tm].nome = nome; // O nome já vem do strdup do parser.y
    (*T)[*tm].tipo_dado = strdup(tipo_dado); // String literal, então strdup
    (*T)[*tm].tipo = tipo; // O tipo já vem do strdup do parser.y (tipo_especificador)
    (*T)[*tm].linha = linha;
    (*T)[*tm].escopo = strdup(escopo); // Pode ser "global" (literal) ou nome da função (strdup'd)
    
    (*tm)++;
}

int busca(tabela *T, int tm, char *nome, char *escopo) {
    if (nome == NULL || escopo == NULL) { 
        return -1;
    }
    for (int i = 0; i < tm; i++) {
        if (T[i].nome != NULL && T[i].escopo != NULL && 
            strcmp(T[i].nome, nome) == 0 && strcmp(T[i].escopo, escopo) == 0) {
            return i;
        }
    }
    return -1; 
}

void imprime(tabela *T, int tm) {
    printf("\nSIMB          TIPO DADO         TIPO          ESCOPO        LINHA\n");
    printf("______________________________________________________________________\n\n");
    
    for (int i = 0; i < tm; i++) {
        printf("%s\t\t%s\t\t%s\t\t%s\t\t%d\n",
            T[i].nome ? T[i].nome : "(null)",
            T[i].tipo_dado ? T[i].tipo_dado : "(null)",
            T[i].tipo ? T[i].tipo : "(null)",
            T[i].escopo ? T[i].escopo : "(null)",
            T[i].linha);
    }
}

// TODO: Adicionar função para liberar a memória da tabela de símbolos
/*
void free_tabela(tabela *T, int tm) {
    if (T == NULL) return;
    for (int i = 0; i < tm; i++) {
        free(T[i].nome);
        free(T[i].tipo_dado);
        free(T[i].tipo);
        free(T[i].escopo);
    }
    free(T);
}
*/