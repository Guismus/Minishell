/*
** EPITECH PROJECT, 2020
** B-PSU-101-MPL-1-1-minishell1-guillaume.boudaille
** File description:
** exec.c
*/

#include "include/my.h"

void sig_catch(int sig)
{
    int term = 0;

    if (WIFSIGNALED(sig)) {
        term = WTERMSIG(sig);
        if (term == SIGSEGV)
            write(2, "Segmentation fault", 18);
        if (term == SIGFPE)
            write(2, "Floating exception", 18);
        if (WCOREDUMP(sig))
            write(2, " (core dumped)\n", 15);
        else
            write(2, "\n", 1);
    }
}

void exec(char **command, char *path)
{
    pid_t pid = fork();
    int status;

    if (pid == -1) {
        exit (84);
    }
    else if (pid == 0) {
        execve(path, command, NULL);
    } else {
        waitpid(pid, &status, 0);
        sig_catch(status);
        return;
    }
}