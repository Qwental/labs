#include "../../include/DEFAULT_FUNCTIONS.h"
#include "include/task2_9_functions.h"

int main()
{
    double numbers_to_cheak[] = {0.100, 0.125, 0.3, 0.25, 0.5, 0.75, 0.857, 0.333333333333333333};
    long long *result_array = NULL;
    int base = 10;
    int number_of_numbers_to_cheak = 8;
    ERRORS_EXIT_CODES error = finit_cheak(&result_array, base, number_of_numbers_to_cheak, 0.100, 0.125, 0.3, 0.25, 0.5, 0.75, 0.857, 0.333333333333333333);

    if (error == E_SUCCESS)
    {
        for (long long i = 0; i < number_of_numbers_to_cheak; i++)
        {
            if ((result_array)[i] == 1)
                printf("Представление числа %.10f в СС %d имеет конечное представление\n", (numbers_to_cheak)[i], base);
            else
                printf("Представление числа %.10f в СС %d имеет НЕконечное представление\n", (numbers_to_cheak)[i], base);
        }

        free(result_array);
        result_array = NULL;
    }
    else
        print_Errors(error);
    puts(" ");
    base = 3;
    double numbers_to_cheak2[] = {0.100, 0.125, 0.3, 0.25, 0.5, 0.75, 0.857, 0.333333333333333333};
    error = finit_cheak(&result_array, base, number_of_numbers_to_cheak, 0.100, 0.125, 0.3, 0.25, 0.5, 0.75, 0.857, 0.333333333333333333);
    if (error == E_SUCCESS)
    {
        for (long long i = 0; i < number_of_numbers_to_cheak; i++)
        {
            if ((result_array)[i] == 1)
                printf("Представление числа %.10f в СС %d имеет конечное представление\n", (numbers_to_cheak2)[i], base);
            else
                printf("Представление числа %.10f в СС %d имеет НЕконечное представление\n", (numbers_to_cheak2)[i], base);
        }

        free(result_array);
        result_array = NULL;
    }
    else
        print_Errors(error);
    puts(" ");

    base = 6;
    double numbers_to_cheak3[] = {0.100, 0.125, 0.3, 0.25, 0.5, 0.75, 0.857, 0.333333333333333333};
    error = finit_cheak(&result_array, base, number_of_numbers_to_cheak, 0.100, 0.125, 0.3, 0.25, 0.5, 0.75, 0.857, 0.333333333333333333);
    if (error == E_SUCCESS)
    {
        for (long long i = 0; i < number_of_numbers_to_cheak; i++)
        {
            if ((result_array)[i] == 1)
                printf("Представление числа %.10f в СС %d имеет конечное представление\n", (numbers_to_cheak3)[i], base);
            else
                printf("Представление числа %.10f в СС %d имеет НЕконечное представление\n", (numbers_to_cheak3)[i], base);
        }

        free(result_array);
        result_array = NULL;
    }
    else
        print_Errors(error);

    return E_SUCCESS;
}




























//TODO мантисса, допкод
