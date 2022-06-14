#include "shell.h"
/**
 * execute - implements commands
 * @cp: command
 * @cmd: pointer to array of commands
 * Return: 0
 */
void execute(char *cp, char **cmd)
{
	pid_t child_pid;
	int status;
	char **env = environ;

	child_pid = fork();
	if (child_pid < 0)
		perror(cp);

	if (child_pid == 0)
	{
		execve(cp, cmd, env);
		perror(cp);
		free(cp);
		free_buff(cmd);
		exit(98);
	}
	else
		wait(&status);
}
