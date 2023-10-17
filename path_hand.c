#include "shell.h"
/**
 * get_path - handle the path
 * @cmd: given command
 * Return: Null if success, otherwise 0
 */
char *get_path(char *cmd)
{
	char *path_envir, *cmd_complete, *dir;
	int i;
	struct stat st;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
				return(_strdup(cmd));
			return (NULL);
		}
	}
	path_envir = _getenv("PATH");
	if (!path_envir)
		return (NULL);
	dir = strtok(path_envir, ":");
	while (dir)
	{
		cmd_complete = malloc(_strlen(dir) + _strlen(cmd) + 2);
		if (cmd_complete)
		{
			_strcpy(cmd_complete, dir);
			_strcat(cmd_complete, "/");
			_strcat(cmd_complete, cmd);
			if (stat(cmd_complete, &st) == 0)
			{
				free(path_envir);
				return (cmd_complete);
			}
			free(cmd_complete);
			dir = strtok(NULL, ":");
		}
	}
	free(path_envir);
	return (NULL);
}
