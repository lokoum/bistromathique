##
## Makefile for makefile in /home/theis_p/git/Piscine_C_J10
## 
## Made by Paul THEIS
## Login   <theis_p@epitech.net>
## 
## Started on  Fri Oct  9 09:30:41 2015 Paul THEIS
## Last update Tue Oct 13 20:22:22 2015 Paul THEIS
##

AR	=	ar rc

CC	=	gcc

NAME	=	libmy.a

RM      =       rm -f

SRC	=	my_find_prime_sup.c	\
		my_getnbr.c		\
		my_isneg.c		\
		my_is_prime.c		\
		my_power_rec.c		\
		my_putchar.c		\
		my_put_nbr.c		\
		my_putstr.c		\
		my_revstr.c		\
		my_showmem.c		\
		my_show_str.c		\
		my_sort_int_tab.c	\
		my_square_root.c	\
		my_strcapitalize.c	\
		my_strcat.c		\
		my_strcmp.c		\
		my_strcpy.c		\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isnum.c		\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_strlcat.c		\
		my_strlen.c		\
		my_strlowcase.c		\
		my_strncat.c		\
		my_strncmp.c		\
		my_strncpy.c		\
		my_strstr.c		\
		my_strupcase.c		\
		my_swap.c		\

OBJ	=	$(SRC:.c=.o)

INC	=	../../include/

$(NAME):	$(OBJ)
		$(AR) $(NAME) $(OBJ)
		ranlib libmy.a
		mkdir $(INC)
		mv $(NAME) ../
		cp my.h $(INC)
		cp mylist.h $(INC)

all:            $(NAME)

clean:		
		$(RM) $(OBJ)

fclean:		clean
		rm -Rf $(INC)
		$(RM) $(NAME)
		$(RM) ../$(NAME)

re:		fclean all
