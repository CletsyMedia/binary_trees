#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @root: A pointer to the root node of the binary tree.
 *
 * Description: This function calculates the height of the binary tree rooted
 * at the given node. The height is the length of the longest path from the
 * root node to a leaf. If the tree is empty (root is NULL), the function
 * returns 0.
 *
 * Return: The height of the binary tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_height = 0, right_height = 0;

		/* Calculate the height of the left subtree */
		left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;

		/* Calculate the height of the right subtree */
		right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

		/* Return the maximum height of left and right subtrees */
		return ((left_height > right_height) ? left_height : right_height);
	}
	/* The tree is empty, so the height is 0 */
	return (0);
}
