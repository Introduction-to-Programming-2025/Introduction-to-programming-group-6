#include <iostream>

using namespace std;

// Помощна функция за търсене в масив
bool contains(int* arr, int size, int val) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) return true;
    }
    return false;
}

// Функция за сечение
int* intersection(int* nums1, int n1, int* nums2, int n2, int& resSize) {
    // Максималният възможен размер е по-малкият от двата размера
    int maxSize = (n1 < n2) ? n1 : n2;
    int* result = new int[maxSize];
    resSize = 0;

    for (int i = 0; i < n1; i++) {
        // Ако елементът е в nums2 И все още не е записан в резултата
        if (contains(nums2, n2, nums1[i]) && !contains(result, resSize, nums1[i])) {
            result[resSize++] = nums1[i];
        }
    }
    return result;
}

int main() {
    int nums1[] = {1, 2, 2, 1};
    int nums2[] = {2, 2};
    int n1 = 4, n2 = 2;
    
    int resSize = 0;
    int* res = intersection(nums1, n1, nums2, n2, resSize);

    cout << "Intersection: [";
    for(int i = 0; i < resSize; i++) cout << res[i] << (i < resSize-1 ? ", " : "");
    cout << "]" << endl;

    delete[] res;
    return 0;
}
