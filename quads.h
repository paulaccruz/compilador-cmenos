#ifndef QUADS_H
#define QUADS_H

// Definição dos tipos de operadores para quádruplas
typedef enum {
    // Operadores aritméticos/lógicos
    ADD_OP, SUB_OP, MUL_OP, DIV_OP,
    LESS_OP, LESS_EQ_OP, GREATER_OP, GREATER_EQ_OP, EQ_OP, NEQ_OP,
    ASSIGN_OP, // Atribuição (=)

    // Controle de fluxo
    IF_FALSE_GOTO_OP, // IFF (Se falso, desvie para...)
    GOTO_OP,
    LABEL_OP, // LAB (Definição de rótulo)

    // Funções
    FUN_OP,     // FUN (declaração de função)
    ARG_OP,     // ARG (declaração de parâmetro - para a função)
    CALL_OP,    // CALL (chamada de função)
    RETURN_OP,  // RET (retorno de função)

    // Acesso à memória / Variáveis
    LOAD_OP,    // LOAD (carregar valor de uma variável/endereço para um temporário)
    //STORE_OP, // STORE (armazenar valor de um temporário para uma variável/endereço) - pode ser coberto por ASSIGN_OP
    PARAM_OP    // PARAM (passar argumento para a função antes de CALL)

    // Adicione mais operadores conforme necessário para C-Minus
} OpCode;

// Estrutura para uma quádrupla
typedef struct Quad {
    OpCode op;
    char *arg1;
    char *arg2;
    char *result;
} Quad;

// Lista de quádruplas
typedef struct QuadList {
    Quad *quads;
    int count;
    int capacity;
} QuadList;

// Funções para manipular a lista de quádruplas
void initQuadList(QuadList *list);
void addQuad(QuadList *list, OpCode op, char *arg1, char *arg2, char *result);
void printQuads(QuadList *list);
void freeQuadList(QuadList *list);

// Funções para gerar temporários e rótulos
char* newTemp();
char* newLabel();

// Declaração da variável global da lista de quádruplas
extern QuadList quadList;

#endif