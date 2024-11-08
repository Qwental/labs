#include "../include/task3_10_functions.h"

/* Рекурсивная очистка дерева */
void delete_tree(Node *Root_Node)
{
    if (Root_Node->NextSibling != NULL)
    {
        delete_tree(Root_Node->NextSibling);
    }
    if (Root_Node->FirstChild != NULL)
    {
        delete_tree(Root_Node->FirstChild);
    }
    free(Root_Node);
}

void create_node(Node *New_Node, const char data)
{
    New_Node->Parent = NULL;
    New_Node->FirstChild = NULL;
    New_Node->NextSibling = NULL;
    New_Node->data = data;
}

ERRORS_EXIT_CODES add_FirstChild(Node *parent, const char data)
{
    if (parent == NULL)
    {
        return E_DEREFENCE_NULL_POINTER;
    }
    Node *child;
    Node *current_node;

    child = (Node *)malloc(sizeof(Node));
    if (child == NULL)
    {
        return E_MEMORY_ALLOCATION;
    }

    child->Parent = parent;
    child->NextSibling = NULL;
    child->FirstChild = NULL;
    child->data = data;

    if (parent->FirstChild == NULL)
    {
        parent->FirstChild = child;
    }
    else
    {
        current_node = parent->FirstChild;

        while (current_node->NextSibling != NULL)
        {
            current_node = current_node->NextSibling;
        }
        current_node->NextSibling = child;
    }
    return E_SUCCESS;
}

ERRORS_EXIT_CODES add_NextSibling(Node *node, const char data)
{
    if (node == NULL)
    {
        return E_DEREFENCE_NULL_POINTER;
    }
    Node *sibling;
    Node *current_node;

    sibling = (Node *)malloc(sizeof(Node));
    if (sibling == NULL)
    {
        return E_MEMORY_ALLOCATION;
    }

    sibling->data = data;
    sibling->Parent = node->Parent;
    sibling->FirstChild = NULL;
    sibling->NextSibling = NULL;

    if (node->NextSibling == NULL)
    {
        node->NextSibling = sibling;
    }
    else
    {
        current_node = node->NextSibling;
        while (current_node->NextSibling != NULL)
        {
            current_node = current_node->NextSibling;
        }
        current_node->NextSibling = sibling;
    }
    return E_SUCCESS;
}

/* Рекурсивный вывод дерева */
void print_tree(Node *Root_Node, const int height, FILE *output_file)
{
    if (Root_Node == NULL)
    {
        return;
    }
    int i;
    for (i = 1; i <= height; i++)
    {
        if (height == i)
        {
            fprintf(output_file, "└───");
            break;
        }
        fprintf(output_file, "\t");
    }
    fprintf(output_file, "%c\n", Root_Node->data);

    print_tree(Root_Node->FirstChild, height + 1, output_file);
    print_tree(Root_Node->NextSibling, height, output_file);
}

ERRORS_EXIT_CODES print_tree_to_file(const char *str_expression, FILE *output_file)
{
    if (str_expression == NULL || output_file == NULL)
    {
        return E_DEREFENCE_NULL_POINTER;
    }
    ERRORS_EXIT_CODES error;
    Node *current_node = NULL;
    Node *New_Node = NULL;
    Node *Temp_Node;
    Node *Root = (Node *)malloc(sizeof(Node));
    if (Root == NULL)
    {
        return E_MEMORY_ALLOCATION;
    }
    current_node = Root;

    create_node(Root, *str_expression); // первая буква - 1 корень
    str_expression++;
    while (*str_expression != '\0')
    {
        if (*str_expression == '(')
        {
            str_expression++;

            New_Node = (Node *)malloc(sizeof(Node));
            if (New_Node == NULL)
            {
                delete_tree(Root);
                return E_MEMORY_ALLOCATION;
            }
            create_node(New_Node, *str_expression);

            error = add_FirstChild(current_node, *str_expression);
            if (error != E_SUCCESS)
            {
                delete_tree(Root);
                free(New_Node);
                return error;
            }
            current_node = current_node->FirstChild;

            free(New_Node);
        }
        else if (*str_expression == ',')
        {
            str_expression++;

            error = add_NextSibling(current_node, *str_expression);
            if (error != E_SUCCESS)
            {
                delete_tree(Root);
                return error;
            }

            Temp_Node = current_node;
            while (Temp_Node->NextSibling != NULL)
            {
                Temp_Node = Temp_Node->NextSibling;
            }
            current_node = Temp_Node;
        }
        else if (*str_expression == ')')
        {
            current_node = current_node->Parent;
        }

        str_expression++;
    }

    print_tree(Root, 0, output_file);
    fprintf(output_file, "---> ---> ---> ---> ---> ---> ---> ---> \n");

    delete_tree(Root);

    return E_SUCCESS;
}
