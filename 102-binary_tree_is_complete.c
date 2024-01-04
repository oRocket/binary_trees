#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if
 * a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int is_complete = 0;

	if (tree == NULL)
		return (0);

	if ((int)binary_tree_size(tree) == (1 << binary_tree_height(tree)) - 1)
		is_complete = 1;

	return (is_complete);
}
