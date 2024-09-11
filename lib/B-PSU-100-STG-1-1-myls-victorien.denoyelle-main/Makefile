##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC     =       lib/my/my_putchar.c	\
		lib/my/my_putstr.c	\
		lib/my/my_put_nbr.c	\
		flags/flag_a.c		\
		flags/flag_l.c		\
		flags/flag_r.c		\
		flags/flag_r_maj.c	\
		flags/flag_t.c		\
		flags/flag_l_droit.c	\
		my_ls.c			\

OBJ	=       $(SRC:.c=.o)

NAME    =       my_ls

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -g

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
