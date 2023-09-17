#include <iostream>
#include <vector>
using namespace std;

// Function to print a matrix
void printMatrix(const vector<vector<double>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "   ";
        }
        cout << endl;
    }
}

// Function to calculate the inverse of a matrix without pivot
vector<vector<double>> matrixInverse(const vector<vector<double>>& matrix) {
    int n = matrix.size();

    // Create an augmented matrix [matrix | I]
    vector<vector<double>> augmentedMatrix(n, vector<double>(2 * n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            augmentedMatrix[i][j] = matrix[i][j];
            if (i == j) {
                augmentedMatrix[i][j + n] = 1.0; // Identity matrix
            }
        }
    }

    // Perform Gaussian elimination without pivot
    for (int i = 0; i < n; ++i) {
        // Make the current element in the diagonal equal to 1
        double currentElement = augmentedMatrix[i][i];
        for (int j = 0; j < 2 * n; ++j) {
            augmentedMatrix[i][j] /= currentElement;
        }

        // Eliminate other elements in the column
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                double factor = augmentedMatrix[j][i];
                for (int k = 0; k < 2 * n; ++k) {
                    augmentedMatrix[j][k] -= factor * augmentedMatrix[i][k];
                }
            }
        }
    }

    // Extract the right half of the augmented matrix, which is the inverse
    vector<vector<double>> inverse(n, vector<double>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inverse[i][j] = augmentedMatrix[i][j + n];
        }
    }

    return inverse;
}

int main() {
    // Example usage
    vector<vector<double>> matrix = {{4, 1, 1}, {2, 5, 2}, {1, 2, 4}};

    vector<vector<double>> inverse = matrixInverse(matrix);

    cout << "Inverse of the matrix:" << endl;
    printMatrix(inverse);

    return 0;
}
