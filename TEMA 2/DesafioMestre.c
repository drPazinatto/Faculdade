#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Para exit()

// Definição da estrutura para representar uma carta de cidade
typedef struct {
    char estado[3];
    char codigo[4];
    char nomeCidade[40];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
    float pibPerCapita;
} CartaCidade;

// Função para ler os dados de uma carta de cidade
void lerCartaCidade(CartaCidade *carta, int numeroCarta) {
    printf("===============Cadastro da %dª Carta===============\n", numeroCarta);
    printf("Estado (ex: SP): ");
    scanf(" %2s", carta->estado);
    printf("Código da Carta (ex: SP01): ");
    scanf(" %3s", carta->codigo);
    printf("Nome da Cidade: ");
    scanf(" %39s", carta->nomeCidade);
    printf("População: ");
    scanf("%d", &carta->populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta->area);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
    printf("=======================================================\n");

    // Calcular Densidade Demográfica e PIB per capita ao ler os dados
    carta->densidadeDemografica = (carta->area > 0) ? (float)carta->populacao / carta->area : 0.0;
    carta->pibPerCapita = (carta->populacao > 0) ? carta->pib / carta->populacao : 0.0;
}

// Função para exibir o menu de atributos
void exibirMenuAtributos(int escolhido1) {
    printf("\nEscolha o atributo para comparação:\n");
    printf("%s1 - População\n", (escolhido1 == 1) ? "[ESCOLHIDO] " : "");
    printf("%s2 - Área\n", (escolhido1 == 2) ? "[ESCOLHIDO] " : "");
    printf("%s3 - PIB\n", (escolhido1 == 3) ? "[ESCOLHIDO] " : "");
    printf("%s4 - Pontos Turísticos\n", (escolhido1 == 4) ? "[ESCOLHIDO] " : "");
    printf("%s5 - Densidade Demográfica\n", (escolhido1 == 5) ? "[ESCOLHIDO] " : "");
    printf("0 - Sair\n");
    printf("Sua escolha: ");
}

