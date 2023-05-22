#include "dog.h"

/**
* init_dog - intializes a variable of type struct dog
* @d: pointer to structure
* @name: name to intialize
* @age: age to intialize
* @owner: owner to intialize
*
* Return: void
*/
void init_dog(struct dog *d, char *name, float age, char *owner)
{
if (d)
{
d->name = name;
d->age = age;
d->owner = owner;
}
}
