#include "../../include/DEFAULT_FUNCTIONS.h"
#include "include/task2_functions.h"

int main(int args, char *argv[])
{
    if (args != 2)
        return print_Errors(E_INVALID_ARG);

    double epsilon;
    ERRORS_EXIT_CODES error;

    error = string_to_double(argv[1], &epsilon);
    if (error != E_SUCCESS)
        return print_Errors(error);
    if (epsilon <= 0 || epsilon > 1)
        return print_Errors(E_INVALID_EPSILON);

    if (epsilon < 0.000000001)
    {
        printf("При введенном epsilon = %.30lf программа будет долго считать интегралы\n", epsilon);
        return E_INVALID_EPSILON;
    }

    printf("\n%-5s%s %-15s  %s%-15s %s%15s\n", " ", "|", "LIM", " | ", "Row/Composition", "  |", "Equation");
    printf("-----------------------------------------------------------------\n");

    printf("%-5s%s %.15f %s%.15f %s%.15f\n", "e", "|", calculate_lim_Euler_number_e(epsilon),
           "| ", calculate_row_Euler_number_e(epsilon), "| ", calculate_equation_Euler_number_e(epsilon));
    printf("-----------------------------------------------------------------\n");

    printf("%-5s%s %.15f %s%.15f %s%.15f\n", "pi", "|", calculate_lim_Pi_number(epsilon),
           "| ", calculate_row_Pi_number(epsilon), "| ", calculate_equation_Pi_number(epsilon));
    printf("-----------------------------------------------------------------\n");

    printf("%-5s%s %.15f %s%.15f %s%.15f\n", "ln2", "|", calculate_lim_ln2(epsilon), "| ",
           calculate_row_ln2(epsilon), "| ", calculate_equation_ln2(epsilon));
    printf("-----------------------------------------------------------------\n");

    printf("%-5s%s %.15f %s%.15f %s%.15f\n", "sqrt2", "|", calculate_lim_sqrt2(epsilon), "| ",
           calculate_Composition_sqrt2(epsilon), "| ", calculate_equation_sqrt2(epsilon));
    printf("-----------------------------------------------------------------\n");

    // Постоянная Эйлера — Маскерони 0.5772156649

    // lim https://math.fandom.com/ru/wiki/%D0%9F%D0%BE%D1%81%D1%82%D0%BE%D1%8F%D0%BD%D0%BD%D0%B0%D1%8F_%D0%AD%D0%B9%D0%BB%D0%B5%D1%80%D0%B0_%E2%80%94_%D0%9C%D0%B0%D1%81%D0%BA%D0%B5%D1%80%D0%BE%D0%BD%D0%B8#:~:text=%D0%9F%D0%BE%D1%81%D1%82%D0%BE%D1%8F%D0%BD%D0%BD%D0%B0%D1%8F%20%D0%AD%CC%81%D0%B9%D0%BB%D0%B5%D1%80%D0%B0%E2%80%94%D0%9C%D0%B0%D1%81%D0%BA%D0%B5%D1%80%D0%BE%CC%81%D0%BD%D0%B8%20%D0%B8%D0%BB%D0%B8%20%D0%BF%D0%BE%D1%81%D1%82%D0%BE%D1%8F%D0%BD%D0%BD%D0%B0%D1%8F,%7D%2D%5Cln%20n%5Cright)%7D

    printf("%-5s%s %.15f %s%.15f %s%.15Lf\n\n", "gamma", "|", calculate_lim_EulerMascheroni_constant(epsilon), "| ",
           calculate_Composition_EulerMascheroni_constant(epsilon), "| ", calculate_equation_EulerMascheroni_constant(epsilon));
}
