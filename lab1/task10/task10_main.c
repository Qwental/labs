#include "task10_functions.h"

// gcc main.c -lm -std=c99 -Woverflow -g -Wall

/*
gcc task10_main.c task10_functions.c -lm -std=c99 -Woverflow -Wall -o task10.out

./task10.out

*/

int main()
{

    printf("Введите основание cистемы счисления(CC) в пределах от 2 до 36 включительно: ");
    int cheak_scanf = 1;
    int base_of_num_system = 0;

    cheak_scanf = scanf("%d", &base_of_num_system);
    getchar(); // EAT THE SPACE!
    if ((cheak_scanf != 1) || ((base_of_num_system > 36) || (base_of_num_system < 2)))
    {
        printf("ERROR: Некорректный ввод основания системы счисления\n");
        return E_INVALID_INPUT;
    }

    long long int current_num_string_length = 0;
    long long int current_num_length = 0;

    long long int max_num_length = 0;
    long long int max_number = 0;

    long long int current_number = 0;
    enum Errors err;

    int correct_input_flag = 0;

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
    if(base_of_num_system != 10)
        printf("MAX in base 10: %lld\n",max_number);
    printf("MAX in base  9: %s\n", convert_to_your_base_from_10CC(max_number, 9));
    printf("MAX in base 18: %s\n", convert_to_your_base_from_10CC(max_number, 18));
    printf("MAX in base 27: %s\n", convert_to_your_base_from_10CC(max_number, 27));
    printf("MAX in base 36: %s\n", convert_to_your_base_from_10CC(max_number, 36));


    return E_SUCCESS;
}