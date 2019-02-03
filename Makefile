GCC		=	gcc

CFLAGS		=	-I ./Include

RM		=	rm -rf

SRC		=	./src/main.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-W -Wall -Wextra -fPIC
CFLAGS		+=	-I ./include

NAME		=	./libmy_malloc.so

all:			$(NAME)

$(NAME):		$(OBJ)
			$(GCC) -shared -o $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
