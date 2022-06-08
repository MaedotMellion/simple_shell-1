#include<stdio.h>
/**
 * main - prints all arguments without using ac
 * @av: array of strings (arguments)
*/

int main(int __attribute__((__unused__))ac, char **av)
{
    int i = 1;
   
    while(av)
    {
        if (av[i] == NULL)
            break;
        printf("%s\n", av[i]);
        i++;
    }
    return (0);
}
