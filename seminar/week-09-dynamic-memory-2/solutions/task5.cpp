#include <iostream>

using namespace std;

bool contains(int* arr, int size, int val) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) return true;
    }
    return false;
}

int* unionArrays(int* nums1, int n1, int* nums2, int n2, int& resSize) {
    // Максимален размер е сумата на двата
    int* result = new int[n1 + n2];
    resSize = 0;

    // Добавяме всички уникални от първия
    for (int i = 0; i < n1; i++) {
        if (!contains(result, resSize, nums1[i])) {
            result[resSize++] = nums1[i];
        }
    }

    // Добавяме всички уникални от втория
    for (int i = 0; i < n2; i++) {
        if (!contains(result, resSize, nums2[i])) {
            result[resSize++] = nums2[i];
        }
    }
    return result;
}

int main() {
    int nums1[] = {2, 5, 6};
    int nums2[] = {4, 6, 8, 10};
    int n1 = 3, n2 = 4;

    int resSize = 0;
    int* res = unionArrays(nums1, n1, nums2, n2, resSize);

    cout << "Union: [";
    for(int i = 0; i < resSize; i++) cout << res[i] << (i < resSize-1 ? ", " : "");
    cout << "]" << endl;

    delete[] res;
    return 0;
}
