#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	/* Check if the double pointer to the root node is not NULL */
	if (tree != NULL)
	{
	bst_t *curr = *tree; /* Initialize current pointer */

	/* Check if the current node is NULL, create a new node as the root */
	if (curr == NULL)
	{
	bst_t *new = binary_tree_node(curr, value);

	return (new == NULL ? NULL : (*tree = new));
	}

	/* Insert in the left subtree if the value is < the current node's value */
	if (value < curr->n)
	{
	if (curr->left != NULL)
	return (bst_insert(&curr->left, value));

	bst_t *new = binary_tree_node(curr, value);

	return (new == NULL ? NULL : (curr->left = new));
	}

	/* Insert in the right subtree if the value is > the current node's value */
	if (value > curr->n)
	{
	if (curr->right != NULL)
	return (bst_insert(&curr->right, value));

	bst_t *new = binary_tree_node(curr, value);

	return (new == NULL ? NULL : (curr->right = new));
	}
	}

	/* Return NULL if the tree or value is NULL */
	return (NULL);
}
