#include "hash_tables.h"

/**
 * hash_table_create - creates hash table
 * @size: Size of hash table
 *
 * Return: Ptr to new table
 */

hash_table_t *hash_table_create(unsigned long int size)
{
hash_table_t *sh_tab;
unsigned long int a;

sh_tab = malloc(sizeof(hash_table_t));
if (sh_tab == NULL)
return (NULL);

sh_tab->size = size;
sh_tab->array = malloc(sizeof(hash_node_t *) * size);
if (sh_tab->array == NULL)
{
free(sh_tab);
return (NULL);
}

for (a = 0; a < size; a++)
sh_tab->array[a] = NULL;

return (sh_tab);
}
