/*
** EPITECH PROJECT, 2020
** B-PSU-101-MPL-1-1-minishell1-guillaume.boudaille
** File description:
** my.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

struct char_list
{
    char *value;
    struct char_list *next;
};

typedef struct char_list t_char_list;

void my_putchar(char c);
void my_putstr(char *str);
int my_strlen(char *str);
int my_strncmp(char const *s1, char const *s2, int n);
int is_exit(char *str);
void int_list_push_front(t_char_list **list, char *value);
void int_list_push_back(t_char_list **list, char *value);
int is_env(char *str);
void print_env(t_char_list *list);
char *my_strcat(char *src, char *dest);
int is_access(char *str, t_char_list *list);
char **get_path(t_char_list *list, char *command);
char **get_command(char *str);
void exec(char **command, char *path);
int is_setenv(char *str);
void add_env(t_char_list **list, char *str);
int my_tablen(char **str);
void sig_catch(int sig);
void rem_env(t_char_list **list, char *str);
int is_unsetenv(char *str);
int nb_words(char *str);
int not_first_word(char *str, int i);
int is_cd(char *str);
int cd_command(t_char_list **env, char **command);
void print_cd_error(char *str);
int is_command(char *line, t_char_list **list, int tkt);