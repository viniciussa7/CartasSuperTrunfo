#include <stdio.h>

typedef struct {
    char estado[3];
    int codigo;
    char nome[100];
    unsigned long int populacao;  // tipo alterado para unsigned long int
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

// Função para calcular a densidade populacional e o PIB per capita
void calcular_valores(Carta *carta) {
    // Calculando a densidade populacional
    carta->densidade_populacional = carta->populacao / carta->area;
    // Calculando o PIB per capita
    carta->pib_per_capita = carta->pib / carta->populacao;
    // Calculando o Super Poder
    carta->super_poder = carta->populacao + carta->area + carta->pib + carta->pontos_turisticos + (1 / carta->densidade_populacional);
}

// Função para comparar os atributos das cartas
void comparar_atributos(Carta *carta1, Carta *carta2) {
    // Comparando População
    printf("População: Carta 1 venceu (%d)\n", carta1->populacao > carta2->populacao);
    
    // Comparando Área
    printf("Área: Carta 1 venceu (%d)\n", carta1->area > carta2->area);
    
    // Comparando PIB
    printf("PIB: Carta 1 venceu (%d)\n", carta1->pib > carta2->pib);
    
    // Comparando Pontos Turísticos
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", carta1->pontos_turisticos > carta2->pontos_turisticos);
    
    // Comparando Densidade Populacional (Menor vence)
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", carta1->densidade_populacional < carta2->densidade_populacional);
    
    // Comparando PIB per Capita
    printf("PIB per Capita: Carta 1 venceu (%d)\n", carta1->pib_per_capita > carta2->pib_per_capita);
    
    // Comparando Super Poder
    printf("Super Poder: Carta 1 venceu (%d)\n", carta1->super_poder > carta2->super_poder);
}

int main() {
    Carta carta1, carta2;
    
    // Leitura dos dados da Carta 1
    printf("Digite os dados para a Carta 1:\n");
    printf("Estado (2 caracteres): ");
    scanf("%s", carta1.estado);
    printf("Código: ");
    scanf("%d", &carta1.codigo);
    printf("Nome: ");
    getchar(); // Para consumir o '\n' deixado pelo scanf anterior
    fgets(carta1.nome, sizeof(carta1.nome), stdin);
    
    printf("População: ");
    scanf("%lu", &carta1.populacao);  // Usando %lu para ler unsigned long int
    printf("Área: ");
    scanf("%f", &carta1.area);
    printf("PIB: ");
    scanf("%f", &carta1.pib);
    printf("Pontos Turísticos: ");
    scanf("%d", &carta1.pontos_turisticos);
    
    // Leitura dos dados da Carta 2
    printf("\nDigite os dados para a Carta 2:\n");
    printf("Estado (2 caracteres): ");
    scanf("%s", carta2.estado);
    printf("Código: ");
    scanf("%d", &carta2.codigo);
    printf("Nome: ");
    getchar(); // Para consumir o '\n' deixado pelo scanf anterior
    fgets(carta2.nome, sizeof(carta2.nome), stdin);
    
    printf("População: ");
    scanf("%lu", &carta2.populacao);  // Usando %lu para ler unsigned long int
    printf("Área: ");
    scanf("%f", &carta2.area);
    printf("PIB: ");
    scanf("%f", &carta2.pib);
    printf("Pontos Turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);
    
    // Calculando os valores necessários para cada carta
    calcular_valores(&carta1);
    calcular_valores(&carta2);
    
    // Comparando as cartas
    printf("\nComparação de Cartas:\n");
    comparar_atributos(&carta1, &carta2);

    return 0;
}
