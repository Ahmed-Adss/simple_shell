#include "shell.h"
/**
 * user_input - comand written by user
 * Return: line written by user
 */
char *user_input(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t n_char;

	write(STDOUT_FILENO, "$ ", 2);
	n_char = getline(&input, &len, stdin);
	if (n_char == -1)
	{
		free(input);
		return (NULL);
	}
	return (input);
}
