#include "binary_trees.h"

/* Function prototypes */
heap_t *find_parent(heap_t *root);
void heapify_up(heap_t **root, heap_t *node);
size_t heap_size(const heap_t *tree);

/**
 * heap_insert - Inserts a value in Max Binary Heap
 * @root: Double pointer to the root node of the Heap to insert the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

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

	/* Find the parent for the new node */
	parent = find_parent(*root);

	/* Insert the new node */
	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	new_node->parent = parent;

	/* Restore the Max Heap property */
	heapify_up(root, new_node);

	return (new_node);
}

/**
 * find_parent - Finds the parent for the new node in Max Heap
 * @root: Pointer to the root node of the heap
 *
 * Return: Pointer to the parent node
 */
heap_t *find_parent(heap_t *root)
{
	heap_t *parent;
	int bit;

	parent = root;

	/* Traverse the heap to find the parent for the new node */
	for (bit = 1 << (heap_size(root) - 2); bit > 0; bit >>= 1)
	{
		parent = (bit & heap_size(root)) ? parent->right : parent->left;
	}

	return (parent);
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
