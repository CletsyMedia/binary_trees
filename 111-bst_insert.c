#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst_helper - Checks if a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 * @lo: The value of the smallest node visited thus far.
 * @hi: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid BST, 1, otherwise, 0.
 */
int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
  if (tree != NULL)
  {
    if (tree->n < lo || tree->n > hi)
      return (0);
    return (is_bst_helper(tree->left, lo, tree->n - 1) &&
            is_bst_helper(tree->right, tree->n + 1, hi));
  }
  return (1);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
  if (tree == NULL)
    return (0);
  return (is_bst_helper(tree, INT_MIN, INT_MAX));
}

/**
 * bst_insert - Inserts a value into a Binary Search Tree (BST).
 *
 * @tree: Double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{ /* Check if the current node is NULL (empty subtree) */
  if (*tree == NULL)
  {
    /* Create a new node and make it the root if the tree is empty */
    *tree = binary_tree_node(NULL, value);
    return (*tree);
  }
  /* Check if the tree is a valid BST */
  if (!binary_tree_is_bst(*tree))
    return (NULL);
  /* Check if the value is less than the current node's value */
  if (value < (*tree)->n)
  {
    /* Recursively insert into the left subtree */
    if ((*tree)->left == NULL)
    {
      (*tree)->left = binary_tree_node(*tree, value);
      return ((*tree)->left);
    }
    else
    {
      return (bst_insert(&((*tree)->left), value));
    }
  }
  /* Check if the value is greater than the current node's value */
  else if (value > (*tree)->n)
  {
    /* Recursively insert into the right subtree */
    if ((*tree)->right == NULL)
    {
      (*tree)->right = binary_tree_node(*tree, value);
      return ((*tree)->right);
    }
    else
    {
      return (bst_insert(&((*tree)->right), value));
    }
  }
  /* If the value is equal, ignore and return NULL (already present) */
  return (NULL);
}
