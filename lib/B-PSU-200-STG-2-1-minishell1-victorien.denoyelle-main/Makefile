##
## EPITECH PROJECT, 2023
## B-MUL-100-STG-1-1-my_radar-thibaut.louis
## File description:
## Makefile
##

SRC	=	main.c	\
		SRC/search_env.c	\
		SRC/dir.c 	\
		SRC/exec.c	\
		SRC/setenv.c	\
		SRC/unsetenv.c	\
		SRC/my_puterror.c	\
		SRC/semicolon_handler.c\

OBJ	=	$(SRC:.c=.o)

NAME =	mysh

.PHONY =	all clean fclean re

all: $(NAME)

$(NAME):	$(OBJ)
	make -C lib
	gcc -o $(NAME) $(OBJ) -L lib -lmy -g

clean:
	rm -f $(OBJ)
	rm -f lib/libmy.a
	rm -f libmy.a
	rm -f mysh

fclean: clean
		rm -f $(NAME)

re: fclean all
