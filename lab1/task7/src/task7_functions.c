#include "../include/task7_functions.h"
#define SPACE " "

const char *find_file_name(const char *file_string)
{
    const char *file_name = strrchr(file_string, '/');
    // Функция strchr ищет последнее вхождения символа

    if (file_name != NULL)
        file_name++;
    else
        file_name = file_string;
    return file_name;
}

ERRORS_EXIT_CODES func_flag_r(const char *path_file1,
                              const char *path_file2,
                              const char *path_file3)
{
    /* Валидации */
    if ((strcmp(find_file_name(path_file1), find_file_name(path_file2)) == 0) ||
        (strcmp(find_file_name(path_file2), find_file_name(path_file3)) == 0) ||
        (strcmp(find_file_name(path_file1), find_file_name(path_file3)) == 0))
    {
        return print_Errors(E_SAME_FILE_NAMES);
    }

    FILE *file_1 = fopen(path_file1, "r");
    if (!file_1)
    {
        return E_CANNOT_OPEN_FILE;
    }

    FILE *file_2 = fopen(path_file2, "r");
    if (!file_2)
    {
        fclose(file_1);
        return E_CANNOT_OPEN_FILE;
    }

    FILE *file_3 = fopen(path_file3, "w");
    if (!file_3)
    {
        fclose(file_1);
        fclose(file_2);
        return E_CANNOT_OPEN_FILE;
    }
    char leksem[BUFSIZ];
    char ch_file_1[2] = "\0";
    char ch_file_2[2] = "\0";

    size_t count = 0;
    int prev_is_leksem = 0;

    size_t ch_count = 0;

    while (!feof(file_1) || !feof(file_2))
    {
        
        if (ch_file_1[0] == EOF)
        {
            // остаток второго фала пишем
            // printf("ch_file_1 == EOF\n");
            while (1)
            {
                ch_file_2[0] = fgetc(file_2);
                ch_count++;
                if (ch_count >= BUFSIZ)
                {
                    fclose(file_1);
                    fclose(file_2);
                    fclose(file_3);
                    return E_BUFFER_OVERFLOW;
                }
                if (ch_file_2[0] == EOF || (isspace(ch_file_2[0])))
                {
                    if (prev_is_leksem)
                    {
                        prev_is_leksem = 0;
                        fprintf(file_3, "%s ", leksem);
                    }
                    break;
                }
                prev_is_leksem = 1;
                strcat(leksem, ch_file_2);
            };

            memset(leksem, 0, strlen(leksem) + 1);
            leksem[0] = '\0';
            ch_count = 0;
            continue;
        }
        if (ch_file_2[0] == EOF)
        {
            // остаток первого фала пишем
            // printf("ch_file_1 == EOF\n");
            // int i = 0;
            while (1)
            {
                ch_file_1[0] = fgetc(file_1);
                // printf("i=%d %s\n", i, leksem);
                ch_count++;
                if (ch_count >= BUFSIZ)
                {
                    fclose(file_1);
                    fclose(file_2);
                    fclose(file_3);
                    return E_BUFFER_OVERFLOW;
                }
                if (ch_file_1[0] == EOF || (isspace(ch_file_1[0])))
                {
                    if (prev_is_leksem)
                    {
                        prev_is_leksem = 0;
                        fprintf(file_3, "%s ", leksem);
                    }
                    break;
                }
                prev_is_leksem = 1;
                strcat(leksem, ch_file_1);
            }

            memset(leksem, 0, strlen(leksem) + 1);
            leksem[0] = '\0';
            ch_count = 0;
            continue;
        }

        if (!(count & 1))
        {
            // четное - вставляем лексему из второго файла
            while (1)
            {

                ch_file_2[0] = fgetc(file_2);
                ch_count++;
                if (ch_count >= BUFSIZ)
                {
                    fclose(file_1);
                    fclose(file_2);
                    fclose(file_3);
                    return E_BUFFER_OVERFLOW;
                }
                if (ch_file_2[0] == EOF || (isspace(ch_file_2[0])))
                {
                    if (prev_is_leksem)
                    {
                        prev_is_leksem = 0;
                        fprintf(file_3, "%s ", leksem);
                    }
                    break;
                }
                prev_is_leksem = 1;
                strcat(leksem, ch_file_2);
            }
        }
        else
        {
            // нечетное - вставляем лексему из первого файла
            while (1)
            {
                ch_file_1[0] = fgetc(file_1);
                ch_count++;
                if (ch_count >= BUFSIZ)
                {
                    fclose(file_1);
                    fclose(file_2);
                    fclose(file_3);
                    return E_BUFFER_OVERFLOW;
                }
                if (ch_file_1[0] == EOF || (isspace(ch_file_1[0])))
                {
                    if (prev_is_leksem)
                    {
                        prev_is_leksem = 0;
                        fprintf(file_3, "%s ", leksem);
                    }
                    break;
                }
                prev_is_leksem = 1;
                strcat(leksem, ch_file_1);
            }

        }
        count++;
        memset(leksem, 0, strlen(leksem) + 1);
        leksem[0] = '\0';
        ch_count = 0;
    }

    fclose(file_1);
    fclose(file_2);
    fclose(file_3);
    return E_SUCCESS;
}

