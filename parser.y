%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arv.h"
#include "tabela.h"
#include "quads.h"      // Incluir o cabeçalho das quádruplas
#include "gen_code.h"   // Incluir o cabeçalho da geração de código

extern int yylex(void);
extern FILE *yyin;
extern int yylineno;
extern char *yytext;

void yyerror(char *s) {fprintf(stderr, "ERRO SINTATICO: %s LINHA: %d\n", yytext, yylineno);}

void erro_semantico(char *msg, char *id, int linha) {
    fprintf(stderr, "ERRO SEMANTICO: %s '%s' LINHA: %d\n", msg, id, linha);
}

tabela *T = NULL;
NO *raiz = NULL;
int tm_tab = 0;
char *escopo_at = "global";
char *funcao_at = NULL;

%}

%union {
    char *string;
    NO *no;
    char *tipo;
}

%token <string> ID
%token <string> NUM

%token  INT VOID WHILE RETURN PEV VIR

%type <tipo> tipo_especificador

%type <no> expressao var simples_expressao soma_expressao termo fator
%type <no> programa declaracao_lista declaracao var_declaracao fun_declaracao
%type <no> params param_lista param composto_declaracao
%type <no> local_declaracoes statement_lista statement expressao_declaracao selecao_declaracao iteracao_declaracao
%type <no> retorno_declaracao args arg_lista relacional


%start programa

%left SOM SUB
%left MUL DIV
%left APR FPR ACO FCO ACH FCH
%left IF ELSE

%nonassoc MEN MEI MAR MAI IGU DIF ATR

%%

programa:
    declaracao_lista {
        $$ = novo(PrgK, "programa", NULL, 1, $1);
        raiz = $$;
    }
;

declaracao_lista:
    declaracao_lista declaracao {
        $$ = novo(PrgK, "declaracao_lista", NULL, 2, $1, $2);
    }
    | declaracao_lista error PEV { yyerrok; $$ = $1; }
    | declaracao_lista error FCH { yyerrok; $$ = $1; }
    | declaracao {
        $$ = novo(PrgK, "declaracao_lista_single", NULL, 1, $1);
    }
;

declaracao:
    var_declaracao {
        $$ = $1;
    }
    | fun_declaracao {
        $$ = $1;
    }
;

var_declaracao:
    tipo_especificador ID PEV {
        if (busca(T, tm_tab, $2, escopo_at) != -1) {
            erro_semantico("Variavel ja declarada", $2, yylineno);
        } else {
            add(&T, &tm_tab, strdup($2), "var", $1, yylineno, escopo_at);
        }
        $$ = novo(PrgK, "var_declaracao", $1, 2, novo(IdK, strdup($2), $1, 0), novo(IdK, strdup($2), "id", 0));
    }
    | tipo_especificador ID ACO NUM FCO PEV {
        if (busca(T, tm_tab, $2, escopo_at) != -1) {
            erro_semantico("Array ja declarado", $2, yylineno);
        } else {
            add(&T, &tm_tab, strdup($2), "array", $1, yylineno, escopo_at);
        }
        $$ = novo(PrgK, "var_declaracao_array", $1, 3, novo(IdK, strdup($2), $1, 0), novo(IdK, strdup($2), "id", 0), novo(ConstK, strdup($4), "int", 0));
    }
    | tipo_especificador error PEV { yyerrok; }
;

tipo_especificador:
    INT { $$ = strdup("int"); }
    | VOID { $$ = strdup("void"); }
;

fun_declaracao:
    tipo_especificador ID APR {
        char *current_func_name = strdup($2);
        funcao_at = current_func_name;
        escopo_at = current_func_name;

        if (busca(T, tm_tab, current_func_name, "global") != -1) {
            erro_semantico("Funcao ja declarada", current_func_name, yylineno);
        } else {
            add(&T, &tm_tab, current_func_name, "func", $1, yylineno, "global");
        }
    } params FPR composto_declaracao {
        $$ = novo(FnK, strdup(funcao_at), $1, 2, $5, $7);

        escopo_at = "global";
        if (funcao_at != NULL) {
            free(funcao_at);
            funcao_at = NULL;
        }
    }

    | tipo_especificador ID APR error FPR composto_declaracao { yyerrok; }
    | tipo_especificador ID APR error FCH { yyerrok; }
