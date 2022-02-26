# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msessa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/12 09:04:04 by msessa            #+#    #+#              #
#    Updated: 2020/12/13 17:48:34 by msessa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c ft_init_converter.c ft_is_number.c ft_is_space.c ft_is_printable.c ft_valid_dict.c ft_strcpy.c ft_semantic_check.c ft_create_dict.c ft_valid_number.c set_keys.c ft_dict_valid_syntax.c ft_strlen.c ft_putstr.c ft_printer.c ft_p_digits.c ft_sort_dict.c ft_strcmp.c ft_number_too_big.c ft_check_exact_match.c ft_bonus.c ft_stdin.c

OBJS	= ${SRCS:.c=.o}

DEPS	= rush_02.h

NAME	= rush-02

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

.PHONY:		all clean fclean

