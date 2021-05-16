/*
** EPITECH PROJECT, 2020
** B-PSU-101-MPL-1-1-minishell1-guillaume.boudaille
** File description:
** list_fonc.c
*/

#include "include/my.h"

void print_cd_error(char *str)
{
    str = my_strcat(str, ": ");
    str = my_strcat(str, strerror(errno));
    str = my_strcat(str, ".\n");
    my_putstr(str);
}

void int_list_push_front(t_char_list **list, char *value)
{
    t_char_list *new = malloc(sizeof(t_char_list));

    new->value = value;
    new->next = *list;
    *list = new;
}

void int_list_push_back(t_char_list **list, char *value)
{
    t_char_list *node = *list;
    t_char_list *new = malloc(sizeof(t_char_list));

    new->value = value;
    new->next = NULL;
    if (node->value == NULL) {
        *list = new;
        return;
    }
    while (node->next != NULL)
        node = node->next;
    node->next = new;
}

char *my_strcat(char *src, char *dest)
{
    char *str = malloc(sizeof(char) * (my_strlen(src) + my_strlen(dest) + 1));
    int i = 0;
    int n = 0;

    while (src[i]) {
        str[i] = src[i];
        i = i + 1;
    }
    while (dest[n])
    {
        str[i] = dest[n];
        i = i + 1;
        n = n + 1;
    }
    str[i] = 0;
    return (str);
}