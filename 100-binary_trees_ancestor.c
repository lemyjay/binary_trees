#include "binary_trees.h"

/**
 * binary_trees_ancestor - A function that finds the lowest common ancestor of two nodes
 * 
 * @first: A pointer to the first node
 * @second: A pointer to the second node
 * 
 * Return: A pointer to the lowest common ancestor node, or NULL if no common ancestor was found 
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    if (first == NULL || second == NULL)
        return (NULL);
    
    if (first->parent == second->parent)
        return ((binary_tree_t *)first->parent);
    else if (first->parent == second)
        return ((binary_tree_t *)second);
    else if (second->parent == first)
        return ((binary_tree_t *)first);
    else
        binary_trees_ancestor(first->parent, second->parent);
    
    return (NULL);
}