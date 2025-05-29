/*
Você deverá modificar o programa em C, que já contém a movimentação da Torre, Bispo, Rainha e Cavalo, realizando as seguintes alterações:
Recursividade
Loops Complexos para o Cavalo
Bispo com Loops Aninhados

Bisco: 5 casas para diagonal direita (cima direita)
Torre: 5 casas para direita
Rainha: 8 casas para esqueda
Cavalo: 1 para cima 2 direita
*/

#include <stdio.h>

void moveCim(int casas){
    if(casas > 0){
        moveCim(casas - 1);
        printf("Move-se para a cima %d casa(s).\n", casas);
    }
}
void moveDir(int casas){
    if(casas > 0){
        moveDir(casas - 1);
        printf("Move-se para a direita %d casa(s).\n", casas);
    }
}
void moveEsq(int casas){
    if(casas > 0){
        moveEsq(casas - 1);
        printf("Move-se para a direita %d casa(s).\n", casas);
    }
}

int main(){

    //Recursão
    printf("----------------\n");
    printf("Movimentações:\n");
    printf("----------------\n");
    int casasTorre = 5;
    printf("Torre\n");
    printf("----------------\n");
    moveDir(casasTorre);
    printf("----------------\n");
    //Recursão
    int casasRainha = 8;
    printf("Rainha\n");
    printf("----------------\n");
    moveEsq(casasRainha);
    printf("----------------\n");
    //Loop aninahdos bispo diagonal direita
    int casasBispo = 5; 
    printf("Bispo\n");          
    printf("----------------\n");
    // Loop externo para cada um dos 5 "passos" da diagonal
    for(int i = 0; i < casasBispo; i++){ 
        // Primeiro movimento: para cima
        for (int j = 0; j < 2; j++) {
            // O número de casas (i) aumenta com cada iteração para simular o mesmo resultado da recursão.
            if (j == 0) {
                printf("Move-se para cima %d casa(s).\n", i + 1); 
            } else {
                printf("Move-se para a direita %d casa(s).\n", i + 1);
            }
        }
    }
    printf("----------------\n");
// Loop complexo para o cavalo
int casasCavalo = 1; // Indica que o padrão "1 casa para cima e 2 casas para a direita" ocorre uma vez.
printf("Cavalo\n");
printf("----------------\n");
for (int i = 0; i < casasCavalo; i++) {
    // Primeiro movimento: para cima
    printf("Move-se para cima 1 casa(s).\n");
    for (int j = 0; j < 2; j++) { 
        // Primeiro movimento: para direita
        printf("Move-se para a direita %d casa(s).\n", j + 1);
    }
}

    return 0;
}