;

params:
    param_lista {
        $$ = $1;
    }
    | VOID {
        $$ = novo(PrgK, "void_params", "void", 0);
    }
    | error {yyerrok;}
    | /* empty */ {
        $$ = novo(PrgK, "empty_params", NULL, 0);
    }
;

param_lista:
    param_lista VIR param {
        $$ = novo(PrgK, "param_list", NULL, 2, $1, $3);
    }
    | param_lista error VIR { yyerrok; }
    | param_lista error FPR { yyerrok; }
    | param {
        $$ = $1;
    }
;

param:
    tipo_especificador ID {
        if (busca(T, tm_tab, $2, escopo_at) != -1) {
            erro_semantico("Parametro ja declarado", $2, yylineno);
        } else {
            add(&T, &tm_tab, strdup($2), "parametro", $1, yylineno, escopo_at);
        }
        $$ = novo(ParamK, strdup($2), $1, 0);
    }
    | tipo_especificador ID ACO FCO {
        if (busca(T, tm_tab, $2, escopo_at) != -1) {
            erro_semantico("Parametro array ja declarado", $2, yylineno);
        } else {
            add(&T, &tm_tab, strdup($2), "param_array", $1, yylineno, escopo_at);
        }
        $$ = novo(ParamK, strdup($2), $1, 0);
    }
    | tipo_especificador error {yyerrok;}
;

composto_declaracao:
    ACH local_declaracoes statement_lista FCH {
        $$ = novo(PrgK, "composto_declaracao",NULL, 2, $2, $3);
    }
    | ACH error FCH { yyerrok; }
;

local_declaracoes:
    local_declaracoes var_declaracao {
        $$ = novo(PrgK, "local_declaracoes",NULL, 2, $1, $2);
    }
    | /* vazio */ {
        $$ = novo(PrgK, "empty", NULL, 0);
    }
;

statement_lista:
    statement_lista statement {
        $$ = novo(PrgK, "statement_lista",NULL, 2, $1, $2);
    }
    | statement_lista error PEV { yyerrok; }
    | statement_lista error FCH { yyerrok; }
    | statement_lista error FPR { yyerrok; }
    | /* vazio */ {
        $$ = novo(PrgK, "empty", NULL, 0);
    }
;

statement:
    expressao_declaracao {
        $$ = $1;
    }
    | composto_declaracao {
        $$ = $1;
    }
    | selecao_declaracao {
        $$ = $1;
    }
    | iteracao_declaracao {
        $$ = $1;
    }
    | retorno_declaracao {
        $$ = $1;
    }
;

expressao_declaracao:
    expressao PEV {
        $$ = novo(PrgK, "expressao_declaracao",NULL, 1, $1);
    }
    | PEV {
        $$ = novo(PrgK, "empty_expression_statement", NULL, 0);
    }
    | error PEV { yyerrok; }
;

selecao_declaracao:
    IF APR expressao FPR statement {
        if (strcmp($3->tipo, "int") != 0) {
            erro_semantico("Condicao do if deve ser inteira", "", yylineno);
        }
        $$ = novo(PrgK, "if_statement", NULL, 2, $3, $5);
    }
    | IF APR error FPR statement { yyerrok; }
    | IF error statement { yyerrok; }
    | IF APR expressao FPR statement ELSE statement {
        if (strcmp($3->tipo, "int") != 0) {
            erro_semantico("Condicao do if deve ser inteira", "", yylineno);
        }
        $$ = novo(PrgK, "if_else_statement", NULL, 3, $3, $5, $7);
    }
     | IF APR error FPR statement ELSE statement { yyerrok; }
;

iteracao_declaracao:
    WHILE APR expressao FPR statement {
        if (strcmp($3->tipo, "int") != 0) {
            erro_semantico("Condicao do while deve ser inteira", "", yylineno);
        }
        $$ = novo(PrgK, "while_statement", NULL, 2, $3, $5);
    }
    | WHILE APR error FPR statement { yyerrok; }
    | WHILE error statement { yyerrok; }
