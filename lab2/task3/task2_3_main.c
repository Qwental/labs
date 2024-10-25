#include "../../include/DEFAULT_FUNCTIONS.h"
#include "include/task2_3_functions.h"
int main()
{
    ERRORS_EXIT_CODES error;
    // char *pattern = "a\ta\ta";



    //char *pattern = "ab\nab";
    //char *pattern = "qwer";
    //char *pattern = "lol";
    //  char *pattern = "ab\n\n\nab";
    int number_files = 2;

    

    error = search_pattern_in_files(pattern, number_files, "/home/qwental/workspace/fund_algos/labs/lab2/task3/src/file1.txt", "/home/qwental/workspace/fund_algos/labs/lab2/task3/src/file2.txt");
    if (error != E_SUCCESS)
    {
        print_Errors(error);
    }
    return E_SUCCESS;
}
