#include "shell.h"

int main(int argc, char **argv)
{
    char *cmd;

    do
    {
        print_prompt1();
       
        cmd = read_cmd();

        if(!cmd)
            exit(EXIT_SUCCESS);

        if(cmd[0] == '\0' || str_cmp(cmd, "\n") == 0)
        {
            free(cmd);
            continue;
        }

        if(str_cmp(cmd, "exit\n") == 0)
        {
            free(cmd);
            break;
        }
        _printf(cmd);
    } while (1);
    
    exit(EXIT_SUCCESS);
}

char *read_cmd(void)
{
	char *buf, *readline, ptrlen = 0;
    size_t l = 1024;
    char *ptr = NULL,  *ptr2 = NULL;
    unsigned int buflen = 0;

    while(1)
    {
	    readline = (char *) getline(&buf, &l, stdin);
	    buflen = strlen(buf);

        if(ptr)
            ptr = (char *) malloc(buflen + 1);
	else
        {
            ptr2 = realloc(ptr, ptrlen+buflen+1);

            if(ptr2)
            {
                ptr = ptr2;
            }
            else
            {
                free(ptr);
                ptr = NULL;
            }
        }
	if(readline == 0)
        {
            free(readline);
	    break;
        }
	strcpy(ptr + ptrlen, buf);

	if(str_cmp(buf, "exit\n") == 0)
        {
            free(buf);
            break;
        }
	ptrlen += buflen;
    }
    return (ptr);
}
