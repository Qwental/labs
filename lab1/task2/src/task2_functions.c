#include "../include/task2_functions.h"

double calculate_lim_Euler_number_e(double epsilon)
{
    double prev_result = 0.0;
    double result = 1.0; // при n = 1

    size_t n = 0;
    while (fabs(result - prev_result) >= epsilon)
    {
        n++;
        prev_result = result;
        result = pow((1.0 + (1.0 / n)), n);
    }
    return result;
}

double calculate_row_Euler_number_e(double epsilon)
{
    double result = 0.0;
    double current_f = 1.0; // при n = 1
    size_t n = 0;           // f = 1 + ... + ...

    while (fabs(current_f) > epsilon)
    {
        result += current_f;
        n++;
        current_f *= (1.0 / n);
    }
    return result;
}

double calculate_equation_Euler_number_e(double epsilon)
{
    /*[Mathematics] log_(e)_(x) = log(x) [In C programming]*/
    /* e = 2.718... Минимальная левая граница = 2, а Максимальная правая = 3 */

    double limit_left = 2.0;
    double limit_right = 3.0;
    double result;
    result = (limit_left + limit_right) / 2;

    while (fabs(log(result) - 1) >= epsilon)
    {
        result = (limit_left + limit_right) / 2;

        if (log(result) >= 1.0) // lne
            limit_right = result;
        else
            limit_left = result;
    }
    return result;
}

double calculate_lim_Pi_number(double epsilon)
{
    size_t n = 1;
    double prev_result = 0.0;
    double result = 4.0; // при n = 1

    while (fabs(result - prev_result) > epsilon)
    {
        n++;
        prev_result = result;
        result = (result * 4 * n * (n - 1)) / ((2 * n - 1) * (2 * n - 1));
    }
    return result;
}

double calculate_row_Pi_number(double epsilon)
{
    double prev_result = 0.0;
    double result = 1.0; // при n = 1
    size_t n = 1;
    while (fabs(result - prev_result) > epsilon)
    {
        n++;
        prev_result = result;
        result += (!((n - 1) & 1)) ? ((1.0) / (2 * n - 1)) : ((-1.0) / (2 * n - 1));
    }
    return result * 4;
}

double calculate_equation_Pi_number(double epsilon)
{
    double limit_left = 3.0;
    double limit_right = 4.0;
    double result = 0.0;
    result = (limit_left + limit_right) / 2;

    while (fabs((sin(result))) >= epsilon)
    {
        result = (limit_left + limit_right) / 2;
        if (sin(result) < 0)
            limit_right = result;
        else
            limit_left = result;
    }
    return result;
}

double calculate_lim_ln2(double epsilon)
{
    size_t n = 1;
    double prev_result = 0.0;
    double result = 1.0; // при n = 1
    while (fabs(result - prev_result) > epsilon)
    {
        n++;
        prev_result = result;
        result = n * (pow(2.0, 1.0 / n) - 1);
    }
    return result;
}

double calculate_row_ln2(double epsilon)
{
    double prev_result = 0.0;
    double result = 1.0; // при n = 1
    size_t n = 1;
    while (fabs(result - prev_result) > epsilon)
    {
        n++;
        prev_result = result;
        result += (!((n - 1) & 1)) ? ((1.0) / (n)) : ((-1.0) / (n));
    }
    return result;
}

double calculate_equation_ln2(double epsilon)
{
    double limit_left = 0.0;
    double limit_right = 1.0;
    double result;
    result = (limit_left + limit_right) / 2;

    while (fabs(exp(result) - 2) >= epsilon)
    {
        result = (limit_left + limit_right) / 2;

        if (exp(result) > 2.0)
            limit_right = result;
        else
            limit_left = result;
    }
    return result;
}

double calculate_lim_sqrt2(double epsilon)
{
    size_t n = 1;
    double prev_result = -0.5; // при n = 0
    double result = 0.375;     // при n = 1
    while (fabs(result - prev_result) > epsilon)
    {
        n++;
        prev_result = result;
        result += ((-1.0) * (result * result / 2)) + 1;
    }
    return result;
}

double calculate_Composition_sqrt2(double epsilon)
{

    double prev_result = 1;
    double result = pow(2.0, 0.25); // при k = 2
    double k = 2.0;
    while (fabs(prev_result - result) > epsilon)
    {
        k++;
        prev_result = result;
        result *= pow(2.0, pow(2.0, -k));
    }
    return result;
}

