# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msessa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/08 10:59:58 by msessa            #+#    #+#              #
#    Updated: 2020/12/16 08:23:30 by msessa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c ft_handle_files.c ft_handle_reads.c ft_print_error.c ft_print_last_line.c ft_print_line.c ft_print_pos_mem.c ft_print_str.c ft_strcmp.c ft_strcpy.c

OBJS	= ${SRCS:.c=.o}

NAME	= ft_hexdump

DEPS	= ft_hexdump.h

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

re:			fclean all

.PHONY:		all clean fclean re
