#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Para rand() e srand()
#include <time.h>   // Para time()

// Definição da estrutura para representar uma carta
typedef struct {
    char estado[3];
    char codigo[4];
    char nomeCidade[40];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

int main() {
    // Declaração das duas cartas
    Carta carta1, carta2;
    int atributoEscolhido;

    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(NULL));

    // Leitura dos dados da Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Estado (ex: SP): ");
    scanf(" %2s", carta1.estado);
    printf("Código da Carta (ex: SP01): ");
    scanf(" %3s", carta1.codigo);
    printf("Nome da Cidade: ");
    scanf(" %39s", carta1.nomeCidade);
    printf("População: ");
    scanf("%d", &carta1.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta1.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);
    printf("\n");

    // Cálculo da Densidade Populacional e PIB per capita para Carta 1
    carta1.densidadePopulacional = (float)carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;

    // Leitura dos dados da Carta 2
    printf("Cadastro da Carta 2:\n");
    printf("Estado (ex: RJ): ");
    scanf(" %2s", carta2.estado);
    printf("Código da Carta (ex: RJ02): ");
    scanf(" %3s", carta2.codigo);
    printf("Nome da Cidade: ");
    scanf(" %39s", carta2.nomeCidade);
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta2.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);
    printf("\n");

    // Cálculo da Densidade Populacional e PIB per capita para Carta 2
    carta2.densidadePopulacional = (float)carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    // Escolhe um atributo aleatoriamente (de 1 a 5)
    atributoEscolhido = (rand() % 5) + 1;

    printf("Comparação de cartas (Atributo: ");

    // Lógica de comparação baseada no atributo escolhido aleatoriamente
    if (atributoEscolhido == 1) { // Comparar por População
        printf("População):\n");
        printf("Carta 1 - %s (%s): %d\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
        printf("Carta 2 - %s (%s): %d\n", carta2.nomeCidade, carta2.estado, carta2.populacao);
        if (carta1.populacao > carta2.populacao) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.populacao > carta1.populacao) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else if (atributoEscolhido == 2) { // Comparar por Área
        printf("Área):\n");
        printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.estado, carta1.area);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.nomeCidade, carta2.estado, carta2.area);
        if (carta1.area > carta2.area) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.area > carta1.area) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else if (atributoEscolhido == 3) { // Comparar por PIB
        printf("PIB):\n");
        printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.estado, carta1.pib);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.nomeCidade, carta2.estado, carta2.pib);
        if (carta1.pib > carta2.pib) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.pib > carta1.pib) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else if (atributoEscolhido == 4) { // Comparar por Densidade Populacional
        printf("Densidade Populacional):\n");
        printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.estado, carta1.densidadePopulacional);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.nomeCidade, carta2.estado, carta2.densidadePopulacional);
        if (carta1.densidadePopulacional < carta2.densidadePopulacional) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.densidadePopulacional < carta1.densidadePopulacional) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else if (atributoEscolhido == 5) { // Comparar por PIB per capita
        printf("PIB per capita):\n");
        printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.estado, carta1.pibPerCapita);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.nomeCidade, carta2.estado, carta2.pibPerCapita);
        if (carta1.pibPerCapita > carta2.pibPerCapita) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    }

    return 0;
}