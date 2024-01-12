#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: pointer to the node
 * @n: an integer
 * Return: address of the new element
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	/* Create a new memory for new node*/
	dlistint_t *new_address = malloc(sizeof(dlistint_t));

	if (new_address == NULL)
		return (NULL); /* Return NULL if memory allocation fails*/
	new_address->n = n;
	/* The new will be the last node, so its next pointer is NULL*/
	new_address->next = NULL;
	if (*head == NULL)
	{
		/* If the list is empty, set the previous pointer to NULL*/
		new_address->prev = NULL;
		*head = new_address; /* Update the head to point to the new*/
	}
	else
	{
		dlistint_t *current = *head;

		while (current->next != NULL)
		{
			current = current->next; /* Traverse to the last node*/
			/* Link the last node's next pointer to the new node*/
			current->next = new_address;
			new_address->prev = current; /* Set the previous pointer of the new node*/
		}
	}
	return (new_address); /* Return the address of the new element*/
}
