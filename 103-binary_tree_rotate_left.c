#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp, *rotl;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	rotl = tree->right;
	tmp = rotl->left;
	rotl->left = tree;
	tree->right = tmp;
	if (tmp != NULL)
	{
		tmp->parent = tree;
	}
	tmp = tree->parent;
	tree->parent = rotl;
	rotl->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->left == tree)
		{
			tmp->left = rotl;
		}
		else
		{
			tmp->right = rotl;
		}
	}
	return (rotl);
}
