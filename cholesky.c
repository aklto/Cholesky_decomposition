#include <stdio.h>
#include <math.h>

#define N 3

void cholesky(float A[N][N], float L[N][N]) {
    int i, k, j;
    for (i = 0; i < N; i++) {
        for (k = 0; k < (i+1); k++) {
            float tmp_sum = 0;
            for (j = 0; j < k; j++) {
                tmp_sum += L[i][j] * L[k][j];
            }
            if (i == k) {
                L[i][k] = sqrt(A[i][i] - tmp_sum);
            } else {
                L[i][k] = (1.0 / L[k][k] * (A[i][k] - tmp_sum));
            }
        }
    }
}

void printMatrix(float M[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%f ", M[i][j]);
        }
        printf("\n");
    }
}

int main() {
    float A[N][N] = {{6, 15, 55}, {15, 55, 225}, {55, 225, 979}};
    float L[N][N] = {0};

    cholesky(A, L);

    printf("L:\n");
    printMatrix(L);

    return 0;
}
