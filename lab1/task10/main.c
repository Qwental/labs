#include "functions.h"
#define INITIAL_SIZE 36

// gcc main.c -lm -std=c99 -Woverflow -g -Wall



enum Errors delete_zeros_from_num(char *temp_number, unsigned long long num_length)
{
    if (!temp_number)
    {
        return E_INVALID_INPUT;
    }

    if ((num_length == 1) && temp_number[0] == '0')
    {
        return E_SUCCESS;
    }

    char t[num_length];
    int j = 0;
    unsigned long long i = 0;

    strcpy(t, temp_number);
    if (t[0] == '-')
    {
        j++;
        i++;
    }
    int end_zeros_flag = 0;
    for (; i < num_length; i++)
    {
        if ((t[i] != '0') && (end_zeros_flag == 0))
        {
            end_zeros_flag = 1;
        }

        if (end_zeros_flag)
        {
            temp_number[j] = t[i];
            j++;
        }
    }
    temp_number[j++] = '\0';
    return E_SUCCESS;
}

char *read_number_string()
{
    unsigned long int size = INITIAL_SIZE;
    unsigned long int length = 0;
    char *string_number = (char *)malloc(size * sizeof(char));

    if (!string_number)
        return NULL;

    char ch;

    printf("Введите число или Stop: ");

    while ((ch = getchar()) != '\n')
    {

        if (length >= size) // увеличиваю размер строки
        {
            size *= 2;
            if (!string_number)
            {
                return NULL;
            }
            string_number = (char *)realloc(string_number, size * sizeof(char));
            if (!string_number)
            {
                return NULL; // ошибка памяти
            }
        }

        string_number[length++] = ch;
        if (length >= (ULLONG_MAX - 1))
        {
            return NULL;
        }
    }

    string_number[length] = '\0'; // добавляем конец строки
    return string_number;
}

enum Errors convert_to_decimal(char *number_string, int base, long long int *number)
{
    // схема горнера
    if (!number_string)
    {
        return E_INVALID_INPUT;
    }
    int sign = 1;
    char *ptr = NULL;
    // TODO CHEAK BASE
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

char *convert_to_your_base_from_10CC(long long int number, int base)
{
    // обратная схема горнера с лекции
    int sign = 1;

    if (number < 0)
    {
        sign = -1;
        number *= -1; // делаем модуль
    }
    long long int r;

    static char buf[BUFSIZ];
    char* ptr = buf + BUFSIZ - 1;
    *ptr-- = 0;
    while(number > 0)
    {
        *--ptr = ((r = number % base) > 9)? r - 10 + 'A' : r + '0';
        number /= base;
    }

    if (sign == -1)
    {
        *--ptr = '-';
    }
    return ptr++;
}

enum Errors check_string_number_in_your_base(char *number_string, int base)
{
    int i = 0;
    if (!number_string)
        return E_INVALID_INPUT;
    if(number_string[i] == '-') 
        i = 1;

    if (base > 9)
    {
        while(number_string[i])
        {
            if (number_string[i] - 'A' + 10 >= base) 
                return E_INVALID_INPUT;
            i++;
        }
    }
    else {
        while(number_string[i])
        {
            if (number_string[i] - '0' >= base) 
                return E_INVALID_INPUT;
            i++;
        }
    }
    return E_SUCCESS;
}


int main()
{

    printf("Введите основание cистемы счисления(CC) в пределах от 2 до 36 включительно: ");
    int cheak_scanf = 1;
    int base_of_num_system = 0;

    cheak_scanf = scanf("%d", &base_of_num_system);
    if ((cheak_scanf != 1) || ((base_of_num_system > 36) || (base_of_num_system < 2)))
    {
        printf("ERROR: Некорректный ввод основания системы счисления\n");
        return E_INVALID_INPUT;
    }

    // char *all_base_digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    getchar(); // EAT THE SPACE!

    long long int current_num_string_length = 0;
    long long int current_num_length = 0;

    long long int max_num_length = 0;
    long long int max_number = 0;

    long long int current_number = 0;
    enum Errors err;

    // convert_to_decimal("111",2,&result);
    // printf("%lld\n", result);

    int correct_input_flag = 0;

#if 1
    while (1)
    {

        char *input_number = read_number_string();

        if (!input_number)
        {
            printf("ERROR: Ошибка выделения памяти\n");
            free(input_number);
            return E_MEMORY_ALLOCATION;
        }

        if ((strcmp(input_number, "Stop") == 0) || (strcmp(input_number, "stop") == 0))
        {
            free(input_number);
            break;
        }

        if (check_string_number_in_your_base(input_number,base_of_num_system) != E_SUCCESS)
        {
            printf("ERROR: Неккоректный ввод числа в СС=%d\n", base_of_num_system);
            return E_INVALID_INPUT;
        }
        correct_input_flag = 1;

        current_num_string_length = strlen(input_number);

        char temp_number[current_num_string_length]; // делаю строку размером введенной

        strcpy(temp_number, input_number);
        free(input_number);

        delete_zeros_from_num(temp_number, current_num_string_length);

        current_num_length = strlen(temp_number);
        puts(temp_number);

        if ((current_num_length >= max_num_length))
        {

            err = convert_to_decimal(temp_number, base_of_num_system, &current_number);
            if (err == E_TYPE_OVERFLOW)
            {
                printf("ERROR: Переполнение типа long long int\n");
                return E_TYPE_OVERFLOW;
            }
            else if (err == E_INVALID_INPUT)
            {
                printf("ERROR: Неккоректный ввод\n");
                return E_INVALID_INPUT;
            }

            max_num_length = current_num_length;
            if (abs(current_number) > abs(max_number))
            {
                max_number = current_number;
            }
        }
        current_number = 0;
    }
    if(!correct_input_flag){
        printf("ERROR: Не было введено ниодного числа\n");
        return E_INVALID_INPUT;
    }
    printf("MAX in base %d: %s\n",base_of_num_system, convert_to_your_base_from_10CC(max_number, base_of_num_system));
    printf("MAX in base 10: %lld\n",max_number);
    printf("MAX in base  9: %s\n", convert_to_your_base_from_10CC(max_number, 9));
    printf("MAX in base 18: %s\n", convert_to_your_base_from_10CC(max_number, 18));
    printf("MAX in base 27: %s\n", convert_to_your_base_from_10CC(max_number, 27));
    printf("MAX in base 36: %s\n", convert_to_your_base_from_10CC(max_number, 36));

#endif

    return E_SUCCESS;
}

// TODO функции куда нада header
// TODO А ЕСЛИ БУДЕТ ТОЛЬКО ВВЕДЕНО STOP?
