#include <iostream>
#include <cassert>
using namespace std;

const size_t SIZE = 1024;

int findOdd(const int arr[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result ^= arr[i];
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    int arr[SIZE];
    assert(n <= SIZE);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << findOdd(arr, n);

    return 0;
}
