// /*

// Vetores e Matrizes

// Conhecidos como Array
// Coleção de elementos de mesmo tipo na memória
// Acesso direto por índices (iniciando sempre pelo 0)

// Quando tratamos de matrizes, podemos pensar em uma tabela com linhas e colunas
// Devemos sempre lembrar que o primeiro elemento de um vetor é o 0, e não o 1
// O tipo de dados entre os diferentes valores deve ser o mesmo, ou seja, se for um vetor de inteiros, todos os valores devem ser inteiros

// Arrays armazenam a acessam multiplos valores
// Possuem tamanho fixo definido e acessos por índice

// */

// //Array fracionário (Float)
// #include <stdio.h>
// int main(){

//     float notas[3] = {85.5, 90.0, 78.3};

//     printf("Notas dos alunos:\n");
//     printf("Aluno 1: %.1f\n", notas[0]);
//     printf("Aluno 2: %.1f\n", notas[1]);
//     printf("Aluno 3: %.1f\n", notas[2]);

//     return 0;
// }

// //Array de letras(Char)
// #include <stdio.h>

// int main(){

//     char letras[4] = {'A', 'B', 'C', 'D'};

//     printf("Letras do alfabeto:\n");
//     printf("Letra 1: %c\n", letras[0]);
//     printf("Letra 2: %c\n", letras[1]);
//     printf("Letra 3: %c\n", letras[2]);
//     printf("Letra 4: %c\n", letras[3]);

//     return 0;
// }


// //Array de strings com estrutua de repetição - Assim podemos percorrer N valores com menos linhas de código
// #include <stdio.h>

// int main(){

//     char *nomes[] = {"Alice", "Bob", "Charlie", "Diana"};
//     int i;

//     for(int i = 0; i < 4; i++){
//         printf("%s \n", nomes[i]);
//     }

//     return 0;
// }

// // Array bidimensional (Matriz)
// #include <stdio.h>

// int main(){
//     int matriz [3] [3]; // Declaração de uma matriz 3x3 (Seu tamanho)
//     /*  
//         [0][0] [0][1] [0][2]
//         [1][0] [1][1] [1][2]
//         [2][0] [2][1] [2][2]

//         [1] [2] [3]
//         [4] [5] [6]
//         [7] [8] [9]
//     */

//     // Inicializando os elementos da matriz
//     matriz [0] [0]=1;
//     matriz [0] [1]=2;
//     matriz [0] [2]=3;
//     matriz [1] [0]=4;
//     matriz [1] [1]=5;
//     matriz [1] [2]=6;
//     matriz [2] [0]=7;
//     matriz [2] [1]=8;
//     matriz [2] [2]=9;
//     // Acessando elemetnos da matriz
//     printf("O elemento na posição [0][0] é: %d\n", matriz[0][0]);
//     printf("O elemento na posição [1][1] é: %d\n", matriz[1][1]);
//     printf("O elemento na posição [2][2] é: %d\n", matriz[2][2]);

//     return 0;
// }

// #include <stdio.h>

// int main (){

//     int index;

//     char * nomesAlunos [3][3]= {
//             {"Aluno 0", "PT 30", "Mat: 90"},
//             {"Aluno 1", "PT 20", "Mat: 80"},
//             {"Aluno 2", "PT 10", "Mat: 70"}
//     };

//     printf("Digita o número do alunoq ue queira ver as notas: \n");
//     printf("0 - Aluno 0\n");
//     printf("1 - Aluno 1\n");
//     printf("2 - Aluno 2\n");

//     scanf("%d", &index);

//     printf("A nota do aluno %s são: %s, %s.\n", nomesAlunos[index][0],nomesAlunos[index][1],nomesAlunos[index][2]);

//     return 0;
// }

/*  
    Manipulação de Matrizes
    - Melhora a eficiência do código
    - Permite aplicar diferente lógicas na matriz
    - Condicionais que evitam erros
    - Loops aninhados simplificam a menipulação de dados
*/

// // Modificação condicional da matriz

// #include <stdio.h>

// int main (){
//     // Matriz exibida de forma linear
//     int matriz [3][3] = { {1,2,3}, {4,5,6}, {7,8,9}};

