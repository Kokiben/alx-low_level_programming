#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
* main - check code
* 
* Return: Always 0.
*/
int main(void)
{
listint_t *tip;
listint_t *new;
listint_t hi = {8, NULL};
size_t m;

tip = &hi;
new = malloc(sizeof(listint_t));
if (new == NULL)
{
printf("Error\n");
return (1);
}
new->n = 9;
new->next = tip;
tip = new;
m = print_listint(tip);
printf("-> %lu elements\n", m);
free(new);
return (0);
}
