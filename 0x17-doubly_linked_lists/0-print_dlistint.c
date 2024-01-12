#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_dlistint - prints all the elements of a list
 * @h: the pointer to the node
 * Return: the number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t node_count = 0; /* To keep track of the number of nodes*/

	while (h != NULL)
	{
		printf("%d\n", h->n); /* Prints the value of the current node*/
		h = h->next; /* Move to the next node*/
		node_count++; /* Increment the node count*/
	}
	return (node_count);
}
