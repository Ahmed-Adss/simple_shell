#include "shell.h"
/**
 * is_positive_number - check if is it positive
 * @str: string to be checked
 * Return: 1
 */
int is_positive_number(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
/**
 * _atoi - convert  character to integer
 * @str: string to be converted
 * Return: integer
 */
int _atoi(char *str)
{
	int i, num = 0;

	for (i = 0; str[i]; i++)
	{
		num *= 10;
		num += (str[i] - '0');
	}
	return (num);
}
