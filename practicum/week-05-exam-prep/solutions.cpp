#include <iostream>

// Задача 1.
void checkmate(unsigned x1, unsigned y1, unsigned x2, unsigned y2)
{
    if (x1 > 8 || y1 > 8 || x2 > 8 || y2 > 8)
    {
        throw std::out_of_range("Position out of chessboard bounds");
    }
    bool rook = x1 == x2 || y1 == y2;
    bool queen = rook || (abs(int(x1) - int(x2)) == abs(int(y1) - int(y2)));
    bool king = (abs(int(x1) - int(x2)) <= 1) && (abs(int(y1) - int(y2)) <= 1);

    int dx = abs(int(x1) - int(x2));
    int dy = abs(int(y1) - int(y2));
    bool knight = (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}
// Задача 2.
int biggestAdjDifference(int n)
{
    if (n < 10)
    {
        return 0;
    }
    int maxDiff = 0;
    while (n >= 10)
    {
        int lastDigit = n % 10;
        n /= 10;
        int nextDigit = n % 10;
        int diff = abs(lastDigit - nextDigit);
        if (diff > maxDiff)
        {
            maxDiff = diff;
        }
    }
    return maxDiff;
}
// Задача 3.
int reverseNumber(int n)
{
    int reversed = 0;
    while (n > 0)
    {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    return reversed;
}
int greaterWithOneDigitSwap(int n)
{
    if (n == 0)
    {
        return 9;
    }

    int digits[10] = {0};
    int temp = n;
    while (temp > 0)
    {
        digits[temp % 10]++;
        temp /= 10;
    }
    int largestNotPresent;
    for (int i = 9; i >= 0; i--)
    {
        if (digits[i] == 0)
        {
            largestNotPresent = i;
            break;
        }
    }

    int reversed = reverseNumber(n);
    int result = 0;
    short swapped = -1;
    while (reversed > 0)
    {
        int digit = reversed % 10;
        if ((digit < largestNotPresent && swapped == -1) || (digit == swapped))
        {
            result = result * 10 + largestNotPresent;
            swapped = digit;
        }
        else
        {
            result = result * 10 + digit;
        }
        reversed /= 10;
    }
    return result;
}
// Задача 4.
int lengthOfLargestZigZagSubarray(int arr[], size_t size)
{
    int longest = 0;
    int current = 1;
    int lastDiff = 0;
    for (size_t i = 0; i < size - 1; i++)
    {
        int currDiff = arr[i] - arr[i + 1];
        if (currDiff * lastDiff < 0)
        {
            current++;
        }
        else if (current + 1 > longest)
        {
            longest = current + 1;
            current = 1;
        }
        lastDiff = currDiff;
    }
    if (current + 1 > longest)
    {
        longest = current + 1;
        current = 1;
    }
    return longest;
}
// Задача 5.
void rotationCropped(int arr[], size_t start, size_t endIndex)
{
    int temp = arr[endIndex];
    for (size_t i = endIndex; i > start; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[start] = temp;
}
void negativeNonNegativeAdj(int arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] >= 0 && i % 2 == 1)
        {
            for (size_t j = i + 1; j < size; j++)
            {
                if (arr[j] < 0)
                {
                    rotationCropped(arr, i, j);
                    break;
                }
            }
        }

        if (arr[i] < 0 && i % 2 == 0)
        {
            for (size_t j = i + 1; j < size; j++)
            {
                if (arr[j] >= 0)
                {
                    rotationCropped(arr, i, j);
                    break;
                }
            }
        }
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    std::cout << greaterWithOneDigitSwap(0) << std::endl;
    std::cout << greaterWithOneDigitSwap(1182) << std::endl;
    std::cout << greaterWithOneDigitSwap(1192) << std::endl;
    std::cout << greaterWithOneDigitSwap(9871) << std::endl;
    std::cout << greaterWithOneDigitSwap(999) << std::endl;
    std::cout << lengthOfLargestZigZagSubarray(arr, size) << std::endl;
    negativeNonNegativeAdj(arr, size);
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}