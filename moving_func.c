#include "monty.h"

/**
 * swap_instruct - top stack element takes the place of second
 * top stack element and vice verse
 * @stack: double pointer to stack_t, stack
 * @line_number: unsigned int; current line
 *
 * Return: Nothing
 * TheOwl
 */
void swap_instruct(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp0, *tmp1, *tmp2;

	if ((*stack == NULL) || ((*stack)->next == NULL && (*stack)->prev == NULL))
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		error_freeing();
		exit(EXIT_FAILURE);
	}
	tmp2 = traverse(*stack);
	tmp1 = tmp2->prev;
	tmp0 = tmp1->prev;
	/* swaping if only 2 nodes in list */
	if (tmp0 == NULL)
	{
		tmp2->next = tmp2->prev;
		tmp1->prev = tmp1->next;
		tmp1->next = NULL;
		tmp2->prev = NULL;
		*stack = tmp2;
		return;
	}
	/* swaping for any other case */
	tmp2->next = tmp1;
	tmp0->next = tmp2;
	tmp2->prev = tmp0;
	tmp1->next = NULL;
	tmp1->prev = tmp2;
}
