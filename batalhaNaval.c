#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }
}

// Função para posicionar navio horizontal
void posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verificar se o navio cabe no tabuleiro horizontalmente
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal não cabe no tabuleiro!\n");
        return;
    }

    // Posicionar navio horizontal
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }
}

// Função para posicionar navio vertical
void posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verificar se o navio cabe no tabuleiro verticalmente
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical não cabe no tabuleiro!\n");
        return;
    }

    // Posicionar navio vertical
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro de Batalha Naval:\n");
    
    // Imprimir cabeçalho de colunas
    printf("  ");
    for (int c = 0; c < TAMANHO_TABULEIRO; c++) {
        printf("%d ", c);
    }
    printf("\n");

    // Imprimir tabuleiro
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        // Imprimir número da linha
        printf("%d ", linha);

        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }
}

int main() {
    // Declarar tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializar tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Posicionar navio horizontal na linha 2, começando na coluna 3
    posicionarNavioHorizontal(tabuleiro, 2, 3);

    // Posicionar navio vertical na coluna 7, começando na linha 5
    posicionarNavioVertical(tabuleiro, 5, 7);

    // Exibir tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}