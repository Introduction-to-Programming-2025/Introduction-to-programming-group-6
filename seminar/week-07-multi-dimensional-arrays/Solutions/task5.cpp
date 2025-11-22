#include <iostream>
using namespace std;

const int MAX_ROWS = 10;  // maximum allowed rows
const int MAX_COLS = 10;  // maximum allowed columns

void spiralMatrix(int rows, int columns, int matrix[MAX_ROWS][MAX_COLS]) {
    int counter = 1;
    int startRow = 0, startColumn = 0;
    int endRow = rows, endColumn = columns;

    while (startRow < endRow && startColumn < endColumn) {
        // first row
        for (int i = startColumn; i < endColumn; i++)
            matrix[startRow][i] = counter++;
        startRow++;

        // last column
        for (int i = startRow; i < endRow; i++)
            matrix[i][endColumn - 1] = counter++;
        endColumn--;

        // last row
        if (startRow < endRow) {
            for (int i = endColumn - 1; i >= startColumn; i--)
                matrix[endRow - 1][i] = counter++;
            endRow--;
        }

        // first column
        if (startColumn < endColumn) {
            for (int i = endRow - 1; i >= startRow; i--)
                matrix[i][startColumn] = counter++;
            startColumn++;
        }
    }
}

void printMatrix(int rows, int columns, int matrix[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int rows, columns;
    cin >> rows >> columns;

    if (rows > MAX_ROWS || columns > MAX_COLS) {
        cout << "Error: exceeds maximum allowed size!\n";
        return 1;
    }

    int matrix[MAX_ROWS][MAX_COLS]; 

    spiralMatrix(rows, columns, matrix);
    printMatrix(rows, columns, matrix);

    return 0;
}