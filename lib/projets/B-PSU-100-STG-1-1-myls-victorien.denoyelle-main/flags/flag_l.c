/*
** EPITECH PROJECT, 2023
** flag_l.c
** File description:
** flag_l.c
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

static void date(char *filename)
{
    struct stat sb;
    char **str;

    stat(filename, &sb);
    str = ctime(sb.st_mtime);
    my_putstr(str);
}

static void name_memory(char *filename)
{
    struct stat sb;

    stat(filename, &sb);
    my_putchar(' ');
    my_put_nbr(sb.st_nlink);
    my_putchar(' ');
    my_put_nbr(sb.st_uid);
    my_putchar(' ');
    my_put_nbr(sb.st_gid);
    my_putchar(' ');
    my_put_nbr(sb.st_blocks * 512);
    my_putchar(' ');
    date(filename);
    my_putchar(' ');
    my_putstr(filename);
    my_putchar('\n');
}

static void flag(char **tab, char *filename)
{
    struct dirent *dir;
    DIR *d = opendir(filename);
    int i = 0;

    dir = readdir(d);
    my_putstr(filename);
    my_putchar(':');
    my_putchar('\n');
    my_putchar('1');
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        droit(tab[i]);
        name_memory(tab[i]);
    }
    my_putchar('2');
}

static int taille_file(char *filename)
{
    DIR *directory;
    struct dirent *entry;
    int count;

    entry = readdir(directory);
    while (entry != NULL) {
        if (entry->d_name[0] != '.' && entry->d_name[1] != '.') {
            count++;
        }
        entry = readdir(directory);
    }
    closedir(directory);
    return count;
}

int flag_l(char *filename)
{
    struct dirent *dir;
    DIR *d = opendir(filename);
    int i = 0;
    char *tab = malloc(sizeof(char *) * taille_file(filename));

    dir = readdir(d);
    my_putchar('3');
    while (dir != 0) {
        if (dir->d_name[0] != '.') {
            my_putchar('4');
            tab[i] = dir->d_name;
        }
        i++;
        dir = readdir(d);
    }
    closedir(d);
    flag(tab, filename);
    return 0;
}
