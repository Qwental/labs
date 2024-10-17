#include "../../include/DEFAULT_FUNCTIONS.h"
#include "include/task6_functions.h"

int main(int args, char *argv[])
{
    if (args != 2)
        return print_Errors(E_INVALID_ARG);

    double epsilon;
    ERRORS_EXIT_CODES error;
    
    error = string_to_double(argv[1], &epsilon);
    if (error != E_SUCCESS)
        return print_Errors(error);
    if (epsilon <= 0 || epsilon > 1)
        return print_Errors(E_INVALID_EPSILON);

    if (epsilon < 0.0000000001)
    {
        printf("При введенном epsilon = %.15lf программа будет долго считать интегралы\n", epsilon);
        return E_INVALID_EPSILON;
    }
    
    printf("Методом центральных прямоугольников посчитаны: \n");
    double result_a = integrate_function(epsilon, function_a);

    printf("Интергал a): %.15lf\n", result_a);
    double result_b = integrate_function(epsilon, function_b);

    printf("Интергал b): %.15lf\n", result_b);
    double result_c = integrate_function(epsilon, function_c);

    printf("Интергал c): %.15lf\n", result_c);
    double result_d = integrate_function(epsilon, function_d);

    printf("Интергал d): %.15lf\n", result_d);
    return E_SUCCESS;
}
