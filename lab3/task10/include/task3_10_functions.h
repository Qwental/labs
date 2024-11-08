#ifndef __task3_10_functions_H__
#define __task3_10_functions_H__

#include "../../../include/DEFAULT_FUNCTIONS.h"

typedef struct Node
{
    struct Node *Parent;
    struct Node *FirstChild;
    struct Node *NextSibling;
    char data;

} Node;

ERRORS_EXIT_CODES add_FirstChild(Node *parent, char data);
ERRORS_EXIT_CODES add_NextSibling(Node *node, char data);
ERRORS_EXIT_CODES print_tree_to_file(char *expression, FILE *file);

#endif // __task3_10_functions_H__
