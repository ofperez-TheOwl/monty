#ifndef ABS_VAR_H
#define ABS_VAR_H

/* prototypes of funtions related to opcodes */
void push_instruct(stack_t **stack, unsigned int line_number);
void pall_instruct(stack_t **stack, unsigned int line_number);
void pint_instruct(stack_t **stack, unsigned int line_number);


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
		{NULL, NULL}
	},
	&stack_start,
};
#endif
