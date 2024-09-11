/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-thibaut.louis
** File description:
** print_return.c
*/

#include "../include/my.h"

int my_puterror(char *str)
{
    write(2, str, my_strlen(str));
}
