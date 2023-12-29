#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverses a binary tree using pre-order traversal.
 * @tree: A pointer to the root node of the tree.
 * @func: A function to apply to each node.
 *
 * Description: This function recursively traverses the binary tree in a
 * pre-order manner, visiting the current node, then the left subtree, and
 * finally the right subtree. For each visited node, the given function
 * 'func' is called.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		/* Apply function to current node */
		func(tree->n);

		/* Traverse left subtree */
		binary_tree_preorder(tree->left, func);

		/* Traverse right subtree */
		binary_tree_preorder(tree->right, func);
	}
}
