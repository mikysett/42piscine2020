/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 10:11:38 by msessa            #+#    #+#             */
/*   Updated: 2020/12/12 10:11:40 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

void	number_error(void)
{
	write(1, "Error\n", 6);
}

void	dict_error(void)
{
	write(1, "Dict Error\n", 11);
}

void	ft_free_dict_arr(t_list **dict_arr)
{
	int i;

	i = 0;
	while (dict_arr[i])
	{
		free(dict_arr[i]->key);
		free(dict_arr[i]->value);
		free(dict_arr[i]);
		i++;
	}
	free(dict_arr);
}

void	ft_init_converter(char *number, char *dict)
{
	t_list **dict_arr;

	if (!(number = ft_valid_number(number)))
		return (number_error());
	dict_arr = ft_valid_dict(dict);
	if (!dict_arr)
		return (dict_error());
	ft_printer(number, dict_arr);
	ft_free_dict_arr(dict_arr);
}
