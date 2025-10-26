#include<iostream>

const unsigned int SIZE = 1028;

int main() {
    int arr[SIZE];

    unsigned int n;
    std::cin >> n;
    for (unsigned int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    unsigned int max_len = 0;
    int max_len_num = arr[0];
    unsigned int i = 0;

    while (i < n) {
        unsigned int j = i + 1, curr_len = 1;
        while (j < n && arr[j] == arr[i]) {
            curr_len++;
            j++;
        }
        if (curr_len > max_len) {
            max_len = curr_len;
            max_len_num = arr[i];
        }
        i = j;
    }

    std::cout << max_len << " " << max_len_num;
    return 0;
}
