#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

int is_bst_helper(const binary_tree_t *tree,
		const binary_tree_t *min, const binary_tree_t *max);

/**
 * binary_tree_is_bst - Checks if a binary tree
 * is a valid Binary Search Tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_helper(tree, NULL, NULL));
}

/**
 * is_bst_helper - Helper function to
 * recursively check if a tree is a BST.
 * @tree: A pointer to the current node.
 * @min: The minimum value a node in the subtree can have.
 * @max: The maximum value a node in the subtree can have.
 *
 * Return: 1 if the subtree is a valid BST, 0 otherwise.
 */
int is_bst_helper(const binary_tree_t *tree,
		const binary_tree_t *min, const binary_tree_t *max)
{
	if (tree == NULL)
		return (1);

	if ((min != NULL && tree->n <= min->n) ||
			(max != NULL && tree->n >= max->n))
		return (0);

	return (is_bst_helper(tree->left, min, tree) &&
			is_bst_helper(tree->right, tree, max));
}
