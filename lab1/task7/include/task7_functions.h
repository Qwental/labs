#ifndef __TASK7_FUNCTIONS_h__
#define __TASK7_FUNCTIONS_h__
#include "../../../include/DEFAULT_FUNCTIONS.h"

/* Прототипы функций ниже*/

const char *find_file_name(const char *file_string);

ERRORS_EXIT_CODES func_flag_r(const char *path_file1,
                              const char *path_file2,
                              const char *path_file3);

ERRORS_EXIT_CODES func_flag_a(const char *path_file1,
                              const char *path_file2);

ERRORS_EXIT_CODES string_to_lower_or_upper_case(char *leksem);
ERRORS_EXIT_CODES string_to_ascii_in_base(char *leksem, size_t base, char *buf);

#endif // __TASK7_FUNCTIONS_h__
