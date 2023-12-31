#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree.
 * @node: A pointer to the node for which to find the sibling.
 *
 * Return: A pointer to the sibling node, or NULL if no sibling exists.
 *
 * Description:
 * This function takes a pointer to a node in a binary tree and returns a
 * pointer to its sibling node. The sibling is the node that shares the same
 * parent with the given node. If no sibling exists (e.g., the given node is
 * the root or has no parent), the function returns NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
	return (NULL);

	if (node->parent->left == node)
	return (node->parent->right);
	else
	return (node->parent->left);
}
