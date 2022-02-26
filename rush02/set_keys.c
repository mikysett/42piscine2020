/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:53:50 by msessa            #+#    #+#             */
/*   Updated: 2020/12/12 17:53:54 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

char	*ft_get_key(char *dict, int start, int key_size)
{
	char	*key;
	int		i;

	i = 0;
	key = malloc(sizeof(char) * (key_size + 1));
	if (!key)
		return (0);
	while (i < key_size)
	{
		key[i] = dict[start + i];
		i++;
	}
	key[i] = '\0';
	return (key);
}

int		skip_useless_zeros(char *dict)
{
	int i;

	i = 0;
	while (dict[i] == '0' && ft_is_number(dict[i + 1]))
		i++;
	return (i);
}

int		ft_set_keys(char *dict, t_list **dict_arr)
{
	int i;
	int key_size;
	int k;

	i = 0;
	k = 0;
	while (dict[i])
	{
		key_size = 0;
		while (dict[i] == '\n')
			i++;
		if (!dict[i])
			break ;
		i += skip_useless_zeros(dict + i);
		while (ft_is_number(dict[i + key_size]))
			key_size++;
		dict_arr[k]->key = ft_get_key(dict, i, key_size);
		if (!(dict_arr[k]->key))
			return (0);
		k++;
		i += key_size;
		while (dict[i] != '\0' && dict[i] != '\n')
			i++;
	}
	return (1);
}
