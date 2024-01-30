#include "binary_trees.h"

/**
 * binary_tree_height - A function that measures the height of a binary tree
 *
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: Height of the binary tree or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent != NULL)
    {
        tree = tree->parent;
        depth++;
    }

	return (depth);
}
