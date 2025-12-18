#include <iostream>
#include <cstring>

bool isVowel(char c)
{
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}
void putUniqueWordsInArray(const char *sentence, char **&uniqueWords, int &uniqueCount)
{
    const char *ptr = sentence;
    char **allWords = new char *[strlen(sentence) + 1];
    int allCount = 0;

    char *word = new char[strlen(sentence) + 1];
    while (*ptr)
    {
        int wordLen = 0;
        while (*ptr && *ptr != ' ')
        {
            word[wordLen++] = tolower(*ptr++);
        }
        word[wordLen] = '\0';

        if (wordLen > 0)
        {
            allWords[allCount] = new char[wordLen + 1];
            strcpy_s(allWords[allCount], wordLen + 1, word);
            allCount++;
        }

        if (*ptr == ' ')
            ptr++;
    }
    delete[] word;

    for (int i = 0; i < allCount; i++)
    {
        int count = 0;
        for (int j = 0; j < allCount; j++)
        {
            if (strcmp(allWords[i], allWords[j]) == 0)
                count++;
        }

        if (count == 1)
        {
            uniqueWords[uniqueCount] = new char[strlen(allWords[i]) + 1];
            strcpy_s(uniqueWords[uniqueCount], strlen(allWords[i]) + 1, allWords[i]);
            uniqueCount++;
        }
    }

    for (int i = 0; i < allCount; i++)
        delete[] allWords[i];
    delete[] allWords;
}

void sortWordsByVowelCountAndThenAlphabetically(char **words, int count)
{
    for (int i = 0; i < count - 1; ++i)
    {
        for (int j = i + 1; j < count; ++j)
        {
            int vowelCountI = 0;
            int vowelCountJ = 0;

            for (int k = 0; words[i][k]; ++k)
                if (isVowel(words[i][k]))
                    vowelCountI++;

            for (int k = 0; words[j][k]; ++k)
                if (isVowel(words[j][k]))
                    vowelCountJ++;

            if (vowelCountI < vowelCountJ ||
                (vowelCountI == vowelCountJ && strcmp(words[i], words[j]) > 0))
            {
                char *temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

char *joinWords(char **words, int count)
{
    size_t totalLength = 0;
    for (int i = 0; i < count; ++i)
    {
        totalLength += strlen(words[i]) + 1;
    }

    char *result = new char[totalLength];
    result[0] = '\0';

    for (int i = 0; i < count; ++i)
    {
        strcat_s(result, totalLength, words[i]);
        if (i < count - 1)
            strcat_s(result, totalLength, " ");
    }

    return result;
}

char *uniqueWordsSortedByVowels(const char *sentence)
{
    char **uniqueWords = new char *[strlen(sentence) + 1];
    int uniqueCount = 0;

    putUniqueWordsInArray(sentence, uniqueWords, uniqueCount);
    sortWordsByVowelCountAndThenAlphabetically(uniqueWords, uniqueCount);
    char *result = joinWords(uniqueWords, uniqueCount);

    for (int i = 0; i < uniqueCount; i++)
        delete[] uniqueWords[i];
    delete[] uniqueWords;

    return result;
}

int main()
{
    const char *sentence = "The quick brown aaa fox bbb jumps bbb over the ccc lazy dog eee";
    char *result = uniqueWordsSortedByVowels(sentence);
    std::cout << result << std::endl;
    delete[] result;
    return 0;
}
