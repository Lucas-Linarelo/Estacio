// Tabuleiro de Batalha naval

#include <stdio.h>

int main (){
    // Declaração do tabuleiro matriz 10x10 com valor 0 (água)
    int tabuleiro[10][10] ={0};

    // Navios linha/coluna
    tabuleiro[0][7] = 3;
    tabuleiro[0][8] = 3;
    tabuleiro[0][9] = 3;

    tabuleiro[6][1] = 3;
    tabuleiro[7][1] = 3;
    tabuleiro[8][1] = 3;

    // Navios diagonal
    tabuleiro[1][1] = 3;
    tabuleiro[2][2] = 3;
    tabuleiro[3][3] = 3;

    tabuleiro [7][9] = 3;
    tabuleiro [8][8] = 3;
    tabuleiro [9][7] = 3;


    // exibir o tabuleiro
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            printf("%d", tabuleiro [i][j]);
        }
        printf("\n");
    }

    return 0;
}