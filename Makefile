# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anrzepec <anrzepec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/17 19:12:20 by anrzepec          #+#    #+#              #
#    Updated: 2018/11/27 18:19:17 by anrzepec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	fillit

SRC 	=  srcs/main.c \
		   srcs/outputs.c \
		   srcs/inputs.c \
		   srcs/checks.c \
		   srcs/set_tetris.c \
		   srcs/lst_functions.c \
		   srcs/math.c \
		   srcs/solver.c 

OBJS	=	$(SRC:.c=.o)

CC		=	gcc

CFLAGS	+=	-Werror -Wall -Wextra

RM		=	rm -f

LIB		=	libft/libft.a

all:		$(LIB) $(NAME)

%.o:		%.c	
			$(CC) $(CFLAGS) -c $< -o $@ -Iincludes

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
