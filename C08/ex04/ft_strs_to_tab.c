/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 12:25:51 by msessa            #+#    #+#             */
/*   Updated: 2020/12/06 12:25:56 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void				ft_strcpy_stock(struct s_stock_str stock, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		stock.str[i] = src[i];
		stock.copy[i] = src[i];
		i++;
	}
	stock.str[i] = '\0';
	stock.copy[i] = '\0';
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str *stocks;

	stocks = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!stocks)
		return (0);
	i = 0;
	while (i < ac)
	{
		stocks[i].size = ft_strlen(av[i]);
		stocks[i].str = malloc(sizeof(char) * (stocks[i].size + 1));
		stocks[i].copy = malloc(sizeof(char) * (stocks[i].size + 1));
		if (!stocks[i].str || !stocks[i].copy)
			return (0);
		ft_strcpy_stock(stocks[i], av[i]);
		i++;
	}
	stocks[i].size = 0;
	stocks[i].str = 0;
	stocks[i].copy = 0;
	return (stocks);
}
