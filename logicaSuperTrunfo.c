#include <stdio.h>
#include <string.h>

int main() {
    Cidade cidade1, cidade2;

    // Ler os dados das duas cidades
    lerDadosCidade(&cidade1, 1);
    lerDadosCidade(&cidade2, 2);

    // Comparar as cartas
    compararCartas(cidade1, cidade2);
    
    // Cadastro das Cartas:
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // utilizando a função scanf para capturar as entradas.
    // utilize o código do primeiro desafio

    // Exemplo:
    // printf("Digite o código da cidade: ");
    // scanf("%s", codigo);
    // 
    // (Repita para cada propriedade)

    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

    // Exemplo:
    // if (populacaoA > populacaoB) {
    //     printf("Cidade 1 tem maior população.\n");
    // } else {
    //     printf("Cidade 2 tem maior população.\n");
    // }

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);

    return 0;
}

// Estrutura para representar uma carta de cidade
typedef struct {
    char estado;
    char codigo[4];
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Cidade;

// Função para ler os dados de uma cidade
void lerDadosCidade(Cidade *cidade, int numeroCarta) {
    printf("\nDigite os dados da Cidade %d:\n", numeroCarta);

    // Solicita o estado da cidade
    printf("Digite o estado da cidade (uma letra): ");
    scanf(" %c", &cidade->estado);

    // Solicita o código da cidade
    printf("Digite o código da cidade (ex: A01): ");
    scanf("%s", cidade->codigo);

    // Solicita o nome da cidade
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", cidade->nome);

    // Solicita a população da cidade
    printf("Digite a população da cidade: ");
    scanf("%lu", &cidade->populacao);

    // Solicita a área da cidade
    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &cidade->area);

    // Solicita o PIB da cidade
    printf("Digite o PIB da cidade (em milhões): ");
    scanf("%f", &cidade->pib);

    // Solicita o número de pontos turísticos
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &cidade->pontos_turisticos);

    // Calcula a densidade populacional
    cidade->densidade_populacional = (float) cidade->populacao / cidade->area;

    // Calcula o PIB per capita
    cidade->pib_per_capita = (cidade->pib * 1000000) / cidade->populacao;

    // Calcula o super poder (soma de todas as propriedades)
    cidade->super_poder = cidade->populacao + cidade->area + cidade->pib + cidade->pib_per_capita + (1 / cidade->densidade_populacional) + cidade->pontos_turisticos;
}

// Função para comparar duas cartas
void compararCartas(Cidade cidade1, Cidade cidade2) {
    printf("\nComparando as cartas:\n");

    // Comparação de população
    printf("População: Cidade 1 (%lu) vs Cidade 2 (%lu) -> %d\n", cidade1.populacao, cidade2.populacao, cidade1.populacao > cidade2.populacao);

    // Comparação de área
    printf("Área: Cidade 1 (%.2f) vs Cidade 2 (%.2f) -> %d\n", cidade1.area, cidade2.area, cidade1.area > cidade2.area);

    // Comparação de PIB
    printf("PIB: Cidade 1 (%.2f) vs Cidade 2 (%.2f) -> %d\n", cidade1.pib, cidade2.pib, cidade1.pib > cidade2.pib);

    // Comparação de pontos turísticos
    printf("Pontos Turísticos: Cidade 1 (%d) vs Cidade 2 (%d) -> %d\n", cidade1.pontos_turisticos, cidade2.pontos_turisticos, cidade1.pontos_turisticos > cidade2.pontos_turisticos);

    // Comparação de densidade populacional (menor valor vence)
    printf("Densidade Populacional: Cidade 1 (%.2f) vs Cidade 2 (%.2f) -> %d\n", cidade1.densidade_populacional, cidade2.densidade_populacional, cidade1.densidade_populacional < cidade2.densidade_populacional);

    // Comparação de PIB per capita
    printf("PIB per capita: Cidade 1 (%.2f) vs Cidade 2 (%.2f) -> %d\n", cidade1.pib_per_capita, cidade2.pib_per_capita, cidade1.pib_per_capita > cidade2.pib_per_capita);

    // Comparação de super poder
    printf("Super Poder: Cidade 1 (%.2f) vs Cidade 2 (%.2f) -> %d\n", cidade1.super_poder, cidade2.super_poder, cidade1.super_poder > cidade2.super_poder);
}