#include <stdio.h>

// Definições de constantes para o tabuleiro e navios
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Loop para percorrer cada linha do tabuleiro
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        // Loop para percorrer cada coluna da linha atual
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            // Define o valor da célula como AGUA (0)
            tabuleiro[linha][coluna] = AGUA;
        }
    }
}

// Função para verificar se uma determinada posição (linha, coluna) está dentro dos limites do tabuleiro
int posicaoValida(int linha, int coluna) {
    // Retorna 1 (verdadeiro) se a linha e a coluna estiverem dentro dos limites (0 a TAMANHO_TABULEIRO - 1)
    return (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO);
}

// Função para posicionar um navio no tabuleiro (horizontal ou vertical)
int posicionarNavioHV(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicial, int colunaInicial, int horizontal) {
    // Verifica se o navio será posicionado horizontalmente
    if (horizontal) {
        // Verifica se o navio cabe horizontalmente dentro do tabuleiro
        if (colunaInicial + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            printf("Erro: Navio horizontal ultrapassa a borda do tabuleiro.\n");
            return 0; // Retorna 0 indicando falha no posicionamento
        }
        // Loop para verificar se há sobreposição com outros navios na posição desejada
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaInicial][colunaInicial + i] == NAVIO) {
                printf("Erro: Sobreposição de navios detectada na horizontal em [%d][%d].\n", linhaInicial, colunaInicial + i);
                return 0; // Retorna 0 indicando falha no posicionamento
            }
        }
        // Posiciona o navio horizontalmente marcando as células com NAVIO (3)
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaInicial][colunaInicial + i] = NAVIO;
        }
    } else { // Se o navio for posicionado verticalmente
        // Verifica se o navio cabe verticalmente dentro do tabuleiro
        if (linhaInicial + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            printf("Erro: Navio vertical ultrapassa a borda do tabuleiro.\n");
            return 0; // Retorna 0 indicando falha no posicionamento
        }
        // Loop para verificar se há sobreposição com outros navios na posição desejada
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaInicial + i][colunaInicial] == NAVIO) {
                printf("Erro: Sobreposição de navios detectada na vertical em [%d][%d].\n", linhaInicial + i, colunaInicial);
                return 0; // Retorna 0 indicando falha no posicionamento
            }
        }
        // Posiciona o navio verticalmente marcando as células com NAVIO (3)
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaInicial + i][colunaInicial] = NAVIO;
        }
    }
    return 1; // Retorna 1 indicando sucesso no posicionamento
}

// Função para posicionar um navio na diagonal
int posicionarNavioDiagonal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicial, int colunaInicial, int direcao) {
    // direcao: 1 para diagonal principal (aumentando linha e coluna), -1 para diagonal secundária (aumentando linha, diminuindo coluna)
    if (direcao == 1) {
        // Verifica se o navio cabe na diagonal principal
        if (linhaInicial + TAMANHO_NAVIO > TAMANHO_TABULEIRO || colunaInicial + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            printf("Erro: Navio diagonal principal ultrapassa a borda do tabuleiro.\n");
            return 0;
        }
        // Verifica sobreposição
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaInicial + i][colunaInicial + i] == NAVIO) {
                printf("Erro: Sobreposição de navios detectada na diagonal principal em [%d][%d].\n", linhaInicial + i, colunaInicial + i);
                return 0;
            }
        }
        // Posiciona o navio na diagonal principal
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaInicial + i][colunaInicial + i] = NAVIO;
        }
    } else if (direcao == -1) {
        // Verifica se o navio cabe na diagonal secundária
        if (linhaInicial + TAMANHO_NAVIO > TAMANHO_TABULEIRO || colunaInicial - (TAMANHO_NAVIO - 1) < 0) {
            printf("Erro: Navio diagonal secundária ultrapassa a borda do tabuleiro.\n");
            return 0;
        }
        // Verifica sobreposição
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaInicial + i][colunaInicial - i] == NAVIO) {
                printf("Erro: Sobreposição de navios detectada na diagonal secundária em [%d][%d].\n", linhaInicial + i, colunaInicial - i);
                return 0;
            }
        }
        // Posiciona o navio na diagonal secundária
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaInicial + i][colunaInicial - i] = NAVIO;
        }
    } else {
        printf("Erro: Direção diagonal inválida.\n");
        return 0;
    }
    return 1;
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Imprime os números das colunas para referência
    printf("  ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n");

    // Loop para percorrer cada linha do tabuleiro
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        // Imprime o número da linha para referência
        printf("%d ", linha);
        // Loop para percorrer cada coluna da linha atual
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            // Imprime o valor da célula (0 para água, 3 para navio) seguido de um espaço
            printf("%d ", tabuleiro[linha][coluna]);
        }
        // Inicia uma nova linha na saída para a próxima linha do tabuleiro
        printf("\n");
    }
    printf("\n"); // Adiciona uma linha em branco no final para melhor visualização
}

