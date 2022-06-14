#include "shell.h"
/**
* _strncmp - compares two strings
* @s1: first string input
* @s2: second string input
* @n: number of bytes
* Return: difference
*/
int _strncmp(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}

	return (0);
}
