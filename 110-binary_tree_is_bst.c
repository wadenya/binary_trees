#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (btib_hlp(tree, INT_MIN, INT_MAX));
}

/**
 * btib_hlp - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 * @min: Lower bound of checked nored
 * @max: Upper bound of checked nodes
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int btib_hlp(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (btib_hlp(tree->left, min, tree->n - 1) &&
		btib_hlp(tree->right, tree->n + 1, max));
}
