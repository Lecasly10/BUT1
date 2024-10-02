/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-thibaut.louis
** File description:
** dir.c
*/

#include "../include/my.h"

static int is_folder(char *path)
{
    struct stat dos;

    stat(path, &dos);
    if (S_ISDIR(dos.st_mode))
        return 1;
    return 0;
}

int modif_dir(mysh_t *my_shell, char *path)
{
    char tmp[1024];
    char tmp2[1024];
    int sortie;

    if (is_folder_error(path))
        return 1;
    getcwd(tmp, 1024);
    if (my_shell->oldpath != NULL)
        free(my_shell->oldpath);
    my_shell->oldpath = my_strdup(tmp);
    sortie = chdir(path);
    if (sortie != 0)
        return sortie;
    getcwd(tmp2, 1024);
    set_env_error(my_shell, "PWD", tmp2);
    return 0;
}

int find_path2(mysh_t *my_shell)
{
    char *home;

    home = search_env_val(my_shell->env, "HOME");
    if (home == NULL){
        my_puterror("cd: No home directory.\n");
        return 1;
    }
    modif_dir(my_shell, home);
    free(home);
    return 0;
}

static int is_folder_error(char *path)
{
    if (access(path, F_OK) == -1){
        my_puterror(path);
        my_puterror(": No such file or directory.\n");
        return 1;
    }int modif_dir(mysh_t *my_shell, char *path)
{
    char tmp[1024];
    char tmp2[1024];
    int sortie;

    if (is_folder_error(path))
        return 1;
    getcwd(tmp, 1024);
    if (my_shell->oldpath != NULL)
        free(my_shell->oldpath);
    my_shell->oldpath = my_strdup(tmp);
    sortie = chdir(path);
    if (sortie != 0)
        return sortie;
    getcwd(tmp2, 1024);
    set_env_error(my_shell, "PWD", tmp2);
    return 0;
}
    if (access(path, R_OK) == -1){
        my_puterror(path);
        my_puterror(": Permission denied.\n");
        return 1;
    }
    if (is_folder(path) == 0){
        my_puterror(path);
        my_puterror(": Not a directory.\n");
        return 1;
    }
    return 0;
}

static int find_path3(mysh_t *my_shell)
{
    int sortie;
    char *tmp;

    if (my_shell->oldpath == NULL){
        my_puterror(": No such file or directory.\n");
        return 1;
    }
    tmp = my_strdup(my_shell->oldpath);
    sortie = modif_dir(my_shell, tmp);
    free(tmp);
    return sortie;
}

int find_path(mysh_t *my_shell, char **commande)
{
    int size = arr_len(commande);

    if (size == 1)
        return find_path2(my_shell);
    if (size > 2){
        my_puterror("cd: Too many arguments.\n");
        return 1;
    }
    if (my_strcmp(commande[1], "~") == 0)
        return find_path2(my_shell);
    if (my_strcmp(commande[1], "-") == 0)
        return find_path3(my_shell);
    return modif_dir(my_shell, commande[1]);
}