;

retorno_declaracao:
    RETURN PEV {
        if (funcao_at == NULL || strcmp(funcao_at, "") == 0) {
            erro_semantico("Return fora de funcao", "", yylineno);
        }
        int idx = busca(T, tm_tab, funcao_at, "global");
        if (idx != -1 && strcmp(T[idx].tipo, "void") != 0) {
            erro_semantico("Funcao deve retornar void", "", yylineno);
        }
        $$ = novo(PrgK, "return_void", "void", 0);
    }
    | RETURN expressao PEV {
        if (funcao_at == NULL || strcmp(funcao_at, "") == 0) {
            erro_semantico("Return fora de funcao", "", yylineno);
        }
        int idx = busca(T, tm_tab, funcao_at, "global");
        if (idx != -1 && strcmp(T[idx].tipo, $2->tipo) != 0) {
            erro_semantico("Tipo de retorno incompativel", "", yylineno);
        }

        $$ = novo(PrgK, "return_expr", $2->tipo, 1, $2);
    }
    | RETURN error PEV { yyerrok; }
;

expressao:
    var ATR expressao {
        if (strcmp($1->tipo, "void") == 0) {
            erro_semantico("Atribuicao invalida para void", "", yylineno);
        }
        if ((strcmp($1->tipo, "erro") != 0)&&(strcmp($1->tipo, $3->tipo) != 0)) {
            erro_semantico("Tipos incompativeis na atribuicao", "", yylineno);
        }

        $$ = novo(PrgK, "assignment", $1->tipo, 2, $1, $3);
    }
    | simples_expressao {
        $$ = $1;
    }
    | var ATR error PEV { yyerrok; }
;

var:
    ID {
        int idx = busca(T, tm_tab, $1, escopo_at);
        char *tipo_var = "erro";

        if (idx == -1) {
            idx = busca(T, tm_tab, $1, "global");
        }

        if (idx == -1) {
            erro_semantico("Variavel nao declarada", $1, yylineno);
        } else {
            tipo_var = T[idx].tipo;
        }
        $$ = novo(IdK, strdup($1), tipo_var, 0);
    }
    | ID ACO expressao FCO {
        int idx = busca(T, tm_tab, $1, escopo_at);
        char *tipo_array = "erro";

        if (idx == -1) {
            idx = busca(T, tm_tab, $1, "global");
        }

        if (idx == -1) {
            erro_semantico("Array nao declarado", $1, yylineno);
        } else if (strcmp(T[idx].tipo_dado, "array") != 0) {
            erro_semantico("Variavel nao e array", $1, yylineno);
            tipo_array = T[idx].tipo;
        } else {
            if (strcmp($3->tipo, "int") != 0) {
                erro_semantico("Indice do array deve ser inteiro", "", yylineno);
            }
            tipo_array = T[idx].tipo;
        }
        $$ = novo(IdK, strdup($1), tipo_array, 1, $3);
    }
    | ID ACO error FCO { yyerrok; }
;

simples_expressao:
    soma_expressao relacional soma_expressao {
        if (strcmp($1->tipo, "int") != 0 || strcmp($3->tipo, "int") != 0) {
            erro_semantico("Operandos devem ser inteiros", "", yylineno);
        }
        $$ = novo(PlusK, $2->val, "int", 2, $1, $3); // Usando PlusK para relacionais também
        // Liberar $2->val pois ele foi strdup'd em 'relacional'
        free($2->val);
        free($2); // Liberar o nó temporário para o operador
    }
    | soma_expressao {
        $$ = $1;
    }
    | simples_expressao relacional error { yyerrok; }
;

relacional:
    MEN { $$ = novo(PrgK, "<", NULL, 0); } // Usando PrgK para o operador, mas o valor é crucial
    | MEI { $$ = novo(PrgK, "<=", NULL, 0); }
    | MAR { $$ = novo(PrgK, ">", NULL, 0); }
    | MAI { $$ = novo(PrgK, ">=", NULL, 0); }
    | IGU { $$ = novo(PrgK, "==", NULL, 0); }
    | DIF { $$ = novo(PrgK, "!=", NULL, 0); }
