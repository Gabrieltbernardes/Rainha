#include <stdio.h>
#include <stdlib.h>

// Vari�vel global para indicar se uma solu��o foi encontrada
int encontrou_solucao = 0;

void rainha(int n, int **mat, int linha) {
    if (linha == n) {
        // Caso base: todas as rainhas foram colocadas com sucesso
        encontrou_solucao = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", mat[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        return;
    }

    // Tenta colocar a rainha em cada coluna da linha atual
    for (int col = 0; col < n; col++) {
        if (encontrou_solucao) return; // Para caso j� tenha encontrado uma solu��o

        int seguro = 1;

        // Verificar a coluna
        for (int i = 0; i < linha; i++) {
            if (mat[i][col] == 1) {
                seguro = 0;
                break;
            }
        }

        // Verificar a diagonal principal (linha - col)
        for (int i = 0; i < linha; i++) {
            if (col - (linha - i) >= 0 && mat[i][col - (linha - i)] == 1) {
                seguro = 0;
                break;
            }
        }

        // Verificar a diagonal secund�ria (linha + col)
        for (int i = 0; i < linha; i++) {
            if (col + (linha - i) < n && mat[i][col + (linha - i)] == 1) {
                seguro = 0;
                break;
            }
        }

        // Se for seguro, coloque a rainha e tente a pr�xima linha
        if (seguro) {
            mat[linha][col] = 1;
            rainha(n, mat, linha + 1);
            mat[linha][col] = 0; // Backtrack
        }
    }
}

int main() {
    int n;
    printf("Digite o tamanho do tabuleiro (N): ");
    scanf("%d", &n);

    if (n < 1) {
        printf("O tamanho do tabuleiro deve ser maior ou igual a 1.\n");
        return 1;
    }

    // Alocar matriz dinamicamente
    int **mat = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        mat[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            mat[i][j] = 0;
        }
    }

    // Resolver a partir da linha 0
    rainha(n, mat, 0);

    if (!encontrou_solucao) {
        printf("Nenhuma solu��o encontrada para o tamanho %d.\n", n);
    }

    // Liberar a mem�ria alocada
    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}

