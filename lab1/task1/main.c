#include "functions.h"
// gcc main.c -lm -std=c99
enum Errors string_to_int(const char *str_number, long long int *int_result_number, int base)
{

	char *endptr;
	*int_result_number = strtol(str_number, &endptr, base);

	if (*int_result_number == LLONG_MAX || *int_result_number == LLONG_MIN)
	{
		return E_INVALID_INPUT;
	}
	else if (*int_result_number == 0)
	{
		return E_INVALID_INPUT;
	}
	else if (*endptr != '\0')
	{
		return E_INVALID_INPUT;
	}

	return E_SUCCESS;
}

enum Errors factorial_x(long long int number_x, unsigned long long int *result_fact_x)
{
	*result_fact_x = 1;
	for (long long n = 2; n <= number_x; ++n)
	{
		if (*result_fact_x > ULLONG_MAX / n)
		{
			return E_NOT_ENOUGH_MEMORY;
		}
		*result_fact_x *= n;
	}

	return E_SUCCESS;
}

#if 1
int main(int argc, char *argv[])
{
	# if 0
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251); //установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); //установка кодовой страницы win-cp 1251 в поток вывода
	// запускайте на linux =)
	#endif

	if (argc != 3)
	{
		printf("ERROR: Некоррекный ввод, аргументов должно быть 2!\n");
		// нужно вернуть ошибку
		return E_NOT_ENOUGH_PARAMS;
	}

	if (!(((argv[1][0] == '-') || (argv[1][0] == '/')) && (argv[1][2] == '\0')))
	{
		printf("ERROR: Некоррекный ввод аргументов! Неизвестный символ: \"%c\" \n", argv[1][0]);
		return E_INVALID_ARG;
	}

	long long int number_x = 0;

	// string_to_int
	if (string_to_int(argv[2], &number_x, 10) != E_SUCCESS)
	{
		printf("ERROR: Невалидное число\n");
		return E_INVALID_INPUT;
	}

	switch (argv[1][1])
	{
	case 'h':
		// TODO либо решето либо перебор до корня

		break;

	case 'p':
		// TODO либо решето либо перебор до корня
		break;
	case 's':
		// TODO s параметр
		break;

	case 'e':
		// TODO через мемоизацию
		break;

	case 'a':
		// TODO либо решето либо до корня перебор
		break;

	case 'f':

		if (number_x < 0)
		{
			printf("ERROR: Изходя из определения факториала числа, найти факториал отрицательного числа невозможно\n");
			return E_INVALID_INPUT;
		}

		unsigned long long int result_fact_x = 1;

		if (factorial_x(number_x, &result_fact_x) == E_NOT_ENOUGH_MEMORY)
		{
			printf("ERROR: Произошло переполнения типа unsigned long long int; вывод значения %lld! невозможно данной программой\n", number_x);
			return E_NOT_ENOUGH_MEMORY;
		}
		printf(" %lld! = %llu\n", number_x, result_fact_x);

		break;

	default:
		printf("ERROR: Некоррекный ввод аргументов, такого ФЛАГА нет: %s\n", argv[1]);
		return E_INVALID_ARG;
	}
	

	return E_SUCCESS;
}
#endif