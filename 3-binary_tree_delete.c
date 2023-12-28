#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree.
 * @tree: A pointer to the root node of the tree to delete.
 *
 *This function recursively deletes a binary tree by traversing
 * it in post-order (left subtree, right subtree, root) and freeing the memory
 * allocated for each node. The process continues until all nodes in the binary
 * tree have been visited and deallocated. The function prevents memory leaks
 * by appropriately freeing the memory for each node.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		/* Recursively delete the left subtree */
		binary_tree_delete(tree->left);

		/* Recursively delete the right subtree */
		binary_tree_delete(tree->right);

		/* Free the memory allocated for the current node */
		free(tree);
	}
}
