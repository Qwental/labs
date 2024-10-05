#include "task3_functions.h"

enum Errors is_double_overflow(double to_check)
{
    if ((fabs(to_check) > DBL_MAX) || to_check == HUGE_VAL || to_check == -HUGE_VAL || isnan(to_check) || isinf(to_check))
    {
        return E_TYPE_OVERFLOW;
    }
    return E_SUCCESS;
}

enum Errors flag_m_is_number_multiple(const long long int number_1, const long long int number_2, int *result)
{
    if (result == NULL)
        return E_INVALID_INPUT;
    if (number_1 % number_2 == 0)
        *result = 1;
    else
        *result = 0;
    return E_SUCCESS;
}

enum Errors string_to_double(const char *str, double *num)
{
    if (!str || !num)
    {
        return E_INVALID_INPUT;
    }
    char *endptr;
    double value = strtod(str, &endptr);

    if (*endptr != '\0')
    {
        return E_INVALID_INPUT;
    }

    if (is_double_overflow(value))
    {
        return E_TYPE_OVERFLOW;
    }
    *num = value;
    return E_SUCCESS;
}

enum Errors print_Errors(enum Errors error)
{
    switch (error)
    {
    case E_SUCCESS:
        printf("Успешное завершение \n");
        return E_SUCCESS;
        break;
    case E_INVALID_INPUT:
        printf("ERROR: Неккорекный ввод \n");
        return E_INVALID_INPUT;

        break;
    case E_NOT_ENOUGH_PARAMS:
        printf("ERROR: Неправильное количество аргументов \n");
        return E_NOT_ENOUGH_PARAMS;
        break;
    case E_INVALID_ARG:
        printf("ERROR: Неправильный ввод аргументов \n");
        return E_INVALID_ARG;

        break;
    case E_TYPE_OVERFLOW:
        printf("ERROR: Переполнения типа данных \n");
        return E_TYPE_OVERFLOW;

        break;
    case E_MEMORY_ALLOCATION:
        printf("ERROR:  Ошибка выделении памяти \n");
        return E_MEMORY_ALLOCATION;

        break;
    case E_CANNOT_OPEN_FILE:
        printf("ERROR:  Ошибка ОТКРЫТИЯ ФАЙЛА \n");
        return E_CANNOT_OPEN_FILE;
        break;
    default:
        printf("ERROR:  Неизвестный код Ошибки \n");
        return E_INVALID_INPUT;
        break;
    }
    return E_INVALID_INPUT;
}

enum Errors flag_q_solution()
{
    return E_SUCCESS;
}

enum Errors string_to_int(const char *str_number, long long int *int_result_number, int base)
{
    if (str_number == NULL || int_result_number == NULL)
        return E_INVALID_INPUT;
    char *endptr;
    *int_result_number = strtol(str_number, &endptr, base);
    if (*int_result_number == LLONG_MAX || *int_result_number == LLONG_MIN)
        return E_TYPE_OVERFLOW;
    else if (*endptr != '\0')
        return E_INVALID_INPUT;
    return E_SUCCESS;
}

enum Errors flag_t_is_sides_triangle_possible(const double eps, const double sides[], int *result)
{
    if (result == NULL)
        return E_INVALID_INPUT;
    double sorted_sides[3];
    for (int i = 0; i < 3; i++)
        sorted_sides[i] = sides[i];
    double temp;

    for (int i = 0; i < 2; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (sorted_sides[i] > sorted_sides[j])
            {
                temp = sorted_sides[i];
                sorted_sides[i] = sorted_sides[j];
                sorted_sides[j] = temp;
            }
        }
    }

    // Теорема Пифагора
    if (fabs(sorted_sides[0] * sorted_sides[0] + sorted_sides[1] * sorted_sides[1] - sorted_sides[2] * sorted_sides[2]) < eps)
    {
        *result = 1;
    }
    else
    {
        *result = 0;
    }
    return E_SUCCESS;
}

int solve_quadratic(double epsilon, double a, double b, double c, double *root1, double *root2)

{
    if (a == 0.0)
    {
        if (c == 0.0)
        {
            if (b == 0.0)
                return 3;
            else
                return 3;
        }
        else
        {
            if (b == 0.0)
                return 0;
            else
            {
                *root1 = -c / (-b);
                return 1;
            }
        }
    }

    else
    {
        double discriminant = b * b - 4 * a * c;

        if (fabs(discriminant) < epsilon)
        {
            discriminant = 0.0;
        }

        if (discriminant < 0)
        {
            return 0;
        }
        else if (discriminant == 0)
        {
            *root1 = -b / (2 * a);
            return 1;
        }
        else
        {
            double sqrt_discriminant = sqrt(discriminant);
            *root1 = (-b + sqrt_discriminant) / (2 * a);
            *root2 = (-b - sqrt_discriminant) / (2 * a);
            return 2;
        }
    }
}

enum Errors flag_q_Permutation_ABC_Print(double epsilon, double a, double b, double c, double *root1, double *root2)
{
    double permutations[6][3] = {{a, b, c}, {a, c, b}, {b, a, c}, {b, c, a}, {c, a, b}, {c, b, a}};
    for (int i = 0; i < 6; i++)
    {
        *root1 = 0.0;
        *root2 = 0.0;
        int num_roots = solve_quadratic(epsilon, permutations[i][0], permutations[i][1], permutations[i][2], root1, root2);
        puts("---------------------------------------------------------------------------------------------------");
        printf("a = %.15lf, b = %.15lf, c = %.15lf\n\n", permutations[i][0], permutations[i][1],
               permutations[i][2]);

        if (num_roots == 0)
            printf("Нет вещественных корней \n");
        else if (num_roots == 1)
            printf("Один корень: %.15lf\n", *root1);
        else if (num_roots == 2)
            printf("Два корня: %.15lf, %.15lf\n", *root1, *root2);

        else if (num_roots == 3)
            printf("Бесконечное колво решений\n");
    }
    puts("---------------------------------------------------------------------------------------------------");

    return E_SUCCESS;
}