#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: A double pointer to the root node of the Heap to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *current, *new_node, *parent;
	int tree_size, remaining_leaves, subtree, bit, level, temp_value;

	if (!root)
		return (NULL);

	if (!(*root))
		return (*root = binary_tree_node(NULL, value));

	current = *root;
	tree_size = binary_tree_size(current);
	remaining_leaves = tree_size;

	for (level = 0, subtree = 1; remaining_leaves >= subtree;
	subtree *= 2, level++)
		remaining_leaves -= subtree;

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		current = remaining_leaves & bit ? current->right : current->left;

	new_node = binary_tree_node(current, value);
	remaining_leaves & 1 ? (current->right = new_node) :
	(current->left = new_node);

	parent = new_node;
	for (; parent->parent && (parent->n > parent->parent->n);
	parent = parent->parent)
	{
		temp_value = parent->n;
		parent->n = parent->parent->n;
		parent->parent->n = temp_value;
		new_node = new_node->parent;
	}

	return (new_node);
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: The tree to measure the size of.
 *
 * Return: The size of the tree or 0 if the tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
