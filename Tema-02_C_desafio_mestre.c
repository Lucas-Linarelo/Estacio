#include <stdio.h>
#include <string.h>

typedef struct {
    char pais[50];
    int populacao, turismo;
    float area, pib, densidade;
} Carta;

void calculaDensidade(Carta *carta) {
    carta->densidade = (carta->area > 0) ? (carta->populacao / carta->area) : 0;
}

void compararAtributo(Carta *carta1, Carta *carta2, int escolha) {
    switch (escolha) {
        case 1:
            printf("------------------------\n");
            printf("Comparacao de Populacao:\n");
            printf("Populacao de %s: %d\n", carta1->pais, carta1->populacao);
            printf("Populacao de %s: %d\n", carta2->pais, carta2->populacao);
            printf("%s tem populacao maior. \n%s\n",
                  (carta1->populacao > carta2->populacao) ? carta1->pais :
                  (carta1->populacao < carta2->populacao) ? carta2->pais : "Os Paises tem populacoes iguais.",
                  (carta1->populacao == carta2->populacao) ? "" :
                  (carta1->populacao > carta2->populacao) ? "A carta 1 Vence!" : "A carta 2 Vence!");
            printf("------------------------\n");
                  break;
        case 2:
            printf("------------------------\n");
            printf("Comparacao de Turismo:\n");
            printf("Turismo de %s: %d\n", carta1->pais, carta1->turismo);
            printf("Turismo de %s: %d\n", carta2->pais, carta2->turismo);
            printf("%s tem Turismo maior. \n%s\n",
                  (carta1->turismo > carta2->turismo) ? carta1->pais :
                  (carta1->turismo < carta2->turismo) ? carta2->pais : "Os Paises tem Turismo iguais.",
                  (carta1->turismo == carta2->turismo) ? "" :
                  (carta1->turismo > carta2->turismo) ? "A carta 1 Vence!" : "A carta 2 Vence!");
            printf("------------------------\n");
                  break;
        case 3:
            printf("------------------------\n");
            printf("Comparacao de Area:\n");
            printf("Area de %s: %.2f\n", carta1->pais, carta1->area);
            printf("Area de %s: %.2f\n", carta2->pais, carta2->area);
            printf("%s tem Area maior. \n%s\n",
                  (carta1->area > carta2->area) ? carta1->pais :
                  (carta1->area < carta2->area) ? carta2->pais : "Os Paises tem Areas iguais.",
                  (carta1->area == carta2->area) ? "" :
                  (carta1->area > carta2->area) ? "A carta 1 Vence!" : "A carta 2 Vence!");
            printf("------------------------\n");
                  break;
        case 4:
            printf("------------------------\n");
            printf("Comparacao de PIB:\n");
            printf("PIB de %s: %.2f\n", carta1->pais, carta1->pib);
            printf("PIB de %s: %.2f\n", carta2->pais, carta2->pib);
            printf("%s tem PIB maior. \n%s\n",
                  (carta1->pib > carta2->pib) ? carta1->pais :
                  (carta1->pib < carta2->pib) ? carta2->pais : "Os Paises tem PIBs iguais.",
                  (carta1->pib == carta2->pib) ? "" :
                  (carta1->pib > carta2->pib) ? "A carta 1 Vence!" : "A carta 2 Vence!");
            printf("------------------------\n");
                  break;
        case 5:
            printf("------------------------\n");
            printf("Comparacao de Densidade:\n");
            printf("Densidade de %s: %.2f\n", carta1->pais, carta1->densidade);
            printf("Densidade de %s: %.2f\n", carta2->pais, carta2->densidade);
            printf("%s tem menor densidade. \n%s\n",
                  (carta1->densidade < carta2->densidade) ? carta1->pais :
                  (carta1->densidade > carta2->densidade) ? carta2->pais : "Os Paises tem densidades iguais.",
                  (carta1->densidade == carta2->densidade) ? "" :
                  (carta1->densidade < carta2->densidade) ? "A carta 1 Vence!" : "A carta 2 Vence!");
            printf("------------------------\n");
            break;
        default:
            printf("Escolha inválida.\n");
            break;
    }
}

