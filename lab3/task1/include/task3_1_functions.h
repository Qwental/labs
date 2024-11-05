#ifndef __task3_1_functions_H__
#define __task3_1_functions_H__

#include "../../../include/DEFAULT_FUNCTIONS.h"

#define INIT_SIZE_FOR_NUMBER BUFSIZ

ERRORS_EXIT_CODES convert_int_number_from_base_10_to_r(int number, int r, char *result, int *length);
ERRORS_EXIT_CODES print_result(const char *result, int length, int number, int base);

#endif // __task3_1_functions_H__