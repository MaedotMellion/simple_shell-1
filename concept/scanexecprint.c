#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/wait.h>


void create_and_wait(pid_t *child_pid, int *status, int *i)
{
	if (*child_pid != 0)
	{
		wait(&(*status));
		*child_pid = fork();
		*i = *i + 1;
	}
}
/**
 * main - prints args
 * Return: void
*/

int main(void)
{
    char *buffer;
    size_t l = 1024;
    int readline;
    char *command;
    int status;

    pid_t child_pid;

    child_pid = fork();

    buffer = malloc(sizeof(size_t) * l);

    while(1)
    {
	    printf("$ ");
	    readline = getline(&buffer, &l, stdin);
	    
	    if (readline != EOF)
		    printf("%s\n", buffer);

	    command = strtok(buffer, " ");

	   if (child_pid != 0)
		   wait(&status);

	   if (child_pid == 0)
	   {
		   if (execve(command, args, NULL) == -1)
			   perror("error");
	   }
	   /* while (command)
	    {
		    printf("%s\n", token);
		    token = strtok(NULL, " ");
	    } */
    } 
    return (0);
}
