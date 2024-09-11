/*
** EPITECH PROJECT, 2023
** flag_a.c
** File description:
** flag a de my_ls
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


int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
    }
    return i;
}

int print_str(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        if (tab[i + 1] != NULL) {
            my_putchar(' ');
            my_putchar(' ');
        }
    }
    my_putchar('\n');
    return 0;
}

void flag_a(char *str, char *filename)
{
    struct dirent *dir;
    DIR *d = opendir(filename);
    char **tab = malloc(sizeof(char *) * nb_f(filename) + 1);
    int i = 0;

    dir = readdir(d);
    for (; dir != NULL; i++) {
        tab[i] = (dir->d_name);
        dir = readdir(d);
    }
    closedir(d);
    tab[i] = NULL;
    print_str(tab);
}
