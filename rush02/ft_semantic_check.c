/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_semantic_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:33:02 by dareias-          #+#    #+#             */
/*   Updated: 2020/12/12 17:46:08 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int	ft_cmp_keys(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	if (s1[i] == s2[i] && s1[i] == '\0')
		return (1);
	return (0);
}

int	ft_is_required_key(char *key)
{
	int i;
	int key_len;

	i = 0;
	key_len = ft_strlen(key);
	if (key_len > 37)
		return (0);
	if (key_len > 2)
	{
		if (key[i] != '1' || key_len % 3 != 1)
			if (ft_strcmp(key, "100") != 0)
				return (0);
		i++;
		while (key[i])
			if (key[i++] != '0')
				return (0);
	}
	if (key_len == 2)
		if (key[0] != '1' && key[1] != '0')
			return (0);
	return (1);
}

int	ft_semantic_check(t_list *dict_arr[], int nb_keys)
{
	int i;
	int j;
	int required;

	i = 0;
	required = 0;
	while (i < nb_keys)
	{
		j = i + 1;
		while (j < nb_keys)
		{
			if (ft_cmp_keys(dict_arr[i]->key, dict_arr[j]->key) == 1)
				return (0);
			j++;
		}
		if (ft_is_required_key(dict_arr[i]->key) == 1)
			required++;
		i++;
	}
	if (required == 41)
		return (1);
	return (0);
}
