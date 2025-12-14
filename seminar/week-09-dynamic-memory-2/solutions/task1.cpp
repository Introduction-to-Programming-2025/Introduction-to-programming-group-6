#include <iostream>
using namespace std;

// Функция за изтриване на елемент
// n се подава по референция (&), за да можем да променим размера
void removeElementAtIndex(int* arr, int& n, int k) {
    if (k < 0 || k >= n) {
        cout << "Невалиден индекс!" << endl;
        return;
    }

    // Преместване на елементите наляво, за да се запълни дупката
    for (int i = k; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    // Намаляваме размера на масива
    n--;
}

int main() {
    // Примерни данни
    int n = 5;
    int* arr = new int[n];
    
    // Запълване на масива: [10, 20, 30, 40, 50]
    for(int i = 0; i < n; i++) arr[i] = (i + 1) * 10;

    int k = 2; // Искаме да изтрием индекс 2 (числото 30)

    cout << "Преди: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    removeElementAtIndex(arr, n, k);

    cout << "След:  ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    delete[] arr;
    return 0;
}
