#include "binary_trees.h"

/**
 * balance_avl_tree - Balance an AVL tree by performing rotations if necessary
 * @root: Pointer to the root node of the AVL tree
 *
 * This function balances the AVL tree rooted at the given node by
 * recursively checking the balance factor of each node and performing
 * rotations if the balance factor is greater than 1 or less than -1.
 * The rotations maintain the AVL tree property and ensure its balance.
 *
 * @root: Pointer to the root node of the AVL tree
 */
void balance_avl_tree(avl_t **root)
{
	if (root == NULL || *root == NULL)
		return;

	if ((*root)->left == NULL && (*root)->right == NULL)
		return;

	/* Recursively balance the left and right subtrees */
	balance_avl_tree(&(*root)->left);
	balance_avl_tree(&(*root)->right);

	/* Check and perform rotations if necessary */
	int balance_factor = binary_tree_balance((const binary_tree_t *)*root);

	if (balance_factor > 1)
		*root = binary_tree_rotate_right((binary_tree_t *)*root);
	else if (balance_factor < -1)
		*root = binary_tree_rotate_left((binary_tree_t *)*root);
}


/**
 * find_in_order_successor - Find the in-order successor of a node in a BST
 * @node: Pointer to the node for which to find the successor
 *
 * This function finds the in-order successor of the given node in a
 * Binary Search Tree (BST).
 *
 * @node: Pointer to the node for which to find the in-order successor
 * Return: In-order successor value or 0 if no successor found
 */
int find_in_order_successor(bst_t *node)
{
	int left_successor = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left_successor = find_in_order_successor(node->left);
		if (left_successor == 0)
	{
			return (node->n);
	}
		return (left_successor);
	}
}



/**
 *remove_type - function that removes a node depending of its children
 *@root: node to remove
 *Return: 0 if it has no children or other value if it has
 */
int remove_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}

/**
 * bst_remove - remove a node from a BST tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - remove a node from a AVL tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	bal(&root_a);
	return (root_a);
}

