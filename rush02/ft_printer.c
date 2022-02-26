/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 09:51:53 by msessa            #+#    #+#             */
/*   Updated: 2020/12/13 09:51:56 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

void	ft_printer(char *number, t_list **dict_arr)
{
	int len_nbr;
	int i;

	if (ft_check_exact_match(number, dict_arr)
		|| ft_number_too_big(dict_arr, number))
		return ;
	i = 0;
	len_nbr = ft_strlen(number);
	while (i < len_nbr)
	{
		if ((len_nbr - i) % 3 == 0)
			ft_p_digit3(number, dict_arr, i);
		else if ((len_nbr - i) % 3 == 2)
		{
			ft_p_digit2(number, dict_arr, i);
			if (number[i] == '1')
				i++;
		}
		else
			ft_p_digit1(number, dict_arr, i, len_nbr);
		ft_p_bigs(number, dict_arr, i, len_nbr);
		i++;
	}
}

void	ft_print_tens(char *number, t_list **dict_arr, int pos)
{
	int i;

	i = 0;
	while (!((ft_strlen((dict_arr[i])->key) == 2)
		&& (dict_arr[i]->key[0] == '1')
		&& (dict_arr[i]->key[1] == number[pos + 1])))
		i++;
	ft_putstr(dict_arr[i]->value);
}

void	ft_p_bigs(char *number, t_list **dict_arr, int pos, int len_nbr)
{
	int i;

	i = 0;
	if (ft_check_hifen(number, pos, len_nbr))
		write(1, "-", 1);
	if (ft_check_and(number, pos, len_nbr))
		write(1, " and ", 5);
	if (ft_check_big(number, pos, len_nbr))
	{
		while (!(ft_is_stdbig(dict_arr[i]->key, pos, len_nbr)))
			i++;
		write(1, " ", 1);
		ft_putstr(dict_arr[i]->value);
		if (ft_check_comma(number, pos, len_nbr))
			write(1, ", ", 2);
	}
	if (pos == len_nbr - 1)
		write(1, "\n", 1);
}

int		ft_all_zeros(char *number, int pos)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (number[pos] != '0')
			return (0);
		pos--;
		i++;
	}
	return (1);
}

int		ft_is_stdbig(char *key, int pos, int len_nbr)
{
	int len_key;
	int i;

	if (key[0] != '1')
		return (0);
	i = 1;
	len_key = len_nbr - pos;
	if (ft_strlen(key) != len_key)
		return (0);
	while (i < len_key)
	{
		if (key[i] != '0')
			return (0);
		i++;
	}
	return (1);
}
