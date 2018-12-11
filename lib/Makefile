##
## EPITECH PROJECT, 2018
## makefile
## File description:
## lib
##

SRC	=	src/file.c	\	 #à changer
		src/file2.c	\	 #à changer
		src/file3.c		 #à changer

NAME	=	Day

OBJ	=	$(SRC:.c=.o)

COMPIL	=	-lmy -Llib/my

CFLAGS	=	-W -Wall -Werror -Wextra -I include/

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		make clean
		gcc -o $(NAME) $(OBJ) $(COMPIL) $(CFLAGS)

clean:
		rm -f $(OBJ)
		rm -rf *~
		rm -rf src/*~

fclean:		clean
		make fclean -C lib/my
		rm -f $(NAME)

re:		fclean all
