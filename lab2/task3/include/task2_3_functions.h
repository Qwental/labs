#ifndef __task2_3_functions_H__
#define __task2_3_functions_H__

#include "../../../include/DEFAULT_FUNCTIONS.h"

#define INITIAL_D 12

ERRORS_EXIT_CODES search_pattern_in_files(char *pattern, long long number_of_files, ...);

// typedef struct line_position
// {
//     size_t number_line;
//     size_t number_column;
// } Line_position;

// typedef struct files_with_pattern
// {
//     char *file_name;
//     size_t number_of_pattern_in_file;
//     Line_position* array_of_line_and_columns;

// } Files_with_Pattern;
char **create_dynamic_array(int rows, int cols);
void free_dynamic_array(char **array, int rows);


ERRORS_EXIT_CODES len_string(const char *string, long long *length);

const char *find_file_name(const char *file_string);
#endif // __task2_3_functions_H__
