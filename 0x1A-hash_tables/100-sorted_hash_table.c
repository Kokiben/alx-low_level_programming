#include "hash_tables.h"

/**
 * shash_table_create - Sort hash table
 * @size: size of hash
 *
 * Return: ptr to new hash, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
shash_table_t *shi;
unsigned long int j;

shi = malloc(sizeof(shash_table_t));
if (shi == NULL)
return (NULL);
shi->size = size;
shi->shead = NULL;
shi->stail = NULL;
shi->array = malloc(size * sizeof(shash_node_t));
if (shi->array == NULL)
{
free(shi);
return (NULL);
}
for (j = 0; j < size; j++)
{
shi->array[j] = NULL;
}
return (shi);
}

/**
 * hash_new - The sorted hash table
 * @key: data
 * @value: data to stor
 *
 * Return: ptr to new hash, or NULL on failure
 */
shash_node_t *hash_new(const char *key, const char *value)
{
shash_node_t *sht;

sht = malloc(sizeof(shash_node_t));
if (sht == NULL)
return (NULL);
sht->key = strdup(key);
if (sht->key == NULL)
{
free(sht);
return (NULL);
}
sht->value = strdup(value);
if (sht->value == NULL)
{
free(sht->key);
free(sht);
return (NULL);
}
sht->next = sht->snext = sht->sprev = NULL;
return (sht);
}

/**
 * addsortt_list - add to sort
 * @tab: Sort hash table
 * @nd: To add
 *
 * Return: void
 */
void addsortt_list(shash_table_t *tab, shash_node_t *nd)
{
shash_node_t *mp;

if (tab->shead == NULL && tab->stail == NULL)
{
tab->shead = tab->stail = nd;
return;
}
mp = tab->shead;
while (mp != NULL)
{
if (strcmp(nd->key, mp->key) < 0)
{
nd->snext = mp;
nd->sprev = mp->sprev;
mp->sprev = nd;
if (nd->sprev != NULL)
nd->sprev->snext = nd;
else
tab->shead = nd;
return;
}
mp = mp->snext;
}
nd->sprev = tab->stail;
tab->stail->snext = nd;
tab->stail = nd;
}

/**
 * shash_table_set - sets key to value
 * @ht: Sort
 * @key: To data
 * @value: To add
 *
 * Return: 1 on success, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
unsigned long int in;
char *n_va;
shash_node_t *sht, *mp;

if (ht == NULL || ht->array == NULL || ht->size == 0 ||
key == NULL || strlen(key) == 0 || value == NULL)
return (0);
in = key_index((const unsigned char *)key, ht->size);
mp = ht->array[in];
while (mp != NULL)
{
if (strcmp(mp->key, key) == 0)
{
n_va = strdup(value);
if (n_va == NULL)
return (0);
free(mp->value);
mp->value = n_va;
return (1);
}
mp = mp->next;
}
sht = hash_new(key, value);
if (sht == NULL)
return (0);
sht->next = ht->array[in];
ht->array[in] = sht;
addsortt_list(ht, sht);
return (1);
}

/**
 * shash_table_get - get value.
 * @ht: hash table
 * @key: To data
 *
 * Return: value with key, or NULL on failure
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
unsigned long int in;
shash_node_t *mp;

if (ht == NULL || ht->array == NULL || ht->size == 0 ||
key == NULL || strlen(key) == 0)
return (NULL);
in = key_index((const unsigned char *)key, ht->size);
mp = ht->array[in];
while (mp != NULL)
{
if (strcmp(mp->key, key) == 0)
return (mp->value);
mp = mp->next;
}
return (NULL);
}

/**
 * shash_table_print - Sorted hash table
 * @ht: to print
 *
 * Return: void
 */
void shash_table_print(const shash_table_t *ht)
{
shash_node_t *mp;
char fg = 0;

if (ht == NULL || ht->array == NULL)
return;
printf("{");
mp = ht->shead;
while (mp != NULL)
{
if (fg == 1)
printf(", ");
printf("'%s': '%s'", mp->key, mp->value);
fg = 1;
mp = mp->snext;
}
printf("}\n");
}

/**
 * shash_table_print_rev - Sorted hash table in reverse
 * @ht: To print
 *
 * Return: void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
shash_node_t *mp;
char fg = 0;

if (ht == NULL || ht->array == NULL)
return;
printf("{");
mp = ht->stail;
while (mp != NULL)
{
if (fg == 1)
printf(", ");
printf("'%s': '%s'", mp->key, mp->value);
fg = 1;
mp = mp->sprev;
}
printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted.
 * @ht: To delete
 *
 * Return: void
 */
void shash_table_delete(shash_table_t *ht)
{
unsigned long int j;
shash_node_t *n;
if (ht == NULL || ht->array == NULL || ht->size == 0)
return;
for (j = 0; j < ht->size; j++)
{
while (ht->array[j] != NULL)
{
n = ht->array[j]->next;
free(ht->array[j]->key);
free(ht->array[j]->value);
free(ht->array[j]);
ht->array[j] = n;
}
}
free(ht->array);
ht->array = NULL;
ht->shead = ht->stail = NULL;
ht->size = 0;
free(ht);
}
