#include "../include/task3_3_functions.h"

ERRORS_EXIT_CODES enter_data_from_file(Employee *one_employee,
                                       FILE *file)
{
    if (file == NULL)
    {
        return E_DEREFENCE_NULL_POINTER;
    }
    ERRORS_EXIT_CODES error;

    long long int id_employee = 0;
    double salary_employee = 0.0;

    char id_temp[SIZE_STRING];
    char salary_temp[SIZE_STRING];

    char name_employee[SIZE_STRING];
    char surname_employee[SIZE_STRING];
    int nextChar = 0;
    nextChar = fgetc(file); // Читаем следующий символ

    if (nextChar == EOF)
    {
        print_bar();
        printf("Достигнут конец файла.\n");
        return E_FALSE;
    }
    ungetc(nextChar, file); // Возвращаем символ обратно в поток

    if (fscanf(file, "%128s %128s %128s %128s\n", id_temp, name_employee, surname_employee, salary_temp) != 4)
    {
        print_bar();
        return E_INVALID_INPUT;
    }

    /* Validations */
    error = string_contains_only_digits(id_temp);
    if (error != E_SUCCESS)
    {
        print_bar();
        return E_INVALID_INPUT;
    }

    error = string_to_long_long_int(id_temp, &id_employee, 10);
    if (error != E_SUCCESS)
    {
        print_bar();
        return E_INVALID_INPUT;
    }

    error = string_to_double(salary_temp, &salary_employee);
    if (error != E_SUCCESS)
    {
        print_bar();
        return E_INVALID_INPUT;
    }

    if ((id_employee < 0) || ( salary_employee < 0))
    {
        print_bar();
        return E_INVALID_INPUT;
    }

    error = string_contains_only_alphas(name_employee);
    if (error != E_SUCCESS)
    {
        print_bar();
        return E_INVALID_INPUT;
    }
    error = string_contains_only_alphas(surname_employee);
    if (error != E_SUCCESS)
    {
        print_bar();
        return E_INVALID_INPUT;
    }

    one_employee->id_employee = id_employee;
    strcpy(one_employee->name_employee, name_employee);
    strcpy(one_employee->surname_employee, surname_employee);
    one_employee->salary_employee = salary_employee;

    return E_SUCCESS;
}

int right_compare_by_salary_surname_name_id(const void *a,
                                            const void *b)
{
    Employee *first = (Employee *)a;
    Employee *second = (Employee *)b;

    int compare_result;

    compare_result = (first->salary_employee - second->salary_employee > DBL_EPSILON) ? 1
                                                                                      : ((second->salary_employee - first->salary_employee > DBL_EPSILON) ? -1 : 0);
    if (compare_result != 0)
    {
        return compare_result;
    }

    compare_result = strcmp(first->surname_employee, second->surname_employee);
    if (compare_result != 0)
    {
        return compare_result;
    }

    compare_result = strcmp(first->name_employee, second->name_employee);
    if (compare_result != 0)
    {
        return compare_result;
    }

    compare_result = first->id_employee - second->id_employee;
    return compare_result;
}

int left_compare_by_salary_surname_name_id(const void *a,
                                           const void *b)
{
    return right_compare_by_salary_surname_name_id(b, a);
}

ERRORS_EXIT_CODES sort_by_increase_salary_surname_name_id(Employee **array_of_employees,
                                                          const int number)
{
    if (*array_of_employees == NULL)
    {
        return E_DEREFENCE_NULL_POINTER;
    }

    if (number < 1)
    {
        return E_INVALID_INPUT;
    }
    qsort(*array_of_employees, number, sizeof((*array_of_employees)[0]), right_compare_by_salary_surname_name_id);
    return E_SUCCESS;
}

ERRORS_EXIT_CODES sort_by_decrease_salary_surname_name_id(Employee **array_of_employees,
                                                          const int number)
{
    if (*array_of_employees == NULL)
    {
        return E_DEREFENCE_NULL_POINTER;
    }

    if (number < 1)
    {
        return E_INVALID_INPUT;
    }
    qsort(*array_of_employees, number, sizeof((*array_of_employees)[0]), left_compare_by_salary_surname_name_id);
    return E_SUCCESS;
}

void print_bar()
{
    printf("+----------------------+-------------------------------------+-------------------------------------+----------------------+\n");
}

ERRORS_EXIT_CODES print_answer(FILE *file_output,
                               int counter_of_employee,
                               Employee *array_of_empoyee)
{
    if (file_output == NULL)
    {
        return E_DEREFENCE_NULL_POINTER;
    }

    int i;
    for (i = 0; i < counter_of_employee; i++)
    {
        fprintf(file_output, "%lld %s %s %lf\n",
                (array_of_empoyee[i]).id_employee,
                (array_of_empoyee[i]).name_employee,
                (array_of_empoyee[i]).surname_employee,
                (array_of_empoyee[i]).salary_employee);
    }
    return E_SUCCESS;
}