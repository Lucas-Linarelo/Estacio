// Estrutura para jogo War
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Constante global para quantidade máxima de territórios
#define MAX_PLACES 5

// Definição da struct Territorio
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

// Função para limpar o buffer de entrada
void LimparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para exibir os territorios
void ExibirTerritorios(struct Territorio *territorios, int quantidade) {
    printf("\n===== Territorios =====\n");
    for (int i = 0; i < quantidade; i++) {
        printf("\nTerritorio: %02d\n", i + 1);
        printf("Cor: %s - Tropas: %d\n", territorios[i].cor, territorios[i].tropas);
    }
    printf("===================================\n");
}

int main() {
    struct Territorio *territorios; // Ponteiro para array de territórios
    int i;

    //alocação dinâmica de memória para o array de territórios
    territorios = (struct Territorio*) malloc(MAX_PLACES * sizeof(struct Territorio));
    if (territorios == NULL){
        printf("Erro na alocacao de memoria!\n");
        return 1; // Sai do programa com código de erro
    }

    printf("============================\n");
    printf("Vamos cadastrar os 5 territorios iniciais\n");

    // Cadastro dos territórios
    for (i = 0; i < MAX_PLACES; i++) {
        printf("\n=== Cadastrando Territorio %d ===\n", i + 1);

        printf("Nome: ");
        fgets(territorios[i].nome, sizeof(territorios[i].nome), stdin);
        territorios[i].nome[strcspn(territorios[i].nome,"\n")] = '\0';

        printf("Cor do Exercito: ");
        fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';

        printf("Numero de tropas: ");
        scanf("%d", &territorios[i].tropas);
        LimparBufferEntrada(); // Limpa o buffer após ler número
    }

    ExibirTerritorios(territorios, MAX_PLACES);

    // Fase de ataque
    srand(time(NULL));
    int atacante, defensor;
    while (1) {
        printf("\nFase de ataque\n");
        printf("Escolha o territorio atacante (1 a %d ou 0 para sair): ", MAX_PLACES);
        scanf("%d", &atacante);
        LimparBufferEntrada();

        if (atacante == 0) {
            printf("Saindo da fase de ataque.\n");
            break;
        }
        if (atacante < 1 || atacante > MAX_PLACES) {
            printf("Atacante invalido!\n");
            continue;
        }
        if (territorios[atacante-1].tropas < 2) {
            printf("O territorio atacante precisa ter pelo menos 2 tropas!\n");
            continue;
        }

        printf("Escolha o territorio defensor (1 a %d): ", MAX_PLACES);
        scanf("%d", &defensor);
        LimparBufferEntrada();

        if (defensor < 1 || defensor > MAX_PLACES || defensor == atacante) {
            printf("Defensor invalido!\n");
            continue;
        }
        if (territorios[defensor-1].tropas < 1) {
            printf("O territorio defensor nao possui tropas!\n");
            continue;
        }

        // Rolagem dos dados
        int dado_atacante = rand() % 6 + 1;
        int dado_defensor = rand() % 6 + 1;

        printf("\n%s rolou um dado e tirou %d\n", territorios[atacante-1].cor, dado_atacante);
        printf("%s rolou um dado e tirou %d\n", territorios[defensor-1].cor, dado_defensor);

        if (dado_atacante > dado_defensor) {
            printf("Vitoria do ataque! O defensor perdeu 1 tropa.\n");
            territorios[defensor-1].tropas--;
        } else {
            printf("Vitoria da defesa! O atacante perdeu 1 tropa.\n");
            territorios[atacante-1].tropas--;
        }

        printf("\nPressione ENTER para continuar para o proximo turno...");
        LimparBufferEntrada();

        ExibirTerritorios(territorios, MAX_PLACES);
    }

    free(territorios);
    return 0;
}