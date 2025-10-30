#include <iostream>
int main()
{
    double n, m;
    char op;
    std::cin >> n >> op;
    do
    {
        std::cin >> m;
        switch (op)
        {
        case '+':
            n = n + m;
            break;
        case '-':
            n = n - m;
            break;
        case '*':
            n = n * m;
            break;
        case '/':
            if (m != 0)
            {
                n = n / m;
            }
            else
            {
                std::cout << "Error: Division by zero!" << std::endl;
                return 1;
            }
            break;
        default:
            std::cout << "Error: Unknown operation, these numbers will be ignored" << std::endl;
        }
        std::cin >> op;
    } while (op != '=');
    std::cout << n << std::endl;
    return 0;
}