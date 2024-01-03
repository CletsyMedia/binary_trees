#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, return 0, else return balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	/* Check if the tree is not NULL */
	if (tree)
	/**
	 * Return the balance factor by subtracting
	 * the height of the right
	 * subtree from the height of the left subtree
	 */
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	/* Return 0 if the tree is NULL */
	return (0);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, return 0, else return the height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	/* Check if the tree is not NULL */
	if (tree)
	{
	size_t left_height = 0, right_height = 0;

	/* Calculate the height of the left subtree */
	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 1;
	/* Calculate the height of the right subtree */
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 1;

	/* Return the maximum height between left and right subtrees */
	return ((left_height > right_height) ? left_height : right_height);
	}

	/* Return 0 if the tree is NULL */
	return (0);
}
