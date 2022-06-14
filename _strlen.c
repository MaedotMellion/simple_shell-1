#include "shell.h"
/**
* _strlen - finds the length of a string
* @s: string input
* Return: returns length of string passed
*/
int _strlen(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}
