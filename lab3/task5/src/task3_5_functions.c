#include "../include/task3_5_functions.h"

ERRORS_EXIT_CODES check_numbers(int count, ...)
{
    va_list args;

    va_start(args, count);

    int mark;
    int i;

    for (i = 0; i < count; i++)
    {
        mark = va_arg(args, int);
        if (mark < 2 || mark > 5)
        {
            va_end(args);
            return E_INVALID_INPUT;
        }
    }
    va_end(args);
    return E_SUCCESS;
}

/* Внутренняя функция, поэтому не нада ее валидировать */ 
void free_array_of_students(Student *array_of_students,
                            int counter_of_students)
{
    int i;
    for (i = 0; i < counter_of_students; i++)
    {
        free(array_of_students[i].array_of_exam_marks);
    }
    free(array_of_students);
}

ERRORS_EXIT_CODES enter_data_from_file(FILE *file,
                                       Student **array_of_students,
                                       int *counter_of_students)
{
    if (file == NULL)
    {
        return E_DEREFENCE_NULL_POINTER;
    }

    ERRORS_EXIT_CODES error;

    long long int id_stud = 0;
    char id_temp[SIZE_STRING];

    unsigned char mark1 = 0;
    unsigned char mark2 = 0;
    unsigned char mark3 = 0;
    unsigned char mark4 = 0;
    unsigned char mark5 = 0;

    char name_stud[SIZE_STRING];
    char surname_stud[SIZE_STRING];
    char group_stud[SIZE_STRING];
    Student *temp;

    *counter_of_students = 0;
    while (!feof(file))
    {
        (*counter_of_students)++;

        temp = NULL;
        temp = realloc(*array_of_students, (*counter_of_students) * sizeof(Student)); // сложно, зато проще логика
        if (temp == NULL)
        {
            free_array_of_students(*array_of_students, *counter_of_students);
            fclose(file);
            return E_MEMORY_ALLOCATION;
        }
        *array_of_students = temp;

        (*array_of_students)[*counter_of_students - 1].array_of_exam_marks = malloc(5 * sizeof(unsigned char));

        if (((*array_of_students)[*counter_of_students - 1].array_of_exam_marks) == NULL)
        {
            free_array_of_students(*array_of_students, *counter_of_students);
            fclose(file);

            return E_MEMORY_ALLOCATION;
        }

        

        if (fscanf(file, "%128s %128s %128s %128s %hhu %hhu %hhu %hhu %hhu", id_temp,
                   surname_stud, name_stud, group_stud, &mark1, &mark2, &mark3, &mark4, &mark5) != 9)
        {
            // puts("FSCANF problem");
            free_array_of_students(*array_of_students, *counter_of_students);
            fclose(file);

            return E_INVALID_INPUT;
        }

        /* VALIDATIONS */

        error = string_to_long_long_int(id_temp, &id_stud, 10);
        if (error != E_SUCCESS)
        {
            // puts("ID_PROBLEM");
            free_array_of_students(*array_of_students, *counter_of_students);
            fclose(file);
            return E_INVALID_INPUT;
        }

        if (id_stud <= 0 || (check_numbers(5, mark1, mark2, mark3, mark4, mark5) != E_SUCCESS))
        {
            // puts("ID_PROBLEM 2222");

            free_array_of_students(*array_of_students, *counter_of_students);
            fclose(file);
            return E_INVALID_INPUT;
        }

        error = string_contains_only_alphas(surname_stud);
        if (error != E_SUCCESS)
        {
            // puts("surname_PROBLEM");
            free_array_of_students(*array_of_students, *counter_of_students);
            fclose(file);
            return E_INVALID_INPUT;
        }

        error = string_contains_only_alphas(name_stud);
        if (error != E_SUCCESS)
        {
            // puts("name_PROBLEM 2222");
            free_array_of_students(*array_of_students, *counter_of_students);
            fclose(file);
            return E_INVALID_INPUT;
        }
        if (group_stud == NULL || strlen(group_stud) == 0)
        {
            // puts("group prob");
            free_array_of_students(*array_of_students, *counter_of_students);
            fclose(file);
            return E_INVALID_INPUT;
        }

        /* END OF VALIDATIONS */

        // printf("%s %s %s %s %hhu %hhu %hhu %hhu %hhu\n", id_temp,
        //        surname_stud, name_stud, group_stud, mark1, mark2, mark3, mark4, mark5);

        (*array_of_students)[*counter_of_students - 1].id_student = id_stud;

        strcpy((*array_of_students)[*counter_of_students - 1].name_student, name_stud);
        strcpy((*array_of_students)[*counter_of_students - 1].surname_student, surname_stud);
        strcpy((*array_of_students)[*counter_of_students - 1].group_student, group_stud);

        (*array_of_students)[*counter_of_students - 1].array_of_exam_marks[0] = mark1;
        (*array_of_students)[*counter_of_students - 1].array_of_exam_marks[1] = mark2;
        (*array_of_students)[*counter_of_students - 1].array_of_exam_marks[2] = mark3;
        (*array_of_students)[*counter_of_students - 1].array_of_exam_marks[3] = mark4;
        (*array_of_students)[*counter_of_students - 1].array_of_exam_marks[4] = mark5;

        // printf("%u %s %s %s %hhu %hhu %hhu %hhu %hhu\n",
        //        (*array_of_students)[*counter_of_students - 1].id_student,
        //        (*array_of_students)[*counter_of_students - 1].surname_student,
        //        (*array_of_students)[*counter_of_students - 1].name_student,
        //        (*array_of_students)[*counter_of_students - 1].group_student,
        //        (*array_of_students)[*counter_of_students - 1].array_of_exam_marks[0],
        //        (*array_of_students)[*counter_of_students - 1].array_of_exam_marks[1],
        //        (*array_of_students)[*counter_of_students - 1].array_of_exam_marks[2],
        //        (*array_of_students)[*counter_of_students - 1].array_of_exam_marks[3],
        //        (*array_of_students)[*counter_of_students - 1].array_of_exam_marks[4]);
    }

    fclose(file);
    return E_SUCCESS;
}

