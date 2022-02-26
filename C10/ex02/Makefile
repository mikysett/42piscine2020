# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msessa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/07 20:14:16 by msessa            #+#    #+#              #
#    Updated: 2020/12/08 20:10:26 by msessa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c ft_atoi.c ft_write_file_name.c ft_display_file.c ft_print_str.c ft_print_error.c ft_stdin.c ft_tail.c

OBJS	= ${SRCS:.c=.o}

NAME	= ft_tail

DEPS	= ft_tail.h

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

${NAME}:	${DEPS} ${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
