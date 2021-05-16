/*
** EPITECH PROJECT, 2020
** B-PSU-101-MPL-1-1-minishell1-guillaume.boudaille
** File description:
** is_command.c
*/

#include "include/my.h"

int is_exit(char *str)
{
    char **command = get_command(str);
    if (my_strncmp(command[0], "exit", my_strlen(command[0])) == 0)
        if (my_strncmp(command[0], "exit", 4) == 0)
            return (1);
    return (0);
}

int is_env(char *str)
{
    char **command = get_command(str);
    if (my_strncmp(command[0], "env", my_strlen(command[0])) == 0)
        if (my_strncmp(command[0], "env", 3) == 0)
            return (1);
    return (0);
}

int is_setenv(char *str)
{
    char **command = get_command(str);
    if (my_strncmp(command[0], "setenv", my_strlen(command[0])) == 0)
        if (my_strncmp(command[0], "setenv", 6) == 0)
            return (1);
    return (0);
}

int is_unsetenv(char *str)
{
    char **command = get_command(str);
    if (my_strncmp(command[0], "unsetenv", my_strlen(command[0])) == 0)
        if (my_strncmp(command[0], "unsetenv", 8) == 0)
            return (1);
    return (0);
}

int is_access(char *str, t_char_list *list)
{
    char **command = get_command(str);
    char **tab = get_path(list, command[0]);

    if (tab == NULL)
        return (0);
    for (int i = 0; tab[i]; i++) {
        if (access(tab[i], F_OK) == 0) {
            exec(command, tab[i]);
            return (1);
        }
        if (access(command[0], F_OK) == 0) {
            exec(command, command[0]);
            return (1);
        }
    }
    return (0);
}