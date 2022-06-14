#include "shell.h"
/**
* _strchr - locates a character in a string
* @s: string input
* @c: character to be located in string
* Return: returns pointer to first occurence of character
*/
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}

	if (!c)
		return (s);
	return (NULL);
}
