#include "hash_tables.h"
#include <string.h>
#include <stdio.h>

/**
 * shash_table_create - creates a sorted hash table
 * @size: the size of the array
 * Return: a pointer to the created hash table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht;
    unsigned long int i;

    ht = malloc(sizeof(shash_table_t));
    if (ht == NULL)
        return (NULL);

    ht->size = size;
    ht->array = malloc(sizeof(shash_node_t *) * size);
    if (ht->array == NULL)
    {
        free(ht);
        return (NULL);
    }

    for (i = 0; i < size; i++)
        ht->array[i] = NULL;

    ht->shead = NULL;
    ht->stail = NULL;

    return (ht);
}

/**
 * shash_table_set - adds an element to the sorted hash table
 * @ht: the hash table
 * @key: the key
 * @value: the value associated with the key
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    shash_node_t *new_node, *current;

    if (ht == NULL || key == NULL || *key == '\0')
        return (0);

    index = key_index((unsigned char *)key, ht->size);
    current = ht->shead;

    while (current != NULL && strcmp(current->key, key) < 0)
        current = current->snext;

    if (current != NULL && strcmp(current->key, key) == 0)
    {
        free(current->value);
        current->value = strdup(value);
        if (current->value == NULL)
            return (0);
        return (1);
    }

    new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL)
        return (0);

    new_node->key = strdup(key);
    if (new_node->key == NULL)
    {
        free(new_node);
        return (0);
    }

    new_node->value = strdup(value);
    if (new_node->value == NULL)
    {
        free(new_node->key);
        free(new_node);
        return (0);
    }

    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    if (current == NULL)
    {
        new_node->sprev = ht->stail;
        new_node->snext = NULL;
        if (ht->stail != NULL)
            ht->stail->snext = new_node;
        ht->stail = new_node;
        if (ht->shead == NULL)
            ht->shead = new_node;
    }
    else
    {
        new_node->sprev = current->sprev;
        new_node->snext = current;
        if (current->sprev != NULL)
            current->sprev->snext = new_node;
        else
            ht->shead = new_node;
        current->sprev = new_node;
    }

    return (1);
}

/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: the hash table
 * @key: the key
 * Return: the value associated with the element, or NULL if key couldn’t be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int index;
    shash_node_t *current;

    if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);

    index = key_index((unsigned char *)key, ht->size);
    current = ht->array[index];

    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
            return (current->value);
        current = current->next;
    }

    return (NULL);
}

/**
 * shash_table_print - prints a sorted hash table
 * @ht: the hash table
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *current;

    if (ht == NULL)
        return;

    printf("{");
    current = ht->shead;
    while (current != NULL)
    {
        printf("'%s': '%s'", current->key, current->value);
        current = current->snext;
        if (current != NULL)
            printf(", ");
    }
    printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse order
 * @ht: the hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *current;

    if (ht == NULL)
        return;

    printf("{");
    current = ht->stail;
    while (current != NULL)
    {
        printf("'%s': '%s'", current->key, current->value);
        current = current->sprev;
        if (current != NULL)
            printf(", ");
    }
    printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: the hash table
 */
void shash_table_delete(shash_table_t *ht)
{
    shash_node_t *current, *temp;

    if (ht == NULL)
        return;

    current = ht->
}
