##
## EPITECH PROJECT, 2018
## makefile
## File description:
## lib
##

SRC	=	src/my_hunter.c \
	    src/creation.c  \
	    src/vector.c    \
	    src/hearts_management.c \
	    src/draw_and_display.c  \
	    src/tools_functions.c   \
	    src/move_rect.c

NAME	=	my_hunter

OBJ	=   $(SRC:.c=.o)

COMPIL	=	-lmy -Llib/my -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

CFLAGS	=	-W -Wall  -Wextra -g -I include/

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		gcc -o $(NAME) $(OBJ) $(CFLAGS) $(COMPIL)

clean:
		rm -f $(OBJ)
		rm -rf *~
		rm -rf src/*~

fclean:
		make clean
		make fclean -C lib/my
		rm -f $(NAME)

re:		fclean all
