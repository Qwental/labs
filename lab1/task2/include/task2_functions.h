#ifndef __task2_functions_H__
#define __task2_functions_H__

#include "../../../include/DEFAULT_FUNCTIONS.h"

#define E 2.718281828459045235360
#define PI 3.14159265358979323846

/* Functions prototypes below */

double calculate_lim_Euler_number_e(double epsilon);
double calculate_row_Euler_number_e(double epsilon);
double calculate_equation_Euler_number_e(double epsilon);

double calculate_lim_Pi_number(double epsilon);
double calculate_row_Pi_number(double epsilon);
double calculate_equation_Pi_number(double epsilon);

double calculate_lim_ln2(double epsilon);
double calculate_row_ln2(double epsilon);
double calculate_equation_ln2(double epsilon);

double calculate_lim_sqrt2(double epsilon);
double calculate_Composition_sqrt2(double epsilon);
double calculate_equation_sqrt2(double epsilon);

double calculate_lim_EulerMascheroni_constant(double epsilon);
double calculate_Composition_EulerMascheroni_constant(double epsilon);
long double calculate_equation_EulerMascheroni_constant(double epsilon);

double sum_for_gamma(size_t n);
int is_prime(long long int number_x);
double Composition_p_for_gamma(double t);
double calculate_LIMIT_FOR_equation_EulerMascheroni_constant(double epsilon);



#endif // __task2_functions_H__