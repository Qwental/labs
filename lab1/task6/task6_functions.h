#ifndef __task6_functions_H__
#define __task6_functions_H__

#include "task6_main.h"

/* Functions prototypes below */

ERRORS_EXIT_CODES print_Errors(enum Errors error);
ERRORS_EXIT_CODES string_to_double(const char *str, double *num);
enum Errors is_double_overflow(double to_check);
double integrate_function(double epsilon, double (*integral)(double));
double function_a(double x);
double function_b(double x);
double function_c(double x);
double function_d(double x);
double method_central_triangle(int number, double epsilon, double (*function)(double));


#endif // __task6_functions_H__