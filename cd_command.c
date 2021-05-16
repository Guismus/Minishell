/*
** EPITECH PROJECT, 2020
** B-PSU-210-MPL-2-1-minishell2-guillaume.boudaille
** File description:
** cd_command.c
*/

#include "include/my.h"

void pwd_home(t_char_list **env)
{
    t_char_list *node = *env;
    t_char_list *cpy = node;
    t_char_list *old = node;
    while (my_strncmp("PWD=", node->value, 4) != 0) {
        node = node->next;
    }
    while (my_strncmp("HOME=", cpy->value, 5) != 0) {
        cpy = cpy->next;
    }
    while (my_strncmp("OLDPWD=", old->value, 5) != 0) {
        old = old->next;
    }
    for (int i = 4; node->value[i - 1]; i++)
        old->value[i + 4] = node->value[i];
    for (int i = 5; cpy->value[i - 1]; i++)
        node->value[i - 1] = cpy->value[i];
    chdir(&cpy->value[5]);
}

void pwd_root(t_char_list **env, char *command)
{
    t_char_list *node = *env;
    t_char_list *old = node;
    while (my_strncmp("PWD=", node->value, 4) != 0) {
        node = node->next;
    }
    while (my_strncmp("OLDPWD=", old->value, 5) != 0) {
        old = old->next;
    }
    if (chdir(command) < 0) {
        print_cd_error(command);
        return;
    }
    for (int i = 4; node->value[i - 1]; i++)
        old->value[i + 4] = node->value[i];
    for (int i = 0; command[i]; i++) {
        node->value[i + 4] = command[i];
        node->value[i + 5] = 0;
    }
}

void pwd_less(t_char_list **env)
{
    t_char_list *node = *env;
    t_char_list *old = *env;
    char *str = NULL;
    while (my_strncmp("PWD=", node->value, 4) != 0)
        node = node->next;
    while (my_strncmp("OLDPWD=", old->value, 5) != 0)
        old = old->next;
    str = malloc(sizeof(char) * (my_strlen(node->value) + 1));
    for (int i = 4; node->value[i - 1]; i++)
        str[i - 4] = node->value[i];
    for (int i = 8; old->value[i - 1]; i++)
        node->value[i - 4] = old->value[i];
    for (int i = 0; str[i]; i++) {
        old->value[i + 8] = str[i];
        old->value[i + 9] = 0;
    }
    chdir(node->value + 4);
}

int pwd_basic(t_char_list **env, char *command)
{
    t_char_list *node = *env;
    t_char_list *old = *env;
    while (my_strncmp("PWD=", node->value, 4) != 0)
        node = node->next;
    while (my_strncmp("OLDPWD=", old->value, 5) != 0)
        old = old->next;
    if (command[0] == '/' && node->value[my_strlen(node->value) - 1] == '/')
        command = command + 1;
    if (command[0] != '/' && node->value[my_strlen(node->value) - 1] != '/')
        command = my_strcat("/", command);
    if (chdir(my_strcat(node->value + 4, command)) < 0) {
        print_cd_error(command + 1);
        return (0);
    }
    for (int i = 4; node->value[i - 1]; i++)
        old->value[i + 4] = node->value[i];
    node->value = my_strcat(node->value, command);
    return (1);
}

int cd_command(t_char_list **env, char **command)
{
    t_char_list *node = *env;
    if (my_tablen(command) > 2) {
        write(2, "cd: Too many arguments.\n", 24);
        return (1);
    }
    if (my_tablen(command) == 1) {
        pwd_home(&node);
        return (1);
    }
    if (my_strncmp("-\0", command[1], 2) == 0) {
        pwd_less(&node);
        return (1);
    }
    if (my_strncmp("/\0", command[1], 1) == 0) {
        pwd_root(&node, command[1]);
        return (1);
    }
    return (pwd_basic(&node, command[1]));
}