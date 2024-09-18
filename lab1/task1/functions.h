#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

# if 0
/* Лалка пиши по русски */
#include <locale.h>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
# endif



enum Errors{
    E_SUCCESS = 0, /* успешное завершение */
    E_INVALID_INPUT = -1, /* некорректный ввод */
    E_NOT_ENOUGH_PARAMS = -2, /* отсутвует аргумент */
    E_INVALID_ARG = -3, /* неправильный аргумент */
    E_NOT_ENOUGH_MEMORY = -4 /* недостаточно памяти для записи значения некоторого типа */
};

enum Errors string_to_int(const char *str_number, long long int *int_result_number, int base);

enum Errors factorial_x(long long int number_x, unsigned long long int *result_fact_x);


#endif