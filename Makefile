##
## Makefile for bistromator in /home/theis_p/bistromator
## 
## Made by Paul THEIS
## Login   <theis_p@epitech.net>
## 
## Started on  Thu Oct 29 02:29:58 2015 Paul THEIS
## Last update Sun Nov  1 22:34:31 2015 Paul THEIS
## Last update Thu Oct 29 17:40:30 2015 Paul THEIS
##

SRCS	=	main.c				\
		list.c				\
		list_tool.c			\
		stack.c				\
		do/do_get.c			\
		do/do_add.c			\
		do/do_mul.c			\
		do/do_div.c			\
		do/do_gear.c			\
		do/do_base.c			\
		do/do_switch.c			\
		do/do_sub.c			\
		do/do_tool.c			\
		do/do_work.c			\
		do/do_dec.c			\
		checkator/checkator_check.c	\
		checkator/checkator_tool.c	\
		scriptor/errator.c		\
		scriptor/debugator.c		\
		scriptor/debugator2.c		\
		scriptor/memor.c		\
		aff_list/aff_list.c

OBJS	=	$(addprefix src/, $(SRCS:.c=.o))

LIBS	=	-Llib -lmy

NAME	=	calc

RM	=	rm -f

CC	=	gcc -Ofast

CFLAGS	=	-W -Wall -Werror -Wextra

CFLAGS	+=	-ansi -pedantic -g

CFLAGS	+=	-Iinclude/

CFLAGS	+=	$(LIBS)

FLAGS	=	$(LIBS)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(FLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
