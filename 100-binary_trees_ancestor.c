#include "binary_trees.h"



/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 *
 * @first: A pointer to the first node
 * @second: A pointer to the second node
 *
 * Return: A pointer to the lowest common ancestor or NULL
 */
binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *first, const binary_tree_t *second)
{
	int first_status = 0, second_status = 0;
	binary_tree_t *ancestor = NULL;

	if (!first || !second)
		return (NULL);

	ancestor = binary_tree_ancestor(first, &first_status);

	if (!ancestor)
		return (NULL);

	return (binary_tree_ancestor(second, &second_status));
}

/**
 * binary_tree_ancestor - Checks if an ancestor has been visited
 *
 * @ancestor: Pointer to the ancestor node
 * @ancestor_status: Status of the ancestor (0 for green, 1 for blue)
 *
 * Return: A pointer to the common ancestor or NULL
 */
binary_tree_t *binary_tree_ancestor(
	const binary_tree_t *ancestor, int *ancestor_status)
{
	if (!ancestor)
		return (NULL);

	if (*ancestor_status == 1)
		return ((binary_tree_t *)ancestor);

	*ancestor_status = 1;

	return (binary_tree_ancestor(ancestor->parent, ancestor_status));
}