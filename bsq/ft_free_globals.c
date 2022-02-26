/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_globals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcassis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:13:56 by jcassis           #+#    #+#             */
/*   Updated: 2020/12/14 17:14:39 by jcassis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_free_globals(void)
{
	int row;

	row = 0;
	while (row < g_nb_lines)
	{
		free(g_map[row]);
		free(g_squares[row]);
		row++;
	}
	free(g_map);
	free(g_squares);
}
