#include "../include/task2_1_functions.h"

ERRORS_EXIT_CODES len_string(const char *string, size_t *length)
{
    // КОД с пары Ильи
    if (string == NULL)
    {
        return E_DEREFENCE_NULL_POINTER;
    }
    const char *start = string;
    while (*string++)
        ;
    *length = string - start - 1;
    return E_SUCCESS;
}

ERRORS_EXIT_CODES reverse_string(const char *input_string, char **output_string)
{

    size_t length = 0;
    if (len_string(input_string, &length) != E_SUCCESS)
    {
        return E_DEREFENCE_NULL_POINTER;
    }

    // НОВАЯ СТРОКА
    *output_string = (char *)malloc(sizeof(char) * (length + 1));

    if (*output_string == NULL)
        return E_MEMORY_ALLOCATION;

    size_t i;
    for (i = 0; i < length; i++)
        (*output_string)[i] = input_string[length - i - 1];

    (*output_string)[length] = '\0';

    return E_SUCCESS;
}

ERRORS_EXIT_CODES string_every_odd_one_to_uppercase(const char *input_string, char **output_string)
{
    size_t length = 0;
    if (len_string(input_string, &length) != E_SUCCESS)
    {
        return E_DEREFENCE_NULL_POINTER;
    }
    // printf("%zu\n",length);
    length++;
    *output_string = (char *)malloc(sizeof(char) * (length));
    if (*output_string == NULL)
        return E_MEMORY_ALLOCATION;

    size_t i;
    for (i = 0; i < length; i++)
    {
        if ((!(i & 1) && isalpha(input_string[i])))
        {
            (*output_string)[i] = toupper(input_string[i]);
        }
        else
        {
            (*output_string)[i] = input_string[i];
        }
    }
    return E_SUCCESS;
}

ERRORS_EXIT_CODES flag_n_string(const char *input_string, char **output_string)
{
    size_t length = 0;
    if (len_string(input_string, &length) != E_SUCCESS)
    {
        return E_DEREFENCE_NULL_POINTER;
    }
    length++;
    // printf("%zu\n",length);
    *output_string = (char *)malloc(sizeof(char) * (length));
    if (*output_string == NULL)
        return E_MEMORY_ALLOCATION;
    (*output_string)[0] = '\0';

    char *digits_string = (char *)malloc(sizeof(char) * (length));
    if (digits_string == NULL)
        return E_MEMORY_ALLOCATION;

    char *alphas_string = (char *)malloc(sizeof(char) * (length));
    if (alphas_string == NULL)
    {
        free(digits_string);
        return E_MEMORY_ALLOCATION;
    }

    char *other_symbols_string = (char *)malloc(sizeof(char) * (length));
    if (other_symbols_string == NULL)
    {
        free(digits_string);
        free(alphas_string);
        return E_MEMORY_ALLOCATION;
    }

    size_t alpha_count = 0;
    size_t other_symbols_count = 0;
    size_t i;
    size_t digit_count = 0;
    for (i = 0; i < length; i++)
    {
        if (isdigit(input_string[i]))
        {
            digits_string[digit_count] = input_string[i];
            digit_count++;
        }
        else if (isalpha(input_string[i]))
        {
            alphas_string[alpha_count] = input_string[i];
            alpha_count++;
        }
        else
        {
            other_symbols_string[other_symbols_count] = input_string[i];
            other_symbols_count++;
        }
    }
    //(*output_string)[length] = '\0';

    digits_string[digit_count] = '\0';
    alphas_string[alpha_count] = '\0';
    other_symbols_string[other_symbols_count] = '\0';

    string_concatination(*output_string, digits_string);
    free(digits_string);
    string_concatination(*output_string, alphas_string);
    free(alphas_string);
    string_concatination(*output_string, other_symbols_string);
    free(other_symbols_string);
    return E_SUCCESS;
}

char *string_concatination(char *output_string, const char *input_string)
{
    char *start_string = output_string;

    // указат в конец строки
    while (*output_string != '\0')
    {
        output_string++;
    }
    // Копируем литералы из вводимой строки в выводимую вместе с \0
    while (*input_string != '\0')
    {
        *output_string = *input_string;
        output_string++;
        input_string++;
    }
    *output_string = '\0';
    return start_string; //
}

void my_puts(const char *string)
{
    while (*string) // Пока не достигнут конец строки
    {
        putchar(*string);
        string++; // Переходим к следующему литералу
    }
    putchar('\n');
}

ERRORS_EXIT_CODES string_to_unsigned_long_int(const char *string, unsigned long *result)

{
    if (string[0] == '-')
        return E_INVALID_INPUT;
    char *endinp;
    *result = strtoul(string, &endinp, 10); // stdlib
    if (*result == ULONG_MAX)
        return E_LONG_OVERFLOW;
    if (*endinp != '\0')
        return E_INVALID_INPUT;
    return E_SUCCESS;
}
ERRORS_EXIT_CODES flag_c_string(char *strings[], size_t length, char **output_strings)
{

    if (strings == NULL)
    {
        return E_DEREFENCE_NULL_POINTER;
    }
    int j = 0;
    if (length > 1)
    {
        for (size_t i = 0; i < length; i++)
        {
            // Мешаем строки
            j = rand() % length;
            swap_strings(&strings[i], &strings[j]);
        }
    }
    size_t current_str_length = 0;
    size_t summary_length_of_strings = 0;
    for (size_t i = 0; i < length; i++)
    {
        if (len_string(strings[i], &current_str_length) != E_SUCCESS)
            return E_MEMORY_ALLOCATION;

        summary_length_of_strings += current_str_length;
    }

    *output_strings = (char *)malloc(sizeof(char) * (summary_length_of_strings + 1));
    if (*output_strings == NULL)
        return E_MEMORY_ALLOCATION;
        
    size_t index = 0;
    for (size_t i = 0; i < length; i++)
    {
        current_str_length = 0;
        if (len_string(strings[i], &current_str_length))
        {
            free(*output_strings);
            return E_MEMORY_ALLOCATION;
        }

        for (size_t j = 0; j < current_str_length; j++)
            (*output_strings)[index++] = strings[i][j];
    }

    (*output_strings)[index] = '\0';
    return E_SUCCESS;
}

void swap_strings(char **s1, char **s2)
{
    char *temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}