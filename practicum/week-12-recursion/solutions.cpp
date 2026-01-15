#include <iostream>
#include <string.h>
#include <cmath>

unsigned firstNSum(unsigned n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + firstNSum(n - 1);
}

unsigned gcd(unsigned a, unsigned b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int reverseHelper(int n, int result)
{
    if (n == 0)
        return result;

    return reverseHelper(n / 10, result * 10 + n % 10);
}

int reverseNumber(int n)
{
    return reverseHelper(n, 0);
}

int waysToClimb(int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    return waysToClimb(n - 1) + waysToClimb(n - 2) + waysToClimb(n - 3);
}

void insertSorted(int *arr, int n, int x)
{
    if (n == 0 || arr[n - 1] <= x)
    {
        arr[n] = x;
        return;
    }
    arr[n] = arr[n - 1];
    insertSorted(arr, n - 1, x);
}

void generateAllBinNoConsecutiveOnes(char *str, int n, int index, int last)
{
    if (index == n)
    {
        str[n] = '\0';
        std::cout << str << std::endl;
        return;
    }
    str[index] = '0';
    generateAllBinNoConsecutiveOnes(str, n, index + 1, 0);
    if (last != 1)
    {
        str[index] = '1';
        generateAllBinNoConsecutiveOnes(str, n, index + 1, 1);
    }
}

void sumToN(int maxNumber, int remaining, int *result, int index, int size)
{
    if (remaining == 0)
    {
        for (int i = 0; i < size; i++)
        {
            if (result[i] != 0)
            {
                std::cout << result[i] << " ";
            }
        }
        std::cout << std::endl;
        return;
    }
    for (int i = std::min(remaining, maxNumber); i >= 1; i--)
    {
        result[index] = i;
        sumToN(i, remaining - i, result, index + 1, size);
        result[index] = 0;
    }
}

int knapsackRec(int W, int *val, int *wt, int n)
{

    if (n == 0 || W == 0)
        return 0;

    int pick = 0;

    if (wt[n - 1] <= W)
        pick = val[n - 1] + knapsackRec(W - wt[n - 1], val, wt, n - 1);

    int notPick = knapsackRec(W, val, wt, n - 1);

    return std::max(pick, notPick);
}

bool almostPalindromeHelper(char *str, int l, int r, int removed)
{
    if (l >= r)
    {
        return true;
    }

    if (removed >= 2)
    {
        return false;
    }

    if (str[l] != str[r])
    {
        return almostPalindromeHelper(str, l + 1, r, removed + 1) ||
               almostPalindromeHelper(str, l, r - 1, removed + 1);
    }

    return almostPalindromeHelper(str, l + 1, r - 1, removed);
}

bool almostPalindrome(char *str)
{
    return almostPalindromeHelper(str, 0, strlen(str) - 1, 0);
}

int fib1(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    return fib1(n - 1) + fib1(n - 2);
}

int fib2Helper(int n, int f1, int f2)
{
    if (n == 1 || n == 2)
    {
        return f1;
    }
    return fib2Helper(n - 1, f1 + f2, f1);
}
int fib2(int n)
{
    return fib2Helper(n, 1, 1);
}
int main()
{
    // int arr[4] = {0};
    // sumToN(4, 4, arr, 0, 4);
    // int val[3] = {1, 2, 3};
    // int wt[3] = {4, 5, 1};
    // int W = 7;
    // std::cout << knapsackRec(W, val, wt, 3);
    // char str[] = "abccdcbba";
    // std::cout << almostPalindrome(str);
    // std::cout << waysToClimb(10);
    // char bin[33];
    // generateAllBinNoConsecutiveOnes(bin, 4, 0, 0);
    std::cout << fib1(10) << ' ' << fib2(10);
}
