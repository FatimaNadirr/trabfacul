#include <stdio.h>
#include <string.h>

#define MAX_ATRIBUTOS 6

typedef struct {
    char estado[30];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePop;
    float pibPerCapita;
} Carta;

void calcularDados(Carta* c) {
    c->densidadePop = (c->area > 0) ? c->populacao / c->area : 0;
    c->pibPerCapita = (c->populacao > 0) ? c->pib / c->populacao : 0;
}

void cadastrarCarta(Carta* c) {
    printf("Estado: ");
    scanf(" %[^\n]", c->estado);
    printf("Codigo da carta: ");
    scanf(" %[^\n]", c->codigo);
    printf("Cidade: ");
    scanf(" %[^\n]", c->cidade);
    printf("Populacao: ");
    scanf("%d", &c->populacao);
    printf("Area (km2): ");
    scanf("%f", &c->area);
    printf("PIB (em bilhões): ");
    scanf("%f", &c->pib);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &c->pontosTuristicos);

    calcularDados(c);
}

const char* nomeAtributo(int opcao) {
    switch (opcao) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "PIB";
        case 4: return "Pontos Turisticos";
        case 5: return "Densidade Populacional";
        case 6: return "PIB per Capita";
        default: return "Desconhecido";
    }
}

float pegarValorAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontosTuristicos;
        case 5: return c.densidadePop;
        case 6: return c.pibPerCapita;
        default: return 0;
    }
}

int escolherAtributo(int opcoesUsadas[]) {
    int opcao;
    printf("\nEscolha um atributo para comparar:\n");
    if (!opcoesUsadas[0]) printf("1. Populacao\n");
    if (!opcoesUsadas[1]) printf("2. Area\n");
    if (!opcoesUsadas[2]) printf("3. PIB\n");
    if (!opcoesUsadas[3]) printf("4. Pontos Turisticos\n");
    if (!opcoesUsadas[4]) printf("5. Densidade Populacional (menor vence)\n");
    if (!opcoesUsadas[5]) printf("6. PIB per Capita\n");

    printf("Digite a opcao: ");
    scanf("%d", &opcao);

    if (opcao >= 1 && opcao <= 6 && !opcoesUsadas[opcao - 1]) {
        opcoesUsadas[opcao - 1] = 1;
        return opcao;
    } else {
        printf("Opcao invalida ou ja usada. Tente novamente.\n");
        return escolherAtributo(opcoesUsadas);
    }
}

int main() {
    Carta carta1, carta2;
    int opcoesUsadas[MAX_ATRIBUTOS] = {0};
    int atributo1, atributo2;
    float valor1_a, valor1_b, valor2_a, valor2_b;
    float somaA, somaB;

    printf("Cadastro da Carta 1:\n");
    cadastrarCarta(&carta1);

    printf("\nCadastro da Carta 2:\n");
    cadastrarCarta(&carta2);

    printf("\n=== Escolha dos Atributos ===\n");
    atributo1 = escolherAtributo(opcoesUsadas);
    atributo2 = escolherAtributo(opcoesUsadas);

    valor1_a = pegarValorAtributo(carta1, atributo1);
    valor1_b = pegarValorAtributo(carta2, atributo1);
    valor2_a = pegarValorAtributo(carta1, atributo2);
    valor2_b = pegarValorAtributo(carta2, atributo2);

    printf("\n=== Comparacao de Cartas ===\n");

    printf("Atributo 1: %s\n", nomeAtributo(atributo1));
    printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, valor1_a);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, valor1_b);
    printf("\nAtributo 2: %s\n", nomeAtributo(atributo2));
    printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, valor2_a);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, valor2_b);

    float pontoA1 = (atributo1 == 5) ? -valor1_a : valor1_a;
    float pontoB1 = (atributo1 == 5) ? -valor1_b : valor1_b;
    float pontoA2 = (atributo2 == 5) ? -valor2_a : valor2_a;
    float pontoB2 = (atributo2 == 5) ? -valor2_b : valor2_b;

    somaA = pontoA1 + pontoA2;
    somaB = pontoB1 + pontoB2;

    printf("\nSoma dos valores dos atributos:\n");
    printf("Carta 1 - %s: %.2f + %.2f = %.2f\n", carta1.cidade, valor1_a, valor2_a, valor1_a + valor2_a);
    printf("Carta 2 - %s: %.2f + %.2f = %.2f\n", carta2.cidade, valor1_b, valor2_b, valor1_b + valor2_b);

    printf("\n=== Resultado Final ===\n");
    if (somaA > somaB) {
        printf("VENCEDORA: Carta 1 - %s (%s)\n", carta1.cidade, carta1.estado);
    } else if (somaB > somaA) {
        printf("VENCEDORA: Carta 2 - %s (%s)\n", carta2.cidade, carta2.estado);
    } else {
        printf("EMPATE!\n");
    }

    return 0;
}
