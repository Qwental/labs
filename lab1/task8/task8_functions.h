#ifndef __task10_functions_H__
#define __task10_functions_H__

#include "task8_main.h"

/* Functions prototypes below */
const char *find_file_name(const char *file_string);
int charToValue(char ch);
int findMinBase(const char *num);
enum Errors convert_to_decimal(char *number_string, int base, long long int *number);




#endif // __task10_functions_H__