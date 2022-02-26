/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_obvious.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 09:44:45 by msessa            #+#    #+#             */
/*   Updated: 2020/12/06 09:44:48 by msessa           ###   ########.fr       */
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
extern int		g_headers[N][N];

bool			is_safe_or_equal(int row, int col, int nbr);
bool			obvious_4(t_point p);
bool			set_obvious(void);

bool			is_safe_or_equal(int row, int col, int nbr)
{
	int i;
	int j;

	if (g_board[row][col] == nbr)
		return (true);
	if (g_board[row][col] != 0)
		return (false);
	j = 0;
	while (j < N)
		if (g_board[row][j++] == nbr)
			return (false);
	i = 0;
	while (i < N)
		if (g_board[i++][col] == nbr)
			return (false);
	return (true);
}

bool			obvious_4(t_point p)
{
	if (p.row == 0 && is_safe_or_equal(0, p.col, N))
		g_board[0][p.col] = N;
	else if (p.row == 1 && is_safe_or_equal(N - 1, p.col, N))
		g_board[N - 1][p.col] = N;
	else if (p.row == 2 && is_safe_or_equal(p.col, 0, N))
		g_board[p.col][0] = N;
	else if (is_safe_or_equal(p.col, N - 1, N))
		g_board[p.col][N - 1] = N;
	else
		return (false);
	return (true);
}

bool			set_obvious(void)
{
	t_point	p;

	p.row = 0;
	while (p.row < N)
	{
		p.col = 0;
		while (p.col < N)
		{
			if (g_headers[p.row][p.col] == 1)
				if (!obvious_4(p))
					return (false);
			p.col++;
		}
		p.row++;
	}
	return (true);
}
