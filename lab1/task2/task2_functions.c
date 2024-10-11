#include "task2_functions.h"

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

ERRORS_EXIT_CODES print_Errors(const enum Errors error)
{
    switch (error)
    {
    case E_SUCCESS:
        printf("Успешное завершение \n");
        return E_SUCCESS;
        break;
    case E_INVALID_INPUT:
        printf("ERROR: Неккорекный ввод \n");
        return E_INVALID_INPUT;

        break;
    case E_NOT_ENOUGH_PARAMS:
        printf("ERROR: Неправильное количество аргументов \n");
        return E_NOT_ENOUGH_PARAMS;
        break;
    case E_INVALID_ARG:
        printf("ERROR: Неправильный ввод аргументов \n");
        return E_INVALID_ARG;

        break;
    case E_TYPE_OVERFLOW:
        printf("ERROR: Переполнения типа данных \n");
        return E_TYPE_OVERFLOW;

        break;
    case E_MEMORY_ALLOCATION:
        printf("ERROR:  Ошибка выделении памяти \n");
        return E_MEMORY_ALLOCATION;

        break;
    case E_CANNOT_OPEN_FILE:
        printf("ERROR:  Ошибка ОТКРЫТИЯ ФАЙЛА \n");
        return E_CANNOT_OPEN_FILE;
        break;
    default:
        printf("ERROR:  Неизвестный код Ошибки \n");
        return E_INVALID_INPUT;
        break;
    }
    return E_INVALID_INPUT;
}
