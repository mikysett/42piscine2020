/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_header.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcassis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:07:37 by jcassis           #+#    #+#             */
/*   Updated: 2020/12/14 12:42:33 by jcassis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_is_printable(char c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}

int		ft_check_valid_labels(void)
{
	if (!ft_is_printable(g_labels.empty)
		|| !ft_is_printable(g_labels.obst)
		|| !ft_is_printable(g_labels.full))
		return (0);
	if (g_labels.empty == g_labels.obst
		|| g_labels.obst == g_labels.full
		|| g_labels.full == g_labels.empty)
		return (0);
	return (1);
}

int		ft_is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_check_nb_lines(char *map_str, int pos)
{
	int i;
	int res;

	res = 0;
	i = pos;
	while (i >= 0)
	{
		if (!ft_is_number(map_str[i]))
			return (0);
		i--;
	}
	i++;
	while (i <= pos)
	{
		res = res * 10 + (map_str[i] - '0');
		i++;
	}
	g_nb_lines = res;
	return (1);
}

int		ft_init_header(char *map_str)
{
	int i;

	i = 0;
	while (map_str[i] != '\0' && map_str[i] != '\n')
		i++;
	if (i < 4 || map_str[i] != '\n')
		return (0);
	i--;
	g_labels.full = map_str[i--];
	g_labels.obst = map_str[i--];
	g_labels.empty = map_str[i--];
	if (!(ft_check_valid_labels()))
		return (0);
	if (!(ft_check_nb_lines(map_str, i)))
		return (0);
	return (1);
}
