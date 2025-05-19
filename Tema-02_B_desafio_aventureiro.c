#include <stdio.h>
#include <string.h>

typedef struct {
    char pais[50];
    int populacao, turismo;
    float area, pib, densidade;
} Carta;

void calculaDensidade(Carta *carta) {
    if (carta->area > 0) {
        carta->densidade = carta->populacao / carta->area;
    } else {
        carta->densidade = 0;
    }
}

void compararAtributo(Carta *carta1, Carta *carta2, int escolha) {
    switch (escolha) {
        case 1:
            printf("Comparacao de Populacao:\n");
            printf("Populacao de %s: %d\n", carta1->pais, carta1->populacao);
            printf("Populacao de %s: %d\n", carta2->pais, carta2->populacao);
            if (carta1->populacao > carta2->populacao) {
                printf("%s tem populacao maior. \nA carta 1 Vence!\n", carta1->pais);
            } else if (carta1->populacao < carta2->populacao) {
                printf("%s tem populacao maior. \nA carta 2 Vence!\n", carta2->pais);
            } else {
                printf("Os Paises tem populacoes iguais.\n");
            }
            break;
        case 2:
            printf("Comparacao de Turismo:\n");
            printf("Turismo de %s: %d\n", carta1->pais, carta1->turismo);
            printf("Turismo de %s: %d\n", carta2->pais, carta2->turismo);
            if (carta1->turismo > carta2->turismo) {
                printf("%s tem Turismo maior. \nA carta 1 Vence!\n", carta1->pais);
            } else if (carta1->turismo < carta2->turismo) {
                printf("%s tem Turismo maior. \nA carta 2 Vence!\n", carta2->pais);
            } else {
                printf("Os Paises tem Turismo iguais.\n");
            }
            break;
        case 3:
            printf("Comparacao de Area:\n");
            printf("Area de %s: %.2f\n", carta1->pais, carta1->area);
            printf("Area de %s: %.2f\n", carta2->pais, carta2->area);
            if (carta1->area > carta2->area) {
                printf("%s tem Area maior. \nA carta 1 Vence!\n", carta1->pais);
            } else if (carta1->area < carta2->area) {
                printf("%s tem Area maior. \nA carta 2 Vence!\n", carta2->pais);
            } else {
                printf("Os Paises tem Areas iguais.\n");
            }
            break;
        case 4:
            printf("Comparacao de PIB:\n");
            printf("PIB de %s: %.2f\n", carta1->pais, carta1->pib);
            printf("PIB de %s: %.2f\n", carta2->pais, carta2->pib);
            if (carta1->pib > carta2->pib) {
                printf("%s tem PIB maior. \nA carta 1 Vence!\n", carta1->pais);
            } else if (carta1->pib < carta2->pib) {
                printf("%s tem PIB maior. \nA carta 2 Vence!\n", carta2->pais);
            } else {
                printf("Os Paises tem PIBs iguais.\n");
            }
            break;
        case 5:
            printf("Comparacao de densidade:\n");
            printf("Densidade de %s: %.2f\n", carta1->pais, carta1->densidade);
            printf("Densidade de %s: %.2f\n", carta2->pais, carta2->densidade);
            if (carta1->densidade < carta2->densidade) {
                printf("%s tem menor densidade. \nA carta 1 Vence!\n", carta1->pais);
            } else if (carta1->densidade > carta2->densidade) {
                printf("%s tem menor densidade. \nA carta 2 Vence!\n", carta2->pais);
            } else {
                printf("Os Paises tem densidades iguais.\n");
            }
            break;
        default:
            printf("Escolha inválida.\n");
            break;
    }
}

int main() {
    Carta carta1 = {"Brasil", 1270000, 900, 202.312, 1600000000, 0};
    Carta carta2 = {"Espanha", 1070000, 700, 262.312, 1900000000, 0};

    calculaDensidade(&carta1);
    calculaDensidade(&carta2);

    int escolha;
    printf("Escolha um atributo para comparar:\n");
    printf("1. Populacao\n");
    printf("2. Turismo\n");
    printf("3. Area\n");
    printf("4. PIB\n");
    printf("5. Densidade\n");
    printf("Digite o numero do atributo escolhido: ");
    scanf("%d", &escolha);

    compararAtributo(&carta1, &carta2, escolha);

    return 0;
}
