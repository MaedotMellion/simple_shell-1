#include "shell.h"

/**
 * main - prints args
 * Return: void
*/

int main(void)
{
    char *buffer;
    size_t l = 1024;
    char *readline;

    buffer = malloc(sizeof(size_t) * l);

    while(1)
    {
	print_prompt1();
        readline = (char *) getline(&buffer, &l, stdin);

        printf("%s", buffer);

        if(readline == 0)
        {
            free(readline);
         break;
        }

        if(str_cmp(buffer, "exit\n") == 0)
        {
            free(buffer);
            break;
        }
    }
    return (0);
}
