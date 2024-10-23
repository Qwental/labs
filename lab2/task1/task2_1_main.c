#include "../../include/DEFAULT_FUNCTIONS.h"
#include "include/task2_1_functions.h"

int main(int args, char *argv[])
{
    if (args < 3)
        return print_Errors(E_INVALID_ARG);
    if ((argv[1][0] != '-') || (argv[1][2] != '\0'))
        return print_Errors(E_INVALID_FLAG_ARG);

    ERRORS_EXIT_CODES error = E_SUCCESS;

    switch (argv[1][1])
    {
    case 'l':
        if (args != 3)
        {
            return print_Errors(E_INVALID_ARG);
        }
        size_t lenght = 0;
        error = len_string(argv[2], &lenght);
        if (error != E_SUCCESS)
            return print_Errors(error);

        printf("Длина введенной строки = %zu\n", lenght);
        break;

    case 'r':
        if (args != 3)
        {
            return print_Errors(E_INVALID_ARG);
        }
        char *string_r = NULL;

        error = reverse_string(argv[2], &string_r);
        if (error != E_SUCCESS)
            return print_Errors(error);

        printf("Перевернутая <строка>: <%s>\n", string_r);
        free(string_r);
        break;

    case 'u':
        char *string_u = NULL;

        error = string_every_odd_one_to_uppercase(argv[2], &string_u);
        if (error != E_SUCCESS)
            return print_Errors(error);
        printf("Результат работы флага u <строка>: <%s>\n", string_u);
        free(string_u);
        break;
    case 'n':
        if (args != 3)
        {
            return print_Errors(E_INVALID_ARG);
        }
        char *string_n = NULL;

        error = flag_n_string(argv[2], &string_n);
        if (error != E_SUCCESS)
            return print_Errors(error);

        printf("Результат работы флага n <строка>: <%s>\n", string_n); // puts(string_n);
        free(string_n);
        break;

    case 'c':

        if (args <= 3)
        {
            return print_Errors(E_INVALID_ARG);
        }

        size_t seed;
        error = string_to_unsigned_long_int(argv[3], &seed); // треться строка <str1 == flag > <str2> <str3==seed> <str4> <...>
        if ((error != E_SUCCESS) || seed == 0)
            return print_Errors(error);
        printf("seed = %zu\n", seed);
        size_t number_strings = args - 3;

        srand(seed);
        char **strings = (char **)malloc(sizeof(char *) * number_strings);
        if (strings == NULL)
        {
            return print_Errors(E_MEMORY_ALLOCATION);
        }

        strings[0] = argv[2];
        // puts(argv[2]);

        for (size_t i = 1; i < number_strings; i++)
        {
            strings[i] = argv[i + 3];
            // puts(argv[3 + i]);
        }

        char *string_c = NULL;

        error = flag_c_string(strings, (int)number_strings, &string_c);
        printf("Результат работы флага c <строка>: <%s>\n", string_c);
        free(string_c);
        free(strings);
        break;

    default:
        return print_Errors(E_INVALID_ARG);
    }

    return E_SUCCESS;
}