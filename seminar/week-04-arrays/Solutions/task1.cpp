#include <iostream>

const unsigned int SIZE = 128;

int main() {
    unsigned int n;
    std::cin >> n;

    int arr[SIZE];

    for (unsigned int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    for (unsigned int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    for (unsigned int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
    return 0;
}
