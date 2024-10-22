#include "../../include/DEFAULT_FUNCTIONS.h"
#include "include/task2_4_functions.h"

int main()
{

    // 4.1
    coord_point p1 = (coord_point){0, 0};
    coord_point p2 = (coord_point){4, 0};
    coord_point p3 = (coord_point){5, 3};
    coord_point p4 = (coord_point){2, 5};
    coord_point p5 = (coord_point){-1, 3};

    printf("A{0,0}, B{4, 0}, C{5, 3}, D{2, 5}, E{-1, 3} - выпуклый\n");
    if (is_convex(5, p1, p2, p3, p4, p5))
        printf("Вывод функции: ВЫПУКЛЫЙ\n");
    else
        printf("Вывод функции: НЕ ВЫПУКЛЫЙ\n");

    p1 = (coord_point){0, 0};
    p2 = (coord_point){4, 0};
    p3 = (coord_point){2, 2};
    p4 = (coord_point){4, 4};
    p5 = (coord_point){0, 4};

    printf("A{0,0}, B{4, 0}, C{2, 2}, D{4, 4}, E{0, 4} - НЕ выпуклый\n");
    if (is_convex(5, p1, p2, p3, p4, p5))
        printf("Вывод функции: ВЫПУКЛЫЙ\n");
    else
        printf("Вывод функции: НЕ ВЫПУКЛЫЙ\n");

    p1 = (coord_point){0, 0};
    p2 = (coord_point){1, 0};
    p3 = (coord_point){0, 1};

    printf("A{0,0}, B{1, 0}, C{0, 1} - Треугольник\n");
    if (is_convex(3, p1, p2, p3))
        printf("Вывод функции: ВЫПУКЛЫЙ\n");
    else
        printf("Вывод функции: НЕ ВЫПУКЛЫЙ\n");

    // 4.2
    ERRORS_EXIT_CODES error;
    long double result = 0;
    error = polynomial(&result, 2, 2.0, 3.0, 4.0, 1.0);
    if (error != E_SUCCESS)
        return print_Errors(error);
    printf("P(n=2, x=2, 3, 2, 1) = %Lf\n", result);

    error = polynomial(&result, 3, 3.0, 1.0, 2.0, 3.0, 4.0);
    if (error != E_SUCCESS)
        return print_Errors(error);

    printf("P(n=3, x=3, 1, 2, 3, 4) = %Lf\n", result);

    // 4.3

    return E_SUCCESS;
}
