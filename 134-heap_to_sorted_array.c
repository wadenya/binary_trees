#include "binary_trees.h"

/**
 * tree_size - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t height_lft = 0;
	size_t height_rght = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_lft = 1 + tree_size(tree->left);

	if (tree->right)
		height_rght = 1 + tree_size(tree->right);

	return (height_lft + height_rght);
}

/**
 * heap_to_sorted_array - converts Binary Max Heap to sorted array of ints
 * @heap: a pointer to the root node of the heap to convert
 * @size: an address to store the size of the array
 * Return: the generated array, NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int y, *d = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	d = malloc(sizeof(int) * (*size));

	if (!d)
		return (NULL);

	for (y = 0; heap; y++)
		d[y] = heap_extract(&heap);

	return (d);
}
