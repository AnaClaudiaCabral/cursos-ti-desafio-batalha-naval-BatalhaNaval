#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Novato - Posicionamento dos Navios
//Ana Claudia Cabral

// Define constantes para o tamanho do tabuleiro e dos navios.
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Loop para percorrer cada linha
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        // Loop para percorrer cada coluna da linha atual
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("### Tabuleiro de Batalha Naval ###\n");
    // Adiciona cabeçalho de colunas para melhor visualização
    printf("  0 1 2 3 4 5 6 7 8 9\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); // Adiciona cabeçalho de linhas
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); // Pula para a próxima linha ao final de cada linha do tabuleiro
    }
}

int main() {
    // Tabuleiro: Matriz 10x10
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com 0 (água)
    inicializarTabuleiro(tabuleiro);

    // Posicionamento dos Navios: Coordenadas definidas diretamente no código.
    // --- Posicionando Navio 1 (Horizontal) ---
    // Coordenadas iniciais (linha, coluna)
    int navio1_linha = 2;
    int navio1_coluna = 2;
    // Loop para preencher as 3 posições do navio na horizontal
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio1_linha][navio1_coluna + i] = 3; // 3 representa um navio
    }

    // --- Posicionando Navio 2 (Vertical) ---
    // Coordenadas iniciais (linha, coluna)
    int navio2_linha = 5;
    int navio2_coluna = 5;
    // Loop para preencher as 3 posições do navio na vertical
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio2_linha + i][navio2_coluna] = 3; // 3 representa um navio
    }

    // 3. Exiba o Tabuleiro: Mostra a matriz no console.
    exibirTabuleiro(tabuleiro);

    printf("novo commit\n");

    return 0;
}



