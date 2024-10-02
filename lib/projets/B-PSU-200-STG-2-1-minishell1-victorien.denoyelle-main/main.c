/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-thibaut.louis
** File description:
** main.c
*/

#include "include/my.h"

int disp_env(char **env, char **com)
{
    if (arr_len(com) != 1){
        my_puterror("env: '");
        my_puterror(com[1]);
        my_puterror("': No such file or directory\n");
        return 1;
    }
    for (int i = 0; env[i] != NULL; i++) {
        my_putstr(env[i]);
        my_putchar('\n');
    }
    return 0;
}

static void without_last_char(char *line)
{
    int i = 0;

    for (; line[i] != '\n'; i++);
    line[i] = '\0';
}

static int open_term(mysh_t *my_shell)
{
    char *result = NULL;
    size_t res_size = 0;
    int fin;
    int exit_code;

    if (isatty(STDIN_FILENO))
        my_putstr("$> ");
    fin = getline(&result, &res_size, stdin);
    if (fin == -1) {
        my_shell->exit = 1;
        free(result);
        return 0;
    }
    without_last_char(result);
    free(result);
    return exit_code;
}

static int print_env(mysh_t *my_shell)
{
    int exit_code = 0;
    int tmp_exit = 0;

    my_shell->exit = 0;
    while (my_shell->exit == 0) {
        tmp_exit = open_term(my_shell);
        if (my_shell->exit != 1)
            exit_code = tmp_exit;
    }
    if (isatty(STDIN_FILENO))
        my_putstr("exit\n");
    return exit_code;
}

char **get_path_list(char **env)
{
    char *stock_path_list;
    char *clean_stock;
    char **result;

    stock_path_list = search_env_val(env, "PATH");
    if (stock_path_list == NULL)
        return NULL;
    clean_stock = clean_str(stock_path_list, ':', ':');
    free(stock_path_list);
    result = my_str_to_word_array_upgrade(clean_stock, ' ', '\t');
    free(clean_stock);
    return result;
}

int main(int ac, char **av, char **env)
{
    mysh_t tmp;
    int exit_code;

    if (ac != 1)
        return 84;
    tmp.env = tabl_copy(env);
    tmp.oldpath = NULL;
    tmp.path = get_path_list(env);
    exit_code = print_env(&tmp);
    free_tabl(tmp.env);
    if (tmp.oldpath != NULL)
        free(tmp.oldpath);
    if (tmp.path != NULL)
        free_tabl(tmp.path);
    return exit_code;
}
