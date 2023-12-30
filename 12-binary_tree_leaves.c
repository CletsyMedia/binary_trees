#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaf nodes in a binary tree.
 * @tree: A pointer to the root node of the binary tree.
 *
 * This function recursively counts the number of leaf nodes in the given
 * binary tree. A leaf node is a node that has no left or right child. If the
 * tree is empty or the root is a leaf, the function returns 0 or 1,
 * respectively. Otherwise, it sums the leaf counts of the left and right
 * subtrees.
 *
 * Return: The number of leaf nodes in the binary tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	return binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);
}
