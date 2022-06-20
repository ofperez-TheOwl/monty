#include "monty.h"

/**
 * pall_instruct - print all element of the stack
 * @stack: double pointer to stack_t, stack
 * @line_number: unsigned int; current line
 *
 * Return: nothing
 * TheOwl
 */
void pall_instruct(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!line_number)
		return;
	if (*stack == NULL)
		return;
	if ((*stack)->prev == NULL && (*stack)->next == NULL)
	{
		printf("%d\n", (*stack)->n);
		return;
	}
	tmp = traverse(*stack);
	while (tmp->prev != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->prev;
	}
	printf("%d\n", tmp->n);
}

/**
 * pint_instruct - print the first element of stack
 * @stack: double pointer to stack_t, stack
 * @line_number: unsigned int; current line
 *
 * Return: nothing
 * TheOwl
 */
void pint_instruct(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* if only one node */
	if ((*stack)->prev == NULL && (*stack)->next == NULL)
	{
		printf("%d\n", (*stack)->n);
		return;
	}
	/* traversing before print the top of the stack */
	tmp = traverse(*stack);
	printf("%d\n", tmp->n);
}

/**
 * pchar_instruct - print the char at the top of the stack
 * @stack: double pointer to stack_t, stack
 * @line_number: unsigned int; current line
 *
 * Return: nothing
 * TheOwl
 */
void pchar_instruct(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* traversing before print the top of the stack */
	tmp = traverse(*stack);
	printf("traverse completed\n");
	if (tmp->n >= 0 && tmp->n <= 127)
		printf("%c\n", tmp->n);
	dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n", line_number);
	exit(EXIT_FAILURE);
}