int main() {
    CartaCidade carta1, carta2;
    int escolha1 = -1, escolha2 = -1;

    printf("Bem-vindo ao Super Trunfo de Cidades!\n");
    printf("=======================================================\n");

    // Leitura dos dados das duas cartas de cidades
    lerCartaCidade(&carta1, 1);
    lerCartaCidade(&carta2, 2);

    printf("\n===================== Escolha dos Atributos =====================\n");
    printf("Carta 1: %s (%s)\n", carta1.nomeCidade, carta1.estado);
    printf("Carta 2: %s (%s)\n", carta2.nomeCidade, carta2.estado);
    printf("===================================================================\n");

    // Escolha do primeiro atributo
    while (escolha1 < 1 || escolha1 > 5) {
        exibirMenuAtributos(-1);
        if (scanf("%d", &escolha1) != 1) {
            printf("Entrada inválida. Digite um número entre 0 e 5.\n");
            while (getchar() != '\n'); // Limpar o buffer de entrada
            continue;
        }
        if (escolha1 == 0) {
            printf("Saindo do jogo.\n");
            exit(0);
        }
        if (escolha1 < 1 || escolha1 > 5) {
            printf("Opção inválida. Escolha um atributo de 1 a 5.\n");
        }
    }

    // Escolha do segundo atributo
    while (escolha2 < 1 || escolha2 > 5 || escolha2 == escolha1) {
        exibirMenuAtributos(escolha1);
        if (scanf("%d", &escolha2) != 1) {
            printf("Entrada inválida. Digite um número entre 0 e 5.\n");
            while (getchar() != '\n'); // Limpar o buffer de entrada
            continue;
        }
        if (escolha2 == 0) {
            printf("Saindo do jogo.\n");
            exit(0);
        }
        if (escolha2 < 1 || escolha2 > 5) {
            printf("Opção inválida. Escolha um atributo de 1 a 5.\n");
        } else if (escolha2 == escolha1) {
            printf("Você já escolheu este atributo. Escolha outro.\n");
        }
    }

    printf("\n===================== Resultado da Comparação =====================\n");
    printf("Cidades: %s (%s) vs %s (%s)\n", carta1.nomeCidade, carta1.estado, carta2.nomeCidade, carta2.estado);
    printf("Atributos Escolhidos: ");

    float valor1_attr1 = 0, valor2_attr1 = 0;
    float valor1_attr2 = 0, valor2_attr2 = 0;
    char nome_attr1[30], nome_attr2[30];

    // Comparação do primeiro atributo
    switch (escolha1) {
        case 1: strcpy(nome_attr1, "População"); valor1_attr1 = carta1.populacao; valor2_attr1 = carta2.populacao; break;
        case 2: strcpy(nome_attr1, "Área"); valor1_attr1 = carta1.area; valor2_attr1 = carta2.area; break;
        case 3: strcpy(nome_attr1, "PIB"); valor1_attr1 = carta1.pib; valor2_attr1 = carta2.pib; break;
        case 4: strcpy(nome_attr1, "Pontos Turísticos"); valor1_attr1 = carta1.pontosTuristicos; valor2_attr1 = carta2.pontosTuristicos; break;
        case 5: strcpy(nome_attr1, "Densidade Demográfica"); valor1_attr1 = carta1.densidadeDemografica; valor2_attr1 = carta2.densidadeDemografica; break;
    }
    printf("%s, ", nome_attr1);
    printf("%s: %.2f vs %s: %.2f - ", carta1.nomeCidade, valor1_attr1, carta2.nomeCidade, valor2_attr1);
    int venceu1 = (escolha1 == 5) ? (valor1_attr1 < valor2_attr1) : (valor1_attr1 > valor2_attr1);
    printf("Resultado 1: %s venceu!\n", venceu1 ? carta1.nomeCidade : (valor1_attr1 == valor2_attr1 ? "Empate" : carta2.nomeCidade));

    // Comparação do segundo atributo
    switch (escolha2) {
        case 1: strcpy(nome_attr2, "População"); valor1_attr2 = carta1.populacao; valor2_attr2 = carta2.populacao; break;
        case 2: strcpy(nome_attr2, "Área"); valor1_attr2 = carta1.area; valor2_attr2 = carta2.area; break;
        case 3: strcpy(nome_attr2, "PIB"); valor1_attr2 = carta1.pib; valor2_attr2 = carta2.pib; break;
        case 4: strcpy(nome_attr2, "Pontos Turísticos"); valor1_attr2 = carta1.pontosTuristicos; valor2_attr2 = carta2.pontosTuristicos; break;
        case 5: strcpy(nome_attr2, "Densidade Demográfica"); valor1_attr2 = carta1.densidadeDemografica; valor2_attr2 = carta2.densidadeDemografica; break;
    }
    printf("%s\n", nome_attr2);
    printf("%s: %.2f vs %s: %.2f - ", carta1.nomeCidade, valor1_attr2, carta2.nomeCidade, valor2_attr2);
    int venceu2 = (escolha2 == 5) ? (valor1_attr2 < valor2_attr2) : (valor1_attr2 > valor2_attr2);
    printf("Resultado 2: %s venceu!\n", venceu2 ? carta1.nomeCidade : (valor1_attr2 == valor2_attr2 ? "Empate" : carta2.nomeCidade));

    // Soma dos atributos
    float soma1 = valor1_attr1 + valor1_attr2;
    float soma2 = valor2_attr1 + valor2_attr2;

    printf("\nSoma dos Atributos:\n");
    printf("%s: %.2f (%s: %.2f + %s: %.2f)\n", carta1.nomeCidade, soma1, nome_attr1, valor1_attr1, nome_attr2, valor1_attr2);
    printf("%s: %.2f (%s: %.2f + %s: %.2f)\n", carta2.nomeCidade, soma2, nome_attr1, valor2_attr1, nome_attr2, valor2_attr2);

    // Determinação do vencedor pela soma dos atributos (usando operador ternário)
    printf("\nResultado Final: %s %s!\n",
           carta1.nomeCidade,
           (soma1 > soma2) ? "venceu" : ((soma1 < soma2) ? "perdeu" : "empatou"));

    printf("===================================================================\n");

    return 0;
}