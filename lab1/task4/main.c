#include "functions.h"


const char* find_file_name(const char *file_string) 
{
    const char* file_name = strrchr(file_string, '/');
    if (file_name != NULL) 
        file_name++;
    else 
        file_name = file_string;
    return file_name;
}

enum Errors delete_arabic_funny_numbers(const char *file_input, const char *file_output)
{
    FILE *file_1 = fopen(file_input, "r");
    FILE *file_2 = fopen(file_output, "w");


    if (!file_1 || !file_2)
    {
        fclose(file_1);
        fclose(file_2);
        return E_CANNOT_OPEN_FILE;
    }

    char ch;
    while ((ch = fgetc(file_1)) != EOF)
        if (!(ch >= '0' && ch <= '9'))
            fputc(ch, file_2);
    fclose(file_1);
    fclose(file_2);
    return E_SUCCESS;
}

enum Errors how_many_latin_symbols_for_each_line(const char *file_input, const char *file_output)
{
    FILE *file_1 = fopen(file_input, "r");
    FILE *file_2 = fopen(file_output, "w");

    if (!file_1 || !file_2)
    {
        fclose(file_1);
        fclose(file_2);
        return E_CANNOT_OPEN_FILE;
    }

    long long int counter = 0;
    char ch;
    while ((ch = getc(file_1)) != EOF)
    {
        if (isalpha(ch))
        {
            if (counter >= LLONG_MAX - 1)
            {
                fclose(file_1);
                fclose(file_2);
                return E_TYPE_OVERFLOW;
            }
            counter++;
        }

        if (ch == '\n')
        {
            fprintf(file_2, "%lld\n", counter);
            counter = 0;
        }
    }

    fclose(file_1);
    fclose(file_2);
    return E_SUCCESS;
}

enum Errors how_many_special_symbols_for_each_line(const char *file_input, const char *file_output)
{
    FILE *file_1 = fopen(file_input, "r");
    FILE *file_2 = fopen(file_output, "w");

    if (!file_1 || !file_2)
    {
        fclose(file_1);
        fclose(file_2);
        return E_CANNOT_OPEN_FILE;
    }

    long long int counter = 0;
    char ch;
    while ((ch = getc(file_1)) != EOF)
    {
        if (!(isalpha(ch)) && !(isdigit(ch)))
        {
            if (counter >= LLONG_MAX - 1)
            {
                fclose(file_1);
                fclose(file_2);
                return E_TYPE_OVERFLOW;
            }
            counter++;
        }
        if (ch == '\n')
        {
            fprintf(file_2, "%lld\n", counter);
            counter = 0;
        }
    }

    fclose(file_1);
    fclose(file_2);
    return E_SUCCESS;
}

enum Errors change_symbols_to_ascii_code(const char *file_input, const char *file_output)
{
    {
        FILE *file_1 = fopen(file_input, "r");
        FILE *file_2 = fopen(file_output, "w");

        if (!file_1 || !file_2)
        {
            fclose(file_1);
            fclose(file_2);
            return E_CANNOT_OPEN_FILE;
        }

        int ch;
        while ((ch = fgetc(file_1)) != EOF)
        {
            if ((ch >= '0' && ch <= '9') || ch == '\n')
                fprintf(file_2, "%d", ch);
            else
                fprintf(file_2, "%X", ch); // %X - 16CC
        }
        fclose(file_1);
        fclose(file_2);
        return E_SUCCESS;
    }
}

int main(int argc, char *argv[])
{
    if (argv[1][0] != '-' && argv[1][0] != '/')
    {
        printf("ERROR: Неккорекный ввод аргументов, они должны начинаться с символов '-' или '/' \n");
        return E_INVALID_ARG;
    }

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

        if (strcmp(argv[2], argv[3]) == 0)
        {
            printf("ERROR: Нужно ввести два РАЗНЫХ файла\n");
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

       sprintf(output, "out_%s",input_file); // ПРИПИСЫВАЕМ К ИМЕНИ(АДРЕСУ) out_

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
            free(output);
            return E_TYPE_OVERFLOW;
        }
        else if (error == E_CANNOT_OPEN_FILE)
        {
            printf("ERROR: невозможно открыть файл\n");
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
            free(output);
            return E_TYPE_OVERFLOW;
        }
        else if (error == E_CANNOT_OPEN_FILE)
        {
            printf("ERROR: невозможно открыть файл\n");
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
            free(output);
            return E_CANNOT_OPEN_FILE;
        }
        break;

    default:
        printf("ERROR: Некоррекный ввод аргументов, такого ФЛАГА %c не предусмотрено!\n", flag);
        break;
    }
            free(output);

    return E_SUCCESS;
}