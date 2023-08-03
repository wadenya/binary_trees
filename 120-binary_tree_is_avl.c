#include "binary_trees.h"

/**
 * binary_tree_is_avl - checks if a binary tree is an avl
 * @tree: pointer to the root node of the tree tp check
 * Return: 1 if tree is avl, 0 otherwise, NULL return 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (btia_hlp(tree, INT_MIN, INT_MAX));
}

/**
 * btia_hlp - help that finds if a binary tree is an avl
 * @tree: pointer to the root node of the tree to check
 * @min: minimum value
 * @max: maximum value
 * Return: 1 if tree is avl, 0 otherwise, NULL return 0
 */
int btia_hlp(const binary_tree_t *tree, int min, int max)
{
	int lft_path, rght_path;

	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	lft_path = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	rght_path = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (abs(lft_path - rght_path) > 1)
		return (0);

	return (btia_hlp(tree->left, min, tree->n - 1) &&
		btia_hlp(tree->right, tree->n + 1, max));

}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to measure the height of
 * Return: height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_lft = 0;
	size_t height_rght = 0;

	if (tree == NULL)
		return (0);

	height_lft = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_rght = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_lft > height_rght ? height_lft : height_rght);
}
