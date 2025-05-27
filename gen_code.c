#include "gen_code.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variáveis globais para gerar temporários e rótulos únicos
// (Estas estão definidas em quads.c, mas podem ser declaradas aqui se forem usadas diretamente)
// static int temp_counter = 0; // Removido, já em quads.c
// static int label_counter = 0; // Removido, já em quads.c


// Função auxiliar para gerar código para expressões e retornar o temporário resultante
// Esta função é chamada quando um nó de expressão precisa ser avaliado
// e seu resultado armazenado em um temporário.
char* gen_expr_code(NO *node) {
    if (node == NULL) return NULL;

    char *arg1_temp = NULL;
    char *arg2_temp = NULL;
    char *result_temp = NULL;

    switch (node->nodekind) {
        case ConstK: {// Nó de constante numérica (ex: 10)
            result_temp = newTemp(); // Cria um novo temporário ($tX)
            // Quádrupla: (ASSIGN, valor_da_constante, -, temporario)
            addQuad(&quadList, ASSIGN_OP, node->val, NULL, result_temp);
            return result_temp; // Retorna o nome do temporário
            break;
            }
        case IdK: {// Nó de identificador (variável, ex: x)
            if (node->qnt_filho == 0) { // Variável simples (não array indexado)
                result_temp = newTemp();
                // Quádrupla: (LOAD, nome_da_variavel, -, temporario)
                addQuad(&quadList, LOAD_OP, node->val, NULL, result_temp);
                return result_temp;
            } else { // Array indexado (ex: arr[i])
                char *index_temp = gen_expr_code(node->filhos[0]); // Avalia o índice 'i'
                result_temp = newTemp();
                // Quádrupla: (LOAD, nome_do_array, temporario_indice, temporario_resultado)
                // Ou você pode usar um OpCode específico como ARRAY_LOAD_OP se preferir
                addQuad(&quadList, LOAD_OP, node->val, index_temp, result_temp);
                free(index_temp); // Libera o temporário do índice
                return result_temp;
            }
            break;
        }

        case PlusK: {// Operações Aritméticas (+, -, *, /) e Relacionais (<, <=, >, >=, ==, !=)
            arg1_temp = gen_expr_code(node->filhos[0]); // Gera código para o primeiro operando
            arg2_temp = gen_expr_code(node->filhos[1]); // Gera código para o segundo operando
            result_temp = newTemp(); // Cria um temporário para o resultado da operação

            OpCode op_code;
            if (strcmp(node->val, "+") == 0) op_code = ADD_OP;
            else if (strcmp(node->val, "-") == 0) op_code = SUB_OP;
            else if (strcmp(node->val, "*") == 0) op_code = MUL_OP;
            else if (strcmp(node->val, "/") == 0) op_code = DIV_OP;
            // Operadores Relacionais
            else if (strcmp(node->val, "<") == 0) op_code = LESS_OP;
            else if (strcmp(node->val, "<=") == 0) op_code = LESS_EQ_OP;
            else if (strcmp(node->val, ">") == 0) op_code = GREATER_OP;
            else if (strcmp(node->val, ">=") == 0) op_code = GREATER_EQ_OP;
            else if (strcmp(node->val, "==") == 0) op_code = EQ_OP;
            else if (strcmp(node->val, "!=") == 0) op_code = NEQ_OP;
            else {
                fprintf(stderr, "Erro: Operador desconhecido em PlusK: %s\n", node->val);
                exit(EXIT_FAILURE);
            }
            // Quádrupla: (OPERADOR, temporario_op1, temporario_op2, temporario_resultado)
            addQuad(&quadList, op_code, arg1_temp, arg2_temp, result_temp);
            free(arg1_temp); free(arg2_temp); // Libera os temporários dos operandos
            return result_temp;
            break;
        }

        case CallK: {
            // Chamada de função
            // Primeiro, gere código para os argumentos (PARAM)
            // Assumimos que o nó 'args' (filhos[0]) é uma lista ou um nó vazio
            int arg_count = 0; // Contar o número de argumentos
            if (node->qnt_filho > 0 && node->filhos[0] != NULL) {
                NO* args_node = node->filhos[0];
                if (args_node->val != NULL) {
                    if (strcmp(args_node->val, "arg_list_single") == 0) {
                        char *arg_temp = gen_expr_code(args_node->filhos[0]);
                        addQuad(&quadList, PARAM_OP, arg_temp, NULL, NULL);
                        free(arg_temp);
                        arg_count = 1;
                    } else if (strcmp(args_node->val, "arg_list") == 0) {
                        // Para 'arg_list', você precisaria de uma função auxiliar para percorrer os argumentos
                        // e emitir os PARAMs. Esta é uma simplificação.
                        // Por agora, vamos apenas chamar a função principal para o nó de argumentos.
                        // Isso é uma simplificação, idealmente, você precisaria de uma função que retorne a contagem de args.
                        gen_intermediate_code(args_node); // Chame a travessia para o nó de argumentos
                        // Para contar, você precisaria de uma lógica mais avançada ou
                        // que a função que gera PARAMs retorne a contagem.
                        // Por agora, vou usar uma contagem fictícia.
                        arg_count = 1; // Ajuste isso para a contagem real de argumentos
                    } else if (strcmp(args_node->val, "empty_args") == 0) {
                        arg_count = 0;
                    }
                }
            }

            result_temp = newTemp();
            char arg_count_str[10];
            sprintf(arg_count_str, "%d", arg_count);
            // Quádrupla: (CALL, nome_da_funcao, num_de_args, temporario_resultado)
            addQuad(&quadList, CALL_OP, node->val, arg_count_str, result_temp);
            return result_temp;
            break;
        }

        case PrgK: // Handle expressions that are children of PrgK nodes like (APR expressao FPR)
            if (node->val == NULL) { // Isso pode ser um nó sem valor específico, mas que é uma expressão
                // Ex: (APR expressao FPR) pode ter sido mapeado para PrgK sem val
                // Apenas passe para o filho, que deve ser a expressão real.
                return gen_expr_code(node->filhos[0]);
            }
            // Se for um PrgK com val (como "assignment"), ele é um statement, não uma expressão que retorna um valor.
            // Ele deve ser tratado diretamente por gen_intermediate_code, não por gen_expr_code.
            // Se chegamos aqui, é um erro ou um nó PrgK que não é uma expressão.
            return NULL; // Retorna NULL para nós que não produzem um resultado de expressão

        default:
            // Para outros NodeKinds que não são expressões, ou que não produzem um resultado,
            // retorne NULL.
            return NULL;
    }
}


