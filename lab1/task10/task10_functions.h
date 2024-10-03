#ifndef __task10_functions_H__
#define __task10_functions_H__

#include "task10_main.h"

/* Functions prototypes below */
enum Errors delete_zeros_from_num(char *temp_number, unsigned long long num_length);
char *read_number_string();
enum Errors convert_to_decimal(char *number_string, int base, long long int *number);
char *convert_to_your_base_from_10CC(long long int number, int base);
enum Errors check_string_number_in_your_base(char *number_string, int base);


#endif // __task10_functions_H__