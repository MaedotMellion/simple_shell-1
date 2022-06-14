#include "shell.h"
/**
* get_path - gets the path from the global enviroment
* Return: NULL
*/
char *get_path(void)
{
	int x;
	char **env = environ, *path = NULL;

	while (*env)
	{
		if (strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env;
			while (*path && x < 5)
			{
				path++;
				x++;
			}
			return (path);
		}
		env++;
	}
	return (NULL);
}
