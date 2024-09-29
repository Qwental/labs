#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

#define INITIAL_SIZE 36

enum Errors{
    E_SUCCESS = 0, /* успешное завершение */
    E_INVALID_INPUT = -1, /* некорректный ввод */
    E_NOT_ENOUGH_PARAMS = -2, /* отсутвует аргумент */
    E_INVALID_ARG = -3, /* неправильный аргумент */
    E_TYPE_OVERFLOW = -4, /* недостаточно памяти для записи значения некоторого типа */
    E_MEMORY_ALLOCATION = -5, /* Ошибка выделении памяти*/
};

enum Errors delete_zeros_from_num(char *temp_number, unsigned long long num_length);
char *read_number_string();
enum Errors convert_to_decimal(char *number_string, int base, long long int *number);
char *convert_to_your_base_from_10CC(long long int number, int base);
enum Errors check_string_number_in_your_base(char *number_string, int base);


#endif // __FUNCTIONS_H__