#include <iostream>

int main()
{
    unsigned n;
    std::cin >> n;
    unsigned sum = 0;
    while (n > 9)
    {
        while (n)
        {
            sum += n % 10;
            n /= 10;
        }
        n = sum;
        sum = 0;
        if (n > 9)
        {
            std::cout << n << " -> ";
        }
    }
    std::cout << n << std::endl;
    return 0;
}