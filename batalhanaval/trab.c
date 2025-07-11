#include <stdio.h>

#define TAM 10
#define TAM_HAB 5

void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;
}

void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void posicionarNavioHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho) {
    for (int i = 0; i < tamanho; i++)
        if (coluna + i < TAM)
            tabuleiro[linha][coluna + i] = 3;
}

void posicionarNavioVertical(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho) {
    for (int i = 0; i < tamanho; i++)
        if (linha + i < TAM)
            tabuleiro[linha + i][coluna] = 3;
}

void posicionarNavioDiagonalPrincipal(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho) {
    for (int i = 0; i < tamanho; i++)
        if (linha + i < TAM && coluna + i < TAM)
            tabuleiro[linha + i][coluna + i] = 3;
}

void posicionarNavioDiagonalSecundaria(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho) {
    for (int i = 0; i < tamanho; i++)
        if (linha + i < TAM && coluna - i >= 0)
            tabuleiro[linha + i][coluna - i] = 3;
}

void criarCone(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i >= j && i + j <= TAM_HAB - 1 + i)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void criarCruz(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void criarOctaedro(int matriz[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int linha, int coluna) {
    int offset = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int li = linha + i - offset;
            int co = coluna + j - offset;

            if (li >= 0 && li < TAM && co >= 0 && co < TAM) {
                if (habilidade[i][j] == 1 && tabuleiro[li][co] == 0)
                    tabuleiro[li][co] = 5;
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    inicializarTabuleiro(tabuleiro);

    posicionarNavioHorizontal(tabuleiro, 0, 0, 3);
    posicionarNavioVertical(tabuleiro, 2, 2, 3);
    posicionarNavioDiagonalPrincipal(tabuleiro, 4, 4, 3);
    posicionarNavioDiagonalSecundaria(tabuleiro, 6, 6, 3);

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    aplicarHabilidade(tabuleiro, cone, 2, 5);
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    aplicarHabilidade(tabuleiro, octaedro, 8, 3);

    printf("Tabuleiro Final:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
