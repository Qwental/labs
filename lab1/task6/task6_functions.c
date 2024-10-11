#include "task6_functions.h"

double function_a(double x)
{
    return log(1 + x) / x;
}

double function_b(double x)
{
    return exp(-x * x / 2);
}

double function_c(double x)
{
    return log(1 / (1 - x));
}

double function_d(double x)
{
    return pow(x, x);
}
/* Функция print_Errors выводит ошибку в консоль и возвращает код ошибки*/
ERRORS_EXIT_CODES print_Errors(const enum Errors error)
{
    switch (error)
    {
    case E_SUCCESS:
        printf("Успешное завершение \n");
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
        printf("ERROR:  Неправильное число точности Эпсилон \n");
        return E_INVALID_EPSILON;
    default:
        printf("ERROR:  Неизвестный код Ошибки \n");
        return E_INVALID_INPUT;
    }
    return E_INVALID_INPUT;
}

ERRORS_EXIT_CODES string_to_double(const char *str, double *num)
{
    if (!str || !num)
        return E_INVALID_INPUT;

    char *endptr;
    double value = strtod(str, &endptr);

    if (*endptr != '\0')
        return E_INVALID_INPUT;

    if (is_double_overflow(value))
        return E_TYPE_OVERFLOW;

    *num = value;
    return E_SUCCESS;
}

enum Errors is_double_overflow(double to_check)
{
    if ((fabs(to_check) > DBL_MAX) || to_check == HUGE_VAL || to_check == -HUGE_VAL || isnan(to_check) || isinf(to_check))
        return E_TYPE_OVERFLOW;
    return E_SUCCESS;
}

double integrate_function(double epsilon, double (*integral)(double))
{
    /*double (*integral)(double) приводим указатель функции к даблу*/
    double previous_result = 1.0;
    double result = 0.0;
    int n = 1; // devison by zero
    while (fabs(result - previous_result) >= epsilon)
    {
        previous_result = result;
        result = method_central_triangle(n, epsilon, integral);
        n += 5;
    }

    return result;
}

double method_central_triangle(int n, double epsilon, double (*function)(double))
{
    double a = 0.00001;
    double b = 1.0;
    double h = (b - a) / n; // разбиение в серединке
    double sum = function(h);
    double x;
    for (double i = epsilon; i < (n - epsilon); i++)
    {
        x = h * i;
        sum += function(x);
    }
    return h * sum;
}