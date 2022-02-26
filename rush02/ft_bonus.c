/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:41:45 by msessa            #+#    #+#             */
/*   Updated: 2020/12/13 17:41:48 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int		ft_check_hifen(char *number, int pos, int len_nbr)
{
	if ((len_nbr - pos) % 3 != 2)
		return (0);
	if (number[pos] == '0')
		return (0);
	if (number[pos + 1] == '0')
		return (0);
	return (1);
}

int		ft_check_and(char *number, int pos, int len_nbr)
{
	if ((len_nbr - pos) % 3 != 0)
		return (0);
	if (number[pos] == '0')
		return (0);
	if (number[pos + 1] == '0' && number[pos + 2] == '0')
		return (0);
	return (1);
}

int		ft_check_big(char *number, int pos, int len_nbr)
{
	if ((len_nbr - pos) % 3 != 1)
		return (0);
	if (ft_all_zeros(number, pos))
		return (0);
	if ((len_nbr - pos) <= 3)
		return (0);
	return (1);
}

int		ft_check_comma(char *number, int pos, int len_nbr)
{
	if (ft_all_zeros_forward(number, pos, len_nbr))
		return (0);
	return (1);
}

int		ft_all_zeros_forward(char *number, int pos, int len_nbr)
{
	pos++;
	while (pos < len_nbr)
	{
		if (number[pos] != '0')
			return (0);
		pos++;
	}
	return (1);
}
