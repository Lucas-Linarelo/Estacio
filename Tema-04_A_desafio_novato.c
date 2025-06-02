// Tabuleiro de Batalha naval

#include <stdio.h>

int main (){
    // Declaração do tabuleiro matriz 10x10 com valor 0 (água)
    int tabuleiro[10][10] ={0};

    // Navios linha/coluna
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;

    tabuleiro[5][6] = 3;
    tabuleiro[6][6] = 3;
    tabuleiro[7][6] = 3;

    // exibir o tabuleiro
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            printf("%d", tabuleiro [i][j]);
        }
        printf("\n");
    }

    return 0;
}