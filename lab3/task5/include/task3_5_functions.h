#ifndef __task3_5_functions_H__
#define __task3_5_functions_H__

#include "../../../include/DEFAULT_FUNCTIONS.h"
#define SIZE_STRING 128 // Врятли в мире у кого-то ФИО длиньше 128
#define MARK_SIZE 10

typedef struct
{
    unsigned int id_student;
    char name_student[SIZE_STRING];
    char surname_student[SIZE_STRING];
    char group_student[SIZE_STRING];

    unsigned char *array_of_exam_marks;
    int array_size;

} Student;

ERRORS_EXIT_CODES enter_data_from_file(FILE *file,
                                       Student **array_of_students,
                                       int *counter_of_students);
void UserInterfaceTable();

ERRORS_EXIT_CODES load_average_all_to_file(Student *array_of_students,
                                           int counter_of_students,
                                           FILE *file_out);

ERRORS_EXIT_CODES print_student_in_file_by_id(Student *array_of_students,
                                              int found,
                                              FILE *file_out,
                                              double average_grade);

int find_student_by_name(Student *array_of_students,
                         int count_of_students,
                         char *buffer);
int find_student_by_group(Student *array_of_students,
                          int count_of_students,
                          char *buffer);

int find_student_by_surname(Student *array_of_students,
                            int count_of_students,
                            char *buffer);

int find_student_by_id(Student *array_of_students,
                       int count_of_students,
                       unsigned int id_for_search);

int compare_students_by_group(const void *a,
                              const void *b);
int compare_students_by_id(const void *a,
                           const void *b);
int compare_students_by_surname(const void *a,
                                const void *b);

int compare_students_by_name(const void *a,
                             const void *b);

double calculate_average_grade(Student *one_student);
ERRORS_EXIT_CODES print_students_from_array(Student *array_of_students, int counter_of_students);
void print_table_header();

ERRORS_EXIT_CODES print_student(Student *array_of_students, int i);

int find_index_in_array_by_id(Student *array_of_students,
                              int count_of_students,
                              unsigned int id_for_search);
#endif // __task3_5_functions_H__