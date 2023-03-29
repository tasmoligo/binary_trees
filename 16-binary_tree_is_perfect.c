#include "binary_trees.h"

/**
  * binary_tree_is_perfect - checks if a binary tree is perfect
  * @tree: pointer to the root node of the tree to check
  * Return: 1 if perfect else 0
  */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}
	if (tree->left == NULL && tree->right == NULL)
	{
		return (0);
	}
	if (binary_tree_height(tree->left) == binary_tree_height(tree->right))
	{
		if (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right))
			return (1);
	}
	return (0);
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
