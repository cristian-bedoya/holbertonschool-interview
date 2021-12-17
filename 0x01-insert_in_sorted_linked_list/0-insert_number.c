#include "lists.h"
/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: head
 * @number: number to be inserted
 *
 * Return: address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current, *new;
	int previus_number;

	current = *head;
	new = malloc(sizeof(listint_t));
	if (!new)
    {
		return (NULL);
    }

	if (!*head)
	{
		new->n = number;
		new->next = NULL;
		*head = new;
		return (new);
	}
	new->n = number;
	while (current)
	{
		previus_number = current->n;
		if (previus_number >= number)
		{
			new->next = current;
			*head = new;
			return (new);
		}
		else if(!current->next && previus_number <= number)
		{
			current->next = new;
			new->next = NULL;
			return (new);
		}
		else if (previus_number <= number && current->next->n >= number)
		{
			new->next = current->next;
			current->next = new;
			return (new);
		}
		current = current->next;
	}
	return (NULL);
}
