
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
#define INIT_SIZE_SMALL 10

#define MY_BUFFER 128 

/* ERRORS_EXIT_CODES или enum Errors - КОДЫ ВОЗВРАТА ДЛЯ ФУНКЦИЙ */
typedef enum Errors
{
    E_SUCCESS = 0,            /* Успешное завершение */
    E_INVALID_INPUT,          /* Ошибка: Некорректный ввод */
    E_NOT_ENOUGH_PARAMS,      /* Ошибка: Отсутвует аргумент */
    E_INVALID_ARG,            /* Ошибка: Неправильный аргумент */
    E_TYPE_OVERFLOW,          /* Ошибка: Недостаточно памяти для записи значения некоторого типа */
    E_MEMORY_ALLOCATION,      /* Ошибка: Выделении памяти */
    E_CANNOT_OPEN_FILE,       /* Ошибка: ОТКРЫТИЯ ФАЙЛА */
    E_INVALID_EPSILON,        /* Ошибка: Невалидного числа эпсилон*/
    E_DEREFENCE_NULL_POINTER, /* Ошибка: Попытка разыменовать Dereference NULL */
    E_INT_OVERFLOW,           /* Ошибка: Переполнение типа INT */
    E_LONG_OVERFLOW,          /* Ошибка: Переполнение типа LONG INT */
    E_FLOAT_OVERFLOW,         /* Ошибка: Переполнение типа FLOAT */
    E_DOUBLE_OVERFLOW,        /* Ошибка: Переполнение типа DOUBLE */
    E_LONG_DOUBLE_OVERFLOW,   /* Ошибка: Переполнение типа DOUBLE */
    E_INVALID_FLAG_ARG,       /* Ошибка: Неккорекный ввод аргументов (флагов), они должны начинаться с символов '-' или '/' */
    E_SAME_FILE_NAMES,        /* Ошибка: Одинаковые имена файлов */
    E_BUFFER_OVERFLOW,        /* Ошибка: Переполнение буффера */
    E_SAME_FILES,             /* Ошибка: Ввод одинковых файлов */
    E_FALSE,                  /* BOOL_FALSE */

} ERRORS_EXIT_CODES;

#endif // __DEFAULT_LIBS_FUNC_CODES_H__