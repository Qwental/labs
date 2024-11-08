
#include "../../include/DEFAULT_FUNCTIONS.h"
#include "include/task2_10_functions.h"

int main()
{
    double *result;
    long long degree_n_of_polindrom = 2;

    printf("Для многочлена f(x) = 1 - 2x + x^2, a = 2\nОжидаем результат: g_0 = 1.0  g_1 = 2.0  g_3 = 1.0\n");
    ERRORS_EXIT_CODES error = calculate_coefficients_with_teylor(2.0, &result, degree_n_of_polindrom, 1.0, -2.0, 1.0);
    if (error == E_SUCCESS)
    {
        
        printf("Результат: \n");
        int i;
        for (i = 0; i <= degree_n_of_polindrom; ++i)
            printf("g_%d = %lf \n", i, result[i]);
    }
    else
        print_Errors(error);
    free(result);

    degree_n_of_polindrom = 4;
    printf("Для многочлена f(x) = -2 + x - 3x^2 + x^4, a = 3\nОжидаем результат: g_0 = 55.0  g_1 = 91.0  g_3 = 51.0 g_4 = 12.0 g_5 = 1.0\n");
    error = calculate_coefficients_with_teylor(3.0, &result, degree_n_of_polindrom, -2.0, 1.0, -3.0, 0.0, 1.0);
    if (error == E_SUCCESS)
    {
        printf("Результат: \n");
        int i;
        for (i = 0; i <= degree_n_of_polindrom; ++i)
            printf("g_%d = %lf \n", i, result[i]);
    }
    else
        print_Errors(error);
    free(result);

    return E_SUCCESS;
}