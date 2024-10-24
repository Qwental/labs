
#include "../include/task2_10_functions.h"

// вычисляет значение многочлена с заданными коэффицентами в точке a
ERRORS_EXIT_CODES calculation_of_polynomial(double *coefficients, double a, int max_degree, double *result)
{
    if (coefficients == NULL)
        return E_DEREFENCE_NULL_POINTER;

    double pow_a = 1;
    *result = 0;
    int i;
    for (i = 0; i <= max_degree; i++)
    {
        *result += (coefficients[i]) * pow_a;
        pow_a *= a;
    }
    return E_SUCCESS;
}

ERRORS_EXIT_CODES calculate_coefs_polinom_with_shift(double a, double **coefficients_f, long long degree_n_of_polindrom_, ...)
{
    if (degree_n_of_polindrom_ < 0)
        return E_INVALID_INPUT;
    *coefficients_f = NULL;

    double *original_f_coefficients = (double *)malloc(sizeof(double) * (degree_n_of_polindrom_ + 1));
    if (original_f_coefficients == NULL)
        return E_MEMORY_ALLOCATION;

    double *changet_to_g_coefficients = (double *)malloc(sizeof(double) * (degree_n_of_polindrom_ + 1));
    if (changet_to_g_coefficients == NULL)
    {
        free(original_f_coefficients);
        return E_MEMORY_ALLOCATION;
    }

    va_list args;
    va_start(args, degree_n_of_polindrom_);
    long long i;
    for (i = 0; i <= degree_n_of_polindrom_; ++i)
        original_f_coefficients[i] = va_arg(args, double);

    va_end(args);

    size_t factorial_n = 1;
    ERRORS_EXIT_CODES error;
    long long current_degree = degree_n_of_polindrom_;
    size_t n;

    for (n = 0; n <= (size_t)degree_n_of_polindrom_; n++)
    {
        error = calculation_of_polynomial(original_f_coefficients, a, current_degree, &(changet_to_g_coefficients[n]));
        if (error != E_SUCCESS)
        {
            free(original_f_coefficients);
            return error;
        }
        if (n > 0)
        {
            if (factorial_n >= (ULLONG_MAX / n))
            {
                free(original_f_coefficients);
                return E_LONG_OVERFLOW;
            }
            factorial_n *= n;
            changet_to_g_coefficients[n] /= factorial_n;
        }

        current_degree--;

        for (i = 0; i <= current_degree; i++)
            original_f_coefficients[i] = original_f_coefficients[i + 1] * (i + 1);
    }

    free(original_f_coefficients);

    *coefficients_f = changet_to_g_coefficients;

    return E_SUCCESS;
}