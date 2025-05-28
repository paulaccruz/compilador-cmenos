#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arv.h"   
#include "tabela.h" 

// Declarações das variáveis globais da tabela de símbolos
extern tabela *T;
extern int tm_tab;

int getValorVariavel(const char *nome) {
    for (int i = 0; i < tm_tab; i++) {
        if (T[i].nome && strcmp(T[i].nome, nome) == 0) {
            return T[i].val;
        }
    }
    fprintf(stderr, "Erro em tempo de execução: Variável '%s' não declarada ou fora do escopo.\n", nome);
    exit(1);
}

void setValorVariavel(const char *nome, int val) {
    for (int i = 0; i < tm_tab; i++) {
        if (T[i].nome && strcmp(T[i].nome, nome) == 0) {
            T[i].val = val;
            return;
        }
    }
    fprintf(stderr, "Erro em tempo de execução: Variável '%s' não declarada para atribuição.\n", nome);
    exit(1);
}


int executarExpressao(NO *no) {
    if (!no) {
        fprintf(stderr, "Erro em tempo de execução: Expressão nula encontrada.\n");
        exit(1);
    }

    switch (no->nodekind) {
        case ConstK: // Corresponde a NUM no parser (nodekind 5)

            if (no->val == NULL) {
                fprintf(stderr, "Erro em tempo de execução: Constante numérica sem valor.\n");
                exit(1);
            }
            return atoi(no->val);

        case IdK: // Corresponde a var/ID no parser (nodekind 6)

            if (no->val == NULL) {
                fprintf(stderr, "Erro em tempo de execução: Identificador de variável nulo.\n");
                exit(1);
            }
            return getValorVariavel(no->val);

        case PlusK: // Corresponde a operações como +, -, *, /, etc. (nodekind 3)
            // Assumindo que no->val guarda o operador ("+", "-", etc.)
            if (no->filhos[0] == NULL || no->filhos[1] == NULL) {
                fprintf(stderr, "Erro em tempo de execução: Operação binária com operandos nulos.\n");
                exit(1);
            }
            int esq = executarExpressao(no->filhos[0]);
            int dir = executarExpressao(no->filhos[1]);

            if (strcmp(no->val, "+") == 0) return esq + dir;
            if (strcmp(no->val, "-") == 0) return esq - dir;
            if (strcmp(no->val, "*") == 0) return esq * dir;
            if (strcmp(no->val, "/") == 0) {
                if (dir == 0) {
                    fprintf(stderr, "Erro em tempo de execução: Divisão por zero.\n");
                    exit(1);
                }
                return esq / dir;
            }
            // ... (adicionar outros operadores, como RelOpK se for o caso)
            fprintf(stderr, "Erro em tempo de execução: Operador desconhecido '%s'.\n", no->val);
            exit(1);

        case RelOpK: // Corresponde a operadores relacionais (nodekind 7)
            if (no->filhos[0] == NULL || no->filhos[1] == NULL) {
                fprintf(stderr, "Erro em tempo de execução: Operação relacional com operandos nulos.\n");
                exit(1);
            }
            esq = executarExpressao(no->filhos[0]);
            dir = executarExpressao(no->filhos[1]);

            if (strcmp(no->val, "<") == 0) return esq < dir;
            if (strcmp(no->val, "<=") == 0) return esq <= dir;
            if (strcmp(no->val, ">") == 0) return esq > dir;
            if (strcmp(no->val, ">=") == 0) return esq >= dir;
            if (strcmp(no->val, "==") == 0) return esq == dir;
            if (strcmp(no->val, "!=") == 0) return esq != dir;
            fprintf(stderr, "Erro em tempo de execução: Operador relacional desconhecido '%s'.\n", no->val);
            exit(1);

        case CallK: 
            if (no->val != NULL && strcmp(no->val, "input") == 0) {
                 // Esta parte não deveria ser alcançada se InputK e OutputK são nodes distintos
                 // Mas mantenho como um fallback caso CallK seja usado para elas em algum momento
                 int valor;
                 printf("Digite um número (via CallK): ");
                 scanf("%d", &valor);
                 return valor;
            }
            fprintf(stderr, "Erro em tempo de execução: Chamada de função '%s' não implementada no interpretador.\n", no->val ? no->val : "NULL");
            exit(1);
        
       case InputK: // NodeKind 8
            {
                int valor;
                printf("Digite um número: "); 
                if (scanf("%d", &valor) != 1) {
                    fprintf(stderr, "Erro de entrada: Esperado um número inteiro. Limpando buffer.\n");
                    while (getchar() != '\n'); 
                    exit(1); 
                }
                return valor;
            }
        default:
            fprintf(stderr, "Erro em tempo de execução: Tipo de nó de expressão desconhecido: %d (val: %s)\n", no->nodekind, no->val ? no->val : "NULL");
            exit(1);
    }
}


