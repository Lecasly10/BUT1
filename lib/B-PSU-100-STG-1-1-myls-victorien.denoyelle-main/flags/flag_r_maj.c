/*
** EPITECH PROJECT, 2023
** flag_r_maj.c
** File description:
** flag_r_maj
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

static void recursif(char **tab, char *precedent)
{
    struct stat sb;

    for (int i = 0; tab[i] != NULL; i++) {
        stat(tab[i], &sb);
        if (S_ISDIR(sb.st_mode)) {
            my_putchar('\n');
            flag_r_maj(tab[i], precedent);
        }
    }
}

void rajout_ligne(char *filename)
{
    char **tab = malloc(sizeof(char *) * nb_f(filename) + 2);
    struct dirent *dir;
    DIR *d = opendir(filename);
    int i = 0;

    dir = readdir(d);
    while (dir != 0) {
        if (dir->d_name[0] != '.') {
            tab[i] = dir->d_name;
            my_putstr(dir->d_name);
            my_putchar(' ');
            i++;
        }
        dir = readdir(d);
    }
    my_putchar('\n');
    tab[i] = NULL;
    recursif(tab, filename);
    free(tab);
    closedir(d);
}

int flag_r_maj(char *filename, char *precedent)
{
    if (precedent != filename) {
        my_putstr(precedent);
        my_putchar('/');
    }
    my_putstr(filename);
    my_putstr(":\n");
    rajout_ligne(filename);
    return 0;
}
