// Tabuleiro de Batalha naval
#include <stdio.h>

#define T_LINHA 10
#define T_COLUNA 10
#define S_LINHA 3
#define S_COLUNA 5

void aplicarHabilidade(int tabuleiro[T_LINHA][T_COLUNA], int habilidade[S_LINHA][S_COLUNA], int origemLinha, int origemColuna) {
    for (int i = 0; i < S_LINHA; i++) {
        for (int j = 0; j < S_COLUNA; j++) {
            // Calcula a posição no tabuleiro
            int linhaTabuleiro = origemLinha + i - S_LINHA / 2;
            int colunaTabuleiro = origemColuna + j - S_COLUNA / 2;

            // Verifica se está dentro dos limites do tabuleiro
            if (linhaTabuleiro >= 0 && linhaTabuleiro < T_LINHA && colunaTabuleiro >= 0 && colunaTabuleiro < T_COLUNA) {
                // Aplica a habilidade ao tabuleiro se a posição da matriz de habilidade for 1
                if (habilidade[i][j] == 1) {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                }
            }
        }
    }
}

int main() {
    // Declaração do tabuleiro matriz 10x10 com valor 0 (água)
    int tabuleiro[T_LINHA][T_COLUNA] = {0};

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

    tabuleiro[7][9] = 3;
    tabuleiro[8][8] = 3;
    tabuleiro[9][7] = 3;

    // Habilidade Cone
    int skillCone[S_LINHA][S_COLUNA] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1}
    };

    // Habilidade Cruz
    int skillCruz[S_LINHA][S_COLUNA] = {
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0}
    };

    // Habilidade Octaedro
    int skillOctaedro[S_LINHA][S_COLUNA] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Aplicar habilidades ao tabuleiro
    aplicarHabilidade(tabuleiro, skillCone, 4, 4);      // Origem da habilidade Cone
    aplicarHabilidade(tabuleiro, skillCruz, 6, 6);     // Origem da habilidade Cruz
    aplicarHabilidade(tabuleiro, skillOctaedro, 2, 7); // Origem da habilidade Octaedro

    // Exibir o tabuleiro
    printf("Tabuleiro com habilidades aplicadas:\n");
    for (int i = 0; i < T_LINHA; i++) {
        for (int j = 0; j < T_COLUNA; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("0 "); // Água
            } else if (tabuleiro[i][j] == 3) {
                printf("3 "); // Navio
            } else if (tabuleiro[i][j] == 5) {
                printf("5 "); // Área afetada pela habilidade
            }
        }
        printf("\n");
    }

    // Exibir o tabuleiro (versão com melhro leitura visual)
    printf("Tabuleiro com habilidades aplicadas:\n");
    for (int i = 0; i < T_LINHA; i++) {
        for (int j = 0; j < T_COLUNA; j++) {
            if (tabuleiro[i][j] == 0) {
                printf(". "); // Água
            } else if (tabuleiro[i][j] == 3) {
                printf("N "); // Navio
            } else if (tabuleiro[i][j] == 5) {
                printf("* "); // Área afetada pela habilidade
            }
        }
        printf("\n");
    }

    return 0;
}