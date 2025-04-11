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

// Função para posicionar um navio no tabuleiro
int posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicial, int colunaInicial, int horizontal) {
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
                printf("Erro: Sobreposição de navios detectada na horizontal.\n");
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
                printf("Erro: Sobreposição de navios detectada na vertical.\n");
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
    int linhaNavio1 = 2;
    int colunaNavio1 = 3;
    int horizontalNavio1 = 1; // 1 para horizontal

    // Tenta posicionar o primeiro navio
    printf("Tentando posicionar o primeiro navio (horizontal) em [%d][%d]...\n", linhaNavio1, colunaNavio1);
    if (posicionarNavio(tabuleiro, linhaNavio1, colunaNavio1, horizontalNavio1)) {
        printf("Primeiro navio posicionado com sucesso.\n");
    }

    // Define as coordenadas iniciais e a orientação do segundo navio (vertical)
    int linhaNavio2 = 6;
    int colunaNavio2 = 1;
    int horizontalNavio2 = 0; // 0 para vertical

    // Tenta posicionar o segundo navio
    printf("Tentando posicionar o segundo navio (vertical) em [%d][%d]...\n", linhaNavio2, colunaNavio2);
    if (posicionarNavio(tabuleiro, linhaNavio2, colunaNavio2, horizontalNavio2)) {
        printf("Segundo navio posicionado com sucesso.\n");
    }

    // Exibe o tabuleiro com os navios posicionados
    printf("\nEstado final do tabuleiro:\n");
    exibirTabuleiro(tabuleiro);

    return 0; // Indica que o programa terminou com sucesso
}