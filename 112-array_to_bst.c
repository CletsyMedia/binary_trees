#include "binary_trees.h"

/**
 * array_to_bst - Builds a Binary Search Tree (BST) from an array of integers.
 *
 * @array: Pointer to the first element of the array to be converted.
 * @size: The number of elements in the array.
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure.
 *
 * Description:
 * This function takes an array of integers and builds a Binary Search Tree
 * by inserting each unique element from the array into the tree using the
 * bst_insert function. Duplicate values are ignored during the insertion.
 * The resulting BST is returned, or NULL if the array is NULL or if memory
 * allocation fails during the insertion.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t a, b;

	/* Check if the array is NULL */
	if (array == NULL)
	return (NULL);

	/* Loop through each element in the array */
	for (a = 0; a < size; a++)
	{
	/* Check for duplicate elements */
	for (b = 0; b < a; b++)
	{
	if (array[b] == array[a])
	break;
	}

	/* Insert the unique element into the BST */
	if (b == a)
	{
	/* Check if bst_insert fails and return NULL in case of failure */
	if (bst_insert(&tree, array[a]) == NULL)
	return (NULL);
	}
	}

	/* Return the root of the created BST */
	return (tree);
}