double calculate_equation_sqrt2(double epsilon)
{
    double limit_left = 1.0;
    double limit_right = 2.0;
    double result;
    result = (limit_left + limit_right) / 2;

    while (fabs(result * result - 2) >= epsilon)
    {
        result = (limit_left + limit_right) / 2;
        if ((result * result) > 2.0)
            limit_right = result;
        else
            limit_left = result;
    }
    return result;
}

double calculate_lim_EulerMascheroni_constant(double epsilon)
{
    double prev_result = 0.0;
    double result = 1.0;
    size_t n = 1;
    while (fabs(result - prev_result) >= epsilon)
    {
        prev_result = result;
        n++;
        result = sum_for_gamma(n) - log(n);
    }
    return result;
}
// Постоянная Эйлера — Маскерони
// lim https://math.fandom.com/ru/wiki/%D0%9F%D0%BE%D1%81%D1%82%D0%BE%D1%8F%D0%BD%D0%BD%D0%B0%D1%8F_%D0%AD%D0%B9%D0%BB%D0%B5%D1%80%D0%B0_%E2%80%94_%D0%9C%D0%B0%D1%81%D0%BA%D0%B5%D1%80%D0%BE%D0%BD%D0%B8#:~:text=%D0%9F%D0%BE%D1%81%D1%82%D0%BE%D1%8F%D0%BD%D0%BD%D0%B0%D1%8F%20%D0%AD%CC%81%D0%B9%D0%BB%D0%B5%D1%80%D0%B0%E2%80%94%D0%9C%D0%B0%D1%81%D0%BA%D0%B5%D1%80%D0%BE%CC%81%D0%BD%D0%B8%20%D0%B8%D0%BB%D0%B8%20%D0%BF%D0%BE%D1%81%D1%82%D0%BE%D1%8F%D0%BD%D0%BD%D0%B0%D1%8F,%7D%2D%5Cln%20n%5Cright)%7D

double calculate_Composition_EulerMascheroni_constant(double epsilon)
{
    double prev_result = 0.0;
    double result = 0.5;

    double k = 2.0;
    epsilon = 0.0000000000000001; // считает праильно только при большом эпсилон =(
    while (fabs(result - prev_result) > epsilon)
    {
        prev_result = result;
        k++;
        if (fmod(sqrt(k), 1.0) == 0.0) // Функция fmod вычисляет остаток от деления и возвращает значение с плавающей точкой, оставшуюся часть от целочисленного деления параметров num/denom.
            k++;                       // result - prev_res = 0, выход из цикла. Поэтому пропустим это значение k;
        // (int)n - целая часть
        result += (1.0 / pow((int)sqrt(k), 2.0)) + ((-1.0) / k);
    }

    return result - ((PI * PI) / 6.0);
}

long double calculate_equation_EulerMascheroni_constant(double epsilon)
{
    int t = 2;
    double prev_result = 0.0;
    double result = log(2) * 0.5;
    double p_fraction_in_limit = 0.5; // fraction == дробь
    while (fabs(result - prev_result) > epsilon)
    {
        prev_result = result;
        while (!is_prime(++t))
            p_fraction_in_limit *= (1.0 - 1.0 / t);

        result = log(t) * p_fraction_in_limit;
    }

    return log(1 / result);
}

double Composition_p_for_gamma(double t)
{
    double result = 1.0;
    for (long long int p = 2; p <= t; ++p)
    {
        if (is_prime(p))
        {
            result *= (p - 1.0) / p;
            break;
        }
    }
    return result;
}

double sum_for_gamma(size_t n)
{
    {
        double result = 1.0;
        for (size_t i = 2; i <= n; ++i)
        {
            result += 1.0 / i;
        }
        return result;
    }
}

int is_prime(long long int number_x)
{
    if (number_x < 0)
        number_x = -number_x;
    if ((number_x == 0) || (number_x == 2) || (number_x == 3))
        return 0;
    if ((((number_x % 2) == 0) || ((number_x % 3) == 0)))
        return 1;
    for (int j = 5; j * j <= number_x; j += 6)
    {
        if (((number_x % j) == 0) || ((number_x % (j + 2)) == 0))
            return 1;
    }
    return 0;
}
