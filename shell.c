#include "shell.h"
/**
 * main - simple shell main enrty
 * @ac: count of args
 * @argv: arguments
 * Return: 0 always success
 */
int main(int ac, char **argv)
{
	char *input = NULL;
	char **cmd = NULL;
	int status = 0, idx = 0;
	(void) ac;

	while (1)
	{
		input = user_input();
		if (input == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}

		idx++;
		cmd = spliter(input);
		if (!cmd)
			continue;

		if (builtin_check(cmd[0]))
		{
			builtin_handle(cmd, argv, &status, idx);
		}
		else
		{
		status = exe_cute(cmd, argv, idx);
		}
	}
}
