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

void create_node(Node *New_Node, char data)
{
    New_Node->Parent = NULL;
    New_Node->FirstChild = NULL;
    New_Node->NextSibling = NULL;
    New_Node->data = data;
}

ERRORS_EXIT_CODES add_FirstChild(Node *parent, char data)
{
    if (parent == NULL)
    {
        return E_DEREFENCE_NULL_POINTER;
    }
    Node *child;
    Node *current;

    child = malloc(sizeof(Node));
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
        current = parent->FirstChild;

        while (current->NextSibling != NULL)
        {
            current = current->NextSibling;
        }
        current->NextSibling = child;
    }
    return E_SUCCESS;
}

ERRORS_EXIT_CODES add_NextSibling(Node *node, char data)
{
    if (node == NULL)
    {
        return E_DEREFENCE_NULL_POINTER;
    }
    Node *sibling;
    Node *current;

    sibling = malloc(sizeof(Node));
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
        current = node->NextSibling;
        while (current->NextSibling != NULL)
        {
            current = current->NextSibling;
        }
        current->NextSibling = sibling;
    }
    return E_SUCCESS;
}

/* Рекурсивный вывод дерева */
void print_tree(Node *Root_Node, const int level, FILE *output_file)
{
    if (Root_Node == NULL)
    {
        return;
    }

    for (int i = 1; i <= level; i++)
    {
        if (level == i)
        {
            fprintf(output_file, "└───");
            break;
        }
        fprintf(output_file, "\t");
    }
    fprintf(output_file, "%c\n", Root_Node->data);

    print_tree(Root_Node->FirstChild, level + 1, output_file);
    print_tree(Root_Node->NextSibling, level, output_file);
}

ERRORS_EXIT_CODES print_tree_to_file(char *str_Expression, FILE *output_file)
{
    if (str_Expression == NULL || output_file == NULL)
    {
        return E_DEREFENCE_NULL_POINTER;
    }
    ERRORS_EXIT_CODES error;

    Node *root = malloc(sizeof(Node));
    if (root == NULL)
    {
        return E_MEMORY_ALLOCATION;
    }

    create_node(root, *str_Expression); // первая буква - корень

    Node *current = root;
    str_Expression++;

    while (*str_Expression != '\0')
    {
        if (*str_Expression == '(')
        {
            str_Expression++;

            Node *New_Node = malloc(sizeof(Node));
            if (New_Node == NULL)
            {
                delete_tree(root);
                return E_MEMORY_ALLOCATION;
            }
            create_node(New_Node, *str_Expression);

            if (root == NULL)
            {
                root = New_Node;
                current = New_Node;
            }
            else
            {
                error = add_FirstChild(current, *str_Expression);
                if (error != E_SUCCESS)
                {
                    delete_tree(root);
                    free(New_Node);
                    return error;
                }
                current = current->FirstChild;
            }
            free(New_Node);
        }
        else if (*str_Expression == ',')
        {
            str_Expression++;
            
            error = add_NextSibling(current, *str_Expression);
            if (error != E_SUCCESS)
            {
                delete_tree(root);
                return error;
            }

            Node *temp = current;
            while (temp->NextSibling != NULL)
            {
                temp = temp->NextSibling;
            }
            current = temp;
        }
        else if (*str_Expression == ')')
        {
            current = current->Parent;
        }

        str_Expression++;
    }

    print_tree(root, 0, output_file);
    fprintf(output_file, "---> ---> ---> ---> ---> ---> ---> ---> \n");

    delete_tree(root);

    return E_SUCCESS;
}
