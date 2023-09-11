#include <stdio.h>

#define N 3 // Number of equations

void printMatrix(int rows, int cols, double matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void gaussianElimination(int n, double matrix[n][n+1]) {
    for (int i = 0; i < n; i++) {
        // Partial Pivoting
        for (int k = i + 1; k < n; k++) {
            if (matrix[i][i] < matrix[k][i]) {
                for (int j = 0; j <= n; j++) {
                    double temp = matrix[i][j];
                    matrix[i][j] = matrix[k][j];
                    matrix[k][j] = temp;
                }
            }
        }

        // Forward Elimination
        for (int k = i + 1; k < n; k++) {
            double factor = matrix[k][i] / matrix[i][i];
            for (int j = i; j <= n; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }

    // Back Substitution
    double solutions[n];
    for (int i = n - 1; i >= 0; i--) {
        solutions[i] = matrix[i][n];
        for (int j = i + 1; j < n; j++) {
            solutions[i] -= matrix[i][j] * solutions[j];
        }
        solutions[i] /= matrix[i][i];
    }

    // Print solutions
    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i + 1, solutions[i]);
    }
}

int main() {
    double matrix[N][N+1] = {
        {2, 1, -1, 8},
        {-3, -1, 2, -11},
        {-2, 1, 2, -3}
    };

    printf("Original Augmented Matrix:\n");
    printMatrix(N, N+1, matrix);

    gaussianElimination(N, matrix);

    return 0;
}