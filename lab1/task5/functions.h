#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <float.h>


#define INITIAL_SIZE 36
#define MAX_EPS_LEN 10


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

double factorial(int n);
enum Errors string_to_double(const char *str, double *num);
enum Errors func_a(double x, double epsilon, double *sigma_sum);
enum Errors func_b(double x, double epsilon, double *sigma_sum);
enum Errors func_c(double x, double epsilon, double *sigma_sum);
enum Errors func_d(double x, double epsilon, double *sigma_sum);


#endif // __FUNCTIONS_H__