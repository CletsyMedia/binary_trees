#include "binary_trees.h"

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

