#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *currNode, *newNode;

	if (tree != NULL)
	{
		currNode = *tree;

		if (currNode == NULL)
		{
			newNode = binary_tree_node(currNode, value);
			if (newNode == NULL)
				return (NULL);
			return (*tree = newNode);
		}
		if (value < currNode->n)
		{
			if (currNode->left != NULL)
				return (bst_insert(&currNode->left, value));
			newNode = binary_tree_node(currNode, value);
			if (newNode == NULL)
				return (NULL);
			return (currNode->left = newNode);
		}
		if (value > currNode->n)
		{
			if (currNode->right != NULL)
				return (bst_insert(&currNode->right, value));
			newNode = binary_tree_node(currNode, value);
			if (newNode == NULL)
				return (NULL);
			return (currNode->right = newNode);
		}
	}
	return (NULL);
}
