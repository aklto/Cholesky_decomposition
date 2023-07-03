#include <stdio.h>
#include <stdlib.h>
#include "../functions/chol_decomp.h"

#define MAX_SIZE 100

float **allocate_matrix(int rows, int cols);
void free_matrix(float **matrix, int rows);
void print_matrix(float **matrix, int rows, int cols);

int main() {
    FILE *file = fopen("files/matrix.txt", "r");
    if (file == NULL) {
        perror("Файл не найден");
        return 1;
    }


    int n;
    fscanf(file, "%d", &n);

    float **A = allocate_matrix(n, n);
    float **L = allocate_matrix(n, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(file, "%f", &A[i][j]);
        }
    }

    fclose(file);

    chol_decomp(A, L, n);

    print_matrix(L, n, n);

    free_matrix(A, n);
    free_matrix(L, n);

    return 0;
}

float **allocate_matrix(int rows, int cols) {
    float **matrix = (float **) malloc(rows * sizeof(float *));
    for (int i = 0; i < rows; i++)
        matrix[i] = (float *) malloc(cols * sizeof(float));

    return matrix;
}

void free_matrix(float **matrix, int rows) {
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
}

void print_matrix(float **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}
