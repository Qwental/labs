#include "../include/task2_2_functions.h"

ERRORS_EXIT_CODES check_overflow(long double value)
{
    if (isinf(value))
        return E_DOUBLE_OVERFLOW;
    else if (isnan(value))
        return E_DOUBLE_OVERFLOW;
    else if (value > LDBL_MAX)
        return E_DOUBLE_OVERFLOW;
    else if (value < -LDBL_MAX)
        return E_DOUBLE_OVERFLOW;
    else
        return E_SUCCESS;
}

/*
С Лекции:

va_list
va_start
#define va_start(ap, parm) (ap) = (char*)(&(parm) + 1) ставит указатель после последнего явно переданного параметра

va_arg
#define va_arg(ap, type) ((type*)((char*)(ap) += sizeof(type))[-1] переносит указатель на размер типа и возвращает значение типа (которое находится до смещения (от туда [-1]))

va_end
зануляет указатель

*/

/* Функция многих переменных для вычисления среднего геометрического, первый аргумент - указатель long double (результат) */
ERRORS_EXIT_CODES geometric_mean(int count, ...)
{
    va_list args;          
    va_start(args, count); /*Иниц. списка */
    long double *composition;
    for (int i = 0; i < count; i++)
    {

        if (i == 0)
        {
            composition = va_arg(args, long double *);
            if (composition == NULL)
            {
                return E_DEREFENCE_NULL_POINTER;
            }
            *composition = 1.0; /* composition по английски Произведение*/
        }

        else
        {
            double num = va_arg(args, double); /*След аргумент*/
            *composition *= num;
            if (check_overflow(*composition) != E_SUCCESS)
            {
                return E_DOUBLE_OVERFLOW;
            }
        }
    }
    va_end(args);
    *composition = pow(*composition, 1.0 / count);
    return E_SUCCESS;
}

/* Функция быстрого возведения в степень вещественного числа */
long double my_fast_pow(double x, int n)
{

    // предельный случай
    if ((fabs(x) <= DBL_EPSILON) && (n < 0))
    {
        return INFINITY;
    }

    //  Базовый случай: x^0 = 1
    if (n == 0)
        return 1.0;
    // Если степень отрицательная, преобразуем её к положительной
    if (n < 0)
        return 1.0 / my_fast_pow(x, (-1.0) * n);

    long double half = my_fast_pow(x, (int)(n / 2));

    if (!(n & 1))
        return half * half; // Если n чётное, используем half * half
    else
        return x * half * half; // Если n нечётное, учитываем лишнее умножение на x
}