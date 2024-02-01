#include "hash_tables.h"
/**
 * hash_table_delete -  a function that deletes a hash table.
 * @ht: To delete.
 */

void hash_table_delete(hash_table_t *ht)
{
hash_node_t *curr_n, *tmp_n;
unsigned long int j;

if (ht == NULL || ht->array == NULL || ht->size == 0)
return;

for (j = 0; j < ht->size; j++)
{
curr_n = ht->array[j];

while (curr_n != NULL)
{
tmp_n = curr_n->next;
free(curr_n->key);
free(curr_n->value);
free(curr_n);
curr_n = tmp_n;
}
}
free(tmp_n);
free(curr_n);
free(ht->array);
ht->array = NULL;
ht->size = 0;
free(ht);
}
