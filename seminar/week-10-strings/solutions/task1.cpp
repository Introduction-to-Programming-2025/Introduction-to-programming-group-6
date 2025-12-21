#include <iostream>

using namespace std;

// 1. my_strlen: Връща дължината на низа
unsigned int my_strlen(const char* str) {
    unsigned int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// 2. my_strcmp: Сравнява два низа лексикографски
// Връща 0 ако са равни, <0 ако s1 е преди s2, >0 ако s1 е след s2
int my_strcmp(const char* s1, const char* s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    // Връща разликата между първите различни символи
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

// 3. my_strcpy: Копира src в dest. Връща указател към dest.
char* my_strcpy(char* dest, const char* src) {
    char* originalDest = dest;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; // Не забравяме терминиращия символ
    return originalDest;
}

// 4. my_strcat: Залепя src към края на dest. Връща dest.
char* my_strcat(char* dest, const char* src) {
    char* ptr = dest;
    
    // Намираме края на dest
    while (*ptr != '\0') {
        ptr++;
    }

    // Копираме src от края на dest
    while (*src != '\0') {
        *ptr = *src;
        ptr++;
        src++;
    }
    *ptr = '\0'; // Терминираме
    return dest;
}

// 5. my_strstr: Търси първото срещане на needle в haystack
const char* my_strstr(const char* haystack, const char* needle) {
    if (*needle == '\0') {
        return haystack; // Празен needle се намира винаги в началото
    }

    for (int i = 0; haystack[i] != '\0'; i++) {
        // Проверка дали съвпада от текущата позиция
        int j = 0;
        while (needle[j] != '\0' && haystack[i + j] == needle[j]) {
            j++;
        }
        
        // Ако сме стигнали края на needle, значи сме намерили съвпадение
        if (needle[j] == '\0') {
            return &haystack[i];
        }
    }
    return nullptr; // Не е намерен
}

// 6. my_atoi: Преобразува низ в цяло число
int my_atoi(const char* str) {
    int res = 0;
    int sign = 1;
    int i = 0;

    // Прескачане на водещи празни пространства
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
        i++;
    }

    // Проверка за знак
    if (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-') sign = -1;
        i++;
    }

    // Преобразуване на цифрите
    while (str[i] >= '0' && str[i] <= '9') {
        res = res * 10 + (str[i] - '0');
        i++;
    }

    return res * sign;
}

// Помощна функция за обръщане на низ (нужна за itoa)
void reverse_str(char* str, int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// 7. my_itoa: Преобразува число в низ (в дадена бройна система, стандартно 10)
char* my_itoa(int value, char* str, int base) {
    int i = 0;
    bool isNegative = false;

    // Валидация за базата (стандартно itoa поддържа бази от 2 до 36)
    if (base < 2 || base > 36) {
        *str = '\0';
        return str;
    }

    // Обработка на 0
    if (value == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    // Обработка на отрицателни числа (само за десетична бройна система)
    if (value < 0 && base == 10) {
        isNegative = true;
        value = -value;
    }

    // Извличане на цифрите
    while (value != 0) {
        int rem = value % base;
        // Ако rem > 9, използваме букви (a-z)
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        value = value / base;
    }

    // Добавяне на минус, ако е необходимо
    if (isNegative) {
        str[i++] = '-';
    }

    str[i] = '\0'; // Терминиране на низа

    // Низа е наобратно, трябва да го обърнем
    reverse_str(str, i);

    return str;
}

int main() {
    // ТЕСТОВЕ НА ФУНКЦИИТЕ

    // 1. Тест my_strlen
    const char* text = "Hello World";
    cout << "1. my_strlen ('" << text << "') = " << my_strlen(text) << endl;

    // 2. Тест my_strcmp
    const char* s1 = "Apple";
    const char* s2 = "Banana";
    const char* s3 = "Apple";
    cout << "2. my_strcmp ('Apple', 'Banana') = " << my_strcmp(s1, s2) << " (Negative expected)" << endl;
    cout << "   my_strcmp ('Apple', 'Apple')  = " << my_strcmp(s1, s3) << " (0 expected)" << endl;

    // 3. Тест my_strcpy
    char buffer[50];
    my_strcpy(buffer, "Copy This");
    cout << "3. my_strcpy result: " << buffer << endl;

    // 4. Тест my_strcat
    my_strcat(buffer, " And This");
    cout << "4. my_strcat result: " << buffer << endl;

    // 5. Тест my_strstr
    const char* haystack = "This is a simple example";
    const char* needle = "simple";
    const char* result = my_strstr(haystack, needle);
    if (result) {
        cout << "5. my_strstr found substring starting at: " << result << endl;
    } else {
        cout << "5. my_strstr not found." << endl;
    }

    // 6. Тест my_atoi
    const char* numStr = "   -12345 abc";
    cout << "6. my_atoi ('   -12345 abc') = " << my_atoi(numStr) << endl;

    // 7. Тест my_itoa
    char numBuffer[20];
    int number = -4567;
    my_itoa(number, numBuffer, 10);
    cout << "7. my_itoa (-4567, base 10) = " << numBuffer << endl;
    
    my_itoa(255, numBuffer, 16);
    cout << "   my_itoa (255, base 16)   = " << numBuffer << endl;

    return 0;
}
