/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_valid_syntax.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 18:05:39 by msessa            #+#    #+#             */
/*   Updated: 2020/12/12 18:05:43 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

char	*ft_is_key(char *dict_str)
{
	while (*dict_str == '\n')
		dict_str++;
	if (!ft_is_number(*dict_str))
		return (0);
	while (*dict_str && ft_is_number(*dict_str))
		dict_str++;
	if (!*dict_str || *dict_str == '\n')
		return (0);
	return (dict_str);
}

char	*ft_is_sep(char *dict_str)
{
	while (ft_is_space(*dict_str) && *dict_str != '\n')
		dict_str++;
	if (*dict_str == ':'
		&& *(dict_str + 1) != '\0'
		&& *(dict_str + 1) != '\n')
		return (dict_str + 1);
	return (0);
}

char	*ft_is_value(char *dict_str)
{
	while (ft_is_space(*dict_str) && *dict_str != '\n')
		dict_str++;
	if (!*dict_str || *dict_str == '\n' || !ft_is_printable(*dict_str))
		return (0);
	while (ft_is_printable(*dict_str))
		dict_str++;
	if (!*dict_str || *dict_str != '\n')
		return (0);
	return (dict_str);
}

int		dict_valid_syntax(char *dict_str)
{
	int nb_keys;

	nb_keys = 0;
	while (*dict_str)
	{
		dict_str = ft_is_key(dict_str);
		if (!dict_str)
			return (0);
		dict_str = ft_is_sep(dict_str);
		if (!dict_str)
			return (0);
		dict_str = ft_is_value(dict_str);
		if (!dict_str)
			return (0);
		nb_keys++;
		while (*dict_str == '\n')
			dict_str++;
	}
	return (nb_keys);
}
