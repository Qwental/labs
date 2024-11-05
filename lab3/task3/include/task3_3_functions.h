#ifndef __task3_3_functions_H__
#define __task3_3_functions_H__

#include "../../../include/DEFAULT_FUNCTIONS.h"

#define SIZE_STRING 128 // Врятли в мире у кого-то ФИО длиньше 128

#define INIT_SIZE_STRUCT 52

/*
Поля:
  *  long long int id_employee;
  *  char name_employee[SIZE_STRING];
  *  char surname_employee[SIZE_STRING];
  *  double salary_employee;
*/
typedef struct
{
  long long int id_employee;
  char name_employee[SIZE_STRING];
  char surname_employee[SIZE_STRING];
  double salary_employee;
} Employee;

ERRORS_EXIT_CODES enter_data_from_file(Employee *one_employee,
                                       FILE *file);

ERRORS_EXIT_CODES sort_by_decrease_salary_surname_name_id(Employee **array_of_employees,
                                                          int number);
ERRORS_EXIT_CODES sort_by_increase_salary_surname_name_id(Employee **array_of_employees,
                                                          int number);

ERRORS_EXIT_CODES print_answer(FILE *file,
                               int counter_of_employee,
                               Employee *array_of_empoyee);

void print_bar();
#endif // __task3_3_functions_H__

// valgrind ./task3_3.out /home/qwental/workspace/fund_algos/labs/lab3/task3/src/input.txt -d