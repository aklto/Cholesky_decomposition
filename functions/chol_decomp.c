#include <math.h>
#include "chol_decomp.h"

void chol_decomp(float **A, float **L, int n) {
    int i, j, k;

    for (i = 0; i < n; i++) {
        for (j = 0; j < (i+1); j++) {
            float s = 0;
            for (k = 0; k < j; k++)
                s += L[i][k] * L[j][k];
            L[i][j] = (i == j) ?
                      sqrt(A[i][i] - s) :
                      (1.0 / L[j][j] * (A[i][j] - s));
        }
    }
}
