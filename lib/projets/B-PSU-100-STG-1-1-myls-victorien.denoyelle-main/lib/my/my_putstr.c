/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** my_putstr
*/

int my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return 0;
}
