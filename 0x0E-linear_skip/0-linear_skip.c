#include "search.h"

/**
 * check_in_list - checks if value equals value of node after getting
 * the right boundaries.
 * @list: pointer to the head of the skip list to search in.
 * @value: value to search for
 * @last: pointer to the last node of defining the boundary.
 *
 * Return: pointer to the first node where value is located
 */
skiplist_t *check_in_list(skiplist_t *list, int value, skiplist_t *last)
{
	while (list)
	{
		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
		if (list->n == value)
			return (list);
		if (list->index == last->index)
			break;
		list = list->next;
	}
	return (NULL);
}

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in.
 * @value: value to search for
 *
 * Return: pointer to the first node where value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *last;

	while (list)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				list->express->index, list->express->n);
		if (list->express->n >= value)
		{
			last = list->express;
			printf("Value found between indexes [%lu] and [%lu]\n",
					list->index, last->index);
			return (check_in_list(list, value, last));
		}
		list = list->express;
		if (!list->express)
		{
			last = list;
			while (last->next)
				last = last->next;
			printf("Value found between indexes [%lu] and [%lu]\n",
					list->index, last->index);
			return (check_in_list(list, value, last));
		}
	}
	return (NULL);
}
