#include <iostream>

size_t readArray(int *arr);
size_t printArray(const int *arr, size_t size);
const size_t MAX_SIZE = 100;

int main()
{
    size_t size;
    char arr[MAX_SIZE];
    std::cin >> size;
    std::cout << "Enter " << size << " elements:" << std::endl;
    for (size_t i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }
    // int arr[MAX_SIZE];
    // size_t size = readArray(arr);
    //  int arr2[MAX_SIZE];
    //  size_t size2 = readArray(arr2);
    //  zad 1.
    //  double avg = 0.0;
    //  for (size_t i = 0; i < size; ++i)
    //  {
    //      avg += arr[i];
    //  }
    //  avg /= size;
    //  for (size_t i = 0; i < size; i++)
    //  {
    //      if (arr[i] > avg)
    //      {
    //          std::cout << arr[i] << " ";
    //      }
    //  }
    //  zad 2.
    //  if (size < 2)
    //  {
    //      std::cout << "Array must have at least two elements." << std::endl;
    //      return 1;
    //  }

    // int max = arr[0];
    // for (size_t i = 1; i < size; i++)
    // {
    //     if (arr[i] > max)
    //     {
    //         max = arr[i];
    //     }
    // }
    // int secondMax = INT_MIN;
    // for (size_t i = 0; i < size; i++)
    // {
    //     if (arr[i] > secondMax && arr[i] < max)
    //     {
    //         secondMax = arr[i];
    //     }
    // }
    // if (secondMax == INT_MIN)
    // {
    //     std::cout << "No second maximum element found." << std::endl;
    // }
    // else
    // {
    //     std::cout << "Second maximum element: " << secondMax << std::endl;
    // }
    // zad 3.
    // bool evenIndex = true;
    // for (size_t i = 0; i < size; i++)
    // {
    //     if (evenIndex)
    //     {
    //         for (size_t j = i; j < size - 1; j++)
    //         {
    //             arr[j] = arr[j + 1];
    //         }
    //         arr[size - 1] = 0;
    //         size--;
    //         i--;
    //     }
    //     evenIndex = !evenIndex;
    // }
    // zad 4.
    // int index = 0;
    // for (size_t i = 1; i < size; i++)
    // {
    //     if (arr[i] != arr[i - 1])
    //     {
    //         arr[++index] = arr[i];
    //     }
    // }
    // size = index + 1;
    // std::cout << size << " " << std::endl;

    // zad 5.
    // int count = 0;
    // for (size_t i = 0; i < size - 1; i++)
    // {
    //     bool alreadyCounted = false;
    //     for (size_t k = 0; k < i; k++)
    //     {
    //         if (arr[i] == arr[k])
    //         {
    //             alreadyCounted = true;
    //             break;
    //         }
    //     }
    //     if (alreadyCounted)
    //     {
    //         continue;
    //     }
    //     for (size_t j = i + 1; j < size; j++)
    //     {
    //         if (arr[i] == arr[j])
    //         {
    //             count++;
    //             break;
    //         }
    //     }
    // }
    // {
    //     std::cout << "Duplicates: " << count << std::endl;
    // }
    // zad 6.
    // const int MAX_SIZE_TIMES_TWO = MAX_SIZE * 2;
    // int mergedArr[MAX_SIZE_TIMES_TWO];
    // int i = 0, j = 0, k = 0;
    // while (i < size && j < size2)
    // {
    //     if (arr[i] < arr2[j])
    //     {
    //         mergedArr[k++] = arr[i++];
    //     }
    //     else
    //     {
    //         mergedArr[k++] = arr2[j++];
    //     }
    // }
    // while (i < size)
    // {
    //     mergedArr[k++] = arr[i++];
    // }
    // while (j < size2)
    // {
    //     mergedArr[k++] = arr2[j++];
    // }
    // zad 7.
    // short num, n1;
    // std::cin >> num;
    // n1 = num;
    // if (num < 0)
    // {
    //     n1 = -num;
    // }

    // bool binaryArr[16] = {0};
    // for (size_t i = 0; i < 15; i++)
    // {
    //     binaryArr[15 - i] = n1 % 2;
    //     n1 /= 2;
    // }

    // if (num < 0)
    // {
    //     for (int i = 15; i >= 0; i--)
    //     {
    //         binaryArr[i] = !binaryArr[i];
    //     }
    //     bool carry = true;
    //     int i = 15;
    //     while (carry && i >= 0)
    //     {
    //         if (binaryArr[i] == 0)
    //         {
    //             binaryArr[i] = 1;
    //             carry = false;
    //         }
    //         else
    //         {
    //             binaryArr[i] = 0;
    //         }
    //         i--;
    //     }
    // }

    // int printedBits = 0;
    // for (size_t i = 0; i < 16; i++)
    // {
    //     std::cout << binaryArr[i];
    //     printedBits++;
    //     if (printedBits == 4 && i != 15)
    //     {
    //         std::cout << " ";
    //         printedBits = 0;
    //     }
    // }
    // std::cout << std::endl;
    // zad 8.
    // bool hasBought = false;
    // int maxProfit = 0;
    // int buyPrice = 0;
    // for (size_t i = 0; i < size - 1; i++)
    // {
    //     if (arr[i] < arr[i + 1] && !hasBought)
    //     {
    //         hasBought = true;
    //         buyPrice = arr[i];
    //     }
    //     if (hasBought && arr[i] > arr[i + 1])
    //     {
    //         maxProfit += arr[i] - buyPrice;
    //         hasBought = false;
    //     }
    // }
    // if (hasBought)
    // {
    //     maxProfit += arr[size - 1] - buyPrice;
    // }
    // std::cout << "Max Profit: " << maxProfit << std::endl;
    // zad 9.
    // if (size != size2)
    // {
    //     std::cout << "Not identical." << std::endl;
    //     return 0;
    // }
    // for (size_t i = 0; i < size; i++)
    // {
    //     bool identical = true;
    //     for (size_t j = 0; j < size; j++)
    //     {
    //         if (arr[(i + j) % size] != arr2[j])
    //         {
    //             identical = false;
    //             break;
    //         }
    //     }
    //     if (identical)
    //     {
    //         std::cout << "Identical." << std::endl;
    //         return 0;
    //     }
    // }
    // std::cout << "Not identical." << std::endl;
    // zad 10.
    bool occurrences[26] = {false};
    int left = 0, maxLength = 0;
    for (size_t right = 0; right < size; right++)
    {
        int index = arr[right] - 'a';
        while (occurrences[index])
        {
            occurrences[arr[left] - 'a'] = false;
            left++;
        }
        occurrences[index] = true;
        maxLength = std::max(maxLength, static_cast<int>(right - left + 1));
    }
    std::cout << "Max length: " << maxLength << std::endl;
    return 0;
}
size_t readArray(int *arr)
{
    size_t size;
    std::cout << "Enter the number of elements (max " << MAX_SIZE << "): ";
    std::cin >> size;
    if (size > MAX_SIZE)
    {
        std::cout << "Size exceeds maximum limit. Setting size to " << MAX_SIZE << "." << std::endl;
        size = MAX_SIZE;
    }
    std::cout << "Enter " << size << " elements:" << std::endl;
    for (size_t i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }
    return size;
}
size_t printArray(const int *arr, size_t size)
{
    std::cout << "[ ";
    for (size_t i = 0; i < size - 1; ++i)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[size - 1] << " ]" << std::endl;
    return size;
}