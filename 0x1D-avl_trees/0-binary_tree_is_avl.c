#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * is_binary_search_tree - docs
 * @node: current node
 * @min: min value
 * @max: max value
 * @height: height
 * Return: 1 if is valid otherwise 0
 */
int is_binary_search_tree(const binary_tree_t *node, int min, int max,
		int *height)
{
	int left = 0;
	int right = 0;

	if (!node)
		return (1);

	if (node->n >= max || node->n <= min)
		return (0);

	if (!is_binary_search_tree(node->left, min, node->n, &left) ||
			!is_binary_search_tree(node->right, node->n,
				max, &right))
		return (0);
	*height = (left > right ? left : right) + 1;
	return (abs(left - right) < 2);
}

/**
 * binary_tree_is_avl - checks a binary tree
 * @tree: root
 * Return: 1 if is valid otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (!tree)
		return (0);
	return (is_binary_search_tree(tree, INT_MIN, INT_MAX, &height));
}
