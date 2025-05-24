#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h> 
#include "arv.h"

NO* novo(NodeKind nodekind, char *val, char *tipo, int qnt_filho, ...) {
    NO *no = (NO*)malloc(sizeof(NO));
    // É uma boa prática verificar se malloc retornou NULL
    if (no == NULL) {
        perror("Failed to allocate memory for NO node");
        exit(EXIT_FAILURE);
    }
    no->nodekind = nodekind;
    no->val = val ? strdup(val) : NULL; // Duplicate val
    no->tipo = tipo ? strdup(tipo) : NULL; // IMPORTANTE: SEMPRE strdup 'tipo' aqui
    no->qnt_filho = qnt_filho;

    if (qnt_filho == 0) {
        no->filhos = NULL;
        return no;
    }

    no->filhos = (NO**)malloc(qnt_filho * sizeof(NO*));
    if (no->filhos == NULL) {
        perror("Failed to allocate memory for NO children");
        free(no->val); // Libera o val alocado antes de sair
        free(no->tipo); // Libera o tipo alocado antes de sair
        free(no);
        exit(EXIT_FAILURE);
    }

    va_list args;
    va_start(args, qnt_filho);
    for (int i = 0; i < qnt_filho; i++) {
        no->filhos[i] = va_arg(args, NO*);
    }
    va_end(args);

    return no;
}

void imp_ARV(NO *no, int h) {
    if (no == NULL) {
        return;
    }

    for (int i = 0; i < h; i++) 
        printf("   |");

    printf("   |-- ");

    if (no->tipo != NULL) 
        printf("(%s) ", no->tipo);

    if (no->val != NULL)
        printf("%s (NodeKind: %d)\n", no->val, no->nodekind); 
    else
        printf("(null_val) (NodeKind: %d)\n", no->nodekind); 


    for (int i = 0; i < no->qnt_filho; i++) {
        imp_ARV(no->filhos[i], h + 1);
    }
    
}

void free_arv(NO *no) {
    if (no == NULL) return;
    for (int i = 0; i < no->qnt_filho; i++) {
        free_arv(no->filhos[i]);
    }
    free(no->val);
    free(no->tipo); 
    free(no->filhos);
    free(no);
}