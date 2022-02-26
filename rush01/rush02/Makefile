# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msessa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/12 09:04:04 by msessa            #+#    #+#              #
#    Updated: 2020/12/12 17:09:43 by msessa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c ft_init_converter.c ft_is_number.c ft_is_space.c ft_is_printable.c ft_valid_dict.c ft_strcpy.c ft_semantic_check.c ft_create_dict.c

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

