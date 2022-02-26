# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msessa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/08 10:59:58 by msessa            #+#    #+#              #
#    Updated: 2020/12/09 15:59:23 by msessa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c ft_read_file.c ft_print_error.c ft_print_memory.c ft_print_str.c ft_stdin.c ft_putnbr_hex.c ft_file_size.c ft_digit_size.c ft_print_hex.c ft_skip_l.c ft_strcat.c ft_strcmp.c

OBJS	= ${SRCS:.c=.o}

NAME	= ft_hexdump

DEPS	= ft_hexdump.h

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
