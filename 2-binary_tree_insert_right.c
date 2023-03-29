#include "binary_trees.h"

/**
  * binary_tree_insert_right - inserts a node as the right-child \
  of another node
  * @parent: pointer to the node to insert the left-child in
  * @value: value to store in the new node
  * Return: pointer to the created node, \
  * NULL on failure or if parent is NULL
  */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *current;

	if (parent == NULL)
		return (NULL);
	current = binary_tree_node(parent, value);
	if (parent->right != NULL)
	{
		parent->right->parent = current;
		current->right = parent->right;
	}
	parent->right = current;
	return (current);
}
