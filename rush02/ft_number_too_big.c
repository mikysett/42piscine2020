/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_too_big.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 13:10:58 by msessa            #+#    #+#             */
/*   Updated: 2020/12/13 13:11:21 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int		ft_is_magnitude(char *key)
{
	if (*key != '1')
		return (0);
	key++;
	while (*key)
	{
		if (*key != '0')
			return (0);
		key++;
	}
	return (1);
}

int		ft_number_too_big(t_list **dict_arr, char *number)
{
	int		max_magnitude;
	char	*key_sel;
	int		size_key;
	int		i;

	i = 40;
	max_magnitude = 37;
	while (dict_arr[i])
	{
		key_sel = dict_arr[i]->key;
		size_key = ft_strlen(key_sel);
		if ((size_key - 1) % 3 == 0 && ft_is_magnitude(key_sel)
			&& size_key == max_magnitude + 3)
			max_magnitude += 3;
		i++;
	}
	if (ft_strlen(number) > max_magnitude + 2)
	{
		dict_error();
		return (1);
	}
	return (0);
}
