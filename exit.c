
#include "shell.h"
/**
* exit_shell - handles the exit command
* @command: pointer command array
* @line: input read from stdin
* Return: void
*/
void exit_shell(char **command, char *line)
{
	free(line);
	free_buff(command);
	exit(0);
}
