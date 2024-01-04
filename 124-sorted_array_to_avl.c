#include <stdlib.h>
#include "binary_trees.h"

/* Function prototypes */
void create_tree(avl_t **node, int *array, size_t size, int mode);

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t middle;

	if (size == 0)
	return (NULL);

	middle = (size / 2);
	middle = (size % 2 == 0) ? middle - 1 : middle;

	root = binary_tree_node(NULL, array[middle]);

	create_tree(&root, array, middle, 1);
	create_tree(&root, array + middle + 1, (size - 1 - middle), 2);

	return (root);
}

/**
 * create_tree - Recursively builds AVL tree from a sorted array
 * @node: Pointer to the current node
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 * @mode: Determines whether to create left (1) or right (2) child
 */
void create_tree(avl_t **node, int *array, size_t size, int mode)
{
	size_t middle;

	if (size == 0)
	return;

	middle = (size / 2);
	middle = (size % 2 == 0) ? middle - 1 : middle;

	if (mode == 1)
	{
	(*node)->left = binary_tree_node(*node, array[middle]);
	create_tree(&((*node)->left), array, middle, 1);
	create_tree(&((*node)->left), array + middle + 1, (size - 1 - middle), 2);
	}
	else
	{
	(*node)->right = binary_tree_node(*node, array[middle]);
	create_tree(&((*node)->right), array, middle, 1);
	create_tree(&((*node)->right), array + middle + 1, (size - 1 - middle), 2);
	}
}
