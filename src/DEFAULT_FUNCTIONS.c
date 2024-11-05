#ifndef __DEFAULT_FUNCTIONS_C__
#define __DEFAULT_FUNCTIONS_C__
#include "../include/DEFAULT_FUNCTIONS.h"

/* Функция print_Errors выводит ошибку в консоль и возвращает код ошибки*/
ERRORS_EXIT_CODES print_Errors(const enum Errors error)
{
    switch (error)
    {
    case E_SUCCESS:
        printf("Успешное завершение! \n");
        return E_SUCCESS;
    case E_INVALID_INPUT:
        printf("ERROR: Неккорекный ввод \n");
        return E_INVALID_INPUT;
    case E_NOT_ENOUGH_PARAMS:
        printf("ERROR: Неправильное количество аргументов \n");
        return E_NOT_ENOUGH_PARAMS;
    case E_INVALID_ARG:
        printf("ERROR: Неправильный ввод аргументов \n");
        return E_INVALID_ARG;
    case E_TYPE_OVERFLOW:
        printf("ERROR: Переполнения типа данных \n");
        return E_TYPE_OVERFLOW;
    case E_MEMORY_ALLOCATION:
        printf("ERROR:  Ошибка выделении памяти \n");
        return E_MEMORY_ALLOCATION;
    case E_CANNOT_OPEN_FILE:
        printf("ERROR:  Ошибка ОТКРЫТИЯ ФАЙЛА \n");
        return E_CANNOT_OPEN_FILE;
    case E_INVALID_EPSILON:
        printf("ERROR:  Невалидная точность эпсилон \n");
        return E_INVALID_EPSILON;
    case E_DEREFENCE_NULL_POINTER:
        printf("ERROR:  Ошибка разыменования указателя на NULL \n");
        return E_INVALID_EPSILON;
    case E_INT_OVERFLOW:
        printf("ERROR:  Переполнение типа  INT \n");
        return E_INVALID_EPSILON;
    case E_LONG_OVERFLOW:
        printf("ERROR:  Переполнение типа LONG INT\n");
        return E_INVALID_EPSILON;
    case E_FLOAT_OVERFLOW:
        printf("ERROR:  Переполнение типа FLOAT \n");
        return E_INVALID_EPSILON;
    case E_DOUBLE_OVERFLOW:
        printf("ERROR:  Переполнение типа  DOUBLE \n");
        return E_INVALID_EPSILON;
    case E_LONG_DOUBLE_OVERFLOW:
        printf("ERROR:  Переполнение типа LONG DOUBLE \n");
        return E_INVALID_EPSILON;
    case E_INVALID_FLAG_ARG:
        printf("ERROR:  Неккорекный ввод аргументов (флагов), они должны начинаться с символов '-' или '/' \n");
        return E_INVALID_FLAG_ARG;
    case E_SAME_FILE_NAMES:
        printf("ERROR:  Одинаковые файлы!\n");
        return E_SAME_FILE_NAMES;
    case E_BUFFER_OVERFLOW:
        printf("ERROR:  Переполнение буффера \n");
        return E_BUFFER_OVERFLOW;
    case E_SAME_FILES:
        printf("ERROR: Одинаковые файлы \n");
        return E_SAME_FILES;
    default:
        printf("ERROR:  Неизвестный код Ошибки \n");
        return E_INVALID_INPUT;
    }
    return E_INVALID_INPUT;
}

/*Cхема Горнера, из BASE СС string в 10 CC LONG LONG INT */
ERRORS_EXIT_CODES convert_to_decimal(char *number_string, int base, long long int *number)
{
    // схема горнера
    if (number_string == NULL)
    {
        return E_DEREFENCE_NULL_POINTER;
    }
    *number = 0;
    int sign = 1;
    char *ptr = NULL;
    if (*number_string == '-')
    {
        sign = -1;
        ptr = number_string + 1;
    }
    else
    {
        ptr = number_string;
    }

    while (*ptr)
    {
        if (*number > ((LLONG_MAX / base) + (isdigit(*ptr) ? *ptr - '0' : *ptr - 'A' + 10)))
            return E_TYPE_OVERFLOW;
        *number = (*number) * base + (isdigit(*ptr) ? *ptr - '0' : *ptr - 'A' + 10);
        ptr++;
    }

    *number = *number * sign;
    return E_SUCCESS;
}

/*Обратная схема Горнера, из 10СС int в BASE CC int*/
char *convert_to_your_base_from_10CC(int number, int base)
{
    int sign = 1;
    if (number < 0)
    {
        sign = -1;
        number *= -1; // делаем модуль
    }
    long long int r;
    static char buf[BUFSIZ];
    char *ptr = buf + BUFSIZ - 1;
    *ptr-- = 0;
    while (number > 0)
    {
        *--ptr = ((r = number % base) > 9) ? r - 10 + 'A' : r + '0';
        number /= base;
    }
    if (sign == -1)
    {
        *--ptr = '-';
    }
    return ptr++;
}

