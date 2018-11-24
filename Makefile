# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anrzepec <anrzepec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/17 19:12:20 by anrzepec          #+#    #+#              #
#    Updated: 2018/11/24 17:59:38 by anrzepec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	fillit

SRC 	=  srcs/main.c \
		   srcs/outputs.c \
		   srcs/inputs.c \
		   srcs/checks.c

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

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: re all fclean clean
