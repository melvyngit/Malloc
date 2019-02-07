##
## Makefile for Malloc in /root/Malloc
## 
## Made by Melvyn Covindarassou
## Login   <covind_m@etna-alternance.net>
## 
## Started on  Thu Feb  7 11:25:21 2019 Melvyn Covindarassou
## Last update Thu Feb  7 11:26:13 2019 Melvyn Covindarassou
##

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
