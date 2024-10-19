#ifndef __task2_1_functions_H__
#define __task2_1_functions_H__

#include "../../../include/DEFAULT_FUNCTIONS.h"
ERRORS_EXIT_CODES len_string(const char *string, size_t *length);
ERRORS_EXIT_CODES reverse_string(const char *input_string, char **output_string);
ERRORS_EXIT_CODES string_every_odd_one_to_uppercase(const char *input_string, char **output_string);
ERRORS_EXIT_CODES flag_n_string(const char *input_string, char **output_string);
char *string_concatination(char *output_string, const char *input_string);
void my_puts(const char *str);
ERRORS_EXIT_CODES flag_c_string(const char *input_string, char **output_string);
ERRORS_EXIT_CODES string_to_unsigned_long_int(const char *string, unsigned long *result);



#endif // __task2_1_functions_H__