#include <stdio.h>

int main (){
    char estado0, estado1;
    char codigo0[5], codigo1[5];
    char cidade0[50], cidade1[50];
    int populacao0, populacao1;
    float area0, area1;
    float pib0, pib1;
    int turismo0, turismo1;

    //Carta 01.
    //Condição que permite apenas uso de letras entre A e H
    printf("Insira os dados da carta 01: \n");
    do {
        printf("Escolha uma letra (A ~ H) para representar o seu Estado: ");
        scanf(" %c", &estado0);
        if(estado0<'A' || estado0 > 'H'){
            printf("Entrada invalida! Por favor , insira uma letra entre A e H.\n");
        }
    } while (estado0 <'A' || estado0 > 'H');
    printf("Numero da Carta (Ex: 01):");
    scanf(" %s", codigo0);
    printf("Nome da cidade:");
    getchar();
    fgets(cidade0, sizeof(cidade0), stdin); //Preve bug com espaço por exemplo: "Rio de janeiro".
    // scanf(" %s", cidade0); REMOVIDO POR CONFLITO
    printf("Populacao: ");
    scanf(" %d", &populacao0);
    printf("Area (em KM quadrados):");
    scanf(" %f", &area0);
    printf("PIB:");
    scanf(" %f", &pib0);
    printf("Numero de Pontos Turisticos:");
    scanf(" %d", &turismo0);

    //Carta 02.
    //Condição que permite apenas uso de letras entre A e H
    printf("Insira os dados da carta 02: \n");
    do {
        printf("Escolha uma letra (A ~ H) para representar o seu Estado: ");
        scanf(" %c", &estado1);
        if(estado1<'A' || estado1 > 'H'){
            printf("Entrada invalida! Por favor , insira uma letra entre A e H.\n");
        }
    } while (estado1 <'A' || estado1 > 'H');
    printf("Numero da Carta (Ex: 01):");
    scanf(" %s", codigo1);
    printf("Nome da cidade:");
    getchar(); //limpa o buffer da nova linha
    fgets(cidade1, sizeof(cidade1), stdin); //Preve bug com espaço por exemplo: "Rio de janeiro".
    printf("Populacao: ");
    scanf(" %d", &populacao1);
    printf("Area (em KM quadrados):");
    scanf(" %f", &area1);
    printf("PIB:");
    scanf(" %f", &pib1);
    printf("Numero de Pontos Turisticos:");
    scanf(" %d", &turismo1);

    //Exibe Carta 01
    printf("\nDados da Carta 01: \n");
    printf("Estado: %c \n", estado0);
    printf("Codigo: %c%s\n", estado0, codigo0);
    printf("Cidade: %s", cidade0);
    printf("Populacao: %d\n", populacao0);
    printf("Area:  %.2f\n", area0);
    printf("PIB: %.2f\n", pib0);
    printf("Pontos Turisticos: %d\n", turismo0);
    if (area0 >0){
        float densidade0 = (float)populacao0/area0;
        printf("Densidade Populacional: %.2f\n", densidade0);
    }else{
        printf("A area deve ser maior que zero para calcular a densidade populacional.");
    }
    if (populacao0 >0){
        float pibCapita0 = (float)pib0/populacao0;
        printf("PIB per Capita: %.2f\n", pibCapita0);
    }else{
        printf("A populacao deve ser maior que zero para calcular o PIB per Capita.");
    }

    //Exibe Carta 02
    printf("\nDados da Carta 02: \n");
    printf("Estado: %c \n", estado1);
    printf("Codigo: %c%s\n", estado1, codigo1);
    printf("Cidade: %s", cidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area:  %.2f\n", area1);
    printf("PIB: %.2f\n", pib1);
    printf("Pontos Turisticos: %d\n", turismo1);
    if (area1 >0){
        float densidade1 = (float)populacao1/area1;
        printf("Densidade Populacional: %.2f\n", densidade1);
    }else{
        printf("A area deve ser maior que zero para calcular a densidade populacional.");
    }
    if (populacao1 >0){
        float pibCapita1 = (float)pib0/populacao1;
        printf("PIB per Capita: %.2f\n", pibCapita1);
    }else{
        printf("A populacao deve ser maior que zero para calcular o PIB per Capita.");
    }

    return 0;
}
