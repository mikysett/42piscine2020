/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcassis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:06:46 by jcassis           #+#    #+#             */
/*   Updated: 2020/12/14 15:33:07 by jcassis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_printer(void)
{
	int i;
	int j;

	i = 0;
	while (i < g_nb_lines)
	{
		j = 0;
		while (j < g_nb_columns)
		{
			write(1, (g_map[i] + j), 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_fill_map(t_square square)
{
	int i;
	int j;

	i = square.row - square.size + 1;
	while (i <= square.row)
	{
		j = square.col - square.size + 1;
		while (j <= square.col)
		{
			g_map[i][j] = g_labels.full;
			j++;
		}
		i++;
	}
	ft_printer();
}
