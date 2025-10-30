#include <iostream>
#include <cmath>
int main()
{
    unsigned n;
    std::cin >> n;
    for (unsigned i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            std::cout << ' ';
        }

        for (int j = 0; j <= i; j++)
        {
            char c = 'A' + std::min(j, (int)i - j);
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}