#include "lists.h"

/**
 * check_cycle - function that checks the single
 * linked pointer for a cycle
 *
 * @pointer: pointer.
 *
 * Return: 0 true or 1 false.
 */

int check_cycle(listint_t *pointer)
{

	listint_t *t, *h;

	if (!pointer)
		return (0);

	t = pointer;
	h = pointer;

	while (t && h && h->next)
	{
		t = t->next;
		h = h->next->next;

		if (h == t)
			return (1);
	}

	return (0);
}
