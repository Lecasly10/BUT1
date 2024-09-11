/*
** EPITECH PROJECT, 2023
** my_ls.c
** File description:
** mon ls
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

int error(char flag)
{
    my_putstr("ls: invalid option: ");
    my_putchar(flag);
    my_putchar('\n');
    return 84;
}

static int gestion_flags(char *str, char *filename)
{
    switch (str[1]) {
    case 'a':
        return flag_a(filename);
    case 'l':
        return flag_l(filename);
    case 'R':
        return flag_r_maj(filename);
    case 'r':
        return flag_r(filename);
    case 't':
        return flag_t(filename);
    default:
        return error(str[1]);
    }
}

int gestion_d(char **argv)
{
    int i = 0;

    for (; argv[i] != 0; i++) {
        if (argv[i][0] == '-' && argv[i][1] == 'd')
            return 1;
    }
    return 0;
}

static int arguments(char **argv, char *filename, int argc)
{
    if (gestion_d(argv) == 1)
        my_putstr(".\n");
    else if (argv[1][0] == '-')
        return gestion_flags(argv[1], filename);
    else {
        my_putstr("ls: cannot access '");
        my_putstr(argv[1]);
        my_putstr("'");
        my_putchar('\n');
        return 84;
    }
    return 0;
}

int my_ls(char *filename)
{
    struct dirent *dir;
    DIR *d = opendir(filename);
    int i = 0;

    dir = readdir(d);
    while (dir != 0) {
        if (dir->d_name[0] != '.') {
            my_putstr(dir->d_name);
            my_putchar(' ');
            my_putchar(' ');
        }
        dir = readdir(d);
    }
    my_putchar('\n');
    closedir(d);
    return 0;
}

static char *gestion_r(char **argv, int argc, int i)
{
    if (argv[i][0] == '-' && (argv[i][1] == 'R' || argv[i][1] == 'r'))
        if (argc == 2)
            return ".";
        else
            return argv[argc - 1];
    else if (argv[i][0] != '-')
        return argv[i];
    else
        return ".";
}

static int verif(char **argv, int argc)
{
    int i = 1;
    char *filename = ".";

    for (; argv[i] != NULL; i++) {
        filename = gestion_r(argv, argc, i);
    }
    return arguments(argv, filename, argc);
}

int main(int argc, char **argv)
{
    if (argc == 1)
        return my_ls(".");
    else
        return verif(argv, argc);
}
