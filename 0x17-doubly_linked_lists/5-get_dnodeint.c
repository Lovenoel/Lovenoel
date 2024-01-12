#include <stdlib.h>
#include "lists.h"

/**
 * get_dnodeint_at_index -  returns the nth node of a dlistint_t linked list
 * @head: pointer of the head of the node
 * Return:the nth node of a list
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int count = 0; /* To keep track of the current node index*/

	while (head != NULL)
	{
		if (count == index)
			return (head); /*Return the node if the index matches*/
		head = head->next; /* Move to the next node*/
		count++;           /* Increment the count*/
	}

	return (NULL); /*Return NULL if the node at the given index doesn't exist*/
}
