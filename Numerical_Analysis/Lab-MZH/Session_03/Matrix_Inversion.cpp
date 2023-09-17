#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Maximum matrix size

// Function to print a matrix
void printMatrix(double matrix[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << "   ";
        }
        cout << endl;
    }
}

// Function to calculate the inverse of a matrix without pivot
void matrixInverse(double matrix[MAX_SIZE][MAX_SIZE], int n) {
    // Create an augmented matrix [matrix | I]
    double augmentedMatrix[MAX_SIZE][2 * MAX_SIZE] = {0};
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
    double inverse[MAX_SIZE][MAX_SIZE] = {0};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inverse[i][j] = augmentedMatrix[i][j + n];
        }
    }

    // Copy the inverse matrix back to the original matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = inverse[i][j];
        }
    }
}

int main() {
    
    int n;
    cout<<"Enter order of the squre matrix: ";
    cin>>n;
    cout<<"Enter elements:"<<endl;
    double matrix[MAX_SIZE][MAX_SIZE];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>matrix[i][j];
        }
    }
    cout<<endl;
    cout << "Given Matrix:" << endl;

    printMatrix(matrix, n);
    cout<<endl;
    
    matrixInverse(matrix, n);

    cout << "Inverse of the matrix:" << endl;
    printMatrix(matrix, n);

    return 0;
}
