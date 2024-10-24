#include "../../include/DEFAULT_FUNCTIONS.h"
#include "include/task2_4_functions.h"

int main()
{

    // 4.1
    printf("POINT 1\n");

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
    printf("POINT 2\n");

    ERRORS_EXIT_CODES error;
    long double result = 0;
    error = polynomial(&result, 2, 2.0, 3.0, 4.0, 1.0);
    if (error != E_SUCCESS)
        return print_Errors(error);
    printf("P(n=2, x=2, 3, 4, 1) = %Lf\n", result);

    error = polynomial(&result, 3, 3.0, 1.0, 2.0, 3.0, 4.0);
    if (error != E_SUCCESS)
        return print_Errors(error);
    printf("P(n=3, x=3, 1, 2, 3, 4) = %Lf\n", result);

    // 4.3

    char *result3 = NULL;
    int base = 10;
    printf("POINT 3\n");
    puts("Ввели в 10СС:  1, 9, 45, 55, 99, 297, 703, 999, 2223, 2728, 4879, 4950, 5050, 7272, 7777, 9999, 17344, 994708");
    print_point3(18, result3, base, "1", "9", "45", "55", "99", "297", "703", "999", "2223", "2728", "4879", "4950", "5050", "7272", "7777", "9999", "17344", "994708");
    puts("Ввели в 10СС:  0, 11");

    print_point3(2, result3, base, "0", "11");
    puts("Ввели в 10СС:  99999999999999999999999, 11");

    print_point3(2, result3, base, "99999999999999999999999", "11");

    puts("Ввели в 10СС: 45, 55,11 ,1");

    print_point3(4, result3, base, "45", "55", "11", "1");
    puts("Ввели в 12СС:  1, 9, 56, 66");
    base = 12;
    print_point3(4, result3, base, "1", "9", "56", "66");
    puts("Ввели в 16СС:  1, 6, A, F, 5B, 78, D5D5");
    base = 16;
    print_point3(8, result3, base, "1", "6", "A", "F", "55", "5B", "78", "D5D5");
    puts("Ввели в 16СС: FFFF, -12, 2D02E, 345353");
    print_point3(4, result3, base, "FFFF", "-12", "2D02E", "345353");

    return E_SUCCESS;
}
