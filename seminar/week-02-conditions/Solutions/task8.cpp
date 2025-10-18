#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;

    if (num < 10 || num > 99) {
        cout << "Invalid number" << endl;
        return 0;
    }

    int tens = num / 10;
    int ones = num % 10;

    if (num >= 10 && num <= 19) {
        switch (num) {
            case 10: cout << "ten"; break;
            case 11: cout << "eleven"; break;
            case 12: cout << "twelve"; break;
            case 13: cout << "thirteen"; break;
            case 14: cout << "fourteen"; break;
            case 15: cout << "fifteen"; break;
            case 16: cout << "sixteen"; break;
            case 17: cout << "seventeen"; break;
            case 18: cout << "eighteen"; break;
            case 19: cout << "nineteen"; break;
        }
    }
    else {
        switch (tens) {
            case 2: cout << "twenty"; break;
            case 3: cout << "thirty"; break;
            case 4: cout << "forty"; break;
            case 5: cout << "fifty"; break;
            case 6: cout << "sixty"; break;
            case 7: cout << "seventy"; break;
            case 8: cout << "eighty"; break;
            case 9: cout << "ninety"; break;
        }

        if (ones != 0) {
            cout << " ";
            switch (ones) {
                case 1: cout << "one"; break;
                case 2: cout << "two"; break;
                case 3: cout << "three"; break;
                case 4: cout << "four"; break;
                case 5: cout << "five"; break;
                case 6: cout << "six"; break;
                case 7: cout << "seven"; break;
                case 8: cout << "eight"; break;
                case 9: cout << "nine"; break;
            }
        }
    }

    cout << endl;
    return 0;
}
