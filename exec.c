#include "shell.h"

/**
 * execute_cmd - Fork and execute a command
 * @argv: Argument vector
 */
void execute_cmd(char **argv)
{
	pid_t pid;
	int status;
	char *path;

	path = get_path_cmd(argv[0]);
	if (!path)
	{
		fprintf(stderr, "./hsh: %s: not found\n", argv[0]);
		return;
	}

	pid = fork();
	if (pid == -1)
	{
		if (path != argv[0])
			free(path);
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
		if (path != argv[0])
			free(path);
	}
}
