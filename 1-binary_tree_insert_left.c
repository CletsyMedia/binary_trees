#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left child of another in a
 * binary tree.
 * @parent: A pointer to the node where the left child will be inserted.
 * @value: The value to store in the new left child node.
 *
 * This function inserts a new node with the specified value as the left
 * child of the given parent node in a binary tree. If the parent already
 * has a left child, the new node takes its place, and the old left child
 * becomes the left child of the new node.
 *
 * Return: NULL if parent is NULL or memory allocation fails, otherwise,
 * a pointer to the new left child node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	if (parent == NULL)
	return (NULL);

	newNode = binary_tree_node(parent, value);
	if (newNode == NULL)
	return (NULL);

	if (parent->left != NULL)
	{
	newNode->left = parent->left;
	parent->left->parent = newNode;
	}
	parent->left = newNode;

	return (newNode);
}
