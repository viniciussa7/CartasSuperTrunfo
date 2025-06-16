#include <stdio.h>

#define N 10  // Tamanho do tabuleiro

// Funções para gerar as matrizes de habilidades
void gerarCone(int tabuleiro[N][N], int x, int y);
void gerarCruz(int tabuleiro[N][N], int x, int y);
void gerarOctaedro(int tabuleiro[N][N], int x, int y);

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[N][N]);

int main() {
    // Inicializando o tabuleiro com água (0)
    int tabuleiro[N][N] = {0};
    
    // Posição do navio (exemplo)
    tabuleiro[4][5] = 3;  // Colocando um navio no centro
    
    // Definindo habilidades no tabuleiro
    gerarCone(tabuleiro, 4, 5);
    gerarCruz(tabuleiro, 4, 5);
    gerarOctaedro(tabuleiro, 4, 5);
    
    // Exibir o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}

void gerarCone(int tabuleiro[N][N], int x, int y) {
    // Definindo uma área de efeito em forma de cone (matriz 5x5)
    int cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };
    
    // Sobrepondo a matriz de cone no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cone[i][j] == 1) {
                // Garantir que a posição não ultrapasse os limites do tabuleiro
                if (x + i >= 0 && x + i < N && y + j >= 0 && y + j < N) {
                    tabuleiro[x + i][y + j] = 5;  // Marcar área afetada
                }
            }
        }
    }
}

void gerarCruz(int tabuleiro[N][N], int x, int y) {
    // Definindo uma área de efeito em forma de cruz (matriz 5x5)
    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };
    
    // Sobrepondo a matriz de cruz no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cruz[i][j] == 1) {
                // Garantir que a posição não ultrapasse os limites do tabuleiro
                if (x + i >= 0 && x + i < N && y + j >= 0 && y + j < N) {
                    tabuleiro[x + i][y + j] = 5;  // Marcar área afetada
                }
            }
        }
    }
}

void gerarOctaedro(int tabuleiro[N][N], int x, int y) {
    // Definindo uma área de efeito em forma de octaedro (matriz 5x5)
    int octaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };
    
    // Sobrepondo a matriz de octaedro no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (octaedro[i][j] == 1) {
                // Garantir que a posição não ultrapasse os limites do tabuleiro
                if (x + i >= 0 && x + i < N && y + j >= 0 && y + j < N) {
                    tabuleiro[x + i][y + j] = 5;  // Marcar área afetada
                }
            }
        }
    }
}

void exibirTabuleiro(int tabuleiro[N][N]) {
    // Exibir o tabuleiro
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("0 ");  // Água
            } else if (tabuleiro[i][j] == 3) {
                printf("3 ");  // Navio
            } else if (tabuleiro[i][j] == 5) {
                printf("5 ");  // Área afetada pela habilidade
            }
        }
        printf("\n");
    }
}
