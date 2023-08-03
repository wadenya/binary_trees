#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return: pointer to the lowest common ancestor node
 *         or NULL if there is no common ancestor node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t first_dpth, second_dpth;

	if (first == NULL || second == NULL)
		return (NULL);

	first_dpth = binary_tree_depth(first);
	second_dpth = binary_tree_depth(second);

	while (first_dpth > second_dpth)
	{
		first = first->parent;
		first_dpth--;
	}
	while (second_dpth > first_dpth)
	{
		second = second->parent;
		second_dpth--;
	}
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: node to calculate the depth
 * Return: depth of the node or 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}
