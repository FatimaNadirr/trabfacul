#include <stdio.h>
#include <stdlib.h>

#define TAM 8

void direcao(int dx, int dy) {
    if (dx == 0 && dy > 0) printf("Direita\n");
    else if (dx == 0 && dy < 0) printf("Esquerda\n");
    else if (dy == 0 && dx > 0) printf("Baixo\n");
    else if (dy == 0 && dx < 0) printf("Cima\n");
    else if (dx > 0 && dy > 0) printf("Diagonal Baixo-Direita\n");
    else if (dx > 0 && dy < 0) printf("Diagonal Baixo-Esquerda\n");
    else if (dx < 0 && dy > 0) {
        printf("Cima\n");
        printf("Direita\n");
    }
    else if (dx < 0 && dy < 0) {
        printf("Cima\n");
        printf("Esquerda\n");
    }
}

void moverTorreRec(int x, int y, int dx, int dy, int passos) {
    if (passos == 0) return;

    int nx = x + dx;
    int ny = y + dy;

    if (nx < 0 || nx >= TAM || ny < 0 || ny >= TAM) return;

    direcao(dx, dy);
    moverTorreRec(nx, ny, dx, dy, passos - 1);
}

void moverTorre(int x, int y) {
    printf("Movimento da TORRE (5 casas para a direita):\n");
    moverTorreRec(x, y, 0, 1, 5);
    printf("\n");
}

void moverBispoRec(int x, int y, int dx, int dy, int passos) {
    if (passos == 0) return;

    int nx = x + dx;
    int ny = y + dy;

    if (nx < 0 || nx >= TAM || ny < 0 || ny >= TAM) return;

    direcao(dx, dy); 
    moverBispoRec(nx, ny, dx, dy, passos - 1);
}

void moverBispo(int x, int y) {
    printf("Movimento do BISPO (5 casas na diagonal cima-direita):\n");
    moverBispoRec(x, y, -1, 1, 5);
    printf("\n");
}

void moverBispoLoop(int x, int y, int passos) {
    printf("Movimento do BISPO com loops aninhados:\n");
    for (int i = 1; i <= passos; i++) { 
        for (int j = 1; j <= passos; j++) { 
            if (i == j) {
                int nx = x - i;
                int ny = y + j;
                if (nx < 0 || ny >= TAM) {
                    continue; 
                }
                direcao(-1, 1); 
            }
        }
    }
    printf("\n");
}


void moverRainhaRec(int x, int y, int dx, int dy, int passos) {
    if (passos == 0) return;

    int nx = x + dx;
    int ny = y + dy;

    if (nx < 0 || nx >= TAM || ny < 0 || ny >= TAM) return;

    direcao(dx, dy);
    moverRainhaRec(nx, ny, dx, dy, passos - 1);
}

void moverRainha(int x, int y) {
    printf("Movimento da RAINHA (8 casas para a esquerda):\n");
    moverRainhaRec(x, y, 0, -1, 8); 
    printf("\n");
}


void moverCavalo(int x, int y) {
    printf("Movimento do CAVALO (duas casas para cima e uma para a direita):\n");

    for (int dx = -2; dx <= -2; dx++) {
        int nx = x + dx;
        if (nx < 0 || nx >= TAM) {
            printf("Movimento inválido (fora do tabuleiro)\n\n");
            break;
        }

        int j = 0;
        while (j < 1) { 
            int ny = y + 1;
            if (ny >= TAM) {
                printf("Movimento inválido (fora do tabuleiro)\n\n");
                break;
            }

            
            printf("Cima\n");
            printf("Cima\n");
            printf("Direita\n");

            break; 
        }
    }

    printf("\n");
}

int main() {
    int origemX = 4, origemY = 4;

    moverTorre(origemX, origemY);
    moverBispo(origemX, origemY);
    moverBispoLoop(origemX, origemY, 5);
    moverRainha(origemX, origemY);
    moverCavalo(origemX, origemY);

    return 0;
}
