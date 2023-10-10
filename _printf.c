#include "shell.h"

/**
 * _printf - print a given message
 */
void _printf(const char *message)
{
	write(STDOUT_FILENO, message, strlen(message));
}
