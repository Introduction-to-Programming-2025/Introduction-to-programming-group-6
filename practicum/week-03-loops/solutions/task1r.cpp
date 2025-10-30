#include <iostream>
int main()
{
    unsigned long long n;
    std::cin >> n;
    unsigned long long sum_even = 0;
    unsigned long long sum_odd = 0;
    unsigned short position = 1;
    while (n > 0)
    {
        unsigned short digit = n % 10;
        if (position % 2 == 0)
        {
            sum_even += digit;
        }
        else
        {
            sum_odd += digit;
        }
        n /= 10;
        position++;
    }
    std::cout << "Odd: " << sum_odd << std::endl;
    std::cout << "Even: " << sum_even << std::endl;
    return 0;
}