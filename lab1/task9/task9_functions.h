#ifndef __task9_functions_H__
#define __task9_functions_H__

#include "task9_main.h"

/* Functions prototypes below */

ERRORS_EXIT_CODES string_to_int(const char *str_number, int *int_result_number, int base);
ERRORS_EXIT_CODES print_Errors(enum Errors error);
void print_and_swap_max_and_min(int *array, int length);
void print_int_array(const int *array, int length);
int compare_ints(const void *a, const void *b);
int find_nearest_number(int number_arr_i, int length, int *array_B);

#endif // __task9_functions_H__