%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arv.h"
#include "tabela.h"


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
        $$ = novo("programa", NULL, 1, $1);
        raiz = $$;
    }
;

declaracao_lista:
    declaracao_lista declaracao {
        $$ = novo("declaracao_lista", NULL, 2, $1, $2);
    }
    | declaracao_lista error PEV { yyerrok; $$ = $1; }
    | declaracao_lista error FCH { yyerrok; $$ = $1; }
    | declaracao {
        $$ = novo("declaracao_lista", "declaracao", 1, $1);
    }
;

declaracao:
    var_declaracao {
        $$ = novo("declaracao", "var", 1, $1);
    }
    | fun_declaracao {
        $$ = novo("declaracao", "func", 1, $1);
    }
;

var_declaracao:
    tipo_especificador ID PEV {
        if (busca(T, tm_tab, $2, escopo_at) != -1) {
            erro_semantico("Variavel ja declarada", $2, yylineno);
        } else {
            add(&T, &tm_tab, $2, "var", $1, yylineno, escopo_at);
        }

       $$ = novo("var_declaracao", "var", 2, novo($1,$1,0), novo($2, "id", 0));

    }
    | tipo_especificador ID ACO NUM FCO PEV {
        if (busca(T, tm_tab, $2, escopo_at) != -1) {
            erro_semantico("Array ja declarado", $2, yylineno);
        } else {
            add(&T, &tm_tab, $2, "array", $1, yylineno, escopo_at);
        }
        $$ = novo("var_declaracao", "array", 3, novo($1,$1,0), novo($2,"id", 0), novo($4, "int", 0));
    }
    | tipo_especificador error PEV { yyerrok; }
;

tipo_especificador:
    INT { $$ = "int"; }
    | VOID { $$ = "void"; }
;

fun_declaracao:
    tipo_especificador ID APR { 

        funcao_at = $2;
        escopo_at = $2;

        if (busca(T, tm_tab, $2, "global") != -1) {

            erro_semantico("Funcao ja declarada", $2, yylineno);
        } else {
            add(&T, &tm_tab, $2, "func", $1, yylineno, "global");

        }
    } params FPR composto_declaracao {
  
        $$ = novo("fun_declaracao", NULL, 4, novo($1, $1, 0), novo($2, $1, 0), $5, $7);                

        escopo_at = "global";
        funcao_at = NULL;
    }

    | tipo_especificador ID APR error FPR composto_declaracao { yyerrok; }
    | tipo_especificador ID APR error FCH { yyerrok; }
;

params:
    param_lista {
        $$ = novo("params", "param_lista", 1, $1);
    }
    | VOID {
        $$ = novo("params", NULL, 1, novo("void", "tipo", 0));
    }
    | error {yyerrok;}
;

param_lista:
    param_lista VIR param arg_lista {
        $$ = novo("param_lista", NULL, 2, $1, $3);
    }
    | param_lista error VIR { yyerrok; } 
    | param_lista error FPR { yyerrok; }
    | param {
        $$ = novo("param_lista", "param", 1, $1);
    }
;

param:
    tipo_especificador ID {
        if (busca(T, tm_tab, $2, escopo_at) != -1) {
            erro_semantico("Parametro ja declarado", $2, yylineno);
        } else {
            add(&T, &tm_tab, $2, "parametro", $1, yylineno, escopo_at);
        }
        $$ = novo("param", "var", 2, novo($1,$1, 0), novo($2, "id",0));
    }
    | tipo_especificador ID ACO FCO {
        if (busca(T, tm_tab, $2, escopo_at) != -1) {
            erro_semantico("Parametro array ja declarado", $2, yylineno);
        } else {
            add(&T, &tm_tab, $2, "param_array", $1, yylineno, escopo_at);
        }
        $$ = novo("param","array", 2, novo($1,$1, 0), novo($2,"id", 0));
    }
    | tipo_especificador error {yyerrok;}
;

composto_declaracao:
    ACH local_declaracoes statement_lista FCH {
        $$ = novo("composto_declaracao",NULL, 2, $2, $3);
    }
    | ACH error FCH { yyerrok; } 
;

