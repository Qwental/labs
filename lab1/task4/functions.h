#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

#define INITIAL_SIZE 36

enum Errors
{
    E_SUCCESS = 0,            /* успешное завершение */
    E_INVALID_INPUT = -1,     /* некорректный ввод */
    E_NOT_ENOUGH_PARAMS = -2, /* отсутвует аргумент */
    E_INVALID_ARG = -3,       /* неправильный аргумент */
    E_TYPE_OVERFLOW = -4,     /* недостаточно памяти для записи значения некоторого типа */
    E_MEMORY_ALLOCATION = -5, /* Ошибка выделении памяти */
    E_CANNOT_OPEN_FILE = -6,  /* Ошибка ОТКРЫТИЯ ФАЙЛА */
};

const char *find_file_name(const char *file_string);
enum Errors delete_arabic_funny_numbers(const char *file_input, const char *file_output);
enum Errors how_many_latin_symbols_for_each_line(const char *file_input, const char *file_output);
enum Errors how_many_special_symbols_for_each_line(const char *file_input, const char *file_output);
enum Errors change_symbols_to_ascii_code(const char *file_input, const char *file_output);

#endif // __FUNCTIONS_H__