//     // Estrutura de repetiçao aninhada com de acordo com o tamanho máximo da matriz
//     for (int i=0; i<3; i++){
//         for (int j=0; j<3; j++){
//             if (matriz[i][j]>5){
//                 matriz [i][j] = -matriz[i][j]; // Inverte o sinal dos números maiores que 5
//             }
//             // Print dentro do loop interno
//             printf("%d ", matriz[i][j]);
//         }
//         printf("\n"); // Pula para a próxima linha após imprimir uma linha da matriz
//     }
//     return 0;
// }

// Contagem condicional em uma matriz

// #include <stdio.h>

// int main (){
//     int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     int contaPar=0, contaImpar=0;
//     for (int i =0; i<3; i++){               // loop externo para linhas
//         for (int j=0; j<3; j++){            // Loops Interno para colunas
//             if (matriz[i][j] %2 ==0){
//                 contaPar++;                 // Incrementa contador de pares
//             } else {
//                 contaImpar++;               // Incrementa contador de ímpares
//             }
//         }
//     }
//     //imprimindo os resultados após cada linha
//     printf("Número de elementos pares: %d\n", contaPar);
//     printf("Número de elementos ímpares: %d\n", contaImpar);
//     return 0;
// }

// // Substituição condicional de elementos em uma matriz
// #include <stdio.h>
// int main (){
//     int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

//     // Substituição condicional de elementos
//     for (int i =0; i<3; i++){
//         for (int j=0; j<3; j++){
//             if (matriz [i][j]%3 == 0){
//                 matriz [i][j] = -1; // Substitui elementos divisíveis por 3 por -1
//             } else {
//                 matriz [i][j] = 0; // Substitui outros elementos por 0
//             }
//             printf("%d ", matriz[i][j]); // Imprime os elementos da matriz
//         }
//         printf("\n"); // Pula para a próxima linha após imprimir uma linha da matriz
//     }
//     return 0;
// }

// // Busca condicional em uma matriz

// #include <stdio.h>
// int main (){
//     int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     int target = 5; // Valor a ser buscado.
//     int found = 0; // Variável para indicar se o elemento foi encontrado.

//     // Busca condicional do elemento alvo.
//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 3; j++) {
//             if (matriz[i][j] == target) {
//                 found = 1; // Marca como encontrado.
//                 printf("Elemento %d encontrado na posição [%d][%d]\n", target, i, j);
//                 break; // Sai do loop interno se o elemento for encontrado
//             }
//         }
//         if (found == 1) { // verifica se o elemento foi encontrado (found = 1).
//             break; 
//         }
//     }
//     if (found != 1){ // Verifica se o elemento não foi encontrado.
//         printf("Elemento %d não encontrado na matriz.\n", target);
//     }

//         return 0;
// }

// Hora de codar
#include <stdio.h>

// constantes para o tamanho da matriz
#define LINHA 5
#define COLUNA 5

int main(){

    int matriz [LINHA][COLUNA]; // Declaração de uma matriz n tamanho das cosntantes.
    int target = 9; // Valor a ser buscado.
    int found = 0; // Variável para indicar se o elemento foi encontrado.
    int soma = 1; // Variável para preencher a matriz com valores de 1 a 25.
    // Estrutura aninhada para preencher a matriz com valores de 1 a 25.
    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            matriz [i][j] = soma;
            soma++; // Incrementa o valor a ser atribuído à matriz.
            printf("%d ", matriz[i][j]); // Imprime os elementos da matriz.
        }
        printf("\n"); // Pula para a próxima linha após imprimir uma linha da matriz.
    }

    // Busca condicional do elemento alvo.
    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            if (matriz[i][j] == target) {
                found = 1; // Marca como encontrado.
                printf("O valor %d encontrado no indice [%d][%d]\n", target, i, j);
                break; // Sai do loop interno se o elemento for encontrado
            }
        }
        if (found == 1) { // verifica se o elemento foi encontrado (found = 1).
            break; 
        }
    }
    if (found != 1){ // Verifica se o elemento não foi encontrado.
        printf("Elemento %d não encontrado na matriz.\n", target);
    }

    return 0;
}


