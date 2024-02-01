#include "hash_tables.h"
/**
 * hash_table_create - create a hash table
 * @size: size of the hash table
 *
 * Return: pointer to the new table
 */

hash_table_t *hash_table_create(unsigned long int size)
{
unsigned long int a;
hash_table_t *sh_tab;

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
