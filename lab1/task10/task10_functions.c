#include "task10_functions.h"

enum Errors delete_zeros_from_num(char *temp_number, unsigned long long num_length)
{
    if (!temp_number)
    {
        return E_INVALID_INPUT;
    }

    if ((num_length == 1) && temp_number[0] == '0')
    {
        return E_SUCCESS;
    }

    char t[num_length];
    int j = 0;
    unsigned long long i = 0;

    strcpy(t, temp_number);
    if (t[0] == '-')
    {
        j++;
        i++;
    }
    int end_zeros_flag = 0;
    for (; i < num_length; i++)
    {
        if ((t[i] != '0') && (end_zeros_flag == 0))
        {
            end_zeros_flag = 1;
        }

        if (end_zeros_flag)
        {
            temp_number[j] = t[i];
            j++;
        }
    }
    temp_number[j++] = '\0';
    return E_SUCCESS;
}

char *read_number_string()
{
    unsigned long int size = INITIAL_SIZE;
    unsigned long int length = 0;
    char *string_number = (char *)malloc(size * sizeof(char));

    if (!string_number)
        return NULL;

    char ch;

    printf("Введите число или Stop: ");

    while ((ch = getchar()) != '\n')
    {

        if (length >= size) // увеличиваю размер строки
        {
            size *= 2;
            if (!string_number)
            {
                return NULL;
            }
            // TODO ИСПРАИТЬ проверку realloc - DONE!

            char* temp_string_number = (char *)realloc(string_number, size * sizeof(char));

            if (!temp_string_number)
            {
                free(string_number);
                return NULL; // ошибка памяти
            }
            string_number = temp_string_number;
        }

        string_number[length++] = ch;
        if (length >= (ULLONG_MAX - 1))
        {
            return NULL;
        }
    }

    string_number[length] = '\0'; // добавляем конец строки
    return string_number;
}

enum Errors convert_to_decimal(char *number_string, int base, long long int *number)
{
    // схема горнера
    if (!number_string)
    {
        return E_INVALID_INPUT;
    }
    int sign = 1;
    char *ptr = NULL;
    if (*number_string == '-')
    {
        sign = -1;
        ptr = number_string + 1;
    }
    else
    {
        ptr = number_string;
    }

    while (*ptr)
    {
        if (*number > ((LLONG_MAX / base) + (isdigit(*ptr) ? *ptr - '0' : *ptr - 'A' + 10)))
            return E_TYPE_OVERFLOW;
        *number = (*number) * base + (isdigit(*ptr) ? *ptr - '0' : *ptr - 'A' + 10);
        ptr++;
    }

    *number = *number * sign;
    return E_SUCCESS;
}

char *convert_to_your_base_from_10CC(long long int number, int base)
{
    // обратная схема горнера с лекции
    int sign = 1;

    if (number < 0)
    {
        sign = -1;
        number *= -1; // делаем модуль
    }
    long long int r;

    static char buf[BUFSIZ];
    char* ptr = buf + BUFSIZ - 1;
    *ptr-- = 0;
    while(number > 0)
    {
        *--ptr = ((r = number % base) > 9)? r - 10 + 'A' : r + '0';
        number /= base;
    }

    if (sign == -1)
    {
        *--ptr = '-';
    }
    return ptr++;
}

enum Errors check_string_number_in_your_base(char *number_string, int base)
{
    int i = 0;
    if (!number_string)
        return E_INVALID_INPUT;
    if(number_string[i] == '-') 
        i = 1;

    if (base > 9)
    {
        while(number_string[i])
        {
            if (number_string[i] - 'A' + 10 >= base) 
                return E_INVALID_INPUT;
            i++;
        }
    }
    else {
        while(number_string[i])
        {
            if (number_string[i] - '0' >= base) 
                return E_INVALID_INPUT;
            i++;
        }
    }
    return E_SUCCESS;
}
