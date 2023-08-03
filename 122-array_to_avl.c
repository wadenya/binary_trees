#include "binary_trees.h"

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
