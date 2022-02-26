/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_headers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 09:45:18 by msessa            #+#    #+#             */
/*   Updated: 2020/12/06 09:45:20 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#define N 4

extern int g_board[N][N];
extern int g_headers[N][N];

bool	ft_init_headers(char *h)
{
	int i;
	int h_line;
	int h_col;

	i = 0;
	h_line = 0;
	h_col = 0;
	while (h[i])
	{
		if (((i + 1) % 2 == 0 && h[i] != ' ')
			|| ((i + 1) % 2 == 1 && (h[i] < '1' || h[i] > '0' + N))
			|| i > N * 8 - 2)
			return (false);
		if ((i + 1) % 2 == 1)
			g_headers[h_line][h_col++] = h[i] - '0';
		if (h_col > N - 1)
		{
			h_line++;
			h_col = 0;
		}
		i++;
	}
	if (i != N * 8 - 1)
		return (false);
	return (true);
}
