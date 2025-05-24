#ifndef GEN_CODE_H
#define GEN_CODE_H

#include "arv.h" // Para NO*
#include "quads.h" // Para QuadList e OpCode

// Função principal para gerar o código intermediário a partir da AST
void gen_intermediate_code(NO *node);

// Função auxiliar para gerar código para expressões e retornar o temporário resultante
char* gen_expr_code(NO *node);

#endif