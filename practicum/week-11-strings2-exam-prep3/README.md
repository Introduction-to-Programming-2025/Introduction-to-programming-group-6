# Седмица 11 - Символни низове и подготовка за контролно 3

[Github assignment](https://classroom.github.com/a/b-IpKfEo)

## Задачи за анализ на генериран код

### Задача 1

Дадена е следната програма генерирана от ИИ, чиято цел е да направи матрицата "гладка". Гладка матрица е таквава, която всеки елемент е средноаритметично между него и съседите си(ляв, десен, горен и долен).
Намерете и оправете грешките.
Спазени ли са добрите практики?

```cpp
#include <iostream>

void smoothGrid(int** grid, int rows, int cols) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int sum = grid[i][j] +
                      grid[i-1][j] + grid[i+1][j] +
                      grid[i][j-1] + grid[i][j+1];

            grid[i][j] = sum / 5;
        }
    }
}

int main() {
    int r = 3, c = 3;
    int** map = new int*[rows];

    for (int i = 0; i < r; i++) {
        std::cout << "Enter " << c << " values for row " << i << ": ";

        for (int j = 0; j < c; j++) {
            std::cin >> map[i][j];
        }
    }

    smoothGrid(map, r, c);

    return 0;
}
```

### Задача 2

Дадена е следната програма написана от ИИ с цел да извлече информация от масив от "CSV" форматирани низове(разделени с запетая). Целта е резултатът да е двумерна матрица от низове, за всеки ред всяко всяко поле е съответното свойство от csv - стринга.

- Коректна ли е?
- Има ли течове на памет?
- Поправете грешките.

```c
#include <iostream>
#include <cstring>

char** splitLine(const char* line, int& count) {
    if (!line) return nullptr;

    count = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == ',') count++;
    }
    count++;

    char** words = new char*[count];
    int start = 0, wordIdx = 0, n = strlen(line);

    for (int i = 0; i <= n; i++) {
        if (line[i] == ',' || line[i] == '\0') {
            int len = i - start;

            words[wordIdx] = new char[len];

            for (int j = 0; j < len; j++) {
                words[wordIdx][j] = line[start + j];
            }

            wordIdx++;
            start = i + 1;
        }
    }
    return words;
}

char*** parseCSVWithHeader(const char** data, int totalRows, int& effectiveRows, int& expectedCols) {
    int headerCols = 0;
    splitLine(data[0], headerCols);

    expectedCols = headerCols;
    effectiveRows = totalRows - 1;
    char*** table = new char**[effectiveRows];

    for (int i = 1; i < totalRows; i++) {
        int currentCols = 0;
        table[i] = splitLine(data[i], currentCols);

        if (currentCols != expectedCols) {
            std::cout << "Warning: Row " << i << " mismatch!\n";
        }
    }
    return table;
}

void cleanUp(char*** table, int rows, int cols) {
    if (!table) return;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            delete[] table[i][j];
        }
        delete[] table[i];
    }
}
char** readInputData(int& count) {
    std::cout << "Колко реда ще въвеждате? ";
    std::cin >> count;

    char** rawData = new char*[count];

    for (int i = 0; i < count; i++) {
        char buffer[100];
        std::cout << "Въведете ред " << i + 1 << " (Format: Name,Age,City): ";
        std::cin >> buffer;

        rawData[i] = new char[strlen(buffer) + 1];
        strcpy(rawData[i], buffer);
    }

    return rawData;
}
int main() {
    char** csvData = readInputData(rowCount);

    int rows = 4, effRows = 0, cols = 0;
    char*** result = parseCSVWithHeader(csv, rows, effRows, cols);

    for (int i = 0; i < effRows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    cleanUp(result, effRows, cols);
    return 0;
}
```

## Задачи за символни низове

### Задача 3

Функция, която приема символен низ - изречение от думи разделени с интервал. Функцията да връща ново изречение състоящо се само от уникалните думи в изречението сортирани по брой на гласните в тях, при равен брой гласни - лексикографски.

```cpp
IN: "The quick brown aaa fox bbb jumps bbb over the ccc lazy dog eee"
OUT: "aaa eee lazy over quick brown dog fox jumps ccc"
```

### Задача 4

Напишете функция, която приема "компресиран" низ и извежда декомпресираната му версия. Ако низът не е записан коректно трябва да съобщите това. Низът може да съдържа:

- Символи (всякакви символи, различни от двойна кавичка, скоби, цифри и наклонена черта ‘\’)
- Escape символи - наклонена черта, следвана от произволен символ. Така в компресираният низ може да се сложат специални символи. Например: a\"-> a".
- Групи, които започват с число последвано от скоби, съдържащи компресиран низ. Декомпресират се като се декомпресира низа в скобите и се повтори толкова пъти колкото е числото.
- Стрингове - последователност от произволни символи, оградени с двойни кавички - пренася се в декомпресираната версия непроменена, но без кавичките. В тази последователност се допускат escape-нати кавички.

```cpp
AABC -> AABC
A\BC -> ABC
R2(AB)3(Z) -> RABABZZZ
A"3(Zs)"3(Zs) -> A3(Zs)ZsZsZs
R2(A\2B)3(Z) -> RA2BA2BZZZ
AB12(X)2(B3(A)) -> ABXXXXXXXXXXXXBAAABAAA
AB12(X)2(B3(A"2'1")) -> ABXXXXXXXXXXXXBA2'1A2'1A2'1BA2'1A2'1A2'1
A"\"BC" -> A"BC
```
