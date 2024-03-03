#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: number of nodes with min 1 child or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return (0);
	return (binary_tree_size(tree) - binary_tree_leaves(tree));
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size of the tree or 0 if tre is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
        if (!tree)
                return (0);
        return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the number of leaves
 * Return: number of leaves or 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
        if (!tree)
                return (0);
        if (tree->left == NULL && tree->right == NULL)
                return (1);
        return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
