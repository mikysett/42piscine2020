/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcassis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:21:30 by jcassis           #+#    #+#             */
/*   Updated: 2020/12/14 17:23:42 by jcassis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_alloc_globals(void)
{
	int i;

	i = 0;
	g_map = malloc(sizeof(char *) * g_nb_lines);
	g_squares = malloc(sizeof(int *) * g_nb_lines);
	if (!g_map || !g_squares)
		return (0);
	while (i < g_nb_lines)
	{
		g_map[i] = malloc(sizeof(char) * g_nb_columns);
		g_squares[i] = malloc(sizeof(int) * g_nb_columns);
		if (!g_map[i] || !g_squares[i])
			return (0);
		i++;
	}
	return (1);
}

int		ft_convert_box(char c_box)
{
	if (c_box == g_labels.obst)
		return (0);
	return (1);
}

void	ft_init_globals(char *map_str)
{
	int sel_row;
	int sel_col;

	sel_row = 0;
	sel_col = 0;
	while (*map_str != '\n')
		map_str++;
	map_str++;
	while (sel_row < g_nb_lines)
	{
		if (sel_col == g_nb_columns)
		{
			sel_col = 0;
			sel_row++;
			map_str++;
		}
		else
		{
			g_map[sel_row][sel_col] = *map_str;
			g_squares[sel_row][sel_col] = ft_convert_box(*map_str);
			sel_col++;
			map_str++;
		}
	}
}

void	ft_init_map(char *map_str)
{
	t_square	square;

	if (!ft_init_header(map_str)
		|| !ft_check_map(map_str))
	{
		ft_file_error();
		return ;
	}
	else
	{
		if (!ft_alloc_globals())
		{
			ft_file_error();
			return ;
		}
		ft_init_globals(map_str);
		square = ft_find_square();
		ft_fill_map(square);
		ft_free_globals();
	}
}
