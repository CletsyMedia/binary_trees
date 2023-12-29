#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size of.
 *
 * Description: This function calculates the size of a binary tree, which is
 * defined as the total number of nodes in the tree. If the tree is empty
 * (NULL), the size is considered to be 0. Otherwise, the size is calculated
 * recursively by adding 1 for the current node and the sizes of its left and
 * right subtrees.
 *
 * Return: The size of the binary tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
