#include "binary_trees.h"

/**
 * create_node - creates an avl_t node
 * @val: value of the node
 * @parent: parent of the new node
 *
 * Return: pointer to the newly created node
 */
avl_t *create_node(int val, avl_t *parent)
{
	avl_t *new = malloc(sizeof(avl_t));

	if (!new)
		return (NULL);
	new->n = val;
	new->left = NULL;
	new->right = NULL;
	new->parent = parent;
	return (new);
}

/**
 * construct_tree - Recursive function that constructs
 * a balanced tree based on a sorted array
 * @parent: parent node
 * @array: array of ints
 * @l: index used as left boundary
 * @r: index used as right boundary
 *
 * Return: pointer to the root node of the created tree
 */
avl_t *construct_tree(avl_t *parent, int *array, int l, int r)
{
	avl_t *new;
	int m = (r - l) / 2 + l;

	if (l > r)
		return (NULL);
	new = create_node(array[m], parent);
	if (!new)
		return (NULL);
	new->left = construct_tree(new, array, l, m - 1);
	new->right = construct_tree(new, array, m + 1, r);

	return (new);
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: a pointer to the root node of the created AVL tree or NULL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	int l = 0;
	int r = size - 1;

	root = construct_tree(root, array, l, r);
	if (!root)
		return (NULL);
	return (root);
}
