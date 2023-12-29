#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @tree: A pointer to the node to measure the depth.
 *
 * Description: This function calculates the depth of a given node in a binary
 * tree. The depth is defined as the number of edges on the path from the node
 * to the root of the tree. If the node is NULL or has no parent, the function
 * returns 0. Otherwise, it recursively calculates the depth by adding 1 to the
 * depth of the parent node.
 *
 * Return: The depth of the node in the binary tree.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
