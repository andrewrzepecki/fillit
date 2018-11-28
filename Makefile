# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anrzepec <anrzepec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/17 19:12:20 by anrzepec          #+#    #+#              #
#    Updated: 2018/11/28 14:07:35 by ccepre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	fillit

SRC 	=  main.c \
		   outputs.c \
		   inputs.c \
		   checks.c \
		   set_tetris.c \
		   lst_functions.c \
		   tools.c \
		   solver.c 

OBJS	=	$(SRC:.c=.o)

CC		=	gcc

CFLAGS	+=	-Werror -Wall -Wextra

RM		=	rm -f

LIB		=	libft/libft.a

all:		$(LIB) $(NAME)

%.o:		%.c	
			$(CC) $(CFLAGS) -c $< -o $@

$(LIB):	
			make -C libft/

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(LIB)

fcleanlib:  cleanlib
			make fclean -C libft/

cleanlib:
			make clean -C libft/

clean:		cleanlib
			$(RM) $(OBJS)

fclean:		fcleanlib clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: re all fclean clean
