#include <stdlib.h>
#include <stdio.h>
#include "lists.h"
/**
 * dlistint_len - returns the number of
 * elements in a linked dlistint_t list.
 * @h: pointer to the node
 * Return: number of elements
 */
size_t dlistint_len(const dlistint_t *h)
{
    size_t num_elem = 0; /* To keep track of the number of nodes*/

    while (h != NULL)
    {
        num_elem++;  /* Incrementing the number of elements*/
        h = h->next; /* Move to the next node*/
    }
    return (num_elem);
}
