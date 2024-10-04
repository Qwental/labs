#include "task5_main.h"

// TODO  предыд член  и сравнивать по еэписло

/*
gcc task5_main.c task5_functions.c -lm -std=c99 -Woverflow -Wall -o task5.out

./task5.out

*/

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("ERROR: Некоррекный ввод, аргументов должно быть 2!\n");
		return E_NOT_ENOUGH_PARAMS;
	}
	double epsilon, x;

	if (string_to_double(argv[1], &epsilon) != E_SUCCESS)
	{
		printf("ERROR: Невалидное epsilon\n");
		return E_INVALID_ARG;
	}

	if (string_to_double(argv[2], &x) != E_SUCCESS)
	{
		printf("ERROR: Невалидное число x\n");
		return E_INVALID_ARG;
	}

	if (epsilon <= 0)
	{
		printf("ERROR: Невалидное epsilon\n");
		return E_INVALID_ARG;
	}
	if ((fabs(x) > sqrt(DBL_MAX)))
	{
		printf("ERROR: Невалидное число x\n");
		return E_INVALID_ARG;
	}

	double sigma = 0.0;
	enum Errors err;
	// a

	err = func_a(x, epsilon, &sigma);
	if (err == E_SUCCESS)
		printf("Ряд а): %.15lf\n", sigma);

	else if (err == E_TYPE_OVERFLOW)
	{
		printf("a) ERROR: Переполнения типа, невалидное число\n");
		return E_INVALID_ARG;
	}
	else
	{
		printf("a) ERROR: Некорректный ввод\n");
		return E_INVALID_INPUT;
	}
	// b

	err = (func_b(x, epsilon, &sigma));
	if (err == E_SUCCESS)
		printf("Ряд b): %.15lf\n", sigma);

	else if (err == E_TYPE_OVERFLOW)
	{
		printf("Ряд b) ERROR: Переполнения типа, невалидное число\n");
		return E_INVALID_ARG;
	}
	else
	{
		printf("Ряд b) ERROR: Некорректный ввод\n");
		return E_INVALID_INPUT;
	}

	if ((fabs(x) >= 1))
	{
		printf("Ряд c) расходиться!\n");
	}
	else
	{
		// c

		err = (func_c(x, epsilon, &sigma));
		if (err == E_SUCCESS)
			printf("Ряд c): %.15lf\n", sigma);

		else if (err == E_TYPE_OVERFLOW)
		{
			printf("Ряд c) ERROR: Переполнения типа, невалидное число\n");
			return E_INVALID_ARG;
		}
		else
		{
			printf("Ряд c) ERROR: Некорректный ввод\n");
			return E_INVALID_INPUT;
		}
	}

	if ((fabs(x) >= 1))
	{
		printf("Ряд d) расходиться!\n");
		return E_SUCCESS;
	}

	// d
	err = (func_d(x, epsilon, &sigma));
	if (err == E_SUCCESS)
		printf("Ряд d): %.15lf\n", sigma);

	else if (err == E_TYPE_OVERFLOW)
	{
		printf("Ряд d) ERROR: Переполнения типа, невалидное число\n");
		return E_INVALID_ARG;
	}
	else
	{
		printf("Ряд d) ERROR: Некорректный ввод\n");
		return E_INVALID_INPUT;
	}

	return E_SUCCESS;
}
