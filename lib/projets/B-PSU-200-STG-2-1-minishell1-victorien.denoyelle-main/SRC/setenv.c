/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-thibaut.louis
** File description:
** setenv.c
*/

#include "../include/my.h"

int set_env(mysh_t *my_shell, char *arg, char *value)
{
    int env_len = arr_len(my_shell->env);
    char **new_env = malloc(sizeof(char *) * (env_len + 2));
    int i = 0;

    for (; my_shell->env[i] != NULL; i++) {
        new_env[i] = my_shell->env[i];
    }
    new_env[i] = my_strdup(arg);
    if (value != NULL)
        new_env[i] = my_str_cat(new_env[i], value, '=');
    else
        new_env[i] = my_str_cat2(new_env[i], "=");
    new_env[i + 1] = NULL;
    free(my_shell->env);
    my_shell->env = new_env;
    return 0;
}

int edit_env(mysh_t *my_shell, char *arg, char *value)
{
    int index = search_env(my_shell->env, arg);

    free(my_shell->env[index]);
    my_shell->env[index] = my_strdup(arg);
    if (value != NULL)
        my_shell->env[index] = my_str_cat(my_shell->env[index], value, '=');
    else
        my_shell->env[index] = my_str_cat2(my_shell->env[index], "=");
    if (my_strcmp(arg, "PATH") == 0) {
        free_tabl(my_shell->path);
        my_shell->path = get_path_list(my_shell->env);
    }
    return 0;
}

int set_env_error(mysh_t *my_shell, char *arg, char *value)
{
    int index = search_env(my_shell->env, arg);

    if (!(arg[0] >= 'a' && arg[0] <= 'z') &&
    !(arg[0] >= 'A' && arg[0] <= 'Z') && arg[0] != '_'){
        my_puterror("setenv: Variable name must");
        my_puterror(" begin with a letter.\n");
        return 1;
    }
    for (int i = 0; arg[i] != '\0'; ++i)
        if (arg[i] != '_' && !(arg[i] <= '9' && arg[i] >= '0')
        && !(arg[i] <= 'z' && arg[i] >= 'a') && !(arg[i] <= 'Z' &&
        arg[i] >= 'A')){
            my_puterror("setenv: Variable name must contain");
            my_puterror(" alphanumeric characters.\n");
            return 1;
        }
    if (index == -1)
        return set_env(my_shell, arg, value);
    else
        return edit_env(my_shell, arg, value);
}

int set_env_officiel(mysh_t *my_shell, char **com)
{
    int stock = arr_len(com);

    if (stock == 1)
        return disp_env(my_shell->env, com);
    if (stock > 3){
        my_puterror("setenv: Too many arguments.\n");
        return 1;
    }
    if (stock == 2)
        return set_env_error(my_shell, com[1], NULL);
    else
        return set_env_error(my_shell, com[1], com[2]);
}
