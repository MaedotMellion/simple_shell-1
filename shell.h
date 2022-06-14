#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

struct builtin
{
	char *env;
	char *exit;
} builtin;

struct info
{
	int final_exit;
	int ln_count;
} info;

struct flags
{
	bool interactive;
} flags;

void prompt(void);
void execute(char *cp, char **cmd);
char **token(char *line);
int check(char **cmd, char *buf);
void test_signal(int m);
int builtin_fun(char **command, char *line);
void exit_shell(char **command, char *line);
char *get_path(void);
char *check_path(char **path, char *command);
char *merge_path(char *path, char *command);
void write_env(void);
void free_buff(char **buf);

extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *s);
char *_strchr(char *s, char c);

#endif /* SHELL_H */
