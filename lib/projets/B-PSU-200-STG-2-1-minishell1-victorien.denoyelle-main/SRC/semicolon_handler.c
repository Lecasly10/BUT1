/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-thibaut.louis
** File description:
** semicolon_handler.c
*/

#include "../include/my.h"

static int is_quit_error(char **com)
{
    if (!my_isdigit(com[1][0])){
        my_puterror("exit: Expression Syntax.\n");
        return 1;
    }
    if (!my_str_isnum(com[1])){
        my_puterror("exit: Badly formed number.\n");
        return 1;
    }
    return 0;
}

static int quit(mysh_t *my_shell, char **com)
{
    int tmp_tabl;
    int exit_code = 0;

    tmp_tabl = arr_len(com);
    if (tmp_tabl == 2){
        if (is_quit_error(com))
            return 1;
        exit_code = my_getnbr(com[1]);
    }
    if (tmp_tabl >= 3){
        my_puterror("exit: Expression Syntax.\n");
        return 1;
    }
    my_shell->exit = 2;
    return exit_code;
}

static int check_builtin(char **com)
{
    if (com == NULL)
        return 0;
    if (my_strcmp(com[0], "cd") == 0)
        return 1;
    if (my_strcmp(com[0], "setenv") == 0)
        return 1;
    if (my_strcmp(com[0], "unsetenv") == 0)
        return 1;
    if (my_strcmp(com[0], "exit") == 0)
        return 1;
    return 0;
}

int check_com(char **com, mysh_t *my_shell)
{
    int exit_code = -1;

    if (com == NULL)
        return 0;
    if (my_strcmp(com[0], "env") == 0)
        exit_code = disp_env(my_shell->env, com);
    if (my_strcmp(com[0], "cd") == 0)
        exit_code = find_path(my_shell, com);
    if (my_strcmp(com[0], "setenv") == 0)
        exit_code = set_env_officiel(my_shell, com);
    if (my_strcmp(com[0], "unsetenv") == 0)
        exit_code = unset_env_offciel(my_shell, com);
    if (my_strcmp(com[0], "exit") == 0)
        exit_code = quit(my_shell, com);
    if (exit_code == -1)
        exit_code = print(my_shell, com);
    return exit_code;
}

static int call_builtin(mysh_t *my_shell, char **command_array)
{
    char **cut_command = my_str_to_word_array_upgrade(command_array[0], ' ',
    '\t');
    int exit_code;

    if (check_builtin(cut_command))
        exit_code = check_com(cut_command, my_shell);
    free_tabl(cut_command);
    return exit_code;
}

int semicolon_handler(mysh_t *my_shell, char *line)
{
    char **command_array = NULL;
    char **command_slice = NULL;
    int exit_code = 0;

    command_slice = my_str_to_word_array_upgrade(line, ';', ';');
    for (int i = 0; command_slice[i] != NULL; i++) {
        command_array = my_str_to_word_array_upgrade(command_slice[i],
    '|', '|');
        if (arr_len(command_array) == 1)
            exit_code = call_builtin(my_shell, command_array);
        free_tabl(command_array);
    }
    free_tabl(command_slice);
    return exit_code;
}
