/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcassis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:18:38 by jcassis           #+#    #+#             */
/*   Updated: 2020/12/14 17:20:15 by jcassis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_is_label(char c)
{
	if (c == g_labels.empty
		|| c == g_labels.obst
		|| c == g_labels.full)
		return (1);
	return (0);
}

void	ft_set_nb_columns(char *map_str)
{
	int i;

	i = 0;
	while (map_str[i] != '\0' && map_str[i] != '\n')
		i++;
	g_nb_columns = i;
}

int		ft_count_nb_lines(char *map_str)
{
	int i;
	int nb_lines;
	int nb_columns;

	i = 0;
	nb_lines = 0;
	nb_columns = 0;
	while (map_str[i])
	{
		if (map_str[i] == '\n')
		{
			if (nb_columns != g_nb_columns)
				return (0);
			nb_columns = 0;
			nb_lines++;
		}
		else
		{
			nb_columns++;
			if (!ft_is_label(map_str[i]) || nb_columns > g_nb_columns)
				return (0);
		}
		i++;
	}
	return (nb_lines = nb_columns != 0 ? 0 : nb_lines);
}

int		ft_check_map(char *map_str)
{
	int nb_lines;

	nb_lines = 0;
	while (*map_str != '\n')
		map_str++;
	map_str++;
	ft_set_nb_columns(map_str);
	nb_lines = ft_count_nb_lines(map_str);
	if (nb_lines != g_nb_lines)
		return (0);
	return (1);
}
