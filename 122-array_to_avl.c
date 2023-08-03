#include "binary_trees.h"

/**
 * avl_insert - inserts a value into an AVL tree.
 * @tree: type **pointer to the root node of the AVL tree to insert into.
 * @value: value to store in the node to be inserted
 * Return: inserted node, or NULL if fails.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	r_insert_node(tree, *tree, &new, value);
	return (new);
}

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: pointer to first element array to be converted
 * @size: number of elements in the array
 * Return: pointer to root node of created AVL tree NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t p;

	for (p = 0; p < size; p++)
		avl_insert(&tree, array[p]);

	return (tree);
}
