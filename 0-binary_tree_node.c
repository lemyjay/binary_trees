#include "binary_trees.h"

/**
 * binary_tree_node - A function that creates a binary tree node
 * 
 * @parent: The pointer to the parent node of the node to create
 * @value: The value to put in the new node
 * 
 * Return: A pointer to the node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new;

    if (parent == NULL)
        return;
    new = malloc(sizeof(binary_tree_t))
    if (new == NULL)
        return;
    new->parent = parent;
    new->n = value;
}