int main() {
    // Declara a matriz que representa o tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa todas as posições do tabuleiro com água (0)
    inicializarTabuleiro(tabuleiro);
    printf("Tabuleiro inicializado com água.\n");

    // Define as coordenadas iniciais e a orientação do primeiro navio (horizontal)
    int linhaNavio1 = 1;
    int colunaNavio1 = 2;
    int horizontalNavio1 = 1; // 1 para horizontal

    // Tenta posicionar o primeiro navio
    printf("Tentando posicionar o primeiro navio (horizontal) em [%d][%d]...\n", linhaNavio1, colunaNavio1);
    if (posicionarNavioHV(tabuleiro, linhaNavio1, colunaNavio1, horizontalNavio1)) {
        printf("Primeiro navio posicionado com sucesso.\n");
    }

    // Define as coordenadas iniciais e a orientação do segundo navio (vertical)
    int linhaNavio2 = 5;
    int colunaNavio2 = 7;
    int horizontalNavio2 = 0; // 0 para vertical

    // Tenta posicionar o segundo navio
    printf("Tentando posicionar o segundo navio (vertical) em [%d][%d]...\n", linhaNavio2, colunaNavio2);
    if (posicionarNavioHV(tabuleiro, linhaNavio2, colunaNavio2, horizontalNavio2)) {
        printf("Segundo navio posicionado com sucesso.\n");
    }

    // Define as coordenadas iniciais e a direção do terceiro navio (diagonal principal)
    int linhaNavio3 = 0;
    int colunaNavio3 = 0;
    int direcaoNavio3 = 1; // 1 para diagonal principal

    // Tenta posicionar o terceiro navio (diagonal principal)
    printf("Tentando posicionar o terceiro navio (diagonal principal) começando em [%d][%d]...\n", linhaNavio3, colunaNavio3);
    if (posicionarNavioDiagonal(tabuleiro, linhaNavio3, colunaNavio3, direcaoNavio3)) {
        printf("Terceiro navio (diagonal principal) posicionado com sucesso.\n");
    }

    // Define as coordenadas iniciais e a direção do quarto navio (diagonal secundária)
    int linhaNavio4 = 0;
    int colunaNavio4 = 9;
    int direcaoNavio4 = -1; // -1 para diagonal secundária

    // Tenta posicionar o quarto navio (diagonal secundária)
    printf("Tentando posicionar o quarto navio (diagonal secundária) começando em [%d][%d]...\n", linhaNavio4, colunaNavio4);
    if (posicionarNavioDiagonal(tabuleiro, linhaNavio4, colunaNavio4, direcaoNavio4)) {
        printf("Quarto navio (diagonal secundária) posicionado com sucesso.\n");
    }

    // Exibe o tabuleiro com os navios posicionados
    printf("\nEstado final do tabuleiro:\n");
    exibirTabuleiro(tabuleiro);

    return 0; // Indica que o programa terminou com sucesso
}