void UserInterfaceTable()
{
    printf("#################################################################################\n");
    printf("#  Выберете действие:\n");
    printf("#   0  чтобы выйти\n");
    printf("#   1  чтобы найти студентов по ID\n");
    printf("#   2  чтобы найти студентов по фамилии\n");
    printf("#   3  чтобы найти студентов по имени\n");
    printf("#   4  чтобы найти студентов по группе\n");
    printf("#   5  чтобы отсортировать по ID\n");
    printf("#   6  чтобы отсортировать по фамилии\n");
    printf("#   7  чтобы отсортировать по имени\n");
    printf("#   8  чтобы отсортировать по группе\n");
    printf("#   9  чтобы сохранить информацию о студенте по ID в файл\n");
    printf("#   10 чтобы сохранить информацию  об оценках лучшего студентах\n");
    printf("#################################################################################\n");
}

double calculate_average_grade(Student *one_student)
{
    double sum = 0;
    int i;
    for (i = 0; i < 5; i++)
    {
        sum += one_student->array_of_exam_marks[i];
    }
    return sum / 5.0;
}

ERRORS_EXIT_CODES load_average_all_to_file(Student *array_of_students,
                                           int counter_of_students,
                                           FILE *file_out)
{
    if (file_out == NULL || array_of_students == NULL)
    {
        return E_DEREFENCE_NULL_POINTER;
    }

    double average_all_students_marks = 0.0;
    double average_marks = 0.0;
    int i;

    for (i = 0; i < counter_of_students; i++)
    {
        average_all_students_marks += calculate_average_grade(&array_of_students[i]);
    }
    average_all_students_marks /= counter_of_students;
    if (fprintf(file_out, "Лучшие студенты которые имеют балл выше чем ср. ариф. по экзаменам: %.3lf\n", average_all_students_marks) < 0)
    {
        return E_INVALID_INPUT;
    }

    for (i = 0; i < counter_of_students; i++)
    {
        average_marks = calculate_average_grade(&array_of_students[i]);

        if (average_marks > average_all_students_marks)
        {
            if (fprintf(file_out, "%s %s %.3lf\n", array_of_students[i].name_student, array_of_students[i].surname_student,
                        average_marks) < 0)
            {
                return E_INVALID_INPUT;
            }
        }
    }

    fprintf(file_out, "\n");
    return E_SUCCESS;
}
void print_table_header()
{
    printf("+----------+----------------------+----------------------+----------------------+-------+-------+-------+-------+-------+\n");
    printf("|    ID    |   Surname            |         Name         |         Group        | Mark1 | Mark2 | Mark3 | Mark4 | Mark5 |\n");
    printf("+----------+----------------------+----------------------+----------------------+-------+-------+-------+-------+-------+\n");
}

ERRORS_EXIT_CODES print_students_from_array(Student *array_of_students, int counter_of_students)
{

    if(array_of_students == NULL){
        return E_DEREFENCE_NULL_POINTER;
    }
    print_table_header();
    for (int i = 0; i < counter_of_students; i++)
    {
        printf("| %-8u | %-20s | %-20s | %-20s | %-5hhu | %-5hhu | %-5hhu | %-5hhu | %-5hhu |\n",
               (array_of_students)[i].id_student,
               (array_of_students)[i].surname_student,
               (array_of_students)[i].name_student,
               (array_of_students)[i].group_student,
               (array_of_students)[i].array_of_exam_marks[0],
               (array_of_students)[i].array_of_exam_marks[1],
               (array_of_students)[i].array_of_exam_marks[2],
               (array_of_students)[i].array_of_exam_marks[3],
               (array_of_students)[i].array_of_exam_marks[4]);
    }
    printf("+----------+----------------------+----------------------+----------------------+-------+-------+-------+-------+-------+\n");
    return E_SUCCESS;
}

