#include <iostream>

int main()
{
    int a, b;
    int num = 0, den = 1;
    do
    {
        std::cin >> a;
        if (a == 0)
            break;
        std::cin >> b;
        if (b == 0)
            break;
        if (b < 0)
        {
            b = -b;
            a = -a;
        }
        num = num * b + den * a;
        den = den * b;
        unsigned x = num < 0 ? -num : num;
        unsigned y = den;
        while (y != 0)
        {
            unsigned r = x % y;
            x = y;
            y = r;
        }
        num /= x;
        den /= x;

    } while (a != 0 && b != 0);
    std::cout << num / den << " и " << num % den << "/" << den << std::endl;
    return 0;
}