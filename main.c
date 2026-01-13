#include "shell.h"

/**
 * main - Simple UNIX command line interpreter
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	pid_t pid;
	int status;
	char *argv[2];

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

		pid = fork();
		if (pid == -1)
			return (1);

		if (pid == 0)
		{
			argv[0] = line;
			argv[1] = NULL;

			execve(line, argv, environ);
			perror("./hsh");
			exit(1);
		}
		else
		{
			wait(&status);
		}
	}
}
