#include <iostream>

using namespace std;

// Функция за обръщане на част от масив
void reversePart(int* arr, int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotate(int* nums, int n, int k) {
    k = k % n; // Ако к е по-голямо от размера
    if (k == 0) return;

    // Алгоритъм за ротация чрез 3 обръщания:
    // 1. Обръщаме целия масив
    reversePart(nums, 0, n - 1);
    // 2. Обръщаме първите k
    reversePart(nums, 0, k - 1);
    // 3. Обръщаме останалите n-k
    reversePart(nums, k, n - 1);
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int k = 3;

    rotate(nums, n, k);

    cout << "Rotated: [";
    for(int i = 0; i < n; i++) cout << nums[i] << (i < n-1 ? ", " : "");
    cout << "]" << endl;

    return 0;
}
