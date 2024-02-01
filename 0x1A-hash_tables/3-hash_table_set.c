#include "hash_tables.h"

/**
 * hash_table_set - Inserts an entry into hash table
 * @ht: Ptr to hash table
 * @key: Key entry into a hash table.
 * @value: Value entry into a hash table.
 *
 * Return: 1 (success) 0 (failure)
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
unsigned long int in;
hash_node_t *n_tmp, *curr_n;

if (ht == NULL || ht->array == NULL || ht->size == 0 ||
key == NULL || strlen(key) == 0 || value == NULL)
return (0);

in = key_index((unsigned char *)key, ht->size);

curr_n = ht->array[in];
while (curr_n != NULL)
{
if (strcmp(curr_n->key, key) == 0)
{
curr_n->value = strdup(value);
return (1);
}
curr_n = curr_n->next;
}

n_tmp = hash_new(key, value);
n_tmp->next = ht->array[in];
ht->array[in] = n_tmp;

return (1);
}

/**
 * new_node - create a new node
 * @key: node key
 * @value: node value
 *
 * Return: new node
 */

hash_node_t *hash_new(const char *key, const char *value)
{
hash_node_t *tmp_n;

tmp_n = malloc(sizeof(hash_node_t));

if (tmp_n == NULL)
return (NULL);

tmp_n->key = strdup(key);
if (tmp_n->key == NULL)
{
free(tmp_n);
return (NULL);
}
tmp_n->value = strdup(value);
if (tmp_n->value == NULL)
{
free(tmp_n->key);
free(tmp_n);
return (NULL);
}

tmp_n->next = NULL;

return (tmp_n);
}