ERRORS_EXIT_CODES print_student_in_file_by_id(Student *array_of_students,
                                              int found,
                                              FILE *file_out,
                                              double average_grade)
{

    if (file_out == NULL || array_of_students == NULL)
    {
        return E_DEREFENCE_NULL_POINTER;
    }

    if (fprintf(file_out, "%s %s %s %lf\n", array_of_students[found].surname_student, array_of_students[found].name_student,
                array_of_students[found].group_student, average_grade) < 0)
    {
        return E_INVALID_INPUT;
    }
    printf("Информация записана в файл\n");

    return E_SUCCESS;
}

ERRORS_EXIT_CODES print_student(Student *array_of_students, int i)
{

    if (array_of_students == NULL)
    {
        return E_DEREFENCE_NULL_POINTER;
    }

    if (i == -1)
    {
        printf("Такого студента нет\n");
        return E_FALSE;
    }
    else
    {
        // print_table_header();
        printf("| %-8u | %-20s | %-20s | %-20s | %-5hhu | %-5hhu | %-5hhu | %-5hhu | %-5hhu |\n",
               (array_of_students)[i].id_student,
               (array_of_students)[i].surname_student,
               (array_of_students)[i].name_student,
               (array_of_students)[i].group_student,
               (array_of_students)[i].array_of_exam_marks[0],
               (array_of_students)[i].array_of_exam_marks[1],
               (array_of_students)[i].array_of_exam_marks[2],
               (array_of_students)[i].array_of_exam_marks[3],
               (array_of_students)[i].array_of_exam_marks[4]);
        printf("+----------+----------------------+----------------------+----------------------+-------+-------+-------+-------+-------+\n");
    }
    return E_SUCCESS;
}

int compare_students_by_group(const void *a,
                              const void *b)
{
    Student *student_1 = (Student *)a;
    Student *student_2 = (Student *)b;

    return (strcmp(student_1->group_student, student_2->group_student));
}
int compare_students_by_id(const void *a,
                           const void *b)
{
    Student *student_1 = (Student *)a;
    Student *student_2 = (Student *)b;

    return student_1->id_student - student_2->id_student;
}

int compare_students_by_surname(const void *a,
                                const void *b)
{
    Student *student_1 = (Student *)a;
    Student *student_2 = (Student *)b;

    return (strcmp(student_1->surname_student, student_2->surname_student));
}

int compare_students_by_name(const void *a,
                             const void *b)
{
    Student *student_1 = (Student *)a;
    Student *student_2 = (Student *)b;

    return (strcmp(student_1->name_student, student_2->name_student));
}

int find_student_by_name(Student *array_of_students,
                         int count_of_students,
                         char *buffer)
{
    if (array_of_students == NULL || buffer == NULL || count_of_students < 1)
    {
        return 0;
    }

    int flag = 0;
    for (int i = 0; i < count_of_students; i++)
    {
        if (strcmp(array_of_students[i].name_student, buffer) == 0)
        {
            if (flag == 0)
            {
                print_table_header();
            }
            print_student(array_of_students, i);
            flag = 1;
        }
    }

    return flag;
}

int find_student_by_group(Student *array_of_students,
                          int count_of_students,
                          char *buffer)
{
    if (array_of_students == NULL || buffer == NULL || count_of_students < 1)
    {
        return 0;
    }
    int flag = 0;

    for (int i = 0; i < count_of_students; i++)
    {
        if (strcmp(array_of_students[i].group_student, buffer) == 0)
        {
            if (flag == 0)
            {
                print_table_header();
            }
            print_student(array_of_students, i);
            flag = 1;
        }
    }

    return flag;
}

int find_student_by_surname(Student *array_of_students,
                            int count_of_students,
                            char *buffer)
{
    if (array_of_students == NULL || buffer == NULL || count_of_students < 1)
    {
        return 0;
    }
    int flag = 0;
    for (int i = 0; i < count_of_students; i++)
    {
        if (strcmp(array_of_students[i].surname_student, buffer) == 0)
        {
            if (flag == 0)
            {
                print_table_header();
            }
            print_student(array_of_students, i);
            flag = 1;
        }
    }
    return flag;
}

int find_student_by_id(Student *array_of_students,
                       int count_of_students,
                       unsigned int id_for_search)
{
    if (array_of_students == NULL || id_for_search < 1 || count_of_students < 1)
    {
        return 0;
    }
    int flag = 0;
    for (int i = 0; i < count_of_students; i++)
    {
        if (array_of_students[i].id_student == id_for_search)
        {
            if (flag == 0)
            {
                print_table_header();
            }
            print_student(array_of_students, i);
            flag = 1;
            break;
        }
    }

    return flag;
}

int find_index_in_array_by_id(Student *array_of_students,
                              int count_of_students,
                              unsigned int id_for_search)
{
    if (array_of_students == NULL || id_for_search < 1 || count_of_students < 1)
    {
        return -1;
    }
    for (int i = 0; i < count_of_students; i++)
    {
        if (array_of_students[i].id_student == id_for_search)
        {
            return i;
        }
    }

    return -1;
}
