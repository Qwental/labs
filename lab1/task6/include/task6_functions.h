#ifndef __task6_functions_H__
#define __task6_functions_H__

#include "../../../include/DEFAULT_FUNCTIONS.h"

/* Functions prototypes below */

double integrate_function(double epsilon, double (*integral)(double));
double function_a(double x);
double function_b(double x);
double function_c(double x);
double function_d(double x);
double method_central_triangle(int number, double epsilon, double (*func_to_integrate)(double));

#endif // __task6_functions_H__