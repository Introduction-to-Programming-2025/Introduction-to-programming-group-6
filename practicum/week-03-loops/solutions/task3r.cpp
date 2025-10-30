#include <iostream>
int main()
{
    unsigned a, b, k, sum = 0;
    std::cin >> a >> b >> k;
    for (size_t i = a; i <= b; i += k)
    {
        sum += i;
    }
    std::cout << sum << std::endl;
    return 0;
}