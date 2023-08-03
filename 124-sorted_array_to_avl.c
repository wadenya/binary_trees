#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: number of elements in the array
 * Return: pointer to root node of the created AVL tree NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t mid;

	if (array == NULL)
		return (NULL);

	mid = (size - 1) / 2;
	tree = binary_tree_node(NULL, array[mid]);

	sata_hlp(&tree, array, -1, mid);
	sata_hlp(&tree, array, mid, size);

	return (tree);
}

/**
 * sata_hlp - help that builds an AVL tree from an array
 * @root: double pointer to the root node of the subtree
 * @array: pointer to the first element of the array to be converted
 * @lo: lower bound index
 * @up: upper bound index
 */
void sata_hlp(avl_t **root, int *array, size_t lo, size_t up)
{
	avl_t *new = NULL;
	size_t mid;

	if (up - lo > 1)
	{
		mid = (up - lo) / 2 + lo;
		new = binary_tree_node(*root, array[mid]);
		if (array[mid] > (*root)->n)
			(*root)->right = new;
		else if (array[mid] < (*root)->n)
			(*root)->left = new;
		sata_hlp(&new, array, lo, mid);
		sata_hlp(&new, array, mid, up);
	}
}
