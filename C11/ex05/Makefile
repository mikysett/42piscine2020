# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msessa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/08 20:32:07 by msessa            #+#    #+#              #
#    Updated: 2020/12/09 09:19:17 by msessa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c ft_atoi.c do_op.c ft_operations.c ft_strlen.c ft_putstr.c ft_putnbr.c

OBJS		= ${SRCS:.c=.o}

DEPS		= do_op.h

NAME		= do-op

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

${NAME}:	${DEPS} ${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
