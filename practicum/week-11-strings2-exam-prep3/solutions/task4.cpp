#include <cstring>
#include <stdexcept>
#include <iostream>

void appendCharacter(char *&str, size_t &capacity, size_t &size, char c)
{
    if (size + 1 >= capacity)
    {
        capacity *= 2;
        char *temp = new char[capacity];
        strcpy_s(temp, capacity, str);
        delete[] str;
        str = temp;
    }
    str[size++] = c;
    str[size] = '\0';
}

void decompressEscape(const char *&ptr, char *&result, size_t &resultCapacity, size_t &resultSize)
{
    if (*ptr != '\\')
    {
        throw std::runtime_error("Invalid function call: *ptr must be escape character ( \\ )");
    }

    ptr++;
    if (*ptr == '\0')
        throw std::runtime_error("Escape at end of string");
    appendCharacter(result, resultCapacity, resultSize, *ptr);
    ptr++;
}

void decompressString(const char *&ptr, char *&result, size_t &resultCapacity, size_t &resultSize)
{
    if (*ptr != '"')
    {
        throw std::runtime_error("Invalid function call: *ptr must be beginning of compressed string ( \" )");
    }

    ptr++;
    while (*ptr != '"')
    {
        if (*ptr == '\0')
        {
            throw std::runtime_error("Invalid string: no closing ( \" )");
        }
        if (*ptr == '\\')
        {
            decompressEscape(ptr, result, resultCapacity, resultSize);
            continue;
        }
        appendCharacter(result, resultCapacity, resultSize, *ptr);
        ptr++;
    }
    ptr++;
}

int numberThanBrace(const char *ptr)
{
    bool found = false;
    int result = 0;
    while (*ptr >= '0' && *ptr <= '9')
    {
        found = true;
        result = result * 10 + (*ptr - '0');
        ptr++;
    }
    if (*ptr != '(')
    {
        found = false;
    }

    return found ? result : -1;
}

void decompressGroup(const char *&ptr, char *&result, size_t &resultCapacity, size_t &resultSize)
{
    int n = numberThanBrace(ptr);
    if (n == -1)
    {
        throw std::runtime_error("Invalid function call: *ptr must be beginning of group");
    }
    while (*ptr >= '0' && *ptr <= '9')
    {
        ptr++;
    }
    // skip (
    ptr++;

    size_t tempCap = 16;
    size_t tempSize = 0;
    char *temp = new char[tempCap];
    temp[0] = '\0';
    while (*ptr != ')')
    {
        if (*ptr == '\0')
        {
            delete[] temp;
            throw std::runtime_error("Invalid string: no closing \")\"");
        }
        if (*ptr == '"')
        {
            decompressString(ptr, temp, tempCap, tempSize);
            continue;
            ;
        }
        if (*ptr == '\\')
        {
            decompressEscape(ptr, temp, tempCap, tempSize);
            continue;
        }
        if (numberThanBrace(ptr) >= 0)
        {
            decompressGroup(ptr, temp, tempCap, tempSize);
            continue;
        }
        appendCharacter(temp, tempCap, tempSize, *ptr);
        ptr++;
    }
    ptr++; // skip ')'

    for (int i = 0; i < n; i++)
    {
        for (size_t j = 0; j < tempSize; j++)
        {
            appendCharacter(result, resultCapacity, resultSize, temp[j]);
        }
    }
    delete[] temp;
}

char *decompress(const char *str)
{
    const char *ptr = str;
    size_t resultCapacity = strlen(str) + 1;
    size_t resultSize = 0;
    char *result = new char[resultCapacity];
    result[0] = '\0';
    while (*ptr)
    {
        if (*ptr == '"')
        {
            decompressString(ptr, result, resultCapacity, resultSize);
            continue;
            ;
        }
        if (*ptr == '\\')
        {
            decompressEscape(ptr, result, resultCapacity, resultSize);
            continue;
        }
        if (numberThanBrace(ptr) >= 0)
        {
            decompressGroup(ptr, result, resultCapacity, resultSize);
            continue;
        }
        appendCharacter(result, resultCapacity, resultSize, *ptr);
        ptr++;
    }
    return result;
}

int main()
{
    const char *tests[] = {
        "AABC",
        "A\\BC",
        "R2(AB)3(Z)",
        "A\"3(Zs)\"3(Zs)",
        "R2(A\\2B)3(Z)",
        "AB12(X)2(B3(A))",
        "AB12(X)2(B3(A\"2'1\"))",
        "A\"\\\"BC\""};

    for (const char *t : tests)
    {
        char *r = decompress(t);
        std::cout << t << " -> " << r << std::endl;
        delete[] r;
    }
    return 0;
}