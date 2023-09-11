#include <stdio.h>
#include <stdlib.h>

void RandomMatrix(int rows, int cols, int matrix[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = rand() % 10;
        }
    }
}

void multiplyMatrices(int rowsA, int colsA, int matrixA[rowsA][colsA],
                      int rowsB, int colsB, int matrixB[rowsB][colsB],
                      int result[rowsA][colsB])
{
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++)
            {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void printMatrix(int rows, int cols, int matrix[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    int matrixA[3][3];
    int matrixB[3][3];
    int result[3][3];

    RandomMatrix(3, 3, matrixA);
    RandomMatrix(3, 3, matrixB);

    printf("Matrix A:\n");
    printMatrix(3, 3, matrixA);

    printf("\nMatrix B:\n");
    printMatrix(3, 3, matrixB);

    multiplyMatrices(3, 3, matrixA, 3, 3, matrixB, result);

    printf("\nResultant Matrix:\n");
    printMatrix(3, 3, result);

    return 0;
}

