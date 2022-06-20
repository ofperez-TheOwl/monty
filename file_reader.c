#include "monty.h"

/**
 * ck_and_rd_first - checks input and reads first line
 * @argc: int; argument counter
 * @argv: double pointer to char; argument vector holding name of file
 *
 * Return: pointer to char; buffer with first line of monty code
 * if failure return NULL
 * TheOwl
 */
char *ck_and_rd_file(int argc, char **argv)
{
	char *buffer;
	int buf_size, fd;
	ssize_t l_read;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		return (NULL);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		return (NULL);
	}
	/* get monty file size and malloc buffer for it */
	buf_size = lseek(fd, 0, SEEK_END);
	if (buf_size == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't get size of file %s\n", argv[1]);
		return (NULL);
	}
	buffer = malloc((buf_size + 1) * sizeof(char));
	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		return (NULL);
	}
	lseek(fd, 0, SEEK_SET); /* reset offset and read monty file */
	l_read = read(fd, buffer, buf_size);
	if (l_read == -1)
	{
		free(buffer);
		dprintf(STDERR_FILENO, "Error : can't read file %s\n", argv[1]);
		return (NULL);
	}
	buffer[buf_size] = '\0';
	monty_var.free_stand_buffer = buffer;
	close(fd);
	return (buffer);
}

/**
 * read_lines - extracts current line of mounty file
 * @buffer: pointer to char; mounty file content
 * @l_number: int; total line number
 * Return: pointer to char; new line of monty code
 * NULL if failure
 * TheOwl
 */
char *read_lines(char *buffer, int l_number)
{
	int i = 0, j = 0;
	char *l_buffer;

	/* find line size and malloc buffer for it */
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	l_buffer = malloc((i + 1) * sizeof(char));
	if (l_buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		error_freeing();
		return (NULL);
	}
	/* copy line from stand_buffer to l_buffer */
	l_buffer[i] = '\0';
	if (l_number - 1 == monty_var.cur_line)
	{
		while (buffer[j] != '\0')
		{
			l_buffer[j] = buffer[j];
			j++;
		}
	}
	else
	{
		while (j < i)
		{
			l_buffer[j] = buffer[j];
			j++;
		}
	}
	/* set global parameters */
	monty_var.cur_line++;
	monty_var.stand_buffer = buffer + i + 1;
	return (l_buffer);
}

/**
 * line_number - returns number of line in mounty file
 * @buffer: pointer to char; content of mounty file
 *
 * Return: int; number of line
 * TheOwl
 */
int line_number(char *buffer)
{
	int i = 0, j = 0;

	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			j++;
		i++;
	}
	return (j + 1);
}
