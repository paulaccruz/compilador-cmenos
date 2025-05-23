%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include "arv.h"
#include "parser.tab.h"
#include "tabela.h"

extern int yylineno;
%}

%option yylineno
DIGITO [0-9]
LETRA [a-zA-Z]
VAZIO [ \s]+

%%
"int"             { return INT; }
"void"            { return VOID; }
"if"              { return IF; }
"else"            { return ELSE; }
"while"           { return WHILE; }
"return"          { return RETURN; }
{LETRA}{LETRA}*   { yylval.string = strdup(yytext); return ID; }
{DIGITO}{DIGITO}* { yylval.string = strdup(yytext); return NUM; } 
"+"               { return SOM; }
"-"               { return SUB; }
"*"               { return MUL; }
"/"               { return DIV; }
"<"               { return MEN; }
"<="              { return MEI; }
">"               { return MAR; }
">="              { return MAI; }
"=="              { return IGU; }
"!="              { return DIF; }
"="               { return ATR; }
";"               { return PEV; }
","               { return VIR; }
"("               { return APR; }
")"               { return FPR; }
"["               { return ACO; }
"]"               { return FCO; }
"{"               { return ACH; }
"}"               { return FCH; }
"//".*            { /* Comentário de linha */ }
"/*"([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+"/" { /* Comentário de bloco */ }
{VAZIO}           { /* Ignora */ }
.      {fprintf(stderr, "ERRO LEXICO: %s LINHA: %d\n", yytext, yylineno);}

%%

int yywrap() {
    return 1;
}