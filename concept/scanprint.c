#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/**
 * main - prints args
 * Return: void
*/

int main(void)
{
    char *buffer;
    size_t l = 1024;
    int readline;
    char *token;

    buffer = malloc(sizeof(size_t) * l);

    while(1)
    {
	    printf("$ ");
	    readline = getline(&buffer, &l, stdin);
	    
	    if (readline == EOF)
		    printf("%s\n", buffer);

	    token = strtok(buffer, " ");
	    while (token)
	    {
		    printf("%s\n", token);
		    token = strtok(NULL, " ");
	    }
    }
    return (0);
}
