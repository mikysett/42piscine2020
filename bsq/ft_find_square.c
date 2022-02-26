/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:37:58 by msessa            #+#    #+#             */
/*   Updated: 2020/12/14 18:38:02 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void		ft_set_square_size(int row, int col)
{
	int min_nb;

	min_nb = g_squares[row][col - 1];
	if (g_squares[row - 1][col - 1] < min_nb)
		min_nb = g_squares[row - 1][col - 1];
	if (g_squares[row - 1][col] < min_nb)
		min_nb = g_squares[row - 1][col];
	g_squares[row][col] = min_nb + 1;
}

t_square	ft_biggest_square(void)
{
	int			row;
	int			col;
	t_square	square;

	row = 0;
	square.size = 0;
	while (row < g_nb_lines)
	{
		col = 0;
		while (col < g_nb_columns)
		{
			if (g_squares[row][col] > square.size)
			{
				square.col = col;
				square.row = row;
				square.size = g_squares[row][col];
			}
			col++;
		}
		row++;
	}
	return (square);
}

t_square	ft_find_square(void)
{
	int row;
	int col;

	row = 1;
	while (row < g_nb_lines)
	{
		col = 1;
		while (col < g_nb_columns)
		{
			if (g_squares[row][col] != 0)
				ft_set_square_size(row, col);
			col++;
		}
		row++;
	}
	return (ft_biggest_square());
}
