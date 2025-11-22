#include <iostream>
#include <cassert>
using namespace std;

const unsigned int N = 10;
const unsigned int M = 15;

void transpose(int arr[][M], int result[][N], int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            result[j][i] = arr[i][j];
}

void addMatrices(int A[N][M], int B[N][M], int result[N][M], int rowsA, int colsA, int rowsB, int colsB) {
    assert(rowsA == rowsB && colsA == colsB);
    for (int i = 0; i < rowsA; i++)
        for (int j = 0; j < colsA; j++)
            result[i][j] = A[i][j] + B[i][j];
}

void multiplyScalar(int A[N][M], int result[N][M], int rows, int cols, int scalar) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = A[i][j] * scalar;
}

void multiplyMatrices(int A[N][M], int B[N][M], int result[N][M],
                      int rowsA, int colsA, int rowsB, int colsB) {
    assert(colsA == rowsB);

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            int sum = 0;
            for (int k = 0; k < colsA; k++)
                sum += A[i][k] * B[k][j];
            result[i][j] = sum;
        }
    }
}

