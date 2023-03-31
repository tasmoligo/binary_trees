#include "binary_trees.h"

/**
  * binary_trees_ancestor - finds the lowest common ancestor of two nodes
  * @first: pointer to the first node
  * @second: pointer to the second node
  * Return:  lowest common ancestor, otherwise, NULL
  */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *f, *s;

	f = first->parent;
	s = second->parent;
	if (!first || !second)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}
	if (first == s || !f || (!f->parent && s))
	{
		return (binary_trees_ancestor(first, s));
	}
	else if (f == second || !s || (!s->parent && f))
	{
		return (binary_trees_ancestor(f, second));
	}
	return (binary_trees_ancestor(f, s));
}
