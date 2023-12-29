#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses a binary tree using post-order traversal.
 * @tree: A pointer to the root node of the tree.
 * @func: A function to apply to each node.
 *
 * Description: This function recursively traverses the binary tree in a
 * post-order manner, visiting the left subtree, then the right subtree,
 * and finally the current node. For each visited node, the given function
 * 'func' is called.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
	/* Traverse left subtree */
	binary_tree_postorder(tree->left, func);

	/* Traverse right subtree */
	binary_tree_postorder(tree->right, func);

	/* Apply function to current node */
	func(tree->n);
	}
}
