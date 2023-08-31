#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 *
 * @tree: Pointer to the root node of the tree to measure the size.
 *
 * Return: Size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size, index;

	if (tree == NULL)
		return (0);

	size = binary_tree_size(tree);
	index = 0;

	return (is_complete_recursive(tree, index, size));
}

/**
 * is_complete_recursive - Checks if a binary tree is complete recursively.
 *
 * @tree: Pointer to the root node of the tree to check.
 * @index: Index of the current node.
 * @size: Total size of the tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete_recursive(const binary_tree_t *tree, size_t index, size_t size)
{
	if (tree == NULL)
		return (1);

	if (index >= size)
		return (0);

	return (is_complete_recursive(tree->left, 2 * index + 1, size) &&
		is_complete_recursive(tree->right, 2 * index + 2, size));
}
