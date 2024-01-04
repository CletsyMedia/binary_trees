#include <stddef.h>
#include "binary_trees.h"

/* Function prototypes */
int is_complete(const binary_tree_t *tree, size_t index, size_t nodes);
int is_max_heap(const binary_tree_t *tree);
size_t count_nodes(const binary_tree_t *tree);

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
	return (0);

	if (!is_complete(tree, 0, count_nodes(tree)) || !is_max_heap(tree))
	return (0);

	return (1);
}

/**
 * is_complete - Checks if a binary tree is a complete tree
 * @tree: Pointer to the root node of the tree to check
 * @index: Current index of the node being checked
 * @nodes: Total number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t nodes)
{
	if (tree == NULL)
	return (1);

	if (index >= nodes)
	return (0);

	return (is_complete(tree->left, 2 * index + 1, nodes) &&
	is_complete(tree->right, 2 * index + 2, nodes));
}

/**
 * is_max_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise
 */
int is_max_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
	return (1);

	if (tree->left && tree->left->n > tree->n)
	return (0);

	if (tree->right && tree->right->n > tree->n)
	return (0);

	return (is_max_heap(tree->left) && is_max_heap(tree->right));
}

/**
 * count_nodes - Counts the number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Number of nodes in the tree
 */
size_t count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
	return (0);

	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}
