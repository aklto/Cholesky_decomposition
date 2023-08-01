#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../functions/chol_decomp.h"

#define EPSILON 0.0001

float** create_matrix(int n);

void delete_matrix(float** mat, int n);

int are_equal(float** mat1, float** mat2, int n);

void test_chol_decomp() {
    int n = 3;
    float **A = create_matrix(n);
    float **L = create_matrix(n);

    A[0][0] = 4.0; A[0][1] = 12.0; A[0][2] = -16.0;
    A[1][0] = 12.0; A[1][1] = 37.0; A[1][2] = -43.0;
    A[2][0] = -16.0; A[2][1] = -43.0; A[2][2] = 98.0;

    float **expected = create_matrix(n);
    expected[0][0] = 2.0; expected[0][1] = 0.0; expected[0][2] = 0.0;
    expected[1][0] = 6.0; expected[1][1] = 1.0; expected[1][2] = 0.0;
    expected[2][0] = -8.0; expected[2][1] = 5.0; expected[2][2] = 3.0;

    chol_decomp(A, L, n);

    if (are_equal(L, expected, n)) {
        printf("Test passed!\n");
    } else {
        printf("Test failed!\n");
    }

    delete_matrix(A, n);
    delete_matrix(L, n);
    delete_matrix(expected, n);
}

void run_tests() {
    test_chol_decomp();
}

float** create_matrix(int n) {
    float **mat = (float **)malloc(n * sizeof(float *));
    for (int i=0; i<n; i++)
        mat[i] = (float *)malloc(n * sizeof(float));
    return mat;
}

void delete_matrix(float** mat, int n) {
    for (int i=0; i<n; i++)
        free(mat[i]);
    free(mat);
}

int are_equal(float** mat1, float** mat2, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (fabs(mat1[i][j] - mat2[i][j]) > EPSILON) {
                return 0;
            }
        }
    }
    return 1;
}
