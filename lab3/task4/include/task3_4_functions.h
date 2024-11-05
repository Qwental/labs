#ifndef __task3_4_functions_H__
#define __task3_4_functions_H__

#include "../../../include/DEFAULT_FUNCTIONS.h"


typedef struct my_string
{
    char *str;
    int length;
} String;

/* Создание Экземпляра типа String */
ERRORS_EXIT_CODES Create_String(char *str, String *created_string);

/* Удаление внутреннего содержимого экземпляра типа String*/
ERRORS_EXIT_CODES Clear_String(String *string);

/*Отношения порядка между двумя экземплярами типа String
Первичное по длине, Вторичное по лексографическому компаратору*/
ERRORS_EXIT_CODES Compare_Strings(String *string1, String *string2, String (*cmp)(String *str1, String *str2));
//TODO cmp
/* Отношения эквивалентности между двумя экземплярами типа String
(лексографический компаратор)*/
ERRORS_EXIT_CODES Are_Strings_Equal(String *string1, String *string2);



#endif // __task3_4_functions_H__