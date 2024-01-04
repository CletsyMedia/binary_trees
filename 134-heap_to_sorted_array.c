#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    /* Check if the tree is NULL */
    if (!tree)
        return (0);

    /* Calculate the size of the left subtree */
    size_t left_size = tree->left ? 1 + binary_tree_size(tree->left) : 0;

    /* Calculate the size of the right subtree */
    size_t right_size = tree->right ? 1 + binary_tree_size(tree->right) : 0;

    /* Return the total size of the tree */
    return left_size + right_size;
}
