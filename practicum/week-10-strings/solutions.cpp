#include <iostream>
#include <cstring>
#include <stdexcept>
#include <climits>

using namespace std;
char *toUpperCase(char *str)
{
    if (!str || str[0] == '\0')
        throw std::runtime_error("Input string is null or empty");

    char *ptr = str;

    while (*ptr)
    {
        if (*ptr >= 'a' && *ptr <= 'z')
            *ptr = *ptr - ('a' - 'A');
        ptr++;
    }

    return str;
}

char *trim(char *str)
{
    if (str == nullptr || str[0] == '\0')
    {
        throw std::runtime_error("Input string is null or empty");
    }

    char *start = str;
    while (*start == ' ')
    {
        start++;
    }

    if (*start == '\0')
    {
        str[0] = '\0';
        return str;
    }

    char *end = start + strlen(start) - 1;
    while (end > start && *end == ' ')
    {
        end--;
    }
    *(end + 1) = '\0';

    if (start != str)
    {
        char *dest = str;
        while (*start)
        {
            *dest++ = *start++;
        }
        *dest = '\0';
    }
    return str;
}

int biggestNumberInString(const char *str)
{
    if (str == nullptr || str[0] == '\0')
    {
        throw std::runtime_error("Input string is null or empty");
    }

    int maxNum = INT_MIN;
    const char *ptr = str;

    while (*ptr)
    {
        if ((*ptr >= '0' && *ptr <= '9') ||
            (*ptr == '-' && *(ptr + 1) >= '0' && *(ptr + 1) <= '9'))
        {
            bool isNegative = false;

            if (*ptr == '-')
            {
                isNegative = true;
                ptr++;
            }

            int num = 0;

            while (*ptr >= '0' && *ptr <= '9')
            {
                num = num * 10 + (*ptr - '0');
                ptr++;
            }

            if (isNegative)
                num = -num;

            if (num > maxNum)
                maxNum = num;
        }
        else
        {
            ptr++;
        }
    }

    return maxNum;
}

char *replaceLastOccurrence(char *str, char *substr, char *replacement)
{
    if (str == nullptr || substr == nullptr || replacement == nullptr)
    {
        throw std::runtime_error("One or more input strings are null");
    }

    char *lastPos = nullptr;
    char *currentPos = str;
    while (*currentPos)
    {
        char *tempStr = currentPos;
        char *tempSubstr = substr;
        while (*tempStr && *tempSubstr && *tempStr == *tempSubstr)
        {
            tempStr++;
            tempSubstr++;
        }
        if (*tempSubstr == '\0')
        {
            lastPos = currentPos;
        }
        currentPos++;
    }

    if (lastPos != nullptr)
    {
        char *before = str;
        char *buffer = new char[strlen(str) - strlen(substr) + strlen(replacement) + 1];
        char *bufPtr = buffer;
        char *after = lastPos + strlen(substr);
        while (before < lastPos)
        {
            *bufPtr++ = *before++;
        }
        char *repPtr = replacement;
        while (*repPtr)
        {
            *bufPtr++ = *repPtr++;
        }
        while (*after)
        {
            *bufPtr++ = *after++;
        }
        *bufPtr = '\0';
        strcpy(str, buffer);
        delete[] buffer;
    }
    return str;
}

