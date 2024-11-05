#include "../../include/DEFAULT_FUNCTIONS.h"
#include "include/task3_3_functions.h"
/*

valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all ./task3_3.out /home/qwental/workspace/fund_algos/labs/lab3/task3/src/input.txt -d /home/qwental/workspace/fund_algos/labs/lab3/task3/src/output.txt



*/
int main(int argc,
         char *argv[])

{
    FILE *file = NULL;
    FILE *file_output = NULL;
    Employee one_employee;
    ERRORS_EXIT_CODES error = E_SUCCESS;
    int array_size = INIT_SIZE_STRUCT;
    int counter_of_employee = 0;
    Employee *array_of_empoyee = NULL;
    Employee *temp = NULL;

    if (argc < 4)
    {
        return print_Errors(E_INVALID_ARG);
    }

    if ((argv == NULL) || (argv[1] == NULL) || (argv[2] == NULL) || (argv[3] == NULL))
    {
        return print_Errors(E_DEREFENCE_NULL_POINTER);
    }

    if ((strlen(argv[2]) != 2) || ((argv[2][0] != '-') && (argv[2][0] != '/')) || ((argv[2][1] != 'd') && (argv[2][1] != 'a')))
    {
        return print_Errors(E_INVALID_FLAG_ARG);
    }

    error = cheak_files(argv[1], argv[3]);
    if (error != E_SUCCESS)
    {
        return print_Errors(error);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        return print_Errors(E_CANNOT_OPEN_FILE);
    }

    // file_output = fopen(argv[3], "w");
    // if (file_output == NULL)
    // {
    //     fclose(file);
    //     return print_Errors(E_CANNOT_OPEN_FILE);
    // }

    array_of_empoyee = (Employee *)malloc(sizeof(Employee) * array_size);
    if (array_of_empoyee == NULL)
    {
        fclose(file);
        return print_Errors(E_MEMORY_ALLOCATION);
    }

    printf("\nОбработка файла с данными \n");

    print_bar();
    printf("| %-20s | %-35s | %-35s | %-20s |\n", "ID", "NAME", "SURNAME", "SALARY");
    print_bar();

    while ((error = enter_data_from_file(&one_employee, file)) == E_SUCCESS)
    {
        

        printf("| %-20lld | %-35s | %-35s | %-20.2lf |\n",
               one_employee.id_employee,
               one_employee.name_employee, one_employee.surname_employee, one_employee.salary_employee);

/*
        */

        if (array_size <= counter_of_employee)
        {
            array_size *= 2;
            temp = (Employee *)realloc(array_of_empoyee, sizeof(Employee) * array_size);

            if (temp == NULL)
            {
                free(array_of_empoyee);
                fclose(file);
                return print_Errors(E_MEMORY_ALLOCATION);
            }

            array_of_empoyee = temp;
        }
        array_of_empoyee[counter_of_employee] = one_employee;
        counter_of_employee++;
    }

    if (error != E_FALSE)
    {
        fclose(file);
        free(array_of_empoyee);
        printf("ERROR: При обработке файла не получилось обработать данные\n");
        return E_INVALID_INPUT;
    }

    fclose(file);

    file_output = fopen(argv[3], "w");
    if (file_output == NULL)
    {
        free(array_of_empoyee);
        return print_Errors(E_CANNOT_OPEN_FILE);
    }
    switch (argv[2][1])
    {

    case 'a':
        printf("Сортируем по возврастанию\n");

        sort_by_increase_salary_surname_name_id(&array_of_empoyee, counter_of_employee);
        break;

    case 'd':
        printf("Сортруем по убыванию\n");

        sort_by_decrease_salary_surname_name_id(&array_of_empoyee, counter_of_employee);
        break;

    default:
        print_Errors(E_INVALID_ARG);

        free(array_of_empoyee);
        fclose(file_output);
        return E_INVALID_INPUT;
    }

    error = print_answer(file_output, counter_of_employee, array_of_empoyee);
    if (error != E_SUCCESS)
    {
        print_Errors(error);
    }

    free(array_of_empoyee);
    fclose(file_output);

    return error;
}