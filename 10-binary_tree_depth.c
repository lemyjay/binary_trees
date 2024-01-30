#include "binary_trees.h"

/**
 * binary_tree_depth - A function that measures the depth of a node in a
 * binary tree
 *
 * @tree: A pointer to the node to measure the depth
 *
 * Return: Depth of the binary tree or 0 if trees is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (left_height > right_height ? left_height : right_height);
}
