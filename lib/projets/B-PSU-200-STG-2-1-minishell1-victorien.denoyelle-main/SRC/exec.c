/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-thibaut.louis
** File description:
** exec.c
*/

#include "../include/my.h"

static int path_validator(char *name_bi)
{
    struct stat buf;
    int fd = stat(name_bi, &buf);

    if (fd == -1){
        my_puterror(name_bi);
        my_puterror(": Command not found.\n");
        return 1;
    }
    if (!S_ISREG(buf.st_mode) || access(name_bi, X_OK) == -1){
        my_puterror(name_bi);
        my_puterror(": Permission denied.\n");
        return 1;
    }
    return 0;
}

static int exit_signal(int status)
{
    if (WCOREDUMP(status)){
        my_puterror("Segmentation fault (core dumped)\n");
        return 139;
    } else {
        my_puterror("Segmentation fault\n");
        return 139;
    }
}

int print(mysh_t *my_shell, char *name_bi, char **av)
{
    int id;
    int status;

    if (path_validator(name_bi) == 1)
        return 1;
    id = fork();
    if (id > 0) {
        waitpid(id, &status, 0);
        if (WIFSIGNALED(status))
            return exit_signal(status);
        if (WIFEXITED(status))
            return WEXITSTATUS(status);
    } else {
        execve(name_bi, av, my_shell->env);
        exit(1);
    }
}

char *path_finding(mysh_t *my_shell, char *name)
{
    char *result;

    if (my_shell->path == NULL)
        return NULL;
    for (int i = 0; my_shell->path[i] != NULL; i++) {
        result = my_strdup(my_shell->path[i]);
        if (my_shell->path[i][my_strlen(my_shell->path[i]) - 1] == '/')
            result = my_str_cat2(result, name);
        else
            result = my_str_cat(result, name, '/');
        if (access(result, X_OK) != -1)
            return result;
        free(result);
    }
    return NULL;
}

int verif_exec(mysh_t *my_shell, char **av)
{
    char *name;
    int exit_code;

    if (access(av[0], F_OK) != -1)
        name = my_strdup(av[0]);
    else
        name = path_finding(my_shell, av[0]);
    if (name == NULL){
        my_puterror(av[0]);
        my_puterror(": Command not found.\n");
        return 1;
    }
    exit_code = print(my_shell, name, av);
    free(name);
    return exit_code;
}