void executarComando(NO *no) {
    if (!no) return;

    switch (no->nodekind) {
        // Atribuição: var = expressao (nodekind 3, no->val == "=")
        case PlusK: // Sua regra de parser para atribuição '=', talvez seja um tipo de PlusK com val "="
            if (no->val != NULL && strcmp(no->val, "=") == 0) {
                if (no->filhos[0] == NULL || no->filhos[0]->nodekind != IdK || no->filhos[1] == NULL) {
                    fprintf(stderr, "Erro em tempo de execução: Atribuição inválida.\n");
                    exit(1);
                }
                char *nomeVar = no->filhos[0]->val; // Nome da variável está em no->filhos[0]->val
                int valor = executarExpressao(no->filhos[1]); // Avalia a expressão do lado direito
                setValorVariavel(nomeVar, valor);
                return; // Retorna após a atribuição
            }
            break; // Cairá para o default ou para a próxima checagem

   // NOVO: Tratamento para o nó de atribuição
               case PrgK: // NodeKind 0 - Pode ser um bloco de comandos OU um nó de atribuição OU uma declaração
            if (no->val != NULL && strcmp(no->val, "assignment") == 0) {
                // ... (seu código para atribuição, já está ok) ...
                char *nomeVar = no->filhos[0]->val;
                int valor = executarExpressao(no->filhos[1]);
                setValorVariavel(nomeVar, valor);
                return;
            } else if (no->val != NULL && (strcmp(no->val, "var_declaracao") == 0 || strcmp(no->val, "local_declaracoes") == 0 || strcmp(no->val, "empty") == 0)) {
                return; // Não faça nada, apenas retorne
            } else {
                // Se for NodeKind 0 e não é "assignment" ou uma declaração, assume que é um bloco de comandos
                // (como composto_declaracao ou statement_lista) e percorre seus filhos.
                for (int i = 0; i < no->qnt_filho; i++) {
                    executarComando(no->filhos[i]);
                }
                return;
            }

   case OutputK: // NodeKind 9 - Para output(expressao)
            if (no->filhos[0] == NULL) {
                fprintf(stderr, "Erro em tempo de execução: Output sem expressão a ser impressa.\n");
                exit(1);
            }
            int valor_output = executarExpressao(no->filhos[0]);
            printf("%d\n", valor_output);
            return;

        default:
            fprintf(stderr, "Erro em tempo de execução: Tipo de nó de comando desconhecido ou não implementado: %d (val: %s)\n", no->nodekind, no->val ? no->val : "NULL");
            exit(1);
    }
}

void executar(NO *no) {

    NO *declaracao_lista_raiz = no->filhos[0]; 
   
    // Cada filho deve ser uma declaração de função (FnK) ou outra declaração.
    for (int i = 0; i < declaracao_lista_raiz->qnt_filho; i++) {
        NO *decl = declaracao_lista_raiz->filhos[i]; // 'decl' agora sim deve ser o nó 'main' (FnK)
 
        if (decl->nodekind == FnK && decl->val != NULL && strcmp(decl->val, "main") == 0) {

            // O corpo da função 'main' é o segundo filho do nó FnK (índice 1)
            // O primeiro filho (índice 0) seria para os parâmetros
            if (decl->qnt_filho < 2 || decl->filhos[1] == NULL) {

                return;
            }
            NO *corpo = decl->filhos[1]; // corpo da função main (composto_declaracao ou statement_lista)
    
            executarComando(corpo); // Executa o corpo da main
  
            return; // Termina após executar a main
        }
    }

}