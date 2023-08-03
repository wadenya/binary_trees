#include "binary_trees.h"

/**
 * balnc - Measures balance factor of a AVL
 * @tree: tree to go through
 * Return: the balanced factor
 */
void balnc(avl_t **tree)
{
	int bnval;

	if (tree == NULL || *tree == NULL)
		return;

	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;

	balnc(&(*tree)->left);
	balnc(&(*tree)->right);
	bnval = binary_tree_balance((const binary_tree_t *)*tree);

	if (bnval > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bnval < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * scsor - get the next successor, meaning the min node in the right subtree
 * @node: the tree to check
 * Return: the min value of the tree
 */
int scsor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = scsor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}
/**
 *remove_type - its function that removes a node depending on its children
 *@root: is the node to remove
 *Return: 0 if it has no children or other value if there
 */
int remove_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}

	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = scsor(root->right);
		root->n = new_value;
		return (new_value);
	}
}
/**
 * bst_remove - remove a node from a BST tree
 * @root: root of the tree
 * @value: node with value to remove
 * Return: the  changed tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - removes a node from a AVL tree
 * @root: pointer to root of the tree
 * @value: node with this value to remove
 * Return: NULL if nothing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	balnc(&root_a);
	return (root_a);
}
