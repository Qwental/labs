
#include "../../include/DEFAULT_FUNCTIONS.h"
#include "include/task2_7_functions.h"

int main()
{
    double epsilon = 0.001;
    double result;
    ERRORS_EXIT_CODES error;

    error = dichotomy(2.5, 2.6, &result, &FUNCTION_1, epsilon);
    if (error == E_SUCCESS)
    {
        printf("Методом дихотомии с точностью = %.15f нашли решение: %.15f=0\n", epsilon, result);
        printf("Проверка решения: F(%.15f) = %.15f\n\n", result, FUNCTION_1(result));
    }

    epsilon = 0.00000000000001;

    error = dichotomy(2.5, 2.6, &result, &FUNCTION_1, epsilon);
    if (error == E_SUCCESS)
    {
        printf("Методом дихотомии с точностью = %.15f нашли решение: %.15f=0\n", epsilon, result);
        printf("Проверка решения: F(%.15f) = %.15f\n\n", result, FUNCTION_1(result));
    }

    error = dichotomy(-0.5, 0, &result, &FUNCTION_2, epsilon);
    if (error == E_SUCCESS)
    {
        printf("Методом дихотомии с точностью = %.15f нашли решение: %.15f=0\n", epsilon, result);
        printf("Проверка решения: F(%.15f) = %.15f\n\n", result, FUNCTION_2(result));
    }

    error = dichotomy(0.56, 0.58, &result, &FUNCTION_3, epsilon);
    if (error == E_SUCCESS)
    {
        printf("Методом дихотомии с точностью = %.15f нашли решение: %.15f=0\n", epsilon, result);
        printf("Проверка решения: F(%.15f) = %.15f\n\n", result, FUNCTION_3(result));
    }
}
