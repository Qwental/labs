#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 10

char *read_string()
{
    int size = INITIAL_SIZE;
    int length = 0;
    char *string_number = (char *)malloc(size * sizeof(char));
    if (!string_number)
    {
        fprintf(stderr, "Ошибка выделения памяти\n");
        return NULL;
    }

    char ch;
    printf("Введите число в СС : ");

    while ((ch = getchar()) != '\n')
    {
        // Увеличиваем размер, если необходимо !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        if (length >= size)
        {
            size *= 2; // Увеличиваем размер вдвое
            string_number = (char *)realloc(string_number, size * sizeof(char));
            if (!string_number)
            {
                fprintf(stderr, "Ошибка выделения памяти\n");
                return NULL;
            }
        }
        string_number[length++] = ch; // Добавляем символ к строке
    }

    // Завершаем строку символом конца строки
    string_number[length] = '\0';
    return string_number;
}

int main()
{
    char *input;
    unsigned long int num_length = 0;
    char * number;
    

    for (int i = 0; i < 3; ++i)
    {
        char *input = read_string();
        if (input)
        {

            num_length = strlen(input);
            char  number[num_length]; // делаю строку размером введенной

            strcpy(number,input);

            printf("Введенная строка: %s\n", input);
                        printf("Введенная строка: %s\n", number);
                        puts("");
            // освобождаю выделенную память под вводимую строку
            free(input);

        }

    }

    return 0;
}
