#include "shell.h"

/**
 * get_path_cmd - Search command in PATH
 * @cmd: Command name
 *
 * Return: Full path or NULL
 */
char *get_path_cmd(char *cmd)
{
	char *path, *path_copy, *dir, *full;
	struct stat st;

	if (stat(cmd, &st) == 0)
		return (cmd);

	path = getenv("PATH");
	if (!path)
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir)
	{
		full = malloc(strlen(dir) + strlen(cmd) + 2);
		if (!full)
			break;

		sprintf(full, "%s/%s", dir, cmd);
		if (stat(full, &st) == 0)
		{
			free(path_copy);
			return (full);
		}
		free(full);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
