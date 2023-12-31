#include "binary_trees.h"

/* Checks if a node is a leaf in a binary tree */
unsigned char is_leaf(const binary_tree_t *node);
/* Measures the depth of a binary tree */
size_t depth(const binary_tree_t *tree);
/* Finds a leaf node in a binary tree */
const binary_tree_t *get_leaf(const binary_tree_t *tree);
/* Checks if a binary tree is perfect recursively */
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
/* Checks if a binary tree is perfect */
int binary_tree_is_perfect(const binary_tree_t *tree);



/**
 * is_leaf - Checks if a node is a leaf in a binary tree.
 * @node: A pointer to the node to check.
 *
 * Return: 1 if the node is a leaf, 0 otherwise.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
  return (node && !node->left && !node->right);
}

/**
 * depth - Measures the depth of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The depth of the tree.
 */
size_t depth(const binary_tree_t *tree)
{
  return ((tree && tree->parent) ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - Finds a leaf node in a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: A pointer to a leaf node in the tree.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - Checks if a binary tree is perfect recursively.
 * @tree: A pointer to the root node of the tree.
 * @leaf_depth: The depth of a leaf node in the tree.
 * @level: The current level in the tree.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int is_perfect_recursive(const binary_tree_t *tree,
                         size_t leaf_depth, size_t level)
{
  if (is_leaf(tree))
    return (level == leaf_depth ? 1 : 0);
  if (tree->left == NULL || tree->right == NULL)
    return (0);
  return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
          is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree.
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
  if (tree == NULL)
    return (0);
  return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
