/*
** EPITECH PROJECT, 2020
** B-PSU-101-MPL-1-1-minishell1-guillaume.boudaille
** File description:
** is_command.c
*/

#include "include/my.h"

int nb_words(char *str)
{
    int nb = 1;

    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ' || str[i] == '\t');
        else if (not_first_word(str, i) == 1);
        else
            nb++;
    }
    str[0] = str[0];
    return (nb);
}