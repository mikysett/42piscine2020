# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msessa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/07 09:00:29 by msessa            #+#    #+#              #
#    Updated: 2020/12/08 20:00:45 by msessa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c ft_display_file.c ft_print_str.c

OBJS		= ${SRCS:.c=.o}

NAME		= ft_display_file

DEPS		= ft_display_file.h

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

${NAME}:	${DEPS} ${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

