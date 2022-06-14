#include "shell.h"
/**
 *test_signal- checks if in interactive mode
 *@m: the signal number
 *Return: void
 */
void test_signal(int m)
{
	(void)m;

	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}
