/*
** EPITECH PROJECT, 2023
** flag_l_droit.c
** File description:
** écrit les droit de chaque fichier
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

static void droit3(char *filename)
{
    struct stat sb;

    stat(filename, &sb);
    if (sb.st_mode && S_IROTH != 0)
        my_putchar('r');
    else
        my_putchar('-');
    if (sb.st_mode && S_IWOTH != 0)
        my_putchar('w');
    else
        my_putchar('-');
    if (sb.st_mode && S_IXOTH != 0)
        my_putchar('x');
    else
        my_putchar('-');
}

static void droit2(char *filename)
{
    struct stat sb;

    stat(filename, &sb);
    if (sb.st_mode && S_IRGRP != 0)
        my_putchar('r');
    else
        my_putchar('-');
    if (sb.st_mode && S_IWGRP != 0)
        my_putchar('w');
    else
        my_putchar('-');
    if (sb.st_mode && S_IXGRP != 0)
        my_putchar('x');
    else
        my_putchar('-');
    droit3(filename);
}

void droit(char *filename)
{
    struct stat sb;

    stat(filename, &sb);
    if (sb.st_mode && S_IRUSR != 0)
        my_putchar('r');
    else
        my_putchar('-');
    if (sb.st_mode && S_IWUSR != 0)
        my_putchar('w');
    else
        my_putchar('-');
    if (sb.st_mode && S_IXUSR != 0)
        my_putchar('x');
    else
        my_putchar('-');
    droit2(filename);
}
