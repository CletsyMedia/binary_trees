#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree.
 *
 * @tree: Pointer to the root node of the tree to rotate.
 *
 * Return: Pointer to the new root node of the rotated tree.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot, *temp;

	/* Check if the tree or its left child is NULL */
	if (tree == NULL || tree->left == NULL)
	return (NULL);

	/* Perform right rotation */
	pivot = tree->left;
	temp = pivot->right;
	pivot->right = tree;
	tree->left = temp;

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
