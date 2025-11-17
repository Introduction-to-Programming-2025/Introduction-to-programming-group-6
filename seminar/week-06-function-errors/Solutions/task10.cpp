#include <iostream>
using namespace std;

const int MAX_N = 100000; // maximum number of elements

bool isPossible(long long sortedArr[], long long size, long long cows, long long x) {
    long long last = 0;
    long long counter = 1;
    for (long long i = 1; i < size; i++) {
        if (sortedArr[i] - sortedArr[last] >= x) {
            last = i;
            counter++;
        }
    }
    return cows <= counter;
}

long long binarySearch(long long sortedArr[], long long trees, long long size, long long maxVal) {
    long long l = 0;
    long long r = maxVal;
    long long ans = 1;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (isPossible(sortedArr, size, trees, mid)) {
            l = mid + 1;
            ans = mid;
        }
        else {
            r = mid - 1;
        }
    }
    return ans;
}

// Selection sort
void selectionSort(long long arr[], long long n) {
    for (long long i = 0; i < n - 1; i++) {
        long long minIndex = i;
        for (long long j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        // swap
        long long temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}


int main() {
    long long n, k;
    cin >> n >> k;

    if (n > MAX_N) {
        cerr << "Error: n exceeds MAX_N = " << MAX_N << "\n";
        return 1;
    }

    long long arr[MAX_N]; // static array
    cin >> arr[0];
    long long maxVal = arr[0];

    for (long long i = 1; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    selectionSort(arr, n);

    cout << binarySearch(arr, k, n, maxVal) << "\n";

    return 0;
}
