#include "binary_trees.h"

/**
 * height - Calculates the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the binary tree.
 */
size_t height(const binary_tree_t *tree)
{
	/* Guard clause to handle NULL trees */
	if (tree != NULL)
	{
	size_t len_h = 0, rig_h = 0;
	/* Calculate the height of the left and right subtrees */
	len_h = tree->left ? 1 + binary_tree_height(tree->left) : 1;
	rig_h = tree->right ? 1 + binary_tree_height(tree->right) : 1;
	return ((len_h > rig_h) ? len_h : rig_h);
	}
	return (0);
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
 * avl_insert_recursive - Inserts a value into an AVL tree recursively.
 * @tree: A double pointer to the root node of the AVL tree.
 * @parent: A pointer to the parent node.
 * @new: A double pointer to store the newly inserted node.
 * @value: The value to be inserted into the AVL tree.
 *
 * Return: A pointer to the newly inserted node, or NULL on failure.
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{
	int bfactor;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	/* If the value already exists in the tree, return the current node */
	else
		return (*tree);

	/* Calculate the balance factor of the current node */
	bfactor = balance_factor(*tree);

	/* Perform AVL rotations based on the balance factor to maintain balance */
	if (bfactor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (bfactor < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (bfactor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bfactor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &new, value);
	return (new);
}
