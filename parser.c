#include "shell.h"

/**
 * trim_spaces - Remove leading and trailing spaces and tabs
 * @str: String to trim
 *
 * Return: Trimmed string
 */
char *trim_spaces(char *str)
{
	char *end;

	while (*str == ' ' || *str == '\t')
		str++;

	if (*str == '\0')
		return (str);

	end = str + strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t'))
		end--;

	*(end + 1) = '\0';

	return (str);
}

/**
 * split_line - Split a line into arguments
 * @line: Command line
 * @argv: Argument vector
 */
void split_line(char *line, char **argv)
{
	int i = 0;
	char *token;

	token = strtok(line, " \t");
	while (token && i < 1023)
	{
		argv[i++] = token;
		token = strtok(NULL, " \t");
	}
	argv[i] = NULL;
}
