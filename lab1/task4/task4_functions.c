#include "task4_functions.h"
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

char *convert_to_your_base_from_10CC(int number, int base)
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
    char *ptr = buf + BUFSIZ - 1;
    *ptr-- = 0;

    while (number > 0)
    {
        *--ptr = ((r = number % base) > 9) ? r - 10 + 'A' : r + '0';
        number /= base;
    }

    if (sign == -1)
    {
        *--ptr = '-';
    }

    return ptr++;
}

enum Errors delete_arabic_funny_numbers(const char *file_input, const char *file_output)
{
    FILE *file_1 = fopen(file_input, "r");

    if (!file_1)
    {
        return E_CANNOT_OPEN_FILE;
    }

    FILE *file_2 = fopen(file_output, "w");

    if (!file_2)
    {
        fclose(file_1);
        return E_CANNOT_OPEN_FILE;
    }

    char ch;
    while (!feof(file_1))
    {
        ch = fgetc(file_1);
        if (ch == EOF)
            continue;
        if (!(ch >= '0' && ch <= '9'))
            fputc(ch, file_2);
    }

    fclose(file_1);
    fclose(file_2);
    return E_SUCCESS;
}

enum Errors how_many_latin_symbols_for_each_line(const char *file_input, const char *file_output)
{
    FILE *file_1 = fopen(file_input, "r");

    if (!file_1)
    {
        return E_CANNOT_OPEN_FILE;
    }

    FILE *file_2 = fopen(file_output, "w");

    if (!file_2)
    {
        fclose(file_1);
        return E_CANNOT_OPEN_FILE;
    }
    long long int counter = 0;
    char ch;

    while (!feof(file_1))
    {
        ch = fgetc(file_1);
        if (isalpha(ch))
        {
            if (counter >= LLONG_MAX - 1)
            {
                fclose(file_1);
                fclose(file_2);
                return E_TYPE_OVERFLOW;
            }
            counter++;
        }

        if ((ch == '\n'))
        {
            fprintf(file_2, "%lld\n", counter);
            counter = 0;
        }
        else if (ch == EOF)
        {
            fprintf(file_2, "%lld", counter);
            counter = 0;
        }
    }

    fclose(file_1);
    fclose(file_2);
    return E_SUCCESS;
}

enum Errors how_many_special_symbols_for_each_line(const char *file_input, const char *file_output)
{
    FILE *file_1 = fopen(file_input, "r");

    if (!file_1)
    {
        return E_CANNOT_OPEN_FILE;
    }

    FILE *file_2 = fopen(file_output, "w");

    if (!file_2)
    {
        fclose(file_1);
        return E_CANNOT_OPEN_FILE;
    }

    long long int counter = 0;
    char ch;
    while (!feof(file_1))
    {
        ch = fgetc(file_1);
        if (!(isalpha(ch)) && !(isdigit(ch)))
        {
            if (counter >= LLONG_MAX - 1)
            {
                fclose(file_1);
                fclose(file_2);
                return E_TYPE_OVERFLOW;
            }
            counter++;
        }
        if (ch == '\n')
        {
            fprintf(file_2, "%lld\n", counter);
            counter = 0;
        }
        else if (ch == EOF)
        {
            fprintf(file_2, "%lld", counter);
            counter = 0;
        }
    }

    fclose(file_1);
    fclose(file_2);
    return E_SUCCESS;
}

enum Errors change_symbols_to_ascii_code(const char *file_input, const char *file_output)
{
    {
        FILE *file_1 = fopen(file_input, "r");

        if (!file_1)
            return E_CANNOT_OPEN_FILE;

        FILE *file_2 = fopen(file_output, "w");
        if (!file_2)
        {
            fclose(file_1);
            return E_CANNOT_OPEN_FILE;
        }

        char ch;
        while (!feof(file_1))
        {
            ch = fgetc(file_1);
            if ((ch >= '0' && ch <= '9') || ch == '\n')
                fprintf(file_2, "%c", ch);
            else
                fprintf(file_2, "%s", convert_to_your_base_from_10CC((int)ch, 16)); // %X -Плоха, Горнер круч
        }
        fclose(file_1);
        fclose(file_2);
        return E_SUCCESS;
    }
}
