#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a doubly linked list.
 * @head: Pointer to the pointer to the head of the doubly linked list.
 * @n: Data for the new node.
 *
 * Return: Address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node, *temp;

	if (head == NULL)
	{
		return (NULL);
		/* Allocate memory for the new node */
		new_node = malloc(sizeof(dlistint_t));
	}
	if (new_node == NULL)
	{
		return (NULL);
		/* Set the data of the new node */
		new_node->n = n;
		new_node->next = NULL;
	}
	/* Handle the case where the list is empty */
	if (*head == NULL) 
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	/* Traverse the list to find the last node*/
	temp = *head;
	while (temp->next != NULL) 
	{
		temp = temp->next;
	}
	/* Update pointers to add the new node at the end */
	new_node->prev = temp;
	temp->next = new_node;

	return (new_node);
}
