#include <stdio.h>
#include <string.h>

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
}

// Função para comparar duas cartas com base em um atributo escolhido
void compararCartas(Cidade cidade1, Cidade cidade2, int atributo) {
    switch (atributo) {
        case 1: // População
            if (cidade1.populacao > cidade2.populacao) {
                printf("Cidade 1 tem maior população.\n");
            } else {
                printf("Cidade 2 tem maior população.\n");
            }
            break;
        case 2: // Área
            if (cidade1.area > cidade2.area) {
                printf("Cidade 1 tem maior área.\n");
            } else {
                printf("Cidade 2 tem maior área.\n");
            }
            break;
        case 3: // PIB
            if (cidade1.pib > cidade2.pib) {
                printf("Cidade 1 tem maior PIB.\n");
            } else {
                printf("Cidade 2 tem maior PIB.\n");
            }
            break;
        case 4: // Pontos Turísticos
            if (cidade1.pontos_turisticos > cidade2.pontos_turisticos) {
                printf("Cidade 1 tem mais pontos turísticos.\n");
            } else {
                printf("Cidade 2 tem mais pontos turísticos.\n");
            }
            break;
        case 5: // Densidade Populacional
            if (cidade1.densidade_populacional < cidade2.densidade_populacional) {
                printf("Cidade 1 tem menor densidade populacional.\n");
            } else {
                printf("Cidade 2 tem menor densidade populacional.\n");
            }
            break;
        case 6: // PIB per Capita
            if (cidade1.pib_per_capita > cidade2.pib_per_capita) {
                printf("Cidade 1 tem maior PIB per capita.\n");
            } else {
                printf("Cidade 2 tem maior PIB per capita.\n");
            }
            break;
        default:
            printf("Atributo inválido.\n");
    }
}

int main() {
    Cidade cidade1, cidade2;
    int atributo;

    // Ler os dados das duas cidades
    lerDadosCidade(&cidade1, 1);
    lerDadosCidade(&cidade2, 2);

    // Menu interativo
    printf("\nEscolha o atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per Capita\n");
    printf("Digite o número do atributo: ");
    scanf("%d", &atributo);

    // Comparar as cartas com base no atributo escolhido
    compararCartas(cidade1, cidade2, atributo);

    return 0;
}