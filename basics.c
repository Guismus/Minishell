/*
** EPITECH PROJECT, 2020
** basics
** File description:
** basics.c
*/

#include "include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char *str)
{
    int i = 0;

    for (i = 0; str[i] != 0; i++);
    return (i);
}

int my_tablen(char **str)
{
    int i = 0;

    for (i = 0; str[i] != 0; i++);
    return (i);
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (;i != n - 1 && s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'; i++);
    return (s1[i] - s2[i]);
}