#include "../../include/DEFAULT_FUNCTIONS.h"
#include "include/task7_functions.h"

int main(int argc, char *argv[])
{
    if ((argc <= 2))
        return print_Errors(E_NOT_ENOUGH_PARAMS);

    if ((argv[1][0] != '-' && argv[1][0] != '/') && (argv[1][2] == '\0'))
        return print_Errors(E_INVALID_FLAG_ARG);

    char flag;
    flag = argv[1][1];
    int last_file_index = argc - 1;

    switch (flag)
    {
    case 'r':
        if ((argc < 5))
            return print_Errors(E_NOT_ENOUGH_PARAMS);
        return print_Errors(func_flag_r(argv[2], argv[3], argv[last_file_index]));
    case 'a':
        if ((argc < 4))
            return print_Errors(E_NOT_ENOUGH_PARAMS);
        return print_Errors(func_flag_a(argv[2], argv[last_file_index]));
    default:
        return print_Errors(E_INVALID_INPUT);
    }

    return print_Errors(E_INVALID_INPUT);
}