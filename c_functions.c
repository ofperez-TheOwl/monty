#include "monty.h"

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
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	new->prev = tmp;
	tmp->next = new;
	monty_var.cur_arg = NULL;
}


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

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO,"L%d: can't pall, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->prev == NULL && (*stack)->next == NULL)
	{
		printf("%d\n", (*stack)->n);
		return;
	}
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
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
		dprintf(STDERR_FILENO,"L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->prev == NULL && (*stack)->next == NULL)
	{
		printf("%d\n", (*stack)->n);
		return;
	}
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	printf("%d\n", tmp->n);
}
