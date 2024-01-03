#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: A pointer to the root node of the tree to delete
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
	return;

	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}

/**
 * array_to_avl - Builds an AVL tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: A pointer to the root node of the created AVL, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	avl_t *node;
	size_t i;

	if (array == NULL || size == 0)
	return (NULL);

	for (i = 0; i < size; i++)
	{
	node = avl_insert(&root, array[i]);
	if (node == NULL)
	{
	/* If avl_insert fails, free the previously allocated memory and return NULL*/
	binary_tree_delete(root);
	return (NULL);
	}
	}

	return (root);
}
