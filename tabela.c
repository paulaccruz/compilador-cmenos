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
    if (*tm % 10 == 0) {
        size_t new_size = (*tm + 10) * sizeof(tabela);
        tabela *new_T = realloc(*T, new_size);
        if (new_T == NULL) {
            fprintf(stderr, "Failed to reallocate memory\n");
            exit(1);
        }
        *T = new_T;
    }
    
    (*T)[*tm].nome = strdup(nome);
    (*T)[*tm].tipo_dado = strdup(tipo_dado);
    (*T)[*tm].tipo = strdup(tipo);
    (*T)[*tm].linha = linha;
    (*T)[*tm].escopo = strdup(escopo);
    
    (*tm)++;
}

int busca(tabela *T, int tm, char *nome, char *escopo) {
    for (int i = 0; i < tm; i++) {
        if (strcmp(T[i].nome, nome) == 0 && strcmp(T[i].escopo, escopo) == 0) {
            return i;
        }
    }
    return -1; 
}

void imprime(tabela *T, int tm) {
    printf("\nSIMB          TIPO DADO         TIPO            ESCOPO       LINHA\n");
    printf("______________________________________________________________________\n\n");
    
    for (int i = 0; i < tm; i++) {
        printf("%s\t\t%s\t\t%s\t\t%s\t\t%d\n",
            T[i].nome,
            T[i].tipo_dado,
            T[i].tipo,
            T[i].escopo,
            T[i].linha);
    }
}
