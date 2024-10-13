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
        n += 1;
    }

    return result;
}
//TODO
double method_central_triangle(int n, double epsilon, double (*function)(double))
{
    double a = 0.00001;
    double b = 1.0;
    double h = (b - a) / n; // разбиение в серединке
    double sum = function(h);
    double x;
    double i;
    for (i = epsilon; i < (n - epsilon); i++) // i 1..n
    {
        x = h * i;
        sum += function(x);
    }
    return h * sum;
}
