#ifndef __task2_4_functions_H__
#define __task2_4_functions_H__

#include "../../../include/DEFAULT_FUNCTIONS.h"

#define INIT_SIZE 100

typedef struct Coordinate_Point
{
    double x;
    double y;
} coord_point;

int is_convex(int number_of_points, ...);
int cross_composition(coord_point A, coord_point B, coord_point C);
ERRORS_EXIT_CODES polynomial(long double *polynomial_result_x, int n, double x, ...);
long double my_fast_pow(double x, int n);

ERRORS_EXIT_CODES is_kaprekar(int count_numbers, char *result, int base, ...);

#endif // __task2_4_functions_H__

/*


треугольник всегда является выпуклым многоугольником.

У любого треугольника все его внутренние углы меньше 180 градусов.
Любые две точки внутри или на границах треугольника можно соединить отрезком, который полностью лежит внутри треугольника.
Треугольник не может иметь вогнутых частей, так как он имеет всего три стороны, и все углы строго меньше 180 градусов.
Таким образом, любой треугольник (равносторонний, равнобедренный, разносторонний) всегда является выпуклым многоугольником

*/