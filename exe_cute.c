#include "shell.h"
/**
 * exe_cute - execute a process
 * @command: given command
 * @argv: array of strings
 * Return: 1 if success, otherwise 0
 */
int exe_cute(char **command, char **argv)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		if (execve(command[0], command, environ) == -1)
			{
				perror(argv[0]);
				free_arr(command);
				exit(0);
			}
	}
	else
	{
		waitpid(child, &status, 0);
		free_arr(command);
	}
	return (WEXITSTATUS(status));
}
