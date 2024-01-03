#include "binary_trees.h"
#include <stddef.h>
#include <limits.h>

/**
 * binary_tree_height - Calculates the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the binary tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	/* Guard clause to handle NULL trees */
	if (!tree)
	return (0);

	/* Calculate the height of the left and right subtrees */
	size_t left_height = tree->left ? 1 + binary_tree_height(tree->left) : 1;
	size_t right_height = tree->right ? 1 + binary_tree_height(tree->right) : 1;

	/* Return the maximum height among the left and right subtrees */
	return ((left_height > right_height) ? left_height : right_height);
}

/**
 * is_avl_helper - Helper function to check if a binary tree is an AVL tree.
 * @tree: A pointer to the root node of the tree.
 * @lo: The lower bound for node values in the tree.
 * @hi: The upper bound for node values in the tree.
 *
 * Return: 1 if the tree is an AVL tree, 0 otherwise.
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	/* Guard clause to handle NULL trees */
	if (!tree)
	return (1);

	/* Check if the current node value is within the specified range */
	if (tree->n < lo || tree->n > hi)
	return (0);

	/* Calculate the height of the left and right subtrees */
	size_t left_h = binary_tree_height(tree->left);
	size_t right_h = binary_tree_height(tree->right);

	/* Calculate the height difference between left and right subtrees */
	size_t h_diff = (left_h > right_h) ? left_h - right_h : right_h - left_h;

	/* Check if the tree violates the AVL property */
	if (h_diff > 1)
	return (0);

	/* Recursively check left and right subtrees */
	return (is_avl_helper(tree->left, lo, tree->n - 1) &&
	is_avl_helper(tree->right, tree->n + 1, hi));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: 1 if the tree is a valid AVL tree, and 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	/* Guard clause to handle NULL trees */
	if (!tree)
	return (0);

	/* Check if the tree is a valid AVL tree within the integer bounds */
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
