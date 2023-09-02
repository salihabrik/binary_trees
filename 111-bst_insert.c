#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree (BST).
 *
 * @tree: A double pointer to the root node of the BST.
 * @value: The value to insert.
 *
 * Return: A pointer to the created node or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		if (*tree == NULL)
			return (NULL);
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			if ((*tree)->left == NULL)
				return (NULL);
			return ((*tree)->left);
		}
		else
			return (bst_insert(&((*tree)->left), value));
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			if ((*tree)->right == NULL)
				return (NULL);
			return ((*tree)->right);
		}
		else
			return (bst_insert(&((*tree)->right), value));
	}

	return (NULL);
}
