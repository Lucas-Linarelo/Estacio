// Estrutura para jogo War
#include <stdio.h>
#include <string.h>

// Constante global para quantidade máxima de territórios
#define MAX_PLACES 5

// Definição da struct Territorio
struct Territorio {
    char nome[30];
    char cor[10];A
    int tropas;
};

// Função para limpar o buffer de entrada
void LimparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    struct Territorio territorios[MAX_PLACES]; // Vetor de territórios
    int i;

    printf("============================\n");
    printf("Vamos cadastrar os 5 territorios iniciais do nosso mundo\n");

    // Cadastro dos territórios
    for (i = 0; i < MAX_PLACES; i++) {
        printf("\n--- Cadastrando Territorio %d ---\n", i + 1);

        printf("Nome: ");
        fgets(territorios[i].nome, sizeof(territorios[i].nome), stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0'; // Remove '\n'

        printf("Cor do Exercito: ");
        fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0'; // Remove '\n'

        printf("Numero de tropas: ");
        scanf("%d", &territorios[i].tropas);
        LimparBufferEntrada(); // Limpa o buffer após ler número
    }

    // Exibi dados cadastrados
    printf("\n===== Territorios cadastrados =====\n");
    for (i = 0; i < MAX_PLACES; i++) {
        printf("Territorio %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do Exercito: %s\n", territorios[i].cor);
        printf("Numero de tropas: %d\n", territorios[i].tropas);
        printf("-----------------------------\n");
    }

    return 0;
}