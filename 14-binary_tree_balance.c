#include "binary_trees.h"

/**
 * BT_height - A function that measures the height of a binary tree
 *
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: Height of the binary tree or 0 if tree is NULL.
 */
size_t BT_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = tree->left ? 1 + BT_height(tree->left) : 0;
	right_height = tree->right ? 1 + BT_height(tree->right) : 0;

	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_balance - A function that measures the balance
 * factor of a binary tree
 *
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: Balance factor or 0 if tree is NULL
 * A NULL pointer is not a node
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = tree->left ? (int)BT_height(tree->left) : -1;
	right_height = tree->right ? (int)BT_height(tree->right) : -1;

	return (left_height - right_height);
}
