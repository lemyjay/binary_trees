#include "binary_trees.h"

/**
 * BT_is_full - A function tha checks if a binary tree is full.
 *
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int BT_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* If the node has no children, it's a leaf and the tree is full */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* If the node has two children, check if both subtrees are full */
	if (tree->left && tree->right)
		return (
				BT_is_full(tree->left) && BT_is_full(tree->right)
				);

	/* If the node has only one child, the tree is not full */
	return (0);
}

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
 * BT_size - A function that measures the size of a binary tree
 *
 * @tree: A pointer to the root node of the tree to measure the size
 *
 * Return: Size of the binary tree or 0 if trees is NULL
 */
size_t BT_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + BT_size(tree->left) + BT_size(tree->right));
}

/**
 * binary_tree_is_perfect_ - A function that checks if a binary tree is perfect.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect_(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = BT_height(tree->left);
	right_height = BT_height(tree->right);

	/* If the tree is full and the left and right subtrees have the same height */
	return (BT_is_full(tree) && left_height == right_height);
}


/**
 * binary_tree_is_perfect - A function that checks if a binary tree is perfect.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    int left_height, right_height, num_nodes;

    if (tree == NULL)
        return (0);

    left_height = BT_height(tree->left);
    right_height = BT_height(tree->right);

    /* Check if the tree is full and the left and right subtrees have the same height */
    if (!BT_is_full(tree) || left_height != right_height)
        return (0);

    /* Calculate the number of nodes */
    num_nodes = (1 << (left_height + 1)) - 1;

    /* Check if the number of nodes meets the perfect binary tree condition */
    return (num_nodes == (int)BT_size(tree));
}
