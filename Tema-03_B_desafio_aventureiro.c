/*
Simplificações para o nível básico
    Não é necessário validar a entrada do usuário.
    Não é necessário implementar a lógica completa do jogo de xadrez, apenas a simulação do movimento de cada peça individualmente.
    Utilize apenas as estruturas de repetição for, while e do-while, uma para cada peça do jogo.
*/

// Movimento Torre com While
#include <stdio.h>
int main(){
    int i = 0;
    printf("A torre irá se mover 3 casas para frente.\n");
    while (i<3){
        printf("Cima\n");
        i++;
    }
    return 0;
}

// Do While - Movimento Bispo
#include <stdio.h>
int main(){
    int i =0;
    printf("O bispo irá se mover 5 casas para cima e para esquerda.\n");
    do{
        printf("Cima esquerda\n");
        i++;
    } while (i <=4);
    return 0;
}

// For - Movimento Rainha
#include <stdio.h>
int main (){
    printf("A rainha irá se mover 7 casas para a direita.\n");
    for (int i=0;i<=6;i++){
        printf("Direita\n");
    } 
    return 0;
}

// Movimento Cavalo
#include <stdio.h>
int main(){
    int i,j;
    printf("O cavalo irá se mover 2 casas para baixo e 1 para direita.\n");

    for(i=1;i<=1;i++){
        for(j=1;j<=i;j++){
            printf("Baixo, Baixo, Direita.\n");
        }
    }
    return 0;
}
// Desafio - Movimento Cavalo 2
#include <stdio.h>
int main(){
    int i,j;
    char i;
    printf("Escolha a direção que o cavalo deve se mover: \n");
    scanf("%c", &i);
    for(i=1;i<=1;i++){
        for(j=1;j<=2;j++){
            printf("Baixo\n");
        }
        printf("Direita\n");
    }
    return 0;
}