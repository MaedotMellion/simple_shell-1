#include "shell.h"
/**
* _strdup - will dupicate a string
* @s: string input
* Return: pointer to new string
*/
char *_strdup(char *s)
{
	char *ptr;
	int i, len;

	if (s == NULL)
		return (NULL);

	len = _strlen(s);
	ptr = malloc(sizeof(char) * (len + 1));

	if (!ptr)
		return (NULL);

	for (i = 0; *s != '\0'; s++, i++)
		ptr[i] = s[0];
	ptr[i++] = '\0';
	return (ptr);
}
