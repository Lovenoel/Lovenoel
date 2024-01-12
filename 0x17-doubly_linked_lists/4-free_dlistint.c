#include <stdlib.h>
#include "lists.h"

/**
 * free_dlistint - frees a dlistint list
 * @head: pointer to the head of the node
 * Return: frees the address
 */
void free_dlistint(dlistint_t *head)
{
    dlistint_t *current = head;
    while (current != NULL)
    {
        dlistint_t *next = current->next; /* Save the next node before freeing the current node*/
        free(current);                    /* Free the current node*/
        current = next;                   /* Move to the next node*/
    }
}
