#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int str_cmp(char *s1, char *s2);
int _putchar(char c);
void _printf(char *str);
unsigned int _strlen(char *str);
void _strcpy(char *str_dest, char *str_src);
char *read_cmd(void);
void print_prompt1(void);
void print_prompt2(void);

#endif /* SHELL_H */
