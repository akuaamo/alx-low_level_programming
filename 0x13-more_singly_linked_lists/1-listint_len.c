#include "lists.h"

/**
 * listint_len -counts number of elements in a linked listint_t
 * @h: List to check
 * Return: number of elements in list
 */
size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	for (; h != NULL; h = h->next)
		count++;

	return (count);
}
