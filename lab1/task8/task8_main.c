#include "task8_functions.h"

// gcc main.c -lm -std=c99 -Woverflow -g -Wall

/*
gcc task8_main.c task8_functions.c -o task8.out -lm -std=c99 -Woverflow -Wall

./task8.out /mnt/c/Users/Holiday/Desktop/Labs/labs/lab1/task8/test/input /mnt/c/Users/Holiday/Desktop/Labs/labs/lab1/task8/output

*/

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("ERROR: Неккорекный ввод, неправильное кол-во аргументов\n");
        return E_INVALID_ARG;
    }

    FILE *input_file = fopen(argv[1], "r");

    if (!input_file)
    {
        printf("ERROR: невозможно открыть файл для ввода\n");
        return E_CANNOT_OPEN_FILE;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (!output_file)
    {
        printf("ERROR: невозможно открыть файл для вывода\n");
        fclose(input_file);
        return E_CANNOT_OPEN_FILE;
    }

    // Проверка на file_name != file_name
    if (strcmp(find_file_name(argv[1]), find_file_name(argv[2])) == 0)
    {
        printf("ERROR: Нужно ввести два файла с разными именами\n");
        return E_INVALID_ARG;
    }

    unsigned long long int buf = INITIAL_BUFFER_SIZE;

    char *number_str = (char *)malloc(buf * sizeof(char));

    if (number_str == NULL)
    {
        printf("ERROR: Ошибка выделения памяти\n");
        fclose(input_file);
        fclose(output_file);
        return E_MEMORY_ALLOCATION;
    }

    int i = 0;
    int ch;
    long long number_decimal = 0;
    while (!feof(input_file))
    {

        ch = fgetc(input_file);

        if (isalnum(ch))
        {
            number_str[i++] = ch;

            if (i >= buf)
            {
                buf *= 2;
                char *temp = (char *)realloc(number_str, buf * sizeof(char));
                if (temp == NULL)
                {
                    printf("ERROR: Ошибка выделения памяти\n");
                    free(number_str);
                    fclose(input_file);
                    fclose(output_file);
                    return E_MEMORY_ALLOCATION;
                }
                number_str = temp;
            }
        }

        else if (i > 0)
        {
            number_str[i] = '\0';
            i = 0;

            int minBase = findMinBase(number_str);
            if (convert_to_decimal(number_str, minBase, &number_decimal) == E_SUCCESS)
            {
                fprintf(output_file, "%s in base %d = %lld\n", number_str, minBase, number_decimal);
            }
            else
            {
                printf("ERROR: Неккорекный ввод \n");
                free(number_str);
                fclose(input_file);
                fclose(output_file);
                return E_INVALID_INPUT;
            }
        }
    }

    free(number_str);
    fclose(input_file);
    fclose(output_file);
    printf("Программа корректно завершила работу\n");
    return E_SUCCESS;
}