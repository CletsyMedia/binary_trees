#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree or 0 if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + tree_size(tree->left);

	if (tree->right)
		height_r = 1 + tree_size(tree->right);

	return (height_l + height_r);
}
/**
 * heap_to_sorted_array - converts a Binary Heap to a sorted array
 * @heap: pointer to the root of the Binary Heap
 * @size: pointer to the size of the resulting array
 *
 * Return: Pointer to the sorted array or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *sorted_array = NULL;

	/* Check if the heap or size pointer is NULL */
	if (!heap || !size)
		return (NULL);

	/* Calculate the size of the resulting array */
	*size = tree_size(heap) + 1;

	/* Allocate memory for the sorted array */
	sorted_array = malloc(sizeof(int) * (*size));

	/* Check for allocation failure */
	if (!sorted_array)
		return (NULL);

	/* Populate the sorted array by extracting elements from the heap */
	for (i = 0; heap; i++)
		sorted_array[i] = heap_extract(&heap);

	/* Return the pointer to the sorted array */
	return (sorted_array);
}
