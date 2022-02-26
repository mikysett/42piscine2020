/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:05:00 by msessa            #+#    #+#             */
/*   Updated: 2020/12/01 20:49:41 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define N 10

void	block_places(int places[N][N], int x, int y);
void	free_places(int places[N][N], int x, int y);
void	print_solution(int *board);
int		find_solutions(int *board, int places[N][N], int q, int solutions);
int		ft_ten_queens_puzzle(void);

void	block_places(int places[N][N], int x, int y)
{
	int i;
	int j;

	i = x + 1;
	j = 1;
	while (i < N)
	{
		if (places[y][i] == 0)
			places[y][i] = x + 1;
		if (y - j >= 0 && places[y - j][i] == 0)
			places[y - j][i] = x + 1;
		if (y + j < N && places[y + j][i] == 0)
			places[y + j][i] = x + 1;
		j++;
		i++;
	}
}

void	free_places(int places[N][N], int x, int y)
{
	int i;
	int j;

	i = x + 1;
	j = 1;
	while (i < N)
	{
		if (places[y][i] == x + 1)
			places[y][i] = 0;
		if (y - j >= 0 && places[y - j][i] == x + 1)
			places[y - j][i] = 0;
		if (y + j < N && places[y + j][i] == x + 1)
			places[y + j][i] = 0;
		j++;
		i++;
	}
}

void	print_solution(int *board)
{
	int		i;
	char	digit;

	i = 0;
	while (i < N)
	{
		digit = board[i] + '0';
		write(1, &digit, 1);
		i++;
	}
	write(1, "\n", 1);
}

int		find_solutions(int *board, int places[N][N], int q, int solutions)
{
	int i;

	i = 0;
	while (i < N)
	{
		if (places[i][q] == 0)
		{
			board[q] = i;
			if (q < N - 1)
			{
				block_places(places, q, i);
				solutions = find_solutions(board, places, q + 1, solutions);
				free_places(places, q, i);
			}
			else
			{
				print_solution(board);
				solutions++;
			}
			board[q] = -1;
		}
		i++;
	}
	return (solutions);
}

int		ft_ten_queens_puzzle(void)
{
	int board[N];
	int places[N][N];
	int i;
	int j;

	i = 0;
	while (i < N)
	{
		board[i] = -1;
		j = 0;
		while (j < N)
		{
			places[i][j] = 0;
			j++;
		}
		i++;
	}
	return (find_solutions(board, places, 0, 0));
}