;

soma_expressao:
    soma_expressao SOM termo {
        if (strcmp($1->tipo, "int") != 0 || strcmp($3->tipo, "int") != 0) {
            erro_semantico("Operandos devem ser inteiros", "", yylineno);
        }
        $$ = novo(PlusK, "+", "int", 2, $1, $3);
    }
    | soma_expressao SUB termo {
        if (strcmp($1->tipo, "int") != 0 || strcmp($3->tipo, "int") != 0) {
            erro_semantico("Operandos devem ser inteiros", "", yylineno);
        }
        $$ = novo(PlusK, "-", "int", 2, $1, $3 );
    }
    | termo {
        $$ = $1;
    }
    | soma_expressao SOM error { yyerrok; }
    | soma_expressao SUB error { yyerrok; }
;

termo:
    termo MUL fator {
        if (strcmp($1->tipo, "int") != 0 || strcmp($3->tipo, "int") != 0) {
            erro_semantico("Operandos devem ser inteiros", "", yylineno);
        }

        $$ = novo(PlusK, "*", "int", 2, $1, $3);

    }
    | termo DIV fator {
        if (strcmp($1->tipo, "int") != 0 || strcmp($3->tipo, "int") != 0) {
            erro_semantico("Operandos devem ser inteiros", "", yylineno);
        }
        $$ = novo(PlusK, "/", "int", 2, $1, $3);
    }
    | fator {
        $$ = $1;
    }
    | termo MUL error { yyerrok; }
    | termo DIV error { yyerrok; }
;

fator:
    NUM {
        $$ = novo(ConstK, strdup($1), "int", 0);
    }
    | var {
        $$ = $1;
    }
    | APR expressao FPR {

        $$ = $2;
    }
    | ID APR args FPR {
        int idx = busca(T, tm_tab, $1, "global");
        char *tipo_retorno = "erro";

        if (idx == -1) {
            erro_semantico("Funcao nao declarada", $1, yylineno);
        } else if (strcmp(T[idx].tipo_dado, "func") != 0) {
            erro_semantico("Identificador nao e uma funcao", $1, yylineno);
            tipo_retorno = T[idx].tipo;
        } else {
            tipo_retorno = T[idx].tipo;
        }
        $$ = novo(CallK, strdup($1), tipo_retorno, 1, $3);
    }
    | APR error FPR { yyerrok; }
    | ID APR error FPR { yyerrok; }
;

args:
    arg_lista {
        $$ = novo(PrgK, "args_list", NULL, 1, $1);
    }
    | /* vazio */ {
        $$ = novo(PrgK, "empty_args", NULL, 0);
    }
;

arg_lista:
    arg_lista VIR expressao {
        $$ = novo(PrgK, "arg_list", NULL, 2, $1, $3); // Lista de argumentos com mais de um
    }
    | expressao {
        $$ = novo(PrgK, "arg_list_single", NULL, 1, $1); // Único argumento
    }
    | arg_lista error VIR { yyerrok; }
    | arg_lista error FPR { yyerrok; }
    | error { $$ = NULL; }
;

%%

int main(int argc, char *argv[]) {
    inicia(&T, &tm_tab);
    initQuadList(&quadList); // Inicializa a lista de quádruplas

    if (argc > 1) {
        FILE *input = fopen(argv[1], "r");
        yyin = input;
    } else {
        yyin = stdin;
    }
    yyparse();
    imprime(T, tm_tab); // Imprime a tabela de símbolos

    if (raiz != NULL) {
        imp_ARV(raiz, 0); // Imprime a AST
        gen_intermediate_code(raiz); // GERA O CÓDIGO INTERMEDIÁRIO
        printQuads(&quadList); // Imprime as quádruplas geradas
        free_arv(raiz); // Libera a memória da AST
    }

    freeQuadList(&quadList); // Libera a memória da lista de quádruplas
    // TODO: Adicionar free_tabela(T, tm_tab) para liberar a tabela de símbolos e evitar vazamento de memória
    return 0;
}