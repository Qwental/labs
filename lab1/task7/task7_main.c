#include "task7_functions.h"

int main(int argc, char *argv[])
{
    if ((argc <= 2))
        return print_Errors(E_INVALID_ARG);
    if (argv[1][0] != '-' && argv[1][0] != '/')
    {
        printf("ERROR: Неккорекный ввод аргументов, они должны начинаться с символов '-' или '/' \n");
        return E_INVALID_ARG;
    }
    char flag = argv[1];
    switch (flag)
    {
    case 'r':
        printf("rrrrrrrrfdfd\n");
        break;
    case 'a':
        printf("aaaaaaaaaaafdfd\n");
        break;
    default:
        break;
    }

    return print_Errors(E_SUCCESS);
}