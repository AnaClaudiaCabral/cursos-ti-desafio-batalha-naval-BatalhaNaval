#include <stdio.h>
#include <stdlib.h> // Para a função abs()

// --- Requisitos não funcionais: Legibilidade e Manutenção ---
// Define constantes para o tamanho do tabuleiro e dos navios.
// Isso torna o código mais legível e fácil de modificar no futuro.
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define HABILIDADE_TAMANHO 5 // Tamanho da matriz de habilidade (5x5)

// Enum para representar o estado de cada célula do tabuleiro.
// Melhora a legibilidade em comparação com números mágicos (0, 3, 5).
typedef enum {
    AGUA,           // Valor 0
    NAVIO,          // Valor 1 (substituindo o 3 para simplificar)
    AREA_HABILIDADE // Valor 2 (substituindo o 5)
} EstadoCelula;

void inicializarTabuleiro(EstadoCelula tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// --- Funções para criar as matrizes de habilidade (0 para não afetado, 1 para afetado) ---
void criarCone(int habilidade[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO]) {
    int centro_col = HABILIDADE_TAMANHO / 2;
    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            // O cone tem origem no topo (i=0) e se expande para baixo.
            // A condição limita a altura do cone a 3 linhas para um efeito visível.
            if (i < 3 && abs(j - centro_col) <= i) {
                habilidade[i][j] = 1; // Área afetada
            } else {
                habilidade[i][j] = 0; // Área não afetada
            }
        }
    }
}

void criarCruz(int habilidade[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO]) {
    int centro = HABILIDADE_TAMANHO / 2;
    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            // A cruz é formada pela linha central e a coluna central.
            if (i == centro || j == centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

void criarOctaedro(int habilidade[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO]) {
    int centro = HABILIDADE_TAMANHO / 2;
    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            // A forma de losango (vista de um octaedro) é criada com a distância de Manhattan.
            if (abs(i - centro) + abs(j - centro) <= centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para aplicar a matriz de habilidade ao tabuleiro principal
void aplicarHabilidade(EstadoCelula tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                       int habilidade[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO],
                       int origem_linha, int origem_coluna) {
    int offset_centro = HABILIDADE_TAMANHO / 2;

    for (int i_hab = 0; i_hab < HABILIDADE_TAMANHO; i_hab++) {
        for (int j_hab = 0; j_hab < HABILIDADE_TAMANHO; j_hab++) {
            // Se a posição na matriz de habilidade é 1 (afetada)
            if (habilidade[i_hab][j_hab] == 1) {
                // Calcula a posição correspondente no tabuleiro principal
                int i_tab = origem_linha - offset_centro + i_hab;
                int j_tab = origem_coluna - offset_centro + j_hab;

                // Verifica se a posição está dentro dos limites do tabuleiro
                if (i_tab >= 0 && i_tab < TAMANHO_TABULEIRO && j_tab >= 0 && j_tab < TAMANHO_TABULEIRO) {
                    // Marca a posição do tabuleiro como afetada pela habilidade
                    tabuleiro[i_tab][j_tab] = AREA_HABILIDADE;
                }
            }
        }
    }
}

void exibirTabuleiro(EstadoCelula tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("### Tabuleiro de Batalha Naval ###\n");
    printf("Legenda: ~ = Agua, N = Navio, X = Habilidade\n\n");
    printf("  "); // Espaço para o cabeçalho das colunas
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j); // Imprime o índice da coluna
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); // Imprime o índice da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            switch (tabuleiro[i][j]) {
                case AGUA:           printf("~ "); break;
                case NAVIO:          printf("N "); break;
                case AREA_HABILIDADE:printf("X "); break;
            }
        }
        printf("\n"); // Pula para a próxima linha
    }
}

int main(){
    // 1. Represente o Tabuleiro: Matriz 10x10
    EstadoCelula tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    inicializarTabuleiro(tabuleiro);

    // 2. Posicione os Navios
    // --- Posicionando Navio 1 (Horizontal) ---
    int navio1_linha = 2;
    int navio1_coluna = 2;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int col = navio1_coluna + i;
        if (col < TAMANHO_TABULEIRO && tabuleiro[navio1_linha][col] == AGUA) {
            tabuleiro[navio1_linha][col] = NAVIO;
        } else {
            printf("Erro ao posicionar o Navio 1 (Horizontal)!\n");
            printf("Verifique os limites do tabuleiro ou sobreposição de navios.\n");
            break; // Interrompe o posicionamento deste navio
        }
    }

    // --- Posicionando Navio 2 (Vertical) ---
    int navio2_linha = 5;
    int navio2_coluna = 5;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int lin = navio2_linha + i;
        if (lin < TAMANHO_TABULEIRO && tabuleiro[lin][navio2_coluna] == AGUA) {
            tabuleiro[lin][navio2_coluna] = NAVIO;
        } else {
            printf("Erro ao posicionar o Navio 2 (Vertical)!\n");
            printf("Verifique os limites do tabuleiro ou sobreposição de navios.\n");
            break;
        }
    }
    
    // --- Criando e Integrando Habilidades ---
    int cone[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO];
    int cruz[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO];
    int octaedro[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO];

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Define pontos de origem e aplica as habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 1, 8);      // Origem do cone em (1, 8)
    aplicarHabilidade(tabuleiro, cruz, 7, 1);      // Origem da cruz em (7, 1)
    aplicarHabilidade(tabuleiro, octaedro, 4, 4);  // Origem do octaedro em (4, 4)

    // 3. Exiba o Tabuleiro
    exibirTabuleiro(tabuleiro);
    
    return 0;
}