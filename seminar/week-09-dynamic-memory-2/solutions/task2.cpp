#include <iostream>

using namespace std;

// Функция за изтриване на ред
// rows се подава по референция
void removeRow(int** matrix, int& rows, int cols, int k) {
    if (k < 0 || k >= rows) return;

    // 1. Освобождаваме паметта на реда, който ще трием
    delete[] matrix[k];

    // 2. Преместваме указателите на следващите редове нагоре
    for (int i = k; i < rows - 1; i++) {
        matrix[i] = matrix[i + 1];
    }

    // 3. Намаляваме броя на редовете
    rows--;
}

int main() {
    int rows = 3, cols = 3;
    
    // Динамично заделяне на матрица
    int** matrix = new int*[rows];
    for(int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = i * 10 + j; // Примерни стойности
        }
    }

    // Принтиране преди
    cout << "Original Matrix:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) cout << matrix[i][j] << " ";
        cout << endl;
    }

    // Изтриване на ред с индекс 1 (втория ред)
    removeRow(matrix, rows, cols, 1);

    // Принтиране след
    cout << "Modified Matrix:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) cout << matrix[i][j] << " ";
        cout << endl;
    }

    // Почистване на паметта
    for(int i = 0; i < rows; i++) delete[] matrix[i];
    delete[] matrix;

    return 0;
}
