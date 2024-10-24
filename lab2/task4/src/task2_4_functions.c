#include "../include/task2_4_functions.h"

int cross_composition(coord_point A, coord_point B, coord_point C)
{
    return (((B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x)) >= 0.0) ? 1 : 0;
}

int is_convex(int number_of_points, ...)
{
    if (number_of_points <= 2)
        return 0;
    if (number_of_points <= 3)
        return 1;

    coord_point point_first, point_second, point_third, point1, point2;

    va_list args; //  список аргументов

    va_start(args, number_of_points);

    point_first = va_arg(args, coord_point);
    point_second = va_arg(args, coord_point);
    point_third = va_arg(args, coord_point);

    int sign_cross_comp = cross_composition(point_first, point_second, point_third);

    point1 = point_first;
    point2 = point_second;

    for (int i = 0; i < number_of_points - 3; i++)
    {
        // B C D ... C D E ... and etc.
        point1 = point2;
        point2 = point_third;
        point_third = va_arg(args, coord_point);

        if (cross_composition(point1, point2, point_third) != sign_cross_comp)
        {
            va_end(args);
            return 0;
        }
    }

    if (cross_composition(point2, point_third, point_first) != sign_cross_comp)
    {
        va_end(args);
        return 0;
    }

    if (cross_composition(point_third, point_first, point_second) != sign_cross_comp)
    {
        va_end(args);
        return 0;
    }
    return 1;
}

// Функция для вычисления значения многочлена
ERRORS_EXIT_CODES polynomial(long double *polynomial_result_x, int n, double x, ...)
{
    if (polynomial_result_x == NULL)
        return E_DEREFENCE_NULL_POINTER;

    (*polynomial_result_x) = 0.0;

    if (n <= 0)
        return E_INVALID_INPUT;

    va_list args;
    va_start(args, x); // Инициализируем список аргументов
    long double coefficient;

    long double powx = 1;

    for (int i = 0; i <= n; i++)
    {
        coefficient = va_arg(args, double);
        // Извлекаем следующий коэффициент
        (*polynomial_result_x) += coefficient * powx; // Добавляем a_i * x^i к результату
        powx *= x;
        if (isinf(*polynomial_result_x) || isnan(*polynomial_result_x) || powx > (HUGE_VAL/x))
        {
            va_end(args);
            return E_DOUBLE_OVERFLOW;
        }
    }
    va_end(args); // Завершаем работу с аргументами
    return E_SUCCESS;
}

// Функция для проверки, является ли число Капрекара
ERRORS_EXIT_CODES number_is_Kaprekar(const char *string_number, int base)
{
    if (base < 2 || base > 36)
        return E_INVALID_INPUT;

    if (string_number == NULL)
        return E_DEREFENCE_NULL_POINTER;

    ERRORS_EXIT_CODES error;

    long long int number;
    error = string_to_long_long_int(string_number, &number, base);
    if (error != E_SUCCESS)
        return error;
    if (number == 1)
    {
        return E_SUCCESS;
    }
    if (number <= 0)
        return E_FALSE;

    if (overflow_long_product_of_a_b(number, number) != E_SUCCESS)
        return E_LONG_OVERFLOW;

    size_t square = (size_t)(number * number);
    char *string_square_in_base = convert_to_your_base_from_10CC_longlongint(square, base);

    size_t len_square = 0;
    if (len_string(string_square_in_base, &len_square) != E_SUCCESS)
    {
        return E_DEREFENCE_NULL_POINTER;
    }

    // size_t k = (size_t)(len_square / 2);
    long long int left_num = 0;
    long long int right_num = 0;

    char *left = NULL;
    char *right = NULL;
    for (size_t split_pos = 1; split_pos < len_square; split_pos++)
    {
        left = (char *)malloc(sizeof(char) * (split_pos + 1)); // +1 для '\0'
        if (left == NULL)
        {
            return E_MEMORY_ALLOCATION;
        }
        right = (char *)malloc(sizeof(char) * (len_square - split_pos + 1));
        if (right == NULL)
        {
            free(left);
            return E_MEMORY_ALLOCATION;
        }

        // Заполняем левую
        strncpy(left, string_square_in_base, split_pos);
        left[split_pos] = '\0';
        // Заполняем правую
        strncpy(right, string_square_in_base + split_pos, len_square - split_pos);
        right[len_square - split_pos] = '\0';

        // Преобразуем обе части в 10cc
        error = convert_to_decimal(left, base, &left_num);
        if (error != E_SUCCESS)
        {
            free(left);
            free(right);
            return error;
        }

        error = convert_to_decimal(right, base, &right_num);
        if (error != E_SUCCESS)
        {
            free(left);
            free(right);
            return error;
        }

        // printf("%lld + %lld  = %lld\n", left_num, right_num, right_num + left_num);

        // Проверяем условие Капрекара
        if ((left_num + right_num == number))
        {
            free(left);
            free(right);
            return E_SUCCESS; // Это число Капрекара
        }
        free(left);
        free(right);
    }

    return E_FALSE; // Это не число Капрекара
}

ERRORS_EXIT_CODES print_point3(int count_numbers, char *result, int base, ...)
{
    int len_result = BUFSIZ;
    const char *separator = ", ";

    result = (char *)malloc(sizeof(char) * (len_result + 1 + strlen(separator)));
    if (result == NULL)
    {
        return E_MEMORY_ALLOCATION;
    }
    result[0] = '\0';
    int flag = 0;
    va_list args;
    va_start(args, base);
    ERRORS_EXIT_CODES error;
    for (int i = 0; i < count_numbers; i++)
    {
        char *string_num = va_arg(args, char *);
        if (string_num == NULL)
        {
            free(result);
            return E_DEREFENCE_NULL_POINTER;
        }
        error = number_is_Kaprekar(string_num, base);
        if (error == E_SUCCESS)
        {
            if (i >= len_result)
            {
                len_result *= 2;
                char *temp = (char *)realloc(result, sizeof(char) * (len_result + 1 + strlen(separator)));
                if (temp == NULL)
                {
                    free(result);
                    va_end(args);
                    return E_MEMORY_ALLOCATION;
                }
                result = temp;
            }
            strcat(result, string_num);
            strcat(result, separator);

            flag = 1;
        }
        else if (error == E_FALSE)
            continue;
        else
        {
            free(result);
            return print_Errors(error);
        }
    }
    if (flag)
        printf("  Результат: Числа %s являются числами Капрекара в СС=%d\n", result, base);
    else
        printf("  Результат: Среди введенных чисел нет чисел Капрекара\n");
    free(result);
    va_end(args);
    return E_SUCCESS;
}

ERRORS_EXIT_CODES len_string(const char *string, size_t *length)
{
    // КОД с пары Ильи
    if (string == NULL)
    {
        return E_DEREFENCE_NULL_POINTER;
    }
    const char *start = string;
    while (*string++)
        ;
    *length = string - start - 1;
    return E_SUCCESS;
}

/* Функция быстрого возведения в степень вещественного числа */
long double my_fast_pow(double x, int n)
{
    // предельный случай
    if ((fabs(x) <= DBL_EPSILON) && (n < 0))
    {
        return INFINITY;
    }

    //  Базовый случай: x^0 = 1
    if (n == 0)
        return 1.0;
    // Если степень отрицательная, преобразуем её к положительной
    if (n < 0)
        return 1.0 / my_fast_pow(x, (-1.0) * n);

    long double half = my_fast_pow(x, (int)(n / 2));

    if (!(n & 1))
        return half * half; // Если n чётное, используем half * half
    else
        return x * half * half; // Если n нечётное, учитываем лишнее умножение на x
}