#include "functions.h"
// gcc main.c -lm -std=c99 -Woverflow -Wall

double factorial(int n)
{
	double fac = 1.0;
	for (int i = 1; i <= n; i++)
	{
		fac *= i;
	}
	return fac;
}

enum Errors string_to_double(const char *str, double *num)
{
	char *endptr;
	if (num == NULL || str == NULL)
		return E_INVALID_ARG;
	*num = strtod(str, &endptr); // конверт троку в числ с плав точк
	if (*num == HUGE_VAL || *num == -HUGE_VAL)
		return E_INVALID_ARG;
	else if (*endptr != '\0')
		return E_INVALID_ARG;
	return E_SUCCESS;
}

enum Errors func_a(double x, double epsilon, double *sigma_sum)
{
	/*
	https://www.youtube.com/watch?app=desktop&v=p9XeWwSypd4
	по тейлору sigma_sum (x^n)\(x!) = e
	*/
	if (sigma_sum == NULL)
		return E_INVALID_INPUT;

	double f = 1.0;
	*sigma_sum = 1.0;
	int n = 1; // f = 1 + ... + ...

	while (fabs(f) > epsilon)
	{
		f *= x / n;
		*sigma_sum += f;
		n++;
		if (n > INT_MAX - 1)
			return E_INVALID_INPUT;
	}
	return E_SUCCESS;
}

enum Errors func_b(double x, double epsilon, double *sigma_sum)
{
	/*
	по тейлору sigma_sum ... = cos(x)
	*/

	if (sigma_sum == NULL)
		return E_INVALID_INPUT;

	// f = 1 + ... - ...
	*sigma_sum = 1.0;
	double f = 1.0;
	int n = 1;

	while (fabs(f) > epsilon)
	{
		f *= (pow(-1, n) * pow(x, 2 * n)) / (factorial(2 * n));
		*sigma_sum += f;
		n++;
		if (n > INT_MAX - 1)
			return E_INVALID_INPUT;
	}
	return E_SUCCESS;
}

enum Errors func_c(double x, double epsilon, double *sigma_sum)
{
	/*
	чет не решается по тейлору
	*/

	if (sigma_sum == NULL)
		return E_INVALID_INPUT;

	int n = 0;
	double f = 1.0;
	*sigma_sum = 0.0;

	while (fabs(f) > epsilon)
	{
		f = (pow(3, 3 * n) * pow(factorial(n), 3) * pow(x, 2 * n)) / factorial(3 * n);
		*sigma_sum += f;
		n++;
		if (n > INT_MAX - 1)
			return E_INVALID_INPUT;
	}
	return E_SUCCESS;
}

enum Errors func_d(double x, double epsilon, double *sigma_sum)
{
	if (sigma_sum == NULL)
		return E_INVALID_INPUT;

	int n = 0;
	double f = 1.0;
	*sigma_sum = 0.0;

	while (fabs(f) > epsilon)
	{
		f = ((pow(-1, n) * (2 * n + 1) * (factorial(2 * n) / pow(factorial(n), 2))) * pow((x / 2), 2 * n));
		*sigma_sum += f;
		n++;
		if (n > INT_MAX - 1)
			return E_INVALID_INPUT;
	}

	return E_SUCCESS;
}

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

	if (func_a(x, epsilon, &sigma) == E_SUCCESS)
		printf("Ряд а): %lf\n", sigma);
	else
	{
		printf("ERROR: Переполнения типа, невалидное число\n");
		return E_INVALID_ARG;
	}

	if (func_b(x, epsilon, &sigma) == E_SUCCESS)

		printf("Ряд b): %lf\n", sigma);

	else
	{
		printf("ERROR: Переполнения типа, невалидное число\n");
		return E_INVALID_ARG;
	}

	if(!(fabs(x)>1))
{
		printf("ERROR: Невалидное число x для C) и D)\n");
		return E_INVALID_ARG;
	}
	

	if (func_c(x, epsilon, &sigma) == E_SUCCESS)
		printf("Ряд с): %lf\n", sigma);
	else
	{
		printf("ERROR: Переполнения типа, невалидное число\n");
		return E_INVALID_ARG;
	}

	if (func_d(x, epsilon, &sigma) == E_SUCCESS)
		printf("Ряд d): %lf\n", sigma);
	else
	{
		printf("ERROR: Переполнения типа, невалидное число\n");
		return E_INVALID_ARG;
	}

	return E_SUCCESS;
}