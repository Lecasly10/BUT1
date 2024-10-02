/*
** EPITECH PROJECT, 2023
** flag_t.c
** File description:
** flag_t
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

int nb_f(char *filename)
{
    struct dirent *dir;
    DIR *d = opendir(filename);
    int cont = 0;

    dir = readdir(d);
    while (dir != NULL) {
        if ((dir->d_name)[0] != '.')
            cont++;
        dir = readdir(d);
    }
    closedir(d);
    return cont;
}

static int compare_dates(const void *a, const void *b)
{
    struct dirent **d1 = (struct dirent **)a;
    struct dirent **d2 = (struct dirent **)b;
    struct stat s1;
    struct stat s2;

    stat((*d1)->d_name, &s1);
    stat((*d2)->d_name, &s2);
    return s2.st_mtime - s1.st_mtime;
}

static struct dirent **tri_time(struct dirent **entries, int num_entries)
{
    struct dirent *key;
    int j;

    for (int i = 1; i < num_entries; i++) {
        key = entries[i];
        j = i - 1;
        while (j >= 0 && compare_dates(&entries[j], &key) < 0) {
            entries[j + 1] = entries[j];
            j = j - 1;
        }
        entries[j + 1] = key;
    }
    return entries;
}

static int print_t(struct dirent **entries, int num_entries, DIR *directory)
{
    tri_time(entries, num_entries);
    for (int i = 0; i < num_entries; i++) {
        my_putstr(entries[i]->d_name);
        my_putstr("  ");
    }
    my_putchar('\n');
    closedir(directory);
    return 0;
}

int flag_t(char *filename)
{
    DIR *directory = opendir(filename);
    struct dirent *entry;
    int num_entries = 0;
    struct dirent **entries = malloc(sizeof(struct dirent *)\
    * nb_f(filename) + 1);

    entry = readdir(directory);
    while (entry != NULL) {
        if (entry->d_name[0] != '.') {
            num_entries++;
            entries[num_entries - 1] = entry;
        }
        entry = readdir(directory);
    }
    return print_t(entries, num_entries, directory);
}
