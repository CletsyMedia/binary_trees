#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Rotates a binary tree to the left.
 *
 * @tree: Pointer to the root of the binary tree to be rotated.
 *
 * This function performs a left rotation on the specified binary tree,
 * updating parent and child pointers accordingly. It returns a pointer to
 * the new root of the rotated tree.
 *
 * Return: Pointer to the new root of the rotated binary tree.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot, *temp;

	/* Check if the tree or its right child is NULL */
	if (tree == NULL || tree->right == NULL)
	return (NULL);

	/* Perform left rotation */
	pivot = tree->right;
	temp = pivot->left;
	pivot->left = tree;
	tree->right = temp;

	/* Update parent pointers */
	if (temp != NULL)
	temp->parent = tree;

	temp = tree->parent;
	tree->parent = pivot;
	pivot->parent = temp;

	/* Update parent's child pointer to the rotated tree */
	if (temp != NULL)
	{
	if (temp->left == tree)
	temp->left = pivot;
	else
	temp->right = pivot;
	}

	return (pivot);
}
