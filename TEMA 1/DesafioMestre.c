#include <stdio.h>

int main() {
    // Variáveis para armazenar os dados da Carta 1
    char estado1;
    char codigo1[4];
    char cidade1[40];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidade1;
    float capita1;
    float superPoder1;

    // Variáveis para armazenar os dados da Carta 2
    char estado2;
    char codigo2[4];
    char cidade2[40];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidade2;
    float capita2;
    float superPoder2;

    // Leitura dos dados da Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Código da Carta (ex: A01): ");
    scanf(" %3s", codigo1);
    printf("Nome da Cidade: ");
    scanf(" %39s", cidade1);
    printf("População: ");
    scanf("%lu", &populacao1); // Use %lu para unsigned long int
    printf("Área (em km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);
    printf("\n");

    // Cálculo da Densidade Populacional e PIB per Capita da Carta 1
    densidade1 = (float)populacao1 / area1;
    capita1 = pib1 / populacao1;

    // Cálculo do Super Poder da Carta 1
    superPoder1 = (float)populacao1 + area1 + pib1 + pontosTuristicos1 + capita1 + (densidade1 > 0 ? (1 / densidade1) : 0);

    // Leitura dos dados da Carta 2
    printf("Cadastro da Carta 2:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Código da Carta (ex: B02): ");
    scanf(" %3s", codigo2);
    printf("Nome da Cidade: ");
    scanf(" %39s", cidade2);
    printf("População: ");
    scanf("%lu", &populacao2); // Use %lu para unsigned long int
    printf("Área (em km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);
    printf("\n");

    // Cálculo da Densidade Populacional e PIB per Capita da Carta 2
    densidade2 = (float)populacao2 / area2;
    capita2 = pib2 / populacao2;

    // Cálculo do Super Poder da Carta 2
    superPoder2 = (float)populacao2 + area2 + pib2 + pontosTuristicos2 + capita2 + (densidade2 > 0 ? (1 / densidade2) : 0);

    // Exibição dos dados da Carta 1
    printf("Carta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", capita1);
    printf("Super Poder: %.2f\n", superPoder1);
    printf("\n");

    // Exibição dos dados da Carta 2
    printf("Carta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", capita2);
    printf("Super Poder: %.2f\n", superPoder2);
    printf("\n");

    // Comparação das Cartas
    printf("Comparação de Cartas:\n");

    printf("População: Carta %d venceu (%d)\n", (populacao1 > populacao2 ? 1 : 2), (populacao1 > populacao2));
    printf("Área: Carta %d venceu (%d)\n", (area1 > area2 ? 1 : 2), (area1 > area2));
    printf("PIB: Carta %d venceu (%d)\n", (pib1 > pib2 ? 1 : 2), (pib1 > pib2));
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", (pontosTuristicos1 > pontosTuristicos2 ? 1 : 2), (pontosTuristicos1 > pontosTuristicos2));
    printf("Densidade Populacional: Carta %d venceu (%d)\n", (densidade1 < densidade2 ? 1 : 2), (densidade1 < densidade2));
    printf("PIB per Capita: Carta %d venceu (%d)\n", (capita1 > capita2 ? 1 : 2), (capita1 > capita2));
    printf("Super Poder: Carta %d venceu (%d)\n", (superPoder1 > superPoder2 ? 1 : 2), (superPoder1 > superPoder2));

    return 0;
}