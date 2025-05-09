#include <stdio.h>

int main() {
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // 1. criando o tabuleiro (Matriz 10x10)
    int tabuleiro[10][10];

    // Inicializando todas as posições com 0 (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Posicionando navio horizontal (linha 3, colunas E-F-G -> [2][4] a [2][6])
    int linha_h = 2;
    int coluna_h = 4;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_h][coluna_h + i] = 3;
    }

    // 3. Posicionando navio vertical (coluna H, linhas 6-7-8 -> [5][7] a [7][7])
    int linha_v = 5;
    int coluna_v = 7;
    int sobreposicao = 0;

    for (int i = 0; i < 3; i++) {
        if (tabuleiro[linha_v + i][coluna_v] == 3) {
            sobreposicao = 1;
            break;
        }
    }

    if (!sobreposicao) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha_v + i][coluna_v] = 3;
        }
    }

    // 4. Exibindo o cabeçalho (letras A-J)
    printf("     ");
    for (int i = 0; i < 10; i++) {
        printf("%2c ", linha[i]);
    }
    printf("\n");

    // 5. Exibindo o tabuleiro com números à esquerda
    for (int i = 0; i < 10; i++) {
        printf("%3d ", i + 1);  // Números das linhas
        for (int j = 0; j < 10; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
