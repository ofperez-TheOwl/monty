#include "monty.h"

/**
 * ck_and_rd_first - checks input and reads first line
 * @argc: int; argument counter
 * @argv: double pointer to char; argument vector
 *
 * Return: pointer to char; buffer with first line of monty code
 * if failure return NULL
 * TheOwl
 */
void *ck_and_rd_first(int argc, char **argv)
{
	char *buffer;
	int monty_fd;
	ssize_t l_read = 1;
	
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		return (NULL);
	}
	monty_fd = open(argv[1], O_RDONLY);
	if (monty_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		return (NULL);
	}
	buffer = malloc(sizeof(char));
	if (buffer == NULL)
	{
		free(buffer);
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		return (NULL);
	}
	l_read = read(monty_fd, buffer, 1);
	if (l_read == -1)
	{
		free(buffer);
		dprintf(STDERR_FILENO, "Error : can't read file %s\n", argv[1]);
		return (NULL);
	}
	while (buffer[l_read - 1] != '\n' && buffer[l_read -1] != EOF)
	{
		free(buffer);
		l_read++;
		buffer = malloc(sizeof(char) * l_read);
		if (buffer == NULL)
		{
			free(buffer);
			dprintf(STDERR_FILENO, "Error: malloc failed\n");
			return (NULL);
		}
		lseek(monty_fd, 0, SEEK_SET);
		l_read = read(monty_fd, buffer, l_read);
		if (l_read == -1)
		{
			free(buffer);
			dprintf(STDERR_FILENO, "Error : can't read file %s\n", argv[1]);
			return (NULL);
		}
	}
	return (buffer);
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
int main(int argc, char ** argv)
{
	char *buffer;
	int monty_fd;
	ssize_t l_read;

	/* exclusion */
	buffer = ck_and_rd_first(argc, argv);
	if (buffer == NULL)
		return (EXIT_FAILURE);
