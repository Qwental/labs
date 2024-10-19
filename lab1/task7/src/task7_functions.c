#include "../include/task7_functions.h"
#define SPACE " "

#include <sys/stat.h> // для работы с функцией stat() и структурой stat, которая хранит информацию о файле.

const char *find_file_name(const char *file_string)
{
    const char *file_name = strrchr(file_string, '/');
    // Функция strchr ищет последнее вхождения символа

    if (file_name != NULL)
        file_name++;
    else
        file_name = file_string; // значит не нашло '/'
    return file_name;
}

ERRORS_EXIT_CODES cheak_files(const char *path_file_1, const char *path_file_2)

{
    /*

        Передаем пути

        используются системные вызовы для получения информации о файле

        st_ino — уникальный идентификатор файла в пределах одного устройства (inode).
        st_dev — идентификатор устройства, на котором находится файл.

        Структура stat, определенная в заголовочном файле <sys/stat.h>,
         хранит метаданные о файлах и директориях в Unix-подобных системах (таких как Linux и macOS). 

        stat -  Get file attributes for FILE and put them in BUF.

        stat(path, &stat) — системный вызов, который заполняет структуру stat информацией о файле, который находится по указанному пути.
        Если stat() возвращает -1, это означает, что произошла ошибка при получении информации о файле (например, файл не существует)


    Почему это работает:
    В современных файловых системах каждый файл имеет уникальный идентификатор inode (индексный узел)
    на конкретном устройстве. В комбинации с идентификатором устройства (например, идентификатором диска или тома)

    Файловый дескриптор — это целое число, которое операционная система присваивает каждому открытому файлу или другому ресурсу
    Идентификатор файла: Файловый дескриптор — это уникальное число для каждого открытого файла в пределах одного процесса.
    С его помощью операционная система знает, к какому файлу нужно обращаться при выполнении операций.

    inode (индексный узел) — это структура данных, используемая в файловых системах Unix и Linux для хранения информации о файлах и директориях.
    Каждый файл и директория в файловой системе имеют свой уникальный inode, который содержит метаданные о файле.

     st_dev -  идентификатор устройства (device ID)


    */
   

    struct stat file_1, file_2; // Остальные поля не нужны

    if (stat(path_file_1, &file_1) != 0)
    {
        printf("ERROR: НЕТ Файла по пути %s\n", path_file_1);
        return E_INVALID_INPUT;
    }
    if (stat(path_file_2, &file_2) != 0)
    {
        printf("ERROR: НЕТ Файла по пути %s\n", path_file_2);
    }
    // .st_ino проверка, что номера inode файлов совпадают. Это уникальный идентификатор файла в пределах одного устройства
    // .st_dev проверка, что файлы находятся на одном и том же устройстве (например, на одном диске).
    if (file_1.st_ino == file_2.st_ino && file_1.st_dev == file_2.st_dev)
    {
        // Файлы совпадают
        printf("ERROR: Файлы совпадают! Их Пути:\n%s\n%s\n", path_file_1, path_file_2);
        return E_SAME_FILE_NAMES;
    }
    // Файлы НЕ совпадают
    return E_SUCCESS;
}

