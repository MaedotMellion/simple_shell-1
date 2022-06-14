#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "shell.h"
#include "node.h"
#include "parser.h"


/**
 * new_node - returns the factorial of a given number
 * @type: takes in the type of node
 * Return: returns a struct node_s
 */

struct node_s *new_node(enum node_type_e type)
{
        struct node_s *node = malloc(sizeof(struct node_s));

        if (!node)
        {
            return NULL;
        }
        memset(node, 0, sizeof(struct node_s));
        node->type = type;

        return (node);
}

/**
 * add_child_node - expands the AST of a simple command by adding
 *                  a new child node and incrementing the root
 *                  node's children field.
 * @parent: takes in the parent node
 * @child: takes in the child node
 * Return: returns nothing
 */

void add_child_node(struct node_s *parent, struct node_s *child)
{
        struct node_s *sibling;

        if (!parent || !child)
        {
            return;
        }

        if (!parent->first_child)
        {
            parent->first_child = child;
        }
        else
        {
            sibling = parent->first_child;

    	    while (sibling->next_sibling)
            {
                sibling = sibling->next_sibling;
            }
    	    sibling->next_sibling = child;
            child->prev_sibling = sibling;
        }
        parent->children++;
}

/**
 * set_node_val_str - sets a node's value to the given string
 * @node: takes in a node
 * @val: takes in a node value
 * Return: returns nothing
 */

void set_node_val_str(struct node_s *node, char *val)
{
        char *val2;
        node->val_type = VAL_STR;

        if (!val)
        {
            node->val.str = NULL;
        }
        else
        {
            val2 = malloc(strlen(val)+1);
    	    if (!val2)
            {
                node->val.str = NULL;
            }
            else
            {
                _strcpy(val2, val);
                node->val.str = val2;
            }
        }
}

/**
 * free_node_tree - frees the memory used by a node structure
 * @node: takes in a node
 * Return: returns nothing
 */

void free_node_tree(struct node_s *node)
{
        struct node_s *child, *next;

        if (!node)
        {
            return;
        }

        child = node->first_child;
        while (child)
        {
            next = child->next_sibling;
            free_node_tree(child);
            child = next;
        }
        if (node->val_type == VAL_STR)
        {
            if(node->val.str)
            {
                free(node->val.str);
            }
        }
        free(node);
}
