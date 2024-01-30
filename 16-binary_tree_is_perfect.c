#include "binary_trees.h"

/**
 * binary_tree_is_perfect - A function that checks if a binary tree is perfect.
 * 
 * @tree: A pointer to the root node of the tree to check.
 * 
 * Return: 1 if tree is perfect, 0 otherwise. 
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    /* If the tree is full and the left and right subtrees have the same height */
    return (binary_tree_is_full(tree) && left_height == right_height);
}