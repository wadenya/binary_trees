#include "binary_trees.h"

/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: the Height or 0 if tree is NULL
 */
size_t tree_height(const heap_t *tree)
{
	size_t height_lft = 0;
	size_t height_rght = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		height_lft = 1 + tree_height(tree->left);

	if (tree->right)
		height_rght = 1 + tree_height(tree->right);

	if (height_lft > height_rght)
		return (height_lft);
	return (height_rght);
}
/**
 * tree_size_h - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size_h(const binary_tree_t *tree)
{
	size_t height_lft = 0;
	size_t height_rght = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		height_lft = 1 + tree_size_h(tree->left);

	if (tree->right)
		height_rght = 1 + tree_size_h(tree->right);

	return (height_lft + height_rght);
}

/**
 * pre_order - goes through a binary tree using pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @node: will be last node in traverse
 * @height: height of tree
 * Return: Null
 */
void pre_order(heap_t *tree, heap_t **node, size_t height)
{
	if (tree == NULL)
		return;

	if (!height)
		*node = tree;
	height--;

	pre_order(tree->left, node, height);
	pre_order(tree->right, node, height);
}

/**
 * heapify - heapifies max binary heap
 * @root: pointer to binary heap
 * @Return: No return
 */
void heapify(heap_t *root)
{
	int val;

	heap_t *tmp1, *tmp2;

	if (root == NULL)
		return;

	tmp1 = root;

	while (1)
	{
		if (!tmp1->left)
			break;

		if (!tmp1->right)
			tmp2 = tmp1->left;

		else
		{
			if (tmp1->left->n > tmp1->right->n)
				tmp2 = tmp1->left;
			else
				tmp2 = tmp1->right;
		}
		if (tmp1->n > tmp2->n)
			break;

		val = tmp1->n;
		tmp1->n = tmp2->n;
		tmp2->n = val;
		tmp1 = tmp2;
	}
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: a double pointer to the root node of heap
 * Return: the value stored in the root node 0 on failure
 */
int heap_extract(heap_t **root)
{
	int val;
	heap_t *heap_r, *node;

	if (!root || !*root)
		return (0);
	heap_r = *root;
	val = heap_r->n;
	if (!heap_r->left && !heap_r->right)
	{
		*root = NULL;
		free(heap_r);
		return (val);
	}

	pre_order(heap_r, &node, tree_height(heap_r));

	heap_r->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(heap_r);
	*root = heap_r;
	return (val);
}
