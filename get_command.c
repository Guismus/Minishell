/*
** EPITECH PROJECT, 2020
** B-PSU-101-MPL-1-1-minishell1-guillaume.boudaille
** File description:
** get_path.c
*/

#include "include/my.h"

int is_space_before(const char *str, int i)
{
    if (str[i] == ' ' || str[i] == '\t') {
        if (i == 0)
            return (1);
        if (str[i - 1] == ' ' || str[i - 1] == '\t')
            return (1);
    }
    return (0);
}

int only_space(char *str)
{
    if (str[0] != ' ' || str[0] != '\t')
        return (0);
    if (str[0] == 0)
        return (1);
    for (int i = 1; str[i]; i++) {
        if (str[i] != ' ' || str[i] != '\t')
            return (0);
    }
    return (1);
}

int len_word(char *str)
{
    int i = 0;

    while (str[0] == ' ' || str[0] == '\t')
        str += 1;
    while (str[i] && str[i] != ' ' && str[i] != '\t')
        i++;
    return (i + 1);
}

int not_first_word(char *str, int i)
{
    if (i == 0)
        return (0);
    if (str[i - 1] != ' ' && str[i - 1] != '\t')
        return (0);
    return (1);
}

char **get_command(char *str)
{
    char **tab = malloc(sizeof(char *) * 1000);
    int j = 0;

    tab[0] = malloc(sizeof(char) * len_word(str));
    for (int i = 0, k = 0; str[i] && str[i] != '\n'; i++) {
        if (is_space_before(str, i) == 1);
        else if (str[i] == ' ' || str[i] == '\t') {
            j++;
            tab[j] = malloc(sizeof(char) * len_word(str + i));
            tab[j][0] = 0;
            tab[j + 1] = NULL;
            k = 0;
        } else {
            tab[j][k] = str[i];
            k++;
            tab[j][k] = 0;
        }
    }
    if (tab[j][0] == 0)
        tab[j] = NULL;
    return (tab);
}