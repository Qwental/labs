#include "task8_functions.h"

const char *find_file_name(const char *file_string)
{
    const char *file_name = strrchr(file_string, '/');
    // Функция strchr ищет последнее вхождения символа

    if (file_name != NULL)
        file_name++;
    else
        file_name = file_string;
    return file_name;
}

int charToValue(char ch)
{
    if (isdigit(ch))
        return ch - '0';
    else if (isalnum(ch))
        return toupper(ch) - 'A' + 10;
    return -1; // eof and etc
}

int findMinBase(const char *num)
{
    int maxDigit = 1;
    for (int i = 0; num[i] != '\0'; ++i)
    {
        if (num[i] == ' ')
            continue;

        int value = charToValue(num[i]);
        if (value == -1)
            continue;
        if (value + 1 > maxDigit)
            maxDigit = value + 1;
    }
    if (maxDigit > 36)
        return 36;
    else
        return maxDigit;
}

enum Errors convert_to_decimal(char *number_string, int base, long long int *number)
{
    // схема горнера
    if (!number_string)
    {
        return E_INVALID_INPUT;
    }
    *number = 0;
    char *ptr = NULL;
    ptr = number_string;
    while (*ptr)
    {
        if (*number > ((LLONG_MAX / base) + (isdigit(*ptr) ? *ptr - '0' : toupper(*ptr) - 'A' + 10)))
            return E_TYPE_OVERFLOW;

        *number = (*number) * base + (isdigit(*ptr) ? *ptr - '0' : toupper(*ptr) - 'A' + 10);
        ptr++;
    }

    return E_SUCCESS;
}