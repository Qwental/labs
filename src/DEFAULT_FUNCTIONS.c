#ifndef __DEFAULT_FUNCTIONS_C__
#define __DEFAULT_FUNCTIONS_C__
#include "../include/DEFAULT_FUNCTIONS.h"

/* Функция print_Errors выводит ошибку в консоль и возвращает код ошибки*/
ERRORS_EXIT_CODES print_Errors(const enum Errors error)
{
    switch (error)
    {
    case E_SUCCESS:
        printf("Успешное завершение! \n");
        return E_SUCCESS;
    case E_INVALID_INPUT:
        printf("ERROR: Неккорекный ввод \n");
        return E_INVALID_INPUT;
    case E_NOT_ENOUGH_PARAMS:
        printf("ERROR: Неправильное количество аргументов \n");
        return E_NOT_ENOUGH_PARAMS;
    case E_INVALID_ARG:
        printf("ERROR: Неправильный ввод аргументов \n");
        return E_INVALID_ARG;
    case E_TYPE_OVERFLOW:
        printf("ERROR: Переполнения типа данных \n");
        return E_TYPE_OVERFLOW;
    case E_MEMORY_ALLOCATION:
        printf("ERROR:  Ошибка выделении памяти \n");
        return E_MEMORY_ALLOCATION;
    case E_CANNOT_OPEN_FILE:
        printf("ERROR:  Ошибка ОТКРЫТИЯ ФАЙЛА \n");
        return E_CANNOT_OPEN_FILE;
    case E_INVALID_EPSILON:
        printf("ERROR:  Невалидная точность эпсилон \n");
        return E_INVALID_EPSILON;
    case E_DEREFENCE_NULL_POINTER:
        printf("ERROR:  Ошибка разыменования указателя на NULL \n");
        return E_INVALID_EPSILON;
    case E_INT_OVERFLOW:
        printf("ERROR:  Переполнение типа  INT \n");
        return E_INVALID_EPSILON;
    case E_LONG_OVERFLOW:
        printf("ERROR:  Переполнение типа LONG INT\n");
        return E_INVALID_EPSILON;
    case E_FLOAT_OVERFLOW:
        printf("ERROR:  Переполнение типа FLOAT \n");
        return E_INVALID_EPSILON;
    case E_DOUBLE_OVERFLOW:
        printf("ERROR:  ОПереполнение типа  DOUBLE \n");
        return E_INVALID_EPSILON;
    case E_LONG_DOUBLE_OVERFLOW:
        printf("ERROR:  Переполнение типа LONG DOUBLE \n");
        return E_INVALID_EPSILON;
    case E_INVALID_FLAG_ARG:
        printf("ERROR:  Неккорекный ввод аргументов (флагов), они должны начинаться с символов '-' или '/'");
        return E_INVALID_FLAG_ARG;
    case E_SAME_FILE_NAMES:
        printf("ERROR:  Одинаковые имена файлов\n");
        return E_SAME_FILE_NAMES;
    case E_BUFFER_OVERFLOW:
        printf("ERROR:  Переполнение буффера \n");
        return E_BUFFER_OVERFLOW;
    case E_SAME_FILES:
        printf("ERROR: Одинаковые файлы \n");
        return E_SAME_FILES;
    default:
        printf("ERROR:  Неизвестный код Ошибки \n");
        return E_INVALID_INPUT;
    }
    return E_INVALID_INPUT;
}

/*Cхема Горнера, из BASE СС string в 10 CC LONG LONG INT */
ERRORS_EXIT_CODES convert_to_decimal(char *number_string, int base, long long int *number)
{
    // схема горнера
    if (number_string == NULL)
    {
        return E_DEREFENCE_NULL_POINTER;
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

/*Обратная схема Горнера, из 10СС int в BASE CC int*/
char *convert_to_your_base_from_10CC(int number, int base)
{
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

/*Проверка переполнения DOUBLE*/
ERRORS_EXIT_CODES is_double_overflow(double to_check)
{
    if ((fabs(to_check) > DBL_MAX) || to_check == HUGE_VAL || to_check == -HUGE_VAL || isnan(to_check) || isinf(to_check))
        return E_DOUBLE_OVERFLOW;
    return E_SUCCESS;
}

/* Перевод строки в double */
ERRORS_EXIT_CODES string_to_double(const char *str, double *num)
{
    if (str == NULL || num == NULL)
        return E_DEREFENCE_NULL_POINTER;

    char *endptr;
    double value = strtod(str, &endptr);

    if (*endptr != '\0')
        return E_INVALID_INPUT; // TODO вариант ошибки для стринга

    if (is_double_overflow(value))
        return E_DOUBLE_OVERFLOW;

    *num = value;
    return E_SUCCESS;
}

/* Перевод строки в long long int */
ERRORS_EXIT_CODES string_to_long_long_int(const char *str_number, long long int *int_result_number, int base)
{
    if (str_number == NULL || int_result_number == NULL)
        return E_DEREFENCE_NULL_POINTER;
    char *endptr;
    *int_result_number = strtol(str_number, &endptr, base);
    if (*int_result_number == LLONG_MAX || *int_result_number == LLONG_MIN)
        return E_LONG_OVERFLOW;
    else if (*endptr != '\0')
        return E_INVALID_INPUT;
    return E_SUCCESS;
}
/* Перевод строки в int */
ERRORS_EXIT_CODES string_to_int(const char *str_number, int *int_result_number, int base)
{
    if (str_number == NULL || int_result_number == NULL)
        return E_INVALID_INPUT;
    char *endptr;
    *int_result_number = strtol(str_number, &endptr, base);
    if (*int_result_number == INT_MAX || *int_result_number == INT_MIN || *int_result_number == -1)
        return E_TYPE_OVERFLOW;
    else if (*endptr != '\0')
        return E_INVALID_INPUT;
    return E_SUCCESS;
}

// TODO int, long, long double overflow
#endif