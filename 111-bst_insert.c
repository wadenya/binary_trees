#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node, NULL if it fails
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *tmp = NULL;
	bst_t *new = NULL;
	bst_t *sec = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	tmp = *tree;
	while (tmp)
	{
		sec = tmp;
		if (value < tmp->n)
			tmp = tmp->left;
		else if (value > tmp->n)
			tmp = tmp->right;
		else if (value == tmp->n)
			return (NULL);
	}

	new = binary_tree_node(NULL, value);
	if (sec == NULL)
		sec = new;
	else if (value < sec->n)
	{
		sec->left = new;
		new->parent = sec;
	}
	else
	{
		sec->right = new;
		new->parent = sec;
	}

	return (new);
}
