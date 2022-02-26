/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_digits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 09:52:45 by msessa            #+#    #+#             */
/*   Updated: 2020/12/13 09:53:11 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

void	ft_p_digit3(char *number, t_list **dict_arr, int pos)
{
	int i;

	i = 0;
	if (number[pos] == '0')
		return ;
	else
	{
		while (ft_strlen(dict_arr[i]->key) != 1
			|| dict_arr[i]->key[0] != number[pos])
			i++;
		ft_putstr(dict_arr[i]->value);
		i = 0;
		write(1, " ", 1);
		while (!(ft_is_stdbig(dict_arr[i]->key, 0, 3)))
			i++;
		ft_putstr(dict_arr[i]->value);
	}
}

void	ft_p_digit2(char *number, t_list **dict_arr, int pos)
{
	int i;

	i = 0;
	if (number[pos] == '0')
		;
	else if (number[pos] == '1')
		ft_print_tens(number, dict_arr, pos);
	else
	{
		while (!((ft_strlen((dict_arr[i])->key) == 2)
			&& ((dict_arr[i])->key[0] == number[pos])
			&& ((dict_arr[i])->key[1] == '0')))
			i++;
		ft_putstr(dict_arr[i]->value);
	}
}

void	ft_p_digit1(char *number, t_list **dict_arr, int pos, int len_nbr)
{
	int i;

	i = 0;
	if (number[pos] == '0' && len_nbr != 1)
		;
	else if (number[pos] == '0' && len_nbr == 1)
	{
		while (!((ft_strlen((dict_arr[i])->key) == 1) &&
				((dict_arr[i])->key[0] == '0')))
			i++;
		ft_putstr(dict_arr[i]->value);
	}
	else
	{
		while (!((ft_strlen((dict_arr[i])->key) == 1) &&
					((dict_arr[i])->key[0] == number[pos])))
			i++;
		ft_putstr(dict_arr[i]->value);
	}
}
