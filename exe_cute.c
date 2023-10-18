#include "shell.h"
/**
 * exe_cute - execute a process
 * @command: given command
 * @argv: array of strings
 * @idx: index
 * Return: 1 if success, otherwise 0
 */
int exe_cute(char **command, char **argv, int idx)
{
	char *cmd_complete;
	pid_t child;
	int status;


	cmd_complete = get_path(command[0]);
	if (!cmd_complete)
	{
		print_error(argv[0], command[0], idx);
		free_arr(command);
		return (127);
	}

	child = fork();
	if (child == 0)
	{
		if (execve(cmd_complete, command, environ) == -1)
		{
			free(cmd_complete);
			free_arr(command);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free_arr(command);
		free(cmd_complete);
	}
	return (WEXITSTATUS(status));
}
