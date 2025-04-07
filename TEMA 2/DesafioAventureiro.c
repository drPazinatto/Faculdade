#include <stdio.h>
#include <string.h>

// Definição da estrutura para representar uma carta de país
typedef struct {
    char estado[3];
    char codigo[4];
    char nomePais[40];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
    float pibPerCapita;
} CartaPais;

// Função para ler os dados de uma carta de país
void lerCartaPais(CartaPais *carta, int numeroCarta) {
    printf("===============Cadastro da %dª Carta===============\n", numeroCarta);
    printf("Estado (ex: BR): ");
    scanf(" %2s", carta->estado);
    printf("Código da Carta (ex: BR01): ");
    scanf(" %3s", carta->codigo);
    printf("Nome do País: ");
    scanf(" %39s", carta->nomePais);
    printf("População: ");
    scanf("%d", &carta->populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta->area);
    printf("PIB (em bilhões de dólares): ");
    scanf("%f", &carta->pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
    printf("=======================================================\n");

    // Calcular Densidade Demográfica e PIB per capita ao ler os dados
    carta->densidadeDemografica = (carta->area > 0) ? (float)carta->populacao / carta->area : 0.0;
    carta->pibPerCapita = (carta->populacao > 0) ? carta->pib / carta->populacao : 0.0;
}

// Função para comparar as cartas com base no atributo escolhido
void compararCartas(CartaPais carta1, CartaPais carta2, int escolha) {
    printf("\nComparando por: ");
    switch (escolha) {
        case 1: // População
            printf("População\n");
            printf("Carta 1 - %s: %d\n", carta1.nomePais, carta1.populacao);
            printf("Carta 2 - %s: %d\n", carta2.nomePais, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomePais);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 2: // Área
            printf("Área\n");
            printf("Carta 1 - %s: %.2f km²\n", carta1.nomePais, carta1.area);
            printf("Carta 2 - %s: %.2f km²\n", carta2.nomePais, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomePais);
            } else if (carta2.area > carta1.area) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 3: // PIB
            printf("PIB\n");
            printf("Carta 1 - %s: %.2f bilhões\n", carta1.nomePais, carta1.pib);
            printf("Carta 2 - %s: %.2f bilhões\n", carta2.nomePais, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomePais);
            } else if (carta2.pib > carta1.pib) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 4: // Número de Pontos Turísticos
            printf("Número de Pontos Turísticos\n");
            printf("Carta 1 - %s: %d\n", carta1.nomePais, carta1.pontosTuristicos);
            printf("Carta 2 - %s: %d\n", carta2.nomePais, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomePais);
            } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 5: // Densidade Demográfica
            printf("Densidade Demográfica\n");
            printf("Carta 1 - %s: %.2f hab/km²\n", carta1.nomePais, carta1.densidadeDemografica);
            printf("Carta 2 - %s: %.2f hab/km²\n", carta2.nomePais, carta2.densidadeDemografica);
            if (carta1.densidadeDemografica < carta2.densidadeDemografica) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomePais);
            } else if (carta2.densidadeDemografica < carta1.densidadeDemografica) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        default:
            printf("Opção inválida!\n");
    }
    printf("=======================================================\n");
}

int main() {
    CartaPais carta1, carta2;
    int escolha;
    char continuar = 's';

    printf("Bem-vindo ao Super Trunfo de Países!\n");
    printf("=======================================================\n");

    // Leitura dos dados das duas cartas
    lerCartaPais(&carta1, 1);
    lerCartaPais(&carta2, 2);

    // Menu interativo para escolher o atributo de comparação
    while (continuar == 's' || continuar == 'S') {
        printf("\nEscolha o atributo para comparar as cartas:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Número de Pontos Turísticos\n");
        printf("5 - Densidade Demográfica\n");
        printf("0 - Sair\n");
        printf("Sua escolha: ");
        scanf("%d", &escolha);
        printf("=======================================================\n");

        switch (escolha) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                compararCartas(carta1, carta2, escolha);
                break;
            case 0:
                continuar = 'n';
                printf("Obrigado por jogar!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                printf("=======================================================\n");
        }
    }

    return 0;
}