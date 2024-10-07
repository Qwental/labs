#ifndef __task3_functions_H__
#define __task3_functions_H__

#include "task3_main.h"

enum Errors is_double_overflow(double to_check);
enum Errors flag_m_is_number_multiple(const long long int number_1, const long long int number_2, int *result);
enum Errors string_to_double(const char *str, double *num);
enum Errors print_Errors(enum Errors error);
enum Errors flag_q_solution();
enum Errors flag_t_is_sides_triangle_possible(const double eps, const double sides[], int *result);
enum Errors string_to_int(const char *str_number, long long int *int_result_number, int base);
int solve_quadratic(double epsilon, double a, double b, double c, double *root1, double *root2);

enum Errors flag_q_Permutation_ABC_Print(double epsilon, double a, double b, double c, double *root1, double *root2);

#endif // __task3_functions_H__