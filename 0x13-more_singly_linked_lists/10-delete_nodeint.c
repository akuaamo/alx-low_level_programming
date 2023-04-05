#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes a node at a given position.
 * @head: Pointer to a pointer to the first node.
 * @index: Index of the node to delete (starting from 0).
 * Return: 1 if the operation succeeded, or -1 otherwise.
 **/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *temp;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		temp = *head;
		*head = temp->next;
		free(temp);
		return (1);
	}

	current = *head;
	for (i = 0; current != NULL && i < index - 1; i++)
		current = current->next;

	if (current == NULL || current->next == NULL)
		return (-1);

	temp = current->next;
	current->next = temp->next;
	free(temp);

	return (1);
}

