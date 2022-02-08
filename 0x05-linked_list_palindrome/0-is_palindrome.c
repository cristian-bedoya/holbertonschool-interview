#include "lists.h"
/**
 * reverse - reverses a linked list nodes
 * @head: node to the first node in a linked list
 * Return: pointer to the first node in the reversed linked list
 */
listint_t *reverse(listint_t *head)
{
	listint_t *t = head;
	listint_t *curr = head;
	listint_t *prev = NULL;

	while (t)
	{
		t = curr->next;
		curr->next = prev;
		prev = curr;
		curr = t;
	}
	return (prev);
}
/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to the first node in a linked list
 * Return: 1 if its a palindrome, 0 if it isn't
 */
int is_palindrome(listint_t **head)
{
	listint_t *s, *f, *curr, *rev;

	curr = *head;
	s = *head;
	f = *head;
	while (curr && f->next && f->next->next)
	{
		s = s->next;
		f = f->next->next;
	}
	rev = reverse(s);
	while (rev && curr)
	{
		if (rev->n != curr->n)
			return (0);

		rev = rev->next;
		curr = curr->next;
	}
	return (1);
}
