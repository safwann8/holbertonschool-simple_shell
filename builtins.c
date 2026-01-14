#include "shell.h"

/**
 * handle_builtins - Handle shell built-in commands
 * @argv: Argument vector
 * @line: Input line
 *
 * Return: 1 if builtin handled, 0 otherwise
 */
int handle_builtins(char **argv, char *line)
{
	if (strcmp(argv[0], "exit") == 0)
	{
		free(line);
		exit(last_status);
	}
	return (0);
}
