#include "monty.h"

/**
 * traverse - traverse doubly linked list to last element
 * @stack: pointer to stack_t; head of the list to traverse
 *
 * Return: pointer to stack_t; last element of the list
 * TheOwl
 */
stack_t *traverse(stack_t *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/**
 * arg_checker - check argument of opcode
 *
 * Return: nothing
 * TheOwl
 */
void arg_checker(void)
{
	int i = 0;

	if (monty_var.cur_arg != NULL)
	{
		while (monty_var.cur_arg[i] != '\0')
		{
			if (monty_var.cur_arg[i] < '0' || monty_var.cur_arg[i] > '9')
			{
				monty_var.cur_arg = NULL;
				break;
			}
			i++;
		}
	}
}

/**
 * free_stack - frees all elements of a doubly linked list
 * @head: pointer to stack_t; first node of list
 *
 * Return: nothing
 * TheOwl
 */
void free_stack(stack_t *head)
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
	free_stack(head->next);
	free(head->next);
	if (head->prev == NULL)
	{
		free(head->prev);
		free(head);
	}
}
