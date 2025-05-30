#include <stdio.h>
#include <stdlib.h>

#define LINHA 3
#define COLUNA 5

// Imprime matriz de habilidade com 0 e 3
void exibirMatrizHabilidade(int hab[LINHA][COLUNA], const char* nome) {
    printf("\nSaída de habilidade em %s:\n", nome);
    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            printf("%d ", hab[i][j] == 1 ? 3 : 0);
        }
        printf("\n");
    }
}

// Gera matriz Cone (triângulo para baixo)
void gerarHabilidadeCone(int hab[LINHA][COLUNA]) {
    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            // Baseado no exemplo: 
            // Linha 0: 0 0 1 0 0
            // Linha 1: 0 1 1 1 0
            // Linha 2: 1 1 1 1 1
            if ((i == 0 && j == 2) ||
                (i == 1 && (j >= 1 && j <= 3)) ||
                (i == 2))
                hab[i][j] = 1;
            else
                hab[i][j] = 0;
        }
    }
}

// Gera matriz Cruz (linha e coluna centrais)
void gerarHabilidadeCruz(int hab[LINHA][COLUNA]) {
    int centroLinha = LINHA / 2;  // 1
    int centroColuna = COLUNA / 2; // 2
    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            // Exemplo cruz:
            // 0 0 1 0 0
            // 1 1 1 1 1
            // 0 0 1 0 0
            if (i == centroLinha || j == centroColuna)
                hab[i][j] = 1;
            else
                hab[i][j] = 0;
        }
    }
}

// Gera matriz Octaedro (losango)
void gerarHabilidadeOctaedro(int hab[LINHA][COLUNA]) {
    int centroLinha = LINHA / 2;   // 1
    int centroColuna = COLUNA / 2; // 2
    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            // Exemplo octaedro:
            // 0 0 1 0 0
            // 0 1 1 1 0
            // 0 0 1 0 0
            int dist = abs(i - centroLinha) + abs(j - centroColuna);
            hab[i][j] = (dist <= 1) ? 1 : 0;
        }
    }
}

int main() {
    int cone[LINHA][COLUNA];
    int cruz[LINHA][COLUNA];
    int octaedro[LINHA][COLUNA];

    gerarHabilidadeCone(cone);
    gerarHabilidadeCruz(cruz);
    gerarHabilidadeOctaedro(octaedro);

    exibirMatrizHabilidade(cone, "cone");
    exibirMatrizHabilidade(cruz, "cruz");
    exibirMatrizHabilidade(octaedro, "octaedro");

    return 0;
}
