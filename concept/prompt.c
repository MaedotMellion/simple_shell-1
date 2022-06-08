#include<stdio.h>
#include<stdlib.h>
/**
 * main - prints args
 * Return: void
*/

int main(void)
{
    char *buffer;
    size_t l = 1024;
    int readline;

    buffer = malloc(sizeof(size_t) * l);

    while(1)
    {
	    printf("$ ");
	    readline = getline(&buffer, &l, stdin);
	    
	    if (readline == EOF)
		    printf("%s\n", buffer);
    }
    return (0);
}
