#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * add_dnodeint - add a new node at the beginning of a dlistint_t list.
 * @head: pointer to the node
 * @n: the integer
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
    /* Create a new node*/
    dlistint_t *new = malloc(sizeof(dlistint_t));

    if (new == NULL)
        return (NULL); /* Return NULL if memory allocation fails*/
    new->n = n;        /* Assign the value to the new node*/
    new->prev = NULL;  /* Set the previous pointer of the new node to NULL*/
    if (*head != NULL)
    {
        new->next = *head;
        (*head)->prev = new; /* Update the previous pointer of the current head*/
    }
    else
    {
        new->next = NULL; /* Set the next pointer of the new node to NULL*/
    }
    *head = new;  /* Update the head pointer to point to the new node*/
    return (new); /* Return the address of the new element*/
}