/*

struct stat {
    dev_t     st_dev;     // Идентификатор устройства, на котором находится файл
    ino_t     st_ino;     // Номер inode файла
    mode_t    st_mode;    // Режим доступа (права и тип файла)
    nlink_t   st_nlink;   // Количество жестких ссылок на файл
    uid_t     st_uid;     // Идентификатор владельца файла
    gid_t     st_gid;     // Идентификатор группы, к которой принадлежит файл
    dev_t     st_rdev;    // Идентификатор специального устройства (если это специальный файл)
    off_t     st_size;    // Размер файла в байтах
    time_t    st_atime;   // Время последнего доступа к файлу
    time_t    st_mtime;   // Время последнего изменения содержимого файла
    time_t    st_ctime;   // Время последнего изменения метаданных файла
    // ... (другие поля могут зависеть от платформы)
};


*/
ERRORS_EXIT_CODES func_flag_r(const char *path_file1,
                              const char *path_file2,
                              const char *path_file3,
                              char *leksem,
                              size_t *bufsize)
{
    /* Валидации */

    if ((cheak_files(path_file1, path_file2) != E_SUCCESS) ||
        (cheak_files(path_file1, path_file3) != E_SUCCESS) ||
        (cheak_files(path_file2, path_file3) != E_SUCCESS))
    {
        free(leksem);
        return (E_SAME_FILES);
    }

    FILE *file_1 = fopen(path_file1, "r");
    if (file_1 == NULL)
    {
        free(leksem);
        return E_CANNOT_OPEN_FILE;
    }

    FILE *file_2 = fopen(path_file2, "r");
    if (file_2 == NULL)
    {
        free(leksem);
        fclose(file_1);
        return E_CANNOT_OPEN_FILE;
    }

    FILE *file_3 = fopen(path_file3, "w");
    if (file_3 == NULL)
    {
        free(leksem);
        fclose(file_1);
        fclose(file_2);
        return E_CANNOT_OPEN_FILE;
    }

    // TODO повторить дискру

    char ch_file_1[2] = "\0";
    char ch_file_2[2] = "\0";

    int count = 1;
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

                if (ch_count >= *bufsize)
                {
                    *bufsize *= 2;
                    char *temp_buf = (char *)realloc(leksem, sizeof(char) * (*bufsize));
                    if (temp_buf == NULL)
                    {
                        free(leksem);
                        fclose(file_1);
                        fclose(file_2);
                        fclose(file_3);
                        return E_MEMORY_ALLOCATION;
                    }
                    leksem = temp_buf;
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

                if (ch_count >= *bufsize)
                {
                    *bufsize *= 2;
                    char *temp_buf = (char *)realloc(leksem, sizeof(char) * (*bufsize));
                    if (temp_buf == NULL)
                    {
                        free(leksem);
                        fclose(file_1);
                        fclose(file_2);
                        fclose(file_3);
                        return E_MEMORY_ALLOCATION;
                    }
                    leksem = temp_buf;
                }

                if (ch_file_1[0] == EOF || (isspace(ch_file_1[0])))
                {
                    if (prev_is_leksem)
                    {
                        prev_is_leksem = 0;
                        fprintf(file_3, "%s ", leksem);
                        count++;
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

                if (ch_count >= *bufsize)
                {
                    *bufsize *= 2;
                    char *temp_buf = (char *)realloc(leksem, sizeof(char) * (*bufsize));
                    if (temp_buf == NULL)
                    {
                        free(leksem);
                        fclose(file_1);
                        fclose(file_2);
                        fclose(file_3);
                        return E_MEMORY_ALLOCATION;
                    }
                    leksem = temp_buf;
                }

                if (ch_file_2[0] == EOF || (isspace(ch_file_2[0])))
                {
                    if (prev_is_leksem)
                    {
                        prev_is_leksem = 0;
                        fprintf(file_3, "%s ", leksem);
                        count++;
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

                if (ch_count >= *bufsize)
                {
                    *bufsize *= 2;
                    char *temp_buf = (char *)realloc(leksem, sizeof(char) * (*bufsize));
                    if (temp_buf == NULL)
                    {
                        free(leksem);
                        fclose(file_1);
                        fclose(file_2);
                        fclose(file_3);
                        return E_MEMORY_ALLOCATION;
                    }
                    leksem = temp_buf;
                }

                if (ch_file_1[0] == EOF || (isspace(ch_file_1[0])))
                {
                    if (prev_is_leksem)
                    {
                        prev_is_leksem = 0;
                        fprintf(file_3, "%s ", leksem);
                        count++;
                    }
                    break;
                }
                prev_is_leksem = 1;
                strcat(leksem, ch_file_1);
            }
        }

        // printf("%d %s\n",count,leksem);
        memset(leksem, 0, strlen(leksem) + 1);
        leksem[0] = '\0';
        ch_count = 0;
    }

    free(leksem);
    fclose(file_1);
    fclose(file_2);
    fclose(file_3);
    return E_SUCCESS;
}

ERRORS_EXIT_CODES func_flag_a(const char *path_file1,
                              const char *path_file2,
                              char *buf,
                              size_t *bufsize)
{
    /* Валидации */

    if ((cheak_files(path_file1, path_file2) != E_SUCCESS))
    {
        free(buf);
        return (E_SAME_FILES);
    }

    FILE *file_1 = fopen(path_file1, "r");
    if (file_1 == NULL)
    {
        free(buf);

        return E_CANNOT_OPEN_FILE;
    }

    FILE *file_out = fopen(path_file2, "w");
    if (file_out == NULL)
    {
        free(buf);

        fclose(file_1);
        return E_CANNOT_OPEN_FILE;
    }

    int leksem_count = 0;
    int prev_is_leksem = 0;
    // char leksem[BUFSIZ];

    char *leksem = (char *)malloc(sizeof(char) * (*bufsize)); // Буффер куда будем пихать лексемы
    if (leksem == NULL)
    {
        free(buf);
        fclose(file_1);
        fclose(file_out);
        return print_Errors(E_MEMORY_ALLOCATION);
    }
    leksem[0] = '\0';

    char symblol[2] = "\0";
    // char buf[BUFSIZ];
    size_t count = 0;

    while (!feof(file_1))
    {
        symblol[0] = fgetc(file_1);
        count++;

        if (count >= *bufsize)
        {
            *bufsize *= 2;
            char *temp_leksem = (char *)realloc(leksem, sizeof(char) * (*bufsize));
            if (temp_leksem == NULL)
            {
                free(leksem);
                fclose(file_1);
                fclose(file_out);
                return E_MEMORY_ALLOCATION;
            }
            leksem = temp_leksem;

            char *temp_buf = (char *)realloc(buf, sizeof(char) * (*bufsize));
            if (temp_buf == NULL)
            {
                free(buf);
                free(leksem);
                fclose(file_1);
                fclose(file_out);
                return E_MEMORY_ALLOCATION;
            }
            buf = temp_buf;
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
                if (string_to_lower_or_upper_case(leksem) != E_SUCCESS)
                {
                    free(buf);
                    free(leksem);
                    fclose(file_1);
                    fclose(file_out);
                    return E_INT_OVERFLOW;
                }
                if (string_to_ascii_in_base(leksem, 4, buf))
                {
                    free(buf);
                    free(leksem);
                    fclose(file_1);
                    fclose(file_out);
                    return E_BUFFER_OVERFLOW;
                }
                fprintf(file_out, "%s ", buf);
                // printf("Buf : %s \n", buf);
            }
            else if ((leksem_count % 5 == 0))
            {
                if (string_to_lower_or_upper_case(leksem) != E_SUCCESS)
                {
                    free(buf);
                    free(leksem);
                    fclose(file_1);
                    fclose(file_out);
                    return E_INT_OVERFLOW;
                }

                if (string_to_ascii_in_base(leksem, 4, buf))
                {
                    free(buf);
                    free(leksem);
                    fclose(file_1);
                    fclose(file_out);
                    return E_BUFFER_OVERFLOW;
                }
                fprintf(file_out, "%s ", buf);
                // printf("Buf : %s \n", buf);
            }

            else if (leksem_count % 2 == 0)
            {
                if (string_to_lower_or_upper_case(leksem) != E_SUCCESS)
                {
                    free(buf);
                    free(leksem);
                    fclose(file_1);
                    fclose(file_out);
                    return E_INT_OVERFLOW;
                }
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

    free(buf);
    free(leksem);

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
        if (i > LONG_MAX - 1)
        {
            return E_INT_OVERFLOW;
        }
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

        // snprintf((buf,sizeof(buf),"%s%s", convert_to_your_base_from_10CC(((int)(leksem[i])), base)));

        if (i >= ((BUFSIZ - (i / base)) / (base)))
        {
            // printf("strcat buf(i) = %zu\n", i);
            return E_BUFFER_OVERFLOW;
        }
        // snprintf((buf,,"%s%s", convert_to_your_base_from_10CC(((int)(leksem[i])), base)));
        strcat(buf, convert_to_your_base_from_10CC(((int)(leksem[i])), base));
    }
    return E_SUCCESS;
}
