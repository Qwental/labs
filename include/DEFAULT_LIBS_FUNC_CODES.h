
#ifndef __DEFAULT_LIBS_FUNC_CODES_H__
#define __DEFAULT_LIBS_FUNC_CODES_H__

/* DEFAULT_LIBS Все инклуды тута */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <stdarg.h>
#include <sys/stat.h> // для работы с функцией stat() и структурой stat, которая хранит информацию о файле.


#define INITIAL_SIZE 20

/* ERRORS_EXIT_CODES или enum Errors - КОДЫ ВОЗВРАТА ДЛЯ ФУНКЦИЙ */
typedef enum Errors
{
    E_SUCCESS = 0,                /* Успешное завершение */
    E_INVALID_INPUT = 1,          /* Ошибка: Некорректный ввод */
    E_NOT_ENOUGH_PARAMS = 2,      /* Ошибка: Отсутвует аргумент */
    E_INVALID_ARG = 3,            /* Ошибка: Неправильный аргумент */
    E_TYPE_OVERFLOW = 4,          /* Ошибка: Недостаточно памяти для записи значения некоторого типа */
    E_MEMORY_ALLOCATION = 5,      /* Ошибка: Выделении памяти */
    E_CANNOT_OPEN_FILE = 6,       /* Ошибка: ОТКРЫТИЯ ФАЙЛА */
    E_INVALID_EPSILON = 7,        /* Ошибка: Невалидного числа эпсилон*/
    E_DEREFENCE_NULL_POINTER = 8, /* Ошибка: Попытка разыменовать Dereference NULL */
    E_INT_OVERFLOW = 9,           /* Ошибка: Переполнение типа INT */
    E_LONG_OVERFLOW = 10,         /* Ошибка: Переполнение типа LONG INT */
    E_FLOAT_OVERFLOW = 11,        /* Ошибка: Переполнение типа FLOAT */
    E_DOUBLE_OVERFLOW = 12,       /* Ошибка: Переполнение типа DOUBLE */
    E_LONG_DOUBLE_OVERFLOW = 13,  /* Ошибка: Переполнение типа DOUBLE */
    E_INVALID_FLAG_ARG = 15,      /* Ошибка: Неккорекный ввод аргументов (флагов), они должны начинаться с символов '-' или '/' */
    E_SAME_FILE_NAMES = 14,       /* Ошибка: Одинаковые имена файлов */
    E_BUFFER_OVERFLOW = 16,       /* Ошибка: Переполнение буффера */
    E_SAME_FILES = 17, /* Ошибка: Ввод одинковых файлов */

} ERRORS_EXIT_CODES;

#endif // __DEFAULT_LIBS_FUNC_CODES_H__