local_declaracoes:
    local_declaracoes var_declaracao {
        $$ = novo("local_declaracoes",NULL, 2, $1, $2);
    }
    | /* vazio */ {
        $$ = novo("local_declaracoes","vazio", 0);
    }
;

statement_lista:
    statement_lista statement {
        $$ = novo("statement_lista",NULL, 2, $1, $2);
    }
    | statement_lista error PEV { yyerrok; }  // Recupera após ';'
    | statement_lista error FCH { yyerrok; }  // Recupera após '}'
    | statement_lista error FPR { yyerrok; }  // Recupera após ')'
    | /* vazio */ {
        $$ = novo("statement_lista","vazio", 0);
    }
;

statement:
    expressao_declaracao {
        $$ = novo("statement","exp", 1, $1);
    }
    | composto_declaracao {
        $$ = novo("statement","comp", 1, $1);
    }
    | selecao_declaracao {
        $$ = novo("statement","selec", 1, $1);
    }
    | iteracao_declaracao {
        $$ = novo("statement","inter", 1, $1);
    }
    | retorno_declaracao {
        $$ = novo("statement", "retorno",1, $1);
    }
;

expressao_declaracao:
    expressao PEV {
        $$ = novo("expressao_declaracao",NULL, 1, $1);
    }
    | PEV {
        $$ = novo("expressao_declaracao",NULL, 0);
    }
    | error PEV { yyerrok; }
;

selecao_declaracao:
    IF APR expressao FPR statement {
        if (strcmp($3->tipo, "int") != 0) {
            erro_semantico("Condicao do if deve ser inteira", "", yylineno);
        }
        $$ = novo("selecao_declaracao", "condicional", 3, novo("if", NULL, 0),  $3, $5);
    }
    | IF APR error FPR statement { yyerrok; }
    | IF error statement { yyerrok; }
    | IF APR expressao FPR statement ELSE statement {
        if (strcmp($3->tipo, "int") != 0) {
            erro_semantico("Condicao do if deve ser inteira", "", yylineno);
        }
        $$ = novo("selecao_declaracao", "condicional", 5,novo("if", NULL, 0), $3,$5,novo("else", NULL, 0), $7);
    }
     | IF APR error FPR statement ELSE statement { yyerrok; }
;

iteracao_declaracao:
    WHILE APR expressao FPR statement {
        if (strcmp($3->tipo, "int") != 0) {
            erro_semantico("Condicao do while deve ser inteira", "", yylineno);
        }
        $$ = novo("iteracao_declaracao", "loop", 3, novo("while", NULL, 0), $3, $5);
    }
    | WHILE APR error FPR statement { yyerrok; }
    | WHILE error statement { yyerrok; }
;

retorno_declaracao:
    RETURN PEV {
        if (funcao_at == NULL) {
            erro_semantico("Return fora de funcao", "", yylineno);
        }
        int idx = busca(T, tm_tab, funcao_at, "global");
        if (idx != -1 && strcmp(T[idx].tipo, "void") != 0) {
            erro_semantico("Funcao deve retornar void", "", yylineno);
        }
        $$ = novo("retorno_declaracao", "void", 1, 
                 novo("return", NULL, 0) 
        );
    }
    | RETURN expressao PEV {
        if (funcao_at == NULL) {
            erro_semantico("Return fora de funcao", "", yylineno);
        }
        int idx = busca(T, tm_tab, funcao_at, "global");
        if (idx != -1 && strcmp(T[idx].tipo, $2->tipo) != 0) {
            erro_semantico("Tipo de retorno incompativel", "", yylineno);
        }

        $$ = novo("retorno_declaracao", $2->tipo, 2,
                 novo("return", NULL, 0),$2);
    }
    | RETURN error PEV { yyerrok; }
;

expressao:
    var ATR expressao {
        if (strcmp($1->tipo, "void") == 0) {
            erro_semantico("Atribuicao invalida para void", "", yylineno);
        }
        if (($1->tipo != "erro")&&(strcmp($1->tipo, $3->tipo) != 0)) {
            erro_semantico("Tipos incompativeis na atribuicao", "", yylineno);
        }

        $$ = novo("expressao", $1->tipo, 2, $1, $3);
    }
    | simples_expressao { // herda o tipo 
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

        $$ = novo("var", tipo_var, 1, novo($1, "id", 0) );
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

        $$ = novo("var", tipo_array, 2,novo($1, "id", 0), $3);
    }
    | ID ACO error FCO { yyerrok; }
