/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 10:58:16 by msessa            #+#    #+#             */
/*   Updated: 2020/12/13 11:26:15 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

char	*ft_swap_keys(t_list **dict_arr, int i, int j)
{
	t_list	*buff;

	buff = dict_arr[i];
	dict_arr[i] = dict_arr[j];
	dict_arr[j] = buff;
	return (dict_arr[i]->key);
}

void	ft_sort_dict(t_list **dict_arr)
{
	int		i;
	int		j;
	int		key1_len;
	int		key2_len;

	i = 0;
	while (dict_arr[i])
	{
		key1_len = ft_strlen(dict_arr[i]->key);
		j = i + 1;
		while (dict_arr[j])
		{
			key2_len = ft_strlen(dict_arr[j]->key);
			if (key1_len > key2_len
				|| (key1_len == key2_len
				&& ft_strcmp(dict_arr[i]->key, dict_arr[j]->key) > 0))
				key1_len = ft_strlen(ft_swap_keys(dict_arr, i, j));
			j++;
		}
		i++;
	}
}
