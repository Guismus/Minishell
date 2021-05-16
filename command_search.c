/*
** EPITECH PROJECT, 2020
** B-PSU-210-MPL-2-1-minishell2-guillaume.boudaille
** File description:
** command_search.c
*/

#include "include/my.h"

void print_command_not_found(char *str)
{
    char **command = get_command(str);

    write(2, command[0], my_strlen(command[0]));
    write(2, ": Command not found.\n", 21);
}

int is_second_command(char *line)
{
    int i = 0;
    for (i = 0; line[i]; i++) {
        if (line[i] == ';' || (line[i] == '&' && line[i + 1] == '&'))
            return (i);
    }
    return (0);
}

int is_command_2(char *line, t_char_list **list, int tkt)
{
    t_char_list *env = *list;
    if (is_setenv(line) == 1) {
        add_env(&env, line);
        return (1);
    }
    if (is_unsetenv(line) == 1) {
        rem_env(list, line);
        return (1);
    }
    if (is_access(line, env) == 1)
        return (1);
    print_command_not_found(line);
    return (0);
}

int is_command(char *line, t_char_list **list, int tkt)
{
    t_char_list *env = *list;
    int n = 0;
    tkt = is_second_command(line);
    if (tkt != 0) {
        if (line[tkt] == '&')
            n = 1;
        line[tkt] = 0;
        if (is_command(line, &env, 0) == 0 && n == 1)
            return (0);
        line = line + tkt + 1 + n;
    }
    if (is_cd(line) == 1)
        return (cd_command(&env, get_command(line)));
    if (is_exit(line) == 1)
        exit (0);
    if (is_env(line) == 1) {
        print_env(env);
        return (1);
    }
    return (is_command_2(line, &env, tkt));
}