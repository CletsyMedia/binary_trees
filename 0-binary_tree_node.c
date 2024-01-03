#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new binary tree node with a given parent.
 * @parent: A pointer to the parent node of the new node.
 * @value: The value to be stored in the new node.
 *
 * This function allocates memory for a new binary tree node,
 * initializes its value and parent, and sets the left and right
 * children to NULL.
 *
 * Return: If memory allocation fails, returns NULL. Otherwise, returns a
 * pointer
 * to the newly created node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode = malloc(sizeof(binary_tree_t));

	if (newNode == NULL)
		return (NULL);

	newNode->n = value;
	newNode->parent = parent;
	newNode->left = NULL;
	newNode->right = NULL;

	return (newNode);
}
