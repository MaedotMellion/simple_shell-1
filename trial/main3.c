#include "shell.h"
#include "parser.h"
#include "executor.h"

int main(int argc, char **argv)
{
    char *cmd;
    initsh();
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
	struct source_s src;
        src.buffer   = cmd;
        src.bufsize  = strlen(cmd);
        src.curpos   = INIT_SRC_POS;
        parse_and_execute(&src);
	free(cmd);
    } while (1);
    exit(EXIT_SUCCESS);
}

char *read_cmd(void)
{
    char buf[1024], ptrlen = 0;
    char *ptr = NULL,  *ptr2 = NULL;
    int buflen = 0;

    while(fgets(buf, 1024, stdin))
    {
        buflen = strlen(buf);

        if(!ptr)
        {
            ptr = malloc(buflen+1);
        }
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
        if(!ptr)
        {
            _printf("error: failed to alloc buffer:\n");
            return NULL;
        }
        _strcpy(ptr+ptrlen, buf);

        if(buf[buflen-1] == '\n')
        {
            if(buflen == 1 || buf[buflen-2] != '\\')
            {
                return ptr;
            }

            ptr[ptrlen+buflen-2] = '\0';
            buflen -= 2;
            print_prompt2();
        }

        ptrlen += buflen;
    }
    return (ptr);
}
int parse_and_execute(struct source_s *src)
{
    skip_white_spaces(src);

    struct token_s *tok = tokenize(src);

    if(tok == &eof_token)
    {
        return 0;
    }

    while(tok && tok != &eof_token)
    {
        struct node_s *cmd = parse_simple_command(tok);

        if(!cmd)
        {
            break;
        }

        do_simple_command(cmd);
        free_node_tree(cmd);
        tok = tokenize(src);
    }

    return 1;
}
