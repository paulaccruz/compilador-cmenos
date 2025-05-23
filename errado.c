/* Programa com múltiplos erros */
int main(void) {
    int x;
    y = 5;                  // ERRO SEMÂNTICO: 'y' não declarado (LINHA 3)
    
    if (x < 10 {            // ERRO SINTÁTICO: Falta ')' (LINHA 6)
        return 1;
    }
    #                       //ERRO LÉXICO:(LINHA 9)
    
    void func();            // ERRO SEMÂNTICO: Função 'func' não definida (LINHA 12)
    
    return x;          
}