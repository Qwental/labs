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
    for (int i = 0; i <= n; i++)
    {
        coefficient = va_arg(args, double);                        // Извлекаем следующий коэффициент
        (*polynomial_result_x) += coefficient * my_fast_pow(x, i); // Добавляем a_i * x^i к результату

        if (isinf(*polynomial_result_x) || isnan(*polynomial_result_x))
        {
            va_end(args);
            return E_DOUBLE_OVERFLOW;
        }
    }

    va_end(args); // Завершаем работу с аргументами

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

// Функция для проверки, является ли число Капрекара
ERRORS_EXIT_CODES is_kaprekar(int count_numbers, char *result, int base, ...)
{
    if (base < 2 || base > 36)
        return E_INVALID_INPUT;

    long long int len_result = INIT_SIZE;

    result = (char *)malloc(sizeof(char) * len_result);
    if (result == NULL)
    {
        return E_MEMORY_ALLOCATION;
    }
    result[0] = '\0';

    va_list args;
    va_start(args, base);
    ERRORS_EXIT_CODES error;
    long long int n;
    for (int j = 0; j < count_numbers; j++)
    {
        error = string_to_long_long_int(va_arg(args, char *), &n, 10);
        if (error != E_SUCCESS)
        {
            va_end(args);
            return error;
        }
        // ОБРАБОТАКА ОДНОГО ЧИСЛА
        if (n == 1)
            return 1; // 1 всегда является числом Капрекара

        long long square = n * n;
        int num_digits = 0;

        // Вычисляем количество цифр в квадрате числа
        long long temp = square;
        while (temp)
        {
            num_digits++;
            temp /= 10;
        }
        long long power, left, right;
        // Проверяем все возможные способы разделения квадрата на две части
        for (int i = 1; i < num_digits; i++)
        {
            power = pow(10, i); // Разделяем квадрат на две части
            left = square / power;
            right = square % power;

            // Проверяем условие числа Капрекара
            if (right > 0 && left + right == n)
            {
                // Число является числом Капрекара
                strcat(result,????);
            }
        }
    }
    va_end(args);

    return E_SUCCESS; // Число не является числом Капрекара
}