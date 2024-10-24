#include "../include/task2_9_functions.h"

// Функция для нахождения НОД
size_t gcd(size_t a, size_t b)
{
    size_t temp;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int has_number_finit_representation(double number, long long base)
{

    long long denominator = 1;
    long long j = 0;
    int cheak = INT_MAX;

    while (number != (int)number)
    {
        if (number > (LDBL_MAX / base))
            return 0;

        if (denominator >= (LLONG_MAX / base) || (j++ > (cheak /= base)))
            return 0;

        number *= base;
        denominator *= base;
    }

    long long i = 0;
    for (i = 2; (i <= base && i <= denominator); i++)
    {
        while (base % i == 0)
        {
            base /= i;
            while (denominator % i == 0)
                denominator /= i;
        }
    }

    return (denominator == 1);
}

ERRORS_EXIT_CODES finit_cheak(long long **result_array, int base, long long number_of_numbers_to_cheak, ...)
{
    if (base < 2)
        return E_INVALID_INPUT;

    va_list numbers_ptr;
    va_start(numbers_ptr, number_of_numbers_to_cheak);

    (*result_array) = (long long *)malloc(sizeof(long long) * number_of_numbers_to_cheak);
    if (result_array == NULL)
        return E_MEMORY_ALLOCATION;

    double number = 0.0;
    long long i;

    for (i = 0; i < number_of_numbers_to_cheak; i++)
    {
        number = va_arg(numbers_ptr, double);

        if (number < LDBL_EPSILON || number > 1.0)
        {
            free((*result_array));
            va_end(numbers_ptr);
            return E_INVALID_INPUT;
        }

        if (has_number_finit_representation(number, base))
            (*result_array)[i] = 1;
        else
            (*result_array)[i] = 0;
    }

    va_end(numbers_ptr);

    return E_SUCCESS;
}
