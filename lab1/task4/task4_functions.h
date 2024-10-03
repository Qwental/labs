#ifndef __task4_functions_H__
#define __task4_functions_H__

#include "task4_main.h"
char *convert_to_your_base_from_10CC( int number, int base);

const char *find_file_name(const char *file_string);
enum Errors delete_arabic_funny_numbers(const char *file_input, const char *file_output);
enum Errors how_many_latin_symbols_for_each_line(const char *file_input, const char *file_output);
enum Errors how_many_special_symbols_for_each_line(const char *file_input, const char *file_output);
enum Errors change_symbols_to_ascii_code(const char *file_input, const char *file_output);

#endif // __task4_functions_H__