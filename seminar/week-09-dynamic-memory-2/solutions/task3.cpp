#include <iostream>

using namespace std;

// Функция за изтриване на стълб
// cols се подава по референция
void removeCol(int** matrix, int rows, int& cols, int k) {
    if (k < 0 || k >= cols) return;

    for (int i = 0; i < rows; i++) {
        // За всеки ред преместваме елементите наляво от k нататък
        for (int j = k; j < cols - 1; j++) {
            matrix[i][j] = matrix[i][j + 1];
        }
    }
    
    cols--;
}

int main() {
    int rows = 3, cols = 3;
    
    // Динамично заделяне
    int** matrix = new int*[rows];
    for(int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = i * 10 + j; 
        }
    }

    cout << "Original:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) cout << matrix[i][j] << " ";
        cout << endl;
    }

    // Изтриване на стълб с индекс 1
    removeCol(matrix, rows, cols, 1);

    cout << "Modified:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) cout << matrix[i][j] << " ";
        cout << endl;
    }

    // Почистване
    for(int i = 0; i < rows; i++) delete[] matrix[i];
    delete[] matrix;

    return 0;
}
