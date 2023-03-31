#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree.
 * @tree: pointer to the root node of the tree to rotate.
 * Return: pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmp, *rotr;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}

	rotr = tree->left;
	tmp = rotr->right;
	rotr->right = tree;
	tree->left = tmp;
	if (tmp != NULL)
	{	
		tmp->parent = tree;
	}

	tmp = tree->parent;
	tree->parent = rotr;
	rotr->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->left == tree)
			tmp->left = rotr;
		else
			tmp->right = rotr;
	}

	return (rotr);
}
