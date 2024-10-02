/*
** EPITECH PROJECT, 2023
** flag_r.c
** File description:
** flag_r
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdint.h>
#include <sys/sysmacros.h>
#include <time.h>

int my_strlen_tab(char **str)
{
    int i = 0;

    for (; str[i] != NULL; i++) {
    }
    return i;
}

int flag_r(char *filename)
{
    int k = nb_f(filename) - 1;
    char **tab = malloc(sizeof(char *) * nb_f(filename) + 2);
    struct dirent *dir;
    DIR *d = opendir(filename);
    int i = 0;

    dir = readdir(d);
    while (dir != 0) {
        if (dir->d_name[0] != '.') {
            tab[k - i] = (dir->d_name);
            i++;
        }
        dir = readdir(d);
    }
    tab[k + 1] = NULL;
    print_str(tab);
    free(tab);
    closedir(d);
    return 0;
}
