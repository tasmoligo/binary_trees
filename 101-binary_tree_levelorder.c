#include "binary_trees.h"

queue_t *create_node(binary_tree_t *node);
void free_queue(queue_t *head);
void pint_push(binary_tree_t *node, queue_t *head,
		queue_t **tail, void (*func)(int));
void pop(queue_t **head);

/**
  * binary_tree_levelorder - goes through a binary tree \
  using level-order traversal
  * @tree: pointer to the root node of the tree to traverse
  * @func: pointer to a function to call for each node.
  * Return: nothing
  */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;
	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		return;
	while (head != NULL)
	{
		pint_push(head->node, head, &tail, func);
		pop(&head);
	}
}

/**
 * create_node - Creates a new levelorder node.
 * @node: pointer to the binary tree node for the new node to contain.
 * Return: a pointer to the new node. otherwise, NULL If an error occur.
 */
queue_t *create_node(binary_tree_t *node)
{
	queue_t *new;

	new = malloc(sizeof(queue_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->node = node;
	new->next = NULL;
	return (new);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: pointer to the head of the queue.
 * Return: nothing
 */
void free_queue(queue_t *head)
{
	queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * pint_push - Runs a function on a given binary tree node and \
 pushes its children into a levelorder_queue_t queue.
 * @node: pointer to the binary tree node to print and push.
 * @head: double pointer to the head of the queue.
 * @tail: double pointer to the tail of the queue.
 * @func: A pointer to the function to call on @node.
 * Return: nothing
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void pint_push(binary_tree_t *node, queue_t *head,
		queue_t **tail, void (*func)(int))
{
	queue_t *new;

	func(node->n);
	if (node->left != NULL)
	{
		new = create_node(node->left);
		if (new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
	if (node->right != NULL)
	{
		new = create_node(node->right);
		if (new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
}

/**
 * pop - Pops the head of a levelorder_queue_t queue.
 * @head: A double pointer to the head of the queue.
 * Return: nothing
 */
void pop(queue_t **head)
{
	queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}
