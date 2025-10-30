#include <iostream>

int main()
{
    unsigned n, m;
    std::cin >> n >> m;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            bool bit = i == 0 || i == n - 1 || j == 0 || j == m - 1;
            std::cout << bit << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            bool bit = i + j >= n - 1;
            std::cout << bit << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}