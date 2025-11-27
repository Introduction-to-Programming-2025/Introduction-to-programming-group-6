#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

const size_t ROWS = 10;
const size_t COLS = 10;

// utility functions
void readMatrix(int arr[][COLS], size_t &n, size_t &m)
{
    std::cin >> n >> m;
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j)
        {
            std::cin >> arr[i][j];
        }
    }
}
void printMatrix(int arr[][COLS], size_t n, size_t m)
{
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 1
int maxInDiagonal(int arr[][COLS], size_t n, size_t m)
{
    int maxVal = arr[0][0];
    size_t limit = (n < m) ? n : m;
    for (size_t i = 0; i < limit; ++i)
    {
        if (arr[i][i] > maxVal)
        {
            maxVal = arr[i][i];
        }
        if (arr[i][m - 1 - i] > maxVal)
        {
            maxVal = arr[i][m - 1 - i];
        }
    }

    return maxVal;
}

void transposeMatrix(int arr[][COLS], size_t n, size_t m)
{
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = i + 1; j < m; ++j)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
}
void reverseRows(int arr[][COLS], size_t n, size_t m)
{
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m / 2; ++j)
        {
            swap(arr[i][j], arr[i][m - 1 - j]);
        }
    }
}
// 2
void rotateMatrix90Degrees(int arr[][COLS], size_t n, size_t m)
{
    transposeMatrix(arr, n, m);
    reverseRows(arr, n, m);
}

// 3
void maxSumRowToRowOne(int arr[][COLS], size_t n, size_t m)
{
    size_t maxSumRowIndex = 0;
    int maxSum = INT_MIN;

    for (size_t i = 0; i < n; ++i)
    {
        int currentRowSum = 0;
        for (size_t j = 0; j < m; ++j)
        {
            currentRowSum += arr[i][j];
        }
        if (currentRowSum > maxSum)
        {
            maxSum = currentRowSum;
            maxSumRowIndex = i;
        }
    }

    if (maxSumRowIndex != 0)
    {
        for (size_t j = 0; j < m; ++j)
        {
            swap(arr[0][j], arr[maxSumRowIndex][j]);
        }
    }
}
// 4
void sortColumnsBySum(int arr[][COLS], size_t n, size_t m)
{
    int columnSums[COLS] = {0};

    for (size_t j = 0; j < m; ++j)
    {
        for (size_t i = 0; i < n; ++i)
        {
            columnSums[j] += arr[i][j];
        }
    }

    for (size_t j = 0; j < m - 1; j++)
    {
        bool swapped = false;
        for (size_t k = 0; k < m - j - 1; ++k)
        {
            if (columnSums[k] < columnSums[k + 1])
            {
                swap(columnSums[k], columnSums[k + 1]);
                for (size_t i = 0; i < n; ++i)
                {
                    swap(arr[i][k], arr[i][k + 1]);
                }
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}

// 5
unsigned numberOfAliveNeighbors(int arr[][COLS], size_t n, size_t m, size_t row, size_t col)
{
    int aliveCount = 0;
    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            if (i == 0 && j == 0)
                continue;

            int neighborRow = row + i;
            int neighborCol = col + j;

            if (neighborRow >= 0 && neighborRow < n && neighborCol >= 0 && neighborCol < m && (arr[neighborRow][neighborCol] == 1 || arr[neighborRow][neighborCol] == 3))
            {
                aliveCount += 1;
            }
        }
    }
    return aliveCount;
}

void conwayGameOfLifeStep(int arr[][COLS], size_t n, size_t m)
{
    // 0 - dead cell
    // 1 - alive cell
    // 2 - dead but will become alive
    // 3 - alive but will die

    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j)
        {
            unsigned aliveNeighbors = numberOfAliveNeighbors(arr, n, m, i, j);

            if (arr[i][j] == 1)
            {
                if (aliveNeighbors < 2 || aliveNeighbors > 3)
                {
                    arr[i][j] = 3;
                }
            }
            else
            {
                if (aliveNeighbors == 3)
                {
                    arr[i][j] = 2;
                }
            }
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (arr[i][j] == 2)
            {
                arr[i][j] = 1;
            }
            else if (arr[i][j] == 3)
            {
                arr[i][j] = 0;
            }
        }
    }
}

void conwayGameOfLife(int arr[][COLS], size_t n, size_t m, size_t steps)
{
    for (size_t step = 0; step < steps; ++step)
    {
        conwayGameOfLifeStep(arr, n, m);
        std::cout << "----" << std::endl;
        std::cout << "GEN: " << step + 1 << ":" << std::endl;
        printMatrix(arr, n, m);
        std::cout << "----" << std::endl;
    }
}

// 6
void matrixNxMLayers(int matrix[][COLS], unsigned n, unsigned m)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            matrix[i][j] = min(min(i, j), min(n - 1 - i, m - 1 - j)) + 1;
        }
    }
}
// 7
int maxSubmatrixSum(int matrix[][COLS], int rows, int cols, int m, int n)
{
    int maxSum = INT_MIN;

    for (int i = 0; i <= rows - m; i++)
    {
        for (int j = 0; j <= cols - n; j++)
        {
            int currentSum = 0;

            for (int x = 0; x < m; x++)
            {
                for (int y = 0; y < n; y++)
                {
                    currentSum += matrix[i + x][j + y];
                }
            }

            if (currentSum > maxSum)
                maxSum = currentSum;
        }
    }

    return maxSum;
}
int reverseColmn(int arr[][COLS], size_t n, size_t col)
{
    for (size_t i = 0; i < n / 2; ++i)
    {
        swap(arr[i][col], arr[n - 1 - i][col]);
    }
    return 0;
}
// 8
void rotateMatrixColmnsKTimes(int arr[][COLS], size_t n, size_t m, size_t k)
{
    k = k % m;
    for (size_t step = 0; step < k; step++)
    {
        for (size_t i = 0; i < n; i++)
        {
            int temp = arr[i][m - 1];
            for (int j = m - 1; j > 0; j--)
            {
                arr[i][j] = arr[i][j - 1];
            }
            arr[i][0] = temp;
        }
    }
    for (size_t i = 1; i < m; i += 2)
    {
        reverseColmn(arr, n, i);
    }
}

int main()
{
    int array[ROWS][COLS];
    size_t n, m;
    readMatrix(array, n, m);
    rotateMatrixColmnsKTimes(array, n, m, 1);
    printMatrix(array, n, m);

    // printMatrix(array, n, m);
    // int matrix[10][10] = {
    //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // conwayGameOfLife(matrix, 10, 10, 8);

    return 0;
}