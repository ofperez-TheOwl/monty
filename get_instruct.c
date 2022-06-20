#include "monty.h"

/**
 * comment_checker - identify comment lines
 * @buffer: pointer to char; a line of mounty file
 *
 * Return: int; 1 if comment line 0 if not
 * TheOwl
 */
int comment_checker(char *buffer)
{
	int i = 0;

	while (buffer[i] == ' ' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '#')
		return (1);
	return (0);
}

/**
 * get_instruction - identify opcode with argument
 * and its C function from a line
 * @buffer: pointer to char; a line of mounty file
 *
 * Return: instruction_t; opcode and its related C function
 * TheOwl
 */
instruction_t get_instruction(char *buffer)
{
	size_t i = 0, j = 0, l = 0, m = 0;
	int k = 0;
	instruction_t *cmd_list = monty_var.instruct;

	while (buffer[i] == ' ') /* clear first spaces */
		i++;
	while (buffer[i + j] != ' ' && buffer[i + j] != '\0') /* get length of opcode */
		j++;
	/* extract instruct */
	while (cmd_list[k].opcode != NULL)
	{
		if (strncmp(cmd_list[k].opcode, buffer + i, j) == 0)
		{
			/* extract argument*/
			while (buffer[i + j + m] == ' ') /* clear spaces after opcode */
				m++;
			while (buffer[i + j + + m + l] != ' ' && buffer[i + j + m + l] != '\0')
				l++;
			buffer[i + j + m + l] = '\0';
			if (l != 0)
				monty_var.cur_arg = buffer + i + j + l;
			return (cmd_list[k]);
		}
		k++;
	}
	dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", monty_var.cur_line, buffer + i);
	free(buffer);
	error_freeing();
	exit(EXIT_FAILURE);
}
