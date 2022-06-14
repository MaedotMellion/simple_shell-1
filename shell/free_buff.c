#include "shell.h"
/**
* free_buff - frees the buffers
* @buf: pointer to buffer
* Return: void
*/
void free_buff(char **buf)
{
	int i = 0;

	if (!buf || buf == NULL)
		return;

	while (buf[i])
	{
		free(buf[i]);
		i++;
	}

	free(buf);
}
