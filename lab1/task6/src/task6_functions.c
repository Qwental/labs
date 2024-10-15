#include "../include/task6_functions.h"

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

double integrate_function(double epsilon, double (*func_to_integrate)(double))
{
    double previous_result = 1.0;
    double result = 0.0;
    int n = 1;

    while (fabs(result - previous_result) >= epsilon)
    {
        previous_result = result;
        result = method_central_triangle(n, epsilon, func_to_integrate);
        n++;
    }

    return result;
}
double method_central_triangle(int n, double epsilon, double (*function)(double))
{
    double a = 0.00001;
    double b = 1.0;

    double lamda = (b - a) / n; // разбиение

    double sum = function(lamda);
    double x = 0.0;

    double i; // i = eps == 0.0001 == 0
    for (i = epsilon + 1; i < (n - epsilon); i++)
    {
        x = lamda * i;
        sum += function(x);
    }

    return sum * lamda;
}
