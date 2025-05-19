#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[3], codigo[10], cidade[50];
    int populacao, turismo;
    float area, pib, densidade, pibCapita;
} Carta;
void calculaDensidade (Carta*c){
    if (c->area > 0){
        c->densidade = c->populacao/ c->area;
    } else {
        c-> densidade = 0;
    }
}
void calculaPibCapita(Carta *c){
    if (c->populacao>0){
        c->pibCapita = c->pib/ c->populacao;
    } else{
        c->pibCapita = 0;
    }
}



int main (){

    // Receber os dados de duas cartas: O programa deve receber os dados de duas cartas do Super Trunfo. Utilize o código desenvolvido no desafio anterior para o cadastro das cartas. As cartas devem conter os seguintes atributos
    Carta carta1 = {"SP", "A01", "Limeira", 270000, 9, 2.312, 16000000, 0, 0};
    Carta carta2 = {"RJ", "B01", "Pinheiral", 870000, 29, 4.312, 36000000, 0, 0};

    // Calcular Densidade Populacional e PIB per capita: O programa deve calcular e exibir
    calculaDensidade(&carta1);
    calculaPibCapita(&carta1);
    calculaDensidade(&carta2);
    calculaPibCapita(&carta2);
    printf("---------------------\n");
    printf("Carta 01\n");
    printf("Cidade: %s\n", carta1.cidade);
    printf("Densidade Populacional: %.2f habitantes/km²\n", carta1.densidade);
    printf("PIB per Capita: %.2f\n", carta1.pibCapita);
    printf("---------------------\n");
    printf("---------------------\n");
    printf("Carta 02\n");
    printf("Cidade: %s\n", carta2.cidade);
    printf("Densidade Populacional: %.2f habitantes/km²\n", carta2.densidade);
    printf("PIB per Capita: %.2f\n", carta2.pibCapita);
    printf("---------------------\n");

    /*
    Comparar um atributo escolhido: Você deverá escolher apenas um dos atributos numéricos (População, Área, PIB, Densidade 
    Populacional ou PIB per capita) para realizar a comparação entre as duas cartas. Essa escolha deve ser feita diretamente 
    no código, não pela entrada do usuário.

    Para todos os atributos, exceto Densidade Populacional, a carta com o maior valor vence.

    Para Densidade Populacional, a carta com o menor valor vence.

    Exibir o resultado da comparação: O programa deve exibir, de forma clara, qual carta venceu a comparação, incluindo o 
    atributo utilizado na comparação e os valores das duas cartas para aquele atributo. 
    */
    printf("---------------------\n");
    printf("Comparando densidade populacional (menor vence):\n");
    printf("---------------------\n");
    if (carta1.densidade < carta2.densidade) {
        printf("%s tem maior densidade populacional.\nA carta 1 vence!\n", carta1.cidade);
    } else if (carta1.densidade > carta2.densidade) {
        printf("%s tem maior densidade populacional.\nA carta 2 vence!\n", carta2.cidade);
    } else {
        printf("As cidades tem densidades populacionais iguais.\n");
    }
    printf("---------------------\n");
    return 0;
}
