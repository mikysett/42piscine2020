/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcassis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:02:46 by jcassis           #+#    #+#             */
/*   Updated: 2020/12/06 09:48:17 by jcassis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#define N 4

extern int	g_board[N][N];
extern int	g_headers[N][N];

bool	top_view(int *ptr)
{
	int i;
	int j;
	int biggest;
	int counter;

	j = 0;
	while (j < N)
	{
		i = 0;
		counter = 0;
		biggest = 0;
		while (i < N)
		{
			if (g_board[i][j] > biggest)
			{
				biggest = g_board[i][j];
				counter++;
			}
			i++;
		}
		if (counter != ptr[j++])
			return (false);
	}
	return (true);
}

bool	bot_view(int *ptr)
{
	int i;
	int j;
	int biggest;
	int counter;

	j = 0;
	while (j < N)
	{
		i = N - 1;
		counter = 0;
		biggest = 0;
		while (i >= 0)
		{
			if (g_board[i][j] > biggest)
			{
				biggest = g_board[i][j];
				counter++;
			}
			i--;
		}
		if (counter != ptr[j++])
			return (false);
	}
	return (true);
}

bool	left_view(int *ptr)
{
	int i;
	int j;
	int biggest;
	int counter;

	i = 0;
	while (i < N)
	{
		j = 0;
		counter = 0;
		biggest = 0;
		while (j < N)
		{
			if (g_board[i][j] > biggest)
			{
				biggest = g_board[i][j];
				counter++;
			}
			j++;
		}
		if (counter != ptr[i++])
			return (false);
	}
	return (true);
}

bool	right_view(int *ptr)
{
	int i;
	int j;
	int biggest;
	int counter;

	i = 0;
	while (i < N)
	{
		j = N - 1;
		counter = 0;
		biggest = 0;
		while (j >= 0)
		{
			if (g_board[i][j] > biggest)
			{
				biggest = g_board[i][j];
				counter++;
			}
			j--;
		}
		if (counter != ptr[i++])
			return (false);
	}
	return (true);
}

bool	is_board_valid(void)
{
	if (!top_view(g_headers[0]))
		return (false);
	if (!bot_view(g_headers[1]))
		return (false);
	if (!left_view(g_headers[2]))
		return (false);
	if (!right_view(g_headers[3]))
		return (false);
	return (true);
}