ERRORS_EXIT_CODES func_flag_a(const char *path_file1,
                              const char *path_file2)
{
    /* Валидации */
    if ((strcmp(find_file_name(path_file1), find_file_name(path_file2)) == 0))
    {
        return print_Errors(E_SAME_FILE_NAMES);
    }

    FILE *file_1 = fopen(path_file1, "r");
    if (!file_1)
    {
        return E_CANNOT_OPEN_FILE;
    }

    FILE *file_out = fopen(path_file2, "w");
    if (!file_out)
    {
        fclose(file_1);
        return E_CANNOT_OPEN_FILE;
    }

    int leksem_count = 0;
    int prev_is_leksem = 0;
    char leksem[BUFSIZ];
    char symblol[2] = "\0";
    char buf[BUFSIZ];
    size_t count = 0;

    while (!feof(file_1))
    {
        symblol[0] = fgetc(file_1);
        count++;
        if (count > BUFSIZ)
        {
            fclose(file_1);
            fclose(file_out);
            return E_BUFFER_OVERFLOW;
        }

        if (isspace(symblol[0]) || (symblol[0] == EOF))
        {

            if (!prev_is_leksem)
                continue;

            leksem_count++;
            prev_is_leksem = 0;
            // printf("String: %s %d\n", leksem, leksem_count);

            if (leksem_count % 10 == 0)
            {
                string_to_lower_or_upper_case(leksem);
                string_to_ascii_in_base(leksem, 4, buf);
                fprintf(file_out, "%s ", buf);
                // printf("Buf : %s \n", buf);
            }
            else if ((leksem_count % 5 == 0))
            {
                string_to_lower_or_upper_case(leksem);
                string_to_ascii_in_base(leksem, 4, buf);
                fprintf(file_out, "%s ", buf);
                // printf("Buf : %s \n", buf);
            }
            else if (leksem_count % 2 == 0)
            {
                string_to_lower_or_upper_case(leksem);
                fprintf(file_out, "%s ", leksem);
            }
            else
            {
                fprintf(file_out, "%s ", leksem);
            }
            memset(leksem, 0, strlen(leksem) + 1);
            count = 0;
            leksem[0] = '\0';
            memset(buf, 0, strlen(buf) + 1);
        }
        else
        {
            strcat(leksem, symblol);
            prev_is_leksem = 1;
        }
    }

    fclose(file_1);
    fclose(file_out);
    return E_SUCCESS;
}

ERRORS_EXIT_CODES string_to_lower_or_upper_case(char *leksem)
{
    if (leksem == NULL)
    {
        return E_DEREFENCE_NULL_POINTER;
    }
    size_t i;
    size_t len_s = strlen(leksem);
    for (i = 0; i < len_s; i++)
    {
        if (isalpha(leksem[i]))
            leksem[i] = (isupper(leksem[i])) ? tolower(leksem[i]) : toupper(leksem[i]);
    }
    return E_SUCCESS;
}

ERRORS_EXIT_CODES string_to_ascii_in_base(char *leksem, size_t base, char *buf)
{
    if (leksem == NULL)
    {
        return E_DEREFENCE_NULL_POINTER;
    }
    size_t i;
    size_t len_s = strlen(leksem);
    for (i = 0; i < len_s; i++)
    {
        strcat(buf, convert_to_your_base_from_10CC(((int)(leksem[i])), base));
    }
    return E_SUCCESS;
}