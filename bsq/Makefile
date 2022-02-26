# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msessa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/12 09:04:04 by msessa            #+#    #+#              #
#    Updated: 2020/12/16 12:12:18 by msessa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c ft_check_map.c ft_file_error.c ft_fill_map.c ft_find_square.c ft_free_globals.c ft_handle_files.c ft_init_map.c ft_stdin.c ft_strlen.c ft_init_header.c

OBJS	= ${SRCS:.c=.o}

DEPS	= bsq.h

NAME	= bsq

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

${NAME}:	${DEPS} ${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

.PHONY:		all clean fclean

