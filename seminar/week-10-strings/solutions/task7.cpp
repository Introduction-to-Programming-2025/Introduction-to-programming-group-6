#include <iostream>
#include <cstring>

using namespace std;

int analyzeMatrix(const char* matrix, int n, const char* str) {
    // 1. Проверка дали матрицата е опростена (елементи между 'a' и 'z')
    for (int i = 0; i < n * n; ++i) {
        if (matrix[i] < 'a' || matrix[i] > 'z') {
            return -1; // Сигнализираме, че матрицата не е валидна
        }
    }

    int len = strlen(str);
    if (len == 0 || len > n) {
        return 0; // Ако низът е празен или по-дълъг от размера на матрицата
    }

    int count = 0;

    // 2. Обхождане по Редове
    for (int r = 0; r < n; ++r) {
        // Можем да започнем проверка само до индекс n - len
        for (int c = 0; c <= n - len; ++c) {
            
            // Проверка: Ляво -> Дясно
            bool matchRight = true;
            for (int k = 0; k < len; ++k) {
                if (matrix[r * n + (c + k)] != str[k]) {
                    matchRight = false;
                    break;
                }
            }
            if (matchRight) count++;

            // Проверка: Дясно -> Ляво (Обратна посока)
            // Започваме от края на текущия отрязък и вървим назад
            bool matchLeft = true;
            for (int k = 0; k < len; ++k) {
                if (matrix[r * n + (c + len - 1 - k)] != str[k]) {
                    matchLeft = false;
                    break;
                }
            }
            if (matchLeft) count++;
        }
    }

    // 3. Обхождане по Колони
    for (int c = 0; c < n; ++c) {
        // Можем да започнем проверка само до ред n - len
        for (int r = 0; r <= n - len; ++r) {
            
            // Проверка: Горе -> Долу
            bool matchDown = true;
            for (int k = 0; k < len; ++k) {
                if (matrix[(r + k) * n + c] != str[k]) {
                    matchDown = false;
                    break;
                }
            }
            if (matchDown) count++;

            // Проверка: Долу -> Горе (Обратна посока)
            bool matchUp = true;
            for (int k = 0; k < len; ++k) {
                if (matrix[(r + len - 1 - k) * n + c] != str[k]) {
                    matchUp = false;
                    break;
                }
            }
            if (matchUp) count++;
        }
    }

    return count;
}

int main() {
    int n;
    
    // Въвеждане на размера n
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid size!" << endl;
        return 1;
    }

    // Динамично заделяне на памет за матрицата (като плосък масив)
    char* matrix = new char[n * n];

    // Въвеждане на елементите
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i * n + j];
        }
    }

    // Въвеждане на търсения низ
    // Заделяме буфер. Приемаме, че низът няма да е по-дълъг от 100 за този пример.
    char searchStr[101];
    cout << "Enter search string: ";
    cin.get(); //Тъй като използваме cin по-рано, в буфера имаме останал '\n'. С това взимаме този елемент от буфера.
    //По-добра практика е да се използва само cin.getline, вместо да се редуват cin >> и cin.getline(). В случая просто беше по-лесно за въвеждане на матрицата.
    cin.getline(searchStr, 101);

    // Извикване на функцията
    int result = analyzeMatrix(matrix, n, searchStr);

    // Извеждане на резултата
    if (result == -1) {
        cout << "Not simplified!" << endl;
    } else {
        cout << "Times met: " << result << endl;
    }

    // Освобождаване на паметта
    delete[] matrix;

    return 0;
}
