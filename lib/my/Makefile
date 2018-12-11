##
## EPITECH PROJECT, 2018
## makefile
## File description:
## task1
##

SRC	=	int_to_char.c			\
		my_revstr_no_display.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME) copy clean

$(NAME):	$(OBJ)
	ar  rc	$(NAME) $(OBJ)

copy:
	cp libmy.a ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
