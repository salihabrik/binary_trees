{
	size_t leftheight = 0;
	size_t rightheight = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		leftheight += 1 + binary_tree_height(tree->left);

	if (tree->right)
		rightheight += 1 + binary_tree_height(tree->right);

	if (leftheight > rightheight)
		return (leftheight);
	else
		return (rightheight);
}
