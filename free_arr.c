#include "shell.h"
/**
 * free_arr - free memory
 * @arr: arr of strings
 * Return: freed arr
 */
void free_arr(char **arr)
{
	int i;

	if (!arr)
	{
		return;
	}
	for (i = 0 ; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}

	free(arr);
}
/**
 * print_error - handle error
 * @name: the name of the program attempting to open the file
 * @cmd: the name of the file that cant be opened
 * @idx: counter var to keep track
 * Return: void
 */
void print_error(char *name, char *cmd, int idx)
{
	char *index;

	index = _itoa(idx);

		write(STDERR_FILENO, name, _strlen(name));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, index, _strlen(index));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, cmd, _strlen(cmd));
		write(STDERR_FILENO, ": not found", 11);
		write(STDERR_FILENO, "\n", 1);
		free(index);
}

/**
 * _itoa - convert a string to integer
 * @n: integer
 * Return: converted int
 */
char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
	{
		buffer[i++] = '0';
	}

	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
			buffer[i] = '\0';
			reverse_string(buffer, i);
			return (_strdup(buffer));
}
/**
 * reverse_string - func to reverse string
 * @str: string to be revesered
 * @len: length of string
 * Return: revered string
 */
void reverse_string(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}
