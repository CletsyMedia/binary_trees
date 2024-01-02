#include "binary_trees.h"

/**
 * create_node - Creates a new level order queue_t node.
 * @node: The binary tree node for the new node to contain.
 *
 * Return: If an error occurs, NULL.
 *	Otherwise, a pointer to the new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *newNode;

	newNode = malloc(sizeof(levelorder_queue_t));
	if (newNode == NULL)
	return (NULL);

	newNode->node = node;
	newNode->next = NULL;

	return (newNode);
}

/**
 * free_queue - Frees a level order queue_t queue.
 * @head: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *temp;

	while (head != NULL)
	{
	temp = head->next;
	free(head);
	head = temp;
	}
}

/**
 * pint_push - Runs a function on a given binary tree node and
 *	pushes its children into a levelorder_queue_t queue.
 * @node: The binary tree node to print and push.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 * @func: A pointer to the function to call on @node.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *newNode;

	func(node->n);
	if (node->left != NULL)
	{
		newNode = create_node(node->left);
		if (newNode == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = newNode;
		*tail = newNode;
	}
	if (node->right != NULL)
	{
		newNode = create_node(node->right);
		if (newNode == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = newNode;
		*tail = newNode;
	}
}

/**
 * pop - Pops the head of a levelorder_queue_t queue.
 * @head: A double pointer to the head of the queue.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}

/**
 * binary_tree_levelorder - Traverses a binary tree using
 *	level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *headLvl, *tail_lvl;

	if (tree == NULL || func == NULL)
		return;

	headLvl = tail_lvl = create_node((binary_tree_t *)tree);
	if (headLvl == NULL)
		return;

	while (headLvl != NULL)
	{
		pint_push(headLvl->node, headLvl, &tail_lvl, func);
		pop(&headLvl);
	}
}
