/*
** EPITECH PROJECT, 2020
** B-PSU-210-MPL-2-1-minishell2-guillaume.boudaille
** File description:
** is_command_two.c
*/

#include "include/my.h"

int is_cd(char *str)
{
    char **command = get_command(str);
    if (my_strncmp(command[0], "cd", my_strlen(command[0])) == 0)
        if (my_strncmp(command[0], "cd", 2) == 0)
            return (1);
    return (0);
}