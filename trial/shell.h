#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void print_prompt1(void);
void print_prompt2(void);
char *read_cmd(void);
int str_cmp (char *s1, char *s2);
int _putchar(char c);
void _printf (char *str);
unsigned int _strlen(char *str);
void _strcpy (char *str_dest, char *str_src);

#endif /* SHELL_H */
