#include "hash_tables.h"

/**
 * hash_table_print - prints.
 * @ht: ptr to hash table.
 *
 * Description: Printed in order
 *              they appear in array of hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
hash_node_t *n;
unsigned long int s;
unsigned char fg = 0;

if (ht == NULL)
return;

printf("{");
for (s = 0; s < ht->size; s++)
{
if (ht->array[s] != NULL)
{
if (fg == 1)
printf(", ");

n = ht->array[s];
while (n != NULL)
{
printf("'%s': '%s'", n->key, n->value);
n = n->next;
if (n != NULL)
printf(", ");
}
fg = 1;
}
}
printf("}\n");
}
