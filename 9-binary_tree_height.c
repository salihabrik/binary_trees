#include "binary_trees.h"


/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    if (binary_tree_balance(tree) != 0)
        return (0);

    if (!tree->left && !tree->right)
        return (1);

    if (!tree->left || !tree->right)
        return (0);

    return (binary_tree_is_perfect(tree->left) &&
            binary_tree_is_perfect(tree->right));
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (!tree)
        return (0);

    left_height = (int)binary_tree_height(tree->left);
    right_height = (int)binary_tree_height(tree->right);

    return (left_height - right_height);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (!tree)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}
