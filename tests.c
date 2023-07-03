#include <stdio.h>
#include <math.h>
#include "CUnit/Basic.h"

#define N 3

void cholesky(float A[N][N], float L[N][N]);
void printMatrix(float M[N][N]);

void test_cholesky(void) {
    float A[N][N] = {{6, 15, 55}, {15, 55, 225}, {55, 225, 979}};
    float L[N][N] = {0};

    cholesky(A, L);

    // Результат должен быть равен эталонному
    float expected_L[N][N] = {{2.449489, 6.123724, 22.453655}, {0, 4.183300, 18.973666}, {0, 0, 6.110101}};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Проверка приближенности каждого элемента
            CU_ASSERT_DOUBLE_EQUAL(L[i][j], expected_L[i][j], 0.00001);
        }
    }
}

int main() {
    // Инициализация CUnit тестового регистра
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_pSuite pSuite = NULL;

    // Добавление suite в регистр
    pSuite = CU_add_suite("Cholesky_Test_Suite", 0, 0);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Добавление теста в suite
    if (NULL == CU_add_test(pSuite, "test of cholesky()", test_cholesky)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Запуск всех тестов
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    CU_cleanup_registry();
    return CU_get_error();
}
