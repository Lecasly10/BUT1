/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-thibaut.louis
** File description:
** search_env.c
*/

#include "../include/my.h"

static int pos_egal(char *line)
{
    int i = 0;

    for (; line[i] != '=' && line[i] != '\0'; i++);
    if (line[i] == '=')
        return i;
    else
        return -1;
}

char *search_name(char *str)
{
    char *result;
    int pos_maj = pos_egal(str);

    result = my_substr(str, pos_maj, 0);
    return result;
}

int search_env(char **env, char *search)
{
    char *stock = NULL;

    for (int i = 0; env[i] != NULL; i++) {
        if (stock != NULL)
            free(stock);
        stock = search_name(env[i]);
        if (my_strcmp(stock, search) == 0) {
            free(stock);
            return i;
        }
    }
    free(stock);
    return -1;
}

char *search_env_val(char **env, char *search)
{
    int i = search_env(env, search);
    char *tmp;
    int pos_maj;
    int pos_min;

    if (i == -1)
        return NULL;
    pos_maj = my_strlen(env[i]);
    pos_min = pos_egal(env[i]) + 1;
    tmp = my_substr(env[i], pos_maj, pos_min);
    return tmp;
}
