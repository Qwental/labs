#include "task4_functions.h"

/*
 gcc task4_main.c task4_functions.c -lm -std=c99 -Woverflow -Wall -o task4.out

./task4.out

./task4.out -a /mnt/c/Users/Holiday/Desktop/Labs/labs/lab1/task4/test/digits

./task4.out -na /mnt/c/Users/Holiday/Desktop/Labs/labs/lab1/task4/test/digits digits
./task4.out -na /mnt/c/Users/Holiday/Desktop/Labs/labs/lab1/task4/test/digits /mnt/c/Users/Holiday/Desktop/Labs/labs/lab1/task4/test/digits


*/

int main(int argc, char *argv[])
{

    if ((argc <= 2))
        {
            printf("ERROR: Неккорекный ввод, неправильное кол-во аргументов!!!!\n");
            return E_INVALID_ARG;
        }

    if (argv[1][0] != '-' && argv[1][0] != '/')
    {
        printf("ERROR: Неккорекный ввод аргументов, они должны начинаться с символов '-' или '/' \n");
        return E_INVALID_ARG;
    }

    char flag_malloc = 0;

    char flag;
    const char *input_argument = argv[2];

    char *output = NULL;

    if (argv[1][1] == 'n')
    {
        if (argc != 4)
        {
            printf("ERROR: Неккорекный ввод, неправильное кол-во аргументов\n");
            return E_INVALID_ARG;
        }

        output = argv[3];

        if (strlen(argv[1]) != 3)
        {
            printf("ERROR: Неккорекный ввод аргументов\n");
            return E_INVALID_ARG;
        }

        if (strcmp(find_file_name(argv[2]), find_file_name(argv[3])) == 0)
        {
            printf("ERROR: Нужно ввести два файла с разными именами\n");
            return E_INVALID_ARG;
        }

        flag = argv[1][2];
    }
    else
    {
        if (strlen(argv[1]) != 2)
        {
            printf("ERROR: Неккорекный ввод аргументов\n");
            return E_INVALID_ARG;
        }
        if (argc != 3)
        {
            printf("ERROR: Неккорекный ввод аргументов\n");
            return E_INVALID_ARG;
        }

        flag = argv[1][1];

        char *prefix = "out_";
        const char *input_file = find_file_name(input_argument);

        output = (char *)malloc((strlen(input_file) + strlen(prefix) + 1) * sizeof(char));

        if (!output)
        {
            printf("ERROR: ошибка выделения динамической памяти\n");
            return E_MEMORY_ALLOCATION;
        }
        flag_malloc = 1;

        sprintf(output, "out_%s", input_file); // ПРИПИСЫВАЕМ К ИМЕНИ(АДРЕСУ) out_
    }

    enum Errors error;

    switch (flag)
    {
    case 'd':
        if (delete_arabic_funny_numbers(input_argument, output) != E_SUCCESS)
        {
            printf("ERROR: невозможно открыть файл\n");
            free(output);
            return E_CANNOT_OPEN_FILE;
        }
        break;

    case 'i':
        error = how_many_latin_symbols_for_each_line(input_argument, output);
        if (error == E_TYPE_OVERFLOW)
        {
            printf("ERROR: переполнения счетчика латинских символов \n");
            if (flag_malloc)
                free(output);
            return E_TYPE_OVERFLOW;
        }
        else if (error == E_CANNOT_OPEN_FILE)
        {
            printf("ERROR: невозможно открыть файл\n");
            if (flag_malloc)
                free(output);
            return E_CANNOT_OPEN_FILE;
        }
        else
        {
            break;
        }

    case 's':
        error = how_many_special_symbols_for_each_line(input_argument, output);
        if (error == E_TYPE_OVERFLOW)
        {
            printf("ERROR: переполнения счетчика латинских символов \n");
            if (flag_malloc)
                free(output);
            return E_TYPE_OVERFLOW;
        }
        else if (error == E_CANNOT_OPEN_FILE)
        {
            printf("ERROR: невозможно открыть файл\n");
            if (flag_malloc)
                free(output);
            return E_CANNOT_OPEN_FILE;
        }
        else
        {
            break;
        }

    case 'a':
        if (change_symbols_to_ascii_code(input_argument, output) != E_SUCCESS)
        {
            printf("ERROR: невозможно открыть файл\n");
            if (flag_malloc)
                free(output);
            return E_CANNOT_OPEN_FILE;
        }
        break;

    default:
        printf("ERROR: Некоррекный ввод аргументов, такого ФЛАГА %c не предусмотрено!\n", flag);
        if (flag_malloc)
                free(output);
        return E_INVALID_INPUT;
    }

    if (flag_malloc)
        free(output);

    return E_SUCCESS;
}
