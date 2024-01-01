#include "binary_trees.h"

/**
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
	binary_tree_t *mom, *pop;

	/* Check for NULL inputs */
	if (!first || !second)
		return (NULL);

	/* Check if nodes are the same */
	if (first == second)
		return ((binary_tree_t *)first);

	mom = first->parent, pop = second->parent;

	/* Check for parent-child relationship and continue the search */
	if (first == pop || !mom || (!mom->parent && pop))
		return (binary_trees_ancestor(first, pop));
	else if (mom == second || !pop || (!pop->parent && mom))
		return (binary_trees_ancestor(mom, second));

	/* Continue the search for common ancestor */
	return (binary_trees_ancestor(mom, pop));
}
