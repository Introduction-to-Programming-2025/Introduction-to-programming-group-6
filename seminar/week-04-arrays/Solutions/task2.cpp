#include <iostream>

const unsigned int SIZE = 1028;

int main() {
    int arr[SIZE];
    unsigned int n;
    bool result = true;

    std::cin >> n;

    for (unsigned int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    for (unsigned int i = 0; i < n / 2; i++) {
        if (arr[i] != arr[n - i - 1]) {
            result = false;
            break;
        }
    }

    std::cout << result << std::endl;
    return 0;
}
