#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: A pointer to the lowest common ancestor, or NULL if not found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *temp = NULL;

	if (!first || !second)
		return (NULL);

	temp = (binary_tree_t *)first;
	while (temp)
	{
		binary_tree_t *temp2 = (binary_tree_t *)second;

		while (temp2)
		{
			if (temp2 == temp)
				return (temp2);
			temp2 = temp2->parent;
		}
		temp = temp->parent;
	}
	return (NULL);
}
