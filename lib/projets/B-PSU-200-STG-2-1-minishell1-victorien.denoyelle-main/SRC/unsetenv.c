/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-thibaut.louis
** File description:
** unsetenv.c
*/

#include "../include/my.h"

int unset_env(mysh_t *my_shell, char *arg)
{
    char **result_com = malloc(sizeof(char *) * (arr_len(my_shell->env)));
    int j = 0;

    for (int i = 0; my_shell->env[i] != NULL; i++){
        if (my_strncmp(my_shell->env[i], arg, my_strlen(arg)) != 0) {
            result_com[j] = my_shell->env[i];
            j++;
        } else {
            free(my_shell->env[i]);
        }
    }
    result_com[j] = NULL;
    free(my_shell->env);
    my_shell->env = result_com;
    return 0;
}

int unset_env_offciel(mysh_t *my_shell, char **com)
{
    int index;

    if (arr_len(com) == 1){
        my_puterror("unsetenv: Too few arguments.\n");
        return 1;
    }
    for (int i = 0; com[i] != NULL; i++) {
        index = search_env(my_shell->env, com[i]);
        if (index != -1)
            unset_env(my_shell, com[i]);
    }
    return 0;
}
