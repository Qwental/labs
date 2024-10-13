#include "../include/task9_functions.h"


void print_and_swap_max_and_min(int *array, int length)
{
    int max_value_index = 0;
    int min_value_index = 0;
    for (int i = 1; i < length; i++)
    {
        if (array[i] > array[max_value_index])
            max_value_index = i;
        if (array[i] < array[min_value_index])
            min_value_index = i;
    }
    printf("MAX value = %d, MIN value = %d\n", array[max_value_index], array[min_value_index]);
    int temp = array[min_value_index];
    array[min_value_index] = array[max_value_index];
    array[max_value_index] = temp;
}

void print_int_array(const int *array, int length)
{
    int a;
    for (int i = 0; i < length; i++)
    {
        a = array[i];
        printf("%d ", a);
    }
    printf("\n");
}

int compare_ints(const void *a, const void *b)
{
    // src:  https://en.cppreference.com/w/c/algorithm/qsort
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;

    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;

} // return (arg1 > arg2) - (arg1 < arg2); // possible shortcut

/* Функция ищет в отсортированном массиве B ближайший A[i] по значению */
int find_nearest_number(int number_arr_i, int length, int *array_B)
{

    int left = 0;
    int right = length - 1;

    int middle;
    int difference;
    while (left < right)
    {
        middle = left + (right - left) / 2;
        difference = array_B[middle] - number_arr_i;

        if (difference == 0)
            return array_B[middle]; // Нашли
        else if (difference < 0)
            left = middle + 1;
        else
            right = middle;
    }

    if (left == 0)
        return array_B[0];
    else
    {
        // ближайший
        if (abs(array_B[left] - number_arr_i) < abs(array_B[left - 1] - number_arr_i))
            return array_B[left];
        else
            return array_B[left - 1];
    }
}