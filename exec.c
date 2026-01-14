#include "shell.h"

int last_status = 0;

/**
 * execute_cmd - Fork and execute a command
 * @argv: Argument vector
 * @line_count: Command line number
 */
void execute_cmd(char **argv, unsigned int line_count)
{
	pid_t pid;
	int status;
	char *path;

	path = get_path_cmd(argv[0]);
	if (!path)
	{
		fprintf(stderr, "./hsh: %u: %s: not found\n",
			line_count, argv[0]);
		last_status = 127;
		return;
	}

	pid = fork();
	if (pid == -1)
	{
		if (path != argv[0])
			free(path);
		last_status = 1;
		return;
	}

	if (pid == 0)
	{
		execve(path, argv, environ);
		perror("./hsh");
		exit(1);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			last_status = WEXITSTATUS(status);
		else
			last_status = 1;

		if (path != argv[0])
			free(path);
	}
}
