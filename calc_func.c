#include "monty.h"

/**
 * add_instruct - adds the top 2 elements of the stack result is stored
 * in the second top element and the top element is removed
 * @stack: double pointer to stack_t, stack
 * @line_number: unsigned int; current line
 *
 * Return: Nothing
 * TheOwl
 */
void add_instruct(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp2, *tmp1;

	if ((*stack == NULL) || ((*stack)->next == NULL && (*stack)->prev == NULL))
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp2 = traverse(*stack);
	tmp1 = tmp2->prev;
	/* addition of 2 top elements */
	tmp1->n = tmp2->n + tmp1->n;
	/* delete top element and free space */
	tmp1->next = NULL;
	free(tmp2);
}
