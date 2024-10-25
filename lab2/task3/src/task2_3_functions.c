#include "../include/task2_3_functions.h"

ERRORS_EXIT_CODES len_string(const char *string, long long *length)
{
    // КОД с пары Ильи
    if (string == NULL)
    {
        return E_DEREFENCE_NULL_POINTER;
    }
    const char *start = string;
    while (*string++)
        ;
    *length = string - start - 1;
    return E_SUCCESS;
}

#if 1
ERRORS_EXIT_CODES search_pattern_in_files(char *pattern, long long number_of_files, ...)
{
    if (pattern == NULL)
    {
        return E_DEREFENCE_NULL_POINTER;
    }


    long long pattern_length;
    ERRORS_EXIT_CODES error = len_string(pattern, &pattern_length);
    if (error != E_SUCCESS || pattern_length == 0)
    {
        return (error != E_SUCCESS) ? error : E_INVALID_INPUT;
    }
    long long nums_slesh_n = 0;
    for (long long j = 0; j < pattern_length; j++)
    {
        if (pattern[j] == '\n')
            nums_slesh_n++;
    }

    va_list files_ptr;
    va_start(files_ptr, number_of_files);

    for (long long file_i = 0; file_i < number_of_files; file_i++)
    {
        char *file_path = va_arg(files_ptr, char *);
        if (file_path == NULL)
        {
            va_end(files_ptr);
            return E_DEREFENCE_NULL_POINTER;
        }

        FILE *file_pattern_to_find = fopen(file_path, "r");
        if (file_pattern_to_find == NULL)
        {
            va_end(files_ptr);
            return E_CANNOT_OPEN_FILE;
        }
        const char *file_name = my_find_file_name(file_path);
                puts("---------------------------------");

        printf("Поиск в файле: %s\n", file_name);
        //strcat((files_array[file_i]), file_name);
        long long index = 0;
        long long position = -1;
        long long occurrence_count = 0;

        long long line_number = 1;
        long long column_number = 1;
        long long current_line_start_column = 1;
        char ch;
        printf("<pattern> = <%s> \n\n", pattern);

        while ((ch = fgetc(file_pattern_to_find)) != EOF)
        {
            position++;

            if (ch == pattern[index])
            {
                if (index == 0)
                {
                    current_line_start_column = column_number;
                }
                index++;

                if (index == pattern_length)
                {
                    line_number -= nums_slesh_n;

                    printf("Вхождение подстроки найдено: строка %lld, столбец %lld\n", line_number, current_line_start_column);
                    occurrence_count++;

                    fseek(file_pattern_to_find, -pattern_length + 1, SEEK_CUR);
                    position = position - pattern_length + 1;
                    column_number = current_line_start_column;
                    index = 0;
                }
            }
            else
            {
                index = ((ch == pattern[0]) ? 1 : 0);

                if (index == 1)
                {
                    current_line_start_column = column_number;
                }
            }

            if (ch == '\n')
            {
                line_number++;
                column_number = 1;
            }
            else
            {
                column_number++;
            }
        }

        if (occurrence_count == 0)
        {
            printf("Подстрока не найдена в файле.\n");
        }
        else
        {
            printf("Всего найдено %lld вхождений подстроки.\n", occurrence_count);
        }

        fclose(file_pattern_to_find);
    }

    va_end(files_ptr);
    return E_SUCCESS;
}
#endif

// Функция для создания динамического двумерного массива строк
char **create_dynamic_array(int rows, int cols)
{
    char **array = (char **)malloc(rows * sizeof(char *)); // Выделяем память для строк
    if (array == NULL)
    {
        perror("Ошибка выделения памяти");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rows; i++)
    {
        array[i] = (char *)malloc(cols * sizeof(char)); // Выделяем память для каждой строки
        if (array[i] == NULL)
        {
            perror("Ошибка выделения памяти");
            exit(EXIT_FAILURE);
        }
    }

    return array;
}

// Функция для освобождения памяти двумерного массива строк
void free_dynamic_array(char **array, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(array[i]);
    }
    free(array);
}