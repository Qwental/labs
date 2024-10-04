#include "task3_functions.h"

/*
 gcc task3_main.c task3_functions.c -o task3.out -lm -std=c99 -Woverflow -Wall

./task3.out

*/
int main(int argc, char *argv[])
{

    if ((argc < 2))
    {
        printf("ERROR: Неккорекный ввод, неправильное кол-во аргументов!!!!\n");
        return E_INVALID_ARG;
    }

    if (argv[1][0] != '-' && argv[1][0] != '/')
    {
        printf("ERROR: Неккорекный ввод аргументов, они должны начинаться с символов '-' или '/' \n");
        return E_INVALID_ARG;
    }

    char flag = argv[1][1];

    enum Errors error;
    double epsilon;
    int result = 0;

    switch (flag)
    {
    case 'q':
        if ((argc != 6))
        {
            printf("ERROR: Неккорекный ввод, неправильное кол-во аргументов ! ! \n");
            return E_INVALID_ARG;
        }

        /*
        ax^2+bx+c = 0
        a = senior_coefficient_a
        b = middle_coefficient_b
        c = junior_coefficient_c
        */

        double senior_coefficient_a;
        double middle_coefficient_b;
        double junior_coefficient_c;

        error = string_to_double(argv[2], &epsilon);

        if (error != E_SUCCESS)
        {
            print_Errors(error);
            return error;
        }

        error = string_to_double(argv[3], &senior_coefficient_a);
        if (error != E_SUCCESS)
        {
            print_Errors(error);
            return error;
        }

        error = string_to_double(argv[4], &middle_coefficient_b);
        if (error != E_SUCCESS)
        {
            print_Errors(error);
            return error;
        }

        error = string_to_double(argv[5], &junior_coefficient_c);
        if (error != E_SUCCESS)
        {
            print_Errors(error);
            return error;
        }

        double root1;
        double root2;

        flag_q_Permutation_ABC_Print(epsilon, senior_coefficient_a, middle_coefficient_b, junior_coefficient_c, &root1, &root2);

        break;

    case 'm':
        if ((argc != 4))
        {
            printf("ERROR: Неккорекный ввод, неправильное кол-во аргументов!!!!\n");
            return E_INVALID_ARG;
        }

        long long int number_1 = 0;
        long long int number_2 = 0;

        error = string_to_int(argv[2], &number_1, 10);
        if (error != E_SUCCESS)
        {
            print_Errors(error);
            return error;
        }
        error = string_to_int(argv[3], &number_2, 10);
        if (error != E_SUCCESS)
        {
            print_Errors(error);
            return error;
        }

        if ((number_1 == 0) || (number_2 == 0))
        {
            printf("ERROR: Некорректный ввод аргументов, следует вводить целые ненулевые числа\n");
            return E_INVALID_ARG;
        }
        if (flag_m_is_number_multiple(number_1, number_2, &result) != E_SUCCESS)
        {
            printf("ERROR: Неккорекный ввод\n");
            return E_INVALID_INPUT;
        }
        if (result)
            printf("Число %lld делиться на число %lld \n", number_1, number_2);
        else
            printf("Число %lld НЕ делиться на число %lld \n", number_1, number_2);

        break;

    case 't':
        if ((argc != 6))
        {
            printf("ERROR: Неккорекный ввод, неправильное кол-во аргументов! !!\n");
            return E_INVALID_ARG;
        }

        error = string_to_double(argv[2], &epsilon);
        if (error != E_SUCCESS)
        {
            print_Errors(error);
            return error;
        }

        double sides_of_rightangled_triangle[3];
        for (int i = 0; i < 3; i++)
        {
            error = string_to_double(argv[3 + i], &(sides_of_rightangled_triangle[i]));
            if (error != E_SUCCESS)
            {
                print_Errors(error);
                return error;
            }
        }

        if (flag_t_is_sides_triangle_possible(epsilon, (sides_of_rightangled_triangle), &result) != E_SUCCESS)
        {
            printf("ERROR: Неккорекный ввод\n");
            return E_INVALID_INPUT;
        }

        if (result)
            printf("+) Числа %.15lf %.15lf %.15lf \n являются пифагоровой тройков при epsilon = %.15lf \n", sides_of_rightangled_triangle[0],
                   sides_of_rightangled_triangle[1], sides_of_rightangled_triangle[2], epsilon);
        else
            printf("-)Числа %.15lf %.15lf %.15lf \n НЕ являются пифагоровой тройков при epsilon = %.15lf \n", sides_of_rightangled_triangle[0],
                   sides_of_rightangled_triangle[1], sides_of_rightangled_triangle[2], epsilon);

        break;

    default:
        printf("ERROR: Некоррекный ввод аргументов, такого ФЛАГА %c не предусмотрено!\n", flag);
        return E_INVALID_INPUT;
    }

    return E_SUCCESS;
}
