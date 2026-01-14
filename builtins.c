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
	int i = 0;

	if (strcmp(argv[0], "exit") == 0)
	{
		free(line);
		exit(last_status);
	}

	if (strcmp(argv[0], "env") == 0)
	{
		while (environ[i])
		{
			write(STDOUT_FILENO, environ[i],
			      strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
		last_status = 0;
		return (1);
	}

	return (0);
}
