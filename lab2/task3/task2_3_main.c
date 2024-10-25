#include "../../include/DEFAULT_FUNCTIONS.h"
#include "include/task2_3_functions.h"
int main()
{
    ERRORS_EXIT_CODES error;

    char *pattern1 = "ab\n\n\nab";
    int number_files = 2;
    error = search_pattern_in_files(pattern1, number_files, "/home/qwental/workspace/fund_algos/labs/lab2/task3/src/file1.txt", "/home/qwental/workspace/fund_algos/labs/lab2/task3/src/file2.txt");
    if (error != E_SUCCESS)
    {
        print_Errors(error);
    }

    char *pattern2 = "lol";
    number_files = 2;
    error = search_pattern_in_files(pattern2, number_files, "/home/qwental/workspace/fund_algos/labs/lab2/task3/src/file1.txt", "/home/qwental/workspace/fund_algos/labs/lab2/task3/src/file2.txt");
    if (error != E_SUCCESS)
    {
        print_Errors(error);
    }

    char *pattern3 = "meow";
    number_files = 2;
    error = search_pattern_in_files(pattern3, number_files, "/home/qwental/workspace/fund_algos/labs/lab2/task3/src/file1.txt", "/home/qwental/workspace/fund_algos/labs/lab2/task3/src/file2.txt");
    if (error != E_SUCCESS)
    {
        print_Errors(error);
    }

    char *pattern4 = "meow\nmeow";
    number_files = 2;
    error = search_pattern_in_files(pattern4, number_files, "/home/qwental/workspace/fund_algos/labs/lab2/task3/src/file1.txt", "/home/qwental/workspace/fund_algos/labs/lab2/task3/src/file2.txt");
    if (error != E_SUCCESS)
    {
        print_Errors(error);
    }

    // char *pattern = "ab\nab";
    // char *pattern = "meow";
    // char *pattern = "meow\nmeow";
    // char *pattern = "lol";

    return E_SUCCESS;
}
