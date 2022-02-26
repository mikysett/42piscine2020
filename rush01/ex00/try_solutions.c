/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_solutions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 09:44:33 by msessa            #+#    #+#             */
/*   Updated: 2020/12/06 09:44:36 by msessa           ###   ########.fr       */
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

extern int		g_board[N][N];

bool			is_safe(int row, int col, int nbr);
void			printer(void);
t_point			set_next_position(t_point p);
bool			try_solutions(t_point p);
bool			is_board_valid(void);

t_point			set_next_position(t_point p)
{
	int		i;
	int		j;
	t_point	next_position;

	i = p.row;
	j = p.col;
	while (j < N)
	{
		while (i < N)
		{
			if (g_board[i][j] == 0)
			{
				next_position.row = i;
				next_position.col = j;
				return (next_position);
			}
			i++;
		}
		i = 0;
		j++;
	}
	next_position.row = -1;
	return (next_position);
}

bool			try_solutions(t_point p)
{
	int		my_number;
	t_point	next_position;

	my_number = 1;
	while (my_number <= N)
	{
		if (is_safe(p.row, p.col, my_number))
		{
			g_board[p.row][p.col] = my_number;
			next_position = set_next_position(p);
			if (next_position.row == -1 && is_board_valid())
			{
				printer();
				return (true);
			}
			if (next_position.row != -1 && try_solutions(next_position))
				return (true);
			g_board[p.row][p.col] = 0;
		}
		my_number++;
	}
	return (false);
}
