#include <iostream>

const unsigned int SIZE = 1028;

int main() {
    unsigned int n;
    std::cin >> n;

    char arr[SIZE];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    const int LETTERS = 16;
    int counts[LETTERS] = { 0 };

    for (int i = 0; i < n; i++) {
        counts[arr[i] - 'a']++;
    }


    for (int i = 0; i < n; i++) {
        std::cout << counts[arr[i] - 'a'] << " ";
    }

    return 0;
}
