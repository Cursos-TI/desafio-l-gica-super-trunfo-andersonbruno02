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

// Função para comparar dois atributos
void compararDoisAtributos(Cidade cidade1, Cidade cidade2, int atributo1, int atributo2) {
    int resultado1, resultado2;

    // Comparação do primeiro atributo
    switch (atributo1) {
        case 1: // População
            resultado1 = (cidade1.populacao > cidade2.populacao) ? 1 : 0;
            break;
        case 2: // Área
            resultado1 = (cidade1.area > cidade2.area) ? 1 : 0;
            break;
        case 3: // PIB
            resultado1 = (cidade1.pib > cidade2.pib) ? 1 : 0;
            break;
        case 4: // Pontos Turísticos
            resultado1 = (cidade1.pontos_turisticos > cidade2.pontos_turisticos) ? 1 : 0;
            break;
        case 5: // Densidade Populacional
            resultado1 = (cidade1.densidade_populacional < cidade2.densidade_populacional) ? 1 : 0;
            break;
        case 6: // PIB per Capita
            resultado1 = (cidade1.pib_per_capita > cidade2.pib_per_capita) ? 1 : 0;
            break;
        default:
            printf("Atributo 1 inválido.\n");
            return;
    }

    // Comparação do segundo atributo
    switch (atributo2) {
        case 1: // População
            resultado2 = (cidade1.populacao > cidade2.populacao) ? 1 : 0;
            break;
        case 2: // Área
            resultado2 = (cidade1.area > cidade2.area) ? 1 : 0;
            break;
        case 3: // PIB
            resultado2 = (cidade1.pib > cidade2.pib) ? 1 : 0;
            break;
        case 4: // Pontos Turísticos
            resultado2 = (cidade1.pontos_turisticos > cidade2.pontos_turisticos) ? 1 : 0;
            break;
        case 5: // Densidade Populacional
            resultado2 = (cidade1.densidade_populacional < cidade2.densidade_populacional) ? 1 : 0;
            break;
        case 6: // PIB per Capita
            resultado2 = (cidade1.pib_per_capita > cidade2.pib_per_capita) ? 1 : 0;
            break;
        default:
            printf("Atributo 2 inválido.\n");
            return;
    }

    // Determinar o vencedor
    if (resultado1 && resultado2) {
        printf("Cidade 1 vence em ambos os atributos.\n");
    } else if (!resultado1 && !resultado2) {
        printf("Cidade 2 vence em ambos os atributos.\n");
    } else {
        printf("Empate: Cada cidade vence em um atributo.\n");
    }
}

int main() {
    Cidade cidade1, cidade2;
    int atributo1, atributo2;

    // Ler os dados das duas cidades
    lerDadosCidade(&cidade1, 1);
    lerDadosCidade(&cidade2, 2);

    // Menu interativo
    printf("\nEscolha dois atributos para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per Capita\n");
    printf("Digite o número do primeiro atributo: ");
    scanf("%d", &atributo1);
    printf("Digite o número do segundo atributo: ");
    scanf("%d", &atributo2);

    // Comparar as cartas com base nos atributos escolhidos
    compararDoisAtributos(cidade1, cidade2, atributo1, atributo2);

    return 0;
}