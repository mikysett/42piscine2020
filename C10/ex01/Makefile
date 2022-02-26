# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msessa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/07 17:14:02 by msessa            #+#    #+#              #
#    Updated: 2020/12/08 20:09:21 by msessa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c ft_display_file.c ft_print_str.c ft_print_error.c ft_stdin.c

OBJS	= ${SRCS:.c=.o}

NAME	= ft_cat

DEPS	= ft_cat.h

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

${NAME}:	${DEPS} ${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
