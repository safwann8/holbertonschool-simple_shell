#include "shell.h"

/**
 * main - Simple UNIX command line interpreter
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned int line_count = 0;
	char *line = NULL;
	char *cmd;
	size_t len = 0;
	char *argv[1024];

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		if (getline(&line, &len, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(line);
			return (0);
		}

		line_count++;

		line[strcspn(line, "\n")] = '\0';
		cmd = trim_spaces(line);

		if (*cmd == '\0')
			continue;

		split_line(cmd, argv);

		/* Handle built-ins first */
		if (handle_builtins(argv, line))
			continue;

		execute_cmd(argv, line_count);
	}
}
