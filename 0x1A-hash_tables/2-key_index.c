#include "hash_tables.h"

/**
 * key_index - Obtain the index for storing a key/value pair
 *      in the array of a hash table.
 * @key: The key for which to determine the index.
 * @size: The size of the hash table's array.
 *
 * Return: The computed index for the given key.
 * Description: Implements the djb2 algorithm for indexing.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
unsigned long int shkey = hash_djb2(key);

return (shkey % size);
}
