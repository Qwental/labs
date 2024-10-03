#ifndef __task5_functions_H__
#define __task5_functions_H__

#include "task5_main.h"

/* Functions prototypes below */

enum Errors string_to_double(const char *str, double *num);
enum Errors func_a(double x, double epsilon, double *sigma_sum);
enum Errors func_b(double x, double epsilon, double *sigma_sum);
enum Errors func_c(double x, double epsilon, double *sigma_sum);
enum Errors func_d(double x, double epsilon, double *sigma_sum);


#endif // __task5_functions_H__