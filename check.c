#include "shell.h"
/**
 *check - checks to see weather its a built in function
 *@cmd: pointer to array of entered commands
 *@buf: line inputed by user
 *Return: 1 if cmd excuted 0 if cmd is not executed
 */
int check(char **cmd, char *buf)
{
	if (builtin_fun(cmd, buf))
		return (1);

	else if (**cmd == '/')
	{
		execute(cmd[0], cmd);
		return (1);
	}
	return (0);
}
