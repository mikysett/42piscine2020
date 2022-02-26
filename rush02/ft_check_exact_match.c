/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_exact_match.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:59:53 by msessa            #+#    #+#             */
/*   Updated: 2020/12/13 14:59:57 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int		ft_check_exact_match(char *number, t_list **dict_arr)
{
	int i;
	int nb_length;
	int key_length;

	nb_length = ft_strlen(number);
	i = 0;
	while (dict_arr[i])
	{
		key_length = ft_strlen(dict_arr[i]->key);
		if (nb_length < key_length)
			return (0);
		if (nb_length == key_length
			&& ft_strcmp(number, dict_arr[i]->key) == 0)
		{
			if (ft_is_magnitude(number))
				return (0);
			ft_putstr(dict_arr[i]->value);
			write(1, "\n", 1);
			return (1);
		}
		i++;
	}
	return (0);
}
