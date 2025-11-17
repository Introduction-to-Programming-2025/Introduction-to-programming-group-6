#include <iostream>
using namespace std;

const int MAX_ROWS = 10;
const int MAX_COLS = 10;

void sort2DArray(int arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int flat[MAX_ROWS * MAX_COLS];
    int k = 0;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            flat[k++] = arr[i][j];


    for (int i = 0; i < k - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < k; j++) {
            if (flat[j] < flat[minIndex])
                minIndex = j;
        }
        
        int temp = flat[i];
        flat[i] = flat[minIndex];
        flat[minIndex] = temp;
    }

    k = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            arr[i][j] = flat[k++];
}

void printMatrix(int arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int rows = 4, cols = 5;
    int arr[MAX_ROWS][MAX_COLS] = {
        {87, 1, 435, 5, 2},
        {500, 90, 65, 23, 39},
        {124, 45, 555, 50, 70},
        {200, 67, 80, 73, 600}
    };

    cout << "Original matrix:\n";
    printMatrix(arr, rows, cols);

    sort2DArray(arr, rows, cols);

    cout << "\nSorted matrix:\n";
    printMatrix(arr, rows, cols);

    return 0;
}
