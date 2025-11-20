#include <iostream>
#include <stdexcept>

using namespace std;
const size_t MAX_SIZE = 100;

int sum2(int a, int b);
void battleships();
size_t findAndMoveLongestIncreasingSubsequence(int *arr, size_t size, int &startIndex);
void rotateArrayKTimes(int *arr, size_t size, size_t i, size_t j, int k, bool toRight);
size_t deleteOutsideInterval(int *arr, size_t size, int num1, int num2);
void printArray(int *arr, size_t size);
void swapWithAvarageInRadius(double *arr, size_t size, size_t r);

int main()
{
    int arr[] = {10, 9, 2, 5, 3, 7, 9, 101, 18};
    size_t size = 9;
    int startIndex = 0;
    size_t length = findAndMoveLongestIncreasingSubsequence(arr, size, startIndex);
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Start index in original: " << startIndex << " Length: " << length << endl;
    return 0;
}

int sum2(int a, int b)
{
    return (a ^ b) & 1;
};
void battleships()
{
    short field = 0;
    // 0000 0000 0000 0000
    unsigned x, y;
    cin >> x >> y;
    if (x > 3 || y > 3)
    {
        throw std::out_of_range("Coordinates out of range");
    }
    field |= 1 << (y * 4 + x);
    for (int i = 0; i < 3; i++)
    {
        cin >> x >> y;
        if (x > 3 || y > 3)
        {
            throw std::out_of_range("Coordinates out of range");
        }
        if (field & (1 << (y * 4 + x)))
        {
            cout << "Hit!" << endl;
            return;
        }
        else
        {
            cout << "Miss!" << endl;
        }
    }
}

void rotateArray(int *arr, size_t size, size_t i, size_t j, bool toRight)
{
    if (i >= size || j >= size || i > j)
    {
        throw std::out_of_range("Index out of range");
    }
    if (toRight)
    {
        int temp = arr[j];
        for (size_t k = j; k > i; k--)
        {
            arr[k] = arr[k - 1];
        }
        arr[i] = temp;
    }
    else
    {
        int temp = arr[i];
        for (size_t k = i; k < j; k++)
        {
            arr[k] = arr[k + 1];
        }
        arr[j] = temp;
    }
}
void rotateArrayKTimes(int *arr, size_t size, size_t i, size_t j, int k, bool toRight)
{
    if (k < 0)
    {
        throw std::invalid_argument("k must be non-negative");
    }
    if (i >= size || j >= size || i > j)
    {
        throw std::out_of_range("Index out of range");
    }

    size_t len = j - i + 1;
    if (len <= 1)
        return;

    k %= len;
    if (k == 0)
        return;

    for (int count = 0; count < k; count++)
    {
        rotateArray(arr, size, i, j, toRight);
    }
}
void deleteAtIndex(int *arr, size_t &size, size_t index)
{
    if (index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    for (size_t i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}
size_t deleteOutsideInterval(int *arr, size_t size, int num1, int num2)
{
    size_t i = 0;
    while (i < size)
    {
        if (arr[i] < num1 || arr[i] > num2)
        {
            deleteAtIndex(arr, size, i);
        }
        else
        {
            i++;
        }
    }
    return size;
}
void swapWithAvarageInRadius(double *arr, size_t size, size_t r)
{
    if (r == 0 || size == 0)
        return;

    double copy[MAX_SIZE];

    for (int i = 0; i < size; i++)
    {
        double sum = 0;
        int count = 0;
        for (int j = 1; j <= r; j++)
        {
            if (j + i < size)
            {
                sum += arr[i + j];
                count++;
            }
            if (i - j >= 0)
            {
                sum += arr[i - j];
                count++;
            }
        }
        sum += arr[i];
        count++;

        copy[i] = sum / count;
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = copy[i];
    }
}

int findLongestIncreasingSubarray(int *arr, size_t size, int &startIndex)
{
    int longestLength = 1;
    int longestStartIndex = 0;
    int currentLength = 1;
    for (size_t i = 1; i < size; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            currentLength++;
        }
        else
        {
            currentLength = 1;
        }

        if (currentLength > longestLength)
        {
            longestLength = currentLength;
            longestStartIndex = i - currentLength + 1;
        }
    }
    startIndex = longestStartIndex;
    return longestLength;
}
void moveSubsequenceToFront(int *arr, size_t &size, int startIndex, int length)
{
    if (startIndex < 0 || startIndex + length > size)
    {
        throw std::out_of_range("Index out of range");
    }
    int temp[MAX_SIZE];
    int index = 0;
    for (int i = 0; i < length; i++)
    {
        temp[i] = arr[startIndex + i];
        index++;
    }
    for (size_t i = 0; i < startIndex; i++)
    {
        temp[index++] = arr[i];
    }
    for (size_t i = startIndex + length; i < size; i++)
    {
        temp[index++] = arr[i];
    }
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = temp[i];
    }
}

size_t findAndMoveLongestIncreasingSubsequence(int *arr, size_t size, int &startIndex)
{
    int length = findLongestIncreasingSubarray(arr, size, startIndex);
    moveSubsequenceToFront(arr, size, startIndex, length);
    return length;
}