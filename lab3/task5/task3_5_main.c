

#include "../../include/DEFAULT_FUNCTIONS.h"
#include "include/task3_5_functions.h"
/*


valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all ./task3_5.out /home/qwental/workspace/fund_algos/labs/lab3/task5/src/input.txt /home/qwental/workspace/fund_algos/labs/lab3/task5/src/logger.txt < conveer_task3_5.txt


*/

int main(int argc,
         char *argv[])

{
    FILE *file = NULL;
    FILE *file_output = NULL;

    ERRORS_EXIT_CODES error = E_SUCCESS;

    int counter_of_students = 0;
    Student *array_of_students = NULL;

    if (argc < 3 || argv == NULL)
    {
        return print_Errors(E_INVALID_ARG);
    }

    error = cheak_files(argv[1], argv[2]);
    if (error != E_SUCCESS)
    {
        return print_Errors(error);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        return print_Errors(E_CANNOT_OPEN_FILE);
    }

    file_output = fopen(argv[2], "a+"); // типо файл трассировачный все дела
    if (file_output == NULL)
    {
        fclose(file);
        return print_Errors(E_CANNOT_OPEN_FILE);
    }

    error = enter_data_from_file(file, &array_of_students, &counter_of_students);
    if (error != E_SUCCESS)
    {
        fclose(file_output);
        return print_Errors(error); // в enter_data_from_file все чиститься
    }

    int action = 0;
    int id_found = -1;
    int id_to_find = 0;
    float average_marks = 0.0;
    char buffer[SIZE_STRING];

    /* интерактивчик */
    while (1)
    {
        UserInterfaceTable();
        id_found = -1;
        id_to_find = 0;
        average_marks = 0.0;
        buffer[0] = '\0';

        printf("Выберете действие: ");
        if (scanf("%d", &action) != 1)
        {
            error = E_INVALID_INPUT;
            break;
        }

        if (action < 0 || action > 10)
        {
            error = E_INVALID_INPUT;
            break;
        }
        if (action == 1)
        {
            printf("Введено действие = %d\n", action);
            printf("Введите ID студента \n");

            if (scanf("%d", &id_to_find) != 1)
            {
                error = E_INVALID_INPUT;
                break;
            }
            if (find_student_by_id(array_of_students, counter_of_students, id_to_find) == 0)
            {
                printf("Студента с таким ID нет!\n");
            }
        }
        else if (action == 2)
        {
            printf("Введено действие = %d\n", action);

            printf("Введите фамилию студента \n"); // validate
            if (scanf("%128s", buffer) != 1)
            {
                error = E_INVALID_INPUT;
                break;
            }
            if (find_student_by_surname(array_of_students, counter_of_students, buffer) == 0)
            {
                printf("Студентов с такой фамилией нет!\n");
            }
        }
        else if (action == 3)
        {
            printf("Введено действие = %d\n", action);

            printf("Введите имя студента \n");
            if (scanf("%128s", buffer) != 1)
            {
                error = E_INVALID_INPUT;
                break;
            }
            if (find_student_by_name(array_of_students, counter_of_students, buffer) == 0)
            {
                printf("Студентов с такой именем нет!\n");
            }
        }
        else if (action == 4)
        {
            printf("Введено действие = %d\n", action);

            printf("Введите группу студента \n");
            if (scanf("%128s", buffer) != 1)
            {
                error = E_INVALID_INPUT;
                break;
            }
            if (find_student_by_group(array_of_students, counter_of_students, buffer) == 0)
            {
                printf("Студентов с такой группой нет!\n");
            }
        }

        else if (action == 5)
        {
            printf("Введено действие = %d\n", action);

            qsort(array_of_students, counter_of_students, sizeof(Student), compare_students_by_id);
            printf("Отсортированно по ID \n");
            error = print_students_from_array(array_of_students, counter_of_students);
            if (error != E_SUCCESS)
            {
                break;
            }
        }
        else if (action == 6)
        {
            printf("Введено действие = %d\n", action);

            qsort(array_of_students, counter_of_students, sizeof(Student), compare_students_by_surname);
            printf("Отсортированно по фамилиям \n");
            error = print_students_from_array(array_of_students, counter_of_students);
            if (error != E_SUCCESS)
            {
                break;
            }
        }
        else if (action == 7)
        {
            printf("Введено действие = %d\n", action);

            qsort(array_of_students, counter_of_students, sizeof(Student), compare_students_by_name);
            printf("Отсортированно по именам \n");
            error = print_students_from_array(array_of_students, counter_of_students);
            if (error != E_SUCCESS)
            {
                break;
            }
        }
        else if (action == 8)
        {
            printf("Введено действие = %d\n", action);

            qsort(array_of_students, counter_of_students, sizeof(Student), compare_students_by_group);
            printf("Отсортированно по группам \n");
            error = print_students_from_array(array_of_students, counter_of_students);
            if (error != E_SUCCESS)
            {
                break;
            }
        }

        else if (action == 9)
        {
            printf("Введено действие = %d\n", action);

            printf("Введите ID студента \n");

            if (scanf("%d", &id_to_find) != 1)
            {
                error = E_INVALID_INPUT;
                break;
            }
            if ((id_found = find_index_in_array_by_id(array_of_students, counter_of_students, id_to_find)) == -1)
            {
                printf("Студента с таким ID нет!\n");
                continue;
            }

            average_marks = calculate_average_grade(&array_of_students[id_found]);

            error = print_student_in_file_by_id(array_of_students, id_found, file_output, average_marks);

            if (error != E_SUCCESS)
            {
                print_Errors(error);
                break;
            }
        }
        else if (action == 10)
        {
            printf("Введено действие = %d\n", action);

            if ((error = load_average_all_to_file(array_of_students, counter_of_students, file_output)) != E_SUCCESS)
            {
                error = E_CANNOT_OPEN_FILE;
                break;
            }
            else
            {
                printf("Информация записана в файл\n");
            }
        }

        else if (action == 0)
        {
            printf("Введено действие = %d\n", action);
            printf("Конец работы программы\n");
            error = E_SUCCESS;
            break;
        }
    }

    // чистим

    fclose(file_output);

    for (int i = 0; i < counter_of_students; i++)
    {
        free(array_of_students[i].array_of_exam_marks);
    }
    free(array_of_students);

    return print_Errors(error);
}

// TODO , тесты, оси, 3.10