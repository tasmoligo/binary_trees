#include "binary_trees.h"

/**
  * binary_tree_balance - measures the balance factor of a binary tree
  * @tree: pointer to the root node of the tree to measure the balance factor
  * Return: integer
  */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_balance = 0, right_balance = 0;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left)
	{
		left_balance = binary_tree_height(tree->left) + 1;
	}
	if (tree->right)
	{
		right_balance = binary_tree_height(tree->right) + 1;
	}
	return (left_balance - right_balance);
}

/**
  * binary_tree_height - measures the height of a binary tree
  * @tree: pointer to the root node of the tree to measure the height
  * Return: the height of the tree, else 0, If tree is NULL
  */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (max_height(tree) - 1);
}

/**
  * max_height - finds the height of the heightest node of binary tree
  * @node : ponter to the node
  * Return: height of highest node
  */
int max_height(const binary_tree_t *node)
{
	int left_side, right_side;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left_side = max_height(node->left);
		right_side = max_height(node->right);
		if (left_side > right_side)
		{
			return (left_side + 1);
		}
		else
		{
			return (right_side + 1);
		}
	}
}
