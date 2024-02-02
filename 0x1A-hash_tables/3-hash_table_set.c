#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_set - adds an element to the hash table
 * @ht: the hash table to add or update the key/value to
 * @key: the key (cannot be an empty string)
 * @value: the value associated with the key (must be duplicated)
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	if (!ht || !key || !*key)
		return (0);

	unsigned long int index = key_index((unsigned char *)key, ht->size);
	hash_node_t *current = ht->array[index];

	while (current && strcmp(current->key, key) && (current = current->next));

	if (current)
		return (update_node_value(current, value));

	hash_node_t *new_node = malloc(sizeof(hash_node_t));
	if (!new_node || !(new_node->key = strdup(key)) ||
			!(new_node->value = strdup(value)))
	{
		free(new_node);
		return (0);
	}
	new_node->next = ht->array[index];
       	ht->array[index] = new_node;
	return (1);
}
