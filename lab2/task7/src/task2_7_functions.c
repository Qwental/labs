#include "../include/task2_7_functions.h"

double FUNCTION_1(double x)
{
    return 2 * sin(x) - atan(x);
}

double FUNCTION_2(double x)
{
    return -log(x + 5) - 2 * sin(x) + 1.0;
}

double FUNCTION_3(double x)
{
    return -133 * sin(x + 1) + 133;
}

double FUNCTION_4(double x)
{
    return sin(x);
}

ERRORS_EXIT_CODES dichotomy(double a, double b, double *result, double (*FUNCTION)(double), const double epsilon)
{
    double c;

    if (result == NULL)
    {
        return print_Errors(E_DEREFENCE_NULL_POINTER);
    }

    if ((FUNCTION(a) > 0 && FUNCTION(b) > 0) || (FUNCTION(a) < 0 && FUNCTION(b) < 0))
    {
        printf("ERROR:  Для границ a = %lf и b = %lf,  не выполнилось условие F(a)*F(b) < 0 \
         \n из-за чего метод Дихотомии не может гарантированно вывести решение\n",
               a, b);

        return E_INVALID_INPUT;
    }

    while (fabs(a - b) >= epsilon)
    {
        c = (a + b) / 2.0;
        if (FUNCTION(a) * FUNCTION(c) > epsilon)
        {
            a = c;
        }
        else
        {
            b = c;
        }
    }
    *result = c;
    return E_SUCCESS;
}
