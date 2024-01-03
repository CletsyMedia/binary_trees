#include "binary_trees.h"
#include "limits.h"

/**
 * calculate_height - Computes the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the tree or 0 if the tree is empty.
 */
size_t calculate_height(const binary_tree_t *tree)
{
	if (tree)
	{
	size_t left_height = tree->left ? 1 + calculate_height(tree->left) : 1;
	size_t right_height = tree->right ? 1 + calculate_height(tree->right) : 1;

	return (left_height > right_height ? left_height : right_height);
	}
	return (0);
}

/**
 * is_avl_tree - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree.
 * @min: The minimum value allowed for a node.
 * @max: The maximum value allowed for a node.
 *
 * Return: 1 if the tree is a valid AVL tree, and 0 otherwise.
 */
int is_avl_tree(const binary_tree_t *tree, int min, int max)
{
	size_t left_h, right_hei, height_diff;

	if (tree)
	{
	if (tree->n < min || tree->n > max)
	return (0);

	left_h = calculate_height(tree->left);
	right_hei = calculate_height(tree->right);
	height_diff = left_h > right_hei ? left_h - right_hei : right_hei - left_h;

	if (height_diff > 1)
	return (0);

	return (is_avl_tree(tree->left, min, tree->n - 1) &&
	is_avl_tree(tree->right, tree->n + 1, max));
	}

	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
