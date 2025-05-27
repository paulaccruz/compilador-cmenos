#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quads.h"

// Variáveis globais para gerar temporários e rótulos únicos
static int temp_counter = 0;
static int label_counter = 0;

// Mapeamento de OpCode para string (para impressão)
const char* OpCodeNames[] = {
    "ADD", "SUB", "MUL", "DIV",
    "LESS", "LESS_EQ", "GREATER", "GREATER_EQ", "EQ", "NEQ",
    "ASSIGN",
    "IFF", "GOTO", "LAB",
    "FUN", "ARG", "CALL", "RET",
    "LOAD", "PARAM" // Removed STORE_OP, it can be ASSIGN where result is a var
};

// Define a variável global quadList (apenas uma vez em um .c)
QuadList quadList;

void initQuadList(QuadList *list) {
    list->count = 0;
    list->capacity = 10;
    list->quads = (Quad*)malloc(list->capacity * sizeof(Quad));
    if (list->quads == NULL) {
        perror("Failed to allocate memory for quad list");
        exit(EXIT_FAILURE);
    }
}

void addQuad(QuadList *list, OpCode op, char *arg1, char *arg2, char *result) {
    if (list->count >= list->capacity) {
        list->capacity *= 2;
        list->quads = (Quad*)realloc(list->quads, list->capacity * sizeof(Quad));
        if (list->quads == NULL) {
            perror("Failed to reallocate memory for quad list");
            exit(EXIT_FAILURE);
        }
    }

    list->quads[list->count].op = op;
    list->quads[list->count].arg1 = arg1 ? strdup(arg1) : NULL;
    list->quads[list->count].arg2 = arg2 ? strdup(arg2) : NULL;
    list->quads[list->count].result = result ? strdup(result) : NULL;
    list->count++;
}

void printQuads(QuadList *list) {
    printf("\n--- Código Intermediário (Quádruplas) ---\n");
    for (int i = 0; i < list->count; i++) {
        Quad q = list->quads[i];
        printf("(%s, %s, %s, %s)\n",
               OpCodeNames[q.op],
               q.arg1 ? q.arg1 : "-",
               q.arg2 ? q.arg2 : "-",
               q.result ? q.result : "-");
    }
    printf("------------------------------------------\n");
}

void freeQuadList(QuadList *list) {
    if (list == NULL) return;
    for (int i = 0; i < list->count; i++) {
        free(list->quads[i].arg1);
        free(list->quads[i].arg2);
        free(list->quads[i].result);
    }
    free(list->quads);
    list->quads = NULL;
    list->count = 0;
    list->capacity = 0;
}

// Gera um novo temporário no formato $tX
char* newTemp() {
    char temp_name[16];
    sprintf(temp_name, "$t%d", temp_counter++);
    return strdup(temp_name);
}

// Gera um novo rótulo no formato L_X
char* newLabel() {
    char label_name[16];
    sprintf(label_name, "L%d", label_counter++);
    return strdup(label_name);
}