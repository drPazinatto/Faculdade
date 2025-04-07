#include <stdio.h>

int main() {
    // Movimento da Torre (5 casas para a direita)
    printf("Movimento da Torre:\n");
    for (int i = 0; i < 5; i++) {
        printf("Direita\n");
    }
    printf("\n");

    // Movimento do Bispo (5 casas na diagonal para cima e à direita)
    printf("Movimento do Bispo:\n");
    int j = 0;
    while (j < 5) {
        printf("Cima, Direita\n");
        j++;
    }
    printf("\n");

    // Movimento da Rainha (8 casas para a esquerda)
    printf("Movimento da Rainha:\n");
    int k = 0;
    do {
        printf("Esquerda\n");
        k++;
    } while (k < 8);
    printf("\n");

    // Movimento do Cavalo (duas casas para baixo e uma para a esquerda)
    printf("Movimento do Cavalo:\n");
    int movimento_baixo = 2;
    int movimento_esquerda = 1;

    // Primeiro movimento: duas casas para baixo (usando loop for)
    for (int baixo = 0; baixo < movimento_baixo; baixo++) {
        printf("Baixo\n");
    }

    // Segundo movimento: uma casa para a esquerda (usando loop while)
    int esquerda = 0;
    while (esquerda < movimento_esquerda) {
        printf("Esquerda\n");
        esquerda++;
    }
    printf("\n");

    return 0;
}