#include "functions.h"
// gcc main.c -lm -std=c99 -Woverflow


int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("ERROR: Некоррекный ввод, аргументов должно быть 2!\n");
		return E_NOT_ENOUGH_PARAMS;
	}

	if (!(((argv[2][0] == '-') || (argv[2][0] == '/')) && (argv[2][2] == '\0')))
	{
		printf("ERROR: Некоррекный ввод аргументов! Неизвестный символ: \"%c\" \n", argv[2][0]);
		return E_INVALID_ARG;
	}

	long long int number_x = 0;

	// string_to_int
	if (string_to_int(argv[1], &number_x, 10) != E_SUCCESS)
	{
		printf("ERROR: Невалидное число\n");
		return E_INVALID_INPUT;
	}

	switch (argv[2][1])
	{
	case 'h':
		char flag = 0;
		// if (number_x < 0)
		// 	number_x = -number_x;

		if (number_x == 0)
		{
			printf("ERROR: не выполненоимо для числа = 0");
			return E_INVALID_INPUT;
		}

		for (int i = 1; i <= 100; ++i)
		{
			if ((flag == 0) && (i % number_x == 0))
			{
				flag = 1;
				printf("Натуральные числа в пределах 100 включительно, кратные %lld:\n", number_x);
				printf("%d\n", i);
			}
			else if (i % number_x == 0)
				printf("%d\n", i);
		}
		if (flag == 0)
			printf("НЕТ Натуральных чисел в пределах 100 включительно, кратные %lld:\n", number_x);
		break;

	case 'p':

		if (number_x == 0)
		{
			printf("ERROR: не выполненоимо для числа = 0\n");
			return E_INVALID_INPUT;
		}

		if (number_x == 1)
		{
			printf("Число 1 — не является ни простым, ни составным числом!\n");
			break;
		}

		if (is_prime(number_x))
		{
			printf("Число %lld является простым\n", number_x);
		}
		else
		{
			printf("Число %lld является составным\n", number_x);
		}
		break;

	case 's':

		if (number_x == 0)
		{
			printf("Число 0 в 16сс: \n 0");
			break;
		}
		char flag_znak = 0;
		if (number_x < 0)
		{
			flag_znak = 1;
			number_x = -number_x;
		}

		int length = 0;
		char *result_conv_to_16 = argv[1];

		int i = 0;
		printf("Число %s в 16сс: \n", argv[1]);

		while (number_x > 0)
		{
			(result_conv_to_16)[i] = digit_to_16(number_x % 16);
			number_x = number_x / 16;
			i++;
		}
		(result_conv_to_16)[i] = '\0';

		char *p = result_conv_to_16;
		do
		{
			length++;
			p++;
		} while (*p != '\0');
		p--;
		if(flag_znak) printf("- ");

		while (length >= 0)
		{
			printf("%c ", *p);
			p--;
			length--;
		}
		puts("");
		break;

	case 'e':
		if (number_x > 10 || number_x < 0)
		{
			printf("ERROR: некорректное число\n");
			return E_INVALID_INPUT;
		}

		unsigned long long int table_e[10][10];

		if (build_table((unsigned long long int *)table_e, number_x) == E_TYPE_OVERFLOW)
		{
			// 10^10 влезает в uns long long
			return E_TYPE_OVERFLOW;
		}
		else
		{
			unsigned long long int *arr = (unsigned long long int *)table_e;
			printf("Таблицу степеней (для всех показателей в диапазоне от 1 до %lld) оснований от 1 до 10\n", number_x);
			for (int i = 0; i < 10; ++i)
			{
				for (int j = 0; j < number_x; ++j)
				{
					printf("%11llu ", arr[i * number_x + j]);
				}
				printf("\n");
			}
		}

		break;

	case 'a':
		unsigned long long int sum_prime_numbers = 0;

		if (number_x <= 0)
		{
			printf("ERROR: невозможно вычислить сумму натуральных чисел на промежутке\n");
			printf(" от 1 до %lld т.к. натуральные числа по определению положительные числа", number_x);
			return E_INVALID_INPUT;
		}

		if (sum_of_prime_numbers(number_x, &sum_prime_numbers) == E_TYPE_OVERFLOW)
		{
			printf("ERROR: Произошло переполнения типа unsigned long long int\n");
			printf("Вывод суммы всех натуральных чисел от 1 до %lld невозможно данной программой\n", number_x);
			return E_TYPE_OVERFLOW;
		}

		printf("Cумма всех натуральных чисел от 1 до %lld = %llu\n", number_x, sum_prime_numbers);
		break;

	case 'f':

		if (number_x < 0)
		{
			printf("ERROR: Изходя из определения факториала числа, найти факториал отрицательного числа невозможно\n");
			return E_INVALID_INPUT;
		}

		if (number_x == 0)
		{
			printf("0! = 1\n");
			break;
		}

		unsigned long long int result_fact_x = 1;

		if (factorial_x(number_x, &result_fact_x) == E_TYPE_OVERFLOW)

		{
			printf("ERROR: Произошло переполнения типа unsigned long long int\n");
			printf("Вывод значения %lld! невозможно данной программой\n", number_x);
			return E_TYPE_OVERFLOW;
		}
		printf("%lld! = %llu\n", number_x, result_fact_x);

		break;

	default:
		printf("ERROR: Некоррекный ввод аргументов, такого ФЛАГА %s не предусмотрено!\n", argv[1]);
		return E_INVALID_ARG;
	}

	return E_SUCCESS;
}
