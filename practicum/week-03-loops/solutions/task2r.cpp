#include <iostream>
#include <cmath>
int main()
{
    unsigned n;
    std::cin >> n;

    int prime = 2;
    while (n > 1)
    {
        if (n % prime == 0)
        {
            std::cout << prime;
            n /= prime;
            if (n != 1)
            {
                std::cout << " * ";
            }
        }
        else
        {
            prime++;
        }
    }
    return 0;
}