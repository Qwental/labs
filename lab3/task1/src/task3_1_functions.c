#include "../include/task3_1_functions.h"

int arithmetic_addition_integers(int a, int b)
{
    int sum_of_units;
    while (b)
    {
        sum_of_units = a ^ b; // суммирование без переноса
        b = (a & b) << 1; //перенос сдвигаем  влево
        a = sum_of_units;
    }
    return sum_of_units;
}

int negative_integer_number(int a)
{
    /*  Так как при инвертировании мы получаем отриц. число на 1 ед. меньше изначального,
        то над прибавить 1   */
    return arithmetic_addition_integers(~a, 1);
}

ERRORS_EXIT_CODES convert_int_number_from_base_10_to_r(int number, int r, char *result, int *length)
{
    if (result == NULL)
    {
        return E_DEREFENCE_NULL_POINTER;
    }

    if (r < 1 || r > 5)
    {
        return E_INVALID_INPUT;
    }

    int mask;
    int digit_and_index;
    char base_symbols[] = "0123456789ABCDEFGHIJKLMNOPQRSTUV"; // все символы в 32сс
    int sign_flag = 0;

    *length = 0;

    if (number < 0)
    {
        sign_flag = 1;
        number = negative_integer_number(number);
    }
    mask = arithmetic_addition_integers(1 << r, negative_integer_number(1)); // получаем маску, чтоб получать по ней циферки

    /*

    31 - 11111
    15 -  1111
    7  -   111
    3  -    11
    1  -     1

    если умножать числа по этой маске, то получим значение цифр в этой сс

    */

    while (number > 0)
    {
        digit_and_index = number & mask; // получаем число в сс 2^r, которое также является индексом в массиве символов
        result[*length] = base_symbols[digit_and_index];
        *length = arithmetic_addition_integers(*length, 1);
        number = number >> r; // переходим к нескт цифре в сс 2^r
    }

    if (sign_flag == 1)
    {
        result[*length] = '-';
        *length = arithmetic_addition_integers(*length, 1);
    }

    return E_SUCCESS;
}

ERRORS_EXIT_CODES print_result(const char *result, int length, int number, int r)
{
    if (result == NULL)
    {
        return E_DEREFENCE_NULL_POINTER;
    }
    // В ОБРАТНОМ ПОРЯДКЕ ВЫВОДИМ
    int i = arithmetic_addition_integers(length, negative_integer_number(1));
    printf("Результат перевода числа %d из 10 СС в %d СС : ", number, 1 << r);

    for (; i >= 0; i = arithmetic_addition_integers(i, negative_integer_number(1)))
    {
        putchar(result[i]);
    }
    putchar('\n');
    return E_SUCCESS;
}