#include <iostream>

const unsigned int SIZE = 128;

int main() {
    int arr[SIZE];

    unsigned int n;
    std::cin >> n;
    for (unsigned int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] < 0) {
            for (int j = i; j < n - 1; j++) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (unsigned int i = 0; i < n; i++) {
        std::cout << arr[i] << std::endl;
    }

    return 0;
}
