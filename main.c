#include "shell.h"

/**
 * trim_spaces - Remove leading and trailing spaces and tabs
 * @str: String to trim
 *
 * Return: Pointer to trimmed string
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

/**
 * main - Simple UNIX command line interpreter
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	char *cmd;
	size_t len = 0;
	pid_t pid;
	int status;
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

		line[strcspn(line, "\n")] = '\0';
		cmd = trim_spaces(line);

		if (*cmd == '\0')
			continue;

		split_line(cmd, argv);

		pid = fork();
		if (pid == -1)
		{
			free(line);
			return (1);
		}

		if (pid == 0)
		{
			execve(argv[0], argv, environ);
			perror("./hsh");
			exit(1);
		}
		else
		{
			wait(&status);
		}
	}
}
