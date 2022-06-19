#include "monty.h"

/**
 * push_instruct - pushes an element to the stack
 * @stack: double pointer to stack_t, stack
 * @line_number: unsigned int; current line
 *
 * Return: nothing
 * TheOwl
 */
void push_instruct(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *tmp;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		free(new);
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/* check if argument is a number */
	arg_checker();
	if (monty_var.cur_arg == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* initialize new node */
	new->n = atoi(monty_var.cur_arg);
	new->next = NULL;
	/* if new is first node */
	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
		return;
	}
	/* if new is not first node */
	tmp = traverse(*stack);
	new->prev = tmp;
	tmp->next = new;
	monty_var.cur_arg = NULL;
}

/**
 * pop_instruct - removes the top element of stack
 * @stack: double pointer to stack_t, stack
 * @line_number: unsigned int; current line
 *
 * Return: nothing
 * TheOwl
 */
void pop_instruct(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* if only one node */
	if ((*stack)->prev == NULL && (*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
		return;
	}
	/* traversing and removing the top of the stack */
	tmp = traverse(*stack);
	(tmp->prev)->next = NULL;
	free(tmp);
}
