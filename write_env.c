#include "shell.h"
/**
* write_env - writes out the environment string to stdout
* Return: void
*/
void write_env(void)
{
	int i;
	char **env = environ;

	i = 0;
	while (env[i])
	{
		write(STDOUT_FILENO, (const void *)env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
