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

LNAME		=	libmy_malloc.so

PWD		=	`pwd`

SRCS		=	./src/mutex_gestion.c		\
			./src/chunk_management.c	\
			./src/size_alignment.c		\
			./src/malloc.c			\
			./src/free.c

OBJS		=	$(SRCS:.c=.o)

CFLAGS		+=	-I ./include
CFLAGS		+=	-W -Wall -Wextra -Werror -fPIC

NAME		=	libmy_malloc_$(shell uname).so

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CC) -shared -o $(NAME) $(OBJS)
			ln -s $(PWD)/$(NAME) $(LNAME)

clean:
			$(RM) $(OBJS) $(LNAME)

fclean:			clean
			$(RM) $(NAME) $(LNAME)

re:			fclean all

.PHONY:			all clean fclean re
