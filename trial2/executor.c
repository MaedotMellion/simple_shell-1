#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "shell.h"
#include "node.h"
#include "executor.h"

char *search_path(char *file)
{
	char *PATH = getenv("PATH"), *p = PATH, *p2, path[];
	int  plen, alen;

	while (p && *p)
	{
		p2 = p;
		while (*p2 && *p2 != ':')
			p2++;
		plen = p2 - p;
		if (!plen)
			plen = 1;
		alen = _strlen(file);
		path[plen + 1 + alen + 1];
	        _strncpy(path, p, p2 - p);
		path[p2 - p] = '\0';

		if (p2[-1] != '/')
		{
			strcat(path, "/");
		}
		_strcat(path, file);
	        struct stat st;
		if (stat(path, &st) == 0)
		{
			if (!S_ISREG(st.st_mode))
			{
				errno = ENOENT;
				p = p2;
				if (*p2 == ':')
					p++;
				continue;
			}

			p = malloc(_strlen(path) + 1);
			if (!p)
				return (NULL);
			_strcpy(p, path);
			return (p);
		}
		else    /* file not found */
		{
			p = p2;
			if (*p2 == ':')
			{
				p++;
			}
		}
        }
	errno = ENOENT;
	return (NULL);
}


int do_exec_cmd(int argc, char **argv)
{
	char *path;

	if (strchr(argv[0], '/'))
	{
		execv(argv[0], argv);
	}
	else
	{
		path = search_path(argv[0]);
		if (!path)
			return 0;
		execv(path, argv);
		free(path);
	}
	return (0);
}


static inline void free_argv(int argc, char **argv)
{
	if (!argc)
	{
		return;
	}

	while (argc--)
        {
		free(argv[argc]);
	}
}


int do_simple_command(struct node_s *node)
{
	struct node_s *child;
	int i = 0, status = 0, int argc = 0;
	char *argv[max_args + 1], *str;
	long max_args = 255;
	pid_t child_pid = 0;

	if (!node)
		return 0;
	child = node->first_child;
	if (!child)
		return 0;
	while (child)
	{
		str = child->val.str;
		argv[argc] = malloc(strlen(str)+1);
		if (!argv[argc])
		{
			free_argv(argc, argv);
			return (0);
		}
		_strcpy(argv[argc], str);
		if (++argc >= max_args)
			break;
		child = child->next_sibling;
	}
	argv[argc] = NULL;

	for( ; i < builtins_count; i++)
	{
		if (str_cmp(argv[0], builtins[i].name) == 0)
		{
			builtins[i].func(argc, argv);
			free_argv(argc, argv);
			return (1);
		}
        }

        if ((child_pid = fork()) == 0)
	{
		do_exec_cmd(argc, argv);
		_printf("error: failed to execute command:\n");
		if (errno == ENOEXEC)
			exit(126);
		else if (errno == ENOENT)
			exit(127);
		else
			exit(EXIT_FAILURE);
	}
	else if (child_pid < 0)
	{
		_printf("error: failed to fork command:\n");
		return (0);
	}
	waitpid(child_pid, &status, 0);
	free_argv(argc, argv);
        return (1);
}
