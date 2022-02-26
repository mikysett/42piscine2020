/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 14:35:57 by msessa            #+#    #+#             */
/*   Updated: 2020/11/28 19:06:16 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	init_shapes(char *shape)
{
	shape[0] = '/';
	shape[1] = '\\';
	shape[2] = '\\';
	shape[3] = '/';
	shape[4] = '*';
	shape[5] = '*';
}

void	ft_print_line(char *shape, int x, int y, int j)
{
	int i;

	x--;
	i = 1;
	if (j == 0 || j == y - 1)
		while (i < x)
		{
			ft_putchar(shape[4]);
			i++;
		}
	else
		while (i < x)
		{
			ft_putchar(' ');
			i++;
		}
}

void	rush(int x, int y)
{
	char	shape[6];
	int		j;

	init_shapes(shape);
	j = 0;
	if (x < 1 || y < 1)
		return ;
	while (j < y)
	{
		if (j == 0)
			ft_putchar(shape[0]);
		else if (j == y - 1)
			ft_putchar(shape[1]);
		else
			ft_putchar(shape[5]);
		ft_print_line(shape, x, y, j);
		if (x > 1 && j == 0)
			ft_putchar(shape[2]);
		else if (x > 1 && j == y - 1)
			ft_putchar(shape[3]);
		else if (y > 1 && x > 1)
			ft_putchar(shape[5]);
		ft_putchar('\n');
		j++;
	}
}
