/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 09:44:17 by msessa            #+#    #+#             */
/*   Updated: 2020/12/06 09:44:22 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#define N 4

typedef struct	s_point
{
	int row;
	int col;
}				t_point;

int				g_board[N][N];
int				g_headers[N][N];

void			ft_putchar(char c);
void			printer(void);
bool			obvious_4(int headers[N][N]);
bool			is_safe(int row, int col, int nbr);
void			print_headers(void);
bool			set_obvious(void);
bool			ft_init_headers(char *h);
t_point			set_next_position(t_point p);
bool			try_solutions(t_point p);

int				main(int argc, char **argv)
{
	t_point	first_position;

	first_position.row = 0;
	first_position.col = 0;
	if (argc != 2 || !ft_init_headers(argv[1]) || !set_obvious()
		|| !try_solutions(set_next_position(first_position)))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (0);
}
