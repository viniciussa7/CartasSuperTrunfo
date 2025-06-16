#include <stdio.h>

// Função recursiva para mover a Torre
void movimentoTorre(int casas, char direcao) {
    if (casas <= 0) {
        return;
    }

    if (direcao == 'C') {
        printf("Cima\n");
    } else if (direcao == 'B') {
        printf("Baixo\n");
    } else if (direcao == 'E') {
        printf("Esquerda\n");
    } else if (direcao == 'D') {
        printf("Direita\n");
    }

    movimentoTorre(casas - 1, direcao);
}

// Função recursiva para o movimento do Bispo, com loops aninhados
void movimentoBispo(int casas, int vertical, int horizontal) {
    if (casas <= 0) {
        return;
    }

    // Loop externo controla o movimento vertical
    for (int i = 0; i < vertical; i++) {
        // Loop interno controla o movimento horizontal
        for (int j = 0; j < horizontal; j++) {
            if (i == j) {
                printf("Diagonal\n");
            }
        }
    }

    movimentoBispo(casas - 1, vertical, horizontal);
}

// Função recursiva para o movimento da Rainha
void movimentoRainha(int casas, char direcao) {
    if (casas <= 0) {
        return;
    }

    if (direcao == 'C') {
        printf("Cima\n");
    } else if (direcao == 'B') {
        printf("Baixo\n");
    } else if (direcao == 'E') {
        printf("Esquerda\n");
    } else if (direcao == 'D') {
        printf("Direita\n");
    }

    movimentoRainha(casas - 1, direcao);
}

// Função para o movimento do Cavalo com loops complexos
void movimentoCavalo() {
    for (int i = 0; i < 2; i++) {  // Loop externo controla o movimento "duas casas para cima"
        for (int j = 0; j < 1; j++) {  // Loop interno controla o movimento "uma casa para a direita"
            if (i == 1 && j == 0) {
                printf("Cima\n");
                printf("Direita\n");
            }
        }
    }
}

int main() {
    int casasTorre = 5;
    int casasBispo = 3;
    int casasRainha = 4;
    
    // Exemplo de movimento da Torre (Cima, Baixo, Esquerda, Direita)
    printf("Movimento da Torre:\n");
    movimentoTorre(casasTorre, 'C');
    printf("\n");

    movimentoTorre(casasTorre, 'B');
    printf("\n");

    movimentoTorre(casasTorre, 'E');
    printf("\n");

    movimentoTorre(casasTorre, 'D');
    printf("\n");

    // Exemplo de movimento do Bispo
    printf("Movimento do Bispo:\n");
    movimentoBispo(casasBispo, 2, 2); // 2 movimentos verticais e horizontais
    printf("\n");

    // Exemplo de movimento da Rainha
    printf("Movimento da Rainha:\n");
    movimentoRainha(casasRainha, 'C');
    printf("\n");

    movimentoRainha(casasRainha, 'B');
    printf("\n");

    movimentoRainha(casasRainha, 'E');
    printf("\n");

    movimentoRainha(casasRainha, 'D');
    printf("\n");

    // Exemplo de movimento do Cavalo
    printf("Movimento do Cavalo:\n");
    movimentoCavalo();
    printf("\n");

    return 0;
}
