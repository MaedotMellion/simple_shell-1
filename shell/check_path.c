#include "shell.h"
/**
* check_path - checks whether path is valid
* @path: pointer to path args
* @command: command
* Return: pointer to command or NULL
*/
char *check_path(char **path, char *command)
{
	int i = 0;
	char *result;

	while (path[i])
	{
		result = merge_path(path[i], command);
		if (access(result, F_OK | X_OK) == 0)
			return (result);

		free(result);
		i++;
	}
	return (NULL);
}
