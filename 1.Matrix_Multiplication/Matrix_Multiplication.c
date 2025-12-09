#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define ROWS 2000
#define COLUMS 2000

void Matrix_mul()
{
    double start = omp_get_wtime();

    unsigned long **A = malloc(sizeof(unsigned long*) * ROWS);
    unsigned long **B = malloc(sizeof(unsigned long*) * ROWS);
    unsigned long **C = malloc(sizeof(unsigned long*) * ROWS);

    for (int i = 0; i < ROWS; i++) {
        A[i] = malloc(sizeof(unsigned long) * COLUMS);
        B[i] = malloc(sizeof(unsigned long) * COLUMS);
        C[i] = malloc(sizeof(unsigned long) * COLUMS);

        for (int j = 0; j < COLUMS; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
            C[i][j] = 0;
        }
    }
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLUMS; j++)
            for (int k = 0; k < COLUMS; k++)
                C[i][j] += A[i][k] * B[k][j];

    double end = omp_get_wtime();
    printf("used time = %f seconds 1 thread\n", end - start);
}

void Matrix_mul_omp()
{
    double start = omp_get_wtime();

    unsigned long **A = malloc(sizeof(unsigned long*) * ROWS);
    unsigned long **B = malloc(sizeof(unsigned long*) * ROWS);
    unsigned long **C = malloc(sizeof(unsigned long*) * ROWS);

    for (int i = 0; i < ROWS; i++) {
        A[i] = malloc(sizeof(unsigned long) * COLUMS);
        B[i] = malloc(sizeof(unsigned long) * COLUMS);
        C[i] = malloc(sizeof(unsigned long) * COLUMS);

        for (int j = 0; j < COLUMS; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
            C[i][j] = 0;
        }
    }

#pragma omp parallel for
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLUMS; j++)
            for (int k = 0; k < COLUMS; k++)
                C[i][j] += A[i][k] * B[k][j];

    double end = omp_get_wtime();
    printf("used time = %f seconds %d threads\n",end - start,omp_get_max_threads());
}

int main()
{
    Matrix_mul();
    Matrix_mul_omp();
    printf("finish\n");
    return 0;
}
