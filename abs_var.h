#ifndef ABS_VAR_H
#define ABS_VAR_H

/* prototypes of funtions related to opcodes */
void push_instruct(stack_t **stack, unsigned int line_number);
void pall_instruct(stack_t **stack, unsigned int line_number);
void pint_instruct(stack_t **stack, unsigned int line_number);
void pop_instruct(stack_t **stack, unsigned int line_number);
void swap_instruct(stack_t **stack, unsigned int line_number);
void add_instruct(stack_t **stack, unsigned int line_number);
void sub_instruct(stack_t **stack, unsigned int line_number);
void div_instruct(stack_t **stack, unsigned int line_number);
void mul_instruct(stack_t **stack, unsigned int line_number);
void mod_instruct(stack_t **stack, unsigned int line_number);
void pchar_instruct(stack_t **stack, unsigned int line_number);


/* definition of global variable */
stack_t *stack_start = NULL;
abs_var monty_var = {
	0,
	NULL,
	NULL,
	NULL,
	{
		{"push", push_instruct},
		{"pall", pall_instruct},
		{"pint", pint_instruct},
		{"pop", pop_instruct},
		{"swap", swap_instruct},
		{"add", add_instruct},
		{"nop", NULL},
		{"sub", sub_instruct},
		{"div", div_instruct},
		{"mul", mul_instruct},
		{"mod", mod_instruct},
		{"pchar", pchar_instruct},
		{NULL, NULL}
	},
	&stack_start,
};
#endif
