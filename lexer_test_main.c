#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arv.h"     // Adicione esta linha
#include "tabela.h"  // Adicione esta linha (se tabela.h também tiver tipos usados indiretamente)
#include "parser.tab.h"

extern FILE *yyin;
extern int yylex(void);
extern int yylineno;
extern char *yytext;

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        if (!f) {
            perror(argv[1]);
            return 1;
        }
        yyin = f;
    } else {
        yyin = stdin; // Se nenhum arquivo for fornecido, lê da entrada padrão
    }

    int tok;
    while ((tok = yylex()) != 0) { // yylex() retorna 0 no final do arquivo
        printf("Token: %d (", tok);
        switch(tok) {
            case ID: printf("ID, val: %s", yylval.string); break;
            case NUM: printf("NUM, val: %s", yylval.string); break;
            case INT: printf("INT"); break;
            case VOID: printf("VOID"); break;
            case WHILE: printf("WHILE"); break;
            case RETURN: printf("RETURN"); break;
            case IF: printf("IF"); break;
            case ELSE: printf("ELSE"); break;
            case SOM: printf("SOM"); break;
            case SUB: printf("SUB"); break;
            case MUL: printf("MUL"); break;
            case DIV: printf("DIV"); break;
            case MEN: printf("MEN"); break;
            case MEI: printf("MEI"); break;
            case MAR: printf("MAR"); break;
            case MAI: printf("MAI"); break;
            case IGU: printf("IGU"); break;
            case DIF: printf("DIF"); break;
            case ATR: printf("ATR"); break;
            case PEV: printf("PEV"); break;
            case VIR: printf("VIR"); break;
            case APR: printf("APR"); break;
            case FPR: printf("FPR"); break;
            case ACO: printf("ACO"); break;
            case FCO: printf("FCO"); break;
            case ACH: printf("ACH"); break;
            case FCH: printf("FCH"); break;
            // Para outros caracteres que podem ser retornados diretamente como seu valor ASCII
            default: printf("Char: '%c'", tok); break;
        }
        printf(") - Linha: %d, Texto: '%s'\n", yylineno, yytext);
        // Libere a memória alocada por strdup em ID e NUM
        if (tok == ID || tok == NUM) {
            // yylval.string é copiado para yylval.string, então precisamos liberar aqui
            // No entanto, é importante que o Bison também libere, ou que você não use strdup em yylex
            // para cada token, se a vida útil do yytext for suficiente.
            // Por simplicidade para este teste, podemos omitir free(yylval.string) aqui se você confia
            // que o Bison vai gerenciar isso, ou se este teste for de curta duração.
            // Para um teste robusto, seria importante gerenciar essa memória.
        }
    }
    return 0;
}