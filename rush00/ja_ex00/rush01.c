/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcarva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:06:12 by julcarva          #+#    #+#             */
/*   Updated: 2020/11/28 17:36:38 by julcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_first_line(int x)
{
	int		i;

	ft_putchar('/');
	i = 1;
	while (i < x - 1)
	{
		ft_putchar('*');
		i++;
	}
	if (x != 1)
	{
		ft_putchar('\\');
		ft_putchar('\n');
	}
}

void	ft_print_body(int x, int y)
{
	int		i;
	int		j;

	j = 1;
	while (j < y - 1)
	{
		ft_putchar('*');
		i = 1;
		while (i < x - 1)
		{
			ft_putchar(' ');
			i++;
		}
		if (x != 1)
		{
			ft_putchar('*');
			ft_putchar('\n');
			j++;
		}
	}
}

void	ft_print_last_line(int x)
{
	int		i;

	ft_putchar('\\');
	i = 1;
	while (i < x - 1)
	{
		ft_putchar('*');
		i++;
	}
	if (x != 1)
		ft_putchar('/');
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
		return ;
	ft_print_first_line(x);
	if (y != 1)
	{
		ft_print_body(x, y);
		ft_print_last_line(x);
	}
}
