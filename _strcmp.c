#include "shell.h"
/**
* _strcmp - compares two strings
* @s1: first string input;
* @s2: second string input;
* Return: difference
*/
int _strcmp(char *s1, char *s2)
{
	int i = 0, result;

	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0')
		i++;

	result = (*(s1 + i) - *(s2 + i));

	return (result);
}
