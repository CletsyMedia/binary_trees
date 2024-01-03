#include "binary_trees.h"

/* Function Prototypes */
size_t binary_tree_height(const binary_tree_t *tree);	/* Remove 'static' */
int balance_factor(const binary_tree_t *tree);
binary_tree_t *avl_insert_recursive(avl_t **tree, int value);

/**
 * avl_insert - Inserts a value in an AVL Tree.
 * @tree: Double pointer to the root node of the AVL tree.
 * @value: Value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (tree == NULL)
	return (NULL);

	return (avl_insert_recursive(tree, value));
}

/**
 * binary_tree_height - Calculates the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the binary tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
	return (0);

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	return (((left_height > right_height) ? left_height : right_height) + 1);
}

/**
 * balance_factor - Calculates the balance factor of a node.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The balance factor of the node.
 */
int balance_factor(const binary_tree_t *tree)
{
	if (tree == NULL)
	return (0);

	return ((int)(binary_tree_height(tree->left) -
	binary_tree_height(tree->right)));
}

/**
 * avl_insert_recursive - Inserts a value in an AVL Tree recursively.
 * @tree: Double pointer to the root node of the AVL tree.
 * @value: Value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
binary_tree_t *avl_insert_recursive(avl_t **tree, int value)
{
	if (*tree == NULL)
	{
	*tree = binary_tree_node(NULL, value);
	if (*tree == NULL)
	return (NULL);
	return (*tree);
	}

	if (value < (*tree)->n)
	{
	(*tree)->left = avl_insert_recursive(&((*tree)->left), value);
	}
	else if (value > (*tree)->n)
	{
	(*tree)->right = avl_insert_recursive(&((*tree)->right), value);
	}
	else
	{
	/* Duplicate values are not allowed in AVL trees */
	return (NULL);
	}

	/* Update the height of the current node */
	size_t left_h = binary_tree_height((*tree)->left);
	size_t right_h = binary_tree_height((*tree)->right);
	
	/* Get the balance factor of the current node */
	int balance = balance_factor(*tree);

	/* Left-Left Case */
	if (balance > 1 && value < (*tree)->left->n)
	{
	return (binary_tree_rotate_right(*tree));
	}

	/* Right-Right Case */
	if (balance < -1 && value > (*tree)->right->n)
	{
	return (binary_tree_rotate_left(*tree));
	}

	/* Left-Right Case */
	if (balance > 1 && value > (*tree)->left->n)
	{
	(*tree)->left = binary_tree_rotate_left((*tree)->left);
	return (binary_tree_rotate_right(*tree));
	}

	/* Right-Left Case */
	if (balance < -1 && value < (*tree)->right->n)
	{
	(*tree)->right = binary_tree_rotate_right((*tree)->right);
	return (binary_tree_rotate_left(*tree));
	}

	return (*tree);
}
