#include "task5_functions.h"

int is_double_overflow(double to_check)
{
	if ((fabs(to_check) > DBL_MAX) || to_check == HUGE_VAL || to_check == -HUGE_VAL || isnan(to_check) || isinf(to_check))
	{
		return E_TYPE_OVERFLOW;
	}
	return E_SUCCESS;
}

enum Errors string_to_double(const char *str, double *num)
{
	if (!str || !num)
	{
		return E_INVALID_INPUT;
	}
	char *endptr;
	double value = strtod(str, &endptr);

	if (*endptr != '\0')
	{
		return E_INVALID_INPUT;
	}

	if (is_double_overflow(value))
	{
		return E_TYPE_OVERFLOW;
	}
	*num = value;
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
	*sigma_sum = 0.0;

	double current_f = 1.0;
	int n = 0; // f = 1 + ... + ...
	double res = 0.0;

	while (fabs(current_f) > epsilon)
	{
		res += current_f;
		n++;

		if (n >= INT_MAX - 1)
			return E_INVALID_INPUT;

		current_f *= (x / n);

		if (is_double_overflow(current_f) || is_double_overflow(res))
		{
			return E_TYPE_OVERFLOW;
		}
	}
	*sigma_sum = res;
	return E_SUCCESS;
}

enum Errors func_b(double x, double epsilon, double *sigma_sum)
{
	/*
	по тейлору sigma_sum ... = cos(x)
	*/

	if (sigma_sum == NULL)
		return E_INVALID_INPUT;
	*sigma_sum = 0.0;

	double current_f = 1.0;
	int n = 0;
	int iter = 0;
	double res = 0.0;

	while (fabs(current_f) >= epsilon)
	{

		if (!(iter & 1))
			res += current_f;
		else
			res -= current_f;

		current_f *= ((x / (n+1)) * (x / (n + 1 + 1)));

		if (is_double_overflow(current_f) || is_double_overflow(res))
			return E_TYPE_OVERFLOW;
		n += 2;
		iter++;
		if (n >= INT_MAX - 2)
			return E_INVALID_INPUT;
	}
	*sigma_sum = res;

	return E_SUCCESS;
}

enum Errors func_c(double x, double epsilon, double *sigma_sum)
{

	if (sigma_sum == NULL)
		return E_INVALID_INPUT;
	*sigma_sum = 0.0;

	double current_f = 1.0;

	int n = 0;
	int n3_drob = 0;

	double res = 0.0;

	while (fabs(current_f) >= epsilon)
	{
		res += current_f;
		n++;

		if ((n >= INT_MAX - 1))
			return E_INVALID_INPUT;

		n3_drob += 3;
		current_f *= (((n * 27 * n * n) / ((n3_drob - 2))) * ((x * x) / ((n3_drob - 1) * (n3_drob))));

		if ((n3_drob >= INT_MAX - 3))
			return E_INVALID_INPUT;

		if (is_double_overflow(current_f) || is_double_overflow(res))
			return E_TYPE_OVERFLOW;
	}
	*sigma_sum = res;

	return E_SUCCESS;
}

enum Errors func_d(double x, double epsilon, double *sigma_sum)
{

	if (sigma_sum == NULL)
		return E_INVALID_INPUT;
	*sigma_sum = 0.0;

	double current_f = x * x * 0.5; // n=2 подставил

	int n = 2;
	int iter = 1;

	double res = 0.0;

	while (fabs(current_f) > epsilon)
	{

		if (!(iter & 1))
			res += current_f;
		else
			res -= current_f;

		iter++;
		n += 2;
		if ((n >= INT_MAX - 2) || (iter >= INT_MAX - 1))
			return E_TYPE_OVERFLOW;

		// двойной фактор типо сразу считаем
		current_f *= (((n - 1) * x) / (n)) * x;

		if (is_double_overflow(current_f) || is_double_overflow(res))
			return E_TYPE_OVERFLOW;
	}
	*sigma_sum = res;

	return E_SUCCESS;
}
