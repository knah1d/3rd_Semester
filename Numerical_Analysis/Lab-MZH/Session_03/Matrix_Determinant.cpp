#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Maximum matrix size

// Function to calculate the determinant of a matrix using Gaussian elimination
double matrixDeterminant(double matrix[MAX_SIZE][MAX_SIZE], int n) {
    double det = 1.0;

    // Create a copy of the matrix
    double temp[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            temp[i][j] = matrix[i][j];
        }
    }

    // Perform Gaussian elimination to transform the matrix into upper triangular form
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double factor = temp[j][i] / temp[i][i];
            for (int k = i; k < n; ++k) {
                temp[j][k] -= factor * temp[i][k];
            }
        }
    }

    // Calculate the determinant as the product of the diagonal elements
    for (int i = 0; i < n; ++i) {
        det *= temp[i][i];
    }

    return det;
}

int main() {
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;

    if (n <= 0 || n > MAX_SIZE) {
        cout << "Invalid matrix size." << endl;
        return 1;
    }

    double matrix[MAX_SIZE][MAX_SIZE];

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    double determinant = matrixDeterminant(matrix, n);

    cout << "Determinant of the matrix: " << determinant << endl;

    return 0;
}
