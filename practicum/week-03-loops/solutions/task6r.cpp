#include <iostream>

int main()
{
    unsigned n;
    std::cin >> n;
    unsigned cnt = 1;
    for (size_t i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (size_t j = 0; j < n; j++)
            {
                std::cout << i * n + j + 1 << ' ';
                cnt++;
            }
        }
        else
        {
            for (int j = n; j > 0; j--)
            {
                std::cout << i * n + j << ' ';
            }
        }
        std::cout << std::endl;
    }
    return 0;
}