// Função principal para gerar o código intermediário a partir da AST
void gen_intermediate_code(NO *node) {
    if (node == NULL) return;

    // A ordem de travessia (pré-ordem, pós-ordem) é crucial aqui.
    // Para declarações e comandos de controle de fluxo, geralmente processamos o nó pai primeiro (pré-ordem).
    // Para expressões, processamos os filhos primeiro (pós-ordem) para ter os resultados dos operandos.

    switch (node->nodekind) {
        case PrgK:{
            if (node->val != NULL) {
                if (strcmp(node->val, "programa") == 0 ||
                    strcmp(node->val, "declaracao_lista") == 0 ||
                    strcmp(node->val, "declaracao_lista_single") == 0 ||
                    strcmp(node->val, "composto_declaracao") == 0 ||
                    strcmp(node->val, "local_declaracoes") == 0 ||
                    strcmp(node->val, "statement_lista") == 0 ||
                    strcmp(node->val, "declaracao") == 0 ||
                    strcmp(node->val, "param_list") == 0 || // Adicionado para lista de parâmetros
                    strcmp(node->val, "arg_list") == 0 // Adicionado para lista de argumentos de chamada
                    )
                {
                    // Para esses nós estruturais, apenas percorra os filhos.
                    for (int i = 0; i < node->qnt_filho; i++) {
                        gen_intermediate_code(node->filhos[i]);
                    }
                }
                // *** ALTERAÇÃO CRUCIAL AQUI ***
                else if (strcmp(node->val, "expressao_declaracao") == 0) {
                    // expressao_declaracao é um statement. Seu filho é uma expressao.
                    // Se a expressao é um assignment ou uma chamada de função (CallK) usada como statement,
                    // ela deve ser processada por gen_intermediate_code, não por gen_expr_code.
                    // Por isso, chamamos gen_intermediate_code no filho.
                    gen_intermediate_code(node->filhos[0]);
                }
                // *** FIM DA ALTERAÇÃO ***
                else if (strcmp(node->val, "empty_expression_statement") == 0 ||
                           strcmp(node->val, "empty_params") == 0 ||
                           strcmp(node->val, "empty") == 0 ||
                           strcmp(node->val, "empty_args") == 0 ||
                           strcmp(node->val, "void_params") == 0) {
                    // Não faz nada para nós vazios ou void.
                } else if (strcmp(node->val, "assignment") == 0) {
                    // Lógica para atribuição (ex: x = 10; ou arr[i] = valor;)
                    char *r_value_temp = gen_expr_code(node->filhos[1]); // Avalia o lado direito

                    NO *l_value_node = node->filhos[0]; // Nó da variável/array no lado esquerdo
                    if (l_value_node->nodekind == IdK && l_value_node->qnt_filho == 0) { // Atribuição a variável simples
                        // Quádrupla: (ASSIGN, valor_temporario_do_r_value, -, nome_da_variavel)
                        addQuad(&quadList, ASSIGN_OP, r_value_temp, NULL, l_value_node->val);
                    } else if (l_value_node->nodekind == IdK && l_value_node->qnt_filho > 0) { // Atribuição a elemento de array
                        char *index_temp = gen_expr_code(l_value_node->filhos[0]); // Avalia o índice
                        // Quádrupla: (ASSIGN, valor_temporario_do_r_value, temporario_indice, nome_do_array)
                        // Poderia ser um OpCode específico como STORE_ARRAY_OP se você quiser.
                        addQuad(&quadList, ASSIGN_OP, r_value_temp, index_temp, l_value_node->val);
                        free(index_temp); // Libera o temporário do índice
                    }
                    free(r_value_temp); // Libera o temporário do lado direito
                } else if (strcmp(node->val, "return_expr") == 0) {
                    char *expr_temp = gen_expr_code(node->filhos[0]); // Avalia a expressão de retorno
                    // Quádrupla: (RET, temporario_resultado_da_expr, -, -)
                    addQuad(&quadList, RETURN_OP, expr_temp, NULL, NULL);
                    free(expr_temp);
                } else if (strcmp(node->val, "return_void") == 0) {
                    // Quádrupla: (RET, -, -, -)
                    addQuad(&quadList, RETURN_OP, NULL, NULL, NULL);
                } else if (strcmp(node->val, "if_statement") == 0 || strcmp(node->val, "if_else_statement") == 0) { // Added if_else_statement
                    char *cond_temp = gen_expr_code(node->filhos[0]); // Avalia a condição
                    char *label_else = newLabel(); // Rótulo para o bloco ELSE ou fim do IF
                    // Quádrupla: (IFF, temporario_condicao, rotulo_else_ou_fim, -)
                    addQuad(&quadList, IF_FALSE_GOTO_OP, cond_temp, label_else, NULL);
                    free(cond_temp);

                    gen_intermediate_code(node->filhos[1]); // Gera código para o bloco IF (true)

                    if (node->qnt_filho == 3) { // IF-ELSE
                        char *label_end_if = newLabel(); // Rótulo para o fim do IF-ELSE
                        // Quádrupla: (GOTO, rotulo_fim_if, -, -) (para pular o ELSE)
                        addQuad(&quadList, GOTO_OP, label_end_if, NULL, NULL);
                        // Quádrupla: (LAB, rotulo_else, -, -) (início do bloco ELSE)
                        addQuad(&quadList, LABEL_OP, label_else, NULL, NULL);
                        gen_intermediate_code(node->filhos[2]); // Gera código para o bloco ELSE
                        // Quádrupla: (LAB, rotulo_fim_if, -, -) (fim do IF-ELSE)
                        addQuad(&quadList, LABEL_OP, label_end_if, NULL, NULL);
                        free(label_end_if);
                    } else { // Somente IF (sem ELSE)
                        // Quádrupla: (LAB, rotulo_else, -, -) (fim do IF)
                        addQuad(&quadList, LABEL_OP, label_else, NULL, NULL);
                    }
                    free(label_else);
                } else if (strcmp(node->val, "while_statement") == 0) {
                    char *label_loop_start = newLabel(); // Rótulo para o início do loop
                    char *label_loop_end = newLabel();   // Rótulo para o fim do loop
                    // Quádrupla: (LAB, rotulo_inicio_loop, -, -)
                    addQuad(&quadList, LABEL_OP, label_loop_start, NULL, NULL);

                    char *cond_temp = gen_expr_code(node->filhos[0]); // Avalia a condição do WHILE
                    // Quádrupla: (IFF, temporario_condicao, rotulo_fim_loop, -)
                    addQuad(&quadList, IF_FALSE_GOTO_OP, cond_temp, label_loop_end, NULL);
                    free(cond_temp);

                    gen_intermediate_code(node->filhos[1]); // Gera código para o corpo do loop

                    // Quádrupla: (GOTO, rotulo_inicio_loop, -, -) (volta para reavaliar a condição)
                    addQuad(&quadList, GOTO_OP, label_loop_start, NULL, NULL);
                    // Quádrupla: (LAB, rotulo_fim_loop, -, -) (fim do loop)
                    addQuad(&quadList, LABEL_OP, label_loop_end, NULL, NULL);
                    free(label_loop_start); free(label_loop_end);
                }
            }
            break;
        }

        case FnK: {// Declaração de Função
            // Quádrupla: (FUN, tipo_retorno, nome_da_funcao, -)
            addQuad(&quadList, FUN_OP, node->tipo, node->val, NULL);
            // Gera código para os parâmetros da função (se houver)
            if (node->qnt_filho > 0 && node->filhos[0] != NULL) {
                gen_intermediate_code(node->filhos[0]); // Chama para o nó params (que pode ser param_lista ou void_params)
            }
            // Gera código para o corpo da função
            if (node->qnt_filho > 1 && node->filhos[1] != NULL) {
                 gen_intermediate_code(node->filhos[1]); // Chama para o composto_declaracao
            }
            break;
        }

        case ParamK: {// Parâmetro de Função (dentro da declaração de função)
            // Quádrupla: (ARG, tipo_parametro, nome_parametro, -)
            addQuad(&quadList, ARG_OP, node->tipo, node->val, NULL);
            break;
        }

        case CallK: {// Chamada de Função (quando usada como statement, ex: func();)
            char *temp = gen_expr_code(node); // Avalia a chamada, result_temp da função CallK em gen_expr_code
            if (temp != NULL) {
                free(temp); // Libera o temporário se o resultado não for usado
            }
            break;
        }

        // Para os nós que representam expressões puras (ConstK, IdK, PlusK),
        // eles não devem ser diretamente alcançados por gen_intermediate_code,
        // a menos que sejam filhos de um expressao_declaracao (já tratado acima)
        // ou parte de uma expressão maior dentro de outro statement.
        // A lógica de gen_expr_code lida com eles.
        case ConstK:
        case IdK:
        case PlusK:{
            // Esses nós são tratados por gen_expr_code, e normalmente não deveriam
            // ser chamados diretamente por gen_intermediate_code a menos que seja um erro
            // na estrutura da AST ou seja uma expressão solta.
            // Se eles chegam aqui, significa que são expressões que não são usadas como r-value de algo.
            // Ex: '5;' ou 'x + y;' como statement.
            // Nesses casos, apenas avalie e descarte o temporário.
            char *discard_temp = gen_expr_code(node);
            if (discard_temp != NULL) {
                free(discard_temp);
            }
            break;
        }

        default:
            // Para outros nós não explicitamente tratados, traverse os filhos.
            for (int i = 0; i < node->qnt_filho; i++) {
                gen_intermediate_code(node->filhos[i]);
            }
            break;
    }
}