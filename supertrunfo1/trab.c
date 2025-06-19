#include <stdio.h>
#include <string.h>

#define MAX_CARTAS 10

typedef struct {
    char estado[30];
    int codigo;
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;

    float densidade;
    float pibPerCapita;
    float superPoder;
} Carta;

float calcularDensidade(int pop, float area) {
    if (area <= 0) return 1;
    return pop / area;
}

float calcularPibPerCapita(float pib, int pop) {
    if (pop <= 0) return 0;
    return pib / pop;
}

float calcularSuperPoder(Carta c) {
    float densidade = c.densidade > 0 ? c.densidade : 1;
    return c.populacao + c.area + c.pib + c.pontosTuristicos + c.pibPerCapita + (1.0 / densidade);
}

void cadastrarCarta(Carta* c) {
    printf("\n--- Cadastro de Carta ---\n");
    printf("Estado: ");
    scanf(" %[^\n]", c->estado);

    printf("Codigo da carta: ");
    scanf("%d", &c->codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", c->nome);

    printf("Populacao: ");
    scanf("%d", &c->populacao);

    printf("Area (km2): ");
    scanf("%f", &c->area);

    printf("PIB (em bilhoes): ");
    scanf("%f", &c->pib);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &c->pontosTuristicos);

    c->densidade = calcularDensidade(c->populacao, c->area);
    c->pibPerCapita = calcularPibPerCapita(c->pib, c->populacao);
    c->superPoder = calcularSuperPoder(*c);
}

void exibirCarta(Carta c) {
    printf("\n--- Carta [%d] - %s (%s) ---\n", c.codigo, c.nome, c.estado);
    printf("Populacao: %d\n", c.populacao);
    printf("Area: %.2f km2\n", c.area);
    printf("PIB: %.2f bi\n", c.pib);
    printf("Pontos Turisticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km2\n", c.densidade);
    printf("PIB per Capita: %.2f\n", c.pibPerCapita);
    printf("Super Poder: %.2f\n", c.superPoder);
}

void compararCartas(Carta a, Carta b) {
    printf("\n==== COMPARACAO ENTRE CARTAS ====\n");

    int pontosA = 0, pontosB = 0;

    if (a.populacao > b.populacao) { printf("Populacao: %s VENCE\n", a.nome); pontosA++; }
    else if (a.populacao < b.populacao) { printf("Populacao: %s VENCE\n", b.nome); pontosB++; }
    else printf("Populacao: EMPATE\n");

    if (a.area > b.area) { printf("Area: %s VENCE\n", a.nome); pontosA++; }
    else if (a.area < b.area) { printf("Area: %s VENCE\n", b.nome); pontosB++; }
    else printf("Area: EMPATE\n");

    if (a.pib > b.pib) { printf("PIB: %s VENCE\n", a.nome); pontosA++; }
    else if (a.pib < b.pib) { printf("PIB: %s VENCE\n", b.nome); pontosB++; }
    else printf("PIB: EMPATE\n");

    if (a.pontosTuristicos > b.pontosTuristicos) { printf("Turismo: %s VENCE\n", a.nome); pontosA++; }
    else if (a.pontosTuristicos < b.pontosTuristicos) { printf("Turismo: %s VENCE\n", b.nome); pontosB++; }
    else printf("Turismo: EMPATE\n");

    if (a.densidade < b.densidade) { printf("Densidade (menos é melhor): %s VENCE\n", a.nome); pontosA++; }
    else if (a.densidade > b.densidade) { printf("Densidade (menos é melhor): %s VENCE\n", b.nome); pontosB++; }
    else printf("Densidade: EMPATE\n");

    if (a.pibPerCapita > b.pibPerCapita) { printf("PIB per Capita: %s VENCE\n", a.nome); pontosA++; }
    else if (a.pibPerCapita < b.pibPerCapita) { printf("PIB per Capita: %s VENCE\n", b.nome); pontosB++; }
    else printf("PIB per Capita: EMPATE\n");

    if (a.superPoder > b.superPoder) { printf("SUPER PODER: %s VENCE\n", a.nome); pontosA += 2; }
    else if (a.superPoder < b.superPoder) { printf("SUPER PODER: %s VENCE\n", b.nome); pontosB += 2; }
    else printf("SUPER PODER: EMPATE\n");

    printf("\n--- Resultado Final ---\n");
    if (pontosA > pontosB) printf("%s é a CIDADE VENCEDORA!\n", a.nome);
    else if (pontosB > pontosA) printf("%s é a CIDADE VENCEDORA!\n", b.nome);
    else printf("EMPATE TOTAL!\n");
}

int main() {
    Carta cartas[2];

    for (int i = 0; i < 2; i++) {
        printf("\n=== Cadastro da Carta %d ===", i + 1);
        cadastrarCarta(&cartas[i]);
    }

    for (int i = 0; i < 2; i++) {
        exibirCarta(cartas[i]);
    }

    compararCartas(cartas[0], cartas[1]);

    return 0;
}