float somaAtributos(Carta*carta, int escolha1, int escolha2){
  float soma =0;
  switch (escolha1){
/* Operador composto em C
    soma
    Variável de acumulo de valores.
    
    +=
    (Operador de adição e atribuição) adiciona o valor 
    à direita ao valor à esquerda e atribui o resultado 
    de volta à variável à esquerda(soma).
    
    carta->populacao
    Acessa o membro populacao do objeto apontado por carta.
    Se carta é um ponteiro para uma estrutura, -> é usado 
    para acessar os membros da estrutura.
*/
    case 1: soma+= carta->populacao; break;
    case 2: soma+= carta->turismo; break;
    case 3: soma+= carta->area; break;
    case 4: soma+= carta->pib; break;
    case 5: soma+= carta->densidade; break;
  }
  switch (escolha2){
    case 1: soma+= carta->populacao; break;
    case 2: soma+= carta->turismo; break;
    case 3: soma+= carta->area; break;
    case 4: soma+= carta->pib; break;
    case 5: soma+= carta->densidade; break;
  }
  return soma;
}

int main() {
    Carta carta1 = {"Brasil", 1270000, 900, 202.312, 1600000000, 0};
    Carta carta2 = {"Espanha", 1070000, 700, 262.312, 1900000000, 0};

    calculaDensidade(&carta1);
    calculaDensidade(&carta2);

    int escolha1, escolha2;

    /*
    Menus Dinâmicos: Crie menus interativos e dinâmicos usando switch. "Dinâmicos" significa que, por exemplo, após o jogador
    escolher o primeiro atributo, esse atributo não deve mais aparecer como opção para a escolha do segundo atributo.
    */
    printf("Escolha o primeiro atributo para comparar:\n");
    printf("1. Populacao\n");
    printf("2. Turismo\n");
    printf("3. Area\n");
    printf("4. PIB\n");
    printf("5. Densidade\n");
    printf("Digite o numero do atributo escolhido: ");
    scanf("%d", &escolha1);
    compararAtributo(&carta1, &carta2, escolha1);

    do {
        printf("\nEscolha o segundo atributo para comparar (diferente da escolha anterior):\n");
        for (int i = 1; i <= 5; i++) {
            if (i != escolha1) {
                printf("%d. ", i);
                switch (i) {
                    case 1: printf("Populacao\n"); break;
                    case 2: printf("Turismo\n"); break;
                    case 3: printf("Area\n"); break;
                    case 4: printf("PIB\n"); break;
                    case 5: printf("Densidade\n"); break;
                }
            }
        }
        printf("Digite o numero do atributo escolhido: ");
        scanf("%d", &escolha2);
    } while (escolha2 == escolha1 || escolha2 < 1 || escolha2 > 5);
    compararAtributo(&carta1, &carta2, escolha2);

  /*
  Soma dos Atributos: Após comparar os dois atributos individualmente, o sistemadeve somar
  os valores dos atributos para cada carta. A carta com a maior soma vence a rodada.
  */
float soma1 = somaAtributos(&carta1, escolha1, escolha2);
float soma2 = somaAtributos(&carta2, escolha1, escolha2);

printf("\nSoma dos atributos selecionados: \n");
printf("A soma dos atribuos da %s: %.2f\n", carta1.pais, soma1);
printf("A soma dos atribuos da %s: %.2f\n", carta2.pais, soma2);
printf("%s vence a rodada!\n", (soma1 > soma2) ? carta1.pais : (soma1 < soma2) ? carta2.pais : "Empate!");

/*
Equivalência ternária

(soma1 > soma2) ? carta1.pais
if (soma1 > soma2) {printf("%s vence a rodada!\n", carta1.pais);}

Código completo

printf("\nSoma dos atributos:\n");
    printf("Soma dos atributos da %s: %.2f\n", carta1.pais, soma1);
    printf("Soma dos atributos da %s: %.2f\n", carta2.pais, soma2);

    if (soma1 > soma2) {
        printf("%s vence a rodada!\n", carta1.pais);
    } else if (soma1 < soma2) {
        printf("%s vence a rodada!\n", carta2.pais);
    } else {
        printf("Empate na rodada!\n");
    }
*/

    return 0;
}