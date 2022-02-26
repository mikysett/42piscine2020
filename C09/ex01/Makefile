# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msessa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/07 09:00:29 by msessa            #+#    #+#              #
#    Updated: 2020/12/07 13:06:27 by msessa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c

OBJS		= ${SRCS:.c=.o}

NAME		= libft.a

INC_DIR		= includes/

DEPS 		= ${INC_DIR}ft.h

CC			= gcc -I${INC_DIR}

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

${NAME}:	${DEPS} ${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

