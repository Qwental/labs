#include "../../include/DEFAULT_FUNCTIONS.h"
#include "include/task3_10_functions.h"

int main(int args, char *argv[])
{
    if (args != 3)
    {
        return print_Errors(E_INVALID_INPUT);
    }
    ERRORS_EXIT_CODES error = E_SUCCESS;
    FILE *input_file = NULL;
    FILE *output_file = NULL;
    char input_buffer[MY_BUFFER];

    if (argv == NULL || argv[1] == NULL || argv[2] == NULL)
    {
        return print_Errors(E_DEREFENCE_NULL_POINTER);
    }

    if ((error = cheak_files(argv[1], argv[2])) != E_SUCCESS)
    {
        return print_Errors(error);
    }

    input_file = fopen(argv[1], "r");
    if (!input_file)
    {
        return print_Errors(E_CANNOT_OPEN_FILE);
    }
    output_file = fopen(argv[2], "w");
    if (!output_file)
    {
        fclose(input_file);
        return print_Errors(E_CANNOT_OPEN_FILE);
    }

    while (fgets(input_buffer, MY_BUFFER, input_file) != NULL)
    {
        error = print_tree_to_file(input_buffer, output_file);
        if (error != E_SUCCESS)
        {
            break;
        }
    }

    fclose(input_file);
    fclose(output_file);
    

    return print_Errors(error);
}