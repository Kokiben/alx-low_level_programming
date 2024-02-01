#include "hash_tables.h"

/**
 * hash_table_get - Obtain the value associated with
 * a specified key in a hash table.
 * @ht: ptr to hash table.
 * @key: The key for which to retrieve the associated value.
 *
 * Returns: If the key cannot be found - NULL.
 *          Otherwise - the value associated with the specified key in the table.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
hash_node_t *n;
unsigned long int in;

if (ht == NULL || key == NULL || *key == '\0')
return (NULL);

in = key_index((const unsigned char *)key, ht->size);
if (in >= ht->size)
return (NULL);

n = ht->array[in];
while (n && strcmp(n->key, key) != 0)
n = n->next;

return ((n == NULL) ? NULL : n->value);
}
