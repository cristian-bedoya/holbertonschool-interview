#include "lists.h"

/**
 * find_listint_loop - find the loop in a linked list.
 * @head: pointer to a pointer to a list to the first element of a list.
 * Return: addrress of the node wherer the loop starts, or NULL if no node.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *fast;
	listint_t *slow;

	if (head == NULL)
		return (NULL);

	fast = head;
	slow = head;

	while (fast != NULL && fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (fast);
		}
	}
	return (NULL);
}
