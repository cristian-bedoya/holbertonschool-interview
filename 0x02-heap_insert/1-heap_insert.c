#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_size - binary tree size
 * @tree_node:tree node
 * Return: the tree_node size
 */
size_t binary_tree_size(const binary_tree_t *tree_node)
{
	int size_left, size_right, total_size;

	if (!tree_node)
		return (0);

	size_left = binary_tree_size(tree_node->left);
	size_right = binary_tree_size(tree_node->right);
	total_size = size_left + size_right;
	return (total_size + 1);
}

/**
 * binary_tree_is_full - checks if a binary tree_node is full
 * @tree_node: pointer to the node_root node of the tree_node to check
 * Return: 1 if it is null, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree_node)
{
	if (!tree_node)
		return (0);

	if (!tree_node->left && !tree_node->right)
		return (1);

	return (binary_tree_is_full(tree_node->left) &&
		binary_tree_is_full(tree_node->right));
}

/**
 * binary_tree_is_perfect - checks if a binary tree_node is perfect
 * @tree_node: pointer to the node_root node of the tree_node to check
 * Return: 1 if it is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree_node)
{
	int left_nodes, right_nodes;

	if (!tree_node)
		return (0);

	left_nodes = binary_tree_size(tree_node->left);
	right_nodes = binary_tree_size(tree_node->right);

	if (binary_tree_is_full(tree_node) && (left_nodes == right_nodes))
		return (1);

	return (0);
}

/**
 * find_node_parent - finds the parent node
 * @node_root: double pointer to the node_root node
 * Return: a pointer to the parent node
 */
heap_t *find_node_parent(heap_t *node_root)
{
	heap_t *p;
	int l, r, ld, rd;

	if (!node_root)
		return (NULL);

	p = node_root;
	l = binary_tree_size(p->left);
	r = binary_tree_size(p->right);
	ld = binary_tree_is_perfect(p->left);
	rd = binary_tree_is_perfect(p->right);
	if (!l || !r)
		return (p);
	if (!ld || (ld && rd && l == r))
		return (find_node_parent(p->left));
	else if (!rd || (ld && rd && l > r))
		return (find_node_parent(p->right));
	return (p);
}

/**
 * swap_node - swaps the nodes
 * @node: pointer to the node
 */
void swap_node(heap_t **node)
{
	heap_t *current;
	int tmp;

	current = *node;
	while (current->parent)
	{
		if (current->parent->n < current->n)
		{
			tmp = current->parent->n;
			current->parent->n = current->n;
			current->n = tmp;
			*node = current->parent;
		}
		current = current->parent;
	}
}

/**
 * heap_insert -  max-heap
 * @node_root:  node_root.
 * @node_value: node_value
 * Return: return a pointer
 */
heap_t *heap_insert(heap_t **node_root, int node_value)
{
	heap_t *new;
	heap_t *parent;

	parent = find_node_parent(*node_root);
	new = binary_tree_node(parent, node_value);
	if (!new)
		return (NULL);
	if (!parent)
		*node_root = new;
	else if (!parent->left)
		parent->left = new;
	else
		parent->right = new;
	swap_node(&new);
	return (new);
}