;

simples_expressao:
    soma_expressao relacional soma_expressao {
        if (strcmp($1->tipo, "int") != 0 || strcmp($3->tipo, "int") != 0) {
            erro_semantico("Operandos devem ser inteiros", "", yylineno);
        }
        $$ = novo("simples_expressao", "int", 3,$1, $2,$3);
    }
    | soma_expressao {
        $$ = $1;  // herda o tipo 
    }
    | simples_expressao relacional error { yyerrok; }
;

relacional:
    MEN { $$ = novo("<", NULL, 0); }
    | MEI { $$ = novo("<=", NULL, 0); }
    | MAR { $$ = novo(">", NULL, 0); }
    | MAI { $$ = novo(">=", NULL, 0); }
    | IGU { $$ = novo("==", NULL, 0); }
    | DIF { $$ = novo("!=", NULL, 0); }
;

soma_expressao:
    soma_expressao SOM termo {
        if (strcmp($1->tipo, "int") != 0 || strcmp($3->tipo, "int") != 0) {
            erro_semantico("Operandos devem ser inteiros", "", yylineno);
        }
        $$ = novo("soma_expressao", "int", 3, $1, novo("+", NULL, 0), $3);
    }
    | soma_expressao SUB termo {
        if (strcmp($1->tipo, "int") != 0 || strcmp($3->tipo, "int") != 0) {
            erro_semantico("Operandos devem ser inteiros", "", yylineno);
        }
        $$ = novo("soma_expressao", "int", 3, $1, novo("-", NULL, 0), $3 );
    }
    | termo {
        $$ = $1; // herda
    }
    | soma_expressao SOM error { yyerrok; }
    | soma_expressao SUB error { yyerrok; }
;

termo:
    termo MUL fator {
        if (strcmp($1->tipo, "int") != 0 || strcmp($3->tipo, "int") != 0) {
            erro_semantico("Operandos devem ser inteiros", "", yylineno);
        }

        $$ = novo("termo", "int", 3, $1, novo("*", NULL, 0), $3);

    }
    | termo DIV fator {
        if (strcmp($1->tipo, "int") != 0 || strcmp($3->tipo, "int") != 0) {
            erro_semantico("Operandos devem ser inteiros", "", yylineno);
        }
        $$ = novo("termo", "int", 3, $1, novo("/", NULL, 0), $3);
    }
    | fator {
        $$ = $1; // herda
    }
    | termo MUL error { yyerrok; }
    | termo DIV error { yyerrok; }
;

fator:
    NUM {
        $$ = novo("NUM", "int", 1, novo($1, "num", 0) );
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
            tipo_retorno = T[idx].tipo; // Tipo de retorno da função
        }

        $$ = novo("chamada_func", tipo_retorno, 2, novo($1, "id", 0), $3 );
    }
    | APR error FPR { yyerrok; }
    | ID APR error FPR { yyerrok; }
;

args:
    arg_lista {
        $$ = novo("args", "lista_args", 1, $1);
    }
    | /* vazio */ {
        $$ = novo("args", "void", 0);
    }
;

arg_lista:
    arg_lista VIR expressao {
        $$ = novo("arg_lista", "lista_args", 2, $1, $3);
    }
        | expressao {
        $$ = novo("arg_lista", "lista_args", 1, $1);
    }
    | arg_lista error VIR { yyerrok; } 
    | arg_lista error FPR { yyerrok; }
    | error

;

%%

int main(int argc, char *argv[]) {
    inicia(&T, &tm_tab);
    if (argc > 1) {
        FILE *input = fopen(argv[1], "r");
        yyin = input;
    } else {
        yyin = stdin;
    }
    yyparse();
    imprime(T, tm_tab); 
    imp_ARV(raiz, 0);
    free_arv(raiz);
    return 0;
}