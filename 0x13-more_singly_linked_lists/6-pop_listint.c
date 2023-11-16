#include "lists.h"

/**
 * pop_listint - deletes the head node of a linked list
 * @head: pointer to elelement in the linked list
 *
 * Return: the data inside the element that was deleted
 * or 0 if the list is empty
*/
int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int n;

	if (!head || !*head)
		return (0);
	n = (*head)->n;
	tmp = (*head)->next;
	free(*head);
	*head = tmp;

	return (n);
}
