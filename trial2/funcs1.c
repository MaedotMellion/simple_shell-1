#include "shell.h"

/**
 * _printf - writes the string str to stdout
 * @str: The string to print
 * Return: returns nothing
 */

void _printf(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1
 *         On error, -1 is returned,
 *         and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - returns the length of a string
 * @str: a pointer to a string
 * Return: returns the length of the string
 */

unsigned int _strlen(char *str)
{
	unsigned int length = 0;

	while (*str != '\0')
	{
		length++;
		str++;
	}

	return (length);
}

/**
 * _strcpy - copies one string on another
 * @str_dest: a pointer to the destination string
 * @str_src: a pointer to the source string
 * Return: returns nothing
 */

void _strcpy(char *str_dest, char *str_src)
{
	while (*str_src != '\0')
	{
		*str_dest = *str_src;
		str_dest++;
		str_src++;
	}
	*str_dest = '\0';
}

/**
 * str_cmp - compares two strings
 * @s_one: a pointer to the first string
 * @s_two: a pointer to the second string
 * Return: 0 if they are equal
 *         1 if s_one > s_two
 *        -1 if s_one < s_two
 */

int str_cmp(char *s_one, char *s_two)
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
