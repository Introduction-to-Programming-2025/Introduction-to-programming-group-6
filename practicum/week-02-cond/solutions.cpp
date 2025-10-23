#include <iostream>
#include <cmath>

int main()
{
    // Зад. 1
    // int ref, a, b, c;
    // std::cin >> ref >> a >> b >> c;
    // int ra = ref - a >= 0 ? ref - a : a - ref;
    // int rb = ref - b >= 0 ? ref - b : b - ref;
    // int rc = ref - c >= 0 ? ref - c : c - ref;
    // if (ra <= rb && ra <= rc)
    // {
    //     std::cout << a << std::endl;
    // }
    // else if (rb <= ra && rb <= rc)
    // {
    //     std::cout << b << std::endl;
    // }
    // else
    // {
    //     std::cout << c << std::endl;
    // }
    // Зад. 2
    // char letter;
    // std::cin >> letter;
    // if (letter >= 'A' && letter <= 'Z')
    // {
    //     letter += 'a' - 'A';
    // }
    // switch (letter)
    // {
    // case 'a':
    // case 'e':
    // case 'i':
    // case 'o':
    // case 'u':
    //     std::cout << "Vowel" << std::endl;
    //     break;
    // default:
    //     std::cout << "Consonant" << std::endl;
    //     break;
    // }
    // return 0;
    // Зад. 3
    // int a, b, c;
    // std::cin >> a >> b >> c;
    // if (a == b && b == c)
    // {
    //     std::cout << "Equilateral" << std::endl;
    // }
    // else if (a == b || b == c || a == c)
    // {
    //     std::cout << "Isosceles" << std::endl;
    // }
    // else
    // {
    //     std::cout << "Scalene" << std::endl;
    // }
    // char p1, p2;
    // std::cin >> p1 >> p2;
    // if ((p1 == 'r' && p2 == 's') || (p1 == 's' && p2 == 'p') || (p1 == 'p' && p2 == 'r'))
    // {
    //     std::cout << "Player 1 wins!" << std::endl;
    // }
    // else if (p1 == p2)
    // {
    //     std::cout << "Draw!" << std::endl;
    // }
    // else
    // {
    //     std::cout << "Player 2 wins!" << std::endl;
    // }
    // Зад. 5
    // int wage = 1077;
    // unsigned budget, people;
    // std::cin >> budget >> people;
    // if (budget >= wage * people)
    // {
    //     std::cout << "Budget is enough!" << std::endl;
    // }
    // else
    // {
    //     std::cout << "We need to fire " << (wage * people - budget) / wage + ((wage * people - budget) % wage != 0) << " people" << std::endl;
    // }
    // Зад. 6
    // char figure;
    // std::cin >> figure;
    // double area;
    // switch (figure)
    // {
    // case 'R':{
    //     double length, width;
    //     std::cin >> length >> width;
    //     area = length * width;
    //     break;
    // }
    // case 'C':{
    //     double radius;
    //     std::cin >> radius;
    //     area = 3.14 * radius * radius;
    //     break;
    // }
    // case 'T':{
    //     double a, b, height;
    //     std::cin >> a >> b >> height;
    //     area = 0.5 * (a + b) * height;
    //     break;
    // }
    // case '3':{
    //     double a, h;
    //     std::cin >> a >> h;
    //     area = a * h / 2;
    //     break;
    // }
    // default:
    //     std::cout << "Unknown figure!" << std::endl;
    //     break;
    // }
    // std::cout << "Area: " << area << std::endl;
    // Зад. 7
    // double x, y;
    // char axis;
    // std::cin >> x >> y >> axis;
    // switch (axis)
    // {
    // case 'x':
    //     x = -x;
    //     break;
    // case 'y':
    //     y = -y;
    //     break;
    // case 'b':

    //     x = -x;
    //     y = -y;
    //     break;
    // }
    // std::cout << "New coordinates: (" << x << ", " << y << ")" << std::endl;
    // Зад. 8
    // int hh, mm, chh, cmm;
    // std::cin >> hh >> mm >> chh >> cmm;
    // mm -= cmm;
    // if (mm < 0)
    // {
    //     mm += 60;
    //     hh--;
    // }
    // hh -= chh;
    // if (hh < 0)
    // {
    //     hh += 24;
    // }
    // if (hh < 10)
    // {
    //     std::cout << '0';
    // }
    // std::cout << hh << ':';
    // if (mm < 10)
    // {
    //     std::cout << '0';
    // }
    // std::cout << mm << std::endl;
    // Зад. 9
    double x, y;
    std::cin >> x >> y;
    double xA = -2, yA = -4;
    double xB = 0, yB = -1;
    double xC = 6, yC = -2;
    double a = sqrt((xB - xA) * (xB - xA) + (yB - yA) * (yB - yA));
    double b = sqrt((xC - xB) * (xC - xB) + (yC - yB) * (yC - yB));
    double c = sqrt((xA - xC) * (xA - xC) + (yA - yC) * (yA - yC));
    double p = (a + b + c) / 2;
    double areaABC = sqrt(p * (p - a) * (p - b) * (p - c));
    double a1 = sqrt((x - xA) * (x - xA) + (y - yA) * (y - yA));
    double b1 = sqrt((x - xB) * (x - xB) + (y - yB) * (y - yB));
    double c1 = sqrt((x - xC) * (x - xC) + (y - yC) * (y - yC));
    double p1 = (a1 + a + b1) / 2;
    double areaPAB = sqrt(p1 * (p1 - a) * (p1 - a1) * (p1 - b1));
    double p2 = (b1 + b + c1) / 2;
    double areaPBC = sqrt(p2 * (p2 - b) * (p2 - b1) * (p2 - c1));
    double p3 = (c1 + c + a1) / 2;
    double areaPCA = sqrt(p3 * (p3 - c) * (p3 - c1) * (p3 - a1));
    double eps = 0.000001;
    std::cout << (fabs(areaABC - (areaPAB + areaPBC + areaPCA)) < eps) << std::endl;

    return 0;
}