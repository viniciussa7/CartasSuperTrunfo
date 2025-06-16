#include <stdio.h>

// Definindo uma estrutura para representar as cartas do Super Trunfo
typedef struct {
    char estado[3];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional; // População / Área
    float pib_per_capita; // PIB / População
} Carta;

// Função para calcular a densidade populacional e o PIB per capita
void calcularDensidadePopulacional(Carta* carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

// Função para comparar as cartas com base em um atributo específico
void compararCartas(Carta carta1, Carta carta2) {
    // Escolher o atributo para comparação
    // Neste caso, estamos comparando o atributo "População"
    printf("Comparação de cartas (Atributo: População):\n\n");

    printf("Carta 1 - %s (%s): %d\n", carta1.nome, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d\n", carta2.nome, carta2.estado, carta2.populacao);

    // Comparando as cartas com base no atributo População
    if (carta1.populacao > carta2.populacao) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nome);
    } else if (carta1.populacao < carta2.populacao) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nome);
    } else {
        printf("\nResultado: Empate!\n");
    }
}

int main() {
    // Criando as duas cartas do Super Trunfo
    Carta carta1 = {
        "SP", 
        "C1", 
        "São Paulo", 
        12300000, // População
        1500.0,   // Área
        4500000000.0, // PIB
        500,      // Pontos turísticos
        0.0,      // Densidade populacional (a ser calculada)
        0.0       // PIB per capita (a ser calculado)
    };

    Carta carta2 = {
        "RJ", 
        "C2", 
        "Rio de Janeiro", 
        6000000,  // População
        1200.0,   // Área
        2500000000.0, // PIB
        300,      // Pontos turísticos
        0.0,      // Densidade populacional (a ser calculada)
        0.0       // PIB per capita (a ser calculado)
    };

    // Calculando a densidade populacional e o PIB per capita para ambas as cartas
    calcularDensidadePopulacional(&carta1);
    calcularDensidadePopulacional(&carta2);

    // Chamando a função para comparar as cartas com base na População
    compararCartas(carta1, carta2);

    return 0;
}
