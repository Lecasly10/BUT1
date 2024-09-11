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
    #include <sys/wait.h>

typedef struct mysh_s {
    char **env;
    char **path;
    int exit;
    char *oldpath;
} mysh_t;

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
int arr_len(char **com);
char *my_revstr(char *str);
char **my_str_to_word_array(char const *str);
char *my_str_cat(char *str1, char *str2, char sep);
int tabl_size(char **result);
char **tabl_copy(char **tabl);
void aff_tabl(char **result);
void free_tabl(char **result);
char *my_strlowcase(char *str);
char *my_strupcas(char *str);
int int_size(long long int nbr);
int my_puterror(char *str);
int my_str_isnum(char const *str);
char *search_name(char *str);
int search_env(char **env, char *search);
char *search_env_val(char **env, char *search);
int find_path(mysh_t *my_shell, char **name);
char *my_substr(char *str1, int final, int begin);
int exec(mysh_t *my_shell, char **av);
char **my_str_to_word_array_upgrade(char *str, char sep1, char sep2);
char *clean_str(char *str, char sep1, char sep2);
int skip(char *str, int i, char sep1, char sep2);
char *my_str_cat2(char *str1, char *str2);
char *path_finding(mysh_t *my_shell, char *name_bi);
int execute(mysh_t *my_shell, char *name_bi, char **av);
char **get_path_list(char **env);
int set_env_officiel(mysh_t *my_shell, char **com);
int disp_env(char **env, char **com);
int unset_env(mysh_t *my_shell, char *arg);
int unset_env_offciel(mysh_t *my_shell, char **com);
int my_strncmp(const char *str1, const char *str2, int n);
int set_env_error(mysh_t *my_shell, char *arg, char *value);
int set_env(mysh_t *my_shell, char *arg, char *value);
int change_dir(mysh_t *my_shell, char *path);
void clean_array(char ***tabl);
int semicolon_handler(mysh_t *my_shell, char *line);
int check_com(char **com, mysh_t *my_shell);
int exec_pipe(char **tmp, mysh_t *my_shell);
int error_chevron(mysh_t *my_shell, char *line);
char *path_finding(mysh_t *my_shell, char *name);

#endif /*MY*/
