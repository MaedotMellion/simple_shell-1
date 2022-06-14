#include "shell.h"
/**
* main - reads commands and executes
* @ac: number of args
* @av: pointer to args
* @envp: pointer to env variables
* Return: 0
*/

int main(int ac, char **av, char *envp[])
{
	char *line = NULL, *pathcommand = NULL, *path = NULL;
	size_t bufsize = 0;
	ssize_t lsize = 0;
	char **command = NULL, **paths = NULL;
	(void)envp, (void)av;
	if (ac < 1)
		return (-1);
	signal(SIGINT, test_signal);
	while (1)
	{
		free_buff(command);
		free_buff(paths);
		free(pathcommand);
		prompt();
		lsize = getline(&line, &bufsize, stdin);
		if (lsize < 0)
			break;
		info.ln_count++;
		if (line[lsize - 1] == '\n')
			line[lsize - 1] = '\0';

		command = token(line);
		if (command == NULL || *command == NULL || **command == '\0')
			continue;
		if (check(command, line))
			continue;
		path = get_path();
		paths = token(path);
		pathcommand = check_path(paths, command[0]);
		if (!pathcommand)
			perror(av[0]);
		else
			execute(pathcommand, command);
	}
	if (lsize < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(line);
	return (0);
}
