#include "binary_trees.h"

/**
 * binary_tree_inorder - Traverses a binary tree using in-order traversal.
 * @tree: A pointer to the root node of the tree.
 * @func: A function to apply to each node.
 *
 * Description: This function recursively traverses the binary tree in an
 * in-order manner, visiting the left subtree, then the current node, and
 * finally the right subtree. For each visited node, the given function
 * 'func' is called.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
	/* Traverse left subtree */
	binary_tree_inorder(tree->left, func);

	/* Apply function to current node */
	func(tree->n);

	/* Traverse right subtree */
	binary_tree_inorder(tree->right, func);
	}
}
