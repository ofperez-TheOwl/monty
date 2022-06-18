#include "monty.h"

/**
 * free_dlistint - frees all elements of a doubly linked list
 * @head: pointer to stack_t; first node of list
 *
 * Return: nothing
 * TheOwl
 */
void free_dlistint(stack_t *head)
{
	/* base case */
	if (head == NULL)
	{
		free(head);
		return;
	}
	if (head->next == NULL)
	{
		free(head->next);
		return;
	}
	/* recursive instructions */
	free_dlistint(head->next);
	free(head->next);
	if (head->prev == NULL)
	{
		free(head->prev);
		free(head);
	}
}
