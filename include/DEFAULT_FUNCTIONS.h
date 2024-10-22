#ifndef __DEFAULT_FUNCTIONS_h__
#define __DEFAULT_FUNCTIONS_h__ 

#include "DEFAULT_LIBS_FUNC_CODES.h"

/* Функция print_Errors выводит ошибку в консоль и возвращает код ошибки*/
ERRORS_EXIT_CODES print_Errors(const enum Errors error);

/* Обратная схема Горнера, из 10СС int в BASE CC int*/
char *convert_to_your_base_from_10CC(int number, int base);

/* Перевод строки в double */
ERRORS_EXIT_CODES string_to_double(const char *str, double *num);

/* Перевод строки в long long int */
ERRORS_EXIT_CODES string_to_long_long_int(const char *str_number, long long int *int_result_number, int base);

/*Cхема Горнера, из BASE СС string в 10 CC LONG LONG INT */
ERRORS_EXIT_CODES convert_to_decimal(char *number_string, int base, long long int *number);

/* Проверка переполнения Double*/
ERRORS_EXIT_CODES is_double_overflow(double to_check);

/* Перевод строки в int */
ERRORS_EXIT_CODES string_to_int(const char *str_number, int *int_result_number, int base);

/* Проверка на разные файлы */
ERRORS_EXIT_CODES cheak_files(const char *path_file_1,const char *path_file_2);



#endif // __DEFAULT_FUNCTIONS_h__ 
