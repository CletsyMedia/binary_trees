#include "binary_trees.h"

size_t depth(const binary_tree_t *tree);

/*
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first binary tree node
 * @second: pointer to the second binary tree node
 *
 * Return: a pointer to the lowest common ancestor, or NULL if no common
 * ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t first_depth, second_depth;

	/* Check for NULL inputs */
	if (first == NULL || second == NULL)
		return (NULL);

	/* Check if nodes are the same */
	if (first == second)
		return ((binary_tree_t *)first);

	/* Check if nodes share the same parent */
	if (first->parent == second->parent)
		return ((binary_tree_t *)first->parent);

	/* Check for direct parent-child relationship */
	if (first == second->parent)
		return ((binary_tree_t *)first);
	if (first->parent == second)
		return ((binary_tree_t *)second);

	/* Traverse up to the root to find the common ancestor */
	for (first_depth = depth(first); first_depth > 1; first_depth--)
		first = first->parent;

	for (second_depth = depth(second); second_depth > 1; second_depth--)
		second = second->parent;

	/* Check for the common ancestor after traversal */
	if (first == second)
		return ((binary_tree_t *)first);
	if (first->parent == second->parent)
		return ((binary_tree_t *)first->parent);
	if (first == second->parent)
		return ((binary_tree_t *)first);
	if (first->parent == second)
		return ((binary_tree_t *)second);
	else
		return (NULL);
}
