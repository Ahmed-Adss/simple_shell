#include "shell.h"
int builtin_check(char *cmd)
{
	char *built_in[] = {
		"exit", "env", "setenv", "cd", NULL
	};
	int i;

	for (i = 0; built_in[i]; i++)
	{
		if (_strcmp(cmd, built_in[i]) == 0)
			return (1);
	}
	return (0);
}

void builtin_handle(char **cmd, char **argv, int *status, int idx)
{
	if (_strcmp(cmd[0], "exit") == 0)
		shell_exit(cmd, argv, status, idx);
	else if (_strcmp(cmd[0], "env") == 0)
		envir_print(cmd, status);
}

void shell_exit(char **cmd, char **argv, int *status, int idx)
{
	int exit_val = (*status);
	char *index, mssg[] = ": exit: Illegal number: ";

	if (cmd[1])
	{
		if (is_positive_number(cmd[1]))
		{
			exit_val = _atoi(cmd[1]);
		}
		else
		{
			index = _itoa(idx);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, _strlen(index));
			write(STDERR_FILENO, mssg, _strlen(mssg));
			write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
			write(STDERR_FILENO, "\n", 1);
			free(index);
			free_arr(cmd);
			(*status) = 2;
			return;
		}
	}
	free_arr(cmd);
	exit(exit_val);
}

void envir_print(char **cmd, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free_arr(cmd);
	(*status) = 0;
}
