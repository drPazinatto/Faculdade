#include <stdio.h>

// Definições de constantes para o tabuleiro e elementos
#define TAMANHO_TABULEIRO 10
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Definição do tamanho das matrizes de habilidade
#define TAMANHO_HABILIDADE 5

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = AGUA;
        }
    }
}

// Função para posicionar um navio no tabuleiro (horizontalmente para simplificar)
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicial, int colunaInicial) {
    if (colunaInicial + 3 <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linhaInicial][colunaInicial + i] = NAVIO;
        }
    }
}

// Função para criar a matriz de habilidade em forma de Cone
void criarHabilidadeCone(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;
    for (int linha = 0; linha < TAMANHO_HABILIDADE; linha++) {
        for (int coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {
            // A área afetada se expande para baixo a partir do topo (linha 0)
            if (linha >= 0 && linha <= centro && coluna >= centro - linha && coluna <= centro + linha) {
                habilidade[linha][coluna] = 1;
            } else {
                habilidade[linha][coluna] = 0;
            }
        }
    }
}

// Função para criar a matriz de habilidade em forma de Cruz
void criarHabilidadeCruz(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;
    for (int linha = 0; linha < TAMANHO_HABILIDADE; linha++) {
        for (int coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {
            // A área afetada forma uma cruz centrada
            if (linha == centro || coluna == centro) {
                habilidade[linha][coluna] = 1;
            } else {
                habilidade[linha][coluna] = 0;
            }
        }
    }
}

// Função para criar a matriz de habilidade em forma de Octaedro (Losango)
void criarHabilidadeOctaedro(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;
    for (int linha = 0; linha < TAMANHO_HABILIDADE; linha++) {
        for (int coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {
            // A área afetada forma um losango centrado
            if (abs(linha - centro) + abs(coluna - centro) <= centro) {
                habilidade[linha][coluna] = 1;
            } else {
                habilidade[linha][coluna] = 0;
            }
        }
    }
}

// Função para aplicar a habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int linhaOrigem, int colunaOrigem) {
    int centroHabilidade = TAMANHO_HABILIDADE / 2;
    for (int linhaHabilidade = 0; linhaHabilidade < TAMANHO_HABILIDADE; linhaHabilidade++) {
        for (int colunaHabilidade = 0; colunaHabilidade < TAMANHO_HABILIDADE; colunaHabilidade++) {
            // Calcula as coordenadas correspondentes no tabuleiro
            int linhaTabuleiro = linhaOrigem - centroHabilidade + linhaHabilidade;
            int colunaTabuleiro = colunaOrigem - centroHabilidade + colunaHabilidade;

            // Verifica se as coordenadas do tabuleiro estão dentro dos limites
            if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO_TABULEIRO && colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO_TABULEIRO) {
                // Se a posição na matriz de habilidade for 1, marca a posição no tabuleiro
                if (habilidade[linhaHabilidade][colunaHabilidade] == 1) {
                    // Evita sobrescrever navios, marca apenas a água
                    if (tabuleiro[linhaTabuleiro][colunaTabuleiro] == AGUA) {
                        tabuleiro[linhaTabuleiro][colunaTabuleiro] = HABILIDADE;
                    }
                }
            }
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("  ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\nLegenda: 0 = Água, 3 = Navio, 5 = Área de Habilidade\n");
}

int main() {
    // Define o tabuleiro 10x10
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Posiciona alguns navios no tabuleiro
    posicionarNavio(tabuleiro, 2, 3);
    posicionarNavio(tabuleiro, 7, 1);

    // Cria as matrizes de habilidade
    int habilidadeCone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidadeCruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidadeOctaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    criarHabilidadeCone(habilidadeCone);
    criarHabilidadeCruz(habilidadeCruz);
    criarHabilidadeOctaedro(habilidadeOctaedro);

    // Define os pontos de origem das habilidades no tabuleiro
    int linhaOrigemCone = 1;
    int colunaOrigemCone = 2;
    int linhaOrigemCruz = 5;
    int colunaOrigemCruz = 5;
    int linhaOrigemOctaedro = 8;
    int colunaOrigemOctaedro = 7;

    printf("Tabuleiro antes das habilidades:\n");
    exibirTabuleiro(tabuleiro);

    // Aplica a habilidade Cone ao tabuleiro
    printf("Aplicando habilidade Cone na posição [%d][%d]:\n", linhaOrigemCone, colunaOrigemCone);
    aplicarHabilidade(tabuleiro, habilidadeCone, linhaOrigemCone, colunaOrigemCone);
    exibirTabuleiro(tabuleiro);

    // Aplica a habilidade Cruz ao tabuleiro
    printf("Aplicando habilidade Cruz na posição [%d][%d]:\n", linhaOrigemCruz, colunaOrigemCruz);
    aplicarHabilidade(tabuleiro, habilidadeCruz, linhaOrigemCruz, colunaOrigemCruz);
    exibirTabuleiro(tabuleiro);

    // Aplica a habilidade Octaedro ao tabuleiro
    printf("Aplicando habilidade Octaedro na posição [%d][%d]:\n", linhaOrigemOctaedro, colunaOrigemOctaedro);
    aplicarHabilidade(tabuleiro, habilidadeOctaedro, linhaOrigemOctaedro, colunaOrigemOctaedro);
    exibirTabuleiro(tabuleiro);

    return 0;
}