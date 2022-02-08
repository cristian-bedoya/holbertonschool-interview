#include "lists.h"


int pali_recursion (listint_t **head, listint_t *right)
{
	int res = 0;

	// Last node is found
	if (right == NULL)
		return (1);
	// Recursively find the last node and check each ret value
	if (!pali_recursion(head, right->next))
	    return (0);
	// Ched node values
	if (right->n == (*head)->n)
	{
		res = 1;
	}

	*head = (*head)->next;
	return res;
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to the first node in a linked list
 * Return: 1 if its a palindrome, 0 if it isn't
 */
int is_palindrome_rec(listint_t **head)
{
	return pali_recursion(head, *head);
}

