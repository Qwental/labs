#include "../../include/DEFAULT_FUNCTIONS.h"
#include "include/task3_1_functions.h"

int main()
{

    char result[INIT_SIZE_FOR_NUMBER];
    int length = 0;
    int number;
    int r;
    ERRORS_EXIT_CODES error;

    r = 5;
    number = 128;

    if ((error = convert_int_number_from_base_10_to_r(number, r, result, &length)) != E_SUCCESS)
    {
        return print_Errors(error);
    }

    if ((error = print_result(result, length, number, r)) != E_SUCCESS)
    {
        return print_Errors(error);
    }

    memset(result, INIT_SIZE_FOR_NUMBER, sizeof(char));

    r = 5;
    number = -1111111;

    if ((error = convert_int_number_from_base_10_to_r(number, r, result, &length)) != E_SUCCESS)
    {
        return print_Errors(error);
    }

    if ((error = print_result(result, length, number, r)) != E_SUCCESS)
    {
        return print_Errors(error);
    }

    memset(result, INIT_SIZE_FOR_NUMBER, sizeof(char));

    r = 4;
    number = -77239;
    if ((error = convert_int_number_from_base_10_to_r(number, r, result, &length)) != E_SUCCESS)
    {
        return print_Errors(error);
    }

    if ((error = print_result(result, length, number, r)) != E_SUCCESS)
    {
        return print_Errors(error);
    }

    memset(result, INIT_SIZE_FOR_NUMBER, sizeof(char));

    r = 3;
    number = -1777;

    if ((error = convert_int_number_from_base_10_to_r(number, r, result, &length)) != E_SUCCESS)
    {
        return print_Errors(error);
    }

    if ((error = print_result(result, length, number, r)) != E_SUCCESS)
    {
        return print_Errors(error);
    }

    memset(result, INIT_SIZE_FOR_NUMBER, sizeof(char));

    r = 2;
    number = 16;

    if ((error = convert_int_number_from_base_10_to_r(number, r, result, &length)) != E_SUCCESS)
    {
        return print_Errors(error);
    }

    if ((error = print_result(result, length, number, r)) != E_SUCCESS)
    {
        return print_Errors(error);
    }

    memset(result, INIT_SIZE_FOR_NUMBER, sizeof(char));

    r = 1;
    number = -10;

    if ((error = convert_int_number_from_base_10_to_r(number, r, result, &length)) != E_SUCCESS)
    {
        return print_Errors(error);
    }

    if ((error = print_result(result, length, number, r)) != E_SUCCESS)
    {
        return print_Errors(error);
    }

    memset(result, INIT_SIZE_FOR_NUMBER, sizeof(char));

    return E_SUCCESS;
}