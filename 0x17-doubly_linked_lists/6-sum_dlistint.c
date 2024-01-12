#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * sum_dlistint - returns the sum of all the data (n)
 * of a dlistint_t linked list.
 * @head: - head of the list
 * Return: 0 when true
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	/* Traverse the linked list and accumulate the sum */
	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
