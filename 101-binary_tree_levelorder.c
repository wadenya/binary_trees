#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t maxlvl, lvl;

	if (!tree || !func)
		return;

	maxlvl = binary_tree_height(tree) + 1;

	for (lvl = 1; lvl <= maxlvl; lvl++)
		btlo_hlp(tree, func, lvl);
}

/**
 * btlo_hlp - goes through a binary tree using post-order traverse
 * @tree: tree to traverse
 * @func: pointer to a function to call for each node
 * @level: the level of tree to call func upon
 */
void btlo_hlp(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 1)
		func(tree->n);
	else
	{
		btlo_hlp(tree->left, func, level - 1);
		btlo_hlp(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to measure the height
 * Return: height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_lft = 0;
	size_t height_rght = 0;

	if (!tree)
		return (0);

	height_lft = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_rght = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_lft > height_rght ? height_lft : height_rght);
}
