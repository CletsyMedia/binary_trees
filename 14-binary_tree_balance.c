#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, return 0, else return the balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	/* Check if the tree is NULL */
	if (!tree)
	return (0);

	/**
	* Calculate the balance factor by subtracting the height of the
	* right subtree from the height of the left subtree.
	*/
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, return 0, else return the height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	/* Check if the tree is NULL */
	if (!tree)
	return (0);

	/**
	* Recursively calculate the height of the tree by comparing the
	* heights of the left and right subtrees and returning the greater
	* height incremented by 1.
	*/
	size_t left = binary_tree_height(tree->left);
	size_t right = binary_tree_height(tree->right);

	return ((left > right) ? left + 1 : right + 1);
}
