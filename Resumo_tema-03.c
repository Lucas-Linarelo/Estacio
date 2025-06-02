// While - Executa repetidade, depende de uma condição verdadeira e termina quando a condição se torna falsa.
#include <stdio.h>
int main() {
    int i = 0;                  //Variável de incremento
    while (i < 10) {            //Condição: Enquanto i for menor que 10, o loop continua  
        printf("%d\n", i);      //Saída: imprime o valor de i
        i++;                    //Incremento: i é incrementado em 1 a cada iteração
    }
    return 0;                   //Retorno: indica que o programa terminou com sucesso
}
//Código prático
#include <stdio.h>
int main() {
    int i = 0;
    while (i<=10){
        if(i%2==0){
            printf("O número %d é par\n", i);
        }
        i++;
    }
    return 0;
}

// Do While - Executa pelo menos uma vez, depois verifica a condição. Se a condição for verdadeira, o loop continua.
#include <stdio.h>
int main() {
    int i = 0;                  //Variável de incremento
    do {
        printf("%d\n", i);      //Saída: imprime o valor de i
        i++;                    //Incremento: i é incrementado em 1 a cada iteração
    } while (i <= 10);          //Condição: Enquanto i for menor que 10, o loop continua
    return 0;                   //Retorno: indica que o programa terminou com sucesso
}
// Código prático
#include <stdio.h>
int main () {
    int numero;
    do{
        printf("Digite um número par para sair do programa: ");
        scanf("%d", &numero);
        if(numero % 2==0){
            printf("O número %d é par\n", numero);
        }else{
            printf("O número %d é ímpar\n", numero);
        }
    }while (numero % 2 != 0);
    // Se o número for par, o loop termina
    printf("Você digitou um número par, o programa foi encerrado.\n");
    return 0;
}

// For - Executa um número específico de vezes(tamanhos especificos), com inicialização, condição e incremento em uma única linha.
#include <stdio.h>
int main() {
    for (int i = 0; i <= 10; i++) {     //Inicialização: i começa em 0, Condição: enquanto i for menor ou igual à 10, Incremento: i é incrementado em 1 a cada iteração
        printf("%d\n", i);              //Saída: imprime o valor de i
    }
    return 0;                           //Retorno: indica que o programa terminou com sucesso
}
// Código prático
#include <stdio.h>
int main(){
    int numero, i;
    printf("Digite um número para calcular a tabuada: ");
    scanf("%d", &numero);
    for(i = 0; i<=10; i++){
        printf("%d x %d = %d\n", numero, i , numero*i);
    }
    return 0;
}

//Loops aninhados - Estrutura de controle de fluxo em programação onde um loop está situado dentro de outro loop, permitindo iterações múltiplas e hierárquicas, frequentemente usadas para processar dados em estruturas como matrizes ou tabelas.
#include <stdio.h>
int main() {
    for (int i = 0; i < 3; i++) {               //Loop externo: itera de 0 a 2
        for (int j = 0; j < 2; j++) {           //Loop interno: itera de 0 a 1
            printf("i: %d, j: %d\n", i, j);     //Saída: imprime os valores de i e j
        }
    }
    return 0;                                   //Retorno: indica que o programa terminou com sucesso
}
// Código prático - Tabuadas
#include <stdio.h>
int main(){
    int i = 1;
    while (i<=10){
        int j = 1;
        while (j<=10){
            printf("%d\t", i *j);
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}

//
#include <stdio.h>
int main(){
    int i,j;
    char letra;
    for(i=1;i<=26;i++){
        letra = 'A';
        for(j=1;j<=i;j++){          // Loop interno (J) com tamanho máximo igual ao valor de i
            printf("%c ", letra);   //
            letra++;                // Incrementa a letra para a próxima
        }
        printf("\n");
    }
    return 0;
}

// Loops avançados - Estruturas de controle de fluxo em programação que permitem a execução repetida de um bloco de código, com variações e condições mais complexas, como loops aninhados, loops infinitos e loops com controle de fluxo avançado (break, continue).
#include <stdio.h>
int main() {
    // && ou || - Operadores que combinam condições lógicas
    // i e j - iniciadores de loop, iniciadas ao mesmo tempo
    // ++ ou -- - Incremento ou decremento de variáveis
for (int i = 0, j =10; i<5 && j>5; i++, j--){
    printf("i = %d, j = %d\n", i, j);
}
return 0;
}

// Atualizações complexas
#include <stdio.h>
int main() {
    // Exemplo de uso do operador ternário para incrementar
    for (int i = 0; i < 100; i += (i % 2 == 0) ? 1 : 2) {
        printf("%d\n", i);
    }
    return 0;
}

// Recursividade - Onde uma função chama a si mesma para resolver um problema, dividindo-o em subproblemas menores, frequentemente usada em algoritmos de busca, ordenação e estruturas de dados como árvores e listas encadeadas.
#include <stdio.h>

// Função recursiva imprime números de N até 1
void recursiveLoop(int n){
    if (n > 0) {
        printf("%d ", n); //Imprime o valor atual de n
        recursiveLoop (n - 1); //Chama a si mesma com n-1
    }
}

// Loop de contagem regressiva usando recursão

#include <stdio.h>

void recursivo(int numero){
    if(numero > 0){
        printf("%d \n", numero);
        recursivo(numero - 1); // Chama a função recursivamente com o número decrementado
    }
}

int main(){
    
    int quantidade = 10;

    printf("Contagem regressiva:\n");
    recursivo(quantidade); // Inicia a contagem regressiva a partir de 10
    
    return 0;
}