/*Обратная схема Горнера, из 10СС longlongint в BASE CC int*/
char *convert_to_your_base_from_10CC_longlongint(long long int number, int base)
{
    long long int sign = 1;
    if (number < 0)
    {
        sign = -1;
        number *= -1; // делаем модуль
    }
    long long int r;
    static char buf[BUFSIZ];
    char *ptr = buf + BUFSIZ - 1;
    *ptr-- = 0;
    while (number > 0)
    {
        *--ptr = ((r = number % base) > 9) ? r - 10 + 'A' : r + '0';
        number /= base;
    }
    if (sign == -1)
    {
        *--ptr = '-';
    }
    return ptr++;
}

/*Проверка переполнения DOUBLE*/
ERRORS_EXIT_CODES is_double_overflow(double to_check)
{
    if ((fabs(to_check) > DBL_MAX) || to_check == HUGE_VAL || to_check == -HUGE_VAL || isnan(to_check) || isinf(to_check))
        return E_DOUBLE_OVERFLOW;
    return E_SUCCESS;
}

/* Перевод строки в double */
ERRORS_EXIT_CODES string_to_double(const char *str, double *num)
{
    if (str == NULL || num == NULL)
        return E_DEREFENCE_NULL_POINTER;

    char *endptr;
    double value = strtod(str, &endptr);

    if (*endptr != '\0')
        return E_INVALID_INPUT; // TODO вариант ошибки для стринга

    if (is_double_overflow(value))
        return E_DOUBLE_OVERFLOW;

    *num = value;
    return E_SUCCESS;
}

/* Перевод строки в long long int */
ERRORS_EXIT_CODES string_to_long_long_int(const char *str_number, long long int *int_result_number, int base)
{
    if (str_number == NULL || int_result_number == NULL)
        return E_DEREFENCE_NULL_POINTER;
    char *endptr;
    *int_result_number = strtol(str_number, &endptr, base);
    if (*int_result_number == LLONG_MAX || *int_result_number == LLONG_MIN)
        return E_LONG_OVERFLOW;
    else if (*endptr != '\0')
        return E_INVALID_INPUT;
    return E_SUCCESS;
}

/* Перевод строки в int */
ERRORS_EXIT_CODES string_to_int(const char *str_number, int *int_result_number, int base)
{
    if (str_number == NULL || int_result_number == NULL)
        return E_INVALID_INPUT;
    char *endptr;
    *int_result_number = strtol(str_number, &endptr, base);
    if (*int_result_number == INT_MAX || *int_result_number == INT_MIN || *int_result_number == -1)
        return E_TYPE_OVERFLOW;
    else if (*endptr != '\0')
        return E_INVALID_INPUT;
    return E_SUCCESS;
}

ERRORS_EXIT_CODES overflow_long_product_of_a_b(long long a, long long b)
{
    // Проверяем специальные случаи
    if (a == 0 || b == 0)
    {
        return E_SUCCESS; // Ноль умноженный на любое число не может вызвать переполнение
    }

    // Если a > 0 и b > 0, проверяем, не превысит ли произведение LLONG_MAX
    if (a > 0 && b > 0 && a > LLONG_MAX / b)
    {
        return E_LONG_OVERFLOW; // Переполнение
    }

    // Если a < 0 и b < 0, проверяем, не превысит ли произведение LLONG_MAX
    if (a < 0 && b < 0 && a < LLONG_MAX / b)
    {
        return E_LONG_OVERFLOW; // Переполнение
    }

    // Если одно из чисел отрицательное, проверяем на LLONG_MIN
    if ((a > 0 && b < 0 && b < LLONG_MIN / a) ||
        (a < 0 && b > 0 && a < LLONG_MIN / b))
    {
        return E_LONG_OVERFLOW; // Переполнение
    }

    return E_SUCCESS; // Переполнения нет
}

/*Проверка файлов на совпадение по Метаданным*/
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

    /*

    struct stat
     {
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
    if (path_file_1 == NULL || path_file_2 == NULL)
    {
        return E_DEREFENCE_NULL_POINTER;
    }

    struct stat file_1, file_2; // Остальные поля не нужны

    if (stat(path_file_1, &file_1) != 0)
    {
        printf("ERROR: НЕТ Файла по пути %s\n", path_file_1);
        return E_INVALID_INPUT;
    }
    if (stat(path_file_2, &file_2) != 0)
    {
        printf("ERROR: НЕТ Файла по пути %s\n", path_file_2);
        return E_INVALID_INPUT;
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

// TODO int, long, long double overflow
#endif

const char *my_find_file_name(const char *file_string)
{
    const char *file_name = strrchr(file_string, '/');
    // Функция strchr ищет последнее вхождения символа

    if (file_name != NULL)
        file_name++;
    else
        file_name = file_string; // значит не нашло '/'
    return file_name;
}

ERRORS_EXIT_CODES string_contains_only_alphas(const char *str)
{
    if (str == NULL)
    {
        return E_DEREFENCE_NULL_POINTER;
    }

    while (*str)
    {
        if (!(isalpha(*str)))
        {
            return E_FALSE;
        }
        str++;
    }
    return E_SUCCESS;
}

ERRORS_EXIT_CODES string_contains_only_digits(const char *str)
{
    if (str == NULL)
    {
        return E_DEREFENCE_NULL_POINTER;
    }
    while (*str)
    {
        if (!isdigit((unsigned char)*str))
        {
            return E_FALSE;
        }
        str++;
    }
    return E_SUCCESS;
}
