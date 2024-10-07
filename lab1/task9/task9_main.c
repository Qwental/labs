#include "task9_functions.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("ERROR: Неккорекный ввод, неправильное кол-во аргументов!!\n");
        return E_INVALID_ARG;
    }
    /*  TASK 9.1*/
    int a;
    int b;
    ERRORS_EXIT_CODES err;

    err = string_to_int(argv[1], &a, 10);
    if (err != E_SUCCESS)
    {
        print_Errors(err);
        return err;
    }

    err = string_to_int(argv[2], &b, 10);
    if (err != E_SUCCESS)
    {
        print_Errors(err);
        return err;
    }

    printf("%d %d \n", a, b);

    // валидация a, b
    if (a < 0 || b < 0)
    {
        printf("ERROR: числа a и b должны быть больше нуля\n");
        return E_INVALID_ARG;
    }
    if (a > b)
    {
        printf("ERROR: число a должно быть меньше чем число b\n");
        return E_INVALID_ARG;
    }

    if (a == b)
    {
        printf("ERROR: a должен быть не равен b\n");
        return E_INVALID_ARG;
    }
    int length_array_1 = INITIAL_SIZE;
    int array_1[length_array_1];
    srand(time(NULL));

    printf("9.1 Изначальный массив: ");
    for (int i = 0; i < length_array_1; i++)
    {
        // rand[a:b]
        array_1[i] = a + rand() % (b - a + 1);
        printf("%d ", array_1[i]);
    }
    printf("\n");

    print_and_swap_max_and_min(array_1, length_array_1);

    printf("9.1 Массив после swap(min,max): ");
    print_int_array(array_1, length_array_1);
    /*  END OF TASK 9.1*/

    /*  TASK 9.2*/
    /* псевдослучайного размера в диапазон [10..10000] */
    int length_array_2 = rand() % (10000 - 10 + 1) + 10;
    printf("%d\n", length_array_2);

    int *array_A = malloc(sizeof(int) * length_array_2 + 1);
    if (array_A == NULL)
    {
        print_Errors(E_MEMORY_ALLOCATION);
        return E_MEMORY_ALLOCATION;
    }

    int *array_B = malloc(sizeof(int) * length_array_2 + 1);
    if (array_B == NULL)
    {
        print_Errors(E_MEMORY_ALLOCATION);
        free(array_A);
        return E_MEMORY_ALLOCATION;
    }

    for (int i = 0; i < length_array_2; i++)
    {
        /* псевдослучайного размера в диапазон [-1000..1000] */

        array_A[i] = -1000 + rand() % (1000 + 1000 + 1);
        array_B[i] = -1000 + rand() % (1000 + 1000 + 1);
    }

    // sort ARRAY_b
    qsort(array_B, length_array_2, sizeof(int), compare_ints);

    int *array_C = malloc(sizeof(int) * length_array_2 + 1);
    if (array_C == NULL)
    {
        print_Errors(E_MEMORY_ALLOCATION);
        free(array_A);
        free(array_B);
        return E_MEMORY_ALLOCATION;
    }
    int current_a;

    for (int i = 0; i < length_array_2; i++)
    {
        current_a = array_A[i];
        array_C[i] = current_a + find_nearest_number(current_a, length_array_2, array_B);
    }

    int current_c;
    for (int i = 0; i < length_array_2; i++)
    {
        current_a = array_A[i];
        current_c = array_C[i];
        printf("A[%d] = %d\tC[%d] = %d\n", i, current_a, i, current_c);
    }

    free(array_A);
    free(array_B);
    free(array_C);

    printf("Программа корректно завершила работу\n");
    return E_SUCCESS;
}