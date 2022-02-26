/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_safe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcassis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:48:34 by jcassis           #+#    #+#             */
/*   Updated: 2020/12/05 14:59:41 by jcassis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#define N 4

extern int g_board[N][N];

bool	is_safe(int row, int col, int nbr)
{
	int i;
	int j;

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
