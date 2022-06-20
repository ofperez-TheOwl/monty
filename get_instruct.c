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
 * _strstr - locate a substring
 * @haystack: pointer to string; string to screen
 * @needle: pointer to string; substring to search for
 *
 * Return: pointer to the located sustring or NULL if none
 * TheOwl
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j, k;

	if (needle[0] == '\0')
		return (haystack);
	for (i = 0; haystack[i] != '\0'; i++)
	{
		if (needle[0] == haystack[i])/* find the first matching */
		{
			k = i + 1;
			j = 1;
			while (needle[j] != '\0')/* check total match*/
			{
				if (needle[j] == haystack[k] && needle[j + 1] != '\0')
				{
					j++;
					k++;
				}
				else if (needle[j] == haystack[k] && needle[j + 1] == '\0')
				{
					return (&haystack[i]);
				}
				else
					break;
			}
		}
	}
	return (NULL); /* no matching */
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
	int i = 0, j = strlen(buffer);
	int cursor, k;
	char *l;
	instruction_t *cmd_list = monty_var.instruct;

	/* extract instruct */
	while (cmd_list[i].opcode != NULL)
	{
		l = _strstr(buffer, cmd_list[i].opcode);
		if (l != NULL)
		{
			cursor = l - buffer;
			if (cursor <= j)
			{
				j = cursor;
				k = i;
			}
		}
		i++;
	}
	if (j == (int)strlen(buffer))
		return (cmd_list[i]);
	/* extract argument*/
	i = 0;
	while (buffer[j] != ' ' && buffer[j] != '\0')
		j++;
	while (buffer[j] == ' ' && buffer[j] != '\0')
		j++;
	while (buffer[j + i] != ' ' && buffer[j + i] != '\0')
		i++;
	buffer[j + i] = '\0';
	if (i != 0)
		monty_var.cur_arg = buffer + j;

	return (cmd_list[k]);
}
