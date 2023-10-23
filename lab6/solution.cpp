#include <iostream>
#include <fstream>

using namespace std;

// declare the static constant size.
static const int MAX_SIZE = 100;

// define the function prototypes.
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int &n, ifstream &file);
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int n);
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int n);
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int n);
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int n);

int main() {
    cout << "Your name" << endl;
    cout << "Lab #6: Matrix manipulation" << endl << endl;

    ifstream file("matrix_input.txt");
    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int n;  // matrix size
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int resultMatrix[MAX_SIZE][MAX_SIZE];

    // read matrices from file
    readMatrix(matrixA, n, file);
    readMatrix(matrixB, n, file);

    cout << "Matrix A:" << endl;
    printMatrix(matrixA, n);
    cout << endl << "Matrix B:" << endl;
    printMatrix(matrixB, n);
    cout << endl;

    // add matrices
    addMatrices(matrixA, matrixB, resultMatrix, n);
    cout << "Matrix Sum (A + B):" << endl;
    printMatrix(resultMatrix, n);
    cout << endl;

    // multiply matrices
    multiplyMatrices(matrixA, matrixB, resultMatrix, n);
    cout << "Matrix Product (A * B):" << endl;
    printMatrix(resultMatrix, n);
    cout << endl;

    // subtract matrices
    subtractMatrices(matrixA, matrixB, resultMatrix, n);
    cout << "Matrix Difference (A - B):" << endl;
    printMatrix(resultMatrix, n);

    file.close();
    return 0;
}

// implement the function bodies below the main function.

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int &n, ifstream &file) {
    file >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            file >> matrix[i][j];
        }
    }
}

void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}
