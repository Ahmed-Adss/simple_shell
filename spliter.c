#include "shell.h"

char **spliter(char *line)
{
	char *split = *temp = NULL;
	char **cmd = NULL;
	int i = 0;

	if (!line)
	{
		return (NULL);
	}
	temp = _strdup(line);
	split = strtok(temp, SPECIFIER);

	if (split == NULL)
	{
		free(line);
		free(temp);
		return (NULL);
	}

	while (split)
	{
		i++;
		split = strtok(NULL, SPECIFIER);
	}
	free(temp);

	cmd = malloc(sizeof(char *) * (i + 1));

	if(!cmd)
	{
		free(line);
		return (NULL);
	}


		split = strtok(line, SPECIFIER);
	while (split)
	{
		cmd[l] = _strdup(split);
		split = strtok(NULL, SEPCIFIER);
		l++;
	}
	free(line);
	cmd[l] = NULL;
	return (cmd);
}
