#include "binary_trees.h"

/**
 * inorder_successor - Finds the inorder successor in a BST.
 *
 * @root: Pointer to the root node of the tree.
 *
 * Return: Pointer to the inorder successor node.
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_delete - Deletes a node from a Binary Search Tree (BST).
 *
 * @root: Pointer to the root node of the tree.
 * @node: Node to be deleted from the tree.
 *
 * Return: Pointer to the new root node of the tree after deletion.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	/* No children or right-child only */
	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	/* Left-child only */
	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	/* Two children */
	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * bst_remove_recursive - Recursively removes a value from a BST.
 *
 * @root: Pointer to the root node of the tree.
 * @node: Current node being checked.
 * @value: The value to be removed from the tree.
 *
 * Return: Pointer to the new root node of the tree after removal.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - Removes a value from a Binary Search Tree (BST).
 *
 * @root: Pointer to the root node of the tree.
 * @value: The value to be removed from the tree.
 *
 * Return: Pointer to the new root node of the tree after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}

