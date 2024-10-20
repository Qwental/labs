#include "../../include/DEFAULT_FUNCTIONS.h"
#include "include/task2_2_functions.h"

#define INIT_SIZE 6
int main()
{

    int length_array = INIT_SIZE;
    double array[length_array];
    srand(time(NULL));
    printf("Изначальный массив фиксированного размера %d: ", length_array);
    int i;
    for (i = 0; i < length_array; i++)
    {
        // rand[a:b]
        // a = 100 b = 513
        array[i] = ((100 + rand() % (513 - 100 + 1)) / (double)(1 + rand() % (11 - 1 + 1)));
        printf("%lf ", array[i]);
    }
    printf("\n");

    long double result = 0.0;
    geometric_mean(INIT_SIZE + 1, &result, array[0], array[1], array[2], array[3], array[4], array[5]);
    printf("Среднее геометрическое значений массива: %Lf\n\n\n", result);

    double x = 2.0;
    int n = 100;
    result = my_fast_pow(x, n);
    printf("%f в степени %d равно %Lf\n", x, n, result);

    x = 3.0;
    n = 5;
    result = my_fast_pow(x, n);
    printf("%f в степени %d равно %Lf\n", x, n, result);

    x = 2;
    n = -3;
    result = my_fast_pow(x, n);

    printf("%f в степени %d равно %Lf\n", x, n, result);
    return E_SUCCESS;
}
