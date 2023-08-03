#include "binary_trees.h"

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is valid Max Binary Heap 0 if tree is NULL, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (btih_hlp(tree));
}

/**
 * btih_hlp - checks if a binary tree is a valid Max Binary Heap
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is valid Max Binary Heap, 1 if tree is NULL, 0 otherwise
 */
int btih_hlp(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (!binary_tree_is_complete(tree))
		return (0);

	if (tree->left)
		if (tree->left->n > tree->n)
			return (0);

	if (tree->right)
		if (tree->right->n > tree->n)
			return (0);

	return (btih_hlp(tree->left) &&
		btih_hlp(tree->right));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root node of tree to check
 * Return: 1 if tree is complete, 0 if tree is incomplete, 0 if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
		return (0);

	size = binary_tree_size(tree);

	return (btic_hlp(tree, 0, size));
}

/**
 * btic_hlp - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * @index: the node index to check
 * @size: the number of nodes in the tree
 * Return: 1 if tree is complete, 0 if tree is incomplete, 0 if tree is NULL
 */
int btic_hlp(const binary_tree_t *tree, size_t index, size_t size)
{
	if (tree == NULL)
		return (1);

	if (index >= size)
		return (0);

	return (btic_hlp(tree->left, 2 * index + 1, size) &&
		btic_hlp(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - it measures the size of a binary tree
 * @tree: tree to measure the size
 * Return: size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
