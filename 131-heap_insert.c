#include <stdlib.h>
#include "binary_trees.h"

/* Function prototypes */
size_t heap_size(const heap_t *tree);
heap_t *last_node(heap_t *root, size_t size, size_t index);
void heapify_up(heap_t **root, heap_t *node);

/**
 * heap_insert - Inserts a value in Max Binary Heap
 * @root: Double pointer to the root node of the Heap to insert the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *last;

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
	return (NULL);

	if (*root == NULL)
	{
	*root = new_node;
	return (new_node);
	}

	last = last_node(*root, heap_size(*root) + 1, 1);

	if (!last->left)
	last->left = new_node;
	else
	last->right = new_node;

	new_node->parent = last;

	heapify_up(root, new_node);

	return (new_node);
}

/**
 * heap_size - Computes the size of the heap
 * @tree: Pointer to the root node of the heap
 *
 * Return: Size of the heap
 */
size_t heap_size(const heap_t *tree)
{
	if (tree == NULL)
	return (0);

	return (1 + heap_size(tree->left) + heap_size(tree->right));
}

/**
 * last_node - Finds the last node in the heap
 * @root: Pointer to the root node of the heap
 * @size: Current size of the heap
 * @index: Index of the node to insert
 *
 * Return: Pointer to the last node
 */
heap_t *last_node(heap_t *root, size_t size, size_t index)
{
	if (root == NULL)
	return (NULL);

	if (size == 1)
	return (root);

	if ((index >> 1) & 1)
	return (last_node(root->right, size >> 1, index >> 1));
	else
	return (last_node(root->left, size >> 1, index >> 1));
}

/**
 * heapify_up - Restores the Max Heap property by moving a node up
 * @root: Double pointer to the root node of the heap
 * @node: Pointer to the node to be moved up
 */
void heapify_up(heap_t **root, heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
	temp = node->n;
	node->n = node->parent->n;
	node->parent->n = temp;
	node = node->parent;
	}

	if (!node->parent)
	*root = node;

}
