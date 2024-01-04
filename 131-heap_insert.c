#include "binary_trees.h"

/**
 * heap_insert - Inserts a value in Max Binary Heap
 * @root: Double pointer to the root node of the Heap to insert the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *tree, *flip;
	int size, leaves, sub, bit, level, temp;

	/* Create a new node */
	new_node = binary_tree_node(NULL, value);
	if (!new_node)
	return (NULL);

	/* If the heap is empty, make the new node the root */
	if (!*root)
	{
	*root = new_node;
	return (new_node);
	}
	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;

	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
	leaves -= sub;
	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
	tree = leaves & bit ? tree->right : tree->left;
	/* Traverse tree to first empty slot */
	/* Insert the new node */
	if (!tree->right)
	tree->right = new_node;
	else
	tree->left = new_node;
	new_node->parent = tree;
	/* Restore the Max Heap property */
	flip = new_node;
	while (flip->parent && (flip->n > flip->parent->n))
	{
	temp = flip->n;
	flip->n = flip->parent->n;
	flip->parent->n = temp;
	new_node = new_node->parent;
	}
	return (new_node);
}

/**
 * binary_tree_size - Computes the size of the binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
	return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
