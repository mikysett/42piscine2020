/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 14:21:57 by msessa            #+#    #+#             */
/*   Updated: 2020/12/06 14:23:07 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_write_nbr(int nb)
{
	if (nb >= 10)
		ft_write_nbr(nb / 10);
	ft_putchar('0' + (nb % 10));
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while ((par + i) != 0 && par[i].str != 0)
	{
		while (*(par[i].str))
			write(1, (par[i].str)++, 1);
		write(1, "\n", 1);
		ft_write_nbr(par[i].size);
		write(1, "\n", 1);
		while (*(par[i].copy))
			write(1, (par[i].copy)++, 1);
		write(1, "\n", 1);
		i++;
	}
}
