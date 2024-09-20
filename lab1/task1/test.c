#include <stdio.h>
#include <math.h>

void func(int *arr)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            printf("%d ", (arr[i * 3 + j]));
        }
        printf("\n");
    }
}

char digit_to_16(int num)
{
    switch (num)
    {
    case 0:
        return '0';
    case 1:
        return '1';
    case 2:
        return '2';
    case 3:
        return '3';
    case 4:
        return '4';
    case 5:
        return '5';
    case 6:
        return '6';
    case 7:
        return '7';
    case 8:
        return '8';
    case 9:
        return '9';
    case 10:
        return 'A';
    case 11:
        return 'B';
    case 12:
        return 'C';
    case 13:
        return 'D';
    case 14:
        return 'E';
    case 15:
        return 'F';
    }
}

# if 0
int main()
{

    char **num_x;
    scanf("%s", &num_x);
    int i = 0;

    while (number > 0)
    {
        (*result_conv_to_16)[i] = digit_to_16(number % 16);
        number = number / 16;
        i++;
        *length++;
    }

    for (int j = 0; j < *length; j++)
    {
        printf("%s ", result_conv_to_16[j]);
    }
}
#endif