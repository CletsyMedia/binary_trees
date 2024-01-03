#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree (BST).
 *
 * @tree: Pointer to the root node of the BST to search.
 * @value: The value to search for in the tree.
 *
 * Return: Pointer to the node containing the specified value, or NULL if not found.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
    /* Check if tree is NULL or if the value is found in the current node */
    if (tree == NULL || tree->n == value)
        return ((bst_t *)tree);

    /* If the value is less than the current node's value, search in the left subtree */
    if (value < tree->n)
        return (bst_search(tree->left, value));
    /* If the value is greater than the current node's value, search in the right subtree */
    else
        return (bst_search(tree->right, value));
}
