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
 * push - Enqueues a binary tree node into a level-order traversal queue.
 *
 * @node: Pointer to the binary tree node to be enqueued.
 * @head: Pointer to the head of the level-order queue.
 * @tail: Double pointer to the tail of the level-order queue.
 *
 * This function creates a new node for the queue, appends it to the end,
 * and updates the tail pointer accordingly.
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
	levelorder_queue_t **tail)
{
	levelorder_queue_t *newNode;

	/* Create a new node for the level-order queue */
	newNode = create_node(node);

	/* Handle memory allocation failure */
	if (newNode == NULL)
	{
	free_queue(head);
	exit(1);
	}

	/* Append the new node to the end of the queue */
	(*tail)->next = newNode;
	*tail = newNode;
}

/**
 * pop - Dequeues the front node from a level-order traversal queue.
 *
 * @head: Double pointer to the head of the level-order queue.
 *
 * This function dequeues the front node from the queue, frees the memory
 * occupied by the front node, and updates the head pointer accordingly.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *temp;

	/* Get the next node in the queue */
	temp = (*head)->next;

	/* Free the memory occupied by the front node */
	free(*head);

	/* Update the head pointer to the next node */
	*head = temp;
}
