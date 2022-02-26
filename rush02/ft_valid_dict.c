/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 13:07:54 by msessa            #+#    #+#             */
/*   Updated: 2020/12/12 13:08:14 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int		file_dict_size(char *dict_name)
{
	int		fd;
	char	c;
	int		size;

	size = 0;
	fd = open(dict_name, O_RDONLY);
	if (fd < 0)
		return (0);
	while ((read(fd, &c, 1)) > 0)
	{
		if (!ft_is_printable(c) && !ft_is_space(c))
		{
			close(fd);
			return (0);
		}
		size++;
	}
	close(fd);
	return (size);
}

int		ft_dict_copy(char *dict_name, char *dict_str, int size)
{
	int fd;

	fd = open(dict_name, O_RDONLY);
	if (fd < 0)
		return (0);
	if (read(fd, dict_str, size) < 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	dict_str[size] = '\0';
	return (1);
}

int		ft_is_value_empty(char *value)
{
	while (*value && *value != '\n')
	{
		if (!ft_is_space(*value))
			return (0);
		value++;
	}
	return (1);
}

t_list	**ft_free_dict_str(char *dict_str)
{
	free(dict_str);
	return (0);
}

t_list	**ft_valid_dict(char *dict_name)
{
	t_list	**dict_arr;
	char	*dict_str;
	int		dict_size;
	int		nb_keys;

	dict_size = file_dict_size(dict_name);
	if (!dict_size)
		return (0);
	dict_str = malloc(sizeof(char) * (dict_size + 1));
	if (!dict_str)
		return (0);
	if (!ft_dict_copy(dict_name, dict_str, dict_size))
		return (ft_free_dict_str(dict_str));
	nb_keys = dict_valid_syntax(dict_str);
	if (nb_keys < 41)
		return (ft_free_dict_str(dict_str));
	dict_arr = ft_create_dict(dict_str, nb_keys);
	free(dict_str);
	if (!dict_arr)
		return (0);
	if (ft_semantic_check(dict_arr, nb_keys))
		return (dict_arr);
	ft_free_dict_arr(dict_arr);
	return (0);
}
