#include "lists.h"

/**
 * is_palindrome - Function that checks
 * if a singly linked list is a palindrome.
 *
 * @head: Double pointer to head of linked list.
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome.
 */

int is_palindrome(listint_t **head)
{
	int palindrome = 1, num_nodes = 1, i = 0, *arr = NULL;
	listint_t *ptr = NULL;

	if (head == NULL)
		return (0);
	if (*head == NULL)
		return (1);

	ptr = *head;
	while (ptr->next != NULL)
	{
		num_nodes += 1;
		ptr = ptr->next;
	}

	arr = malloc(num_nodes * sizeof(int));

	ptr = *head;
	while (ptr != NULL)
	{
		arr[i++] = ptr->n;
		ptr = ptr->next;
	}

	i = 0;
	while (i < num_nodes && palindrome == 1)
	{
		if (arr[i] != arr[num_nodes - 1 - i])
			palindrome = 0;
		i++;
	}

	free(arr);

	return (palindrome);
}