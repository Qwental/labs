#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>


enum Errors{
    E_SUCCESS = 0, /* успешное завершение */
    E_INVALID_INPUT = -1, /* некорректный ввод */
    E_NOT_ENOUGH_PARAMS = -2, /* отсутвует аргумент */
    E_INVALID_ARG = -3, /* неправильный аргумент */
    E_TYPE_OVERFLOW = -4, /* недостаточно памяти для записи значения некоторого типа */
    E_MEMORY_ALLOCATION = -5, /* Ошибка выделении памяти*/
};


//char *read_number_string(int base_of_num_system);



#endif // __FUNCTIONS_H__