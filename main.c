#include "monty.h"
#include "abs_var.h"

/**
 * main - entry point of monty
 * monty interprets and executes monty file given as argument
 * @argc: int; argument counter
 * @argv: double pointer to char; argument vector
 *
 * Return: int; EXIT_SUCCESS when succes with output to stdout
 * EXIT_FAILURE when failure with error message to stderr
 * TheOwl
 */
int main(int argc, char **argv)
{
	char *l_buffer;
	int l_number;
	instruction_t cmd;

	/* read mounty file */
	monty_var.stand_buffer = ck_and_rd_file(argc, argv);
	if (monty_var.stand_buffer == NULL)
	{
		error_freeing();
		return (EXIT_FAILURE);
	}
	/* get number of line */
	l_number = line_number(monty_var.stand_buffer);
	while (monty_var.cur_line < l_number)
	{
		/* read each line */
		printf("Line is : %d\n", monty_var.cur_line);
		l_buffer = read_lines(monty_var.stand_buffer, l_number);
		/* identify and execute instructions */
		if (strlen(l_buffer) != 0 && comment_checker(l_buffer) != 1)
		{
			cmd = get_instruction(l_buffer);
			if (cmd.opcode != NULL && cmd.f != NULL)
				cmd.f(monty_var.init_stack, monty_var.cur_line);
		}
		free(l_buffer);
	}
	error_freeing();
	return (EXIT_SUCCESS);
}
