#include "search.h"
/**
 * print_found - print message
 * @f_idx: first_idx
 * @s_idx: second_idx
 * @end: know if the last one in express line
 *
 * Return: nothing
 */
void print_found(size_t f_idx, size_t s_idx, skiplist_t *end)
{
	if (end != NULL)
	{
		while (end->next != NULL)
			end = end->next;
		s_idx = end->index;
	}
	printf("Value found between indexes [%lu] and [%lu]\n", f_idx, s_idx);
}
/**
 * print_check - print message
 * @idx: index
 * @value: value
 *
 * Return: nothing
 */
void print_check(size_t idx, int value)
{
	printf("Value checked at index [%lu] = [%i]\n", idx, value);
}
/**
 * find_each - check next by next
 * @head: express line node
 * @value: value to compare
 *
 * Return: node found
 */
skiplist_t *find_each(skiplist_t *head, int value)
{
	skiplist_t *current = head;

	if (head == NULL)
		printf("n head nullll");
	for (; current; current = current->next)
	{
		print_check(current->index, current->n);
		if (current->n == value)
			return (current);
	}
	return (NULL);
}
/**
 * linear_skip - found a value in skip list
 * @head: express line node
 * @value: value to compare
 *
 * Return: node found
 */
skiplist_t *linear_skip(skiplist_t *head, int value)
{
	skiplist_t *current  = head, *next = NULL;

	if (head == NULL)
		return (NULL);

	while (current != NULL)
	{
		next = current->express;
		if (next != NULL)
		{
			print_check(next->index, next->n);
			if (next->n >= value)
			{
				print_found(current->index, next->index, NULL);
				return (find_each(current, value));
			}

			if (next->express == NULL)
			{
				print_found(next->index, 0, next);
				return (find_each(next, value));
			}
		}
		current = current->express;
	}
	return (NULL);
}
