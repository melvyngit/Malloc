CC		=	gcc

RM		=	rm -rf

CFLAGS		=	-I ./Include

SRCS		=	./src/mutex_gestion.c		\
			./src/chunk_management.c	\
			./src/size_alignment.c		\
			./src/malloc.c			\
			./src/free.c

OBJS		=	$(SRCS:.c=.o)

CFLAGS		+=	-I ./include
CFLAGS		+=	-W -Wall -Wextra -Werror -fPIC

NAME		=	./libmy_malloc.so

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CC) -shared -o $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
