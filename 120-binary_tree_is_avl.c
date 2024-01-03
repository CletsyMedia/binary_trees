#include "binary_trees.h"
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
	if (tree)
	{
	size_t len_h = 0, rig_h = 0;
	/* Calculate the height of the left and right subtrees */
	len_h = tree->left ? 1 + binary_tree_height(tree->left) : 1;
	rig_h = tree->right ? 1 + binary_tree_height(tree->right) : 1;
	return ((len_h > rig_h) ? len_h : rig_h);
	}
	return (0);
}

/**
 * is_avl_helper - Helper function to check if a binary tree is an AVL tree.
 * @tree: A pointer to the root node of the tree.
 * @low: The lower bound for node values in the tree.
 * @higher: The upper bound for node values in the tree.
 *
 * Return: 1 if the tree is an AVL tree, 0 otherwise.
 */
int is_avl_helper(const binary_tree_t *tree, int low, int higher)
{
	size_t left_hgt, right_hgt, diff;

	if (tree != NULL)
	{
		if (tree->n < low || tree->n > higher)
			return (0);
		left_hgt = binary_tree_height(tree->left);
		right_hgt = binary_tree_height(tree->right);
		diff = left_hgt > right_hgt ? left_hgt - right_hgt : right_hgt - left_hgt;
		if (diff > 1)
			return (0);
		return (is_avl_helper(tree->left, low, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, higher));
	}
	return (1);
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
	if (tree == NULL)
	return (0);

	/* Check if the tree is a valid AVL tree within the integer bounds */
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
