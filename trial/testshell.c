#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/wait.h>


/**
 * str_cmp - compares two strings
 * @s_one: a pointer to the first string
 * @s_two: a pointer to the second string
 * Return: 0 if they are equal
 *         1 if s_one > s_two
 *        -1 if s_one < s_two
 */

int str_cmp (char *s_one, char *s_two)
{
    int notEqual = 0, isGreat = 0;

    while (*s_one != '\0' || *s_two != '\0')
    {
        if (*s_one != *s_two)
        {
            notEqual = 1;

            if (*s_one > *s_two)
                isGreat = 1;
            break;
        }
        s_one++;
        s_two++;
    }
    if (notEqual && isGreat)
        return (1);
    else if (notEqual && !isGreat)
        return (-1);
    else 
        return (0);
}

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
   char *readline;
  

    buffer = malloc(sizeof(size_t) * l);

    while(1)
    {
	    printf("$ ");
	    readline = (char *) getline(&buffer, &l, stdin);

		    printf("%s", buffer);

	if(readline == 0)
        {
            free(readline);
            break;
        }

	if(str_cmp(buffer, "exit\n") == 0)
        {
            free(buffer);
            break;
        }
    }
    return (0);
}
