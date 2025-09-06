#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes Globais
#define MAX_LIVROS 50
#define MAX_EMPRESTIMOS 100 //dEFINIMOS UMA CAPACIDADE MAXIMA DE EMPRESTIMOS
#define TAM_STRING 100

// definição da struct Livro
struct Livro {
    char titulo[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel; // 1 para disponível, 0 para emprestado
};

// definição da struct Emprestimo
struct Emprestimo {
    int indiceLivro; // Para saber qual livro do array , 'biblioteca' foi emprestado.
    char nomeUsuario[TAM_STRING];
};

// Função para limpar o buffer de entrada
void LimparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função principal (main)
int main () {
    // 1. Alocação dinâmica de memória para o array de livros utilizando arrays estáticos, usando ponteiros.
    struct Livro *biblioteca;
    struct Emprestimo *emprestimos;

    //usamos call para o array de livros. calloc(num_elementos, tamanho_de_cada_elemento)
    //Vantagem; inicializa todos os bytes com 0. Deixando-os disponiveis para uso.
    biblioteca = (struct Livro *)calloc(MAX_LIVROS, sizeof(struct Livro));

    // Usamos malloc para o array de empréstimos. malloc(tamanho_total_em_bytes)
    emprestimos = (struct Emprestimo *)malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));

    //Verificação: É importante verificar se a alocação de memória foi bem-sucedida.
    if (biblioteca == NULL || emprestimos == NULL) {
        printf("Erro na alocacao de memoria!\n");
        return 1; // Sai do programa com código de erro
    }

    int totalLivros = 0; // Contador de livros cadastrados
    int totalEmprestimos = 0; // Contador de empréstimos realizados
    int opcao;

    do {
        printf("\n=== Sistema de Biblioteca 2 ===\n");
        printf("-----------------------------\n");
        printf("1. Cadastrar Livro\n");
        printf("2. Listar Livros\n");
        printf("3. Emprestar Livro\n");
        printf("4. Listar Emprestimos\n");
        printf("5. Sair\n");
        printf("-----------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        LimparBufferEntrada(); // Limpa o buffer após ler número

        switch (opcao) {

            case 1: { // Cadastro de Livro
                printf("\n--- Cadastrar Livro ---\n");
                if (totalLivros < MAX_LIVROS) {
                    printf("Titulo: ");
                    fgets(biblioteca[totalLivros].titulo, TAM_STRING, stdin);
                    biblioteca[totalLivros].titulo[strcspn(biblioteca[totalLivros].titulo, "\n")] = '\0';

                    printf("Autor: ");
                    fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);
                    biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';

                    printf("Editora: ");
                    fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);
                    biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0';

                    printf("Edicao: ");
                    scanf("%d", &biblioteca[totalLivros].edicao);
                    LimparBufferEntrada();

                    biblioteca[totalLivros].disponivel = 1;
                    totalLivros++;
                    printf("Livro cadastrado com sucesso!\n");
                } else {
                    printf("Capacidade maxima de livros atingida!\n");
                }
                printf("Pressione Enter para continuar...");
                getchar();
                break;
            }

            case 2: { // Listagem de Livros
                printf("\n--- Lista de Livros ---\n");
                if (totalLivros == 0) {
                    printf("Nenhum livro cadastrado.\n");
                } else {
                    for (int i = 0; i < totalLivros; i++) {
                        printf("Livro %d:\n", i + 1);
                        printf("Titulo: %s\n", biblioteca[i].titulo);
                        printf("Autor: %s\n", biblioteca[i].autor);
                        printf("Editora: %s\n", biblioteca[i].editora);
                        printf("Edicao: %d\n", biblioteca[i].edicao);
                        printf("Status: %s\n", biblioteca[i].disponivel ? "Disponivel" : "Emprestado");
                        printf("-----------------------------\n");
                    }
                }
                printf("Pressione Enter para continuar...");
                getchar();
                break;
            }

            case 3: { // Realizar empréstimo
                printf("\n--- Emprestar Livro ---\n");
                if (totalEmprestimos >= MAX_EMPRESTIMOS) {
                    printf("Capacidade maxima de emprestimos atingida!\n");
                } else {
                    printf("Livros Disponiveis:\n");
                    int disponiveis = 0;
                    for (int i = 0; i < totalLivros; i++) {
                        if (biblioteca[i].disponivel) {
                            printf("%d. %s\n", i + 1, biblioteca[i].titulo);
                            disponiveis++;
                        }
                    }
                    if (disponiveis == 0) {
                        printf("Nenhum livro disponivel para emprestimo.\n");
                    } else {
                        printf("Escolha o numero do livro para emprestar: ");
                        int numLivro;
                        scanf("%d", &numLivro);
                        LimparBufferEntrada();

                        int indice = numLivro - 1;
                        if (indice >= 0 && indice < totalLivros && biblioteca[indice].disponivel) {
                            printf("Digite o nome do usuario: ");
                            fgets(emprestimos[totalEmprestimos].nomeUsuario, TAM_STRING, stdin);
                            emprestimos[totalEmprestimos].nomeUsuario[strcspn(emprestimos[totalEmprestimos].nomeUsuario, "\n")] = '\0';

                            emprestimos[totalEmprestimos].indiceLivro = indice;
                            biblioteca[indice].disponivel = 0;
                            totalEmprestimos++;
                            printf("Livro emprestado com sucesso!\n");
                        } else {
                            printf("Escolha invalida ou livro não disponivel.\n");
                        }
                    }
                }
                printf("Pressione Enter para continuar...");
                getchar();
                break;
            }

            case 4: { // Listagem de Empréstimos
                printf("\n--- Lista de Emprestimos ---\n");
                if (totalEmprestimos == 0) {
                    printf("Nenhum emprestimo realizado.\n");
                } else {
                    for (int i = 0; i < totalEmprestimos; i++) {
                        int indiceLivro = emprestimos[i].indiceLivro;
                        printf("Emprestimo %d:\n", i + 1);
                        printf("Livro: %s\n", biblioteca[indiceLivro].titulo);
                        printf("Usuario: %s\n", emprestimos[i].nomeUsuario);
                        printf("-----------------------------\n");
                    }
                }
                printf("Pressione Enter para continuar...");
                getchar();
                break;
            }

            case 5:
                printf("Saindo do sistema. Ate mais!\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 5);

    free(biblioteca);
    free(emprestimos);
    printf("Memoria liberada. Programa encerrado.\n");
    return 0;
}