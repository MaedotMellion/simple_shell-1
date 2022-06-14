#include "shell.h"
/**
* builtin_fun - implements builtin funcs
* @command: pointer to command
* @line: input read from stdin
* Return: 1 if executed, 0 if not
*/
int builtin_fun(char **command, char *line)
{
	struct builtin builtin = {"env", "exit"};

	if (strcmp(*command, builtin.env) == 0)
	{
		write_env();
		return (1);
	}
	else if (_strcmp(*command, builtin.exit) == 0)
	{
		exit_shell(command, line);
		return (1);
	}
	return (0);
}
