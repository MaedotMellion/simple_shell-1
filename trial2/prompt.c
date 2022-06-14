#include <stdio.h>
#include "shell.h"

/**
 * print_prompt1 - prints the prompt sign ($)
 * Return: returns nothing
 */

void print_prompt1(void)
{
	_printf("$ ");
}

/**
 * print_prompt2 - prints the sign (>) when a new line is added
 * Return: returns nothing
 */

void print_prompt2(void)
{
	_printf("> ");
}
