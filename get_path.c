/*
** EPITECH PROJECT, 2020
** B-PSU-101-MPL-1-1-minishell1-guillaume.boudaille
** File description:
** get_path.c
*/

#include "include/my.h"

void alloc_tab(char **tab)
{
    for (int i = 0; i != 999; i++) {
        tab[i] = malloc(sizeof(char) * 1000);
        for (int j = 0; j != 999; j++)
            tab[i][j] = 0;
    }
}

char *search_path(t_char_list *list)
{
    while (my_strncmp(list->value, "PATH=", 5) != 0 && list->value != NULL)
        list = list->next;
    if (list->value == NULL)
        return (NULL);
    return (list->value + 5);
}

char **get_path(t_char_list *list, char *command)
{
    char *str = NULL;
    char **tab = malloc(sizeof(char *) * 1000);
    int j = 0;

    if (search_path(list) == NULL)
        return (NULL);
    str = search_path(list);
    alloc_tab(tab);
    for (int i = 0, n = 0; str[i]; i++, n++) {
        if (str[i] == ':') {
            tab[j] = my_strcat(tab[j], "/");
            tab[j] = my_strcat(tab[j], command);
            i++;
            n = 0;
            j++;
        }
        tab[j][n] = str[i];
    }
    tab[j] = my_strcat(my_strcat(tab[j], "/"), command);
    return (tab);
}
