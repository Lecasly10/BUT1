/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-navy-noe.carabin
** File description:
** my.h
*/

#ifndef MY
    #define MY

    #include <stdarg.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <dirent.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <signal.h>

void my_putchar(char);
int my_put_nbr(int);
int my_putstr(char const *);
int my_strlen(const char *str);
void aff_point(const char *name);
void lsflag_l(const char *chemin);
int my_strcmp(const char *s1, const char *s2);
void lsflag_rmaj(const char *chemin);
char *my_strdup(const char *str);
int my_compute_power_it(int nb, int p);
int my_str_to_int(char *str);
int my_min(int a, int b, int c);
int my_getnbr(const char *str);
int my_isdigit(int c);
int compt_tabl(char **args);
int diff(char *arg);
int flag_pourc(void);
char *my_revstr(char *str);
char **my_str_to_word_array(char const *str);
char *my_str_cat(char *str1, char *str2, char sep);
int arr_len(char **result);
char **tabl_copy(char **tabl);
void aff_tabl(char **result);
void free_tabl(char **result);
char *my_strlowcase(char *str);
char *my_strupcas(char *str);
int int_size(long long int nbr);
int my_str_isnum(char const *str);
char *my_substr(char *str1, int final, int begin);
char *clean_str(char *str, char sep1, char sep2);
int skip(char *str, int i, char sep1, char sep2);
char *my_str_cat2(char *str1, char *str2);
char **my_str_to_word_array_upgrade(char *str, char sep1, char sep2);
int my_strncmp(const char *str1, const char *str2, int n);
void clean_array(char ***tabl);

#endif /*MY*/
