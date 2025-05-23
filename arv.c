
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h> 
#include "arv.h"

NO* novo(char *val, char *tipo, int qnt_filho, ...) {
    NO *no = (NO*)malloc(sizeof(NO));
    no->val = strdup(val);
    no->tipo = tipo ? strdup(tipo) : NULL; // Tipo semântico
    no->qnt_filho = qnt_filho;

    if (qnt_filho == 0) {
        no->filhos = NULL;
        return no;
    }

    no->filhos = (NO**)malloc(qnt_filho * sizeof(NO*));

    va_list args;
    va_start(args, qnt_filho);
    for (int i = 0; i < qnt_filho; i++) {
        no->filhos[i] = va_arg(args, NO*);
    }
    va_end(args);

    return no;
}

void imp_ARV(NO *no, int h) {
    //printf("---------------------ARVORE------------------------\n");
    
    for (int i = 0; i < h; i++)  
        printf("  |");

    printf("  |-- ");

    if (no->tipo != NULL) 
        printf("(%s) ", no->tipo);

    printf(" %s\n", no->val);


    for (int i = 0; i < no->qnt_filho; i++) 
        imp_ARV(no->filhos[i], h + 1);
    
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