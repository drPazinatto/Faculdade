#include <stdio.h>

// --- Movimento da Torre (Recursivo) ---
void moverTorreRecursivo(int casas) {
    if (casas > 0) {
        printf("Direita\n");
        moverTorreRecursivo(casas - 1);
    }
}

// --- Movimento do Bispo (Recursivo e com Loops Aninhados) ---
void moverBispoRecursivo(int casas) {
    moverBispoRecursivoVertical(casas, 0);
}

void moverBispoRecursivoVertical(int casas_vertical, int casas_horizontal) {
    if (casas_vertical > 0) {
        for (int i = 0; i < casas_horizontal + 1; i++) {
            printf("Cima, Direita\n");
        }
        moverBispoRecursivoVertical(casas_vertical - 1, casas_horizontal + 1);
    }
}

// --- Movimento da Rainha (Recursivo) ---
void moverRainhaRecursivo(int casas) {
    if (casas > 0) {
        printf("Esquerda\n");
        moverRainhaRecursivo(casas - 1);
    }
}

int main() {
    // --- Movimento da Torre ---
    printf("Movimento da Torre (Recursivo):\n");
    int torre_casas = 5;
    moverTorreRecursivo(torre_casas);
    printf("\n");

    // --- Movimento do Bispo ---
    printf("Movimento do Bispo (Recursivo e com Loops Aninhados):\n");
    int bispo_casas = 5;
    moverBispoRecursivo(bispo_casas);
    printf("\n");

    // --- Movimento da Rainha ---
    printf("Movimento da Rainha (Recursivo):\n");
    int rainha_casas = 8;
    moverRainhaRecursivo(rainha_casas);
    printf("\n");

    // --- Movimento do Cavalo (Loops Aninhados Complexos) ---
    printf("Movimento do Cavalo (Loops Aninhados Complexos):\n");
    int movimento_cima = 2;
    int movimento_direita = 1;

    // Loop externo para controlar a sequência principal do movimento em "L"
    for (int l_movimento = 0; l_movimento < 1; l_movimento++) {
        // Loop interno para o movimento vertical (duas casas para cima)
        for (int cima = 1; cima <= movimento_cima; cima++) {
            printf("Cima\n");
            // Condição para inserir um 'continue' após o primeiro movimento para cima
            if (cima == 1) {
                continue; // Simula uma pausa ou etapa intermediária no movimento
            }
        }

        // Loop interno para o movimento horizontal (uma casa para a direita)
        int direita = 1;
        while (direita <= movimento_direita) {
            printf("Direita\n");
            direita++;
            // Condição para um 'break' após o movimento para a direita
            if (direita > movimento_direita) {
                break; // Finaliza o movimento em "L"
            }
        }
    }
    printf("\n");

    return 0;
}