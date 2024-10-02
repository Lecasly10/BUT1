##
## EPITECH PROJECT, 2023
## B-MUL-100-STG-1-1-my_radar-thibaut.louis
## File description:
## Makefile
##

SRC	=	Pas_malloc/my_putchar.c	\
		Pas_malloc/my_strcpy.c  \
		Pas_malloc/my_strlen.c 	\
		Pas_malloc/my_put_nbr.c	\
		Pas_malloc/my_putstr.c	\
		Pas_malloc/my_strcmp.c	\
		Malloc/my_strdup.c	\
		Pas_malloc/my_compute_power_it.c	\
		Pas_malloc/my_str_to_int.c	\
		Pas_malloc/my_min.c		\
		Pas_malloc/my_isdigit.c	\
		Pas_malloc/my_getnbr.c	\
		Pas_malloc/my_revstr.c	\
		Malloc/my_str_to_word_array.c	\
		Malloc/my_str_cat.c	\
		Malloc/arrlen.c	\
		Malloc/tabl_copy.c	\
		Malloc/aff_tabl.c	\
		Malloc/free_tabl.c	\
		Pas_malloc/my_strlowcas.c	\
		Pas_malloc/my_strupcas.c	\
		Pas_malloc/size_int.c		\
		Pas_malloc/my_str_isnum.c	\
		Malloc/my_substr.c			\
		Malloc/clean_str.c			\
		Malloc/my_str_to_word_array_upgrade.c	\
		Malloc/clean_array.c	\


OBJ	=	$(SRC:.c=.o)

NAMELI	=	libmy.a

all: $(NAMELI)

$(NAMELI):	$(OBJ)
	gcc -c $(SRC) -g
	ar rc $(NAMELI) $(OBJ)
	find -name "*.o" -delete

clean:
	rm -f $(OBJ)
	rm -f libmy.a

fclean: clean
		rm -f $(NAMELI)

re: fclean all
