#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst_helper - Checks if a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 * @min_val: The value of the smallest node visited thus far.
 * @max_val: The value of the largest node visited thus far.
 *
 * Return: If the tree is a valid BST, 1, otherwise, 0.
 */
int is_bst_helper(const binary_tree_t *tree, int min_val, int max_val)
{
	/* Check if the tree is not NULL */
	if (tree != NULL)
	{
	/* Check if the node value is within the valid range */
	if (tree->n < min_val || tree->n > max_val)
	return (0);
	/* Recursively check the left and right subtrees with updated range */
	return (is_bst_helper(tree->left, min_val, tree->n - 1) &&
	is_bst_helper(tree->right, tree->n + 1, max_val));
	}
	/* Return 1 if the tree is NULL */
	return (1);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	/* Check if the tree is NULL */
	if (tree == NULL)
	return (0);


	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
