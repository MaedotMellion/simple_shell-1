#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/wait.h>

/**
 * main - prints args
 * Return: void
*/

int main(void)
{
	char *buffer, *token, *command[100];
	size_t l = 1024;
	int status, i = 0;
	pid_t child_pid;
    
	buffer = malloc(sizeof(size_t) * l);

 	while(1)
	{
		printf("$ ");
		getline(&buffer, &l, stdin);
		token = strtok(buffer, " ");

		while(token)
		{
			command[i] = strdup(token);
			token = strtok(NULL, " ");
			i++;
		}
		command[i] = NULL;

		child_pid = fork();

		if (child_pid == 0)
		{
			printf("%s", command[0]);
			if (execve(command[0], command, NULL) == -1)
				perror("Error");
		}
		else if (child_pid > 0)
		{
			wait(&status);
		}
		else
		{
			perror("Fork failed");
		}
	}

	return (0);
}
