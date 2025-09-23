#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Aventureiro - Tabuleiro Completo e Navios Diagonais
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
// Função para validar se a posição do navio é válida (dentro dos limites e sem sobreposição)
int isPosicaoValida(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int tamanho, char orientacao) {
    for (int i = 0; i < tamanho; i++) {
        int l = linha;
        int c = coluna;

        if (orientacao == 'H') { // Horizontal
            c += i;
        } else if (orientacao == 'V') { // Vertical
            l += i;
        } else if (orientacao == 'D') { // Diagonal principal
            l += i;
            c += i;
        } else if (orientacao == 'S') { // Diagonal secundária
            l += i;
            c -= i;
        }

        // Verifica se está fora dos limites do tabuleiro
        if (l < 0 || l >= TAMANHO_TABULEIRO || c < 0 || c >= TAMANHO_TABULEIRO) {
            return 0; // Inválido: Fora dos limites
        }

        // Verifica se a posição já está ocupada por outro navio
        if (tabuleiro[l][c] != 0) {
            return 0; // Inválido: Sobreposição
        }
    }
    return 1; // Posição válida
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
     int navio1_linha = 1, navio1_coluna = 1;
    if (isPosicaoValida(tabuleiro, navio1_linha, navio1_coluna, TAMANHO_NAVIO, 'H')) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navio1_linha][navio1_coluna + i] = 3; // 3 representa um navio   
    }
    } else {
        printf("Erro: Posição do Navio 1 (Horizontal) é inválida!\n");
    }

    // --- Posicionando Navio 2 (Vertical) ---
    // Coordenadas iniciais (linha, coluna)
    int navio2_linha = 5;
    int navio2_coluna = 5;
    // Loop para preencher as 3 posições do navio na vertical
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio2_linha + i][navio2_coluna] = 3; // 3 representa um navio
        int navio2_linha = 3, navio2_coluna = 8;
    if (isPosicaoValida(tabuleiro, navio2_linha, navio2_coluna, TAMANHO_NAVIO, 'V')) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navio2_linha + i][navio2_coluna] = 3;
    }
    } else {
        printf("Erro: Posição do Navio 2 (Vertical) é inválida!\n");
    }

    // --- Posicionando Navio 3 (Diagonal Principal) ---
    int navio3_linha = 5, navio3_coluna = 1;
    if (isPosicaoValida(tabuleiro, navio3_linha, navio3_coluna, TAMANHO_NAVIO, 'D')) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navio3_linha + i][navio3_coluna + i] = 3;
        }
    } else {
        printf("Erro: Posição do Navio 3 (Diagonal) é inválida!\n");
    }

    // --- Posicionando Navio 4 (Diagonal Secundária) ---
    int navio4_linha = 0, navio4_coluna = 9;
    if (isPosicaoValida(tabuleiro, navio4_linha, navio4_coluna, TAMANHO_NAVIO, 'S')) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navio4_linha + i][navio4_coluna - i] = 3;
        }
    } else {
        printf("Erro: Posição do Navio 4 (Diagonal) é inválida!\n");
    }

    // 3. Exiba o Tabuleiro: Mostra a matriz no console.
    exibirTabuleiro(tabuleiro);
    }
 

    return 0;
    }
{

}
}