bool validParentheses(const char *str)
{
    if (!str)
        throw std::runtime_error("Input string is null");

    char *braces = new char[strlen(str) + 1];
    int top = -1;

    while (*str)
    {
        char c = *str;
        if (c == '(' || c == '[' || c == '{')
        {
            braces[++top] = c;
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (top == -1)
            {
                delete[] braces;
                return false;
            }

            char open = braces[top--];

            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{'))
            {
                delete[] braces;
                return false;
            }
        }
        str++;
    }
    delete[] braces;
    return top == -1;
}

void mostCommonCharacter(const char *str)
{
    if (str == nullptr || str[0] == '\0')
    {
        throw std::runtime_error("Input string is null or empty");
    }

    int alphabet[26] = {0};
    while (*str)
    {
        if (*str >= 'a' && *str <= 'z')
        {
            alphabet[*str - 'a']++;
        }
        else if (*str >= 'A' && *str <= 'Z')
        {
            alphabet[*str - 'A']++;
        }
        str++;
    }
    unsigned maxIndex = 0;
    for (size_t i = 0; i < 26; i++)
    {
        if (alphabet[i] > alphabet[maxIndex])
        {
            maxIndex = i;
        }
    }
    std::cout << "Most frequent character: " << (char)('a' + maxIndex) << " count: " << alphabet[maxIndex] << std::endl;
}

bool canFormWord(const char *word, const char *letters)
{
    if (!word || !letters)
        return false;

    int counts[256] = {0};

    const char *ptr = letters;
    while (*ptr)
    {
        counts[(unsigned char)(*ptr)]++;
        ptr++;
    }

    ptr = word;
    while (*ptr)
    {
        if (counts[(unsigned char)(*ptr)] == 0)
            return false;
        counts[(unsigned char)(*ptr)]--;
        ptr++;
    }

    return true;
}

char *addTogether(const char *str1, const char *str2)
{
    if (!str1 || !str2)
        throw std::runtime_error("One or more input strings are null");

    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t maxLen = std::max(len1, len2);

    char *temp = new char[maxLen + 2];

    int carry = 0;
    size_t i = 0;

    while (i < len1 || i < len2 || carry)
    {
        int digit1 = (i < len1) ? str1[len1 - 1 - i] - '0' : 0;
        int digit2 = (i < len2) ? str2[len2 - 1 - i] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        temp[i++] = (sum % 10) + '0';
        carry = sum / 10;
    }
    temp[i] = '\0';

    char *result = new char[i + 1];
    for (size_t j = 0; j < i; j++)
    {
        result[j] = temp[i - 1 - j];
    }
    result[i] = '\0';

    delete[] temp;
    return result;
}

char *longestWord(const char *str)
{
    if (str == nullptr || str[0] == '\0')
    {
        throw std::runtime_error("Input string is null or empty");
    }

    const char *maxStart = nullptr;
    size_t maxLength = 0;

    const char *currentStart = nullptr;
    size_t currentLength = 0;

    while (*str)
    {
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
        {
            if (currentStart == nullptr)
            {
                currentStart = str;
            }
            currentLength++;
        }
        else
        {
            if (currentLength > maxLength)
            {
                maxLength = currentLength;
                maxStart = currentStart;
            }
            currentStart = nullptr;
            currentLength = 0;
        }
        str++;
    }

    if (currentLength > maxLength)
    {
        maxLength = currentLength;
        maxStart = currentStart;
    }

    if (maxStart == nullptr)
    {
        return nullptr;
    }

    char *longestWord = new char[maxLength + 1];
    strncpy(longestWord, maxStart, maxLength);
    longestWord[maxLength] = '\0';

    return longestWord;
}
char *reverseWords(const char *str)
{
    if (!str || str[0] == '\0')
        throw std::runtime_error("Input string is null or empty");

    size_t len = strlen(str);
    char *buffer = new char[len + 1];
    char *bufPtr = buffer;

    const char *end = str + len;
    const char *wordEnd = end;

    while (wordEnd > str)
    {
        const char *wordStart = wordEnd - 1;
        while (wordStart >= str && *wordStart != ' ' && *wordStart != '\t' && *wordStart != '\n')
            wordStart--;

        wordStart++;

        if (bufPtr != buffer)
            *bufPtr++ = ' ';

        const char *p = wordStart;
        while (p < wordEnd)
            *bufPtr++ = *p++;

        wordEnd = wordStart - 1;
    }

    *bufPtr = '\0';
    return buffer;
}

int main()
{
    char text[] = "   Hello, World!   ";
    cout << toUpperCase(text) << endl;
    cout << trim(text) << endl;
    cout << biggestNumberInString("abc999def1532ghi789") << endl;
    char str1[100] = "Hello, World! World!";
    cout << replaceLastOccurrence(str1, "World", "Universe") << endl;
    cout << (validParentheses("({([]})") ? "Valid" : "Invalid") << endl;
    mostCommonCharacter("Hello, World!");
    cout << (canFormWord("programirane", "sadksaadlekagasdlijasdrjansmoirdrjoaospijdastaopf") ? "Can form" : "Cannot form") << endl;
    cout << (canFormWord("programirane", "sadksaadlekagasdlijasdjansmoirdrjoaospijdastaopf") ? "Can form" : "Cannot form") << endl;

    char *sum = addTogether("999999999999999", "9999999999999999");
    cout << sum << endl;
    delete[] sum;
    char *longest = longestWord("Example sentance with longestlongestword in here");
    cout << longest << endl;
    delete[] longest;
    char *reversed = reverseWords("one two three four");
    cout << reversed << endl;
    delete[] reversed;
    return 0;
}