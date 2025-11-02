#include <iostream>

const unsigned int SIZE = 1028;

int main() {
    int arr[SIZE];
    unsigned int n, len = 0;
    bool result = true;

    std::cin >> n;

    while (n > 0) {
        arr[len++] = n % 10;
        n /= 10;
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
