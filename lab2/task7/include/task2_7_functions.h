#ifndef __task2_7_functions_H__
#define __task2_7_functions_H__

#include "../../../include/DEFAULT_FUNCTIONS.h"
double FUNCTION_1(double x);

double FUNCTION_2(double x);
double FUNCTION_3(double x);
double FUNCTION_4(double x);

ERRORS_EXIT_CODES dichotomy(double a, double b, double *result, double (*FUNCTION)(double), const double epsilon);

#endif // __task2_7_functions_H__