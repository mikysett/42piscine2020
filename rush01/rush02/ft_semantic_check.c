/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semantic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:34:27 by dareias-          #+#    #+#             */
/*   Updated: 2020/12/12 13:17:24 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int ft_cmp_keys(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	if (s1[i] == s2[i] && s1[i] == '\0')
		return(1);
	return (0);
}

int ft_semantic_check(t_list *dict[], int nb_keys)
{
	int i;
	int j;

	i = 0;
	while (i < nb_keys)
	{
		j = i + 1;
		while (j < nb_keys)
		{
			if (ft_cmp_keys(dict[i]->key, dict[j]->key) == 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
