/*
** EPITECH PROJECT, 2020
** B-PSU-101-MPL-1-1-minishell1-guillaume.boudaille
** File description:
** main.c
*/

#include "include/my.h"

void set_old_pwd(t_char_list **env)
{
    t_char_list *node = *env;
    while (my_strncmp("PWD=", node->value, 4) != 0)
        node = node->next;
    add_env(env, my_strcat("setenv OLDPWD ", node->value + 4));
}

int main(int ac, char **av, char **env)
{
    char *line = NULL;
    int status = 0;
    size_t len = 0;
    t_char_list *list = malloc(sizeof(list));
    pid_t pid = fork();
    if (pid != 0) {
        waitpid(pid, &status, 0);
        my_putstr("exit\n");
        exit (0);
    }
    for (int i = 0; env[i]; i++)
        int_list_push_back(&list, env[i]);
    set_old_pwd(&list);
    if (isatty(STDIN_FILENO) == 1)
        write(1, "$> ", 3);
    while (getline(&line, &len, stdin) != -1) {
        is_command(line, &list, 0);
        if (isatty(STDIN_FILENO) == 1)
            write(1, "$> ", 3);
    }
}