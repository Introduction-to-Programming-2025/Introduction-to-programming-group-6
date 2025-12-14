#include <iostream>

using namespace std;

bool contains(int* arr, int size, int val) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) return true;
    }
    return false;
}

void printDifference(int* nums1, int n1, int* nums2, int n2) {
    // В най-лошия случай всички са различни
    int* diffVals = new int[n1];
    int* diffIndices = new int[n1];
    int count = 0;

    for (int i = 0; i < n1; i++) {
        // Ако елементът от nums1 НЕ съществува в nums2
        if (!contains(nums2, n2, nums1[i])) {
            diffVals[count] = nums1[i];
            diffIndices[count] = i + 1; // Индексът е 1-based според примера
            count++;
        }
    }

    cout << "Output: [";
    for (int i = 0; i < count; i++) cout << diffVals[i] << (i < count-1 ? ", " : "");
    cout << "], indices: ";
    for (int i = 0; i < count; i++) cout << diffIndices[i] << (i < count-1 ? ", " : "");
    cout << endl;

    delete[] diffVals;
    delete[] diffIndices;
}

int main() {
    int nums1[] = {17, 9, 6, 7, 13};
    int nums2[] = {10, 1, 7, 18, 22};
    
    printDifference(nums1, 5, nums2, 5);

    return 0;
}
