/*
** EPITECH PROJECT, 2020
** B-PSU-101-MPL-1-1-minishell1-guillaume.boudaille
** File description:
** env_function.c
*/

#include "include/my.h"

void print_env(t_char_list *list)
{
    while (list != NULL) {
        my_putstr(list->value);
        my_putchar('\n');
        list = list->next;
    }
}

int verif_setenv(char *str)
{
    if (str[0] < 'a' || str[0] > 'z') {
        if (str[0] < 'A' || str[0] > 'Z') {
            write(2, "setenv: Variable name must begin with a letter.\n", 48);
            return (0);
        }
    }
    for (int i = 0, tkt = 0; str[i]; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] == '_')
            tkt = 1;
        if (str[i] >= '0' && str[i] <= '9' || str[i] >= 'A' && str[i] <= 'Z')
            tkt = 1;
        if (tkt == 0) {
            write(2, "setenv: Variable name must ", 27);
            write(2, "contain alphanumeric characters.\n", 33);
            return (0);
        }
        tkt = 0;
    }
    return (1);
}

void add_env(t_char_list **list, char *str)
{
    t_char_list *node = *list;

    char **command = get_command(str);
    char *value = NULL;

    if (my_tablen(command) == 1)
        return;
    if (verif_setenv(command[1]) == 0) {
        return;
    }
    value = my_strcat(command[1], "=");
    if (my_tablen(command) == 2) {
        int_list_push_back(&node, value);
        return;
    }
    if (my_tablen(command) == 3) {
        int_list_push_back(&node, my_strcat(value, command[2]));
        return;
    }
    write(2, "setenv: Too many arguments.\n", 28);
}

void delete_list(t_char_list **list, char *str)
{
    t_char_list *node = *list;

    while (node->next != NULL &&
        my_strncmp(node->next->value, str, my_strlen(str)) != 0) {
        node = node->next;
    }
    if (node->next != NULL) {
        node->next = node->next->next;
    }
}

void rem_env(t_char_list **list, char *str)
{
    t_char_list *node = *list;

    char **command = get_command(str);
    char *value = NULL;

    if (my_tablen(command) == 1) {
        write(2, "setenv: Too few arguments.\n", 27);
        return;
    }
    for (int i = 1; command[i]; i++)
        command[i] = my_strcat(command[i], "=");
    for (int i = 1; command[i]; i++)
        delete_list(list, command[i]);
}