#include "hash_tables.h"
/**
 * hash_table_create - creat a the hash table
 * @size: Size of hash table
 *
 * Return: ptr
 */

hash_table_t *hash_table_create(unsigned long int size)
{
hash_table_t *sh_tab;
unsigned long int s;

sh_tab = malloc(sizeof(hash_table_t));
if (sh_tab == NULL)
return (NULL);

sh_tab->size = size;
sh_tab->array = malloc(size * sizeof(hash_node_t *));
if (sh_tab->array == NULL)
{
free(sh_tab);
return (NULL);
}

for (s = 0; s < size; s++)
sh_tab->array[s] = NULL;

return (sh_tab);
}
