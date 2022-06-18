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
	int i = 0;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		free(new);
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/* check if argument is a number */
	if (monty_var.cur_arg != NULL)
	{
		while (monty_var.cur_arg[i] != '\0')
		{
			printf("check argument\n");
			if (monty_var.cur_arg[i] < '0' || monty_var.cur_arg[i] > '9')
			{
				monty_var.cur_arg = NULL;
				break;
			}
			i++;
		}
	}
	if (monty_var.cur_arg == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("argument is %s\n", monty_var.cur_arg);
	/* initialize new node */
	new->n = atoi(monty_var.cur_arg);
	new->next = NULL;
	/* if new is first node */
	if (*stack == NULL)
	{
		printf("first node\n");
		new->prev = NULL;
		*stack = new;
		return;
	}
	printf("not first node\n");
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

	if (line_number < 2)
		return;
	if (*stack == NULL)
		return;
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
