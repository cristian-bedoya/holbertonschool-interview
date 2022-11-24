#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * is_binary_search_tree - checks if tree is a binary search tree
 * @node: current node being checked
 * @min: integer indicating the left boundary of the current node's value
 * @max: integer indicating the right boundary of the current node's value
 * @height: height of the current binary tree level
 * (curr value needs to be <= max and >= min)
 * Return: 1 if tree is a valid BST otherwise 0
 */
int is_binary_search_tree(const binary_tree_t *node, int min, int max,
		int *height)
{
	int left_h = 0;
	int right_h = 0;

	if (!node)
		return (1);

	if (node->n >= max || node->n <= min)
		return (0);

	if (!is_binary_search_tree(node->left, min, node->n, &left_h) ||
			!is_binary_search_tree(node->right, node->n,
				max, &right_h))
		return (0);
	*height = (left_h > right_h ? left_h : right_h) + 1;
	return (abs(left_h - right_h) < 2);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer tot the root node of the tree to check
 * Return: 1 if tree is a valid AVL, otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (!tree)
		return (0);
	return (is_binary_search_tree(tree, INT_MIN, INT_MAX, &height));
}
