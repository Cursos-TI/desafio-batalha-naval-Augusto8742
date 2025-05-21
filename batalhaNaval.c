#include <stdio.h>

int main() {
    // Cabeçalho de letras
    char letras[10] = {'A','B','C','D','E','F','G','H','I','J'};

    // Tabuleiro 10x10 inicializado com 0 (água)
    int tabuleiro[10][10];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            tabuleiro[i][j] = 0;

    // Navios nas diagonais (formando um "X")
    for (int i = 0; i < 10; i++) {
        tabuleiro[i][i] = 3;         // Diagonal principal ↘
        tabuleiro[i][9 - i] = 3;     // Diagonal secundária ↙
    }

    // Navio horizontal central (linha 5, colunas E e F → [4][4] e [4][5])
    tabuleiro[4][4] = 3;
    tabuleiro[4][5] = 3;

    // Navio vertical central (coluna D, linhas 4 e 7 → [3][3] e [6][3])
    tabuleiro[3][3] = 3;
    tabuleiro[6][3] = 3;

    // Exibição do tabuleiro
    printf("TABULEIRO BATALHA NAVAL\n");
    printf("    ");
    for (int i = 0; i < 10; i++) {
        printf("%2c ", letras[i]);
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("%3d ", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
